using System;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

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
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-bin.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dev.tar.lzma",
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dll.tar.lzma"
        };

        private static readonly string gccBasePath = Path.GetFullPath(Path.Combine(
            Path.GetDirectoryName(typeof(GccDriver).Assembly.Location), "gcc"));

        private static async Task<(int, string)> ExecuteAsync(
            string workingPath, string[] searchPaths, string executablePath, params object[] args)
        {
            using (var p = new Process())
            {
                p.StartInfo.FileName = executablePath;
                p.StartInfo.Arguments = string.Join(" ", args);
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.CreateNoWindow = true;
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

                p.Start();
                p.BeginOutputReadLine();
                p.BeginErrorReadLine();

                var exitCode = await tcs.Task;

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
                    using (var fs = new FileStream(path, FileMode.Create, FileAccess.ReadWrite, FileShare.None, 65536, true))
                    {
                        await stream.CopyToAsync(fs).ConfigureAwait(false); ;
                        await fs.FlushAsync().ConfigureAwait(false); ;
                    }
                }
            }

            return path;
        }

        private static async Task DownloadGccRequirementsAsync(string basePath)
        {
            if (Directory.Exists(basePath))
            {
                Directory.Delete(basePath, true);
            }
            Directory.CreateDirectory(basePath);

            try
            {
                var fetchPath = Path.Combine(basePath, "fetch");
                Directory.CreateDirectory(fetchPath);

                try
                {
                    var bsdTarArchivePath =
                        await DownloadFromUrlAsync(bsdTarUrl, fetchPath).ConfigureAwait(false);
                    await Task.Run(() =>
                    ZipFile.ExtractToDirectory(bsdTarArchivePath, fetchPath)).ConfigureAwait(false);

                    var bsdTarPath = Path.Combine(fetchPath, "basic-bsdtar.exe");

                    var archivePaths = await Task.WhenAll(
                        gccRequirementUrls.Select(async url =>
                        {
                            var path = await DownloadFromUrlAsync(url, fetchPath).ConfigureAwait(false);
                            var decompressionFlag = Path.GetExtension(path) == ".lzma" ? "--lzma" : "-j";
                            var (exitCode, log) = await ExecuteAsync(
                                basePath, new[] { basePath }, bsdTarPath, decompressionFlag, "-xf", path).ConfigureAwait(false);
                            return path;
                        })).ConfigureAwait(false);
                }
                finally
                {
                    Directory.Delete(fetchPath, true);
                }
            }
            catch
            {
                Directory.Delete(basePath, true);
                throw;
            }
        }

        public static async Task<string> CompileAndRunAsync(TextReader tr, params string[] includePaths)
        {
            if (!Directory.Exists(gccBasePath))
            {
                await DownloadGccRequirementsAsync(gccBasePath).ConfigureAwait(false);
            }

            var tempPath = Path.GetTempPath();
            var baseFolderName = string.Format("{0}", Guid.NewGuid().ToString("N"));
            var basePath = Path.Combine(tempPath, baseFolderName);

            Directory.CreateDirectory(basePath);
            try
            {
                // Step3: Construct source file
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

                // Step2: Compile by gcc
                var gccBinPath = Path.Combine(gccBasePath, "bin");
                var gccPath = Path.Combine(gccBinPath, "gcc.exe");

                var gccArguments = includePaths
                    .SelectMany(p => new[] { "-I", p })
                    .Concat(new[] { "-o", path + ".exe", path + ".c" })
                    .ToArray();

                var (compileExitCode, compileLog) = await ExecuteAsync(
                    basePath, new[] { gccBinPath }, gccPath, gccArguments);
                if ((compileExitCode != 0) || !string.IsNullOrWhiteSpace(compileLog)
                    || !File.Exists(path + ".exe"))
                {
                    throw new Exception("gcc [ExitCode=" + compileExitCode + "]: " + compileLog);
                }

                // Step3: Execute native binary
                var (exitCode, log) = await ExecuteAsync(
                    basePath, new[] { basePath }, path + ".exe");
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
