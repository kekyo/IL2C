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
        private static void sleep()
        {
            var sleepTime = new timespec { tv_sec = 1 };
            var dummy = new timespec();

            Interops.nanosleep(ref sleepTime, ref dummy);
        }

        public static int Main()
        {
            var ledFd = Interops.GPIO_OpenAsOutput(
                Interops.MT3620_RDB_LED1_RED,
                GPIO_OutputMode_Type.GPIO_OutputMode_PushPull,
                GPIO_Value_Type.GPIO_Value_High);

            var epollFd = Interops.epoll_create1(0);

            var flag = false;
            
            while (true)
            {
                for (var index = 0; index < 10000; index++)
                {
                    Interops.GPIO_SetValue(ledFd, flag ? GPIO_Value_Type.GPIO_Value_High : GPIO_Value_Type.GPIO_Value_Low);
                    flag = !flag;

                    sleep();
                }
            }
        }
    }
}
