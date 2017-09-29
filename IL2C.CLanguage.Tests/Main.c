#include <assert.h>
#include "TargetCode.h"

int main()
{
    int16_t result = Int16MainBody();

    int16_t expected = 3;
    assert(expected == result);
}
