#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct IL2C_TestTargetClass_AccessValueTypeFieldTestType
{
    int32_t Value1;
} IL2C_TestTargetClass_AccessValueTypeFieldTestType;

void IL2C_TestTargetClass_AccessValueTypeFieldMethod(void)
{
    IL2C_TestTargetClass_AccessValueTypeFieldTestType local0;

    IL2C_TestTargetClass_AccessValueTypeFieldTestType* __stack0_IL2C_TestTargetClass_AccessValueTypeFieldTestType_reference;
    int32_t __stack1_int32_t;

    __stack0_IL2C_TestTargetClass_AccessValueTypeFieldTestType_reference = &local0;
    memset(__stack0_IL2C_TestTargetClass_AccessValueTypeFieldTestType_reference, 0x00, sizeof(IL2C_TestTargetClass_AccessValueTypeFieldTestType));
    __stack0_IL2C_TestTargetClass_AccessValueTypeFieldTestType_reference = &local0;
    __stack1_int32_t = 123;
    __stack0_IL2C_TestTargetClass_AccessValueTypeFieldTestType_reference->Value1 = __stack1_int32_t;
    return;
}
