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
    System_String* stack0_1__;
    System_String* stack1_0__;
} Calculator_PolishNotation_SkipWhiteSpace_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t ch = L'\x0000';

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_2__;
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_SkipWhiteSpace_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.1  */
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0001: stloc.0  */
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0002: br.s IL_001a */
#line 96 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_001a;
IL_0004:
    /* IL_0004: ldarg.0  */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_1__ = line;
    /* IL_0005: ldloc.0  */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0006: callvirt System.String.get_Chars */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = System_String_get_Chars(frame__.stack0_1__, stack1_1__);
    /* IL_000b: stloc.1  */
#line 99 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    ch = stack0_2__;
    /* IL_000c: ldloc.1  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = ch;
    /* IL_000d: ldc.i4.s 32 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 32;
    /* IL_000f: beq.s IL_0016 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_2__ == stack1_1__) goto IL_0016;
    /* IL_0011: ldloc.1  */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = ch;
    /* IL_0012: ldc.i4.s 9 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 9;
    /* IL_0014: bne.un.s IL_0023 */
#line 100 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_2__ != stack1_1__) goto IL_0023;
IL_0016:
    /* IL_0016: ldloc.0  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0017: ldc.i4.1  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 1;
    /* IL_0018: add  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0019: stloc.0  */
#line 104 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
IL_001a:
    /* IL_001a: ldloc.0  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_001b: ldarg.0  */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_001c: callvirt System.String.get_Length */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0021: blt.s IL_0004 */
#line 97 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_0__ < stack1_1__) goto IL_0004;
IL_0023:
    /* IL_0023: ldloc.0  */
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0024: ret  */
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return stack0_0__;
#line 107 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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
    System_String* stack0_2__;
    Calculator_OperatorNode* stack0_4__;
    System_String* stack1_0__;
} Calculator_PolishNotation_ParseOperator_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t ch = L'\x0000';

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack0_1__;
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_3__;
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_ParseOperator_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.1  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0001: ldarg.0  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0002: callvirt System.String.get_Length */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0007: blt.s IL_000b */
#line 112 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_0__ < stack1_1__) goto IL_000b;
    /* IL_0009: ldnull  */
#line 114 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_000a: ret  */
#line 114 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 114 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_OperatorNode*)stack0_1__;
IL_000b:
    /* IL_000b: ldarg.1  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_000c: stloc.0  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_000d: ldarg.0  */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_000e: ldloc.0  */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_000f: callvirt System.String.get_Chars */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = System_String_get_Chars(frame__.stack0_2__, stack1_1__);
    /* IL_0014: stloc.1  */
#line 118 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    ch = stack0_3__;
    /* IL_0015: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_0016: ldc.i4.s 43 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 43;
    /* IL_0018: beq.s IL_002b */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_3__ == stack1_1__) goto IL_002b;
    /* IL_001a: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_001b: ldc.i4.s 45 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 45;
    /* IL_001d: beq.s IL_002b */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_3__ == stack1_1__) goto IL_002b;
    /* IL_001f: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_0020: ldc.i4.s 42 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 42;
    /* IL_0022: beq.s IL_002b */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_3__ == stack1_1__) goto IL_002b;
    /* IL_0024: ldloc.1  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_0025: ldc.i4.s 47 */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 47;
    /* IL_0027: beq.s IL_002b */
#line 119 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_3__ == stack1_1__) goto IL_002b;
    /* IL_0029: ldnull  */
#line 121 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_002a: ret  */
#line 121 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 121 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_OperatorNode*)stack0_1__;
IL_002b:
    /* IL_002b: ldloc.0  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_002c: ldc.i4.1  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 1;
    /* IL_002d: add  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_002e: stloc.0  */
#line 123 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_002f: ldarg.0  */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_0030: ldloc.0  */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0031: call Calculator.PolishNotation.SkipWhiteSpace */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_2__, stack1_1__);
    /* IL_0036: stloc.0  */
#line 125 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0037: ldloc.1  */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = ch;
    /* IL_0038: ldloc.0  */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0039: newobj Calculator.OperatorNode..ctor */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = il2c_get_uninitialized_object(Calculator_OperatorNode);
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_OperatorNode__ctor(frame__.stack0_4__, stack0_3__, stack1_1__);
    /* IL_003e: ret  */
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return frame__.stack0_4__;
#line 126 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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
    System_String* stack0_2__;
    Calculator_NumericNode* stack0_5__;
    System_String* stack1_0__;
} Calculator_PolishNotation_ParseNumeric_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t numeric = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack0_1__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_3__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_4__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t* stack1_2__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack2_0__;
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_ParseNumeric_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.1  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0001: ldarg.0  */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0002: callvirt System.String.get_Length */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0007: blt.s IL_000b */
#line 131 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_0__ < stack1_1__) goto IL_000b;
    /* IL_0009: ldnull  */
