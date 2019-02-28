#include <il2c_private.h>

//////////////////////////////////////////////////
// GCC

// MinGW (Win32 API)
#if defined(__GNUC__) && defined(_WIN32)

void il2c_debug_write__(const char* message)
{
    il2c_assert(message != NULL);

    OutputDebugStringA(message);
}

void il2c_debug_write_format__(const char* format, ...)
{
    il2c_assert(format != NULL);

    va_list va;
    char buffer[128];

    va_start(va, format);
    vsprintf(buffer, format, va);
    va_end(va);

    OutputDebugStringA(buffer);
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
        if ((cr != NULL) || (lf != NULL))
        {
            if ((cr != NULL) && (lf != NULL) && ((lf - cr) == 1))
            {
                *cr = L'\0';
                return true;
            }
            if (lf != NULL)
            {
                *lf = L'\0';
                return true;
            }
            if (cr != NULL)
            {
                *cr = L'\0';
                return true;
            }
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
