using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace il2c_test_target
{
    public class ClassTypeTestTarget
    {
        public static int Value1 = 123;
        public static ClassTypeTestTarget OR1;

        public int Value2;
        public ClassTypeTestTarget OR2;

        public int GetValue2(int a, int b)
        {
            return this.Value2 + a + b;
        }
    }

    public class ClassTypeTest
    {
        public static int Test4()
        {
            var hoge3 = new ClassTypeTestTarget();
            hoge3.Value2 = 456;

            return hoge3.Value2;
        }

        public static int Test5()
        {
            var hoge3 = new ClassTypeTestTarget();
            hoge3.Value2 = 789;

            var result = hoge3.GetValue2(123, 456);
            return result;
        }
    }
}
