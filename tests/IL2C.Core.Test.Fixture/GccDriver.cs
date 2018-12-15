using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class GccDriver
    {
        private static readonly string mingwBaseUrl =
            "https://jaist.dl.sourceforge.net/project/mingw/MinGW";
        private static readonly string bsdTarUrl =
            mingwBaseUrl + "/Extension/bsdtar/basic-bsdtar-2.8.3-1/basic-bsdtar-2.8.3-1-mingw32-bin.zip";

        private static readonly string[] gccRequirementUrls =
        {
            mingwBaseUrl + "/Base/binutils/binutils-2.28/binutils-2.28-1-mingw32-bin.tar.xz",
            mingwBaseUrl + "/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dev.tar.lzma",
            mingwBaseUrl + "/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/w32api/w32api-3.17/w32api-3.17-2-mingw32-dev.tar.lzma",
            mingwBaseUrl + "/Base/mpc/mpc-1.0.1-2/mpc-1.0.1-2-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/mpfr/mpfr-3.1.2-2/mpfr-3.1.2-2-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/gmp/gmp-5.1.2/gmp-5.1.2-1-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/libiconv/libiconv-1.14-3/libiconv-1.14-3-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma",
            mingwBaseUrl + "/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/zlib/zlib-1.2.8/zlib-1.2.8-1-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/gettext/gettext-0.18.3.1-1/gettext-0.18.3.1-1-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-bin.tar.lzma",
            mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dev.tar.lzma",
            mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dll.tar.lzma",
            // Require C++
            //mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-bin.tar.lzma",
            //mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dev.tar.lzma",
            //mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dll.tar.lzma",
            mingwBaseUrl + "/Extension/gdb/gdb-7.6.1-1/gdb-7.6.1-1-mingw32-bin.tar.lzma",
            //"https://cmake.org/files/v3.12/cmake-3.12.3-win32-x86.zip",
            "https://github.com/kekyo/IL2C/releases/download/cmake-3.12.3/cmake-3.12.3-win32-x86.zip",
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

        private static async Task<int> ExtractFromZip(string basePath, string zipPath, bool suppressTopDirectory)
        {
            var absoluteBasePath = Path.GetFullPath(basePath);

            return await Task.Run(() =>
            {
                using (var zip = ZipFile.OpenRead(zipPath))
                {
                    foreach (var entry in zip.Entries.
                        Where(entry => !string.IsNullOrWhiteSpace(entry.Name)))
                    {
                        var path = Path.Combine(
                            absoluteBasePath,
                            Path.Combine(entry.FullName.Split('/').Skip(suppressTopDirectory ? 1 : 0).ToArray()));
                        if (!Directory.Exists(Path.GetDirectoryName(path)))
                        {
                            try
                            {
                                Directory.CreateDirectory(Path.GetDirectoryName(path));
                            }
                            catch
                            {
                            }
                        }
                        entry.ExtractToFile(path, true);
                    }
                }
                return 0;
            });
        }

        private static async Task DownloadGccRequirementsAsync(string basePath)
        {
            try
            {
                var fetchPath = Path.Combine(basePath, "fetch");
                await Task.Run(() => Directory.CreateDirectory(fetchPath));

                try
                {
                    var bsdTarArchivePath = await DownloadFromUrlAsync(bsdTarUrl, fetchPath);
                    await ExtractFromZip(fetchPath, bsdTarArchivePath, false);

                    var bsdTarPath = Path.Combine(fetchPath, "basic-bsdtar.exe");

                    var archivePaths = await Task.WhenAll(
                        gccRequirementUrls.Select(async url =>
                        {
                            var archivePath = await DownloadFromUrlAsync(url, fetchPath);

                            int exitCode = -1;
                            string log = string.Empty;
                            switch (Path.GetExtension(archivePath))
                            {
                                case ".lzma":
                                    (exitCode, log) = await ExecuteAsync(
                                        basePath, new[] { basePath }, bsdTarPath, "--lzma", "-xf", archivePath);
                                    break;
                                case ".xz":
                                    (exitCode, log) = await ExecuteAsync(
                                        basePath, new[] { basePath }, bsdTarPath, "-j", "-xf", archivePath);
                                    break;
                                case ".gz":
                                    (exitCode, log) = await ExecuteAsync(
                                        basePath, new[] { basePath }, bsdTarPath, "-z", "-xf", archivePath);
                                    break;
                                case ".zip":
                                    exitCode = await ExtractFromZip(basePath, archivePath, true);
                                    break;
                            }

                            if (exitCode != 0)
                            {
                                throw new Exception("Failed extraction gcc asset: " + Path.GetFileName(archivePath));
                            }
                            Trace.WriteLine("Downloaded and extracted gcc asset: " + Path.GetFileName(archivePath));

                            return archivePath;
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

        public static async Task<string> DriveGccAsync(
            Func<string, string, string, string, Task<string>> executeAsync,
            string scriptTemplateName,
            bool optimize, string sourcePath, params string[] includePaths)
        {
            // Download requirements for gcc (single)
            if (!Directory.Exists(gccBasePath))
            {
                await Task.Run(() =>
                {
                    using (var m = new Mutex(false, typeof(GccDriver).FullName))
                    {
                        m.WaitOne();
                        try
                        {
                            if (!Directory.Exists(gccBasePath))
                            {
                                DownloadGccRequirementsAsync(gccBasePath + ".tmp").Wait();
                                Directory.Move(gccBasePath + ".tmp", gccBasePath);

                                CompileAsync(
                                    "make_libil2c.bat",
                                    optimize,
                                    Path.GetFullPath(Path.Combine(gccBasePath, "..", "dummy.c")),
                                    includePaths).Wait();
                            }
                        }
                        finally
                        {
                            m.ReleaseMutex();
                        }
                    }
                });
            }

            var basePath = Path.GetDirectoryName(sourcePath);
            var outPath = Path.Combine(basePath, "out");
            var executablePath = Path.Combine(outPath, Path.GetFileNameWithoutExtension(sourcePath) + ".exe");
            var includePath = Path.GetFullPath(Path.Combine(gccBasePath, "..", "..", "..", "..", "..", "..", "IL2C.Runtime"));
            var libPath = Path.GetFullPath(Path.Combine(gccBasePath, ".."));
            var optimizeFlag = optimize ? "-Ofast -flto" : "-O0";
            var disableObjDump = optimize ? "rem " : string.Empty;

            if (!Directory.Exists(outPath))
            {
                Directory.CreateDirectory(outPath);
            }

            // Step1: Compile by gcc (from batch script)
            var gccBinPath = Path.Combine(gccBasePath, "bin");
            var gccPath = Path.Combine(gccBinPath, "gcc.exe");

            // TODO: turn to cmake based.
            var scriptPath = Path.Combine(basePath, scriptTemplateName);
            await TestUtilities.CopyResourceToTextFileAsync(
                scriptPath, scriptTemplateName,
                new Dictionary<string, object>
                {
                    { "gccBinPath", gccBinPath },
                    { "includePath", includePath },
                    { "libPath", libPath },
                    { "optimizeFlag", optimizeFlag },
                    { "disableObjDump", disableObjDump }
                });

            return await executeAsync(basePath, gccBinPath, scriptPath, executablePath);
        }

        private static async Task<string> CompileAndRunAsync(
            string basePath, string gccBinPath, string scriptPath, string executablePath)
        {
            var (compileExitCode, compileLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await ExecuteAsync(
                    basePath, new[] { gccBinPath }, scriptPath);
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
            bool optimize, string sourcePath, params string[] includePaths)
        {
            return DriveGccAsync(CompileAndRunAsync, "make.bat", optimize, sourcePath, includePaths);
        }

        private static async Task<string> CompileAsync(
            string basePath, string gccBinPath, string scriptPath, string executablePath)
        {
            var (compileExitCode, compileLog) = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await ExecuteAsync(
                    basePath, new[] { gccBinPath }, scriptPath);
                if ((exitCode != 0) || !string.IsNullOrWhiteSpace(log))
                {
                    throw new Exception("gcc [ExitCode=" + exitCode + "]: " + log);
                }
                return (exitCode, log);
            });

            return compileLog;
        }

        public static Task<string> CompileAsync(
            string scriptTemplateName, bool optimize, string sourcePath, params string[] includePaths)
        {
            return DriveGccAsync(CompileAsync, scriptTemplateName, optimize, sourcePath, includePaths);
        }
    }
}
