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

#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t ch = L'\x0000';
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local2__ = false;
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local3__ = false;
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t local4__ = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_1__;
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_3__;
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_SkipWhiteSpace_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
#line 95 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0002: stloc.0  */
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0003: br.s IL_002a */
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_002a;
IL_0005:
    /* IL_0005: nop  */
    /* IL_0006: ldarg.0  */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_0007: ldloc.0  */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0008: callvirt System.String.get_Chars */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = System_String_get_Chars(frame__.stack0_2__, stack1_1__);
    /* IL_000d: stloc.1  */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    ch = stack0_3__;
    /* IL_000e: ldloc.1  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_000f: ldc.i4.s 32 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 32;
    /* IL_0011: beq.s IL_001d */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_3__ == stack1_1__) goto IL_001d;
    /* IL_0013: ldloc.1  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_0014: ldc.i4.s 9 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 9;
    /* IL_0016: ceq  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_3__ == (int32_t)stack1_1__;
    /* IL_0018: ldc.i4.0  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_0019: ceq  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_001b: br.s IL_001e */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_001e;
IL_001d:
    /* IL_001d: ldc.i4.0  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = 0;
IL_001e:
    /* IL_001e: stloc.2  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local2__ = (bool)stack0_0__;
    /* IL_001f: ldloc.2  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local2__;
    /* IL_0020: brfalse.s IL_0025 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0025;
    /* IL_0022: nop  */
    /* IL_0023: br.s IL_0037 */
#line 102 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_0037;
IL_0025:
    /* IL_0025: ldloc.0  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0026: ldc.i4.1  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 1;
    /* IL_0027: add  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0028: stloc.0  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0029: nop  */
IL_002a:
    /* IL_002a: ldloc.0  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_002b: ldarg.0  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_002c: callvirt System.String.get_Length */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0031: clt  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_0033: stloc.3  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local3__ = (bool)stack0_0__;
    /* IL_0034: ldloc.3  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local3__;
    /* IL_0035: brtrue.s IL_0005 */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ != false) goto IL_0005;
IL_0037:
    /* IL_0037: ldloc.0  */
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0038: stloc.s local4__ */
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local4__ = stack0_0__;
    /* IL_003a: br.s IL_003c */
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_003c;
IL_003c:
    /* IL_003c: ldloc.s local4__ */
#line 108 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = local4__;
    /* IL_003e: ret  */
#line 108 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 108 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return stack0_0__;
#line 108 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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

#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t ch = L'\x0000';
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local2__ = false;
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local4__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_1__;
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack0_2__;
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_4__;
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_ParseOperator_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
#line 111 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0008: clt  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_000a: ldc.i4.0  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_000b: ceq  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_000d: stloc.2  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local2__ = (bool)stack0_0__;
    /* IL_000e: ldloc.2  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local2__;
    /* IL_000f: brfalse.s IL_0016 */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0016;
    /* IL_0011: nop  */
    /* IL_0012: ldnull  */
#line 114 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0013: stloc.3  */
#line 114 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local3__ = (Calculator_OperatorNode*)stack0_2__;
    /* IL_0014: br.s IL_005b */
#line 114 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_005b;
IL_0016:
    /* IL_0016: ldarg.1  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0017: stloc.0  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0018: ldarg.0  */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_0019: ldloc.0  */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_001a: callvirt System.String.get_Chars */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = System_String_get_Chars(frame__.stack0_3__, stack1_1__);
    /* IL_001f: stloc.1  */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    ch = stack0_4__;
    /* IL_0020: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = ch;
    /* IL_0021: ldc.i4.s 43 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 43;
    /* IL_0023: beq.s IL_0039 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ == stack1_1__) goto IL_0039;
    /* IL_0025: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = ch;
    /* IL_0026: ldc.i4.s 45 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 45;
    /* IL_0028: beq.s IL_0039 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ == stack1_1__) goto IL_0039;
    /* IL_002a: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = ch;
    /* IL_002b: ldc.i4.s 42 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 42;
    /* IL_002d: beq.s IL_0039 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ == stack1_1__) goto IL_0039;
    /* IL_002f: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = ch;
    /* IL_0030: ldc.i4.s 47 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 47;
    /* IL_0032: ceq  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_4__ == (int32_t)stack1_1__;
    /* IL_0034: ldc.i4.0  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_0035: ceq  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_0037: br.s IL_003a */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_003a;
