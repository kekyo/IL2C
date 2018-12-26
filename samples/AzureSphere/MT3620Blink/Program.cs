namespace MT3620Blink
{
    public static class Program
    {
        private sealed class LedTimer : Timer
        {
            private readonly GpioOutput led;
            private bool flag;

            public LedTimer(GpioOutput led, long nsec)
                : base(nsec)
            {
                this.led = led;
            }

            protected override void Raised()
            {
                led.SetValue(flag);
                flag = !flag;
            }
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
                        using (var ledTimer = new LedTimer(led, 125_000_000L))
                        {
                            epoll.RegisterDescriptor(ledTimer);

                            //var blinkIntervals = new[] { 125_000_000L, 250_000_000L, 500_000_000L };
                            //var blinkIntervalIndex = 0;

                            //epoll.RegisterDescriptor(
                            //    button,
                            //    () =>
                            //    {
                            //        blinkIntervalIndex = (blinkIntervalIndex + 1) % blinkIntervals.Length;
                            //        timer.SetInterval(blinkIntervals[blinkIntervalIndex]);
                            //    });

                            epoll.Run();
                        }
                    }
                }
            }

            return 0;
        }
    }
}
