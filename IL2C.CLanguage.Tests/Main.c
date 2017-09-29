#include <assert.h>
#include "TargetCode.h"

int main()
{
    uint16_t result = UInt16WithMaxValueMainBody();

    uint16_t expected = UINT16_MAX - 5 + 2;
    assert(expected == result);
}
