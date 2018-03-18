using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IL2C.Tests
{
    public struct ValueTypeTestTarget
    {
        public static int Value1 = 123;
        public int Value2;
        public ClassTypeTestTarget OR2;

        public int GetValue2(int a, int b)
        {
            return this.Value2 + a + b;
        }
    }

    public class ValueTypeTest
    {
        public static int Test4()
        {
            var hoge3 = new ValueTypeTestTarget();
            hoge3.Value2 = 456;

            return hoge3.Value2;
        }

        public static int Test5()
        {
            var hoge3 = new ValueTypeTestTarget();
            hoge3.Value2 = 789;

            var result = hoge3.GetValue2(123, 456);
            return result;
        }
    }
}
