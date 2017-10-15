#include <stdio.h>
#include "Generated/il2c_test_target.h"

int main()
{
    il2c_test_target_Hoge3 hoge3;
    hoge3.Value2 = 789;
    int32_t result4 = il2c_test_target_Hoge3_GetValue2(&hoge3, 123, 456);
    printf("result4 = %d\n", result4);

    int32_t result5 = il2c_test_target_Hoge4_Test5();
    printf("result5 = %d\n", result5);

    int32_t result0 = il2c_test_target_Hoge4_Test4();
    printf("result0 = %d\n", result0);

    uint8_t result1 = il2c_test_target_Hoge2_Add3(10, true);  // 10 + 2
    printf("result1 = %d\n", result1);

    uint8_t result2 = il2c_test_target_Hoge2_Add3(10, false); // 10 + 1
    printf("result2 = %d\n", result2);
}
