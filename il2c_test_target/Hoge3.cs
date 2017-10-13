using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace il2c_test_target
{
    public struct Hoge3
    {
        public static int Value1 = 123;
        public int Value2;
    }

    public class Hoge4
    {
        public static void Test4()
        {
            var hoge3 = new Hoge3();
            hoge3.Value2 = 456;
        }
    }
}
