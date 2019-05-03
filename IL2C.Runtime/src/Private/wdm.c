#include <il2c_private.h>

//////////////////////////////////////////////////
// WDM

#if defined(_WDM)

void il2c_initialize(void)
{
    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();
}

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    // TODO:
    OutputDebugStringW(message);
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
    _putws(s);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    // Can't read from the default console on the WDM kernel mode driver.
    return false;
}

#endif
