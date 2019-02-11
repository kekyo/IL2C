using System;
using System.Runtime.InteropServices;

namespace WDM.Code
{
    public class Wdm
    {
#if true
        public static void DbgPrint(string message)
        {
        }

        public static void DbgPrint(uint componentId, uint level, string message)
        {
        }
#else
        [DllImport("wdm.h", EntryPoint = "DbgPrint")]
        public static extern void DbgPrint([MarshalAs(UnmanagedType.LPStr)] string message);
        [DllImport("wdm.h", EntryPoint = "DbgPrintEx")]
        public static extern void DbgPrint(uint componentId, uint level, [MarshalAs(UnmanagedType.LPStr)] string message);
#endif

        [DllImport("memmem.h", EntryPoint = "__memmem")]
        public static extern IntPtr memmem(IntPtr p1, int s1, IntPtr p2, int s2);

        [DllImport("memmem.h", EntryPoint = "__memcpy")]
        public static extern void memcpy(IntPtr pDest, IntPtr pSource, int size);
    }
}
