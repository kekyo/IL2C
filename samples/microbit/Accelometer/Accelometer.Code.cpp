#include "Accelometer.h"
#include "Accelometer.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:


#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:


////////////////////////////////////////////////////////////
// Enum: Accelometer.Demo.ArrowNames

// Enum layout
typedef enum Accelometer_Demo_ArrowNames
{
    Accelometer_Demo_ArrowNames_North = 0,
    Accelometer_Demo_ArrowNames_NorthEast = 1,
    Accelometer_Demo_ArrowNames_East = 2,
    Accelometer_Demo_ArrowNames_SouthEast = 3,
    Accelometer_Demo_ArrowNames_South = 4,
    Accelometer_Demo_ArrowNames_SouthWest = 5,
    Accelometer_Demo_ArrowNames_West = 6,
    Accelometer_Demo_ArrowNames_NorthWest = 7,
} Accelometer_Demo_ArrowNames;


// Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_ArrowNames_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Enum: Accelometer.Demo.IconNames

// Enum layout
typedef enum Accelometer_Demo_IconNames
{
    Accelometer_Demo_IconNames_Heart = 0,
    Accelometer_Demo_IconNames_SmallHeart = 1,
    Accelometer_Demo_IconNames_Yes = 2,
    Accelometer_Demo_IconNames_No = 3,
    Accelometer_Demo_IconNames_Happy = 4,
    Accelometer_Demo_IconNames_Sad = 5,
    Accelometer_Demo_IconNames_Confused = 6,
    Accelometer_Demo_IconNames_Angry = 7,
    Accelometer_Demo_IconNames_Asleep = 8,
    Accelometer_Demo_IconNames_Surprised = 9,
    Accelometer_Demo_IconNames_Silly = 10,
    Accelometer_Demo_IconNames_Fabulous = 11,
    Accelometer_Demo_IconNames_Meh = 12,
    Accelometer_Demo_IconNames_TShirt = 13,
    Accelometer_Demo_IconNames_Rollerskate = 14,
    Accelometer_Demo_IconNames_Duck = 15,
    Accelometer_Demo_IconNames_House = 16,
    Accelometer_Demo_IconNames_Tortoise = 17,
    Accelometer_Demo_IconNames_Butterfly = 18,
    Accelometer_Demo_IconNames_StickFigure = 19,
    Accelometer_Demo_IconNames_Ghost = 20,
    Accelometer_Demo_IconNames_Sword = 21,
    Accelometer_Demo_IconNames_Giraffe = 22,
    Accelometer_Demo_IconNames_Skull = 23,
    Accelometer_Demo_IconNames_Umbrella = 24,
    Accelometer_Demo_IconNames_Snake = 25,
    Accelometer_Demo_IconNames_Rabbit = 26,
    Accelometer_Demo_IconNames_Cow = 27,
    Accelometer_Demo_IconNames_QuarterNote = 28,
    Accelometer_Demo_IconNames_EigthNote = 29,
    Accelometer_Demo_IconNames_Pitchfork = 30,
    Accelometer_Demo_IconNames_Target = 31,
    Accelometer_Demo_IconNames_Triangle = 32,
    Accelometer_Demo_IconNames_LeftTriangle = 33,
    Accelometer_Demo_IconNames_Chessboard = 34,
    Accelometer_Demo_IconNames_Diamond = 35,
    Accelometer_Demo_IconNames_SmallDiamond = 36,
    Accelometer_Demo_IconNames_Square = 37,
    Accelometer_Demo_IconNames_SmallSquare = 38,
    Accelometer_Demo_IconNames_Scissors = 39,
} Accelometer_Demo_IconNames;


// Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_IconNames_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:

//////////////////////////////////////////////////////////////////////////////////
// Methods:

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// Static fields:


//////////////////////////////////////////////////////////////////////////////////
// Methods:

////////////////////////////////////////////////////////////
// Type: Accelometer.Demo

///////////////////////////////////////
// P/Invoke: BeginAccelometer

void Accelometer_Demo_BeginAccelometer(bool highResolution, uint8_t scale)
{
    accelometer.begin(highResolution, scale);
}

///////////////////////////////////////
// P/Invoke: UpdateAccelometer

uint8_t Accelometer_Demo_UpdateAccelometer(void)
{
    return accelometer.update();
}

///////////////////////////////////////
// P/Invoke: GetAccelometerX

int8_t Accelometer_Demo_GetAccelometerX(void)
{
    return accelometer.getX();
}

///////////////////////////////////////
// P/Invoke: GetAccelometerY

int8_t Accelometer_Demo_GetAccelometerY(void)
{
    return accelometer.getY();
}

///////////////////////////////////////
// P/Invoke: GetAccelometerZ

int8_t Accelometer_Demo_GetAccelometerZ(void)
{
    return accelometer.getZ();
}

