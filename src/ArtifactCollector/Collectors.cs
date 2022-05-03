////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace IL2C.ArtifactCollector
{
    internal static class Collectors
    {
        public static Task RecreateDirectoryAsync(string path)
        {
            return Task.Run(() =>
            {
                if (Directory.Exists(path))
                {
                    Directory.Move(path, path + ".old");
                    Directory.Delete(path + ".old", true);
                }

                Directory.CreateDirectory(path);
            });
        }

        private static Task CopyFileAsync(string from, string to)
        {
            return Task.Run(() =>
            {
                var toDirectory = Path.GetDirectoryName(to);
                var count = 10;
                while (!Directory.Exists(toDirectory))
                {
                    try
                    {
                        Directory.CreateDirectory(toDirectory);
                    }
                    catch (IOException)
                    {
                        count--;
                        if (count <= 0)
                        {
                            throw;
                        }
                    }
                }

                File.Copy(from, to, true);
            });
        }

        private static async Task CopyArtifactsAsync(string artifactsDir, string targetDirectoryPath)
        {
            var versionString = ThisAssembly.AssemblyVersion;

            var nupkgPaths = Directory.GetFiles(targetDirectoryPath, "*.nupkg", SearchOption.AllDirectories).
                Where(p => p.Contains(versionString)).
                GroupBy(p => p).
                Select(g => Tuple.Create(g.Key, g.OrderByDescending(p => p.Length).ToArray())).
                ToDictionary(entry => entry.Item1, entry => entry.Item2);

            foreach (var nupkgPath in nupkgPaths.Select(entry => entry.Value.First()))
            {
                var targetNupkgFileName = Path.GetFileName(nupkgPath);
                var targetPath = Path.Combine(artifactsDir, targetNupkgFileName);

                if (File.Exists(targetPath))
                {
                    File.Move(targetPath, targetPath + ".orig");
                    File.Delete(targetPath + ".orig");
                }

                await CopyFileAsync(nupkgPath, targetPath);

                Program.WriteLine(
                    "AritfactCollector: Package collected: File={0}, Built={1}",
                    targetNupkgFileName,
                    Path.GetFileName(nupkgPath));
            }
        }

        public static async Task BuildCsprojAndCollectArtifactsAsync(
            string solutionDir, string artifactsDir, string buildIdentifier, IEnumerable<string> csprojPaths)
        {
            foreach (var path in csprojPaths)
            {
                var workingPath = Path.GetDirectoryName(path);
                var result = await Executor.ExecuteAsync(
                    workingPath,
                    new string[0],
                    "dotnet",
                    "pack",
                    "--no-build",
                    "--configuration", "Release",
                    "-p:Platform=",   // BUG WORKAROUND: dotnet pack is misunderstanding Platform variable sets to "Any CPU", so have to set blank.
                    $"-p:BuildIdentifier={buildIdentifier}",
                    $"\"{path}\"");
                Program.WriteLine(result.Item2);
                if (result.Item1 != 0)
                {
                    throw new Exception($"Csproj failed: Path={path}, ExitCode={result.Item2}");
                }
            }

            await Task.WhenAll(csprojPaths.
                Select(path => Path.GetDirectoryName(Path.GetFullPath(path))).
                Distinct().
                Select(path => CopyArtifactsAsync(artifactsDir, path)));
        }

        public static async Task BuildNuspecAndCollectArtifactsAsync(
            string solutionDir, string artifactsDir, string buildIdentifier, IEnumerable<string> nuspecPaths)
        {
            var nugetPath = Path.Combine(solutionDir, ".nuget", "nuget.exe");

            var versionString = ThisAssembly.AssemblyVersion;

            foreach (var path in nuspecPaths)
            {
                var outputDirectory = Path.Combine(Path.GetDirectoryName(path), "bin", "Release");
                var workingPath = Path.GetDirectoryName(path);
                var result = await Executor.ExecuteAsync(
                    workingPath,
                    new string[0],
                    nugetPath,
                    "pack",
                    "-Version", versionString,
                    "-NoPackageAnalysis",
                    "-Prop", $"Configuration=Release",
                    "-Prop", $"BuildIdentifier={buildIdentifier}",
                    "-OutputDirectory", $"\"{outputDirectory}\"",
                    $"\"{path}\"");
                Program.WriteLine(result.Item2);
                if (result.Item1 != 0)
                {
                    throw new Exception($"Nuspec failed: Path={path}, ExitCode={result.Item1}");
                }
            }

            await Task.WhenAll(nuspecPaths.
                Select(path => Path.GetDirectoryName(Path.GetFullPath(path))).
                Distinct().
                Select(path => CopyArtifactsAsync(artifactsDir, path)));
        }

        public static async Task BuildZipFromCollectArtifactsAsync(
            string artifactsDir, IEnumerable<string> zipArtifactsPaths)
        {
            var versionString = ThisAssembly.AssemblyVersion;

            await Task.WhenAll(zipArtifactsPaths.Select(zipArtifactsPath => Task.Run(() =>
            {
                var zipArtifactsName = Path.GetFileNameWithoutExtension(zipArtifactsPath);
                var zipArtifactsFullPath = Path.Combine(artifactsDir, $"{zipArtifactsName}.{versionString}.zip");
                var zipArtifactsBasePath = Path.GetDirectoryName(Path.GetFullPath(zipArtifactsPath));
                var zipArtifactsDocument = XDocument.Load(zipArtifactsPath);

                var filePaths =
                    zipArtifactsDocument.Root.Elements("file").
                    Where(file => !string.IsNullOrWhiteSpace((string)file.Attribute("src"))).
                    Select(file => Path.Combine(zipArtifactsBasePath, (string)file.Attribute("src"))).
                    ToArray();

                if (File.Exists(zipArtifactsFullPath))
                {
                    File.Move(zipArtifactsFullPath, zipArtifactsFullPath + ".tmp");
                    File.Delete(zipArtifactsFullPath);
                }

                using (var zip = ZipFile.Open(zipArtifactsFullPath, ZipArchiveMode.Create))
                {
                    foreach (var filePath in filePaths.
                        SelectMany(path => Directory.EnumerateFiles(Path.GetDirectoryName(path), Path.GetFileName(path), SearchOption.AllDirectories)))
                    {
                        var entry = zip.CreateEntryFromFile(filePath, filePath.Substring(zipArtifactsBasePath.Length + 1));
                    }
                }

                Program.WriteLine(zipArtifactsFullPath);
            })));
        }

        private static async Task CopyResourceWithReplacementsAsync(
            string resourceName, string path, IReadOnlyDictionary<string, string> replacements)
        {
            using (var sr = new StreamReader(
                typeof(Collectors).Assembly.GetManifestResourceStream(resourceName),
                Encoding.UTF8, true))
            {
                var arduinoProperties = new StringBuilder(await sr.ReadToEndAsync());
                foreach (var entry in replacements)
                {
                    arduinoProperties.Replace(entry.Key, entry.Value);
                }
                File.WriteAllText(path, arduinoProperties.ToString(), Encoding.UTF8);
            }
        }

        public static async Task CollectArduinoArtifactsAsync(string solutionDir, string artifactsDir)
        {
            var arduinoBasePath = Path.Combine(artifactsDir, "Arduino");
            await RecreateDirectoryAsync(arduinoBasePath);

            await CopyResourceWithReplacementsAsync(
                "IL2C.ArtifactCollector.Arduino.properties",
                Path.Combine(arduinoBasePath, "library.properties"),
                new Dictionary<string, string>
                {
                    { "{version}", typeof(Program).Assembly.GetCustomAttribute<AssemblyFileVersionAttribute>().Version },
                    { "{semver2}", typeof(Program).Assembly.GetCustomAttribute<AssemblyInformationalVersionAttribute>().InformationalVersion }
                });

            var fromIncludeDir = Path.Combine(solutionDir, "IL2C.Runtime", "include");
            var toIncludeDir = Path.Combine(arduinoBasePath, "include");
            await Task.WhenAll(
                Directory.EnumerateFiles(fromIncludeDir, "*.h", SearchOption.AllDirectories).
                Select(path => CopyFileAsync(path, Path.Combine(toIncludeDir, path.Substring(fromIncludeDir.Length + 1)))));

            var fromSrcDir = Path.Combine(solutionDir, "IL2C.Runtime", "src");
            var toSrcDir = Path.Combine(arduinoBasePath, "src");
            await Task.WhenAll(
                Directory.EnumerateFiles(fromSrcDir, "*.c", SearchOption.AllDirectories).
                Concat(Directory.EnumerateFiles(fromSrcDir, "*.h", SearchOption.AllDirectories)).
                Select(path => CopyFileAsync(path, Path.Combine(toSrcDir, path.Substring(fromSrcDir.Length + 1)))));
        }
    }
}
