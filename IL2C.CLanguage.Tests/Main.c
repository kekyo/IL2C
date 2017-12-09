#include <stdio.h>

#include "Generated/il2c_test_target.h"

__define_const_string__(hoge, "Hoge\r\n");

int main()
{
    __gc_initialize__();

    //while (1)
    {
        int index;
        for (index = 0; index < 100; index++)
        {
            il2c_test_target_StringTest_LiteralString();

            System_String* pString1 = il2c_test_target_StringTest_InOutString(hoge);
            printf("pString1 = %s", pString1->pString);

            il2c_test_target_StringTest_OutputDebugString(hoge);

            System_String* pString2 = il2c_test_target_StringTest_LiteralCombinedString();
            printf("pString2 = %s", pString2->pString);

            int32_t result6 = il2c_test_target_ClassTypeTest_Test4();
            printf("result6 = %d\n", result6);

            int32_t result7 = il2c_test_target_ClassTypeTest_Test5();
            printf("result7 = %d\n", result7);

            il2c_test_target_ValueTypeTestTarget hoge3;
            hoge3.Value2 = 789;
            int32_t result4 = il2c_test_target_ValueTypeTestTarget_GetValue2(&hoge3, 123, 456);
            printf("result4 = %d\n", result4);

            int32_t result5 = il2c_test_target_ValueTypeTest_Test5();
            printf("result5 = %d\n", result5);

            int32_t result0 = il2c_test_target_ValueTypeTest_Test4();
            printf("result0 = %d\n", result0);

            uint8_t result1 = il2c_test_target_Hoge2_Add3(10, true);  // 10 + 2
            printf("result1 = %d\n", result1);

            uint8_t result2 = il2c_test_target_Hoge2_Add3(10, false); // 10 + 1
            printf("result2 = %d\n", result2);
        }

        __gc_collect__();
    }

    __gc_shutdown__();
}
