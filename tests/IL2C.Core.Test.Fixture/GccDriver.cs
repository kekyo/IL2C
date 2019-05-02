using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class GccDriver
    {
        public static async Task<string> BuildAsync(
            string binPath, bool optimize, string sourcePath, string includePath)
        {
            var basePath = Path.GetDirectoryName(sourcePath);
            var outPath = Path.Combine(basePath, "out");
            var executablePath = Path.Combine(outPath, Path.GetFileNameWithoutExtension(sourcePath) + ".exe");
            var configuration = optimize ? "release" : "debug";
            var optimizeFlag = optimize ? "-Ofast -DNDEBUG" : "-O0 -D_DEBUG -DIL2C_USE_RUNTIME_DEBUG_LOG";

            if (!Directory.Exists(outPath))
            {
                Directory.CreateDirectory(outPath);
            }

            // Step1: Compile by gcc (from batch script)

            var scriptPath = Path.Combine(basePath, "make.bat");
            await TestUtilities.CopyResourceToTextFileAsync(
                scriptPath, "make.bat",
                new Dictionary<string, object>
                {
                    { "binPath", binPath },
                    { "includePath", includePath },
                    { "configuration", configuration },
                    { "optimizeFlag", optimizeFlag },
                    { "sourcePath", string.Join(" ", sourcePath) }
                });

            var (compileExitCode, compileLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    basePath, new[] { binPath }, scriptPath);
                if ((exitCode != 0) || !string.IsNullOrWhiteSpace(log)
                    || !File.Exists(executablePath))
                {
                    throw new Exception("gcc [ExitCode=" + exitCode + "]: " + log);
                }
                return (exitCode, log);
            });

            // Step2: Execute native binary
            var (testExitCode, testLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    basePath, new[] { basePath }, executablePath);
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
