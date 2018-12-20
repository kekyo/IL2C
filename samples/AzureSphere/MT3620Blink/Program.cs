using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MT3620Blink
{
    public static class Program
    {
        private static void sleep(int msec)
        {
            var sec = msec / 1000;
            var nsec = (msec % 1000) * 1_000_000;
            var sleepTime = new timespec { tv_sec = sec, tv_nsec = nsec };
            var dummy = new timespec();

            Interops.nanosleep(ref sleepTime, ref dummy);
        }

        public static int Main()
        {
            var ledFd = Interops.GPIO_OpenAsOutput(
                Interops.MT3620_RDB_LED1_RED,
                GPIO_OutputMode_Type.GPIO_OutputMode_PushPull,
                GPIO_Value_Type.GPIO_Value_High);

            var buttonFd = Interops.GPIO_OpenAsInput(
                Interops.MT3620_RDB_BUTTON_A);

            var flag = false;
            var blinkIntervals = new[] { 125, 250, 500 };
            var blinkIntervalIndex = 0;

            while (true)
            {
                Interops.GPIO_SetValue(ledFd, flag ? GPIO_Value_Type.GPIO_Value_High : GPIO_Value_Type.GPIO_Value_Low);
                flag = !flag;

                Interops.GPIO_GetValue(buttonFd, out var buttonValue);
                if (buttonValue == GPIO_Value_Type.GPIO_Value_Low)
                {
                    blinkIntervalIndex = (blinkIntervalIndex + 1) % blinkIntervals.Length;
                }

                sleep(blinkIntervals[blinkIntervalIndex]);
            }
        }
    }
}
