#include <stdbool.h>
#include <stdint.h>

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

#include <stdbool.h>
#include <stdint.h>

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

#include <stdbool.h>
#include <stdint.h>

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

#include <stdbool.h>
#include <stdint.h>

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

