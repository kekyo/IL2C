#include <stdbool.h>
#include <stdint.h>

uint8_t ByteMainBody(void)
{
    uint8_t local0;
    uint8_t local1;
    uint8_t local2;
    uint8_t local3;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = 1;
    local0 = (uint8_t)__stack0_int32_t;
    __stack0_int32_t = 2;
    local1 = (uint8_t)__stack0_int32_t;
    __stack0_int32_t = local0;
    __stack1_int32_t = local1;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack0_int32_t = (uint8_t)__stack0_int32_t;
    local2 = (uint8_t)__stack0_int32_t;
    __stack0_int32_t = local2;
    local3 = (uint8_t)__stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local3;
    return (uint8_t)__stack0_int32_t;
}
