////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.Internal
{
    internal readonly struct ExecuteResult
    {
        public readonly int ExitCode;
        public readonly string Logs;

        public ExecuteResult(int exitCode, string logs)
        {
            this.ExitCode = exitCode;
            this.Logs = logs;
        }

        public override string ToString() =>
            $"{this.ExitCode}: {this.Logs}";
    }

    internal static class IOAccessor
    {
        public static string ToRelativePath(string baseDirPath, string path)
        {
            var length = baseDirPath.EndsWith(Path.DirectorySeparatorChar.ToString()) ?
                baseDirPath.Length : baseDirPath.Length + 1;
            var candidate = path.StartsWith(baseDirPath) ?
                path.Substring(length) : path;
            return candidate.Length >= 1 ? candidate : ".";
        }

        public static string GetDirectoryPath(string path) =>
            Path.GetDirectoryName(path) switch
            {
                null => Path.DirectorySeparatorChar.ToString(),
                { Length: 0 } => ".",
                { } d => d,
            };

        public static ValueTask SafeCreateDirectoryAsync(string path, bool clean)
        {
            if (clean)
            {
                return new ValueTask(Task.Run(() =>
                {
                    try
                    {
                        Directory.Delete(path, true);
                        Directory.CreateDirectory(path);
                    }
                    catch
                    {
                    }
                }));
            }
            else
            {
                if (!Directory.Exists(path))
                {
                    return new ValueTask(Task.Run(() =>
                    {
                        try
                        {
                            Directory.CreateDirectory(path);
                        }
                        catch
                        {
                        }
                    }));
                }
                else
                {
                    return default;
                }
            }
        }

        public static async ValueTask<string> ReadAllTextAsync(
            string path, Encoding encoding)
        {
            using var fs = new FileStream(
                path, FileMode.Open, FileAccess.Read, FileShare.Read, 65536, true);
            var tr = new StreamReader(fs, encoding);

            return await tr.ReadToEndAsync().ConfigureAwait(false);
        }

        public static async ValueTask WriteAllTextAsync(
            string path, string contents, Encoding encoding)
        {
            using var fs = new FileStream(
                path, FileMode.Create, FileAccess.ReadWrite, FileShare.None, 65536, true);
            var tw = new StreamWriter(fs, encoding);

            await tw.WriteAsync(contents).ConfigureAwait(false);
            await tw.FlushAsync().ConfigureAwait(false);
        }

        public static async ValueTask<ExecuteResult> ExecuteAsync(
            string workingPath, string scriptName, string[] searchPaths,
            string executablePath, string[] args)
        {
            if (Environment.OSVersion.Platform == PlatformID.Win32NT)
            {
                await WriteAllTextAsync(
                    Path.Combine(workingPath, scriptName + ".bat"),
                    string.Join(Environment.NewLine, new[]
                    {
                        "@echo off",
                        string.Empty,
                        "rem IL2C: It is a pseudo script.",
                        string.Empty,
                        searchPaths.Length >= 1 ?
                            $"set PATH={string.Join(";",searchPaths)};%PATH%" :
                            "rem set PATH=;%PATH%",
                        string.Empty,
                        $"\"{executablePath}\" {string.Join(" ", args)}",
                        string.Empty,
                    }),
                    new UTF8Encoding(false, true)).
                    ConfigureAwait(false);
            }
            else
            {
                await WriteAllTextAsync(
                    Path.Combine(workingPath, scriptName + ".sh"),
                    string.Join(Environment.NewLine, new[]
                    {
                        "#!/bin/sh",
                        string.Empty,
                        "# IL2C: It is a pseudo script.",
                        string.Empty,
                        searchPaths.Length >= 1 ?
                            $"export PATH=\"{string.Join(":",searchPaths)}:$PATH\"" :
                            "#export PATH=\":$PATH\"",
                        string.Empty,
                        $"\"{executablePath}\" {string.Join(" ", args)}",
                        string.Empty,
                    }),
                    new UTF8Encoding(false, true)).
                    ConfigureAwait(false);
            }

            using (var p = new Process())
            {
                p.StartInfo.FileName = executablePath;
                p.StartInfo.Arguments = string.Join(" ", args);
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.CreateNoWindow = true;
                p.StartInfo.ErrorDialog = false;
                p.StartInfo.WorkingDirectory = workingPath;

#if NET46_OR_GREATER || NETSTANDARD || NETCOREAPP
                var pathEnv = p.StartInfo.Environment["PATH"];
                p.StartInfo.Environment["PATH"] = string.Join(";", searchPaths) + ";" + pathEnv;
#else
                var pathEnv = p.StartInfo.EnvironmentVariables["PATH"];
                p.StartInfo.EnvironmentVariables["PATH"] = string.Join(";", searchPaths) + ";" + pathEnv;
#endif
                p.StartInfo.RedirectStandardOutput = true;
                p.StartInfo.RedirectStandardError = true;

                var sb = new StringBuilder();
                p.OutputDataReceived += (sender, e) => { if (e.Data != null) lock (sb) sb.AppendLine(e.Data); };
                p.ErrorDataReceived += (sender, e) => { if (e.Data != null) lock (sb) sb.AppendLine(e.Data); };

                var tcs = new TaskCompletionSource<int>();
                p.Exited += (sender, e) => tcs.SetResult(p.ExitCode);
                p.EnableRaisingEvents = true;

                p.Start();

                p.BeginOutputReadLine();
                p.BeginErrorReadLine();

                var exitCode = await tcs.Task.
                    ConfigureAwait(false);

                p.WaitForExit();

                p.CancelOutputRead();
                p.CancelErrorRead();

                return new ExecuteResult(exitCode, sb.ToString());
            }
        }
    }
}
