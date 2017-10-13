#include <assert.h>
#include "Generated/il2c_test_target.h"

int main()
{
    il2c_test_target_Hoge4_Test4();

    uint8_t result1 = il2c_test_target_Hoge2_Add3(10, true);  // 10 + 2
    assert(result1 == 12);

    uint8_t result2 = il2c_test_target_Hoge2_Add3(10, false); // 10 + 1
    assert(result2 == 11);
}
