#ifndef __MODULE_il2c_test_target__
#define __MODULE_il2c_test_target__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct il2c_test_target_ClassTypeTestTarget
{
    int32_t Value2;
} il2c_test_target_ClassTypeTestTarget;

typedef struct il2c_test_target_ClassTypeTest
{
    char __dummy[];
} il2c_test_target_ClassTypeTest;

typedef struct il2c_test_target_ValueTypeTestTarget
{
    int32_t Value2;
} il2c_test_target_ValueTypeTestTarget;

typedef struct il2c_test_target_ValueTypeTest
{
    char __dummy[];
} il2c_test_target_ValueTypeTest;

typedef struct il2c_test_target_Hoge2
{
    char __dummy[];
} il2c_test_target_Hoge2;

typedef struct il2c_test_target_Hoge1
{
    char __dummy[];
} il2c_test_target_Hoge1;

extern int32_t il2c_test_target_ValueTypeTestTarget_Value1;

extern int32_t il2c_test_target_ClassTypeTestTarget_GetValue2(il2c_test_target_ClassTypeTestTarget* __this, int32_t a, int32_t b);
extern int32_t il2c_test_target_ClassTypeTest_Test4(void);
extern int32_t il2c_test_target_ClassTypeTest_Test5(void);
extern int32_t il2c_test_target_ValueTypeTestTarget_GetValue2(il2c_test_target_ValueTypeTestTarget* __this, int32_t a, int32_t b);
extern int32_t il2c_test_target_ValueTypeTest_Test4(void);
extern int32_t il2c_test_target_ValueTypeTest_Test5(void);
extern uint8_t il2c_test_target_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t il2c_test_target_Hoge2_Add4(uint16_t a, bool isTwo);
extern int32_t il2c_test_target_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t il2c_test_target_Hoge1_Add2(int64_t a, bool isTwo);

#endif
