#include <il2c_private.h>

//////////////////////////////////////////////////
// GCC

// MinGW (Win32 API)
#if defined(__GNUC__) && defined(_WIN32)

void il2c_debug_write(const char* message)
{
    il2c_assert(message != NULL);

    int32_t length = il2c_get_utf8_length(message, false);
    wchar_t* pBuffer = il2c_mcalloc((length + 1) * sizeof(wchar_t));
    il2c_utf16_from_utf8_and_get_last(pBuffer, message);

    OutputDebugStringW(pBuffer);

    il2c_mcfree(pBuffer);
}

void il2c_debug_write2(const char* message1, const char* message2)
{
    il2c_assert(message1 != NULL);
    il2c_assert(message2 != NULL);

    int32_t length1 = il2c_get_utf8_length(message1, false);
    int32_t length2 = il2c_get_utf8_length(message2, false);
    wchar_t* pBuffer = il2c_mcalloc((length1 + length2 + 1) * sizeof(wchar_t));
    wchar_t* pLast1 = il2c_utf16_from_utf8_and_get_last(pBuffer, message1);
    il2c_utf16_from_utf8_and_get_last(pLast1, message2);

    OutputDebugStringW(pBuffer);

    il2c_mcfree(pBuffer);
}

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);
    fputws(s, stdout);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);
    _putws(s);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);

    const wchar_t* p = fgetws(buffer, length - 1, stdin);
    if (p != NULL)
    {
        wchar_t* cr = wcschr(buffer, L'\r');
        wchar_t* lf = wcschr(buffer, L'\n');
        if ((cr != NULL) && (lf != NULL) && ((lf - cr) == 1))
        {
            *cr = L'\0';
            return true;
        }
    }

    return false;
}

void il2c_initialize(void)
{
    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();
}

#endif
