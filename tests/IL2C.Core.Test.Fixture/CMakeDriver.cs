using System;
using System.IO;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class CMakeDriver
    {
        public static async Task<string> BuildAsync(
            string binPath, bool optimize, string sourcePath, string includePath)
        {
            var basePath = Path.GetDirectoryName(sourcePath);
            var configuration = optimize ? "Release" : "Debug";
            var outPath = Path.Combine(basePath, "build");
            var executablePath = Path.Combine(outPath, Path.GetFileNameWithoutExtension(sourcePath) + ".exe");

            if (Directory.Exists(outPath))
            {
                Directory.Move(outPath, outPath + "_");
                Directory.Delete(outPath + "_", true);
            }

            Directory.CreateDirectory(outPath);

            var scriptPath = Path.Combine(basePath, "CMakeLists.txt");
            await TestUtilities.CopyResourceToTextFileAsync(scriptPath, "CMakeLists.txt");

            // Step1: Generate ninja script by cmake.
            var (cmakeExitCode, cmakeLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath, new[] { binPath },
                    Path.Combine(binPath, "cmake.exe"), "-G", "Ninja", "-DCMAKE_MAKE_PROGRAM=ninja.exe", "-DPLATFORM=mingw32", $"-DCONFIGURATION={configuration}", "..");
                if (exitCode != 0)
                {
                    throw new Exception("cmake [ExitCode=" + exitCode + "]: " + log);
                }
                return (exitCode, log);
            });

            // Step2: Execute ninja
            var (cmakeNinjaExitCode, cmakeNinjaLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath, new[] { binPath },
                    Path.Combine(binPath, "cmake.exe"), "--build", ".", "-j");
                if (exitCode != 0)
                {
                    throw new Exception("cmake [ninja] [ExitCode=" + exitCode + "]: " + log);
                }
                return (exitCode, log);
            });

            // Step3: Execute native binary
            var (testExitCode, testLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath, new[] { outPath }, executablePath);
                if (exitCode != 0)
                {
                    throw new Exception("test [ExitCode=" + exitCode + "]: " + log);
                }
                return (exitCode, log);
            });

            return testLog;
        }
    }
}
