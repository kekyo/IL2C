using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Win32.Code
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
