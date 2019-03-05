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
            private readonly GpioInput changeInput;
            private readonly GpioInput exitInput;
            private bool lastChangeInput;
            private bool lastExitInput;
            private readonly GpioBlinker blinker;
            private readonly Application app;

            public GpioPoller(
                int changeInputGpioId, int exitInputGpioId,
                GpioBlinker blinker, Application app)
            {
                changeInput = new GpioInput(changeInputGpioId);
                lastChangeInput = changeInput.Value;

                exitInput = new GpioInput(exitInputGpioId);
                lastExitInput = exitInput.Value;

                this.blinker = blinker;
                this.app = app;
                this.SetInterval(100_000_000L);
            }

            public override void Dispose()
            {
                base.Dispose();
                changeInput.Dispose();
                exitInput.Dispose();
            }

            protected override void Raised()
            {
                var current = changeInput.Value;
                if (current != lastChangeInput)
                {
                    if (!current)
                    {
                        blinker.NextInterval();
                    }
                }
                lastChangeInput = current;

                current = exitInput.Value;
                if (current != lastExitInput)
                {
                    if (!current)
                    {
                        app.Abort();
                    }
                }
                lastExitInput = current;
            }
        }

        public static int Main()
        {
            using (var app = new Application())
            {
                using (var ledBlinker = new GpioBlinker(Interops.MT3620_RDB_LED1_RED))
                {
                    using (var buttonPoller = new GpioPoller(
                        Interops.MT3620_RDB_BUTTON_A,
                        Interops.MT3620_RDB_BUTTON_B,
                        ledBlinker,
                        app))
                    {
                        app.RegisterDescriptor(ledBlinker);
                        app.RegisterDescriptor(buttonPoller);

                        app.Run();
                    }
                }
            }

            return 0;
        }
    }
}