IL_0039:
    /* IL_0039: ldc.i4.0  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = 0;
IL_003a:
    /* IL_003a: stloc.s local4__ */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local4__ = (bool)stack0_0__;
    /* IL_003c: ldloc.s local4__ */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local4__;
    /* IL_003e: brfalse.s IL_0045 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0045;
    /* IL_0040: nop  */
    /* IL_0041: ldnull  */
#line 121 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0042: stloc.3  */
#line 121 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local3__ = (Calculator_OperatorNode*)stack0_2__;
    /* IL_0043: br.s IL_005b */
#line 121 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_005b;
IL_0045:
    /* IL_0045: ldloc.0  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0046: ldc.i4.1  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 1;
    /* IL_0047: add  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0048: stloc.0  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0049: ldarg.0  */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_004a: ldloc.0  */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_004b: call Calculator.PolishNotation.SkipWhiteSpace */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_3__, stack1_1__);
    /* IL_0050: stloc.0  */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0051: ldloc.1  */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = ch;
    /* IL_0052: ldloc.0  */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0053: newobj Calculator.OperatorNode..ctor */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = il2c_get_uninitialized_object(Calculator_OperatorNode);
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_OperatorNode__ctor(frame__.stack0_5__, stack0_4__, stack1_1__);
    /* IL_0058: stloc.3  */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local3__ = frame__.stack0_5__;
    /* IL_0059: br.s IL_005b */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_005b;
IL_005b:
    /* IL_005b: ldloc.3  */
#line 127 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = frame__.local3__;
    /* IL_005c: ret  */
#line 127 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 127 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return frame__.stack0_5__;
#line 127 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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

#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t numeric = 0;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local3__ = false;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t ch = L'\x0000';
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local6__ = false;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local7__ = false;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local8__ = false;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local9__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_1__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack0_2__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_5__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t* stack1_2__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack2_0__;
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_ParseNumeric_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
#line 130 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0008: clt  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_000a: ldc.i4.0  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_000b: ceq  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_000d: stloc.3  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local3__ = (bool)stack0_0__;
    /* IL_000e: ldloc.3  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local3__;
    /* IL_000f: brfalse.s IL_0017 */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0017;
    /* IL_0011: nop  */
    /* IL_0012: ldnull  */
#line 133 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0013: stloc.s local4__ */
#line 133 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local4__ = (Calculator_NumericNode*)stack0_2__;
    /* IL_0015: br.s IL_008d */
#line 133 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_008d;
IL_0017:
    /* IL_0017: ldarg.1  */
#line 136 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0018: stloc.0  */
#line 136 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0019: br.s IL_0039 */
#line 136 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_0039;
IL_001b:
    /* IL_001b: nop  */
    /* IL_001c: ldarg.0  */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = line;
    /* IL_001d: ldloc.0  */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_001e: callvirt System.String.get_Chars */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_5__ = System_String_get_Chars(frame__.stack0_4__, stack1_1__);
    /* IL_0023: stloc.s ch */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    ch = stack0_5__;
    /* IL_0025: ldloc.s ch */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_5__ = ch;
    /* IL_0027: ldc.i4.s 32 */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 32;
    /* IL_0029: ceq  */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_5__ == (int32_t)stack1_1__;
    /* IL_002b: stloc.s local6__ */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local6__ = (bool)stack0_0__;
    /* IL_002d: ldloc.s local6__ */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local6__;
    /* IL_002f: brfalse.s IL_0034 */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0034;
    /* IL_0031: nop  */
    /* IL_0032: br.s IL_0048 */
#line 142 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_0048;
IL_0034:
    /* IL_0034: ldloc.0  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0035: ldc.i4.1  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 1;
    /* IL_0036: add  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0037: stloc.0  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0038: nop  */
IL_0039:
    /* IL_0039: ldloc.0  */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_003a: ldarg.0  */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_003b: callvirt System.String.get_Length */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0040: clt  */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_0042: stloc.s local7__ */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local7__ = (bool)stack0_0__;
    /* IL_0044: ldloc.s local7__ */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local7__;
    /* IL_0046: brtrue.s IL_001b */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ != false) goto IL_001b;
