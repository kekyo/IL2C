using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace TakeAdvantageWithIL2CInvoke
{
    // Refer timespec struct type from pure C header file.
    [NativeType("time.h", SymbolName = "struct timespec")]
    internal struct timespec
    {
        public int tv_sec;
        public int tv_nsec;
    }

    public static class Program
    {
        // It is intruduced what/how to do 'IL2C/Invoke'.
        // Explained blog entry: https://www.kekyo.net/2019/01/04/6917

        // Refer nanosleep() API from pure C header file.
        [NativeMethod("time.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern void nanosleep(
            ref timespec time, ref timespec remains);

        public static void Main()
        {
            var sleepTime = new timespec { tv_sec = 1 };
            var dummy = new timespec();

            while (true)
            {
                Console.WriteLine("Hmm...");
                nanosleep(ref sleepTime, ref dummy);
            }
        }
    }
}
