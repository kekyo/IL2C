using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;
using IL2C.ILConveters;
using Mono.Cecil.Cil;

namespace IL2C
{
    [TestFixture]
    public sealed class Test
    {
        [Test]
        public static async Task DumpSupportedOpCodes()
        {
            var ilConverterType = typeof(ILConverter);
            var ilConverters =
                ilConverterType.Assembly.GetTypes()
                .Where(type => type.IsClass && type.IsSealed
                    && ilConverterType.IsAssignableFrom(type)
                    && (type.GetConstructor(Type.EmptyTypes) != null))
                .Select(type => (ILConverter)Activator.CreateInstance(type))
                .ToDictionary(ilConverter => ilConverter.OpCode.Name);
            var opCodes =
                typeof(OpCodes)
                .GetFields(BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly)
                .Where(field => field.FieldType == typeof(OpCode))
                .Select(field => (OpCode)field.GetValue(null))
                .OrderBy(opCode => opCode.Name)
                .ToArray();

            var basePath = Path.GetDirectoryName(typeof(Test).Assembly.Location);
            var path = Path.Combine(basePath, "supported-opcodes.md");

            using (var fs = new FileStream(path, FileMode.Create, FileAccess.ReadWrite, FileShare.None, 65536, true))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteLineAsync("# Supported IL opcodes");
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("OpCode | Status | ILConverter");
                await tw.WriteLineAsync("|:---|:---|:---|");

                foreach (var opCode in opCodes)
                {
                    ilConverters.TryGetValue(opCode.Name, out var ilConverter);
                    await tw.WriteLineAsync(
                        string.Format("| {0} | {1} | {2} |",
                            opCode.Name,
                            (ilConverter != null) ? "Implemented" : string.Empty,
                            ilConverter?.GetType().FullName ?? string.Empty));
                }
            }
        }

        [TestCaseExplicit("Square", 2)]
        public static Task TestTarget(string testName, object[] args)
        {
            return TestFramework.ExecuteTestAsync(typeof(TestTarget), testName, args);
        }
    }
}