#line 133 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_000a: ret  */
#line 133 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 133 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_NumericNode*)stack0_1__;
IL_000b:
    /* IL_000b: ldarg.1  */
#line 136 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_000c: stloc.0  */
#line 136 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_000d: br.s IL_001e */
#line 136 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_001e;
IL_000f:
    /* IL_000f: ldarg.0  */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_0010: ldloc.0  */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0011: callvirt System.String.get_Chars */
#line 139 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = System_String_get_Chars(frame__.stack0_2__, stack1_1__);
    /* IL_0016: ldc.i4.s 32 */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 32;
    /* IL_0018: beq.s IL_0027 */
#line 140 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_3__ == stack1_1__) goto IL_0027;
    /* IL_001a: ldloc.0  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_001b: ldc.i4.1  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 1;
    /* IL_001c: add  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_001d: stloc.0  */
#line 144 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
IL_001e:
    /* IL_001e: ldloc.0  */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_001f: ldarg.0  */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0020: callvirt System.String.get_Length */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0025: blt.s IL_000f */
#line 137 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_0__ < stack1_1__) goto IL_000f;
IL_0027:
    /* IL_0027: ldloc.0  */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = index;
    /* IL_0028: ldarg.1  */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = startIndex;
    /* IL_0029: bne.un.s IL_002d */
#line 147 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_0__ != stack1_1__) goto IL_002d;
    /* IL_002b: ldnull  */
#line 149 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_002c: ret  */
#line 149 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 149 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_NumericNode*)stack0_1__;
IL_002d:
    /* IL_002d: ldarg.0  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_002e: ldarg.1  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = startIndex;
    /* IL_002f: ldloc.0  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack2_0__ = index;
    /* IL_0030: ldarg.1  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack3_0__ = startIndex;
    /* IL_0031: sub  */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack2_0__ = stack2_0__ - stack3_0__;
    /* IL_0032: callvirt System.String.Substring */
#line 152 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = System_String_Substring_1(frame__.stack0_2__, stack1_1__, stack2_0__);
    /* IL_0037: ldloca.s numeric */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_2__ = &numeric;
    /* IL_0039: call System.Int32.TryParse */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = System_Int32_TryParse(frame__.stack0_2__, stack1_2__);
    /* IL_003e: brtrue.s IL_0042 */
#line 153 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ != false) goto IL_0042;
    /* IL_0040: ldnull  */
#line 155 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_0041: ret  */
#line 155 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 155 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_NumericNode*)stack0_1__;
IL_0042:
    /* IL_0042: ldarg.0  */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_0043: ldloc.0  */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_0044: call Calculator.PolishNotation.SkipWhiteSpace */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_2__, stack1_1__);
    /* IL_0049: stloc.0  */
#line 158 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_004a: ldloc.1  */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = numeric;
    /* IL_004b: ldloc.0  */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = index;
    /* IL_004c: newobj Calculator.NumericNode..ctor */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = il2c_get_uninitialized_object(Calculator_NumericNode);
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_NumericNode__ctor(frame__.stack0_5__, stack0_0__, stack1_1__);
    /* IL_0051: ret  */
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return frame__.stack0_5__;
#line 159 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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
    System_String* stack0_2__;
    Calculator_OperatorNode* stack0_3__;
    Calculator_NumericNode* stack0_4__;
    Calculator_ReducibleNode* stack0_5__;
    Calculator_ExpressionNode* stack0_6__;
    System_String* stack1_0__;
    Calculator_OperatorNode* stack1_2__;
    Calculator_ReducibleNode* stack1_3__;
    Calculator_ReducibleNode* stack2_0__;
} Calculator_PolishNotation_ParseExpression_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t index = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_0__;
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    untyped_ptr stack0_1__;
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_ParseExpression_EXECUTION_FRAME__ frame__ =
        { NULL, 12 };
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.1  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = startIndex;
    /* IL_0001: ldarg.0  */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = line;
    /* IL_0002: callvirt System.String.get_Length */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = System_String_get_Length(frame__.stack1_0__);
    /* IL_0007: blt.s IL_000b */
#line 164 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_0__ < stack1_1__) goto IL_000b;
    /* IL_0009: ldnull  */
