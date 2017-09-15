using System;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

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
        static void Main(string[] args)
        {
            var opCodesType = typeof(OpCodes);
            var opCodeList = opCodesType.GetFields(
                BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly);
            var opCodes = opCodeList
                .Select(fi => (OpCode)fi.GetValue(null))
                .Where(opCode => opCode.OpCodeType != OpCodeType.Nternal)
                .ToDictionary(opCode => (ushort)opCode.Value, opCode => opCode);

            var testType = typeof(Test);
            var mainMethod = testType.GetMethods().First();
            var mainBody = mainMethod.GetMethodBody();
            var locals = mainBody.LocalVariables;
            var ilBytes = mainBody.GetILAsByteArray();

            var index = 0;
            while (index < ilBytes.Length)
            {
                var byte0 = ilBytes[index++];
                if (opCodes.TryGetValue(byte0, out var opCode) == false)
                {
                    var byte1 = ilBytes[index++];
                    var word = (ushort)(byte0 << 8 | byte1);
                    opCode = opCodes[word];
                }

                switch (opCode.OperandType)
                {
                    case OperandType.ShortInlineBrTarget:
                        var operand = ilBytes[index++];
                        Console.WriteLine("{0} {1}", opCode.Name, operand);
                        break;
                    default:
                        Console.WriteLine(opCode.Name);
                        break;
                }
            }
        }
    }
}
