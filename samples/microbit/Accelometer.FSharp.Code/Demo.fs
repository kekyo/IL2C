namespace Accelometer

open System.Runtime.InteropServices

module Demo =
    [<DllImport("Accelometer.h", EntryPoint="accelometer.begin")>]
    extern void private BeginAccelometer(bool highResolution, byte scale)

    [<DllImport("Accelometer.h", EntryPoint="accelometer.update")>]
    extern byte UpdateAccelometer()

    [<DllImport("Accelometer.h", EntryPoint = "accelometer.getX")>]
    extern sbyte GetAccelometerX()

    [<DllImport("Accelometer.h", EntryPoint = "accelometer.getY")>]
    extern sbyte GetAccelometerY()

    [<DllImport("Accelometer.h", EntryPoint = "accelometer.getZ")>]
    extern sbyte GetAccelometerZ()

    [<DllImport("Accelometer.h", EntryPoint = "SCREEN.begin")>]
    extern void BeginScreen()

    type ArrowNames = North = 0 | NorthEast = 1 | East = 2 | SouthEast = 3 | South = 4 | SouthWest = 5 | West = 6 | NorthWest = 7

    [<DllImport("Accelometer.h", EntryPoint = "SCREEN.showArrow")>]
    extern void ShowArrow(ArrowNames direction, uint32 interval)

    type IconNames = Heart = 0

    [<DllImport("Accelometer.h", EntryPoint = "SCREEN.showIcon")>]
    extern void ShowIcon(IconNames icon, uint32 interval)

    [<DllImport("Accelometer.h", EntryPoint = "delay")>]
    extern void Delay(int millis)

    let Main() =
        BeginScreen()
        BeginAccelometer(false, 2uy)

        while true do
            UpdateAccelometer() |> ignore

            let x = GetAccelometerX()
            let y = GetAccelometerY()

            let fn = y > 20y
            let fs = y < -20y
            let fw = x > 20y
            let fe = x < -20y

            let interval = 30u

            match fn, fe, fw, fs with
                | true, true, _, _ -> ShowArrow(ArrowNames.NorthEast, interval)
                | true, _, true, _ -> ShowArrow(ArrowNames.NorthWest, interval)
                | true, _, _, _ -> ShowArrow(ArrowNames.North, interval)
                | _, true, _, true -> ShowArrow(ArrowNames.SouthEast, interval)
                | _, _, true, true -> ShowArrow(ArrowNames.SouthWest, interval)
                | _, _, _, true -> ShowArrow(ArrowNames.South, interval)
                | _, true, _, _ -> ShowArrow(ArrowNames.East, interval)
                | _, _, true, _ -> ShowArrow(ArrowNames.West, interval)
                | _ -> ShowIcon(IconNames.Heart, 500u)

            Delay(5) |> ignore
