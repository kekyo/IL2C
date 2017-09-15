using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using il2c.ILConveters;

namespace il2c
{
    class Test
    {
        public static int main()
        {
            var a = 1;
            var b = 2;
            var c = a + b;
            return c;
        }
    }

    class Program
    {
        private static readonly Dictionary<ushort, ILConverter> ilConverters;

        static Program()
        {
            ilConverters = typeof(ILConverter)
                .Assembly
                .GetTypes()
                .Where(type => type.IsSealed && typeof(ILConverter).IsAssignableFrom(type))
                .Select(type => (ILConverter) Activator.CreateInstance(type))
                .ToDictionary(ilc => (ushort) ilc.OpCode.Value);
        }

        private sealed class ILData
        {
            public readonly ILConverter ILConverter;
            public readonly object Operand;

            public ILData(ILConverter ilc)
            {
                this.ILConverter = ilc;
                this.Operand = null;
            }

            public ILData(ILConverter ilc, object operand)
            {
                this.ILConverter = ilc;
                this.Operand = operand;
            }

            public string Apply(Stack<string> stack)
            {
                return this.ILConverter.Apply(this.Operand, stack);
            }
        }

        private static IEnumerable<ILData> DecodeAndEnumerateOpCodes(MethodBody methodBody)
        {
            var ilBytes = methodBody.GetILAsByteArray();

            var index = 0;
            while (index < ilBytes.Length)
            {
                var byte0 = ilBytes[index++];
                if (ilConverters.TryGetValue(byte0, out var ilc) == false)
                {
                    var byte1 = ilBytes[index++];
                    var word = (ushort)(byte0 << 8 | byte1);
                    ilc = ilConverters[word];
                }

                switch (ilc.OpCode.OperandType)
                {
                    case OperandType.ShortInlineBrTarget:
                        object operand = ilBytes[index++];
                        yield return new ILData(ilc, operand);
                        break;
                    default:
                        yield return new ILData(ilc);
                        break;
                }
            }
        }

        private static string GetCLanguageTypeName(Type type)
        {
            return (type == typeof(System.Int32)) ? "int" : type.FullName;
        }

        static void Main(string[] args)
        {
            var testType = typeof(Test);
            var mainMethod = testType.GetMethods().First();

            var mainBody = mainMethod.GetMethodBody();
            var locals = mainBody.LocalVariables;

            var returnTypeName =
                GetCLanguageTypeName(mainMethod.ReturnType);

            Console.WriteLine("{0} {1}(void)", returnTypeName, mainMethod.Name);
            Console.WriteLine("{");

            foreach (var local in locals)
            {
                Console.WriteLine(
                    "{0} local{1};",
                    GetCLanguageTypeName(local.LocalType),
                    local.LocalIndex);                
            }

            Console.WriteLine();

            var stack = new Stack<string>();
            foreach (var ilData in DecodeAndEnumerateOpCodes(mainBody))
            {
                var sourceCode = ilData.Apply(stack);
                if (sourceCode != null)
                {
                    Console.WriteLine(sourceCode);
                }
            }

            Console.WriteLine("}");
        }
    }
}
