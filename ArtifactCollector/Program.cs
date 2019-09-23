/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
                    typeof(Program).Assembly.GetName().Version);

                await Collectors.RecreateDirectoryAsync(artifactsDir);

                var csprojPaths = dirNames.
                    SelectMany(p => Directory.GetFiles(Path.Combine(solutionDir, p), "*.csproj")).
                    ToArray();

                WriteLine("\r\n/////////////////////////////////////////////////////\r\n// Collect for {0}\r\n\r\n",
                    string.Join(", ", csprojPaths.Select(p => Path.GetFileName(p))));

                await Collectors.BuildCsprojAndCollectArtifactsAsync(
                    solutionDir, artifactsDir, buildIdentifier, csprojPaths);

                var nuspecPaths = dirNames.
                    SelectMany(p => Directory.GetFiles(Path.Combine(solutionDir, p), "*.nuspec")).
                    ToArray();

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