IL_0048:
    /* IL_0048: ldloc.0  */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0049: ldarg.1  */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = startIndex;
    /* IL_004a: ceq  */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_004c: stloc.s local8__ */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local8__ = (bool)stack0_0__;
    /* IL_004e: ldloc.s local8__ */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local8__;
    /* IL_0050: brfalse.s IL_0058 */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0058;
    /* IL_0052: nop  */
    /* IL_0053: ldnull  */
#line 149 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0054: stloc.s local4__ */
#line 149 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local4__ = (Calculator_NumericNode*)stack0_2__;
    /* IL_0056: br.s IL_008d */
#line 149 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_008d;
IL_0058:
    /* IL_0058: ldarg.0  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = line;
    /* IL_0059: ldarg.1  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = startIndex;
    /* IL_005a: ldloc.0  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack2_0__ = index;
    /* IL_005b: ldarg.1  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack3_0__ = startIndex;
    /* IL_005c: sub  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack2_0__ = stack2_0__ - stack3_0__;
    /* IL_005d: callvirt System.String.Substring */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = System_String_Substring_1(frame__.stack0_4__, stack1_1__, stack2_0__);
    /* IL_0062: stloc.1  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.token = frame__.stack0_4__;
    /* IL_0063: ldloc.1  */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = frame__.token;
    /* IL_0064: ldloca.s numeric */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = &numeric;
    /* IL_0066: call System.Int32.TryParse */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = System_Int32_TryParse(frame__.stack0_4__, stack1_2__);
    /* IL_006b: ldc.i4.0  */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_006c: ceq  */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_1__ == (int32_t)stack1_1__;
    /* IL_006e: stloc.s local9__ */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local9__ = (bool)stack0_0__;
    /* IL_0070: ldloc.s local9__ */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local9__;
    /* IL_0072: brfalse.s IL_007a */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_007a;
    /* IL_0074: nop  */
    /* IL_0075: ldnull  */
#line 155 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0076: stloc.s local4__ */
#line 155 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local4__ = (Calculator_NumericNode*)stack0_2__;
    /* IL_0078: br.s IL_008d */
#line 155 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_008d;
IL_007a:
    /* IL_007a: ldarg.0  */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = line;
    /* IL_007b: ldloc.0  */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_007c: call Calculator.PolishNotation.SkipWhiteSpace */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_4__, stack1_1__);
    /* IL_0081: stloc.0  */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0082: ldloc.2  */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = numeric;
    /* IL_0083: ldloc.0  */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0084: newobj Calculator.NumericNode..ctor */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = il2c_get_uninitialized_object(Calculator_NumericNode);
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_NumericNode__ctor(frame__.stack0_3__, stack0_0__, stack1_1__);
    /* IL_0089: stloc.s local4__ */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local4__ = frame__.stack0_3__;
    /* IL_008b: br.s IL_008d */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_008d;
IL_008d:
    /* IL_008d: ldloc.s local4__ */
#line 160 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.local4__;
    /* IL_008f: ret  */
#line 160 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 160 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return frame__.stack0_3__;
#line 160 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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

#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local4__ = false;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local6__ = false;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local7__ = false;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local8__ = false;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local9__ = false;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local10__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_1__;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack0_2__;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack1_2__;
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_ParseExpression_EXECUTION_FRAME__ frame__ =
        { NULL, 13 };
#line 163 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0008: clt  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ < (int32_t)stack1_1__;
    /* IL_000a: ldc.i4.0  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_000b: ceq  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_000d: stloc.s local4__ */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local4__ = (bool)stack0_0__;
    /* IL_000f: ldloc.s local4__ */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local4__;
    /* IL_0011: brfalse.s IL_001c */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_001c;
    /* IL_0013: nop  */
    /* IL_0014: ldnull  */
