#include <assert.h>
#include "TargetCode.h"

int main()
{
    int8_t result = SByteWithMinusMainBody();

    int8_t expected = 3;
    assert(expected == result);
}
