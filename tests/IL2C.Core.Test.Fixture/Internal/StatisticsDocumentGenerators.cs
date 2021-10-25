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

using Mono.Cecil.Cil;
using NUnit.Framework;

using IL2C.ILConverters;

namespace IL2C.Internal
{
    [TestFixture]
    public sealed class StatisticsDocumentGenerators
    {
        private static readonly string generatedDocumentBasePath = Path.GetFullPath(
            Path.Combine(
                Path.GetDirectoryName(typeof(StatisticsDocumentGenerators).Assembly.Location),
                "..",
                "..",
                "..",
                "..",
                "..",
                "docs"));

        private static string GetOpCodeDirectoryName(string name) =>
            name[0] + name.ToLowerInvariant().Substring(1);

        [Test]
        public static async Task DumpSupportedOpCodes()
        {
            var ilConverterType = typeof(ILConverter);
            var ilConverters =
                ilConverterType.Assembly.GetTypes().
                Where(type => type.IsClass && type.IsSealed
                    && ilConverterType.IsAssignableFrom(type)
                    && (type.GetConstructor(Type.EmptyTypes) != null)).
                Select(type => (ILConverter)Activator.CreateInstance(type)).
                ToDictionary(ilConverter => ilConverter.OpCode.Name, StringComparer.InvariantCultureIgnoreCase);

            var refOpCodeNames =
                typeof(System.Reflection.Emit.OpCodes).
                GetFields(BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly).
                Where(field => field.FieldType == typeof(System.Reflection.Emit.OpCode)).
                Select(field =>
                {
                    var opCode = (System.Reflection.Emit.OpCode)field.GetValue(null);
                    return (opCode.Value, field.Name);
                }).
                ToDictionary(entry => entry.Item1, entry => entry.Item2);

            var opCodes =
                typeof(OpCodes).
                GetFields(BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly).
                Where(field => field.FieldType == typeof(OpCode)).
                Select(field =>
                {
                    var opCode = (OpCode)field.GetValue(null);
                    var isEmitRelated = refOpCodeNames.TryGetValue(opCode.Value, out var refOpCodeName);
                    var name = isEmitRelated ? refOpCodeName : opCode.Name;
                    return (name, isEmitRelated, opCode);
                }).
                OrderBy(entry => entry.name).
                ToArray();

            var ilConverterTests =
                TestUtilities.ExtractTestCasesFromCoreTestTarget()["IL2C.ILConverters"].
                SelectMany(entry => entry.Value).
                GroupBy(testCase => testCase.Id).
                ToDictionary(g => g.Key, g => g.Count(), StringComparer.InvariantCultureIgnoreCase);

            var path = Path.Combine(generatedDocumentBasePath, "supported-opcodes.md");

            using (var fs = await TestUtilities.CreateStreamAsync(path))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteLineAsync("# Supported IL opcodes");
                await tw.WriteLineAsync();
                await tw.WriteLineAsync(
                    string.Format("* Number of opcode implementations: {0} / {1}",
                        opCodes.Count(entry => ilConverters.ContainsKey(entry.opCode.Name)),
                        opCodes.Length));
                await tw.WriteLineAsync(
                    string.Format("* Number of opcode tests: {0} [{1} / {2}]",
                        opCodes.Sum(entry => ilConverterTests.TryGetValue(entry.name, out var count) ? count : 0),
                        opCodes.Count(entry => ilConverterTests.ContainsKey(entry.name)),
                        opCodes.Length));
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("OpCode | Binary | Implement | Test | ILConverter");
                await tw.WriteLineAsync("|:---|:---|:---|:---|:---|");

                foreach (var (name, isEmitRelated, opCode) in opCodes)
                {
                    ilConverters.TryGetValue(opCode.Name, out var ilConverter);

                    var opCodeName = opCode.Name.TrimEnd('.');
                    await tw.WriteLineAsync(
                        string.Format("| {0} | 0x{1:x} | {2} | {3} | {4} |",
                            isEmitRelated ?
                                string.Format(
                                    "[{0}](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.{1})",
                                    opCodeName, name.ToLowerInvariant()) :
                                opCodeName,
                            (ushort)opCode.Value,
                            (ilConverter != null) ? "Implemented" : string.Empty,
                            ilConverterTests.TryGetValue(name, out var count) ?
                                string.Format("[Test [{0}]](../tests/IL2C.Core.Test.ILConverters/{1})", count, GetOpCodeDirectoryName(name)) :
                                string.Empty,
                            ilConverter?.GetType().FullName ?? string.Empty));
                }

                await tw.FlushAsync();
            }
        }

