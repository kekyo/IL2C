#include <windows.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

#include <il2c.h>

#include "Calculator.Code.h"

//////////////////////////////////////////////////////////////////////////
// IL2C <---> UEFI interop functions

bool twtoi(const wchar_t *_Str, int32_t* value)
{
    char sign = 0;

    for (;; _Str++)
    {
        wchar_t ch = *_Str;
        if ((ch == L' ') || (ch == L'\t'))
        {
            continue;
        }

        if (ch == L'-')
        {
            sign = -1;
            _Str++;
        }
        else if (ch == L'+')
        {
            sign = 1;
            _Str++;
        }
        else if ((*_Str < L'0') || (*_Str > L'9'))
        {
            return false;
        }

        break;
    }

    bool f = false;
    int32_t n = 0;
    while ((*_Str >= L'0') && (*_Str <= L'9'))
    {
        n = n * 10 + *_Str++ - L'0';
        f = true;
    }

    if (!f) return false;

    if (sign != 0) *value = sign * n;
    else *value = n;

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

void SendExternalTicker(const wchar_t* message)
{
    fwprintf(stderr, L"%ls\r\n", message);
}

///////////////////////////////////////////////////////////

IL2C_CONST_STRING(hoge, L"Hoge\r\n");

int main()
{
    il2c_initialize();

    Calculator_PolishNotation_Main();

    il2c_shutdown();
}