#line 166 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0015: stloc.s local5__ */
#line 166 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_0017: br IL_00bd */
#line 166 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00bd;
IL_001c:
    /* IL_001c: ldarg.0  */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_001d: ldarg.1  */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = startIndex;
    /* IL_001e: call Calculator.PolishNotation.ParseOperator */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = Calculator_PolishNotation_ParseOperator(frame__.stack0_3__, stack1_1__);
    /* IL_0023: stloc.0  */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.oper = frame__.stack0_4__;
    /* IL_0024: ldloc.0  */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = frame__.oper;
    /* IL_0025: ldnull  */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = NULL;
    /* IL_0026: ceq  */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (intptr_t)frame__.stack0_4__ == (intptr_t)stack1_2__;
    /* IL_0028: stloc.s local6__ */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local6__ = (bool)stack0_0__;
    /* IL_002a: ldloc.s local6__ */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local6__;
    /* IL_002c: brfalse.s IL_0037 */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0037;
    /* IL_002e: nop  */
    /* IL_002f: ldnull  */
#line 172 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0030: stloc.s local5__ */
#line 172 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_0032: br IL_00bd */
#line 172 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00bd;
IL_0037:
    /* IL_0037: ldarg.0  */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_0038: ldloc.0  */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_3__ = frame__.oper;
    /* IL_0039: ldfld Calculator.AbstractNode.NextIndex */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_003e: call Calculator.PolishNotation.ParseNumeric */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_6__ = Calculator_PolishNotation_ParseNumeric(frame__.stack0_3__, stack1_1__);
    /* IL_0043: stloc.1  */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.left = (Calculator_ReducibleNode*)frame__.stack0_6__;
    /* IL_0044: ldloc.1  */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_7__ = frame__.left;
    /* IL_0045: ldnull  */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = NULL;
    /* IL_0046: ceq  */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_0048: stloc.s local7__ */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local7__ = (bool)stack0_0__;
    /* IL_004a: ldloc.s local7__ */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local7__;
    /* IL_004c: brfalse.s IL_006d */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_006d;
    /* IL_004e: nop  */
    /* IL_004f: ldarg.0  */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_0050: ldloc.0  */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_3__ = frame__.oper;
    /* IL_0051: ldfld Calculator.AbstractNode.NextIndex */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_0056: call Calculator.PolishNotation.ParseExpression */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_3__, stack1_1__);
    /* IL_005b: stloc.1  */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.left = (Calculator_ReducibleNode*)frame__.stack0_5__;
    /* IL_005c: ldloc.1  */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_7__ = frame__.left;
    /* IL_005d: ldnull  */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = NULL;
    /* IL_005e: ceq  */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_0060: stloc.s local8__ */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local8__ = (bool)stack0_0__;
    /* IL_0062: ldloc.s local8__ */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local8__;
    /* IL_0064: brfalse.s IL_006c */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_006c;
    /* IL_0066: nop  */
    /* IL_0067: ldnull  */
#line 181 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_0068: stloc.s local5__ */
#line 181 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_006a: br.s IL_00bd */
#line 181 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00bd;
IL_006c:
    /* IL_006c: nop  */
IL_006d:
    /* IL_006d: ldarg.0  */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_006e: ldloc.1  */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_4__ = frame__.left;
    /* IL_006f: ldfld Calculator.AbstractNode.NextIndex */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_4__->NextIndex;
    /* IL_0074: call Calculator.PolishNotation.ParseNumeric */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_6__ = Calculator_PolishNotation_ParseNumeric(frame__.stack0_3__, stack1_1__);
    /* IL_0079: stloc.2  */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.right = (Calculator_ReducibleNode*)frame__.stack0_6__;
    /* IL_007a: ldloc.2  */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_7__ = frame__.right;
    /* IL_007b: ldnull  */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = NULL;
    /* IL_007c: ceq  */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_007e: stloc.s local9__ */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local9__ = (bool)stack0_0__;
    /* IL_0080: ldloc.s local9__ */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local9__;
    /* IL_0082: brfalse.s IL_00a3 */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_00a3;
    /* IL_0084: nop  */
    /* IL_0085: ldarg.0  */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_0086: ldloc.1  */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_4__ = frame__.left;
    /* IL_0087: ldfld Calculator.AbstractNode.NextIndex */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_4__->NextIndex;
    /* IL_008c: call Calculator.PolishNotation.ParseExpression */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_3__, stack1_1__);
    /* IL_0091: stloc.2  */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.right = (Calculator_ReducibleNode*)frame__.stack0_5__;
    /* IL_0092: ldloc.2  */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_7__ = frame__.right;
    /* IL_0093: ldnull  */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = NULL;
    /* IL_0094: ceq  */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = (intptr_t)frame__.stack0_7__ == (intptr_t)stack1_2__;
    /* IL_0096: stloc.s local10__ */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local10__ = (bool)stack0_0__;
    /* IL_0098: ldloc.s local10__ */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = local10__;
    /* IL_009a: brfalse.s IL_00a2 */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_00a2;
    /* IL_009c: nop  */
    /* IL_009d: ldnull  */
