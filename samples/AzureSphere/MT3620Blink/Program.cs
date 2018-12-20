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
    public static class Program
    {
        public static int Main()
        {
            var fd = Interops.GPIO_OpenAsOutput(
                Interops.MT3620_RDB_LED1_RED,
                GPIO_OutputMode_Type.GPIO_OutputMode_PushPull,
                GPIO_Value_Type.GPIO_Value_High);

            var flag = false;
            var sleepTime = new timespec { tv_sec = 1 };
            var dummy = new timespec();
            
            while (true)
            {
                for (var index = 0; index < 10000; index++)
                {
                    Interops.GPIO_SetValue(fd, flag ? GPIO_Value_Type.GPIO_Value_High : GPIO_Value_Type.GPIO_Value_Low);
                    flag = !flag;

                    Console.WriteLine("Hello Azure Sphere with C#! " + index);

                    Interops.nanosleep(ref sleepTime, ref dummy);
                }
            }
        }
    }
}
