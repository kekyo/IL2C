#include <stdint.h>

int64_t main(void)
{
    int64_t local0;
    int64_t local1;
    int64_t local2;
    int64_t local3;

    int32_t __stack0_int32_t;
    int64_t __stack0_int64_t;
    int64_t __stack1_int64_t;

    __stack0_int32_t = 1;
    __stack0_int64_t = (int64_t)__stack0_int32_t;
    local0 = __stack0_int64_t;
    __stack0_int32_t = 2;
    __stack0_int64_t = (int64_t)__stack0_int32_t;
    local1 = __stack0_int64_t;
    __stack0_int64_t = local0;
    __stack1_int64_t = local1;
    __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;
    local2 = __stack0_int64_t;
    __stack0_int64_t = local2;
    local3 = __stack0_int64_t;
    __stack0_int64_t = local3;
    return __stack0_int64_t;
}
