#include <stdio.h>

#include "Generated/Win32.Code.h"

__DEFINE_CONST_STRING__(hoge, L"Hoge\r\n");

int main()
{
    __gc_initialize__();

    while (1)
    {
        int index;
        for (index = 0; index < 100; index++)
        {
            Win32_Code_StringTest_LiteralString();

            System_String* pString1 = Win32_Code_StringTest_InOutString(hoge);
            printf("pString1 = %ls", pString1->pBody);

            Win32_Code_Win32_OutputDebugString(hoge);

            System_String* pString2 = Win32_Code_StringTest_LiteralCombinedString();
            printf("pString2 = %ls", pString2->pBody);

            int32_t result6 = Win32_Code_ClassTypeTest_Test4();
            printf("result6 = %d\n", result6);

            int32_t result7 = Win32_Code_ClassTypeTest_Test5();
            printf("result7 = %d\n", result7);

            Win32_Code_ValueTypeTestTarget hoge3;
            hoge3.Value2 = 789;
            int32_t result4 = Win32_Code_ValueTypeTestTarget_GetValue2(&hoge3, 123, 456);
            printf("result4 = %d\n", result4);

            int32_t result5 = Win32_Code_ValueTypeTest_Test5();
            printf("result5 = %d\n", result5);

            int32_t result0 = Win32_Code_ValueTypeTest_Test4();
            printf("result0 = %d\n", result0);

            uint8_t result1 = Win32_Code_Hoge2_Add3(10, true);  // 10 + 2
            printf("result1 = %d\n", result1);

            uint8_t result2 = Win32_Code_Hoge2_Add3(10, false); // 10 + 1
            printf("result2 = %d\n", result2);
        }

        __gc_collect__();
    }

    __gc_shutdown__();
}
