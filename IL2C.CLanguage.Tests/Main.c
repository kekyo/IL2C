#include <assert.h>
#include "TargetCode.h"

int main()
{
    auto value = -5;

    auto result = ConditionalBranchMainBody(value);

    auto expected = value + 2;
    assert(expected == result);
}
