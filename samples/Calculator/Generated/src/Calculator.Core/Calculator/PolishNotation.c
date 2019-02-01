// [15-2] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>
#include <Calculator.Core_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: Calculator.PolishNotation

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.PolishNotation

///////////////////////////////////////
// [3] Calculator.PolishNotation.SkipWhiteSpace(System.String line, System.Int32 startIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_PolishNotation_SkipWhiteSpace_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    System_String* stack0_2__;
    System_String* stack1_0__;
} Calculator_PolishNotation_SkipWhiteSpace_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t index = 0;
    wchar_t ch = L'\x0000';
    bool local2__ = false;
    bool local3__ = false;
    int32_t local4__ = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_1__;
    wchar_t stack0_3__;
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_PolishNotation_SkipWhiteSpace_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(95) */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: stloc.0                         : PolishNotation.cs(96) */
    index = stack0_0__;
    /* IL_0003: br.s IL_002a                    : PolishNotation.cs(96) */
    goto IL_002a;
IL_0005:
    /* IL_0005: nop                             : PolishNotation.cs(98) */
    /* IL_0006: ldarg.0  */
    frame__.stack0_2__ = line;
    /* IL_0007: ldloc.0                         : PolishNotation.cs(99) */
    stack1_1__ = index;
    /* IL_0008: callvirt System.String.get_Chars : PolishNotation.cs(99) */
    stack0_3__ = System_String_get_Chars(frame__.stack0_2__, stack1_1__);
    /* IL_000d: stloc.1                         : PolishNotation.cs(99) */
    ch = stack0_3__;
    /* IL_000e: ldloc.1                         : PolishNotation.cs(100) */
    stack0_3__ = ch;
    /* IL_000f: ldc.i4.s 32                     : PolishNotation.cs(100) */
    stack1_1__ = 32;
    /* IL_0011: beq.s IL_001d                   : PolishNotation.cs(100) */
    if (stack0_3__ == stack1_1__) goto IL_001d;
    /* IL_0013: ldloc.1                         : PolishNotation.cs(100) */
    stack0_3__ = ch;
    /* IL_0014: ldc.i4.s 9                      : PolishNotation.cs(100) */
    stack1_1__ = 9;
    /* IL_0016: ceq                             : PolishNotation.cs(100) */
    stack0_0__ = (int32_t)stack0_3__ == (int32_t)stack1_1__;
    /* IL_0018: ldc.i4.0                        : PolishNotation.cs(100) */
    stack1_1__ = 0;
    /* IL_0019: ceq                             : PolishNotation.cs(100) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_001b: br.s IL_001e                    : PolishNotation.cs(100) */
    goto IL_001e;
IL_001d:
    /* IL_001d: ldc.i4.0                        : PolishNotation.cs(100) */
    stack0_0__ = 0;
IL_001e:
    /* IL_001e: stloc.2                         : PolishNotation.cs(100) */
    local2__ = (bool)stack0_0__;
    /* IL_001f: ldloc.2                         : PolishNotation.cs(100) */
    stack0_1__ = local2__;
    /* IL_0020: brfalse.s IL_0025               : PolishNotation.cs(100) */
    if (stack0_1__ == false) goto IL_0025;
    /* IL_0022: nop                             : PolishNotation.cs(101) */
    /* IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
    /* IL_0025: ldloc.0                         : PolishNotation.cs(104) */
    stack0_0__ = index;
    /* IL_0026: ldc.i4.1                        : PolishNotation.cs(104) */
    stack1_1__ = 1;
    /* IL_0027: add                             : PolishNotation.cs(104) */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0028: stloc.0                         : PolishNotation.cs(104) */
    index = stack0_0__;
    /* IL_0029: nop                             : PolishNotation.cs(105) */
IL_002a:
    /* IL_002a: ldloc.0  */
    stack0_0__ = index;
    /* IL_002b: ldarg.0                         : PolishNotation.cs(97) */
    frame__.stack1_0__ = line;
    /* IL_002c: callvirt System.String.get_Length : PolishNotation.cs(97) */
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0031: clt                             : PolishNotation.cs(97) */
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_0033: stloc.3                         : PolishNotation.cs(97) */
    local3__ = (bool)stack0_0__;
    /* IL_0034: ldloc.3                         : PolishNotation.cs(97) */
    stack0_1__ = local3__;
    /* IL_0035: brtrue.s IL_0005                : PolishNotation.cs(97) */
    if (stack0_1__ != false) goto IL_0005;
IL_0037:
    /* IL_0037: ldloc.0                         : PolishNotation.cs(107) */
    stack0_0__ = index;
    /* IL_0038: stloc.s local4__                : PolishNotation.cs(107) */
    local4__ = stack0_0__;
    /* IL_003a: br.s IL_003c                    : PolishNotation.cs(107) */
    goto IL_003c;
