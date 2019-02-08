#include <il2c_private.h>

//////////////////////////////////////////////////
// GCC

// Linux
#if defined(__GNUC__) && defined(__linux__)

wchar_t* il2c_itow(int32_t v, wchar_t* b, size_t l)
{
    swprintf(b, l, L"%d", v);
    return b;
}

wchar_t* il2c_ultow(uint32_t v, wchar_t* b, size_t l)
{
    swprintf(b, l, L"%lu", v);
    return b;
}

wchar_t* il2c_i64tow(int64_t v, wchar_t* b, size_t l)
{
    swprintf(b, l, L"%lld", v);
    return b;
}

wchar_t* il2c_ui64tow(uint64_t v, wchar_t* b, size_t l)
{
    swprintf(b, l, L"%llu", v);
    return b;
}

#include <time.h>

void il2c_sleep(uint32_t milliseconds)
{
    struct timespec tm1 = { (time_t)(milliseconds) / 1000, ((long)(milliseconds) % 1000) * 1000 * 1000 };
    struct timespec tm2;
    while (1)
    {
        if (nanosleep(&tm1, &tm2) == 0) break;
        if (nanosleep(&tm2, &tm1) == 0) break;
    }
}

#if !defined(__AZURE_SPHERE__)

void il2c_debug_write(const char* format, ...)
{
    va_list va;
    char buffer[128];

    va_start(va, format);
    il2c_assert(format != NULL);
    vsprintf(buffer, format, va);
    fputs(buffer, stdout);
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
    fputws(s, stdout);
    fputws(L"\n", stdout);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);
    const wchar_t* p = fgetws(buffer, length - 1, stdin);
    return p != NULL;
}

#endif

void il2c_initialize(void)
{
    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();
}

#endif