///////////////////////////////////////
// P/Invoke: BeginScreen

void Accelometer_Demo_BeginScreen(void)
{
    SCREEN.begin();
}

///////////////////////////////////////
// P/Invoke: ShowArrow

void Accelometer_Demo_ShowArrow(Accelometer_Demo_ArrowNames direction, uint32_t interval)
{
    SCREEN.showArrow((ArrowNames)direction, interval);
}

///////////////////////////////////////
// P/Invoke: ShowIcon

void Accelometer_Demo_ShowIcon(Accelometer_Demo_IconNames icon, uint32_t interval)
{
    SCREEN.showIcon((IconNames)icon, interval);
}

///////////////////////////////////////
// P/Invoke: Delay

void Accelometer_Demo_Delay(int32_t millis)
{
    delay(millis);
}

///////////////////////////////////////
// Main

void Accelometer_Demo_Main(void)
{
    //-------------------
    // Local variables:

    int8_t x;
    int8_t y;
    bool fn;
    bool fs;
    bool fw;
    bool fe;
    uint32_t interval;
    bool local0;
    bool local1;
    bool local2;
    bool local3;
    bool local4;
    bool local5;
    bool local6;
    bool local7;
    bool local8;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(94): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: call System.Void Accelometer.Demo::BeginScreen() */
    Accelometer_Demo_BeginScreen();
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(96): */
    /* Path=1, Unique=0: IL_0007: ldc.i4.0 */
    stack0_0__ = 0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.2 */
    stack1_0__ = 2;
    /* Path=1, Unique=0: IL_0009: call System.Void Accelometer.Demo::BeginAccelometer(System.Boolean,System.Byte) */
    Accelometer_Demo_BeginAccelometer(stack0_0__ ? true : false, (uint8_t)stack1_0__);
    /* Path=1, Unique=0: IL_000e: nop */
    /* Path=1, Unique=0: IL_000f: br IL_00fd */
    goto IL_00fd;
IL_0014:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(99): */
    /* Path=3, Unique=0: IL_0014: nop */
    /* Path=3, Unique=0: IL_0015: call System.Byte Accelometer.Demo::UpdateAccelometer() */
    stack0_0__ = Accelometer_Demo_UpdateAccelometer();
    /* Path=3, Unique=0: IL_001a: pop */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(102): */
    /* Path=3, Unique=0: IL_001b: call System.SByte Accelometer.Demo::GetAccelometerX() */
    stack0_0__ = Accelometer_Demo_GetAccelometerX();
    /* Path=3, Unique=0: IL_0020: stloc.0 */
    x = (int8_t)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(103): */
    /* Path=3, Unique=0: IL_0021: call System.SByte Accelometer.Demo::GetAccelometerY() */
    stack0_0__ = Accelometer_Demo_GetAccelometerY();
    /* Path=3, Unique=0: IL_0026: stloc.1 */
    y = (int8_t)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(105): */
    /* Path=3, Unique=0: IL_0027: ldloc.1 */
    stack0_0__ = y;
    /* Path=3, Unique=0: IL_0028: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* Path=3, Unique=0: IL_002a: cgt */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_002c: stloc.2 */
    fn = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(106): */
    /* Path=3, Unique=0: IL_002d: ldloc.1 */
    stack0_0__ = y;
    /* Path=3, Unique=0: IL_002e: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* Path=3, Unique=0: IL_0030: clt */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0032: stloc.3 */
    fs = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(107): */
    /* Path=3, Unique=0: IL_0033: ldloc.0 */
    stack0_0__ = x;
    /* Path=3, Unique=0: IL_0034: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* Path=3, Unique=0: IL_0036: cgt */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0038: stloc.s local4 */
    fw = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(108): */
    /* Path=3, Unique=0: IL_003a: ldloc.0 */
    stack0_0__ = x;
    /* Path=3, Unique=0: IL_003b: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* Path=3, Unique=0: IL_003d: clt */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_003f: stloc.s local5 */
    fe = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(110): */
    /* Path=3, Unique=0: IL_0041: ldc.i4.s 30 */
    stack0_0__ = 30;
    /* Path=3, Unique=0: IL_0043: stloc.s local6 */
    interval = (uint32_t)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* Path=3, Unique=0: IL_0045: ldloc.2 */
    stack0_0__ = fn;
    /* Path=3, Unique=0: IL_0046: ldloc.s local5 */
    stack1_0__ = fe;
    /* Path=3, Unique=0: IL_0048: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=3, Unique=0: IL_0049: stloc.s local7 */
    local0 = stack0_0__ ? true : false;
    /* Path=3, Unique=0: IL_004b: ldloc.s local7 */
    stack0_0__ = local0;
    /* Path=3, Unique=0: IL_004d: brfalse.s IL_005d */
    if (stack0_0__ == 0) goto IL_005d;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* Path=3, Unique=0: IL_004f: ldc.i4.1 */
    stack0_0__ = 1;
    /* Path=3, Unique=0: IL_0050: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=3, Unique=0: IL_0052: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=3, Unique=0: IL_0057: nop */
    /* Path=3, Unique=0: IL_0058: br IL_00f5 */
    goto IL_00f5;
IL_005d:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(113): */
    /* Path=4, Unique=0: IL_005d: ldloc.2 */
    stack0_0__ = fn;
    /* Path=4, Unique=0: IL_005e: ldloc.s local4 */
    stack1_0__ = fw;
    /* Path=4, Unique=0: IL_0060: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=4, Unique=0: IL_0061: stloc.s local8 */
    local1 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_0063: ldloc.s local8 */
    stack0_0__ = local1;
    /* Path=4, Unique=0: IL_0065: brfalse.s IL_0075 */
    if (stack0_0__ == 0) goto IL_0075;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(113): */
    /* Path=4, Unique=0: IL_0067: ldc.i4.7 */
    stack0_0__ = 7;
    /* Path=4, Unique=0: IL_0068: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=4, Unique=0: IL_006a: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=4, Unique=0: IL_006f: nop */
    /* Path=4, Unique=0: IL_0070: br IL_00f5 */
    goto IL_00f5;
IL_0075:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* Path=6, Unique=0: IL_0075: ldloc.2 */
    stack0_0__ = fn;
    /* Path=6, Unique=0: IL_0076: stloc.s local9 */
    local2 = stack0_0__ ? true : false;
    /* Path=6, Unique=0: IL_0078: ldloc.s local9 */
    stack0_0__ = local2;
    /* Path=6, Unique=0: IL_007a: brfalse.s IL_0087 */
    if (stack0_0__ == 0) goto IL_0087;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* Path=6, Unique=0: IL_007c: ldc.i4.0 */
    stack0_0__ = 0;
    /* Path=6, Unique=0: IL_007d: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=6, Unique=0: IL_007f: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=6, Unique=0: IL_0084: nop */
    /* Path=6, Unique=0: IL_0085: br.s IL_00f5 */
    goto IL_00f5;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* Path=7, Unique=0: IL_0087: ldloc.3 */
    stack0_0__ = fs;
    /* Path=7, Unique=0: IL_0088: ldloc.s local5 */
    stack1_0__ = fe;
    /* Path=7, Unique=0: IL_008a: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=7, Unique=0: IL_008b: stloc.s local10 */
    local3 = stack0_0__ ? true : false;
    /* Path=7, Unique=0: IL_008d: ldloc.s local10 */
    stack0_0__ = local3;
    /* Path=7, Unique=0: IL_008f: brfalse.s IL_009c */
    if (stack0_0__ == 0) goto IL_009c;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* Path=7, Unique=0: IL_0091: ldc.i4.3 */
    stack0_0__ = 3;
    /* Path=7, Unique=0: IL_0092: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=7, Unique=0: IL_0094: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=7, Unique=0: IL_0099: nop */
    /* Path=7, Unique=0: IL_009a: br.s IL_00f5 */
    goto IL_00f5;
IL_009c:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(116): */
    /* Path=8, Unique=0: IL_009c: ldloc.3 */
    stack0_0__ = fs;
    /* Path=8, Unique=0: IL_009d: ldloc.s local4 */
    stack1_0__ = fw;
    /* Path=8, Unique=0: IL_009f: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=8, Unique=0: IL_00a0: stloc.s local11 */
    local4 = stack0_0__ ? true : false;
    /* Path=8, Unique=0: IL_00a2: ldloc.s local11 */
    stack0_0__ = local4;
    /* Path=8, Unique=0: IL_00a4: brfalse.s IL_00b1 */
    if (stack0_0__ == 0) goto IL_00b1;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(116): */
    /* Path=8, Unique=0: IL_00a6: ldc.i4.5 */
    stack0_0__ = 5;
    /* Path=8, Unique=0: IL_00a7: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=8, Unique=0: IL_00a9: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=8, Unique=0: IL_00ae: nop */
    /* Path=8, Unique=0: IL_00af: br.s IL_00f5 */
    goto IL_00f5;
IL_00b1:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(117): */
    /* Path=9, Unique=0: IL_00b1: ldloc.3 */
    stack0_0__ = fs;
    /* Path=9, Unique=0: IL_00b2: stloc.s local12 */
    local5 = stack0_0__ ? true : false;
    /* Path=9, Unique=0: IL_00b4: ldloc.s local12 */
    stack0_0__ = local5;
    /* Path=9, Unique=0: IL_00b6: brfalse.s IL_00c3 */
    if (stack0_0__ == 0) goto IL_00c3;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(117): */
    /* Path=9, Unique=0: IL_00b8: ldc.i4.4 */
    stack0_0__ = 4;
    /* Path=9, Unique=0: IL_00b9: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=9, Unique=0: IL_00bb: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=9, Unique=0: IL_00c0: nop */
    /* Path=9, Unique=0: IL_00c1: br.s IL_00f5 */
    goto IL_00f5;
IL_00c3:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(118): */
    /* Path=10, Unique=0: IL_00c3: ldloc.s local5 */
    stack0_0__ = fe;
    /* Path=10, Unique=0: IL_00c5: stloc.s local13 */
    local6 = stack0_0__ ? true : false;
    /* Path=10, Unique=0: IL_00c7: ldloc.s local13 */
    stack0_0__ = local6;
    /* Path=10, Unique=0: IL_00c9: brfalse.s IL_00d6 */
    if (stack0_0__ == 0) goto IL_00d6;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(118): */
    /* Path=10, Unique=0: IL_00cb: ldc.i4.2 */
    stack0_0__ = 2;
    /* Path=10, Unique=0: IL_00cc: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=10, Unique=0: IL_00ce: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=10, Unique=0: IL_00d3: nop */
    /* Path=10, Unique=0: IL_00d4: br.s IL_00f5 */
    goto IL_00f5;
IL_00d6:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(119): */
    /* Path=11, Unique=0: IL_00d6: ldloc.s local4 */
    stack0_0__ = fw;
    /* Path=11, Unique=0: IL_00d8: stloc.s local14 */
    local7 = stack0_0__ ? true : false;
    /* Path=11, Unique=0: IL_00da: ldloc.s local14 */
    stack0_0__ = local7;
    /* Path=11, Unique=0: IL_00dc: brfalse.s IL_00e9 */
    if (stack0_0__ == 0) goto IL_00e9;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(119): */
    /* Path=11, Unique=0: IL_00de: ldc.i4.6 */
    stack0_0__ = 6;
    /* Path=11, Unique=0: IL_00df: ldloc.s local6 */
    stack1_0__ = interval;
    /* Path=11, Unique=0: IL_00e1: call System.Void Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=11, Unique=0: IL_00e6: nop */
    /* Path=11, Unique=0: IL_00e7: br.s IL_00f5 */
    goto IL_00f5;
IL_00e9:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(120): */
    /* Path=12, Unique=0: IL_00e9: ldc.i4.0 */
    stack0_0__ = 0;
    /* Path=12, Unique=0: IL_00ea: ldc.i4 500 */
    stack1_0__ = 500;
    /* Path=12, Unique=0: IL_00ef: call System.Void Accelometer.Demo::ShowIcon(Accelometer.Demo/IconNames,System.UInt32) */
    Accelometer_Demo_ShowIcon((Accelometer_Demo_IconNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=12, Unique=0: IL_00f4: nop */
IL_00f5:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(122): */
    /* Path=5, Unique=0: IL_00f5: ldc.i4.5 */
    stack0_0__ = 5;
    /* Path=5, Unique=0: IL_00f6: call System.Void Accelometer.Demo::Delay(System.Int32) */
    Accelometer_Demo_Delay(stack0_0__);
    /* Path=5, Unique=0: IL_00fb: nop */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(123): */
    /* Path=5, Unique=0: IL_00fc: nop */
IL_00fd:
    /* Path=2, Unique=0: IL_00fd: ldc.i4.1 */
    stack0_0__ = 1;
    /* Path=2, Unique=0: IL_00fe: stloc.s local15 */
    local8 = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_0100: br IL_0014 */
    goto IL_0014;
}

///////////////////////////////////////
// .ctor

void Accelometer_Demo__ctor(Accelometer_Demo* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Accelometer_Demo* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Accelometer_Demo** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Accelometer_Demo_IL2C_RuntimeCast__(Accelometer_Demo* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Accelometer_Demo)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Accelometer_Demo_IL2C_MarkHandler__(Accelometer_Demo* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_RUNTIME_TYPE__ = {
    "Accelometer.Demo",
    sizeof(Accelometer_Demo),
    /* internalcall */ (IL2C_MARK_HANDLER)__Accelometer_Demo_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Accelometer.Demo
__Accelometer_Demo_VTABLE_DECL__ __Accelometer_Demo_VTABLE__ = {
    (void* (*)(Accelometer_Demo*, IL2C_RUNTIME_TYPE_DECL*))__Accelometer_Demo_IL2C_RuntimeCast__,
    (System_String* (*)(Accelometer_Demo*))__System_Object_ToString__,
    (int32_t (*)(Accelometer_Demo*))__System_Object_GetHashCode__,
    (void (*)(Accelometer_Demo*))__System_Object_Finalize__,
    (bool (*)(Accelometer_Demo*, System_Object*))__System_Object_Equals__,
};
