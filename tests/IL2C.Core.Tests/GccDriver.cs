using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class GccDriver
    {
        private static readonly string gccBasePath = Path.GetFullPath(Path.Combine(
            Path.GetDirectoryName(typeof(GccDriver).Assembly.Location),
            "..",
            "..",
            "..",
            "..",
            "..",
            "gcc",
            "bin"));
        private static readonly string gccPath = Path.Combine(gccBasePath, "cc.exe");

        private static async Task<(int, string)> ExecuteAsync(string workingPath, string executablePath, params object[] args)
        {
            using (var p = new Process())
            {
                p.StartInfo.FileName = executablePath;
                p.StartInfo.Arguments = string.Join(" ", args);
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.CreateNoWindow = true;
                p.StartInfo.WorkingDirectory = workingPath;
                p.StartInfo.RedirectStandardOutput = true;
                p.StartInfo.RedirectStandardError = true;

                var sb = new StringBuilder();
                p.OutputDataReceived += (sender, e) => sb.Append(e.Data);
                p.ErrorDataReceived += (sender, e) => sb.Append(e.Data);

                var tcs = new TaskCompletionSource<int>();
                p.Exited += (sender, e) =>
                {
                    tcs.SetResult(p.ExitCode);
                };
                p.EnableRaisingEvents = true;

                p.Start();
                p.BeginOutputReadLine();
                p.BeginErrorReadLine();

                var exitCode = await tcs.Task;

                p.CancelOutputRead();
                p.CancelErrorRead();

                return (exitCode, sb.ToString());
            }
        }

        public static async Task<string> CompileAndRunAsync(TextReader tr)
        {
            var tempPath = Path.GetTempPath();
            var baseFolderName = string.Format("{0}", Guid.NewGuid().ToString("N"));
            var basePath = Path.Combine(tempPath, baseFolderName);

            Directory.CreateDirectory(basePath);
            try
            {
                var path = Path.Combine(basePath, "test");
                using (var tw = File.CreateText(path + ".c"))
                {
                    while (true)
                    {
                        var line = await tr.ReadLineAsync().ConfigureAwait(false);
                        if (line == null)
                        {
                            break;
                        }

                        await tw.WriteLineAsync(line).ConfigureAwait(false);
                    }
                    await tw.FlushAsync().ConfigureAwait(false);
                }

                var (compileExitCode, compileLog) =
                    await ExecuteAsync(gccBasePath, gccPath, "-o", path + ".exe", path + ".c");
                if ((compileExitCode != 0) && string.IsNullOrWhiteSpace(compileLog)
                    && File.Exists(path + ".exe"))
                {
                    throw new Exception("gcc [ExitCode=" + compileExitCode + "]: " + compileLog);
                }

                var (exitCode, log) =
                    await ExecuteAsync(basePath, path + ".exe");
                if (exitCode != 0)
                {
                    throw new Exception("test [ExitCode=" + exitCode + "]: " + log);
                }

                return log;
            }
            finally
            {
                Directory.Delete(basePath, true);
            }
        }
    }
}
