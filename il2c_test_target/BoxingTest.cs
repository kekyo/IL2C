using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace il2c_test_target
{
    public class BoxingTest
    {
        public static void BoxingInt32(int a)
        {
            object value = a;
        }
    }
}
