using System;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

using Nito.AsyncEx;

namespace IL2C
{
    internal static class GccDriver
    {
        private static readonly string bsdTarUrl =
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Extension/bsdtar/basic-bsdtar-2.8.3-1/basic-bsdtar-2.8.3-1-mingw32-bin.zip";

        private static readonly string[] gccRequirementUrls =
        {
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/binutils/binutils-2.28/binutils-2.28-1-mingw32-bin.tar.xz",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dev.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/w32api/w32api-3.17/w32api-3.17-2-mingw32-dev.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mpc/mpc-1.0.1-2/mpc-1.0.1-2-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mpfr/mpfr-3.1.2-2/mpfr-3.1.2-2-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gmp/gmp-5.1.2/gmp-5.1.2-1-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/libiconv/libiconv-1.14-3/libiconv-1.14-3-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/zlib/zlib-1.2.8/zlib-1.2.8-1-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gettext/gettext-0.18.3.1-1/gettext-0.18.3.1-1-mingw32-dll.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-bin.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dev.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dll.tar.lzma",
            // Require C++
            //"https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-bin.tar.lzma",
            //"https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dev.tar.lzma",
            //"https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dll.tar.lzma"
        };

        private static readonly string gccBasePath = Path.GetFullPath(Path.Combine(
            Path.GetDirectoryName(typeof(GccDriver).Assembly.Location), "gcc"));

        private static readonly AsyncLock gccLock = new AsyncLock();

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

        private static async Task<string> DownloadFromUrlAsync(string url, string basePath)
        {
            var uri = new Uri(url, UriKind.RelativeOrAbsolute);
            var path = Path.Combine(basePath, uri.PathAndQuery.Split('/').Last());

            using (var client = new HttpClient())
            {
                using (var stream = await client.GetStreamAsync(url).ConfigureAwait(false))
                {
                    using (var fs = await TestUtilities.CreateStreamAsync(path))
                    {
                        await stream.CopyToAsync(fs);
                        await fs.FlushAsync();

                        fs.Close();
                    }
                }
            }

            return path;
        }

        private static async Task DownloadGccRequirementsAsync(string basePath)
        {
            try
            {
                var fetchPath = Path.Combine(basePath, "fetch");
                await Task.Run(() => Directory.CreateDirectory(fetchPath));

                try
                {
                    var bsdTarArchivePath =
                        await DownloadFromUrlAsync(bsdTarUrl, fetchPath);
                    await Task.Run(() =>
                        ZipFile.ExtractToDirectory(bsdTarArchivePath, fetchPath));

                    var bsdTarPath = Path.Combine(fetchPath, "basic-bsdtar.exe");

                    var archivePaths = await Task.WhenAll(
                        gccRequirementUrls.Select(async url =>
                        {
                            var path = await DownloadFromUrlAsync(url, fetchPath);
                            var decompressionFlag = Path.GetExtension(path) == ".lzma" ? "--lzma" : "-j";
                            var (exitCode, log) = await ExecuteAsync(
                                basePath, new[] { basePath }, bsdTarPath, decompressionFlag, "-xf", path);
                            if (exitCode != 0)
                            {
                                throw new Exception("Failed extraction gcc asset: " + Path.GetFileName(path));
                            }
                            Trace.WriteLine("Downloaded and extracted gcc asset: " + Path.GetFileName(path));
                            return path;
                        }));
                }
                finally
                {
                    await Task.Run(() => Directory.Delete(fetchPath, true));
                }
            }
            catch
            {
                await Task.Run(() => Directory.Delete(basePath, true));
                throw;
            }
        }

        public static async Task<string> CompileAndRunAsync(
            string sourcePath, params string[] includePaths)
        {
            // Download requirements for gcc (single)
            if (!Directory.Exists(gccBasePath))
            {
                using (var l = await gccLock.LockAsync().ConfigureAwait(false))
                {
                    if (!Directory.Exists(gccBasePath))
                    {
                        await DownloadGccRequirementsAsync(gccBasePath);
                    }
                }
            }

            var basePath = Path.GetDirectoryName(sourcePath);
            var objPath = Path.Combine(basePath, "obj");
            var executablePath = Path.Combine(objPath, Path.GetFileNameWithoutExtension(sourcePath) + ".exe");

            if (!Directory.Exists(objPath))
            {
                Directory.CreateDirectory(objPath);
            }

            // Step1: Compile by gcc
            var gccBinPath = Path.Combine(gccBasePath, "bin");
            var gccPath = Path.Combine(gccBinPath, "gcc.exe");

            var gccArguments = includePaths
                .SelectMany(p => new[] { "-I", p })
                .Concat(new[] { "-save-temps=obj", "-O0", "-g", "-fdata-sections", "-ffunction-sections", "-Wl,--gc-sections", "-o", executablePath, sourcePath })
                .ToArray();

            // TODO: turn to cmake based.
            var scriptPath = Path.Combine(basePath, "make.bat");
            await TestUtilities.WriteTextFileAsync(
                scriptPath,
                string.Format(
                    "@echo off\r\nsetlocal\r\nset PATH={0};%PATH%\r\nrmdir /s /q obj\r\nmkdir obj\r\n{1} {2}\r\n",
                    gccBinPath,
                    gccPath,
                    string.Join(" ", gccArguments)));

            var (compileExitCode, compileLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await ExecuteAsync(
                    basePath, new[] { gccBinPath }, gccPath, gccArguments);
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
    }
}
