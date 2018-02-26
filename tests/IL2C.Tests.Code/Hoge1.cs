using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IL2C.Tests
{
    public class Hoge1
    {
        public static int Add1(int a, bool isTwo)
        {
            return a + (isTwo ? 2 : 1);
        }

        public static long Add2(long a, bool isTwo)
        {
            return a + (isTwo ? 2 : 1);
        }
    }
}
