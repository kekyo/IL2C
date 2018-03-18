using System;
using NUnit.Framework;

namespace Calculator
{
    [TestFixture]
    public class PolishNotationTests
    {
        #region SkipWhiteSpace
        [Test]
        public void SkipWhiteSpaceFromIndex0Test()
        {
            var index = PolishNotation.SkipWhiteSpace("   ", 0);

            Assert.AreEqual(3, index);
        }

        [Test]
        public void SkipWhiteSpaceTest()
        {
            var index = PolishNotation.SkipWhiteSpace("     ", 2);

            Assert.AreEqual(5, index);
        }
        #endregion

        #region ParseOperator
        [Test]
        public void OperatorAddParseFromIndex0Test()
        {
            var oper = PolishNotation.ParseOperator("+", 0);

            Assert.AreEqual('+', oper.Operator);
            Assert.AreEqual(1, oper.NextIndex);
        }

        [Test]
        public void OperatorAddParseWithTrailingSpaceTest()
        {
            var oper = PolishNotation.ParseOperator("+   ", 0);

            Assert.AreEqual('+', oper.Operator);
            Assert.AreEqual(4, oper.NextIndex);
        }

        [Test]
        public void OperatorAddParseBeginningPartialIndexTest()
        {
            var oper = PolishNotation.ParseOperator("  +  ", 2);

            Assert.AreEqual('+', oper.Operator);
            Assert.AreEqual(5, oper.NextIndex);
        }
        #endregion

        #region ParseNumeric
        [Test]
        public void NumericParseFromIndex0Test()
        {
            var numeric = PolishNotation.ParseNumeric("123", 0);

            Assert.AreEqual(123, numeric.Numeric);
            Assert.AreEqual(3, numeric.NextIndex);
        }

        [Test]
        public void NumericParseWithTrailingSpaceTest()
        {
            var numeric = PolishNotation.ParseNumeric("123   ", 0);

            Assert.AreEqual(123, numeric.Numeric);
            Assert.AreEqual(6, numeric.NextIndex);
        }

        [Test]
        public void NumericParseBeginningPartialIndexTest()
        {
            var numeric = PolishNotation.ParseNumeric("  123  ", 2);

            Assert.AreEqual(123, numeric.Numeric);
            Assert.AreEqual(7, numeric.NextIndex);
        }

        [Test]
        public void MaxNumericParseTest()
        {
            var valueString = int.MaxValue.ToString();
            var numeric = PolishNotation.ParseNumeric(valueString, 0);

            Assert.AreEqual(int.MaxValue, numeric.Numeric);
            Assert.AreEqual(valueString.Length, numeric.NextIndex);
        }

        [Test]
        public void MinNumericParseTest()
        {
            var valueString = int.MinValue.ToString();
            var numeric = PolishNotation.ParseNumeric(valueString, 0);

            Assert.AreEqual(int.MinValue, numeric.Numeric);
            Assert.AreEqual(valueString.Length, numeric.NextIndex);
        }
        [Test]
        public void ZeroNumericParseTest()
        {
            var valueString = "0";
            var numeric = PolishNotation.ParseNumeric(valueString, 0);

            Assert.AreEqual(0, numeric.Numeric);
            Assert.AreEqual(valueString.Length, numeric.NextIndex);
        }
        #endregion

        #region ParseExpression
        [Test]
        public void ExpressionParseFromIndex0Test()
        {
            var expr = PolishNotation.ParseExpression("+ 123 456", 0);

            Assert.AreEqual('+', expr.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)expr.Left).Numeric);
            Assert.AreEqual(456, ((NumericNode)expr.Right).Numeric);
            Assert.AreEqual(9, expr.NextIndex);
        }

        [Test]
        public void ExpressionParseWithTrailingSpaceTest()
        {
            var expr = PolishNotation.ParseExpression("+ 123 456   ", 0);
            
            Assert.AreEqual('+', expr.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)expr.Left).Numeric);
            Assert.AreEqual(456, ((NumericNode)expr.Right).Numeric);
            Assert.AreEqual(12, expr.NextIndex);
        }

        [Test]
        public void ExpressionParseBeginningPartialIndexTest()
        {
            var expr = PolishNotation.ParseExpression("   + 123 456   ", 3);

            Assert.AreEqual('+', expr.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)expr.Left).Numeric);
            Assert.AreEqual(456, ((NumericNode)expr.Right).Numeric);
            Assert.AreEqual(15, expr.NextIndex);
        }

        [Test]
        public void ExpressionParseSparseTest()
        {
            var expr = PolishNotation.ParseExpression("+   123  456   ", 0);

            Assert.AreEqual('+', expr.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)expr.Left).Numeric);
            Assert.AreEqual(456, ((NumericNode)expr.Right).Numeric);
            Assert.AreEqual(15, expr.NextIndex);
        }

        [Test]
        public void ExpressionParseWithLeftNestedTest()
        {
            var expr = PolishNotation.ParseExpression("+ - 123 456 789   ", 0);

            Assert.AreEqual('+', expr.Operator.Operator);
            var left = (ExpressionNode) expr.Left;
            Assert.AreEqual('-', left.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)left.Left).Numeric);
            Assert.AreEqual(456, ((NumericNode)left.Right).Numeric);
            Assert.AreEqual(789, ((NumericNode)expr.Right).Numeric);
            Assert.AreEqual(18, expr.NextIndex);
        }

        [Test]
        public void ExpressionParseWithRightNestedTest()
        {
            var expr = PolishNotation.ParseExpression("+ 123 - 456 789   ", 0);

            Assert.AreEqual('+', expr.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)expr.Left).Numeric);
            var right = (ExpressionNode)expr.Right;
            Assert.AreEqual('-', right.Operator.Operator);
            Assert.AreEqual(456, ((NumericNode)right.Left).Numeric);
            Assert.AreEqual(789, ((NumericNode)right.Right).Numeric);
            Assert.AreEqual(18, expr.NextIndex);
        }

        [Test]
        public void ExpressionParseWithBothNestedTest()
        {
            var expr = PolishNotation.ParseExpression("+ - 123 456 * 789 111  ", 0);

            Assert.AreEqual('+', expr.Operator.Operator);
            var left = (ExpressionNode)expr.Left;
            Assert.AreEqual('-', left.Operator.Operator);
            Assert.AreEqual(123, ((NumericNode)left.Left).Numeric);
            Assert.AreEqual(456, ((NumericNode)left.Right).Numeric);
            var right = (ExpressionNode)expr.Right;
            Assert.AreEqual('*', right.Operator.Operator);
            Assert.AreEqual(789, ((NumericNode)right.Left).Numeric);
            Assert.AreEqual(111, ((NumericNode)right.Right).Numeric);
            Assert.AreEqual(23, expr.NextIndex);
        }
        #endregion

        #region Reduce
        [Test]
        public void ReducePattern1Test()
        {
            var expr = PolishNotation.ParseExpression("+ - 123 456 * 789 111  ", 0);

            var result = expr.Reduce();

            Assert.AreEqual(-333 + 87579, result);
        }

        [Test]
        public void ReducePattern2Test()
        {
            var expr = PolishNotation.ParseExpression("+ * 2 3 4", 0);

            var result = expr.Reduce();

            Assert.AreEqual(10, result);
        }

        [Test]
        public void ReducePattern3Test()
        {
            var expr = PolishNotation.ParseExpression("* + 2 3 4", 0);

            var result = expr.Reduce();

            Assert.AreEqual(20, result);
        }
        #endregion
    }
}