IL_003c:
    /* IL_003c: ldloc.s local4__                : PolishNotation.cs(108) */
    stack0_0__ = local4__;
    /* IL_003e: ret                             : PolishNotation.cs(108) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_0__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.ParseOperator(System.String line, System.Int32 startIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_PolishNotation_ParseOperator_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_OperatorNode* local3__;
    System_String* stack0_3__;
    Calculator_OperatorNode* stack0_5__;
    System_String* stack1_0__;
} Calculator_PolishNotation_ParseOperator_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t index = 0;
    wchar_t ch = L'\x0000';
    bool local2__ = false;
    bool local4__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_1__;
    untyped_ptr stack0_2__;
    wchar_t stack0_4__;
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_PolishNotation_ParseOperator_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(111) */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0                         : PolishNotation.cs(112) */
    frame__.stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length : PolishNotation.cs(112) */
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0008: clt                             : PolishNotation.cs(112) */
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_000a: ldc.i4.0                        : PolishNotation.cs(112) */
    stack1_1__ = 0;
    /* IL_000b: ceq                             : PolishNotation.cs(112) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_000d: stloc.2                         : PolishNotation.cs(112) */
    local2__ = (bool)stack0_0__;
    /* IL_000e: ldloc.2                         : PolishNotation.cs(112) */
    stack0_1__ = local2__;
    /* IL_000f: brfalse.s IL_0016               : PolishNotation.cs(112) */
    if (stack0_1__ == false) goto IL_0016;
    /* IL_0011: nop                             : PolishNotation.cs(113) */
    /* IL_0012: ldnull  */
    stack0_2__ = NULL;
    /* IL_0013: stloc.3                         : PolishNotation.cs(114) */
    frame__.local3__ = (Calculator_OperatorNode*)stack0_2__;
    /* IL_0014: br.s IL_005b                    : PolishNotation.cs(114) */
    goto IL_005b;
IL_0016:
    /* IL_0016: ldarg.1                         : PolishNotation.cs(117) */
    stack0_0__ = startIndex;
    /* IL_0017: stloc.0                         : PolishNotation.cs(117) */
    index = stack0_0__;
    /* IL_0018: ldarg.0                         : PolishNotation.cs(118) */
    frame__.stack0_3__ = line;
    /* IL_0019: ldloc.0                         : PolishNotation.cs(118) */
    stack1_1__ = index;
    /* IL_001a: callvirt System.String.get_Chars : PolishNotation.cs(118) */
    stack0_4__ = System_String_get_Chars(frame__.stack0_3__, stack1_1__);
    /* IL_001f: stloc.1                         : PolishNotation.cs(118) */
    ch = stack0_4__;
    /* IL_0020: ldloc.1                         : PolishNotation.cs(119) */
    stack0_4__ = ch;
    /* IL_0021: ldc.i4.s 43                     : PolishNotation.cs(119) */
    stack1_1__ = 43;
    /* IL_0023: beq.s IL_0039                   : PolishNotation.cs(119) */
    if (stack0_4__ == stack1_1__) goto IL_0039;
    /* IL_0025: ldloc.1                         : PolishNotation.cs(119) */
    stack0_4__ = ch;
    /* IL_0026: ldc.i4.s 45                     : PolishNotation.cs(119) */
    stack1_1__ = 45;
    /* IL_0028: beq.s IL_0039                   : PolishNotation.cs(119) */
    if (stack0_4__ == stack1_1__) goto IL_0039;
    /* IL_002a: ldloc.1                         : PolishNotation.cs(119) */
    stack0_4__ = ch;
    /* IL_002b: ldc.i4.s 42                     : PolishNotation.cs(119) */
    stack1_1__ = 42;
    /* IL_002d: beq.s IL_0039                   : PolishNotation.cs(119) */
    if (stack0_4__ == stack1_1__) goto IL_0039;
    /* IL_002f: ldloc.1                         : PolishNotation.cs(119) */
    stack0_4__ = ch;
    /* IL_0030: ldc.i4.s 47                     : PolishNotation.cs(119) */
    stack1_1__ = 47;
    /* IL_0032: ceq                             : PolishNotation.cs(119) */
    stack0_0__ = (int32_t)stack0_4__ == (int32_t)stack1_1__;
    /* IL_0034: ldc.i4.0                        : PolishNotation.cs(119) */
    stack1_1__ = 0;
    /* IL_0035: ceq                             : PolishNotation.cs(119) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_0037: br.s IL_003a                    : PolishNotation.cs(119) */
    goto IL_003a;
IL_0039:
    /* IL_0039: ldc.i4.0                        : PolishNotation.cs(119) */
    stack0_0__ = 0;
IL_003a:
    /* IL_003a: stloc.s local4__                : PolishNotation.cs(119) */
    local4__ = (bool)stack0_0__;
    /* IL_003c: ldloc.s local4__                : PolishNotation.cs(119) */
    stack0_1__ = local4__;
    /* IL_003e: brfalse.s IL_0045               : PolishNotation.cs(119) */
    if (stack0_1__ == false) goto IL_0045;
    /* IL_0040: nop                             : PolishNotation.cs(120) */
    /* IL_0041: ldnull  */
    stack0_2__ = NULL;
    /* IL_0042: stloc.3                         : PolishNotation.cs(121) */
    frame__.local3__ = (Calculator_OperatorNode*)stack0_2__;
    /* IL_0043: br.s IL_005b                    : PolishNotation.cs(121) */
    goto IL_005b;