#line 166 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_000a: ret  */
#line 166 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 166 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_ExpressionNode*)stack0_1__;
IL_000b:
    /* IL_000b: ldarg.0  */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_000c: ldarg.1  */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = startIndex;
    /* IL_000d: call Calculator.PolishNotation.ParseOperator */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = Calculator_PolishNotation_ParseOperator(frame__.stack0_2__, stack1_1__);
    /* IL_0012: stloc.0  */
#line 169 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.oper = frame__.stack0_3__;
    /* IL_0013: ldloc.0  */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.oper;
    /* IL_0014: brtrue.s IL_0018 */
#line 170 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (frame__.stack0_3__ != NULL) goto IL_0018;
    /* IL_0016: ldnull  */
#line 172 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_0017: ret  */
#line 172 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 172 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_ExpressionNode*)stack0_1__;
IL_0018:
    /* IL_0018: ldarg.0  */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_0019: ldloc.0  */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_2__ = frame__.oper;
    /* IL_001a: ldfld Calculator.AbstractNode.NextIndex */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_2__->NextIndex;
    /* IL_001f: call Calculator.PolishNotation.ParseNumeric */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = Calculator_PolishNotation_ParseNumeric(frame__.stack0_2__, stack1_1__);
    /* IL_0024: stloc.1  */
#line 175 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.left = (Calculator_ReducibleNode*)frame__.stack0_4__;
    /* IL_0025: ldloc.1  */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = frame__.left;
    /* IL_0026: brtrue.s IL_003a */
#line 176 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (frame__.stack0_5__ != NULL) goto IL_003a;
    /* IL_0028: ldarg.0  */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_0029: ldloc.0  */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_2__ = frame__.oper;
    /* IL_002a: ldfld Calculator.AbstractNode.NextIndex */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_2__->NextIndex;
    /* IL_002f: call Calculator.PolishNotation.ParseExpression */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_6__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_2__, stack1_1__);
    /* IL_0034: stloc.1  */
#line 178 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.left = (Calculator_ReducibleNode*)frame__.stack0_6__;
    /* IL_0035: ldloc.1  */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = frame__.left;
    /* IL_0036: brtrue.s IL_003a */
#line 179 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (frame__.stack0_5__ != NULL) goto IL_003a;
    /* IL_0038: ldnull  */
#line 181 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_0039: ret  */
#line 181 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 181 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_ExpressionNode*)stack0_1__;
IL_003a:
    /* IL_003a: ldarg.0  */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_003b: ldloc.1  */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_3__ = frame__.left;
    /* IL_003c: ldfld Calculator.AbstractNode.NextIndex */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_0041: call Calculator.PolishNotation.ParseNumeric */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_4__ = Calculator_PolishNotation_ParseNumeric(frame__.stack0_2__, stack1_1__);
    /* IL_0046: stloc.2  */
#line 185 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.right = (Calculator_ReducibleNode*)frame__.stack0_4__;
    /* IL_0047: ldloc.2  */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = frame__.right;
    /* IL_0048: brtrue.s IL_005c */
#line 186 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (frame__.stack0_5__ != NULL) goto IL_005c;
    /* IL_004a: ldarg.0  */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_004b: ldloc.1  */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_3__ = frame__.left;
    /* IL_004c: ldfld Calculator.AbstractNode.NextIndex */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_0051: call Calculator.PolishNotation.ParseExpression */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_6__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_2__, stack1_1__);
    /* IL_0056: stloc.2  */
#line 188 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.right = (Calculator_ReducibleNode*)frame__.stack0_6__;
    /* IL_0057: ldloc.2  */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_5__ = frame__.right;
    /* IL_0058: brtrue.s IL_005c */
#line 189 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (frame__.stack0_5__ != NULL) goto IL_005c;
    /* IL_005a: ldnull  */
#line 191 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = NULL;
    /* IL_005b: ret  */
#line 191 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 191 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return (Calculator_ExpressionNode*)stack0_1__;
IL_005c:
    /* IL_005c: ldarg.0  */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = line;
    /* IL_005d: ldloc.2  */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_3__ = frame__.right;
    /* IL_005e: ldfld Calculator.AbstractNode.NextIndex */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = frame__.stack1_3__->NextIndex;
    /* IL_0063: call Calculator.PolishNotation.SkipWhiteSpace */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(frame__.stack0_2__, stack1_1__);
    /* IL_0068: stloc.3  */
