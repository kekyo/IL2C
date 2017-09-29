#include <stdbool.h>
#include <stdint.h>

int16_t Int16MainBody(void)
{
    int16_t local0;
    int16_t local1;
    int16_t local2;
    int16_t local3;

    int32_t __stack0_int32_t;
    int32_t __stack1_int32_t;

    __stack0_int32_t = -2;
    local0 = (int16_t)__stack0_int32_t;
    __stack0_int32_t = 5;
    local1 = (int16_t)__stack0_int32_t;
    __stack0_int32_t = local0;
    __stack1_int32_t = local1;
    __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
    __stack0_int32_t = (int16_t)__stack0_int32_t;
    local2 = (int16_t)__stack0_int32_t;
    __stack0_int32_t = local2;
    local3 = (int16_t)__stack0_int32_t;
    goto L_0000;
L_0000:
    __stack0_int32_t = local3;
    return (int16_t)__stack0_int32_t;
}
