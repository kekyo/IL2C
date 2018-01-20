using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace UEFI.Code
{
    public class Expression
    {
        public readonly Expression Lhs;
        public readonly Expression Rhs;
        public readonly char Oper;

        private Expression(Expression lhs, Expression rhs, char oper)
        {
            this.Lhs = lhs;
            this.Rhs = rhs;
            this.Oper = oper;
        }
    }

    public class ReversePolishNotation
    {
        private static Expression Parse(string line, int startIndex)
        {
            var index = startIndex;
            while (index < line.Length)
            {
                
            }
            return null;
        }

        public static void Main()
        {
            while (true)
            {
                Console.Write("RPN> ");
                var line = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(line) == false)
                {
                    var expr = Parse(line, 0);
                }
            }
        }
    }
}
