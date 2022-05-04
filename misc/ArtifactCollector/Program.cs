﻿////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace IL2C.ArtifactCollector
{
    public static class Program
    {
        private static readonly object locker = new object();

        public static void WriteLine(string message)
        {
            lock (locker)
            {
                Console.WriteLine(message);
            }
        }

        public static void WriteLine(string format, params object[] args) =>
            WriteLine(string.Format(format, args));

        private static async Task<int> MainAsync(string[] args)
        {
            try
            {
                var solutionDir = Path.GetFullPath(args[0]);
                var artifactsDir = Path.GetFullPath(args[1]);
                var buildIdentifier = args[2];
                var dirNames = args.Skip(3).ToArray();

                WriteLine("/////////////////////////////////////////////////////\r\nIL2C artifact collector");
                WriteLine("SolutionDir={0}",
                    solutionDir);
                WriteLine("ArtifactsDir={0}",
                    artifactsDir);
                WriteLine("Build identifier={0}",
                    buildIdentifier);
                WriteLine("Target version={0}",
                    ThisAssembly.AssemblyVersion);

                await Collectors.RecreateDirectoryAsync(artifactsDir);

                var csprojPaths = dirNames.
                    SelectMany(p => Directory.GetFiles(Path.Combine(solutionDir, p), "*.csproj")).
                    ToArray();

                var nuspecPaths = dirNames.
                    SelectMany(p => Directory.GetFiles(Path.Combine(solutionDir, p), "*.nuspec")).
                    Where(p => !csprojPaths.Any(csprojPath => Path.GetDirectoryName(csprojPath) == Path.GetDirectoryName(p))).
                    ToArray();

                WriteLine("\r\n/////////////////////////////////////////////////////\r\n// Collect for {0}\r\n\r\n",
                    string.Join(", ", csprojPaths.Select(p => Path.GetFileName(p))));

                await Collectors.BuildCsprojAndCollectArtifactsAsync(
                    solutionDir, artifactsDir, buildIdentifier, csprojPaths);

                WriteLine("\r\n/////////////////////////////////////////////////////\r\n// Collect for {0}\r\n\r\n",
                    string.Join(", ", nuspecPaths.Select(p => Path.GetFileName(p))));

                await Collectors.BuildNuspecAndCollectArtifactsAsync(
                    solutionDir, artifactsDir, buildIdentifier, nuspecPaths);

                var zipArtifactsPaths = dirNames.
                    SelectMany(p => Directory.GetFiles(Path.Combine(solutionDir, p), "*.zaspec")).
                    ToArray();

                WriteLine("\r\n/////////////////////////////////////////////////////\r\n// Collect for {0}\r\n\r\n",
                    string.Join(", ", zipArtifactsPaths.Select(p => Path.GetFileName(p))));

                await Collectors.BuildZipFromCollectArtifactsAsync(
                    artifactsDir, zipArtifactsPaths);

                WriteLine("\r\n/////////////////////////////////////////////////////\r\n// Collect for {0}\r\n\r\n",
                    "Arduino library");

                await Collectors.CollectArduinoArtifactsAsync(solutionDir, artifactsDir);
            }
            catch (Exception ex)
            {
                WriteLine(ex.ToString());
                return Marshal.GetHRForException(ex);
            }

            return 0;
        }

        public static int Main(string[] args) =>
            MainAsync(args).Result;
    }
}