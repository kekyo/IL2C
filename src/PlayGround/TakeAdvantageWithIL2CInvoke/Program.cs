using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

// It is intruduced what/how to do 'IL2C/Invoke'.
namespace TakeAdvantageWithIL2CInvoke
{
    // Refer tm struct type from pure C header file.
    // IL2C/Invoke doesn't need to adjust any field offset/packing.
    // Managed side declarations are pure stub.
    [NativeType("time.h", SymbolName = "struct tm")]
    internal struct tm
    {
        public int tm_sec;
        public int tm_min;
        public int tm_hour;
        public int tm_mday;
        public int tm_mon;
        public int tm_year;
        public int tm_wday;
        public int tm_yday;
        public int tm_isdst;
    }

    public static class Program
    {
        // Refer mktime() API from pure C header file.
        // extern "C" time_t mktime(struct tm*);
        [NativeMethod("time.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern long mktime(in tm tmValue);

        public static void Main()
        {
            // 2022/10/23 12:34:56
            var tmValue = new tm
            {
                tm_year = 2022 - 1900,
                tm_mon = 10 - 1,
                tm_mday = 23,
                tm_hour = 12,
                tm_min = 34,
                tm_sec = 56,
                tm_wday = 0,
                tm_yday = 0,
                tm_isdst = 0,
            };

            var result = mktime(tmValue);

            // 1666496096
            Console.WriteLine(result);
        }
    }
}
