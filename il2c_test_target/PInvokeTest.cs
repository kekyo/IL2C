using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace il2c_test_target
{
    public class PInvokeTest
    {
        [DllImport("PInvoke.h")]
        public static extern long PInvokeTestFunc(int a, byte b);
    }
}