#line 191 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = NULL;
    /* IL_009e: stloc.s local5__ */
#line 191 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local5__ = (Calculator_ExpressionNode*)stack0_2__;
    /* IL_00a0: br.s IL_00bd */
#line 191 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00bd;
IL_00a2:
    /* IL_00a2: nop  */
IL_00a3:
    /* IL_00a3: ldarg.0  */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = line;
    /* IL_00a4: ldloc.2  */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_4__ = frame__.right;
    /* IL_00a5: ldfld Calculator.AbstractNode.NextIndex */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_4__->NextIndex;
    /* IL_00aa: call Calculator.PolishNotation.SkipWhiteSpace */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_3__, stack1_1__);
    /* IL_00af: stloc.3  */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_00b0: ldloc.0  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = frame__.oper;
    /* IL_00b1: ldloc.1  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_4__ = frame__.left;
    /* IL_00b2: ldloc.2  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack2_0__ = frame__.right;
    /* IL_00b3: ldloc.3  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack3_0__ = index;
    /* IL_00b4: newobj Calculator.ExpressionNode..ctor */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = il2c_get_uninitialized_object(Calculator_ExpressionNode);
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_ExpressionNode__ctor(frame__.stack0_5__, frame__.stack0_4__, frame__.stack1_4__, frame__.stack2_0__, stack3_0__);
    /* IL_00b9: stloc.s local5__ */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.local5__ = frame__.stack0_5__;
    /* IL_00bb: br.s IL_00bd */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00bd;
IL_00bd:
    /* IL_00bd: ldloc.s local5__ */
#line 197 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = frame__.local5__;
    /* IL_00bf: ret  */
#line 197 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 197 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return frame__.stack0_5__;
#line 197 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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

#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local1__ = false;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t result = 0;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local4__ = false;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local5__ = false;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool local6__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_1__;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_2__;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_0__;
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack1_2__;

    //-------------------
    // [3-5] Setup execution frame:

#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
#line 200 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldstr "Polish notation calculator." */
#line 201 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string0__;
    /* IL_0006: call System.Console.WriteLine */
#line 201 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_000b: nop  */
    /* IL_000c: ldstr "This is proof of concept for IL2C." */
#line 202 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string1__;
    /* IL_0011: call System.Console.WriteLine */
#line 202 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0016: nop  */
    /* IL_0017: ldstr "https://github.com/kekyo/IL2C" */
#line 203 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string2__;
    /* IL_001c: call System.Console.WriteLine */
#line 203 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0021: nop  */
    /* IL_0022: call System.Console.WriteLine */
#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine();
    /* IL_0027: nop  */
    /* IL_0028: ldstr "Type "exit" to exit." */
#line 205 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string3__;
    /* IL_002d: call System.Console.WriteLine */
#line 205 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0032: nop  */
    /* IL_0033: ldstr "Example: "+ 2 3"" */
#line 206 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string4__;
    /* IL_0038: call System.Console.WriteLine */
#line 206 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_003d: nop  */
    /* IL_003e: ldstr "Example: "* + 2 3 6"" */
#line 207 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string5__;
    /* IL_0043: call System.Console.WriteLine */
#line 207 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0048: nop  */
    /* IL_0049: br.s IL_00c0 */
#line 207 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00c0;
IL_004b:
    /* IL_004b: nop  */
    /* IL_004c: call System.Console.WriteLine */
#line 211 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine();
    /* IL_0051: nop  */
    /* IL_0052: ldstr "PN> " */
#line 212 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string6__;
    /* IL_0057: call System.Console.Write */
