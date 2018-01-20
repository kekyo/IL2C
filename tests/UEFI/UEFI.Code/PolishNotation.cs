using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace UEFI.Code
{
    public struct OperatorResult
    {
        public readonly char Operator;
        public readonly int Index;

        public OperatorResult(char oper, int index)
        {
            this.Operator = oper;
            this.Index = index;
        }
    }

    public struct NumericResult
    {
        public readonly int Numeric;
        public readonly int Index;

        public NumericResult(int numeric, int index)
        {
            this.Numeric = numeric;
            this.Index = index;
        }
    }

    public class PolishNotation
    {
        private static int SkipWhiteSpace(string line, int startIndex)
        {
            var index = startIndex;
            while (index < line.Length)
            {
                var ch = line[index];
                if ((ch != ' ') && (ch != '\t'))
                {
                    break;
                }
                index++;
            }

            return index;
        }

        private static OperatorResult ParseOperator(string line, int startIndex)
        {
            var index = startIndex;
            var ch = line[index++];

            index = SkipWhiteSpace(line, index);
            return new OperatorResult(ch, index);
        }

        private static NumericResult ParseNumeric(string line, int startIndex)
        {
            var index = startIndex;
            while (index < line.Length)
            {
                var ch = line[index];
                if ((ch < '0') || (ch > '9'))
                {
                    break;
                }
                index++;
            }

            var token = line.Substring(startIndex, index - startIndex);
            var numeric = int.Parse(token);

            index = SkipWhiteSpace(line, index);
            return new NumericResult(numeric, index);
        }

        public static void Main()
        {
            while (true)
            {
                Console.Write("PN> ");
                var line = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(line) == false)
                {
                    var expr = ParseOperator(line, 0);
                }
            }
        }
    }
}
