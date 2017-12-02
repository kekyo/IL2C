using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace il2c_test_target
{
    public class BoxingTest
    {
        private static int x;

        public static void BoxingInt32(int a)
        {
            object value = a;

            int r = (int) value;
        }
    }
}