IL_0045:
    /* IL_0045: ldloc.0                         : PolishNotation.cs(123) */
    stack0_0__ = index;
    /* IL_0046: ldc.i4.1                        : PolishNotation.cs(123) */
    stack1_1__ = 1;
    /* IL_0047: add                             : PolishNotation.cs(123) */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0048: stloc.0                         : PolishNotation.cs(123) */
    index = stack0_0__;
    /* IL_0049: ldarg.0                         : PolishNotation.cs(125) */
    frame__.stack0_3__ = line;
    /* IL_004a: ldloc.0                         : PolishNotation.cs(125) */
    stack1_1__ = index;
    /* IL_004b: call Calculator.PolishNotation.SkipWhiteSpace : PolishNotation.cs(125) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_3__, stack1_1__);
    /* IL_0050: stloc.0                         : PolishNotation.cs(125) */
    index = stack0_0__;
    /* IL_0051: ldloc.1                         : PolishNotation.cs(126) */
    stack0_4__ = ch;
    /* IL_0052: ldloc.0                         : PolishNotation.cs(126) */
    stack1_1__ = index;
    /* IL_0053: newobj Calculator.OperatorNode..ctor : PolishNotation.cs(126) */
    frame__.stack0_5__ = il2c_get_uninitialized_object(Calculator_OperatorNode);
    Calculator_OperatorNode__ctor(frame__.stack0_5__, stack0_4__, stack1_1__);
    /* IL_0058: stloc.3                         : PolishNotation.cs(126) */
    frame__.local3__ = frame__.stack0_5__;
    /* IL_0059: br.s IL_005b                    : PolishNotation.cs(126) */
    goto IL_005b;
IL_005b:
    /* IL_005b: ldloc.3                         : PolishNotation.cs(127) */
    frame__.stack0_5__ = frame__.local3__;
    /* IL_005c: ret                             : PolishNotation.cs(127) */
    il2c_unlink_execution_frame(&frame__);
    return frame__.stack0_5__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.ParseNumeric(System.String line, System.Int32 startIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_PolishNotation_ParseNumeric_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    System_String* token;
    Calculator_NumericNode* local4__;
    Calculator_NumericNode* stack0_3__;
    System_String* stack0_4__;
    System_String* stack1_0__;
} Calculator_PolishNotation_ParseNumeric_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t index = 0;
    int32_t numeric = 0;
    bool local3__ = false;
    wchar_t ch = L'\x0000';
    bool local6__ = false;
    bool local7__ = false;
    bool local8__ = false;
    bool local9__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_1__;
    untyped_ptr stack0_2__;
    wchar_t stack0_5__;
    int32_t stack1_1__;
    int32_t* stack1_2__;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_PolishNotation_ParseNumeric_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(130) */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0                         : PolishNotation.cs(131) */
    frame__.stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length : PolishNotation.cs(131) */
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0008: clt                             : PolishNotation.cs(131) */
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_000a: ldc.i4.0                        : PolishNotation.cs(131) */
    stack1_1__ = 0;
    /* IL_000b: ceq                             : PolishNotation.cs(131) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_000d: stloc.3                         : PolishNotation.cs(131) */
    local3__ = (bool)stack0_0__;
    /* IL_000e: ldloc.3                         : PolishNotation.cs(131) */
    stack0_1__ = local3__;
    /* IL_000f: brfalse.s IL_0017               : PolishNotation.cs(131) */
    if (stack0_1__ == false) goto IL_0017;
    /* IL_0011: nop                             : PolishNotation.cs(132) */
    /* IL_0012: ldnull  */
    stack0_2__ = NULL;
    /* IL_0013: stloc.s local4__                : PolishNotation.cs(133) */
    frame__.local4__ = (Calculator_NumericNode*)stack0_2__;
    /* IL_0015: br.s IL_008d                    : PolishNotation.cs(133) */
    goto IL_008d;
IL_0017:
    /* IL_0017: ldarg.1                         : PolishNotation.cs(136) */
    stack0_0__ = startIndex;
    /* IL_0018: stloc.0                         : PolishNotation.cs(136) */
    index = stack0_0__;
    /* IL_0019: br.s IL_0039                    : PolishNotation.cs(136) */
    goto IL_0039;
IL_001b:
    /* IL_001b: nop                             : PolishNotation.cs(138) */
    /* IL_001c: ldarg.0  */
    frame__.stack0_4__ = line;
    /* IL_001d: ldloc.0                         : PolishNotation.cs(139) */
    stack1_1__ = index;
    /* IL_001e: callvirt System.String.get_Chars : PolishNotation.cs(139) */
    stack0_5__ = System_String_get_Chars(frame__.stack0_4__, stack1_1__);
    /* IL_0023: stloc.s ch                      : PolishNotation.cs(139) */
    ch = stack0_5__;
    /* IL_0025: ldloc.s ch                      : PolishNotation.cs(140) */
    stack0_5__ = ch;
    /* IL_0027: ldc.i4.s 32                     : PolishNotation.cs(140) */
    stack1_1__ = 32;
    /* IL_0029: ceq                             : PolishNotation.cs(140) */
    stack0_0__ = (int32_t)stack0_5__ == (int32_t)stack1_1__;
    /* IL_002b: stloc.s local6__                : PolishNotation.cs(140) */
    local6__ = (bool)stack0_0__;
    /* IL_002d: ldloc.s local6__                : PolishNotation.cs(140) */
    stack0_1__ = local6__;
    /* IL_002f: brfalse.s IL_0034               : PolishNotation.cs(140) */
    if (stack0_1__ == false) goto IL_0034;
    /* IL_0031: nop                             : PolishNotation.cs(141) */
    /* IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
    /* IL_0034: ldloc.0                         : PolishNotation.cs(144) */
    stack0_0__ = index;
    /* IL_0035: ldc.i4.1                        : PolishNotation.cs(144) */
    stack1_1__ = 1;
    /* IL_0036: add                             : PolishNotation.cs(144) */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0037: stloc.0                         : PolishNotation.cs(144) */
    index = stack0_0__;
    /* IL_0038: nop                             : PolishNotation.cs(145) */
