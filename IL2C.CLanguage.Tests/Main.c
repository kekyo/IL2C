#include <assert.h>
#include "TargetCode.h"

int main()
{
    uint8_t result = ByteMainBody();

    uint8_t expected = 3;
    assert(expected == result);
}
