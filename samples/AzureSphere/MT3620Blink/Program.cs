using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

using IL2C;

namespace MT3620Blink
{
    [NativeType("time.h", SymbolName = "struct timespec")]
    internal struct timespec
    {
        public int tv_sec;
        public int tv_nsec;
    }

    public static class Program
    {
        [NativeMethod("time.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern void nanosleep(ref timespec time, ref timespec dummy);

        public static int Main()
        {
            var sleepTime = new timespec { tv_sec = 1 };
            var dummy = new timespec();

            while (true)
            {
                for (var index = 0; index < 10000; index++)
                {
                    Console.WriteLine("Hello Azure Sphere with C#! " + index);
                    nanosleep(ref sleepTime, ref dummy);
                }
            }
        }
    }
}
