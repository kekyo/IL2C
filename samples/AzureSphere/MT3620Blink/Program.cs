using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MT3620Blink
{
    public static class Program
    {
        private static void sleep(int nsec)
        {
            var sleepTime = new timespec { tv_nsec = nsec };
            Interops.nanosleep(ref sleepTime, out var dummy);
        }

        public static int Main()
        {
            using (var epoll = new Application())
            {
                using (var led = new GpioOutput(
                    Interops.MT3620_RDB_LED1_RED,
                    GPIO_OutputMode_Type.GPIO_OutputMode_PushPull,
                    true))
                {
                    using (var button = new GpioInput(
                        Interops.MT3620_RDB_BUTTON_A))
                    {
                        using (var timer = new Timer(125_000_000L))
                        {
                            var flag = false;

                            epoll.RegisterDescriptor(
                                timer,
                                () =>
                                {
                                    led.SetValue(flag);
                                    flag = !flag;
                                });

                            var blinkIntervals = new[] { 125_000_000L, 250_000_000L, 500_000_000L };
                            var blinkIntervalIndex = 0;

                            epoll.RegisterDescriptor(
                                button,
                                () =>
                                {
                                    blinkIntervalIndex = (blinkIntervalIndex + 1) % blinkIntervals.Length;
                                    timer.SetInterval(blinkIntervals[blinkIntervalIndex]);
                                });

                            epoll.Run();
                        }
                    }
                }
            }

            return 0;
        }
    }
}
