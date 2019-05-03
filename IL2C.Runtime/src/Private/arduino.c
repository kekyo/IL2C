#include <il2c_private.h>

//////////////////////////////////////////////////
// Arduino

#if defined(ARDUINO) && defined(__GNUC__)

void il2c_initialize()
{
    il2c_initialize__(0);
}

void il2c_shutdown()
{
    il2c_shutdown__();
}

int32_t* il2c_errno__(void)
{
    static int eno = 0;
    return &eno;
}

void il2c_sleep(uint32_t milliseconds)
{
#if defined(portTICK_RATE_MS)
    vTaskDelay(milliseconds / portTICK_RATE_MS);
#else
    delay(milliseconds);
#endif
}

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const char* message)
{
    il2c_assert(message != NULL);

    int32_t length = il2c_get_utf8_length(message, false);
    il2c_mcalloc(wchar_t, pBuffer, (length + 3) * sizeof(wchar_t));
    wchar_t* pLast = il2c_utf16_from_utf8_and_get_last(pBuffer, message);
    *pLast++ = L'\r';
    *pLast++ = L'\n';
    *pLast = L'\0';

    // TODO: Serial out
    //g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, pBuffer);

    il2c_mcfree(pBuffer);
}
#endif

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);

    // TODO: Serial out
    //g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);

    // TODO: Serial out
    //g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
    //g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);

    return false;
}

#endif
