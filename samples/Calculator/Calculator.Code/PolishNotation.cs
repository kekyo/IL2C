using System;
using System.Runtime.CompilerServices;

[assembly: InternalsVisibleTo("Calculator.Code.Tests")]

namespace Calculator
{
    public abstract class AbstractNode
    {
        public readonly int NextIndex;

        protected AbstractNode(int nextIndex)
        {
            this.NextIndex = nextIndex;
        }
    }

    public class OperatorNode : AbstractNode
    {
        public readonly char Operator;

        public OperatorNode(char oper, int nextIndex) : base(nextIndex)
        {
            this.Operator = oper;
        }
    }

    public abstract class ReducibleNode : AbstractNode
    {
        protected ReducibleNode(int nextIndex) : base(nextIndex)
        {
        }

        public abstract int Reduce();
    }

    public class NumericNode : ReducibleNode
    {
        public readonly int Numeric;

        public NumericNode(int numeric, int nextIndex) : base(nextIndex)
        {
            this.Numeric = numeric;
        }

        public override int Reduce()
        {
            return this.Numeric;
        }
    }

    public class ExpressionNode : ReducibleNode
    {
        public readonly OperatorNode Operator;
        public readonly ReducibleNode Left;
        public readonly ReducibleNode Right;

        public ExpressionNode(OperatorNode oper, ReducibleNode left, ReducibleNode right, int nextIndex) : base(nextIndex)
        {
            this.Operator = oper;
            this.Left = left;
            this.Right = right;
        }

        public override int Reduce()
        {
            var leftResult = this.Left.Reduce();
            var rightResult = this.Right.Reduce();
            if (this.Operator.Operator == '+')
            {
                return leftResult + rightResult;
            }
            if (this.Operator.Operator == '-')
            {
                return leftResult - rightResult;
            }
            if (this.Operator.Operator == '*')
            {
                return leftResult * rightResult;
            }
            if (this.Operator.Operator == '/')
            {
                return leftResult / rightResult;
            }

            // Invalid
            return 0;
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
                if (ch == ' ')
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
            if (int.TryParse(token, out var numeric) == false)
            {
                return null;
            }

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

            ReducibleNode left = ParseNumeric(line, oper.NextIndex);
            if (left == null)
            {
                left = ParseExpression(line, oper.NextIndex);
                if (left == null)
                {
                    return null;
                }
            }

            ReducibleNode right = ParseNumeric(line, left.NextIndex);
            if (right == null)
            {
                right = ParseExpression(line, left.NextIndex);
                if (right == null)
                {
                    return null;
                }
            }

            var index = SkipWhiteSpace(line, right.NextIndex);
            return new ExpressionNode(oper, left, right, index);
        }

        public static void Main()
        {
            Console.WriteLine("Polish notation calculator.");
            Console.WriteLine("This is proof of concept for IL2C.");
            Console.WriteLine("https://github.com/kekyo/IL2C");
            Console.WriteLine();
            Console.WriteLine("Type \"exit\" to exit.");

            while (true)
            {
                Console.WriteLine();
                Console.Write("PN> ");
                var line = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(line) == false)
                {
                    if (line == "exit")
                    {
                        return;
                    }

                    var expr = ParseExpression(line, 0);
                    if (expr == null)
                    {
                        Console.WriteLine("Syntax error.");
                        continue;
                    }

                    var result = expr.Reduce();

                    Console.Write("Reuslt=");
                    Console.WriteLine(result);
                }
            }
        }
    }
}
