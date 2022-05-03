#include <il2c_private.h>

//////////////////////////////////////////////////
// Linux

#if defined(__linux__)

void il2c_initialize(void)
{
    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();
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

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    // TODO: syslog
    fputws(message, stderr);
}
#endif

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
