#include <stdbool.h>
#include <stdint.h>

int32_t IL2C_ConverterTest_CallStaticMethodWithFieldReferencedTestType_Field0 = 1;
int64_t IL2C_ConverterTest_CallStaticMethodWithFieldReferencedTestType_Field1 = 2LL;

int64_t IL2C_ConverterTest_AccessStaticFieldTestMethod(void)
{
    int64_t local0;

    int32_t __stack0_int32_t;
    int64_t __stack0_int64_t;
    int64_t __stack1_int64_t;

    __stack0_int32_t = IL2C_ConverterTest_CallStaticMethodWithFieldReferencedTestType_Field0;
    __stack0_int64_t = __stack0_int32_t;
    __stack1_int64_t = IL2C_ConverterTest_CallStaticMethodWithFieldReferencedTestType_Field1;
    __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;
    local0 = __stack0_int64_t;
    goto L_0000;
L_0000:
    __stack0_int64_t = local0;
    return __stack0_int64_t;
}
