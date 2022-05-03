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
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace IL2C.Internal
{
    internal static class CMakeDriver
    {
#if false
        public static async Task<string> BuildAsync(
            string binPath, string configuration, string sourcePath, string il2cRuntimePath)
        {
            var basePath = Path.GetDirectoryName(sourcePath);
            var outPath = Path.Combine(basePath, "build");
            var executablePath = Path.Combine(
                outPath,
                Path.GetFileNameWithoutExtension(sourcePath) + (TestUtilities.IsWindows ? ".exe" : string.Empty));

            var targetCMakeScriptName = TestUtilities.IsWindows ?  // DIRTY: ugly choice only win-mingw32 or linux...
                "gcc4-win-mingw32.cmake" : "gcc-linux.cmake";

            // Step1: Generate ninja script by cmake.
            if (!Directory.Exists(outPath))
            {
                Directory.CreateDirectory(outPath);

                var scriptPath = Path.Combine(basePath, "CMakeLists.txt");
                await TestUtilities.CopyResourceToTextFileAsync(scriptPath, "CMakeLists.txt");

                try
                {
                    var cmakeLog = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
                    {
                        var (exitCode, log) = await TestUtilities.ExecuteAsync(
                            outPath,
                            "gen",
                            TestUtilities.IsWindows ? new[] { binPath } : Array.Empty<string>(),
                            TestUtilities.IsWindows ? Path.Combine(binPath, "cmake.exe") : "cmake",
                            "-G",
                            "Ninja",
                            TestUtilities.IsWindows ? "-DCMAKE_MAKE_PROGRAM=ninja.exe" : "-DCMAKE_MAKE_PROGRAM=ninja",
                            TestUtilities.IsWindows ? "-DPLATFORM=mingw32" : "-DPLATFORM=x86_64",
                            $"-DCONFIGURATION={configuration}",
                            $"-DCMAKE_TARGET_SCRIPT_NAME={targetCMakeScriptName}",
                            "..");
                        if (exitCode != 0)
                        {
                            throw new Exception($"cmake [Path=\"{basePath}\", ExitCode={exitCode}]: {log}");
                        }
                        return log;
                    });
                }
                catch
                {
                    try
                    {
                        Directory.Delete(outPath, true);
                    }
                    catch
                    {
                    }
                    throw;
                }
            }

            // Step2: Execute ninja
            var cmakeNinjaLog = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath,
                    "build",
                    TestUtilities.IsWindows ? new[] { binPath } : Array.Empty<string>(),
                    TestUtilities.IsWindows ? Path.Combine(binPath, "cmake.exe") : "cmake",
                    "--build",
                    ".",
                    "-j");
                if (exitCode != 0)
                {
                    throw new Exception($"cmake [ninja] [Path=\"{basePath}\", ExitCode={exitCode}]: {log}");
                }
                return log;
            });

            // Step3: Execute native binary
            var testLog = await TestUtilities.RetryIfStrangeProblemAsync(async () =>
            {
                var (exitCode, log) = await TestUtilities.ExecuteAsync(
                    outPath,
                    "run",
                    new[] { outPath },
                    executablePath);
                if (exitCode != 0)
                {
                    throw new Exception($"test [Path=\"{basePath}\", ExitCode={exitCode}]: {log}");
                }
                return log;
            });

            return testLog;
        }
#else
        // FASTER than cmake: It's direct gcc driver with self-parsing cmake configuration.
        public static async Task<string> BuildAsync(
            string binPath, string configuration, string sourcePath, string il2cRuntimePath)
        {
            var basePath = Path.GetDirectoryName(sourcePath);
            var outPath = Path.Combine(basePath, "build");
            var executablePath = Path.Combine(
                outPath,
                Path.GetFileNameWithoutExtension(sourcePath) + (TestUtilities.IsWindows ? ".exe" : string.Empty));

            var currentListDir = Path.GetFullPath(
                Path.Combine(il2cRuntimePath, "cmake"));
            var targetCMakeScriptName = TestUtilities.IsWindows ?  // DIRTY: ugly choice only win-mingw32 or linux...
                "gcc4-win-mingw32.cmake" : "gcc-linux.cmake";
            var dict = await CMakeListsSimpleParser.ExtractDefinitionsAsync(
                Path.Combine(currentListDir, targetCMakeScriptName),
                new Dictionary<string, string>(StringComparer.InvariantCultureIgnoreCase) {
                    { "Configuration", configuration },
                    { "Platform", TestUtilities.IsWindows ? "mingw32" : "x86_64" },   // DIRTY: `uname -m` on Ubuntu 20.04
                    { "CMAKE_CURRENT_LIST_DIR", currentListDir },
                    { "CMAKE_TARGET_SCRIPT_NAME", targetCMakeScriptName },
                });

            var incDir = dict.TryGetValue("INCDIR", out var id) ? id : string.Empty;
            var libDir = dict.TryGetValue("LIBDIR", out var ld) ? ld : string.Empty;
            var cdefs = dict.TryGetValue("COMPILE_DEFINITIONS", out var cd) ? cd : string.Empty;
            var ccflags = dict.TryGetValue("CMAKE_C_FLAGS", out var ccf) ? ccf : string.Empty;
            
            // IL2C library implicitly included into CMAKE_REQUIRED_LIBRARIES on cmake script.
            var libs = string.Join(" ",
                (dict.TryGetValue("CMAKE_REQUIRED_LIBRARIES", out var rl) ?
                rl.Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(lib => $"-l{lib}") : Array.Empty<string>()));

            if (!Directory.Exists(outPath))
            {
                Directory.CreateDirectory(outPath);

                var scriptPath = Path.Combine(basePath, "CMakeLists.txt");
                await TestUtilities.CopyResourceToTextFileAsync(scriptPath, "CMakeLists.txt");
            }

            // Step1: Execute gcc
            var (gccExitCode, gccLog) = await TestUtilities.ExecuteAsync(
                outPath,
                "build",
                TestUtilities.IsWindows ? new[] { binPath } : Array.Empty<string>(),
                TestUtilities.IsWindows ? Path.Combine(binPath, "gcc.exe") : "gcc",   // NOT windows: uses system default gcc.
                $"-I{basePath}",
                incDir,
                libDir,
                cdefs,
                ccflags,
                "-o",
                executablePath,
                sourcePath,
                libs);
            if (gccExitCode != 0)
            {
                throw new Exception($"gcc [Path=\"{basePath}\", ExitCode={gccExitCode}]: {gccLog}");
            }

            // Step2: Execute native binary
            var (testExitCode, testLog) = await TestUtilities.ExecuteAsync(
                outPath,
                "run",
                new[] { outPath },
                executablePath);
            if (testExitCode != 0)
            {
                throw new Exception($"test [Path=\"{basePath}\", ExitCode={testExitCode}]: {testLog}");
            }

            return testLog;
        }
#endif
    }
}
