#include <il2c_private.h>

//////////////////////////////////////////////////
// Visual C++

// Standard Win32 API
#if defined(_MSC_VER) && defined(_WIN32) && !defined(UEFI) && !defined(_WDM)

void il2c_debug_write(const char* format, ...)
{
    va_list va;
    char buffer[128];

    va_start(va, format);
    il2c_assert(format != NULL);
    wvsprintfA(buffer, format, va);
    OutputDebugStringA(buffer);
    va_end(va);
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
    return p != NULL;
}

#endif
