#include <assert.h>
#include "TargetCode.h"

int main()
{
    int32_t i32r1 = Add1(123, false);
    assert(124 == i32r1);

    int32_t i32r2 = Add1(123, true);
    assert(125 == i32r2);

    int64_t i64r1 = Add2(123456789012345LL, false);
    assert(123456789012346LL == i64r1);

    int64_t i64r2 = Add2(-123456789012345LL, true);
    assert(-123456789012343LL == i64r2);

    int32_t ui8r1 = Add3(250, false);
    assert(251 == ui8r1);

    int32_t ui8r2 = Add3(250, true);
    assert(252 == ui8r2);

    int32_t ui16r1 = Add4(65530, false);
    assert(65531 == ui16r1);

    int32_t ui16r2 = Add4(65530, true);
    assert(65532 == ui16r2);
}