IL_0039:
    /* IL_0039: ldloc.0  */
    stack0_0__ = index;
    /* IL_003a: ldarg.0                         : PolishNotation.cs(137) */
    frame__.stack1_0__ = line;
    /* IL_003b: callvirt System.String.get_Length : PolishNotation.cs(137) */
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0040: clt                             : PolishNotation.cs(137) */
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_0042: stloc.s local7__                : PolishNotation.cs(137) */
    local7__ = (bool)stack0_0__;
    /* IL_0044: ldloc.s local7__                : PolishNotation.cs(137) */
    stack0_1__ = local7__;
    /* IL_0046: brtrue.s IL_001b                : PolishNotation.cs(137) */
    if (stack0_1__ != false) goto IL_001b;
IL_0048:
    /* IL_0048: ldloc.0                         : PolishNotation.cs(147) */
    stack0_0__ = index;
    /* IL_0049: ldarg.1                         : PolishNotation.cs(147) */
    stack1_1__ = startIndex;
    /* IL_004a: ceq                             : PolishNotation.cs(147) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_004c: stloc.s local8__                : PolishNotation.cs(147) */
    local8__ = (bool)stack0_0__;
    /* IL_004e: ldloc.s local8__                : PolishNotation.cs(147) */
    stack0_1__ = local8__;
    /* IL_0050: brfalse.s IL_0058               : PolishNotation.cs(147) */
    if (stack0_1__ == false) goto IL_0058;
    /* IL_0052: nop                             : PolishNotation.cs(148) */
    /* IL_0053: ldnull  */
    stack0_2__ = NULL;
    /* IL_0054: stloc.s local4__                : PolishNotation.cs(149) */
    frame__.local4__ = (Calculator_NumericNode*)stack0_2__;
    /* IL_0056: br.s IL_008d                    : PolishNotation.cs(149) */
    goto IL_008d;
IL_0058:
    /* IL_0058: ldarg.0                         : PolishNotation.cs(152) */
    frame__.stack0_4__ = line;
    /* IL_0059: ldarg.1                         : PolishNotation.cs(152) */
    stack1_1__ = startIndex;
    /* IL_005a: ldloc.0                         : PolishNotation.cs(152) */
    stack2_0__ = index;
    /* IL_005b: ldarg.1                         : PolishNotation.cs(152) */
    stack3_0__ = startIndex;
    /* IL_005c: sub                             : PolishNotation.cs(152) */
    stack2_0__ = stack2_0__ - stack3_0__;
    /* IL_005d: callvirt System.String.Substring : PolishNotation.cs(152) */
    frame__.stack0_4__ = System_String_Substring_1(frame__.stack0_4__, stack1_1__, stack2_0__);
    /* IL_0062: stloc.1                         : PolishNotation.cs(152) */
    frame__.token = frame__.stack0_4__;
    /* IL_0063: ldloc.1                         : PolishNotation.cs(153) */
    frame__.stack0_4__ = frame__.token;
    /* IL_0064: ldloca.s numeric                : PolishNotation.cs(153) */
    stack1_2__ = &numeric;
    /* IL_0066: call System.Int32.TryParse      : PolishNotation.cs(153) */
    stack0_1__ = System_Int32_TryParse(frame__.stack0_4__, stack1_2__);
    /* IL_006b: ldc.i4.0                        : PolishNotation.cs(153) */
    stack1_1__ = 0;
    /* IL_006c: ceq                             : PolishNotation.cs(153) */
    stack0_0__ = (int32_t)stack0_1__ == (int32_t)stack1_1__;
    /* IL_006e: stloc.s local9__                : PolishNotation.cs(153) */
    local9__ = (bool)stack0_0__;
    /* IL_0070: ldloc.s local9__                : PolishNotation.cs(153) */
    stack0_1__ = local9__;
    /* IL_0072: brfalse.s IL_007a               : PolishNotation.cs(153) */
    if (stack0_1__ == false) goto IL_007a;
    /* IL_0074: nop                             : PolishNotation.cs(154) */
    /* IL_0075: ldnull  */
    stack0_2__ = NULL;
    /* IL_0076: stloc.s local4__                : PolishNotation.cs(155) */
    frame__.local4__ = (Calculator_NumericNode*)stack0_2__;
    /* IL_0078: br.s IL_008d                    : PolishNotation.cs(155) */
    goto IL_008d;
IL_007a:
    /* IL_007a: ldarg.0                         : PolishNotation.cs(158) */
    frame__.stack0_4__ = line;
    /* IL_007b: ldloc.0                         : PolishNotation.cs(158) */
    stack1_1__ = index;
    /* IL_007c: call Calculator.PolishNotation.SkipWhiteSpace : PolishNotation.cs(158) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_4__, stack1_1__);
    /* IL_0081: stloc.0                         : PolishNotation.cs(158) */
    index = stack0_0__;
    /* IL_0082: ldloc.2                         : PolishNotation.cs(159) */
    stack0_0__ = numeric;
    /* IL_0083: ldloc.0                         : PolishNotation.cs(159) */
    stack1_1__ = index;
    /* IL_0084: newobj Calculator.NumericNode..ctor : PolishNotation.cs(159) */
    frame__.stack0_3__ = il2c_get_uninitialized_object(Calculator_NumericNode);
    Calculator_NumericNode__ctor(frame__.stack0_3__, stack0_0__, stack1_1__);
    /* IL_0089: stloc.s local4__                : PolishNotation.cs(159) */
    frame__.local4__ = frame__.stack0_3__;
    /* IL_008b: br.s IL_008d                    : PolishNotation.cs(159) */
    goto IL_008d;
