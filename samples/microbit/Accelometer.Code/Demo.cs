using System;
using System.Runtime.InteropServices;

namespace Accelometer
{
    public class Demo
    {
        [DllImport("Accelometer.h", EntryPoint="accelometer.begin")]
        private static extern void BeginAccelometer(bool highResolution = true, byte scale = 2);

        [DllImport("Accelometer.h", EntryPoint="accelometer.update")]
        private static extern byte UpdateAccelometer();

        [DllImport("Accelometer.h", EntryPoint = "accelometer.getX")]
        private static extern sbyte GetAccelometerX();

        [DllImport("Accelometer.h", EntryPoint = "accelometer.getY")]
        private static extern sbyte GetAccelometerY();

        [DllImport("Accelometer.h", EntryPoint = "accelometer.getZ")]
        private static extern sbyte GetAccelometerZ();

        private enum ArrowNames
        {
            North = 0,
            NorthEast = 1,
            East = 2,
            SouthEast = 3,
            South = 4,
            SouthWest = 5,
            West = 6,
            NorthWest = 7
        }

        [DllImport("Accelometer.h", EntryPoint = "SCREEN.showArrow")]
        private static extern sbyte ShowArrow(ArrowNames direction, uint interval = 750);

        private enum IconNames
        {
            Heart = 0,
            SmallHeart = 1,
            Yes = 2,
            No = 3,
            Happy = 4,
            Sad = 5,
            Confused = 6,
            Angry = 7,
            Asleep = 8,
            Surprised = 9,
            Silly = 10,
            Fabulous = 11,
            Meh = 12,
            TShirt = 13,
            Rollerskate = 14,
            Duck = 15,
            House = 16,
            Tortoise = 17,
            Butterfly = 18,
            StickFigure = 19,
            Ghost = 20,
            Sword = 21,
            Giraffe = 22,
            Skull = 23,
            Umbrella = 24,
            Snake = 25,
            Rabbit = 26,
            Cow = 27,
            QuarterNote = 28,
            EigthNote = 29,
            Pitchfork = 30,
            Target = 31,
            Triangle = 32,
            LeftTriangle = 33,
            Chessboard = 34,
            Diamond = 35,
            SmallDiamond = 36,
            Square = 37,
            SmallSquare = 38,
            Scissors = 39
        }

        [DllImport("Accelometer.h", EntryPoint = "SCREEN.showIcon")]
        private static extern sbyte ShowIcon(IconNames icon, uint interval = 750);

        [DllImport("Accelometer.h", EntryPoint = "delay")]
        private static extern void Delay(int millis);

        public static void Main()
        {
            BeginAccelometer(false, 2);

            while (true)
            {
                UpdateAccelometer();

                var x = GetAccelometerX();
                var y = GetAccelometerY();

                var fn = y > 20;
                var fs = y < -20;
                var fw = x > 20;
                var fe = x < -20;

                if (fn && fe) ShowArrow(ArrowNames.NorthEast);
                else if (fn && fw) ShowArrow(ArrowNames.NorthWest);
                else if (fn) ShowArrow(ArrowNames.North);
                else if (fs && fe) ShowArrow(ArrowNames.SouthEast);
                else if (fs && fw) ShowArrow(ArrowNames.SouthWest);
                else if (fs) ShowArrow(ArrowNames.South);
                else if (fe) ShowArrow(ArrowNames.East);
                else if (fw) ShowArrow(ArrowNames.West);
                else ShowIcon(IconNames.Heart);

                Delay(100);
            }
        }
    }
}
