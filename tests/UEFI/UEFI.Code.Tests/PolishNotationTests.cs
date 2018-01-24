using System;
using NUnit.Framework;

namespace UEFI.Code
{
    [TestFixture]
    public class PolishNotationTests
    {
        [Test]
        public void OperatorAddParseFromIndex0Test()
        {
            var expr = PolishNotation.ParseOperator("+", 0);

            Assert.AreEqual('+', expr.Operator);
            Assert.AreEqual(1, expr.NextIndex);
        }

        [Test]
        public void OperatorAddParseWithTrailingSpaceTest()
        {
            var expr = PolishNotation.ParseOperator("+   ", 0);

            Assert.AreEqual('+', expr.Operator);
            Assert.AreEqual(4, expr.NextIndex);
        }

        [Test]
        public void OperatorAddParseBeginningPartialIndexTest()
        {
            var expr = PolishNotation.ParseOperator("  +  ", 2);

            Assert.AreEqual('+', expr.Operator);
            Assert.AreEqual(5, expr.NextIndex);
        }
    }
}
