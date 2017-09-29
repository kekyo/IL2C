#include <stdbool.h>
#include <stdint.h>

uint16_t UInt16WithMaxValueMainBody(void)
{
    uint16_t local0;
    uint16_t local1;
    uint16_t local2;
    uint16_t local3;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = 65530;
    local0 = (uint16_t)__stack0_int32_t;
    __stack0_int32_t = 2;
    local1 = (uint16_t)__stack0_int32_t;
    __stack0_int32_t = local0;
    __stack1_int32_t = local1;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack0_int32_t = (uint16_t)__stack0_int32_t;
    local2 = (uint16_t)__stack0_int32_t;
    __stack0_int32_t = local2;
    local3 = (uint16_t)__stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local3;
    return (uint16_t)__stack0_int32_t;
}
