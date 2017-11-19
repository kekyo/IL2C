using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace il2c_test_target
{
    public class PInvokeTest
    {
        [DllImport("windows.h")]
        public static extern uint GetCurrentProcessId();

        [DllImport("windows.h")]
        public static extern uint GetCurrentThreadId();
    }
}
