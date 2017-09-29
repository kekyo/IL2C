using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace il2c_test_target
{
    public class Hoge2
    {
        public static byte Add3(byte a, bool isTwo)
        {
            return (byte)(a + (isTwo ? 2 : 1));
        }

        public static ushort Add4(ushort a, bool isTwo)
        {
            return (ushort)(a + (isTwo ? 2 : 1));
        }
    }
}
