#include <stdbool.h>
#include <stdint.h>

int8_t SByteWithMinusMainBody(void)
{
    int8_t local0;
    int8_t local1;
    int8_t local2;
    int8_t local3;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = -2;
    local0 = (int8_t)__stack0_int32_t;
    __stack0_int32_t = 5;
    local1 = (int8_t)__stack0_int32_t;
    __stack0_int32_t = local0;
    __stack1_int32_t = local1;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack0_int32_t = (int8_t)__stack0_int32_t;
    local2 = (int8_t)__stack0_int32_t;
    __stack0_int32_t = local2;
    local3 = (int8_t)__stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local3;
    return (int8_t)__stack0_int32_t;
}
