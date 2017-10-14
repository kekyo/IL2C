#ifndef __MODULE_il2c_test_target__
#define __MODULE_il2c_test_target__

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct il2c_test_target_Hoge3
{
    int32_t Value2;
} il2c_test_target_Hoge3;

extern int32_t il2c_test_target_Hoge3_Value1;

extern int32_t il2c_test_target_Hoge4_Test4(void);
extern uint8_t il2c_test_target_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t il2c_test_target_Hoge2_Add4(uint16_t a, bool isTwo);
extern int32_t il2c_test_target_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t il2c_test_target_Hoge1_Add2(int64_t a, bool isTwo);

#endif
