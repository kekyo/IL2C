#include "Accelometer.h"
#include "Accelometer.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:


#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:


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
// P/Invoke: ShowArrow

int8_t Accelometer_Demo_ShowArrow(Accelometer_Demo_ArrowNames direction, uint32_t interval)
{
    return SCREEN.showArrow(direction, interval);
}

///////////////////////////////////////
// P/Invoke: ShowIcon

int8_t Accelometer_Demo_ShowIcon(Accelometer_Demo_IconNames icon, uint32_t interval)
{
    return SCREEN.showIcon(icon, interval);
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

/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(89): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.0 */
    stack0_0__ = 0;
    /* Path=1, Unique=0: IL_0002: ldc.i4.2 */
    stack1_0__ = 2;
    /* Path=1, Unique=0: IL_0003: call System.Void Accelometer.Demo::BeginAccelometer(System.Boolean,System.Byte) */
    Accelometer_Demo_BeginAccelometer(stack0_0__ ? true : false, (uint8_t)stack1_0__);
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: br IL_010c */
    goto IL_010c;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(93): */
    /* Path=3, Unique=0: IL_000e: nop */
    /* Path=3, Unique=0: IL_000f: call System.Byte Accelometer.Demo::UpdateAccelometer() */
    stack0_0__ = Accelometer_Demo_UpdateAccelometer();
    /* Path=3, Unique=0: IL_0014: pop */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(96): */
    /* Path=3, Unique=0: IL_0015: call System.SByte Accelometer.Demo::GetAccelometerX() */
    stack0_0__ = Accelometer_Demo_GetAccelometerX();
    /* Path=3, Unique=0: IL_001a: stloc.0 */
    x = (int8_t)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(97): */
    /* Path=3, Unique=0: IL_001b: call System.SByte Accelometer.Demo::GetAccelometerY() */
    stack0_0__ = Accelometer_Demo_GetAccelometerY();
    /* Path=3, Unique=0: IL_0020: stloc.1 */
    y = (int8_t)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(99): */
    /* Path=3, Unique=0: IL_0021: ldloc.1 */
    stack0_0__ = y;
    /* Path=3, Unique=0: IL_0022: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* Path=3, Unique=0: IL_0024: cgt */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0026: stloc.2 */
    fn = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(100): */
    /* Path=3, Unique=0: IL_0027: ldloc.1 */
    stack0_0__ = y;
    /* Path=3, Unique=0: IL_0028: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* Path=3, Unique=0: IL_002a: clt */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_002c: stloc.3 */
    fs = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(101): */
    /* Path=3, Unique=0: IL_002d: ldloc.0 */
    stack0_0__ = x;
    /* Path=3, Unique=0: IL_002e: ldc.i4.s 20 */
    stack1_0__ = 20;
    /* Path=3, Unique=0: IL_0030: cgt */
    stack0_0__ = (stack0_0__ > stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0032: stloc.s local4 */
    fw = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(102): */
    /* Path=3, Unique=0: IL_0034: ldloc.0 */
    stack0_0__ = x;
    /* Path=3, Unique=0: IL_0035: ldc.i4.s -20 */
    stack1_0__ = -20;
    /* Path=3, Unique=0: IL_0037: clt */
    stack0_0__ = (stack0_0__ < stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0039: stloc.s local5 */
    fe = stack0_0__ ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(104): */
    /* Path=3, Unique=0: IL_003b: ldloc.2 */
    stack0_0__ = fn;
    /* Path=3, Unique=0: IL_003c: ldloc.s local5 */
    stack1_0__ = fe;
    /* Path=3, Unique=0: IL_003e: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=3, Unique=0: IL_003f: stloc.s local6 */
    local0 = stack0_0__ ? true : false;
    /* Path=3, Unique=0: IL_0041: ldloc.s local6 */
    stack0_0__ = local0;
    /* Path=3, Unique=0: IL_0043: brfalse.s IL_0056 */
    if (stack0_0__ == 0) goto IL_0056;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(104): */
    /* Path=3, Unique=0: IL_0045: ldc.i4.1 */
    stack0_0__ = 1;
    /* Path=3, Unique=0: IL_0046: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=3, Unique=0: IL_004b: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=3, Unique=0: IL_0050: pop */
    /* Path=3, Unique=0: IL_0051: br IL_0103 */
    goto IL_0103;
IL_0056:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(105): */
    /* Path=4, Unique=0: IL_0056: ldloc.2 */
    stack0_0__ = fn;
    /* Path=4, Unique=0: IL_0057: ldloc.s local4 */
    stack1_0__ = fw;
    /* Path=4, Unique=0: IL_0059: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=4, Unique=0: IL_005a: stloc.s local7 */
    local1 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_005c: ldloc.s local7 */
    stack0_0__ = local1;
    /* Path=4, Unique=0: IL_005e: brfalse.s IL_0071 */
    if (stack0_0__ == 0) goto IL_0071;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(105): */
    /* Path=4, Unique=0: IL_0060: ldc.i4.7 */
    stack0_0__ = 7;
    /* Path=4, Unique=0: IL_0061: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=4, Unique=0: IL_0066: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=4, Unique=0: IL_006b: pop */
    /* Path=4, Unique=0: IL_006c: br IL_0103 */
    goto IL_0103;
IL_0071:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(106): */
    /* Path=6, Unique=0: IL_0071: ldloc.2 */
    stack0_0__ = fn;
    /* Path=6, Unique=0: IL_0072: stloc.s local8 */
    local2 = stack0_0__ ? true : false;
    /* Path=6, Unique=0: IL_0074: ldloc.s local8 */
    stack0_0__ = local2;
    /* Path=6, Unique=0: IL_0076: brfalse.s IL_0086 */
    if (stack0_0__ == 0) goto IL_0086;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(106): */
    /* Path=6, Unique=0: IL_0078: ldc.i4.0 */
    stack0_0__ = 0;
    /* Path=6, Unique=0: IL_0079: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=6, Unique=0: IL_007e: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=6, Unique=0: IL_0083: pop */
    /* Path=6, Unique=0: IL_0084: br.s IL_0103 */
    goto IL_0103;
IL_0086:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(107): */
    /* Path=7, Unique=0: IL_0086: ldloc.3 */
    stack0_0__ = fs;
    /* Path=7, Unique=0: IL_0087: ldloc.s local5 */
    stack1_0__ = fe;
    /* Path=7, Unique=0: IL_0089: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=7, Unique=0: IL_008a: stloc.s local9 */
    local3 = stack0_0__ ? true : false;
    /* Path=7, Unique=0: IL_008c: ldloc.s local9 */
    stack0_0__ = local3;
    /* Path=7, Unique=0: IL_008e: brfalse.s IL_009e */
    if (stack0_0__ == 0) goto IL_009e;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(107): */
    /* Path=7, Unique=0: IL_0090: ldc.i4.3 */
    stack0_0__ = 3;
    /* Path=7, Unique=0: IL_0091: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=7, Unique=0: IL_0096: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=7, Unique=0: IL_009b: pop */
    /* Path=7, Unique=0: IL_009c: br.s IL_0103 */
    goto IL_0103;
IL_009e:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(108): */
    /* Path=8, Unique=0: IL_009e: ldloc.3 */
    stack0_0__ = fs;
    /* Path=8, Unique=0: IL_009f: ldloc.s local4 */
    stack1_0__ = fw;
    /* Path=8, Unique=0: IL_00a1: and */
    stack0_0__ = stack0_0__ & stack1_0__;
    /* Path=8, Unique=0: IL_00a2: stloc.s local10 */
    local4 = stack0_0__ ? true : false;
    /* Path=8, Unique=0: IL_00a4: ldloc.s local10 */
    stack0_0__ = local4;
    /* Path=8, Unique=0: IL_00a6: brfalse.s IL_00b6 */
    if (stack0_0__ == 0) goto IL_00b6;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(108): */
    /* Path=8, Unique=0: IL_00a8: ldc.i4.5 */
    stack0_0__ = 5;
    /* Path=8, Unique=0: IL_00a9: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=8, Unique=0: IL_00ae: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=8, Unique=0: IL_00b3: pop */
    /* Path=8, Unique=0: IL_00b4: br.s IL_0103 */
    goto IL_0103;
IL_00b6:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(109): */
    /* Path=9, Unique=0: IL_00b6: ldloc.3 */
    stack0_0__ = fs;
    /* Path=9, Unique=0: IL_00b7: stloc.s local11 */
    local5 = stack0_0__ ? true : false;
    /* Path=9, Unique=0: IL_00b9: ldloc.s local11 */
    stack0_0__ = local5;
    /* Path=9, Unique=0: IL_00bb: brfalse.s IL_00cb */
    if (stack0_0__ == 0) goto IL_00cb;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(109): */
    /* Path=9, Unique=0: IL_00bd: ldc.i4.4 */
    stack0_0__ = 4;
    /* Path=9, Unique=0: IL_00be: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=9, Unique=0: IL_00c3: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=9, Unique=0: IL_00c8: pop */
    /* Path=9, Unique=0: IL_00c9: br.s IL_0103 */
    goto IL_0103;
IL_00cb:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(110): */
    /* Path=10, Unique=0: IL_00cb: ldloc.s local5 */
    stack0_0__ = fe;
    /* Path=10, Unique=0: IL_00cd: stloc.s local12 */
    local6 = stack0_0__ ? true : false;
    /* Path=10, Unique=0: IL_00cf: ldloc.s local12 */
    stack0_0__ = local6;
    /* Path=10, Unique=0: IL_00d1: brfalse.s IL_00e1 */
    if (stack0_0__ == 0) goto IL_00e1;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(110): */
    /* Path=10, Unique=0: IL_00d3: ldc.i4.2 */
    stack0_0__ = 2;
    /* Path=10, Unique=0: IL_00d4: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=10, Unique=0: IL_00d9: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=10, Unique=0: IL_00de: pop */
    /* Path=10, Unique=0: IL_00df: br.s IL_0103 */
    goto IL_0103;
IL_00e1:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(111): */
    /* Path=11, Unique=0: IL_00e1: ldloc.s local4 */
    stack0_0__ = fw;
    /* Path=11, Unique=0: IL_00e3: stloc.s local13 */
    local7 = stack0_0__ ? true : false;
    /* Path=11, Unique=0: IL_00e5: ldloc.s local13 */
    stack0_0__ = local7;
    /* Path=11, Unique=0: IL_00e7: brfalse.s IL_00f7 */
    if (stack0_0__ == 0) goto IL_00f7;
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(111): */
    /* Path=11, Unique=0: IL_00e9: ldc.i4.6 */
    stack0_0__ = 6;
    /* Path=11, Unique=0: IL_00ea: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=11, Unique=0: IL_00ef: call System.SByte Accelometer.Demo::ShowArrow(Accelometer.Demo/ArrowNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowArrow((Accelometer_Demo_ArrowNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=11, Unique=0: IL_00f4: pop */
    /* Path=11, Unique=0: IL_00f5: br.s IL_0103 */
    goto IL_0103;
IL_00f7:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(112): */
    /* Path=12, Unique=0: IL_00f7: ldc.i4.0 */
    stack0_0__ = 0;
    /* Path=12, Unique=0: IL_00f8: ldc.i4 750 */
    stack1_0__ = 750;
    /* Path=12, Unique=0: IL_00fd: call System.SByte Accelometer.Demo::ShowIcon(Accelometer.Demo/IconNames,System.UInt32) */
    stack0_0__ = Accelometer_Demo_ShowIcon((Accelometer_Demo_IconNames)stack0_0__, (uint32_t)stack1_0__);
    /* Path=12, Unique=0: IL_0102: pop */
IL_0103:
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(114): */
    /* Path=5, Unique=0: IL_0103: ldc.i4.s 100 */
    stack0_0__ = 100;
    /* Path=5, Unique=0: IL_0105: call System.Void Accelometer.Demo::Delay(System.Int32) */
    Accelometer_Demo_Delay(stack0_0__);
    /* Path=5, Unique=0: IL_010a: nop */
/* D:\\PROJECT\\IL2C\\samples\\microbit\\Accelometer.Code\\Demo.cs(115): */
    /* Path=5, Unique=0: IL_010b: nop */
IL_010c:
    /* Path=2, Unique=0: IL_010c: ldc.i4.1 */
    stack0_0__ = 1;
    /* Path=2, Unique=0: IL_010d: stloc.s local14 */
    local8 = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_010f: br IL_000e */
    goto IL_000e;
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
    /* internalcall */ (void*)__Accelometer_Demo_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Accelometer.Demo
__Accelometer_Demo_VTABLE_DECL__ __Accelometer_Demo_VTABLE__ = {
    (void*)__Accelometer_Demo_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};
