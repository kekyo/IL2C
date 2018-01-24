using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace UEFI.Code
{
    public abstract class PolishNotationNode
    {
        public readonly int NextIndex;

        protected PolishNotationNode(int nextIndex)
        {
            this.NextIndex = nextIndex;
        }
    }

    public class OperatorNode : PolishNotationNode
    {
        public readonly char Operator;

        public OperatorNode(char oper, int index) : base(index)
        {
            this.Operator = oper;
        }
    }
    
    public class NumericNode : PolishNotationNode
    {
        public readonly int Numeric;

        public NumericNode(int numeric, int index) : base(index)
        {
            this.Numeric = numeric;
        }
    }

    public class ExpressionNode : PolishNotationNode
    {
        public readonly OperatorNode Operator;
        public readonly NumericNode LeftNumeric;
        public readonly NumericNode RightNumeric;

        public ExpressionNode(OperatorNode oper, NumericNode leftNumeric, NumericNode rightNumeric, int index) : base(index)
        {
            this.Operator = oper;
            this.LeftNumeric = leftNumeric;
            this.RightNumeric = rightNumeric;
        }
    }

    public class CombinedExpressionNode : PolishNotationNode
    {
        public readonly ExpressionNode FirstExpression;
        public readonly ExpressionNode SecondExpression;

        public CombinedExpressionNode(ExpressionNode firstExpression, ExpressionNode secondExpression, int index) : base(index)
        {
            this.FirstExpression = firstExpression;
            this.SecondExpression = secondExpression;
        }
    }

    public class PolishNotation
    {
        internal static int SkipWhiteSpace(string line, int startIndex)
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

        internal static OperatorNode ParseOperator(string line, int startIndex)
        {
            if (startIndex >= line.Length)
            {
                return null;
            }

            var index = startIndex;
            var ch = line[index];
            if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/'))
            {
                return null;
            }
            index++;

            index = SkipWhiteSpace(line, index);
            return new OperatorNode(ch, index);
        }

        internal static NumericNode ParseNumeric(string line, int startIndex)
        {
            if (startIndex >= line.Length)
            {
                return null;
            }

            var index = startIndex;
            while (index < line.Length)
            {
                var ch = line[index];
                if ((((ch >= '0') && (ch <= '9')) || (ch == '-')) == false)
                {
                    break;
                }
                index++;
            }

            if (index == startIndex)
            {
                return null;
            }

            var token = line.Substring(startIndex, index - startIndex);
            var numeric = int.Parse(token);

            index = SkipWhiteSpace(line, index);
            return new NumericNode(numeric, index);
        }

        internal static ExpressionNode ParseExpression(string line, int startIndex)
        {
            if (startIndex >= line.Length)
            {
                return null;
            }

            var oper = ParseOperator(line, startIndex);
            if (oper == null)
            {
                return null;
            }

            var numericLeft = ParseNumeric(line, oper.NextIndex);
            if (numericLeft == null)
            {
                return null;
            }

            var numericRight = ParseNumeric(line, numericLeft.NextIndex);
            if (numericRight == null)
            {
                return null;
            }

            var index = SkipWhiteSpace(line, numericRight.NextIndex);
            return new ExpressionNode(oper, numericLeft, numericRight, index);
        }

        //internal static CombinedExpressionResult ParseCombinedExpression(string line, int startIndex)
        //{
            
        //}

        public static void Main()
        {
            while (true)
            {
                Console.WriteLine();
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
