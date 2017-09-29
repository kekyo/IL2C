#include <assert.h>
#include "TargetCode.h"

int main()
{
    int32_t i32r1 = il2c_test_target_Hoge1_Add1(123, false);
    assert(124 == i32r1);

    int32_t i32r2 = il2c_test_target_Hoge1_Add1(123, true);
    assert(125 == i32r2);

    int64_t i64r1 = il2c_test_target_Hoge1_Add2(123456789012345LL, false);
    assert(123456789012346LL == i64r1);

    int64_t i64r2 = il2c_test_target_Hoge1_Add2(-123456789012345LL, true);
    assert(-123456789012343LL == i64r2);

    uint8_t ui8r1 = il2c_test_target_Hoge2_Add3(250, false);
    assert(251 == ui8r1);

    uint8_t ui8r2 = il2c_test_target_Hoge2_Add3(250, true);
    assert(252 == ui8r2);

    uint16_t ui16r1 = il2c_test_target_Hoge2_Add4(65530, false);
    assert(65531 == ui16r1);

    uint16_t ui16r2 = il2c_test_target_Hoge2_Add4(65530, true);
    assert(65532 == ui16r2);
}
