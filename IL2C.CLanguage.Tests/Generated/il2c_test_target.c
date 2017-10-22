#include "il2c_test_target.h"

int32_t il2c_test_target_ValueTypeTestTarget_Value1 = 123;


int32_t il2c_test_target_ClassTypeTestTarget_GetValue2(il2c_test_target_ClassTypeTestTarget* __this, int32_t a, int32_t b)
{
    int32_t local0;

    il2c_test_target_ClassTypeTestTarget* __stack0_il2c_test_target_ClassTypeTestTarget_reference;
    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_il2c_test_target_ClassTypeTestTarget_reference = __this;
    __stack0_int32_t = __stack0_il2c_test_target_ClassTypeTestTarget_reference->Value2;
    __stack1_int32_t = a;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack1_int32_t = b;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    local0 = __stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local0;
    return __stack0_int32_t;
}


int32_t il2c_test_target_ClassTypeTest_Test4(void)
{
    il2c_test_target_ClassTypeTestTarget* local0;
    int32_t local1;

    il2c_test_target_ClassTypeTestTarget* __stack0_il2c_test_target_ClassTypeTestTarget_reference;
    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_il2c_test_target_ClassTypeTestTarget_reference = (il2c_test_target_ClassTypeTestTarget*)malloc(sizeof(il2c_test_target_ClassTypeTestTarget*));
    memset(__stack0_il2c_test_target_ClassTypeTestTarget_reference, 0x00, sizeof(il2c_test_target_ClassTypeTestTarget));
    il2c_test_target_ClassTypeTestTarget__ctor(__stack0_il2c_test_target_ClassTypeTestTarget_reference);
    local0 = __stack0_il2c_test_target_ClassTypeTestTarget_reference;
    __stack0_il2c_test_target_ClassTypeTestTarget_reference = local0;
    __stack1_int32_t = 456;
    __stack0_il2c_test_target_ClassTypeTestTarget_reference->Value2 = __stack1_int32_t;
    __stack0_il2c_test_target_ClassTypeTestTarget_reference = local0;
    __stack0_int32_t = __stack0_il2c_test_target_ClassTypeTestTarget_reference->Value2;
    local1 = __stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local1;
    return __stack0_int32_t;
}


int32_t il2c_test_target_ClassTypeTest_Test5(void)
{
    il2c_test_target_ClassTypeTestTarget* local0;
    int32_t local1;
    int32_t local2;

    il2c_test_target_ClassTypeTestTarget* __stack0_il2c_test_target_ClassTypeTestTarget_reference;
    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;
    int32_t __stack2_int32_t;

    __stack0_il2c_test_target_ClassTypeTestTarget_reference = (il2c_test_target_ClassTypeTestTarget*)malloc(sizeof(il2c_test_target_ClassTypeTestTarget*));
    memset(__stack0_il2c_test_target_ClassTypeTestTarget_reference, 0x00, sizeof(il2c_test_target_ClassTypeTestTarget));
    il2c_test_target_ClassTypeTestTarget__ctor(__stack0_il2c_test_target_ClassTypeTestTarget_reference);
    local0 = __stack0_il2c_test_target_ClassTypeTestTarget_reference;
    __stack0_il2c_test_target_ClassTypeTestTarget_reference = local0;
    __stack1_int32_t = 789;
    __stack0_il2c_test_target_ClassTypeTestTarget_reference->Value2 = __stack1_int32_t;
    __stack0_il2c_test_target_ClassTypeTestTarget_reference = local0;
    __stack1_int32_t = 123;
    __stack2_int32_t = 456;
    __stack0_int32_t = il2c_test_target_ClassTypeTestTarget_GetValue2(__stack0_il2c_test_target_ClassTypeTestTarget_reference, __stack1_int32_t, __stack2_int32_t);
    local1 = __stack0_int32_t;
    __stack0_int32_t = local1;
    local2 = __stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local2;
    return __stack0_int32_t;
}


int32_t il2c_test_target_ValueTypeTestTarget_GetValue2(il2c_test_target_ValueTypeTestTarget* __this, int32_t a, int32_t b)
{
    int32_t local0;

    il2c_test_target_ValueTypeTestTarget* __stack0_il2c_test_target_ValueTypeTestTarget_reference;
    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_il2c_test_target_ValueTypeTestTarget_reference = __this;
    __stack0_int32_t = __stack0_il2c_test_target_ValueTypeTestTarget_reference->Value2;
    __stack1_int32_t = a;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack1_int32_t = b;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    local0 = __stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local0;
    return __stack0_int32_t;
}


