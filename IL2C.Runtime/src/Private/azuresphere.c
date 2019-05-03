#include <il2c_private.h>

//////////////////////////////////////////////////
// GCC

// Azure Sphere
#if defined(__AZURE_SPHERE__)

#include <applibs/log.h>

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    size_t l = il2c_wcslen(message);
    il2c_mcalloc(char, d, l + 1);
    size_t i;
    for (i = 0; i < l; i++) d[i] = (char)(message[i]);
    d[i] = '\0';
    Log_Debug(d);
    il2c_mcfree(d);
}
#endif

// TODO: UTF16 --> UTF8

void il2c_write(const wchar_t* p)
{
    size_t l = il2c_wcslen(p);
    il2c_mcalloc(char, d, l + 1);
    size_t i;
    for (i = 0; i < l; i++) d[i] = (char)(p[i]);
    d[i] = '\0';
    Log_Debug(d);
    il2c_mcfree(d);
}

void il2c_writeline(const wchar_t* p)
{
    size_t l = il2c_wcslen(p);
    il2c_mcalloc(char, d, l + 2);
    size_t i;
    for (i = 0; i < l; i++) d[i] = (char)(p[i]);
    d[i++] = '\n';
    d[i] = '\0';
    Log_Debug(d);
    il2c_mcfree(d);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    // Can't read from the default console on the Azure Sphere MCU.
    return false;
}

#endif