IL_008d:
    /* IL_008d: ldloc.s local4__                : PolishNotation.cs(160) */
    frame__.stack0_3__ = frame__.local4__;
    /* IL_008f: ret                             : PolishNotation.cs(160) */
    il2c_unlink_execution_frame(&frame__);
    return frame__.stack0_3__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.ParseExpression(System.String line, System.Int32 startIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_PolishNotation_ParseExpression_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_OperatorNode* oper;
    Calculator_ReducibleNode* left;
    Calculator_ReducibleNode* right;
    Calculator_ExpressionNode* local5__;
    System_String* stack0_3__;
    Calculator_OperatorNode* stack0_4__;
    Calculator_ExpressionNode* stack0_5__;
    Calculator_NumericNode* stack0_6__;
    Calculator_ReducibleNode* stack0_7__;
    System_String* stack1_0__;
    Calculator_OperatorNode* stack1_3__;
    Calculator_ReducibleNode* stack1_4__;
    Calculator_ReducibleNode* stack2_0__;
} Calculator_PolishNotation_ParseExpression_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t index = 0;
    bool local4__ = false;
    bool local6__ = false;
    bool local7__ = false;
    bool local8__ = false;
    bool local9__ = false;
    bool local10__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_1__;
    untyped_ptr stack0_2__;
    int32_t stack1_1__;
    untyped_ptr stack1_2__;
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_PolishNotation_ParseExpression_EXECUTION_FRAME__ frame__ =
        { NULL, 13 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(163) */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0                         : PolishNotation.cs(164) */
    frame__.stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length : PolishNotation.cs(164) */
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0008: clt                             : PolishNotation.cs(164) */
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_000a: ldc.i4.0                        : PolishNotation.cs(164) */
    stack1_1__ = 0;
    /* IL_000b: ceq                             : PolishNotation.cs(164) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_000d: stloc.s local4__                : PolishNotation.cs(164) */
    local4__ = (bool)stack0_0__;
    /* IL_000f: ldloc.s local4__                : PolishNotation.cs(164) */
    stack0_1__ = local4__;
    /* IL_0011: brfalse.s IL_001c               : PolishNotation.cs(164) */
    if (stack0_1__ == false) goto IL_001c;
    /* IL_0013: nop                             : PolishNotation.cs(165) */
    /* IL_0014: ldnull  */
    stack0_2__ = NULL;
    /* IL_0015: stloc.s local5__                : PolishNotation.cs(166) */
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_0017: br IL_00bd                      : PolishNotation.cs(166) */
    goto IL_00bd;
IL_001c:
    /* IL_001c: ldarg.0                         : PolishNotation.cs(169) */
    frame__.stack0_3__ = line;
    /* IL_001d: ldarg.1                         : PolishNotation.cs(169) */
    stack1_1__ = startIndex;
    /* IL_001e: call Calculator.PolishNotation.ParseOperator : PolishNotation.cs(169) */
    frame__.stack0_4__ = Calculator_PolishNotation_ParseOperator(frame__.stack0_3__, stack1_1__);
    /* IL_0023: stloc.0                         : PolishNotation.cs(169) */
    frame__.oper = frame__.stack0_4__;
    /* IL_0024: ldloc.0                         : PolishNotation.cs(170) */
    frame__.stack0_4__ = frame__.oper;
    /* IL_0025: ldnull                          : PolishNotation.cs(170) */
    stack1_2__ = NULL;
    /* IL_0026: ceq                             : PolishNotation.cs(170) */
    stack0_0__ = (intptr_t)frame__.stack0_4__ == (intptr_t)stack1_2__;
    /* IL_0028: stloc.s local6__                : PolishNotation.cs(170) */
    local6__ = (bool)stack0_0__;
    /* IL_002a: ldloc.s local6__                : PolishNotation.cs(170) */
    stack0_1__ = local6__;
    /* IL_002c: brfalse.s IL_0037               : PolishNotation.cs(170) */
    if (stack0_1__ == false) goto IL_0037;
    /* IL_002e: nop                             : PolishNotation.cs(171) */
    /* IL_002f: ldnull  */
    stack0_2__ = NULL;
    /* IL_0030: stloc.s local5__                : PolishNotation.cs(172) */
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_0032: br IL_00bd                      : PolishNotation.cs(172) */
    goto IL_00bd;
IL_0037:
    /* IL_0037: ldarg.0                         : PolishNotation.cs(175) */
    frame__.stack0_3__ = line;
    /* IL_0038: ldloc.0                         : PolishNotation.cs(175) */
    frame__.stack1_3__ = frame__.oper;
    /* IL_0039: ldfld Calculator.AbstractNode.NextIndex : PolishNotation.cs(175) */
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_003e: call Calculator.PolishNotation.ParseNumeric : PolishNotation.cs(175) */
    frame__.stack0_6__ = Calculator_PolishNotation_ParseNumeric(frame__.stack0_3__, stack1_1__);
    /* IL_0043: stloc.1                         : PolishNotation.cs(175) */
    frame__.left = (Calculator_ReducibleNode*)frame__.stack0_6__;
    /* IL_0044: ldloc.1                         : PolishNotation.cs(176) */
    frame__.stack0_7__ = frame__.left;
    /* IL_0045: ldnull                          : PolishNotation.cs(176) */
    stack1_2__ = NULL;
    /* IL_0046: ceq                             : PolishNotation.cs(176) */
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_0048: stloc.s local7__                : PolishNotation.cs(176) */
    local7__ = (bool)stack0_0__;
    /* IL_004a: ldloc.s local7__                : PolishNotation.cs(176) */
    stack0_1__ = local7__;
    /* IL_004c: brfalse.s IL_006d               : PolishNotation.cs(176) */
    if (stack0_1__ == false) goto IL_006d;
    /* IL_004e: nop                             : PolishNotation.cs(177) */
    /* IL_004f: ldarg.0  */
    frame__.stack0_3__ = line;
    /* IL_0050: ldloc.0                         : PolishNotation.cs(178) */
    frame__.stack1_3__ = frame__.oper;
    /* IL_0051: ldfld Calculator.AbstractNode.NextIndex : PolishNotation.cs(178) */
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_0056: call Calculator.PolishNotation.ParseExpression : PolishNotation.cs(178) */
    frame__.stack0_5__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_3__, stack1_1__);
    /* IL_005b: stloc.1                         : PolishNotation.cs(178) */
    frame__.left = (Calculator_ReducibleNode*)frame__.stack0_5__;
    /* IL_005c: ldloc.1                         : PolishNotation.cs(179) */
    frame__.stack0_7__ = frame__.left;
    /* IL_005d: ldnull                          : PolishNotation.cs(179) */
    stack1_2__ = NULL;
    /* IL_005e: ceq                             : PolishNotation.cs(179) */
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_0060: stloc.s local8__                : PolishNotation.cs(179) */
    local8__ = (bool)stack0_0__;
    /* IL_0062: ldloc.s local8__                : PolishNotation.cs(179) */
    stack0_1__ = local8__;
    /* IL_0064: brfalse.s IL_006c               : PolishNotation.cs(179) */
    if (stack0_1__ == false) goto IL_006c;
    /* IL_0066: nop                             : PolishNotation.cs(180) */
    /* IL_0067: ldnull  */
    stack0_2__ = NULL;
    /* IL_0068: stloc.s local5__                : PolishNotation.cs(181) */
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_006a: br.s IL_00bd                    : PolishNotation.cs(181) */
    goto IL_00bd;
