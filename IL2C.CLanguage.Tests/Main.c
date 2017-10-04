#include <assert.h>
#include "TargetCode.h"

int main()
{
    int64_t value = IL2C_ConverterTest_AccessStaticFieldTestMethod();
    assert(value == 3);
}