#line 212 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_Write_9(frame__.stack0_0__);
    /* IL_005c: nop  */
    /* IL_005d: call System.Console.ReadLine */
#line 213 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = System_Console_ReadLine();
    /* IL_0062: stloc.0  */
#line 213 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.line = frame__.stack0_0__;
    /* IL_0063: ldloc.0  */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = frame__.line;
    /* IL_0064: call System.String.IsNullOrWhiteSpace */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = System_String_IsNullOrWhiteSpace(frame__.stack0_0__);
    /* IL_0069: ldc.i4.0  */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = 0;
    /* IL_006a: ceq  */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = (int32_t)stack0_2__ == (int32_t)stack1_0__;
    /* IL_006c: stloc.1  */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local1__ = (bool)stack0_1__;
    /* IL_006d: ldloc.1  */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = local1__;
    /* IL_006e: brfalse.s IL_00bf */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_2__ == false) goto IL_00bf;
    /* IL_0070: nop  */
    /* IL_0071: ldloc.0  */
#line 216 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = frame__.line;
    /* IL_0072: ldstr "exit" */
#line 216 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_1__ = Calculator_Core_string7__;
    /* IL_0077: call System.String.op_Equality */
#line 216 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = System_String_op_Equality(frame__.stack0_0__, frame__.stack1_1__);
    /* IL_007c: stloc.s local4__ */
#line 216 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local4__ = stack0_2__;
    /* IL_007e: ldloc.s local4__ */
#line 216 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = local4__;
    /* IL_0080: brfalse.s IL_0085 */
#line 216 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_2__ == false) goto IL_0085;
    /* IL_0082: nop  */
    /* IL_0083: br.s IL_00c5 */
#line 218 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00c5;
IL_0085:
    /* IL_0085: ldloc.0  */
#line 221 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = frame__.line;
    /* IL_0086: ldc.i4.0  */
#line 221 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = 0;
    /* IL_0087: call Calculator.PolishNotation.ParseExpression */
#line 221 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_0__, stack1_0__);
    /* IL_008c: stloc.2  */
#line 221 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.expr = frame__.stack0_3__;
    /* IL_008d: ldloc.2  */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.expr;
    /* IL_008e: ldnull  */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = NULL;
    /* IL_008f: ceq  */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = (intptr_t)frame__.stack0_3__ == (intptr_t)stack1_2__;
    /* IL_0091: stloc.s local5__ */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local5__ = (bool)stack0_1__;
    /* IL_0093: ldloc.s local5__ */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = local5__;
    /* IL_0095: brfalse.s IL_00a5 */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_2__ == false) goto IL_00a5;
    /* IL_0097: nop  */
    /* IL_0098: ldstr "Syntax error." */
#line 224 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string8__;
    /* IL_009d: call System.Console.WriteLine */
#line 224 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_00a2: nop  */
    /* IL_00a3: br.s IL_00c0 */
#line 225 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_00c0;
IL_00a5:
    /* IL_00a5: ldloc.2  */
#line 228 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.expr;
    /* IL_00a6: callvirt Calculator.ReducibleNode.Reduce */
#line 228 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = frame__.stack0_3__->vptr0__->Reduce((Calculator_ReducibleNode*)frame__.stack0_3__);
    /* IL_00ab: stloc.3  */
#line 228 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    result = stack0_1__;
    /* IL_00ac: ldstr "Reuslt=" */
#line 230 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string9__;
    /* IL_00b1: call System.Console.Write */
#line 230 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_Write_9(frame__.stack0_0__);
    /* IL_00b6: nop  */
    /* IL_00b7: ldloc.3  */
#line 231 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = result;
    /* IL_00b8: call System.Console.WriteLine */
#line 231 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_6(stack0_1__);
    /* IL_00bd: nop  */
    /* IL_00be: nop  */
IL_00bf:
    /* IL_00bf: nop  */
IL_00c0:
    /* IL_00c0: ldc.i4.1  */
#line 209 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = 1;
    /* IL_00c1: stloc.s local6__ */
#line 209 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    local6__ = (bool)stack0_1__;
    /* IL_00c3: br.s IL_004b */
#line 209 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_004b;
IL_00c5:
    /* IL_00c5: ret  */
#line 234 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 234 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return;
#line 234 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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