IL_006c:
    /* IL_006c: nop                             : PolishNotation.cs(183) */
IL_006d:
    /* IL_006d: ldarg.0  */
    frame__.stack0_3__ = line;
    /* IL_006e: ldloc.1                         : PolishNotation.cs(185) */
    frame__.stack1_4__ = frame__.left;
    /* IL_006f: ldfld Calculator.AbstractNode.NextIndex : PolishNotation.cs(185) */
    stack1_1__ = frame__.stack1_4__->NextIndex;
    /* IL_0074: call Calculator.PolishNotation.ParseNumeric : PolishNotation.cs(185) */
    frame__.stack0_6__ = Calculator_PolishNotation_ParseNumeric(frame__.stack0_3__, stack1_1__);
    /* IL_0079: stloc.2                         : PolishNotation.cs(185) */
    frame__.right = (Calculator_ReducibleNode*)frame__.stack0_6__;
    /* IL_007a: ldloc.2                         : PolishNotation.cs(186) */
    frame__.stack0_7__ = frame__.right;
    /* IL_007b: ldnull                          : PolishNotation.cs(186) */
    stack1_2__ = NULL;
    /* IL_007c: ceq                             : PolishNotation.cs(186) */
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_007e: stloc.s local9__                : PolishNotation.cs(186) */
    local9__ = (bool)stack0_0__;
    /* IL_0080: ldloc.s local9__                : PolishNotation.cs(186) */
    stack0_1__ = local9__;
    /* IL_0082: brfalse.s IL_00a3               : PolishNotation.cs(186) */
    if (stack0_1__ == false) goto IL_00a3;
    /* IL_0084: nop                             : PolishNotation.cs(187) */
    /* IL_0085: ldarg.0  */
    frame__.stack0_3__ = line;
    /* IL_0086: ldloc.1                         : PolishNotation.cs(188) */
    frame__.stack1_4__ = frame__.left;
    /* IL_0087: ldfld Calculator.AbstractNode.NextIndex : PolishNotation.cs(188) */
    stack1_1__ = frame__.stack1_4__->NextIndex;
    /* IL_008c: call Calculator.PolishNotation.ParseExpression : PolishNotation.cs(188) */
    frame__.stack0_5__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_3__, stack1_1__);
    /* IL_0091: stloc.2                         : PolishNotation.cs(188) */
    frame__.right = (Calculator_ReducibleNode*)frame__.stack0_5__;
    /* IL_0092: ldloc.2                         : PolishNotation.cs(189) */
    frame__.stack0_7__ = frame__.right;
    /* IL_0093: ldnull                          : PolishNotation.cs(189) */
    stack1_2__ = NULL;
    /* IL_0094: ceq                             : PolishNotation.cs(189) */
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_0096: stloc.s local10__               : PolishNotation.cs(189) */
    local10__ = (bool)stack0_0__;
    /* IL_0098: ldloc.s local10__               : PolishNotation.cs(189) */
    stack0_1__ = local10__;
    /* IL_009a: brfalse.s IL_00a2               : PolishNotation.cs(189) */
    if (stack0_1__ == false) goto IL_00a2;
    /* IL_009c: nop                             : PolishNotation.cs(190) */
    /* IL_009d: ldnull  */
    stack0_2__ = NULL;
    /* IL_009e: stloc.s local5__                : PolishNotation.cs(191) */
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_00a0: br.s IL_00bd                    : PolishNotation.cs(191) */
    goto IL_00bd;
