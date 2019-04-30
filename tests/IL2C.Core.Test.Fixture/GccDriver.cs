using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class GccDriver
    {
        private static async Task<(int, string)> ExecuteAsync(
            string workingPath, string[] searchPaths, string executablePath, params object[] args)
        {
            using (var p = new Process())
            {
                p.StartInfo.FileName = executablePath;
                p.StartInfo.Arguments = string.Join(" ", args);
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.CreateNoWindow = true;
                p.StartInfo.ErrorDialog = false;
                p.StartInfo.WorkingDirectory = workingPath;

                var pathEnv = p.StartInfo.Environment["PATH"];
                p.StartInfo.Environment["PATH"] = string.Join(";", searchPaths) + ";" + pathEnv;

                p.StartInfo.RedirectStandardOutput = true;
                p.StartInfo.RedirectStandardError = true;

                var sb = new StringBuilder();
                p.OutputDataReceived += (sender, e) => { if (e.Data != null) lock (sb) sb.AppendLine(e.Data); };
                p.ErrorDataReceived += (sender, e) => { if (e.Data != null) lock (sb) sb.AppendLine(e.Data); };

                var tcs = new TaskCompletionSource<int>();
                p.Exited += (sender, e) => tcs.SetResult(p.ExitCode);
                p.EnableRaisingEvents = true;

                await TestUtilities.RetryIfStrangeProblemAsync(() => p.Start());

                p.BeginOutputReadLine();
                p.BeginErrorReadLine();

                var exitCode = await tcs.Task;

                p.WaitForExit();

                p.CancelOutputRead();
                p.CancelErrorRead();

                return (exitCode, sb.ToString());
            }
        }

        public static async Task<string> DriveGccAsync(
            string binPath,
            Func<string, string, string, string, Task<string>> executeAsync,
            string scriptTemplateName,
            bool optimize, string sourcePath, string includePath)
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

            // TODO: turn to cmake based.
            var scriptPath = Path.Combine(basePath, scriptTemplateName);
            await TestUtilities.CopyResourceToTextFileAsync(
                scriptPath, scriptTemplateName,
                new Dictionary<string, object>
                {
                    { "binPath", binPath },
                    { "includePath", includePath },
                    { "configuration", configuration },
                    { "optimizeFlag", optimizeFlag },
                    { "sourcePath", string.Join(" ", sourcePath) }
                });

            return await executeAsync(basePath, binPath, scriptPath, executablePath);
        }

        private static async Task<string> CompileAndRunAsync(
            string basePath, string binPath, string scriptPath, string executablePath)
        {
            var (compileExitCode, compileLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await ExecuteAsync(
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
                var (exitCode, log) = await ExecuteAsync(
                    basePath, new[] { basePath }, executablePath);
                if (exitCode != 0)
                {
                    throw new Exception("test [ExitCode=" + exitCode + "]: " + log);
                }
                return (exitCode, log);
            });

            return testLog;
        }

        public static Task<string> CompileAndRunAsync(
            string binPath, bool optimize, string sourcePath, string includePath)
        {
            return DriveGccAsync(binPath, CompileAndRunAsync, "make.bat", optimize, sourcePath, includePath);
        }
    }
}
