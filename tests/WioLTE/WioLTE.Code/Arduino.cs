using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace WioLTE.Code
{
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

        [DllImport("Arduino.h", EntryPoint = "SerialUSB.println")]
        public static extern void PrintLn(string message);
    }
}
