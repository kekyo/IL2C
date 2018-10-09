
#include "memmem.h"
#include "WDM.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:

IL2C_CONST_STRING(string0__, L"Hello driver constructor called!!\r\n");
IL2C_CONST_STRING(string1__, L"Draw BABEL!!\r\n");

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:


//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: WDM.Code.InterceptCDRomDevice

extern /* internalcall */ void __WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__(WDM_Code_InterceptCDRomDevice* this__);
extern /* internalcall */ void* __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: WDM.Code.InterceptCDRomDevice


// [2-4] Member methods: WDM.Code.Wdm

extern /* internalcall */ void __WDM_Code_Wdm_IL2C_MarkHandler__(WDM_Code_Wdm* this__);
extern /* internalcall */ void* __WDM_Code_Wdm_IL2C_RuntimeCast__(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: WDM.Code.Wdm


#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Declare static fields:



//////////////////////////////////////////////////////////////////////////////////
// [9-4] Declare methods:

////////////////////////////////////////////////////////////
// [9-4] Type: WDM.Code.InterceptCDRomDevice

///////////////////////////////////////
// [3] WDM.Code.InterceptCDRomDevice..ctor(WDM.Code.InterceptCDRomDevice this__, System.IntPtr pFrom, System.IntPtr pTo, System.Int32 size)

void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* this__, intptr_t pFrom, intptr_t pTo, int32_t size)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WDM_Code_InterceptCDRomDevice* stack0_0__ = NULL;
    System_String* stack0_1__ = NULL;
    intptr_t stack1_0__;
    int32_t stack1_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        WDM_Code_InterceptCDRomDevice** pstack0_0__;
        System_String** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(11): */
    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    /* IL_0006: nop  */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(12): */
    /* IL_0007: nop  */
    /* IL_0008: ldstr "Hello driver constructor called!!
" */
    stack0_1__ = string0__;
    /* IL_000d: call WDM.Code.Wdm.DbgPrint */
    WDM_Code_Wdm_DbgPrint(stack0_1__);
    /* IL_0012: nop  */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(15): */
    /* IL_0013: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0014: ldarg.1  */
    stack1_0__ = pFrom;
    /* IL_0015: stfld WDM.Code.InterceptCDRomDevice.pFrom */
    stack0_0__->pFrom = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(16): */
    /* IL_001a: ldarg.0  */
    stack0_0__ = this__;
    /* IL_001b: ldarg.2  */
    stack1_0__ = pTo;
    /* IL_001c: stfld WDM.Code.InterceptCDRomDevice.pTo */
    stack0_0__->pTo = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(17): */
    /* IL_0021: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0022: ldarg.3  */
    stack1_1__ = size;
    /* IL_0023: stfld WDM.Code.InterceptCDRomDevice.size */
    stack0_0__->size = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(18): */
    /* IL_0028: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// [3] WDM.Code.InterceptCDRomDevice.ReadCompleted(WDM.Code.InterceptCDRomDevice this__, System.IntPtr pBuffer, System.Int32 offset, System.Int32 size)

uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* this__, intptr_t pBuffer, int32_t offset, int32_t size)
{
    //-------------------
    // Local variables:

    intptr_t result;
    bool local1__;
    uint32_t local2__;

    //-------------------
    // Evaluation stacks:

    intptr_t stack0_0__;
    int32_t stack0_1__;
    System_String* stack0_2__ = NULL;
    int32_t stack1_0__;
    intptr_t stack1_1__;
    WDM_Code_InterceptCDRomDevice* stack1_2__ = NULL;
    WDM_Code_InterceptCDRomDevice* stack2_0__ = NULL;
    intptr_t stack2_1__;
    int32_t stack2_2__;
    WDM_Code_InterceptCDRomDevice* stack3_0__ = NULL;
    int32_t stack3_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pstack0_2__;
        WDM_Code_InterceptCDRomDevice** pstack1_2__;
        WDM_Code_InterceptCDRomDevice** pstack2_0__;
        WDM_Code_InterceptCDRomDevice** pstack3_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    __executionFrame__.pstack2_0__ = &stack2_0__;
    __executionFrame__.pstack3_0__ = &stack3_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(21): */
    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
    stack0_0__ = pBuffer;
    /* IL_0002: ldarg.2  */
    stack1_0__ = offset;
    /* IL_0003: call System.IntPtr.op_Addition */
    stack0_0__ = System_IntPtr_op_Addition(stack0_0__, stack1_0__);
    /* IL_0008: ldarg.3  */
    stack1_0__ = size;
    /* IL_0009: ldarg.0  */
    stack2_0__ = this__;
    /* IL_000a: ldfld WDM.Code.InterceptCDRomDevice.pFrom */
    stack2_1__ = stack2_0__->pFrom;
    /* IL_000f: ldarg.0  */
    stack3_0__ = this__;
    /* IL_0010: ldfld WDM.Code.InterceptCDRomDevice.size */
    stack3_1__ = stack3_0__->size;
    /* IL_0015: call WDM.Code.Wdm.memmem */
    stack0_0__ = WDM_Code_Wdm_memmem(stack0_0__, stack1_0__, stack2_1__, stack3_1__);
    /* IL_001a: stloc.0  */
    result = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(23): */
    /* IL_001b: ldloc.0  */
    stack0_0__ = result;
    /* IL_001c: ldsfld System.IntPtr.Zero */
    stack1_1__ = System_IntPtr_Zero;
    /* IL_0021: call System.IntPtr.op_Inequality */
    stack0_1__ = System_IntPtr_op_Inequality(stack0_0__, stack1_1__);
    /* IL_0026: stloc.1  */
    local1__ = (stack0_1__) ? true : false;
    /* IL_0027: ldloc.1  */
    stack0_1__ = local1__;
    /* IL_0028: brfalse.s IL_004a */
    if (stack0_1__ == 0) goto IL_004a;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(24): */
    /* IL_002a: nop  */
    /* IL_002b: ldstr "Draw BABEL!!
" */
    stack0_2__ = string1__;
    /* IL_0030: call WDM.Code.Wdm.DbgPrint */
    WDM_Code_Wdm_DbgPrint(stack0_2__);
    /* IL_0035: nop  */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(27): */
    /* IL_0036: ldloc.0  */
    stack0_0__ = result;
    /* IL_0037: ldarg.0  */
    stack1_2__ = this__;
    /* IL_0038: ldfld WDM.Code.InterceptCDRomDevice.pTo */
    stack1_1__ = stack1_2__->pTo;
    /* IL_003d: ldarg.0  */
    stack2_0__ = this__;
    /* IL_003e: ldfld WDM.Code.InterceptCDRomDevice.size */
    stack2_2__ = stack2_0__->size;
    /* IL_0043: call WDM.Code.Wdm.memcpy */
    WDM_Code_Wdm_memcpy(stack0_0__, stack1_1__, stack2_2__);
    /* IL_0048: nop  */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(28): */
    /* IL_0049: nop  */
