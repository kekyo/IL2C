#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

//////////////////////////////////////////////////////////////////////////
// IL2C <---> UEFI interop functions

bool twtoi(const wchar_t *_Str, int32_t* value)
{
    bool sign = false;

    for (;; _Str++)
    {
        wchar_t ch = *_Str;
        if ((ch == L' ') || (ch == L'\t'))
        {
            continue;
        }

        if (ch == L'-')
        {
            sign = true;
            _Str++;
        }
        else if (ch == L'+')
        {
            _Str++;
        }
        else if ((*_Str < L'0') || (*_Str > L'9'))
        {
            return false;
        }

        break;
    }

    int32_t n = 0;
    while ((*_Str >= L'0') && (*_Str <= L'9'))
    {
        n = n * 10 + *_Str++ - L'0';
    }

    *value = sign ? -n : n;
    return true;
}

void itow(int32_t value, wchar_t* p)
{
    wchar_t *j;
    wchar_t b[6];

    if (value < 0)
    {
        *p++ = L'-';
        value = -value;
    }

    j = &b[5];
    *j-- = 0;

    do
    {
        *j-- = value % 10 + L'0';
        value /= 10;
    } while (value);

    do
    {
        *p++ = *++j;
    } while (*j);
}

void ReadLine(wchar_t* pBuffer, uint16_t length)
{
    fgetws(pBuffer, length, stdin);
    size_t l = wcslen(pBuffer);
    pBuffer[l - 1] = L'\0';
}

void Write(const wchar_t* pMessage)
{
    wprintf(L"%ls", pMessage);
}

void WriteLine(const wchar_t* pMessage)
{
    wprintf(L"%ls\r\n", pMessage);
}

void WriteLineToError(const wchar_t* pMessage)
{
    fwprintf(stderr, L"%ls\r\n", pMessage);
}

///////////////////////////////////////////////////////////

#include "Generated/Win32.Code.h"

IL2C_CONST_STRING(hoge, L"Hoge\r\n");

int main()
{
    il2c_initialize();

    Win32_Code_PolishNotation_Main();

    Win32_Code_InheritTypeTest_Test1();
    Win32_Code_InheritTypeTest_Test2();
    Win32_Code_InheritTypeTest_Test3();
    Win32_Code_InheritTypeTest_Test4();

    while (1)
    {
        int index;
        for (index = 0; index < 100; index++)
        {
            Win32_Code_StringTest_LiteralString();

            System_String* pString11 = Win32_Code_StringTest_LiteralSubstring();
            printf("pString11 = %ls\r\n", pString11->string_body__);

            wchar_t ch1 = Win32_Code_StringTest_GetChar();
            printf("ch1 = %lc\r\n", ch1);

            wchar_t ch2 = Win32_Code_StringTest_GetCharByIndex(hoge, 2);
            printf("ch2 = %lc\r\n", ch2);

            System_String* pString1 = Win32_Code_StringTest_InOutString(hoge);
            printf("pString1 = %ls", pString1->string_body__);

            Win32_Code_Win32_OutputDebugString(hoge);

            System_String* pString2 = Win32_Code_StringTest_LiteralCombinedString();
            printf("pString2 = %ls\n", pString2->string_body__);

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

        il2c_collect();
    }

    il2c_shutdown();
}
