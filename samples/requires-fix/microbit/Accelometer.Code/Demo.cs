using System;
using System.Runtime.InteropServices;

namespace Accelometer
{
    public static class Demo
    {
        #region Interop
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

        [DllImport("Accelometer.h", EntryPoint = "SCREEN.begin")]
        private static extern void BeginScreen();

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
        private static extern void ShowArrow(ArrowNames direction, uint interval = 750);

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
        private static extern void ShowIcon(IconNames icon, uint interval = 750);

        [DllImport("Accelometer.h", EntryPoint = "delay")]
        private static extern void Delay(int millis);
        #endregion

        public static void Main()
        {
            BeginScreen();
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

                uint interval = 30;

                if (fn && fe) ShowArrow(ArrowNames.NorthEast, interval);
                else if (fn && fw) ShowArrow(ArrowNames.NorthWest, interval);
                else if (fn) ShowArrow(ArrowNames.North, interval);
                else if (fs && fe) ShowArrow(ArrowNames.SouthEast, interval);
                else if (fs && fw) ShowArrow(ArrowNames.SouthWest, interval);
                else if (fs) ShowArrow(ArrowNames.South, interval);
                else if (fe) ShowArrow(ArrowNames.East, interval);
                else if (fw) ShowArrow(ArrowNames.West, interval);
                else ShowIcon(IconNames.Heart, 500);

                Delay(5);
            }
        }
    }
}