#line 195 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    index = stack0_0__;
    /* IL_0069: ldloc.0  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.oper;
    /* IL_006a: ldloc.1  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_3__ = frame__.left;
    /* IL_006b: ldloc.2  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack2_0__ = frame__.right;
    /* IL_006c: ldloc.3  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack3_0__ = index;
    /* IL_006d: newobj Calculator.ExpressionNode..ctor */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_6__ = il2c_get_uninitialized_object(Calculator_ExpressionNode);
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_ExpressionNode__ctor(frame__.stack0_6__, frame__.stack0_3__, frame__.stack1_3__, frame__.stack2_0__, stack3_0__);
    /* IL_0072: ret  */
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return frame__.stack0_6__;
#line 196 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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
    Calculator_ExpressionNode* stack0_2__;
    System_String* stack1_0__;
} Calculator_PolishNotation_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_PolishNotation_Main(void)
{
    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    bool stack0_1__;
#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_3__;
#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_PolishNotation_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldstr "Polish notation calculator." */
#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string0__;
    /* IL_0005: call System.Console.WriteLine */
#line 204 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_000a: ldstr "This is proof of concept for IL2C." */
#line 205 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string1__;
    /* IL_000f: call System.Console.WriteLine */
#line 205 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_0014: ldstr "https://github.com/kekyo/IL2C" */
#line 206 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string2__;
    /* IL_0019: call System.Console.WriteLine */
#line 206 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_001e: call System.Console.WriteLine */
#line 207 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine();
    /* IL_0023: ldstr "Type "exit" to exit." */
#line 208 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string3__;
    /* IL_0028: call System.Console.WriteLine */
#line 208 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
IL_002d:
    /* IL_002d: call System.Console.WriteLine */
#line 212 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine();
    /* IL_0032: ldstr "PN> " */
#line 213 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string4__;
    /* IL_0037: call System.Console.Write */
#line 213 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_Write_9(frame__.stack0_0__);
    /* IL_003c: call System.Console.ReadLine */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = System_Console_ReadLine();
    /* IL_0041: stloc.0  */
#line 214 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.line = frame__.stack0_0__;
    /* IL_0042: ldloc.0  */
#line 215 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = frame__.line;
    /* IL_0043: call System.String.IsNullOrWhiteSpace */
#line 215 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = System_String_IsNullOrWhiteSpace(frame__.stack0_0__);
    /* IL_0048: brtrue.s IL_002d */
#line 215 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ != false) goto IL_002d;
    /* IL_004a: ldloc.0  */
#line 217 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = frame__.line;
    /* IL_004b: ldstr "exit" */
#line 217 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = Calculator_Core_string5__;
    /* IL_0050: call System.String.op_Equality */
#line 217 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_1__ = System_String_op_Equality(frame__.stack0_0__, frame__.stack1_0__);
    /* IL_0055: brfalse.s IL_0058 */
#line 217 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_1__ == false) goto IL_0058;
    /* IL_0057: ret  */
#line 219 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 219 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return;
IL_0058:
    /* IL_0058: ldloc.0  */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = frame__.line;
    /* IL_0059: ldc.i4.0  */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = 0;
    /* IL_005a: call Calculator.PolishNotation.ParseExpression */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = Calculator_PolishNotation_ParseExpression(frame__.stack0_0__, stack1_1__);
    /* IL_005f: stloc.1  */
#line 222 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.expr = frame__.stack0_2__;
    /* IL_0060: ldloc.1  */
#line 223 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = frame__.expr;
    /* IL_0061: brtrue.s IL_006f */
#line 223 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (frame__.stack0_2__ != NULL) goto IL_006f;
    /* IL_0063: ldstr "Syntax error." */
#line 225 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = Calculator_Core_string6__;
    /* IL_0068: call System.Console.WriteLine */
#line 225 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_006d: br.s IL_002d */
#line 226 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_002d;
IL_006f:
    /* IL_006f: ldloc.1  */
#line 229 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_2__ = frame__.expr;
    /* IL_0070: callvirt Calculator.ReducibleNode.Reduce */
#line 229 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_3__ = frame__.stack0_2__->vptr0__->Reduce((Calculator_ReducibleNode*)frame__.stack0_2__);
    /* IL_0075: ldstr "Reuslt=" */
#line 231 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_0__ = Calculator_Core_string7__;
    /* IL_007a: call System.Console.Write */
#line 231 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_Write_9(frame__.stack1_0__);
    /* IL_007f: call System.Console.WriteLine */
#line 232 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    System_Console_WriteLine_6(stack0_3__);
    /* IL_0084: br.s IL_002d */
#line 210 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    goto IL_002d;
#line 210 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
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
    /* IL_0006: ret  */
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
