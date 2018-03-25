#include "Accelometer.h"
#include "Accelometer.Code, Version=0.3.1.0, Culture=neutral, PublicKeyToken=null.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:


#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:


////////////////////////////////////////////////////////////
// Enum: Accelometer.Demo/ArrowNames

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

// Enum vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Accelometer_Demo_ArrowNames* this__, IL2C_RUNTIME_TYPE_DECL* type);
} __Accelometer_Demo_ArrowNames_VTABLE_DECL__;

// Enum layout
struct Accelometer_Demo_ArrowNames
{
    __Accelometer_Demo_ArrowNames_VTABLE_DECL__* vptr0__;
    __System_IComparable_VTABLE_DECL__* vptr_System_IComparable__;
    __System_IFormattable_VTABLE_DECL__* vptr_System_IFormattable__;
    __System_IConvertible_VTABLE_DECL__* vptr_System_IConvertible__;
    System_Int32 value__;
};


// Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_ArrowNames_RUNTIME_TYPE__;

// Enum vtable
extern __Accelometer_Demo_ArrowNames_VTABLE_DECL__ __Accelometer_Demo_ArrowNames_VTABLE__;

////////////////////////////////////////////////////////////
// Enum: Accelometer.Demo/IconNames

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

// Enum vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Accelometer_Demo_IconNames* this__, IL2C_RUNTIME_TYPE_DECL* type);
} __Accelometer_Demo_IconNames_VTABLE_DECL__;

// Enum layout
struct Accelometer_Demo_IconNames
{
    __Accelometer_Demo_IconNames_VTABLE_DECL__* vptr0__;
    __System_IComparable_VTABLE_DECL__* vptr_System_IComparable__;
    __System_IFormattable_VTABLE_DECL__* vptr_System_IFormattable__;
    __System_IConvertible_VTABLE_DECL__* vptr_System_IConvertible__;
    System_Int32 value__;
};


// Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_IconNames_RUNTIME_TYPE__;

// Enum vtable
extern __Accelometer_Demo_IconNames_VTABLE_DECL__ __Accelometer_Demo_IconNames_VTABLE__;

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
// P/Invoke: Accelometer.Demo.BeginAccelometer@0(System.Boolean highResolution, System.Byte scale)