IL_004a:
    /* IL_004a: ldc.i4.0  */
    stack0_1__ = 0;
    /* IL_004b: stloc.2  */
    local2__ = (uint32_t)(stack0_1__);
    /* IL_004c: br.s IL_004e */
    goto IL_004e;
IL_004e:
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(31): */
    /* IL_004e: ldloc.2  */
    stack0_1__ = local2__;
    /* IL_004f: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (uint32_t)(stack0_1__);
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(WDM_Code_InterceptCDRomDevice)) return this__;

    // [7-4] Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// [7-5] GC's mark handler
void __WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__(WDM_Code_InterceptCDRomDevice* this__)
{

    // [7-7] Delegate checking base types
    __System_Object_IL2C_MarkHandler__((System_Object*)this__);
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__ = {
    "WDM.Code.InterceptCDRomDevice",
    sizeof(WDM_Code_InterceptCDRomDevice),
    /* internalcall */ (IL2C_MARK_HANDLER)__WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of WDM.Code.InterceptCDRomDevice
__WDM_Code_InterceptCDRomDevice_VTABLE_DECL__ __WDM_Code_InterceptCDRomDevice_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
    __WDM_Code_InterceptCDRomDevice_ReadCompleted__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: WDM.Code.Wdm

///////////////////////////////////////
// [3] WDM.Code.Wdm.DbgPrint(System.String message)

void WDM_Code_Wdm_DbgPrint(System_String* message)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:


    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\Wdm.cs(10): */
    /* IL_0000: nop  */
    /* IL_0001: ret  */
    return;
}

///////////////////////////////////////
// [3] WDM.Code.Wdm.DbgPrint(System.UInt32 componentId, System.UInt32 level, System.String message)

void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:


    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\Wdm.cs(14): */
    /* IL_0000: nop  */
    /* IL_0001: ret  */
    return;
}

///////////////////////////////////////
// [6] P/Invoke: WDM.Code.Wdm.memmem(System.IntPtr p1, System.Int32 s1, System.IntPtr p2, System.Int32 s2)

intptr_t WDM_Code_Wdm_memmem(intptr_t p1, int32_t s1, intptr_t p2, int32_t s2)
{
    return __memmem(p1, s1, p2, s2);
}

///////////////////////////////////////
// [6] P/Invoke: WDM.Code.Wdm.memcpy(System.IntPtr pDest, System.IntPtr pSource, System.Int32 size)

void WDM_Code_Wdm_memcpy(intptr_t pDest, intptr_t pSource, int32_t size)
{
    __memcpy(pDest, pSource, size);
}

///////////////////////////////////////
// [3] WDM.Code.Wdm..ctor(WDM.Code.Wdm this__)

void WDM_Code_Wdm__ctor(WDM_Code_Wdm* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WDM_Code_Wdm* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        WDM_Code_Wdm** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    /* IL_0006: nop  */
    /* IL_0007: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __WDM_Code_Wdm_IL2C_RuntimeCast__(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(WDM_Code_Wdm)) return this__;

    // [7-4] Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// [7-5] GC's mark handler
void __WDM_Code_Wdm_IL2C_MarkHandler__(WDM_Code_Wdm* this__)
{

    // [7-7] Delegate checking base types
    __System_Object_IL2C_MarkHandler__((System_Object*)this__);
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __WDM_Code_Wdm_RUNTIME_TYPE__ = {
    "WDM.Code.Wdm",
    sizeof(WDM_Code_Wdm),
    /* internalcall */ (IL2C_MARK_HANDLER)__WDM_Code_Wdm_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of WDM.Code.Wdm
__WDM_Code_Wdm_VTABLE_DECL__ __WDM_Code_Wdm_VTABLE__ = {
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
