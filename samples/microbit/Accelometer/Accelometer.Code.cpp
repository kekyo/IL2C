
#include "Accelometer.h"
#include "Accelometer.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:


//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:


////////////////////////////////////////////////////////////
// [1] Accelometer.Demo.ArrowNames

// [1-1] Enum layout
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

// [1-4] Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_ArrowNames_RUNTIME_TYPE__;

// [1-5] Enum vtable
extern __Accelometer_Demo_ArrowNames_VTABLE_DECL__ __Accelometer_Demo_ArrowNames_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Accelometer.Demo.IconNames

// [1-1] Enum layout
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

// [1-4] Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_IconNames_RUNTIME_TYPE__;

// [1-5] Enum vtable
extern __Accelometer_Demo_IconNames_VTABLE_DECL__ __Accelometer_Demo_IconNames_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:


//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: Accelometer.Demo

extern void Accelometer_Demo_BeginAccelometer(bool highResolution, uint8_t scale);
extern uint8_t Accelometer_Demo_UpdateAccelometer();
extern int8_t Accelometer_Demo_GetAccelometerX();
extern int8_t Accelometer_Demo_GetAccelometerY();
extern int8_t Accelometer_Demo_GetAccelometerZ();
extern void Accelometer_Demo_BeginScreen();
extern void Accelometer_Demo_ShowArrow(Accelometer_Demo_ArrowNames direction, uint32_t interval);
extern void Accelometer_Demo_ShowIcon(Accelometer_Demo_IconNames icon, uint32_t interval);
extern void Accelometer_Demo_Delay(int32_t millis);

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Declare static fields:


//////////////////////////////////////////////////////////////////////////////////
// [9-4] Declare methods:

////////////////////////////////////////////////////////////
// [9-4] Type: Accelometer.Demo

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.BeginAccelometer(System.Boolean highResolution, System.Byte scale)

