using System;

namespace MT3620Blink
{
    public static class Program
    {
        private sealed class GpioBlinker : Timer
        {
            private readonly long[] blinkIntervals = new[] { 125_000_000L, 250_000_000L, 500_000_000L };
            private readonly GpioOutput output;
            private bool flag;
            private int blinkIntervalIndex;

            public GpioBlinker(int gpioId)
            {
                output = new GpioOutput(
                    gpioId,
                    GPIO_OutputMode_Type.GPIO_OutputMode_PushPull,
                    true);
                this.NextInterval();
            }

            public override void Dispose()
            {
                base.Dispose();
                output.Dispose();
            }

            protected override void Raised()
            {
                output.SetValue(flag);
                flag = !flag;
            }

            public void NextInterval()
            {
                this.SetInterval(blinkIntervals[blinkIntervalIndex]);

                blinkIntervalIndex++;
                blinkIntervalIndex %= 3;
            }
        }

        private sealed class GpioPoller : Timer
        {
            private readonly GpioInput input;
            private readonly GpioBlinker blinker;
            private bool last;

            public GpioPoller(int gpioId, GpioBlinker blinker)
            {
                input = new GpioInput(gpioId);
                last = input.Value;
                this.blinker = blinker;
                this.SetInterval(100_000_000L);
            }

            public override void Dispose()
            {
                base.Dispose();
                input.Dispose();
            }

            protected override void Raised()
            {
                var current = input.Value;
                if (current != last)
                {
                    if (!current)
                    {
                        blinker.NextInterval();
                    }
                }
                last = current;
            }
        }

        public static int Main()
        {
            using (var epoll = new Application())
            {
                using (var ledBlinker = new GpioBlinker(Interops.MT3620_RDB_LED1_RED))
                {
                    using (var buttonPoller = new GpioPoller(Interops.MT3620_RDB_BUTTON_A, ledBlinker))
                    {
                        epoll.RegisterDescriptor(ledBlinker);
                        epoll.RegisterDescriptor(buttonPoller);

                        epoll.Run();
                    }
                }
            }

            return 0;
        }
    }
}
