using System;
using System.IO;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class CMakeDriver
    {
        public static async Task<string> BuildAsync(
            string binPath, string configuration, string sourcePath, string includePath)
        {
            var basePath = Path.GetDirectoryName(sourcePath);
            var outPath = Path.Combine(basePath, "build");
            var executablePath = Path.Combine(outPath, Path.GetFileNameWithoutExtension(sourcePath) + ".exe");

            // Step1: Generate ninja script by cmake.
            if (!Directory.Exists(outPath))
            {
                Directory.CreateDirectory(outPath);

                var scriptPath = Path.Combine(basePath, "CMakeLists.txt");
                await TestUtilities.CopyResourceToTextFileAsync(scriptPath, "CMakeLists.txt");

                try
                {
                    var cmakeLog = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
                    {
                        var (exitCode, log) = await TestUtilities.ExecuteAsync(
                            outPath, new[] { binPath },
                            Path.Combine(binPath, "cmake.exe"), "-G", "Ninja", "-DCMAKE_MAKE_PROGRAM=ninja.exe", "-DPLATFORM=mingw32", $"-DCONFIGURATION={configuration}", "..");
                        if (exitCode != 0)
                        {
                            throw new Exception("cmake [ExitCode=" + exitCode + "]: " + log);
                        }
                        return log;
                    });
                }
                catch
                {
                    try
                    {
                        Directory.Delete(outPath, true);
                    }
                    catch
                    {
                    }
                    throw;
                }
            }

            // Step2: Execute ninja
            var cmakeNinjaLog = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath, new[] { binPath },
                    Path.Combine(binPath, "cmake.exe"), "--build", ".", "-j");
                if (exitCode != 0)
                {
                    throw new Exception("cmake [ninja] [ExitCode=" + exitCode + "]: " + log);
                }
                return log;
            });

            // Step3: Execute native binary
            var testLog = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath, new[] { outPath }, executablePath);
                if (exitCode != 0)
                {
                    throw new Exception("test [ExitCode=" + exitCode + "]: " + log);
                }
                return log;
            });

            return testLog;
        }
    }
}