int32_t il2c_test_target_ValueTypeTest_Test4(void)
{
    il2c_test_target_ValueTypeTestTarget local0;
    int32_t local1;

    il2c_test_target_ValueTypeTestTarget* __stack0_il2c_test_target_ValueTypeTestTarget_reference;
    il2c_test_target_ValueTypeTestTarget __stack0_il2c_test_target_ValueTypeTestTarget;
    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_il2c_test_target_ValueTypeTestTarget_reference = &local0;
    memset(__stack0_il2c_test_target_ValueTypeTestTarget_reference, 0x00, sizeof(il2c_test_target_ValueTypeTestTarget));
    __stack0_il2c_test_target_ValueTypeTestTarget_reference = &local0;
    __stack1_int32_t = 456;
    __stack0_il2c_test_target_ValueTypeTestTarget_reference->Value2 = __stack1_int32_t;
    __stack0_il2c_test_target_ValueTypeTestTarget = local0;
    __stack0_int32_t = __stack0_il2c_test_target_ValueTypeTestTarget.Value2;
    local1 = __stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local1;
    return __stack0_int32_t;
}


int32_t il2c_test_target_ValueTypeTest_Test5(void)
{
    il2c_test_target_ValueTypeTestTarget local0;
    int32_t local1;
    int32_t local2;

    il2c_test_target_ValueTypeTestTarget* __stack0_il2c_test_target_ValueTypeTestTarget_reference;
    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;
    int32_t __stack2_int32_t;

    __stack0_il2c_test_target_ValueTypeTestTarget_reference = &local0;
    memset(__stack0_il2c_test_target_ValueTypeTestTarget_reference, 0x00, sizeof(il2c_test_target_ValueTypeTestTarget));
    __stack0_il2c_test_target_ValueTypeTestTarget_reference = &local0;
    __stack1_int32_t = 789;
    __stack0_il2c_test_target_ValueTypeTestTarget_reference->Value2 = __stack1_int32_t;
    __stack0_il2c_test_target_ValueTypeTestTarget_reference = &local0;
    __stack1_int32_t = 123;
    __stack2_int32_t = 456;
    __stack0_int32_t = il2c_test_target_ValueTypeTestTarget_GetValue2(__stack0_il2c_test_target_ValueTypeTestTarget_reference, __stack1_int32_t, __stack2_int32_t);
    local1 = __stack0_int32_t;
    __stack0_int32_t = local1;
    local2 = __stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local2;
    return __stack0_int32_t;
}


uint8_t il2c_test_target_Hoge2_Add3(uint8_t a, bool isTwo)
{
    uint8_t local0;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = a;
    __stack1_int32_t = isTwo ? 1 : 0;
    if (__stack1_int32_t != 0) goto L_0000;
    __stack1_int32_t = 1;
    goto L_0001;
L_0000:
    __stack1_int32_t = 2;
L_0001:
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack0_int32_t = (uint8_t)__stack0_int32_t;
    local0 = (uint8_t)__stack0_int32_t;
    goto L_0002;
L_0002:
    __stack0_int32_t = local0;
    return (uint8_t)__stack0_int32_t;
}


uint16_t il2c_test_target_Hoge2_Add4(uint16_t a, bool isTwo)
{
    uint16_t local0;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = a;
    __stack1_int32_t = isTwo ? 1 : 0;
    if (__stack1_int32_t != 0) goto L_0000;
    __stack1_int32_t = 1;
    goto L_0001;
L_0000:
    __stack1_int32_t = 2;
L_0001:
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack0_int32_t = (uint16_t)__stack0_int32_t;
    local0 = (uint16_t)__stack0_int32_t;
    goto L_0002;
L_0002:
    __stack0_int32_t = local0;
    return (uint16_t)__stack0_int32_t;
}


int32_t il2c_test_target_Hoge1_Add1(int32_t a, bool isTwo)
{
    int32_t local0;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = a;
    __stack1_int32_t = isTwo ? 1 : 0;
    if (__stack1_int32_t != 0) goto L_0000;
    __stack1_int32_t = 1;
    goto L_0001;
L_0000:
    __stack1_int32_t = 2;
L_0001:
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    local0 = __stack0_int32_t;
    goto L_0002;
L_0002:
    __stack0_int32_t = local0;
    return __stack0_int32_t;
}


int64_t il2c_test_target_Hoge1_Add2(int64_t a, bool isTwo)
{
    int64_t local0;

    int64_t __stack0_int64_t;
    int32_t __stack1_int32_t;
    int64_t __stack1_int64_t;

    __stack0_int64_t = a;
    __stack1_int32_t = isTwo ? 1 : 0;
    if (__stack1_int32_t != 0) goto L_0000;
    __stack1_int32_t = 1;
    goto L_0001;
L_0000:
    __stack1_int32_t = 2;
L_0001:
    __stack1_int64_t = __stack1_int32_t;
    __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;
    local0 = __stack0_int64_t;
    goto L_0002;
L_0002:
    __stack0_int64_t = local0;
    return __stack0_int64_t;
}

