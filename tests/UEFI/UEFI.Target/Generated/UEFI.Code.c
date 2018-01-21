#include "UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, L"PN> ");

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
// Type: UEFI.Code.OperatorResult

//////////////////////
// Runtime helpers:

static void __UEFI_Code_OperatorResult_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_ValueType)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __UEFI_Code_OperatorResult_RUNTIME_TYPE_DEF__ = {
    "UEFI.Code.OperatorResult",
    sizeof(UEFI_Code_OperatorResult),
    __UEFI_Code_OperatorResult_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __UEFI_Code_OperatorResult_RUNTIME_TYPE__ = &__UEFI_Code_OperatorResult_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// .ctor

void UEFI_Code_OperatorResult__ctor(UEFI_Code_OperatorResult* __this, wchar_t oper, int32_t index)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_OperatorResult* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorResult** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 15 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = (int32_t)(oper);
    /* Path=1, Unique=0: IL_0003: stfld System.Char UEFI.Code.OperatorResult::Operator */
    __stack0_0->Operator = (wchar_t)__stack1_0;
#line 17 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = index;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 UEFI.Code.OperatorResult::Index */
    __stack0_0->Index = __stack1_0;
#line 18 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

////////////////////////////////////////////////////////////
// Type: UEFI.Code.NumericResult

//////////////////////
// Runtime helpers:

static void __UEFI_Code_NumericResult_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_ValueType)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __UEFI_Code_NumericResult_RUNTIME_TYPE_DEF__ = {
    "UEFI.Code.NumericResult",
    sizeof(UEFI_Code_NumericResult),
    __UEFI_Code_NumericResult_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __UEFI_Code_NumericResult_RUNTIME_TYPE__ = &__UEFI_Code_NumericResult_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// .ctor

void UEFI_Code_NumericResult__ctor(UEFI_Code_NumericResult* __this, int32_t numeric, int32_t index)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_NumericResult* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericResult** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 27 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = numeric;
    /* Path=1, Unique=0: IL_0003: stfld System.Int32 UEFI.Code.NumericResult::Numeric */
    __stack0_0->Numeric = __stack1_0;
#line 29 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = index;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 UEFI.Code.NumericResult::Index */
    __stack0_0->Index = __stack1_0;
#line 30 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

////////////////////////////////////////////////////////////
// Type: UEFI.Code.PolishNotation

//////////////////////
// Runtime helpers:

static void __UEFI_Code_PolishNotation_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __UEFI_Code_PolishNotation_RUNTIME_TYPE_DEF__ = {
    "UEFI.Code.PolishNotation",
    0,
    __UEFI_Code_PolishNotation_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __UEFI_Code_PolishNotation_RUNTIME_TYPE__ = &__UEFI_Code_PolishNotation_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// SkipWhiteSpace

int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    wchar_t local1;
    bool local2;
    bool local3;
    int32_t local4;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    int32_t __stack0_2;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** p__stack0_1;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 36 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
#line 39 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    __stack0_1 = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_2 = System_String_get_Chars(__stack0_1, __stack1_2);
    /* Path=3, Unique=0: IL_000d: stloc.1 */
    local1 = (wchar_t)__stack0_2;
#line 41 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_000e: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_000f: ldc.i4.s 32 */
    __stack1_2 = 32;
    /* Path=3, Unique=0: IL_0011: beq.s IL_001d */
    if (__stack0_0 == __stack1_2) goto IL_001d;
    /* Path=3, Unique=0: IL_0013: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0014: ldc.i4.s 9 */
    __stack1_2 = 9;
    /* Path=3, Unique=0: IL_0016: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=3, Unique=0: IL_0018: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=3, Unique=0: IL_0019: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=3, Unique=0: IL_001b: br.s IL_001e */
    goto IL_001e;
IL_001d:
    /* Path=5, Unique=0: IL_001d: ldc.i4.0 */
    __stack0_0 = 0;
IL_001e:
    /* Path=5, Unique=0: IL_001e: stloc.2 */
    local2 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_001f: ldloc.2 */
    __stack0_0 = local2;
    /* Path=5, Unique=0: IL_0020: brfalse.s IL_0025 */
    if (__stack0_0 == 0) goto IL_0025;
#line 42 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0022: nop */
    /* Path=5, Unique=0: IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
#line 45 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_0025: ldloc.0 */
    __stack0_0 = local0;
    /* Path=6, Unique=0: IL_0026: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=6, Unique=0: IL_0027: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=6, Unique=0: IL_0028: stloc.0 */
    local0 = __stack0_0;
#line 46 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_0029: nop */
IL_002a:
    /* Path=2, Unique=0: IL_002a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    __stack1_0 = line;
    /* Path=2, Unique=0: IL_002c: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=2, Unique=0: IL_0031: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=2, Unique=0: IL_0033: stloc.3 */
    local3 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_0034: ldloc.3 */
    __stack0_0 = local3;
    /* Path=2, Unique=0: IL_0035: brtrue.s IL_0005 */
    if (__stack0_0 != 0) goto IL_0005;
IL_0037:
#line 48 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0037: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0038: stloc.s local4 */
    local4 = __stack0_0;
    /* Path=2, Unique=0: IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
#line 49 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=4, Unique=0: IL_003e: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// ParseOperator

UEFI_Code_OperatorResult UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    wchar_t local1;
    UEFI_Code_OperatorResult local2;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    int32_t __stack0_2;
    UEFI_Code_OperatorResult __stack0_3;
    int32_t __stack1_0;
    int32_t __stack2_0;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 52 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
#line 54 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0003: ldarg.0 */
    __stack0_1 = line;
    /* Path=1, Unique=0: IL_0004: ldloc.0 */
    __stack1_0 = local0;
    /* Path=1, Unique=0: IL_0005: dup */
    __stack2_0 = __stack1_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4.1 */
    __stack3_0 = 1;
    /* Path=1, Unique=0: IL_0007: add */
    __stack2_0 = __stack2_0 + __stack3_0;
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    local0 = __stack2_0;
    /* Path=1, Unique=0: IL_0009: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_2 = System_String_get_Chars(__stack0_1, __stack1_0);
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    local1 = (wchar_t)__stack0_2;
#line 56 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: ldarg.0 */
    __stack0_1 = line;
    /* Path=1, Unique=0: IL_0010: ldloc.0 */
    __stack1_0 = local0;
    /* Path=1, Unique=0: IL_0011: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_1, __stack1_0);
    /* Path=1, Unique=0: IL_0016: stloc.0 */
    local0 = __stack0_0;
#line 57 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0017: ldloc.1 */
    __stack0_0 = local1;
    /* Path=1, Unique=0: IL_0018: ldloc.0 */
    __stack1_0 = local0;
    /* Path=1, Unique=0: IL_0019: newobj System.Void UEFI.Code.OperatorResult::.ctor(System.Char,System.Int32) */
    memset(&__stack0_3, 0x00, sizeof(UEFI_Code_OperatorResult));
    UEFI_Code_OperatorResult__ctor(&__stack0_3, (wchar_t)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_001e: stloc.2 */
    local2 = __stack0_3;
    /* Path=1, Unique=0: IL_001f: br.s IL_0021 */
    goto IL_0021;
IL_0021:
#line 58 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0021: ldloc.2 */
    __stack0_3 = local2;
    /* Path=2, Unique=0: IL_0022: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// ParseNumeric

UEFI_Code_NumericResult UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    System_String* local1 = NULL;
    int32_t local2;
    wchar_t local3;
    bool local4;
    bool local5;
    UEFI_Code_NumericResult local6;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    System_String* __stack0_2 = NULL;
    UEFI_Code_NumericResult __stack0_3;
    int32_t __stack0_4;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;
    int32_t __stack2_0;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal1;
        System_String** p__stack0_1;
        System_String** p__stack0_2;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 61 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0003: br.s IL_0029 */
    goto IL_0029;
IL_0005:
#line 64 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    __stack0_1 = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_4 = System_String_get_Chars(__stack0_1, __stack1_2);
    /* Path=3, Unique=0: IL_000d: stloc.3 */
    local3 = (wchar_t)__stack0_4;
#line 66 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_000e: ldloc.3 */
    __stack0_0 = local3;
    /* Path=3, Unique=0: IL_000f: ldc.i4.s 48 */
    __stack1_2 = 48;
    /* Path=3, Unique=0: IL_0011: blt.s IL_001a */
    if (__stack0_0 < __stack1_2) goto IL_001a;
    /* Path=3, Unique=0: IL_0013: ldloc.3 */
    __stack0_0 = local3;
    /* Path=3, Unique=0: IL_0014: ldc.i4.s 57 */
    __stack1_2 = 57;
    /* Path=3, Unique=0: IL_0016: cgt */
    __stack0_0 = (__stack0_0 > __stack1_2) ? 1 : 0;
    /* Path=3, Unique=0: IL_0018: br.s IL_001b */
    goto IL_001b;
IL_001a:
    /* Path=5, Unique=0: IL_001a: ldc.i4.1 */
    __stack0_0 = 1;
IL_001b:
    /* Path=5, Unique=0: IL_001b: stloc.s local4 */
    local4 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_001d: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=5, Unique=0: IL_001f: brfalse.s IL_0024 */
    if (__stack0_0 == 0) goto IL_0024;
#line 67 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0021: nop */
    /* Path=5, Unique=0: IL_0022: br.s IL_0038 */
    goto IL_0038;
IL_0024:
#line 70 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_0024: ldloc.0 */
    __stack0_0 = local0;
    /* Path=6, Unique=0: IL_0025: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=6, Unique=0: IL_0026: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=6, Unique=0: IL_0027: stloc.0 */
    local0 = __stack0_0;
#line 71 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_0028: nop */
IL_0029:
    /* Path=2, Unique=0: IL_0029: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_002a: ldarg.0 */
    __stack1_0 = line;
    /* Path=2, Unique=0: IL_002b: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=2, Unique=0: IL_0030: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=2, Unique=0: IL_0032: stloc.s local5 */
    local5 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_0034: ldloc.s local5 */
    __stack0_0 = local5;
    /* Path=2, Unique=0: IL_0036: brtrue.s IL_0005 */
    if (__stack0_0 != 0) goto IL_0005;
IL_0038:
#line 73 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0038: ldarg.0 */
    __stack0_1 = line;
    /* Path=2, Unique=0: IL_0039: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=2, Unique=0: IL_003a: ldloc.0 */
    __stack2_0 = local0;
    /* Path=2, Unique=0: IL_003b: ldarg.1 */
    __stack3_0 = startIndex;
    /* Path=2, Unique=0: IL_003c: sub */
    __stack2_0 = __stack2_0 - __stack3_0;
    /* Path=2, Unique=0: IL_003d: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    __stack0_2 = System_String_Substring_1(__stack0_1, __stack1_2, __stack2_0);
    /* Path=2, Unique=0: IL_0042: stloc.1 */
    local1 = __stack0_2;
#line 74 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0043: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_0044: call System.Int32 System.Int32::Parse(System.String) */
    __stack0_0 = System_Int32_Parse(__stack0_1);
    /* Path=2, Unique=0: IL_0049: stloc.2 */
    local2 = __stack0_0;
#line 76 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_004a: ldarg.0 */
    __stack0_1 = line;
    /* Path=2, Unique=0: IL_004b: ldloc.0 */
    __stack1_2 = local0;
    /* Path=2, Unique=0: IL_004c: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_1, __stack1_2);
    /* Path=2, Unique=0: IL_0051: stloc.0 */
    local0 = __stack0_0;
#line 77 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0052: ldloc.2 */
    __stack0_0 = local2;
    /* Path=2, Unique=0: IL_0053: ldloc.0 */
    __stack1_2 = local0;
    /* Path=2, Unique=0: IL_0054: newobj System.Void UEFI.Code.NumericResult::.ctor(System.Int32,System.Int32) */
    memset(&__stack0_3, 0x00, sizeof(UEFI_Code_NumericResult));
    UEFI_Code_NumericResult__ctor(&__stack0_3, __stack0_0, __stack1_2);
    /* Path=2, Unique=0: IL_0059: stloc.s local6 */
    local6 = __stack0_3;
    /* Path=2, Unique=0: IL_005b: br.s IL_005d */
    goto IL_005d;
IL_005d:
#line 78 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_005d: ldloc.s local6 */
    __stack0_3 = local6;
    /* Path=4, Unique=0: IL_005f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// Main

void UEFI_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    bool local1;
    UEFI_Code_OperatorResult local2;
    bool local3;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    UEFI_Code_OperatorResult __stack0_2;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 81 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: br.s IL_002d */
    goto IL_002d;
IL_0003:
#line 83 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0003: nop */
    /* Path=3, Unique=0: IL_0004: ldstr "PN> " */
    __stack0_1 = __string0;
    /* Path=3, Unique=0: IL_0009: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_1);
    /* Path=3, Unique=0: IL_000e: nop */
#line 85 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_000f: call System.String System.Console::ReadLine() */
    __stack0_1 = System_Console_ReadLine();
    /* Path=3, Unique=0: IL_0014: stloc.0 */
    local0 = __stack0_1;
#line 86 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0015: ldloc.0 */
    __stack0_1 = local0;
    /* Path=3, Unique=0: IL_0016: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    __stack0_0 = System_String_IsNullOrWhiteSpace(__stack0_1);
    /* Path=3, Unique=0: IL_001b: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=3, Unique=0: IL_001c: ceq */
    __stack0_0 = (__stack0_0 == __stack1_0) ? 1 : 0;
    /* Path=3, Unique=0: IL_001e: stloc.1 */
    local1 = __stack0_0 ? true : false;
    /* Path=3, Unique=0: IL_001f: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0020: brfalse.s IL_002c */
    if (__stack0_0 == 0) goto IL_002c;
#line 87 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0022: nop */
    /* Path=3, Unique=0: IL_0023: ldloc.0 */
    __stack0_1 = local0;
    /* Path=3, Unique=0: IL_0024: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=3, Unique=0: IL_0025: call UEFI.Code.OperatorResult UEFI.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    __stack0_2 = UEFI_Code_PolishNotation_ParseOperator(__stack0_1, __stack1_0);
    /* Path=3, Unique=0: IL_002a: stloc.2 */
    local2 = __stack0_2;
#line 89 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002b: nop */
IL_002c:
    /* Path=3, Unique=0: IL_002c: nop */
IL_002d:
    /* Path=2, Unique=0: IL_002d: ldc.i4.1 */
    __stack0_0 = 1;
    /* Path=2, Unique=0: IL_002e: stloc.3 */
    local3 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_002f: br.s IL_0003 */
    goto IL_0003;
}

///////////////////////////////////////
// .ctor

void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_PolishNotation* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_PolishNotation** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}