void Accelometer_Demo_BeginAccelometer(bool highResolution, uint8_t scale)
{
    accelometer.begin(highResolution, scale);
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.UpdateAccelometer()

uint8_t Accelometer_Demo_UpdateAccelometer()
{
    return accelometer.update();
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.GetAccelometerX()

int8_t Accelometer_Demo_GetAccelometerX()
{
    return accelometer.getX();
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.GetAccelometerY()

int8_t Accelometer_Demo_GetAccelometerY()
{
    return accelometer.getY();
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.GetAccelometerZ()

int8_t Accelometer_Demo_GetAccelometerZ()
{
    return accelometer.getZ();
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.BeginScreen()

void Accelometer_Demo_BeginScreen()
{
    SCREEN.begin();
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.ShowArrow(Accelometer.Demo.ArrowNames direction, System.UInt32 interval)

void Accelometer_Demo_ShowArrow(Accelometer_Demo_ArrowNames direction, uint32_t interval)
{
    SCREEN.showArrow((ArrowNames)direction, interval);
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.ShowIcon(Accelometer.Demo.IconNames icon, System.UInt32 interval)

void Accelometer_Demo_ShowIcon(Accelometer_Demo_IconNames icon, uint32_t interval)
{
    SCREEN.showIcon((IconNames)icon, interval);
}

///////////////////////////////////////
// [6] P/Invoke: Accelometer.Demo.Delay(System.Int32 millis)

void Accelometer_Demo_Delay(int32_t millis)
{
    delay(millis);
}

///////////////////////////////////////
// [3] Accelometer.Demo.Main()

void Accelometer_Demo_Main()
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
    bool local7__;
    bool local8__;
    bool local9__;
    bool local10__;
    bool local11__;
    bool local12__;
    bool local13__;
    bool local14__;
    bool local15__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(94): */
    /* IL_0000: nop  */
    /* IL_0001: call Accelometer.Demo.BeginScreen */
    Accelometer_Demo_BeginScreen();
    /* IL_0006: nop  */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(96): */
    /* IL_0007: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_0008: ldc.i4.2  */
    stack1_0__ = 2;
    /* IL_0009: call Accelometer.Demo.BeginAccelometer */
    Accelometer_Demo_BeginAccelometer((stack0_0__) ? true : false, (uint8_t)(stack1_0__));
    /* IL_000e: nop  */
    /* IL_000f: br IL_00fd */
    goto IL_00fd;
IL_0014:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(99): */
    /* IL_0014: nop  */
    /* IL_0015: call Accelometer.Demo.UpdateAccelometer */
    stack0_0__ = Accelometer_Demo_UpdateAccelometer();
    /* IL_001a: pop  */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(102): */
    /* IL_001b: call Accelometer.Demo.GetAccelometerX */
    stack0_0__ = Accelometer_Demo_GetAccelometerX();
    /* IL_0020: stloc.0  */
    x = (int8_t)(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(103): */
    /* IL_0021: call Accelometer.Demo.GetAccelometerY */
    stack0_0__ = Accelometer_Demo_GetAccelometerY();
    /* IL_0026: stloc.1  */
    y = (int8_t)(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(105): */
    /* IL_0027: ldloc.1  */
    stack0_0__ = y;
    /* IL_0028: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* IL_002a: cgt  */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* IL_002c: stloc.2  */
    fn = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(106): */
    /* IL_002d: ldloc.1  */
    stack0_0__ = y;
    /* IL_002e: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* IL_0030: clt  */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* IL_0032: stloc.3  */
    fs = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(107): */
    /* IL_0033: ldloc.0  */
    stack0_0__ = x;
    /* IL_0034: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* IL_0036: cgt  */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* IL_0038: stloc.s fw */
    fw = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(108): */
    /* IL_003a: ldloc.0  */
    stack0_0__ = x;
    /* IL_003b: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* IL_003d: clt  */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* IL_003f: stloc.s fe */
    fe = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(110): */
    /* IL_0041: ldc.i4.s 30 */
    stack0_0__ = 30;
    /* IL_0043: stloc.s interval */
    interval = (uint32_t)(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* IL_0045: ldloc.2  */
    stack0_0__ = fn;
    /* IL_0046: ldloc.s fe */
    stack1_0__ = fe;
    /* IL_0048: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_0049: stloc.s local7__ */
    local7__ = (stack0_0__) ? true : false;
    /* IL_004b: ldloc.s local7__ */
    stack0_0__ = local7__;
    /* IL_004d: brfalse.s IL_005d */
    if (stack0_0__ == 0) goto IL_005d;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* IL_004f: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_0050: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_0052: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_0057: nop  */
    /* IL_0058: br IL_00f5 */
    goto IL_00f5;
IL_005d:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(113): */
    /* IL_005d: ldloc.2  */
    stack0_0__ = fn;
    /* IL_005e: ldloc.s fw */
    stack1_0__ = fw;
    /* IL_0060: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_0061: stloc.s local8__ */
    local8__ = (stack0_0__) ? true : false;
    /* IL_0063: ldloc.s local8__ */
    stack0_0__ = local8__;
    /* IL_0065: brfalse.s IL_0075 */
    if (stack0_0__ == 0) goto IL_0075;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(113): */
    /* IL_0067: ldc.i4.7  */
    stack0_0__ = 7;
    /* IL_0068: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_006a: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_006f: nop  */
    /* IL_0070: br IL_00f5 */
    goto IL_00f5;
IL_0075:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* IL_0075: ldloc.2  */
    stack0_0__ = fn;
    /* IL_0076: stloc.s local9__ */
    local9__ = (stack0_0__) ? true : false;
    /* IL_0078: ldloc.s local9__ */
    stack0_0__ = local9__;
    /* IL_007a: brfalse.s IL_0087 */
    if (stack0_0__ == 0) goto IL_0087;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* IL_007c: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_007d: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_007f: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_0084: nop  */
    /* IL_0085: br.s IL_00f5 */
    goto IL_00f5;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* IL_0087: ldloc.3  */
    stack0_0__ = fs;
    /* IL_0088: ldloc.s fe */
    stack1_0__ = fe;
    /* IL_008a: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_008b: stloc.s local10__ */
    local10__ = (stack0_0__) ? true : false;
    /* IL_008d: ldloc.s local10__ */
    stack0_0__ = local10__;
    /* IL_008f: brfalse.s IL_009c */
    if (stack0_0__ == 0) goto IL_009c;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* IL_0091: ldc.i4.3  */
    stack0_0__ = 3;
    /* IL_0092: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_0094: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_0099: nop  */
    /* IL_009a: br.s IL_00f5 */
    goto IL_00f5;
IL_009c:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(116): */
    /* IL_009c: ldloc.3  */
    stack0_0__ = fs;
    /* IL_009d: ldloc.s fw */
    stack1_0__ = fw;
    /* IL_009f: and  */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* IL_00a0: stloc.s local11__ */
    local11__ = (stack0_0__) ? true : false;
    /* IL_00a2: ldloc.s local11__ */
    stack0_0__ = local11__;
    /* IL_00a4: brfalse.s IL_00b1 */
    if (stack0_0__ == 0) goto IL_00b1;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(116): */
    /* IL_00a6: ldc.i4.5  */
    stack0_0__ = 5;
    /* IL_00a7: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00a9: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_00ae: nop  */
    /* IL_00af: br.s IL_00f5 */
    goto IL_00f5;
IL_00b1:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(117): */
    /* IL_00b1: ldloc.3  */
    stack0_0__ = fs;
    /* IL_00b2: stloc.s local12__ */
    local12__ = (stack0_0__) ? true : false;
    /* IL_00b4: ldloc.s local12__ */
    stack0_0__ = local12__;
    /* IL_00b6: brfalse.s IL_00c3 */
    if (stack0_0__ == 0) goto IL_00c3;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(117): */
    /* IL_00b8: ldc.i4.4  */
    stack0_0__ = 4;
    /* IL_00b9: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00bb: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_00c0: nop  */
    /* IL_00c1: br.s IL_00f5 */
    goto IL_00f5;
IL_00c3:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(118): */
    /* IL_00c3: ldloc.s fe */
    stack0_0__ = fe;
    /* IL_00c5: stloc.s local13__ */
    local13__ = (stack0_0__) ? true : false;
    /* IL_00c7: ldloc.s local13__ */
    stack0_0__ = local13__;
    /* IL_00c9: brfalse.s IL_00d6 */
    if (stack0_0__ == 0) goto IL_00d6;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(118): */
    /* IL_00cb: ldc.i4.2  */
    stack0_0__ = 2;
    /* IL_00cc: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00ce: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_00d3: nop  */
    /* IL_00d4: br.s IL_00f5 */
    goto IL_00f5;
IL_00d6:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(119): */
    /* IL_00d6: ldloc.s fw */
    stack0_0__ = fw;
    /* IL_00d8: stloc.s local14__ */
    local14__ = (stack0_0__) ? true : false;
    /* IL_00da: ldloc.s local14__ */
    stack0_0__ = local14__;
    /* IL_00dc: brfalse.s IL_00e9 */
    if (stack0_0__ == 0) goto IL_00e9;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(119): */
    /* IL_00de: ldc.i4.6  */
    stack0_0__ = 6;
    /* IL_00df: ldloc.s interval */
    stack1_0__ = interval;
    /* IL_00e1: call Accelometer.Demo.ShowArrow */
    Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_00e6: nop  */
    /* IL_00e7: br.s IL_00f5 */
    goto IL_00f5;
IL_00e9:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(120): */
    /* IL_00e9: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_00ea: ldc.i4 500 */
    stack1_0__ = 500;
    /* IL_00ef: call Accelometer.Demo.ShowIcon */
    Accelometer_Demo_ShowIcon((Accelometer_Demo_IconNames)stack0_0__, (uint32_t)(stack1_0__));
    /* IL_00f4: nop  */
IL_00f5:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(122): */
    /* IL_00f5: ldc.i4.5  */
    stack0_0__ = 5;
    /* IL_00f6: call Accelometer.Demo.Delay */
    Accelometer_Demo_Delay(stack0_0__);
    /* IL_00fb: nop  */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(123): */
    /* IL_00fc: nop  */
IL_00fd:
    /* IL_00fd: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_00fe: stloc.s local15__ */
    local15__ = (stack0_0__) ? true : false;
    /* IL_0100: br IL_0014 */
    goto IL_0014;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Accelometer_Demo_IL2C_RuntimeCast__(Accelometer_Demo* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Accelometer_Demo)) return this__;

    // [7-4] Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// [7-5] GC's mark handler
void __Accelometer_Demo_IL2C_MarkHandler__(Accelometer_Demo* this__)
{

    // [7-7] Delegate checking base types
    __System_Object_IL2C_MarkHandler__((System_Object*)this__);
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_RUNTIME_TYPE__ = {
    "Accelometer.Demo",
    sizeof(Accelometer_Demo),
    /* internalcall */ (IL2C_MARK_HANDLER)__Accelometer_Demo_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Accelometer.Demo
__Accelometer_Demo_VTABLE_DECL__ __Accelometer_Demo_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Accelometer.Demo.ArrowNames

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Accelometer_Demo_ArrowNames_IL2C_RuntimeCast__(Accelometer_Demo_ArrowNames* this__, IL2C_RUNTIME_TYPE_DECL* type)
{

    // [7-4] Delegate checking base types
    return __System_Enum_IL2C_RuntimeCast__((System_Enum*)this__, type);
}

// [7-5] GC's mark handler
void __Accelometer_Demo_ArrowNames_IL2C_MarkHandler__(Accelometer_Demo_ArrowNames* this__)
{

    /* Suppressed invoke base mark handler */
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_ArrowNames_RUNTIME_TYPE__ = {
    "Accelometer.Demo.ArrowNames",
    sizeof(Accelometer_Demo_ArrowNames),
    /* internalcall */ (IL2C_MARK_HANDLER)__Accelometer_Demo_ArrowNames_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Accelometer.Demo.IconNames

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Accelometer_Demo_IconNames_IL2C_RuntimeCast__(Accelometer_Demo_IconNames* this__, IL2C_RUNTIME_TYPE_DECL* type)
{

    // [7-4] Delegate checking base types
    return __System_Enum_IL2C_RuntimeCast__((System_Enum*)this__, type);
}

// [7-5] GC's mark handler
void __Accelometer_Demo_IconNames_IL2C_MarkHandler__(Accelometer_Demo_IconNames* this__)
{

    /* Suppressed invoke base mark handler */
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_IconNames_RUNTIME_TYPE__ = {
    "Accelometer.Demo.IconNames",
    sizeof(Accelometer_Demo_IconNames),
    /* internalcall */ (IL2C_MARK_HANDLER)__Accelometer_Demo_IconNames_IL2C_MarkHandler__,
};
