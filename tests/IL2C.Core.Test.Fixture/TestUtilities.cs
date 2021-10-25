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
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

using IL2C.Internal;

namespace IL2C
{
    internal static class TestUtilities
    {
        private static readonly Encoding utf8 = new UTF8Encoding(false);

        #region Test case related
        private static object ConvertToArgumentType(object value, Type argumentType)
        {
            // This is helper function that convert between raw value type and argument type.
            // Because .NET attribute can't have complex type arguments.
            if (value == null)
            {
                return null;
            }
            else if (value.GetType() == argumentType)
            {
                return value;
            }
            else if (argumentType == typeof(IntPtr))
            {
                if (value is int)
                {
                    return new IntPtr((int)value);
                }
                else if (value is long)
                {
                    return new IntPtr((long)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else if (argumentType == typeof(UIntPtr))
            {
                if (value is uint)
                {
                    return new UIntPtr((uint)value);
                }
                else if (value is ulong)
                {
                    return new UIntPtr((ulong)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else
            {
                return Convert.ChangeType(value, argumentType);
            }
        }

        public static IReadOnlyDictionary<string, IReadOnlyDictionary<Type, TestCaseInformation[]>> ExtractTestCasesFromCoreTestTarget() =>
            typeof(BasicTypes.System_Boolean).Assembly.GetTypes().          // BasicTypes
            Concat(typeof(ILConverters.Add).Assembly.GetTypes()).           // ILConverters
            Concat(typeof(RuntimeSystems.ArrayTypes).Assembly.GetTypes()).  // RuntimeSystems
            Where(type => type.IsPublic && type.IsClass && !type.IsAbstract && type.IsDefined(typeof(TestCaseAttribute))).
            GroupBy(type => type.Namespace).
            ToDictionary(
                g => g.Key,
                g => (IReadOnlyDictionary<Type, TestCaseInformation[]>)g.ToDictionary(type => type, TestUtilities.GetTestCaseInformations));

        public static TestCaseInformation CreateTestCaseInformation(
            string categoryName, string id, string name, string uniqueName, string description,
            MethodInfo method, MethodBase[] additionalMethods, TestCaseAttribute caseAttribute) =>
            new TestCaseInformation(
                categoryName,
                id,
                name,
                uniqueName,
                description,
                ConvertToArgumentType(caseAttribute.Expected, method.ReturnType),
                caseAttribute.Assert,
                method,
                (caseAttribute.IncludeBaseTypes ?
                    method.DeclaringType.BaseType.Traverse(type => type.BaseType).Concat(caseAttribute.IncludeTypes) :
                    caseAttribute.IncludeTypes).
                    ToArray(),
                additionalMethods,
                caseAttribute.Arguments.
                    Zip(method.GetParameters().Select(p => p.ParameterType), (arg, type) => ConvertToArgumentType(arg, type)).
                    ToArray(),
                caseAttribute.IgnoreILErrors);

        private static IEnumerable<Type> TraverseTypes(Type targetType, bool includeBaseTypes) =>
            includeBaseTypes ?
                targetType.Traverse(type => type.BaseType) :
                new[] { targetType };

        public static TestCaseInformation[] GetTestCaseInformations(Type targetType)
        {
            var categoryName = targetType.
                Namespace.Split('.').Last();
            var id = targetType.
                GetCustomAttribute<TestIdAttribute>()?.Id ??
                targetType.Name;

            var caseInfos =
                (from testCase in targetType.GetCustomAttributes<TestCaseAttribute>(true)
                 let method = targetType.GetMethod(
                     testCase.MethodName,
                     BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly)    // Static method only for test entry
                 where method != null
                 let additionalMethods =
                    testCase.AdditionalMethodNames.
                    SelectMany(methodName =>
                        TraverseTypes(targetType, testCase.IncludeBaseTypes).
                        SelectMany(type => type.GetMembers(
                            BindingFlags.Public | BindingFlags.NonPublic |
                            BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly).  // Both instance or static method
                            OfType<MethodBase>().
                            Where(m => m.Name == methodName))).
                    Concat(testCase.IncludeTypes.SelectMany(type => type.GetMembers(   // The IncludeTypes import all members implicitly.
                        BindingFlags.Public | BindingFlags.NonPublic |
                        BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly).  // Both instance or static method
                        OfType<MethodBase>())).
                    ToArray()
                 let totalAdditionalMethods =
                    // If contains instance method in set of additional methods (test case is implicitly required the instance), add the constructor.
                    (additionalMethods.Any(m => !m.IsStatic) ?
                        new[] { (MethodBase)targetType.GetConstructor(Type.EmptyTypes) } :
                        new MethodBase[0]).
                    Concat(additionalMethods).
                    ToArray()
                 group new { testCase, method, AdditionalMethods = totalAdditionalMethods } by method.Name).
                 SelectMany(g => g.Select((entry, index) => CreateTestCaseInformation(
                        categoryName, id, entry.method.Name, entry.method.Name + "_" + index, entry.method.DeclaringType.GetCustomAttribute<DescriptionAttribute>()?.Description ?? string.Empty,
                        entry.method, entry.AdditionalMethods, entry.testCase))).
                 OrderBy(caseInfo => caseInfo.Name).
                 ToArray();
            return caseInfos;
        }
        #endregion

        #region IO related
        public static readonly bool IsWindows =
            Environment.OSVersion.Platform == PlatformID.Win32NT;

        private static bool IsStrangeProblemException(Exception ex) =>
            ex.Message.Contains("not a valid application") ||
            ex.Message.Contains("it is being used by another process") ||
            ex.Message.Contains("system cannot find the file specified") ||
            ex.Message.Contains("file or directory is corrupted and unreadable") ||
            ex.Message.Contains("Permission denied") ||
            ex.Message.Contains("ExitCode=-1073741819");

        // HACK: If use offloading Task rarely causes strange problems, it's workaround by retry. ¯\_(ツ)_/¯
        public static async Task<T> RetryIfStrangeProblemAsync<T>(Func<T> func, int count = 16)
        {
            while (true)
            {
                try
                {
                    return func();
                }
                catch (Exception ex)
                {
                    if (!IsStrangeProblemException(ex))
                    {
                        throw;
                    }
                    if (count-- == 0)
                    {
                        throw;
                    }
                }
                await Task.Delay(100);
            }
        }

        // HACK: If use offloading Task rarely causes strange problems, it's workaround by retry. ¯\_(ツ)_/¯
        public static async Task<T> RetryIfStrangeProblemAsync<T>(Func<Task<T>> func, int count = 16)
        {
            while (true)
            {
                try
                {
                    return await func();
                }
                catch (Exception ex)
                {
                    if (!IsStrangeProblemException(ex))
                    {
                        throw;
                    }
                    if (count-- == 0)
                    {
                        throw;
                    }
                }
                await Task.Delay(100);
            }
        }

        public static Task<Stream> CreateStreamAsync(string path) =>
            RetryIfStrangeProblemAsync(() =>
            {
                var basePath = Path.GetDirectoryName(path);
                while (!Directory.Exists(basePath))
                {
                    try
                    {
                        Directory.CreateDirectory(basePath);
                    }
                    catch
                    {
                    }
                }
                return (Stream)new FileStream(
                    path,
                    FileMode.Create, FileAccess.ReadWrite, FileShare.None,
                    65536, true);
            });

        public static async Task WriteTextFileAsync(
            TextWriter tw, TextReader from, IReadOnlyDictionary<string, object> replaceValues)
        {
            while (true)
            {
                var line = await from.ReadLineAsync();
                if (line == null)
                {
                    break;
                }

                if (replaceValues.Count >= 1)
                {
                    var sb = new StringBuilder(line);
                    foreach (var entry in replaceValues)
                    {
                        sb.Replace("{" + entry.Key + "}", entry.Value.ToString());
                    }
                    await tw.WriteLineAsync(sb.ToString());
                }
                else
                {
                    await tw.WriteLineAsync(line);
                }
            }

            await tw.FlushAsync();
        }

        public static async Task WriteTextFileAsync(
            string path, TextReader tr, IReadOnlyDictionary<string, object> replaceValues)
        {
            using (var fs = await CreateStreamAsync(path))
            {
                var tw = new StreamWriter(fs, utf8);
                await WriteTextFileAsync(tw, tr, replaceValues);
                fs.Close();
            }
        }

        public static Task WriteTextFileAsync(
            string path, string text, IReadOnlyDictionary<string, object> replaceValues) =>
            WriteTextFileAsync(path, new StringReader(text), replaceValues);

        private static readonly Dictionary<string, object> empty = new Dictionary<string, object>();

        public static Task WriteTextFileAsync(
            string path, TextReader tr) =>
            WriteTextFileAsync(path, tr, empty);

        public static Task WriteTextFileAsync(
            string path, string text) =>
            WriteTextFileAsync(path, text, empty);

        public static async Task CopyResourceToStreamAsync(
            Stream targetStream, string resourceName, IReadOnlyDictionary<string, object> replaceValues)
        {
            using (var ts = typeof(TestFramework).Assembly.GetManifestResourceStream(
                "IL2C.Templates." + resourceName))
            {
                var tr = new StreamReader(ts, utf8, true);
                var tw = new StreamWriter(targetStream, utf8);
                await WriteTextFileAsync(tw, tr, replaceValues);
                await tw.FlushAsync();
            }
        }

        public static Task CopyResourceToStreamAsync(
            Stream targetStream, string resourceName) =>
            CopyResourceToStreamAsync(targetStream, resourceName, empty);

        public static async Task CopyResourceToTextFileAsync(
            string path, string resourceName, IReadOnlyDictionary<string, object> replaceValues)
        {
            using (var ts = typeof(TestFramework).Assembly.GetManifestResourceStream(
                "IL2C.Templates." + resourceName))
            {
                var tr = new StreamReader(ts, utf8, true);
                await WriteTextFileAsync(path, tr, replaceValues);
            }
        }

        public static Task CopyResourceToTextFileAsync(
            string path, string resourceName) =>
            CopyResourceToTextFileAsync(path, resourceName, empty);

        public static async Task<(int, string)> ExecuteAsync(
            string workingPath, string scriptName, string[] searchPaths, string executablePath, params object[] args)
        {
            if (IsWindows)
            {
                File.WriteAllText(
                    Path.Combine(workingPath, scriptName + ".bat"),
                    string.Join(Environment.NewLine, new[]
                    {
                        "@echo off",
                        string.Empty,
                        "rem IL2C: It is a pseudo script.",
                        string.Empty,
                        $"set PATH={string.Join(";",searchPaths)};%PATH%",
                        string.Empty,
                        $"cd \"{workingPath}\"",
                        string.Empty,
                        $"\"{executablePath}\" {string.Join(" ", args)}",
                        string.Empty,
                    }),
                    new UTF8Encoding(false, true));
            }
            else
            {
                File.WriteAllText(
                    Path.Combine(workingPath, scriptName + ".sh"),
                    string.Join(Environment.NewLine, new[]
                    {
                        "#!/bin/sh",
                        string.Empty,
                        "# IL2C: It is a pseudo script.",
                        string.Empty,
                        $"export PATH=\"{string.Join(":",searchPaths)}:$PATH\"",
                        string.Empty,
                        $"cd \"{workingPath}\"",
                        string.Empty,
                        $"\"{executablePath}\" {string.Join(" ", args)}",
                        string.Empty,
                    }),
                    new UTF8Encoding(false, true));
            }
            
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

                await RetryIfStrangeProblemAsync(() => p.Start());

                p.BeginOutputReadLine();
                p.BeginErrorReadLine();

                var exitCode = await tcs.Task;

                p.WaitForExit();

                p.CancelOutputRead();
                p.CancelErrorRead();

                return (exitCode, sb.ToString());
            }
        }
        #endregion
    }
}