System_Void* Accelometer_Demo_BeginAccelometer_0(System_Boolean highResolution, System_Byte scale)(System_Boolean highResolution, System_Byte scale)
{
    accelometer.begin(highResolution, scale);
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.UpdateAccelometer@0()

System_Byte Accelometer_Demo_UpdateAccelometer_0()()
{
    return accelometer.update();
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.GetAccelometerX@0()

System_SByte Accelometer_Demo_GetAccelometerX_0()()
{
    return accelometer.getX();
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.GetAccelometerY@0()

System_SByte Accelometer_Demo_GetAccelometerY_0()()
{
    return accelometer.getY();
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.GetAccelometerZ@0()

System_SByte Accelometer_Demo_GetAccelometerZ_0()()
{
    return accelometer.getZ();
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.BeginScreen@0()

System_Void* Accelometer_Demo_BeginScreen_0()()
{
    SCREEN.begin();
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval)

System_Void* Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)
{
    SCREEN.showArrow((ArrowNames)direction, interval);
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.ShowIcon@0(Accelometer.Demo.IconNames icon, System.UInt32 interval)

System_Void* Accelometer_Demo_ShowIcon_0(Accelometer_Demo_IconNames icon, System_UInt32 interval)(Accelometer_Demo_IconNames icon, System_UInt32 interval)
{
    SCREEN.showIcon((IconNames)icon, interval);
}

///////////////////////////////////////
// P/Invoke: Accelometer.Demo.Delay@0(System.Int32 millis)

System_Void* Accelometer_Demo_Delay_0(System_Int32 millis)(System_Int32 millis)
{
    delay(millis);
}

///////////////////////////////////////
// Accelometer.Demo.Main@0()

System_Void* Accelometer_Demo_Main_0()()
{
    //-------------------
    // Local variables:

    System_SByte x;
    System_SByte y;
    System_Boolean fn;
    System_Boolean fs;
    System_Boolean fw;
    System_Boolean fe;
    System_UInt32 interval;
    System_Boolean local7__;
    System_Boolean local8__;
    System_Boolean local9__;
    System_Boolean local10__;
    System_Boolean local11__;
    System_Boolean local12__;
    System_Boolean local13__;
    System_Boolean local14__;
    System_Boolean local15__;

    //-------------------
    // Evaluation stacks:

    System_Int32 stack0_0__;
    System_Int32 stack1_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(94): */
    /* IL_0000: nop  */
    /* IL_0001: call Accelometer.Demo.BeginScreen@0() */
    Accelometer_Demo_BeginScreen_0()();
    /* IL_0006: nop  */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(96): */
    /* IL_0007: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_0008: ldc.i4.2  */
    stack1_0__ = 2;
    /* IL_0009: call Accelometer.Demo.BeginAccelometer@0(System.Boolean highResolution, System.Byte scale) */
    Accelometer_Demo_BeginAccelometer_0(System_Boolean highResolution, System_Byte scale)(stack0_0__ ? true : false, (System_Byte)stack1_0__);
    /* IL_000e: nop  */
    /* IL_000f: br IL_00fd */
    goto IL_000f;
IL_0014:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(99): */
    /* IL_0014: nop  */
    /* IL_0015: call Accelometer.Demo.UpdateAccelometer@0() */
    stack0_0__ = Accelometer_Demo_UpdateAccelometer_0()();
    /* IL_001a: pop  */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(102): */
    /* IL_001b: call Accelometer.Demo.GetAccelometerX@0() */
    stack0_0__ = Accelometer_Demo_GetAccelometerX_0()();
    /* IL_0020: stloc.0  */
    x = (System_SByte)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(103): */
    /* IL_0021: call Accelometer.Demo.GetAccelometerY@0() */
    stack0_0__ = Accelometer_Demo_GetAccelometerY_0()();
    /* IL_0026: stloc.1  */
    y = (System_SByte)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(105): */
    /* IL_0027: ldloc.1  */
    stack0_0__ = y;
    /* IL_0028: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* IL_002a: cgt  */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* IL_002c: stloc.2  */
    fn = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(106): */
    /* IL_002d: ldloc.1  */
    stack0_0__ = y;
    /* IL_002e: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* IL_0030: clt  */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* IL_0032: stloc.3  */
    fs = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(107): */
    /* IL_0033: ldloc.0  */
    stack0_0__ = x;
    /* IL_0034: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* IL_0036: cgt  */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* IL_0038: stloc.s fw */
    fw = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(108): */
    /* IL_003a: ldloc.0  */
    stack0_0__ = x;
    /* IL_003b: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* IL_003d: clt  */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* IL_003f: stloc.s fe */
    fe = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(110): */
    /* IL_0041: ldc.i4.s 30 */
    stack0_0__ = 30;
    /* IL_0043: stloc.s interval */
    interval = (System_UInt32)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* IL_0045: ldloc.2  */
    stack0_0__ = fn;
    /* IL_0046: ldloc.s fe */
    stack1_0__ = fe;
    /* IL_0048: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_0049: stloc.s local7__ */
    local7__ = stack0_0__ ? true : false;
    /* IL_004b: ldloc.s local7__ */
    stack0_0__ = local7__;
    /* IL_004d: brfalse.s IL_005d */
    if (stack0_0__ == 0) goto IL_004d;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* IL_004f: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_0050: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_0052: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_0057: nop  */
    /* IL_0058: br IL_00f5 */
    goto IL_0058;
IL_005d:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(113): */
    /* IL_005d: ldloc.2  */
    stack0_0__ = fn;
    /* IL_005e: ldloc.s fw */
    stack1_0__ = fw;
    /* IL_0060: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_0061: stloc.s local8__ */
    local8__ = stack0_0__ ? true : false;
    /* IL_0063: ldloc.s local8__ */
    stack0_0__ = local8__;
    /* IL_0065: brfalse.s IL_0075 */
    if (stack0_0__ == 0) goto IL_0065;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(113): */
    /* IL_0067: ldc.i4.7  */
    stack0_0__ = 7;
    /* IL_0068: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_006a: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_006f: nop  */
    /* IL_0070: br IL_00f5 */
    goto IL_0058;
IL_0075:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* IL_0075: ldloc.2  */
    stack0_0__ = fn;
    /* IL_0076: stloc.s local9__ */
    local9__ = stack0_0__ ? true : false;
    /* IL_0078: ldloc.s local9__ */
    stack0_0__ = local9__;
    /* IL_007a: brfalse.s IL_0087 */
    if (stack0_0__ == 0) goto IL_007a;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* IL_007c: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_007d: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_007f: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_0084: nop  */
    /* IL_0085: br.s IL_00f5 */
    goto IL_0058;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* IL_0087: ldloc.3  */
    stack0_0__ = fs;
    /* IL_0088: ldloc.s fe */
    stack1_0__ = fe;
    /* IL_008a: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_008b: stloc.s local10__ */
    local10__ = stack0_0__ ? true : false;
    /* IL_008d: ldloc.s local10__ */
    stack0_0__ = local10__;
    /* IL_008f: brfalse.s IL_009c */
    if (stack0_0__ == 0) goto IL_008f;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* IL_0091: ldc.i4.3  */
    stack0_0__ = 3;
    /* IL_0092: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_0094: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_0099: nop  */
    /* IL_009a: br.s IL_00f5 */
    goto IL_0058;
IL_009c:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(116): */
    /* IL_009c: ldloc.3  */
    stack0_0__ = fs;
    /* IL_009d: ldloc.s fw */
    stack1_0__ = fw;
    /* IL_009f: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_00a0: stloc.s local11__ */
    local11__ = stack0_0__ ? true : false;
    /* IL_00a2: ldloc.s local11__ */
    stack0_0__ = local11__;
    /* IL_00a4: brfalse.s IL_00b1 */
    if (stack0_0__ == 0) goto IL_00a4;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(116): */
    /* IL_00a6: ldc.i4.5  */
    stack0_0__ = 5;
    /* IL_00a7: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00a9: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_00ae: nop  */
    /* IL_00af: br.s IL_00f5 */
    goto IL_0058;
IL_00b1:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(117): */
    /* IL_00b1: ldloc.3  */
    stack0_0__ = fs;
    /* IL_00b2: stloc.s local12__ */
    local12__ = stack0_0__ ? true : false;
    /* IL_00b4: ldloc.s local12__ */
    stack0_0__ = local12__;
    /* IL_00b6: brfalse.s IL_00c3 */
    if (stack0_0__ == 0) goto IL_00b6;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(117): */
    /* IL_00b8: ldc.i4.4  */
    stack0_0__ = 4;
    /* IL_00b9: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00bb: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_00c0: nop  */
    /* IL_00c1: br.s IL_00f5 */
    goto IL_0058;
IL_00c3:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(118): */
    /* IL_00c3: ldloc.s fe */
    stack0_0__ = fe;
    /* IL_00c5: stloc.s local13__ */
    local13__ = stack0_0__ ? true : false;
    /* IL_00c7: ldloc.s local13__ */
    stack0_0__ = local13__;
    /* IL_00c9: brfalse.s IL_00d6 */
    if (stack0_0__ == 0) goto IL_00c9;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(118): */
    /* IL_00cb: ldc.i4.2  */
    stack0_0__ = 2;
    /* IL_00cc: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00ce: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_00d3: nop  */
    /* IL_00d4: br.s IL_00f5 */
    goto IL_0058;
IL_00d6:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(119): */
    /* IL_00d6: ldloc.s fw */
    stack0_0__ = fw;
    /* IL_00d8: stloc.s local14__ */
    local14__ = stack0_0__ ? true : false;
    /* IL_00da: ldloc.s local14__ */
    stack0_0__ = local14__;
    /* IL_00dc: brfalse.s IL_00e9 */
    if (stack0_0__ == 0) goto IL_00dc;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(119): */
    /* IL_00de: ldc.i4.6  */
    stack0_0__ = 6;
    /* IL_00df: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00e1: call Accelometer.Demo.ShowArrow@0(Accelometer.Demo.ArrowNames direction, System.UInt32 interval) */
    Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)((Accelometer_Demo_ArrowNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_00e6: nop  */
    /* IL_00e7: br.s IL_00f5 */
    goto IL_0058;
IL_00e9:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(120): */
    /* IL_00e9: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_00ea: ldc.i4 500 */
    stack1_0__ = 500;
    /* IL_00ef: call Accelometer.Demo.ShowIcon@0(Accelometer.Demo.IconNames icon, System.UInt32 interval) */
    Accelometer_Demo_ShowIcon_0(Accelometer_Demo_IconNames icon, System_UInt32 interval)((Accelometer_Demo_IconNames)stack0_0__, (System_UInt32)stack1_0__);
    /* IL_00f4: nop  */
IL_00f5:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(122): */
    /* IL_00f5: ldc.i4.5  */
    stack0_0__ = 5;
    /* IL_00f6: call Accelometer.Demo.Delay@0(System.Int32 millis) */
    Accelometer_Demo_Delay_0(System_Int32 millis)(stack0_0__);
    /* IL_00fb: nop  */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(123): */
    /* IL_00fc: nop  */
IL_00fd:
    /* IL_00fd: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_00fe: stloc.s local15__ */
    local15__ = stack0_0__ ? true : false;
    /* IL_0100: br IL_0014 */
    goto IL_0100;
}

///////////////////////////////////////
// Accelometer.Demo..ctor@0(Accelometer.Demo this__)

System_Void* Accelometer_Demo__ctor_0(Accelometer_Demo this__)(Accelometer_Demo* this__)
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

    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor@0(System.Object this__) */
    /* IL_0006: nop  */
    /* IL_0007: ret  */
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
    sizeof(Accelometer_Demo*),
    /* internalcall */ (IL2C_MARK_HANDLER)__Accelometer_Demo_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Accelometer.Demo
__Accelometer_Demo_VTABLE_DECL__ __Accelometer_Demo_VTABLE__ = {
};