IL_00a2:
    /* IL_00a2: nop                             : PolishNotation.cs(193) */
IL_00a3:
    /* IL_00a3: ldarg.0  */
    frame__.stack0_3__ = line;
    /* IL_00a4: ldloc.2                         : PolishNotation.cs(195) */
    frame__.stack1_4__ = frame__.right;
    /* IL_00a5: ldfld Calculator.AbstractNode.NextIndex : PolishNotation.cs(195) */
    stack1_1__ = frame__.stack1_4__->NextIndex;
    /* IL_00aa: call Calculator.PolishNotation.SkipWhiteSpace : PolishNotation.cs(195) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_3__, stack1_1__);
    /* IL_00af: stloc.3                         : PolishNotation.cs(195) */
    index = stack0_0__;
    /* IL_00b0: ldloc.0                         : PolishNotation.cs(196) */
    frame__.stack0_4__ = frame__.oper;
    /* IL_00b1: ldloc.1                         : PolishNotation.cs(196) */
    frame__.stack1_4__ = frame__.left;
    /* IL_00b2: ldloc.2                         : PolishNotation.cs(196) */
    frame__.stack2_0__ = frame__.right;
    /* IL_00b3: ldloc.3                         : PolishNotation.cs(196) */
    stack3_0__ = index;
    /* IL_00b4: newobj Calculator.ExpressionNode..ctor : PolishNotation.cs(196) */
    frame__.stack0_5__ = il2c_get_uninitialized_object(Calculator_ExpressionNode);
    Calculator_ExpressionNode__ctor(frame__.stack0_5__, frame__.stack0_4__, frame__.stack1_4__, frame__.stack2_0__, stack3_0__);
    /* IL_00b9: stloc.s local5__                : PolishNotation.cs(196) */
    frame__.local5__ = frame__.stack0_5__;
    /* IL_00bb: br.s IL_00bd                    : PolishNotation.cs(196) */
    goto IL_00bd;
IL_00bd:
    /* IL_00bd: ldloc.s local5__                : PolishNotation.cs(197) */
    frame__.stack0_5__ = frame__.local5__;
    /* IL_00bf: ret                             : PolishNotation.cs(197) */
    il2c_unlink_execution_frame(&frame__);
    return frame__.stack0_5__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.Main()

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_PolishNotation_Main_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    System_String* line;
    Calculator_ExpressionNode* expr;
    System_String* stack0_0__;
    Calculator_ExpressionNode* stack0_3__;
    System_String* stack1_1__;
} Calculator_PolishNotation_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_PolishNotation_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    bool local1__ = false;
    int32_t result = 0;
    bool local4__ = false;
    bool local5__ = false;
    bool local6__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    bool stack0_2__;
    int32_t stack1_0__;
    untyped_ptr stack1_2__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_PolishNotation_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(203) */
    /* IL_0001: ldstr "Polish notation calculator." */
    frame__.stack0_0__ = Calculator_Core_string0__;
    /* IL_0006: call System.Console.WriteLine   : PolishNotation.cs(204) */
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_000b: nop                             : PolishNotation.cs(204) */
    /* IL_000c: ldstr "This is proof of concept for IL2C." */
    frame__.stack0_0__ = Calculator_Core_string1__;
    /* IL_0011: call System.Console.WriteLine   : PolishNotation.cs(205) */
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0016: nop                             : PolishNotation.cs(205) */
    /* IL_0017: ldstr "https://github.com/kekyo/IL2C" */
    frame__.stack0_0__ = Calculator_Core_string2__;
    /* IL_001c: call System.Console.WriteLine   : PolishNotation.cs(206) */
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0021: nop                             : PolishNotation.cs(206) */
    /* IL_0022: call System.Console.WriteLine */
    System_Console_WriteLine();
    /* IL_0027: nop                             : PolishNotation.cs(207) */
    /* IL_0028: ldstr "Type "exit" to exit." */
    frame__.stack0_0__ = Calculator_Core_string3__;
    /* IL_002d: call System.Console.WriteLine   : PolishNotation.cs(208) */
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0032: nop                             : PolishNotation.cs(208) */
    /* IL_0033: br.s IL_00aa */
    goto IL_00aa;
