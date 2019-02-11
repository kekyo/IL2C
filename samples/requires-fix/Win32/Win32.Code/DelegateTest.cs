using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Win32.Code
{
    public delegate int DelegateTestTargetDelegate(int a, int b);

    public class DelegateTypeTest
    {
        public static int AddTarget(int a, int b)
        {
            return a + b;
        }

        public static int Test1()
        {
            var hoge = new DelegateTestTargetDelegate(AddTarget);
            return hoge(1, 2);
        }
    }
}
