using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace WioLTE.Code
{
    public class Wio
    {
        [DllImport("WioLTE.h", EntryPoint = "Wio.Init")]
        public static extern void Init();

        [DllImport("WioLTE.h", EntryPoint = "Wio.LedSetRGB")]
        public static extern void LedSetRGB(int r, int g, int b);
    }
}
