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

// NOT Azure Sphere
#if !defined(__AZURE_SPHERE__)

void il2c_debug_write(const char* message)
{
    il2c_assert(message != NULL);

    int32_t length = il2c_get_utf8_length(message, false);
    wchar_t* pBuffer = il2c_mcalloc((length + 3) * sizeof(wchar_t));
    wchar_t* pLast = il2c_utf16_from_utf8_and_get_last(pBuffer, message);
    *pLast++ = L'\r';
    *pLast++ = L'\n';
    *pLast = L'\0';

    fputws(pBuffer, stderr);

    il2c_mcfree(pBuffer);
}

void il2c_debug_write_format(const char* format, ...)
{
    il2c_assert(format != NULL);

    va_list va;

    va_start(va, format);
    vfwprintf(stderr, format, va);
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