IL_0035:
    /* IL_0035: nop                             : PolishNotation.cs(211) */
    /* IL_0036: call System.Console.WriteLine */
    System_Console_WriteLine();
    /* IL_003b: nop                             : PolishNotation.cs(212) */
    /* IL_003c: ldstr "PN> " */
    frame__.stack0_0__ = Calculator_Core_string4__;
    /* IL_0041: call System.Console.Write       : PolishNotation.cs(213) */
    System_Console_Write_9(frame__.stack0_0__);
    /* IL_0046: nop                             : PolishNotation.cs(213) */
    /* IL_0047: call System.Console.ReadLine */
    frame__.stack0_0__ = System_Console_ReadLine();
    /* IL_004c: stloc.0                         : PolishNotation.cs(214) */
    frame__.line = frame__.stack0_0__;
    /* IL_004d: ldloc.0                         : PolishNotation.cs(215) */
    frame__.stack0_0__ = frame__.line;
    /* IL_004e: call System.String.IsNullOrWhiteSpace : PolishNotation.cs(215) */
    stack0_2__ = System_String_IsNullOrWhiteSpace(frame__.stack0_0__);
    /* IL_0053: ldc.i4.0                        : PolishNotation.cs(215) */
    stack1_0__ = 0;
    /* IL_0054: ceq                             : PolishNotation.cs(215) */
    stack0_1__ = (int32_t)stack0_2__ == (int32_t)stack1_0__;
    /* IL_0056: stloc.1                         : PolishNotation.cs(215) */
    local1__ = (bool)stack0_1__;
    /* IL_0057: ldloc.1                         : PolishNotation.cs(215) */
    stack0_2__ = local1__;
    /* IL_0058: brfalse.s IL_00a9               : PolishNotation.cs(215) */
    if (stack0_2__ == false) goto IL_00a9;
    /* IL_005a: nop                             : PolishNotation.cs(216) */
    /* IL_005b: ldloc.0  */
    frame__.stack0_0__ = frame__.line;
    /* IL_005c: ldstr "exit"                    : PolishNotation.cs(217) */
    frame__.stack1_1__ = Calculator_Core_string5__;
    /* IL_0061: call System.String.op_Equality  : PolishNotation.cs(217) */
    stack0_2__ = System_String_op_Equality(frame__.stack0_0__, frame__.stack1_1__);
    /* IL_0066: stloc.s local4__                : PolishNotation.cs(217) */
    local4__ = stack0_2__;
    /* IL_0068: ldloc.s local4__                : PolishNotation.cs(217) */
    stack0_2__ = local4__;
    /* IL_006a: brfalse.s IL_006f               : PolishNotation.cs(217) */
    if (stack0_2__ == false) goto IL_006f;
    /* IL_006c: nop                             : PolishNotation.cs(218) */
    /* IL_006d: br.s IL_00af */
    goto IL_00af;
IL_006f:
    /* IL_006f: ldloc.0                         : PolishNotation.cs(222) */
    frame__.stack0_0__ = frame__.line;
    /* IL_0070: ldc.i4.0                        : PolishNotation.cs(222) */
    stack1_0__ = 0;
    /* IL_0071: call Calculator.PolishNotation.ParseExpression : PolishNotation.cs(222) */
    frame__.stack0_3__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_0__, stack1_0__);
    /* IL_0076: stloc.2                         : PolishNotation.cs(222) */
    frame__.expr = frame__.stack0_3__;
    /* IL_0077: ldloc.2                         : PolishNotation.cs(223) */
    frame__.stack0_3__ = frame__.expr;
    /* IL_0078: ldnull                          : PolishNotation.cs(223) */
    stack1_2__ = NULL;
    /* IL_0079: ceq                             : PolishNotation.cs(223) */
    stack0_1__ = (intptr_t)frame__.stack0_3__ == (intptr_t)stack1_2__;
    /* IL_007b: stloc.s local5__                : PolishNotation.cs(223) */
    local5__ = (bool)stack0_1__;
    /* IL_007d: ldloc.s local5__                : PolishNotation.cs(223) */
    stack0_2__ = local5__;
    /* IL_007f: brfalse.s IL_008f               : PolishNotation.cs(223) */
    if (stack0_2__ == false) goto IL_008f;
    /* IL_0081: nop                             : PolishNotation.cs(224) */
    /* IL_0082: ldstr "Syntax error." */
    frame__.stack0_0__ = Calculator_Core_string6__;
    /* IL_0087: call System.Console.WriteLine   : PolishNotation.cs(225) */
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_008c: nop                             : PolishNotation.cs(225) */
    /* IL_008d: br.s IL_00aa */
    goto IL_00aa;
IL_008f:
    /* IL_008f: ldloc.2                         : PolishNotation.cs(229) */
    frame__.stack0_3__ = frame__.expr;
    /* IL_0090: callvirt Calculator.ReducibleNode.Reduce : PolishNotation.cs(229) */
    stack0_1__ = frame__.stack0_3__->vptr0__->Reduce((Calculator_ReducibleNode*)frame__.stack0_3__);
    /* IL_0095: stloc.3                         : PolishNotation.cs(229) */
    result = stack0_1__;
    /* IL_0096: ldstr "Reuslt="                 : PolishNotation.cs(231) */
    frame__.stack0_0__ = Calculator_Core_string7__;
    /* IL_009b: call System.Console.Write       : PolishNotation.cs(231) */
    System_Console_Write_9(frame__.stack0_0__);
    /* IL_00a0: nop                             : PolishNotation.cs(231) */
    /* IL_00a1: ldloc.3  */
    stack0_1__ = result;
    /* IL_00a2: call System.Console.WriteLine   : PolishNotation.cs(232) */
    System_Console_WriteLine_6(stack0_1__);
    /* IL_00a7: nop                             : PolishNotation.cs(232) */
    /* IL_00a8: nop  */
IL_00a9:
    /* IL_00a9: nop  */
IL_00aa:
    /* IL_00aa: ldc.i4.1  */
    stack0_1__ = 1;
    /* IL_00ab: stloc.s local6__                : PolishNotation.cs(210) */
    local6__ = (bool)stack0_1__;
    /* IL_00ad: br.s IL_0035                    : PolishNotation.cs(210) */
    goto IL_0035;
IL_00af:
    /* IL_00af: ret                             : PolishNotation.cs(241) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation..ctor(Calculator.PolishNotation this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_PolishNotation__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_PolishNotation* stack0_0__;
} Calculator_PolishNotation__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_PolishNotation__ctor(Calculator_PolishNotation* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_PolishNotation__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(Calculator_PolishNotation, "Calculator.PolishNotation", IL2C_TYPE_REFERENCE, sizeof(Calculator_PolishNotation), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
