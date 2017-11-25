using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace il2c_test_target
{
#if _WIN32
    public class Win32
    {
        [DllImport("windows.h")]
        public static extern int GetCurrentProcessId();

        [DllImport("windows.h")]
        public static extern int GetCurrentThreadId();
    }
#else
    public class Arduino
    {
        //[DllImport("Arduino.h", EntryPoint = "pinMode")]
        //public static extern int PinMode(byte pin, byte mode);

        [DllImport("Arduino.h", EntryPoint = "digitalRead")]
        public static extern int DigitalRead(byte pin);

        [DllImport("Arduino.h", EntryPoint = "digitalWrite")]
        public static extern void DigitalWrite(byte pin, byte val);

        [DllImport("Arduino.h", EntryPoint = "delay")]
        public static extern void Delay(int milliseconds);
    }

    public class Wio
    {
        [DllImport("WioLTE.h", EntryPoint = "Wio.Init")]
        public static extern void Init();

        [DllImport("WioLTE.h", EntryPoint = "Wio.LedSetRGB")]
        public static extern void LedSetRGB(int r, int g, int b);
    }

#if false
    public class WioTest
    {
        private static readonly int INTERVAL = 50;
        private static int Hue = 0;

        public static void loop()
        {
            int r;
            int g;
            int b;

            if (Hue < 60)
            {
                r = 255;
                g = Hue * 255 / 60;
                b = 0;
            }
            else if (Hue < 120)
            {
                r = (120 - Hue) * 255 / 60;
                g = 255;
                b = 0;
            }
            else if (Hue < 180)
            {
                r = 0;
                g = 255;
                b = (Hue - 120) * 255 / 60;
            }
            else if (Hue < 240)
            {
                r = 0;
                g = (240 - Hue) * 255 / 60;
                b = 255;
            }
            else if (Hue < 300)
            {
                r = (Hue - 240) * 255 / 60;
                g = 0;
                b = 255;
            }
            else
            {
                r = 255;
                g = 0;
                b = (360 - Hue) * 255 / 60;
            }

            Wio.LedSetRGB(r, g, b);

            Hue += 10;
            if (Hue >= 360) Hue = 0;

            Wio.delay(INTERVAL);
        }
    }
#endif
#endif
}