        [Test]
        public static async Task DumpSupportedBasicTypes()
        {
            // TODO: Has to add manually 
            var types = new Type[]
            {
                typeof(object),
                typeof(Type),
                typeof(ValueType),
                typeof(Enum),
                typeof(Delegate),
                typeof(Exception),
                typeof(Array),
                typeof(void),
                typeof(byte),
                typeof(sbyte),
                typeof(short),
                typeof(ushort),
                typeof(int),
                typeof(uint),
                typeof(long),
                typeof(ulong),
                typeof(float),
                typeof(double),
                typeof(bool),
                typeof(char),
                typeof(string),
                typeof(IntPtr),
                typeof(UIntPtr),
                typeof(GC),
                typeof(GCHandle),
                typeof(RuntimeFieldHandle),
            }.
            OrderBy(type => type.FullName).
            ToArray();

            var runtimeTypesTests =
                TestUtilities.ExtractTestCasesFromCoreTestTarget()["IL2C.BasicTypes"].
                ToDictionary(entry => entry.Key.Name, entry => new { Name = entry.Key.Name, Count = entry.Value.Count() });

            var path = Path.Combine(generatedDocumentBasePath, "supported-basic-types.md");

            using (var fs = await TestUtilities.CreateStreamAsync(path))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteLineAsync("# Supported basic types");
                await tw.WriteLineAsync();
                await tw.WriteLineAsync(
                    string.Format("* Number of types: {0}",
                        types.Length));
                await tw.WriteLineAsync(
                    string.Format("* Number of tests: {0} [{1} / {2}]",
                        types.Sum(type => runtimeTypesTests.TryGetValue(type.FullName.Replace('.', '_'), out var entry) ? entry.Count : 0),
                        types.Count(type => runtimeTypesTests.ContainsKey(type.FullName.Replace('.', '_'))),
                        types.Length));
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("Type | Test");
                await tw.WriteLineAsync("|:---|:---|");

                foreach (var type in types)
                {
                    runtimeTypesTests.TryGetValue(type.FullName.Replace('.', '_'), out var entry);

                    await tw.WriteLineAsync(
                        string.Format("| [{0}](https://docs.microsoft.com/en-us/dotnet/api/{1}) | {2} |",
                            type.FullName,
                            type.FullName.ToLowerInvariant(),
                            (entry != null) ?
                                ((entry.Count >= 1) ?
                                    string.Format("[Test [{0}]](../tests/IL2C.Core.Test.BasicTypes/{1})", entry.Count, entry.Name) :
                                    string.Empty) :
                                string.Empty));
                }

                await tw.FlushAsync();
            }
        }

        [Test]
        public static async Task DumpSupportedRuntimeSystems()
        {
            var typeSystemsTests =
                TestUtilities.ExtractTestCasesFromCoreTestTarget()["IL2C.RuntimeSystems"].
                SelectMany(entry => entry.Value).
                GroupBy(testCase => testCase.Id).
                ToDictionary(
                    g => g.Key,
                    g => new {
                        Name = g.Key,
                        Count = g.Count(),
                        Description = g.
                            Select(testCase => testCase.Description).
                            Distinct().
                            FirstOrDefault(d => !string.IsNullOrWhiteSpace(d)) ?? string.Empty });

            var path = Path.Combine(generatedDocumentBasePath, "supported-runtime-system-features.md");

            using (var fs = await TestUtilities.CreateStreamAsync(path))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteLineAsync("# Supported runtime system features");
                await tw.WriteLineAsync();
                //await tw.WriteLineAsync(
                //    string.Format("* Number of tests: {0} [{1} / {2}]",
                //        types.Sum(type => typeSystemsTests.TryGetValue(type.FullName.Replace('.', '_'), out var entry) ? entry.Count : 0),
                //        types.Count(type => typeSystemsTests.ContainsKey(type.FullName.Replace('.', '_'))),
                //        types.Length));
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("Feature | Test | Descrition");
                await tw.WriteLineAsync("|:---|:---|:---|");

                foreach (var typeSystemTest in typeSystemsTests.OrderBy(entry => entry.Key))
                {
                    await tw.WriteLineAsync(
                        string.Format("| {0} | [Test [{1}]](../tests/IL2C.Core.Test.RuntimeSystems/{0}) | {2} |",
                        typeSystemTest.Key,
                        typeSystemTest.Value.Count,
                        typeSystemTest.Value.Description));
                }

                await tw.FlushAsync();
            }
        }
    }
}
