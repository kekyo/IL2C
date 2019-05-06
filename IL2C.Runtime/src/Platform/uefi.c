//////////////////////////////////////////////////
// UEFI

#if defined(UEFI)

#if defined(_DEBUG)
#define EFI_DEBUG 1
#else
#undef EFI_DEBUG
#endif

#include <il2c_private.h>

#include <stdio.h>
#include <stdarg.h>
#include "debugbreak.h"

#include "efi/efi.h"

static EFI_SYSTEM_TABLE* g_pSystemTable = NULL;

void il2c_initialize(void* imageHandle, void* pSystemTable)
{
    // Setup interop pointer
    g_pSystemTable = pSystemTable;

    // Disable default auto-reset watchdog timer
    g_pSystemTable->BootServices->SetWatchdogTimer(0, 0, 0, NULL);

    // Clear screen
    g_pSystemTable->ConOut->ClearScreen(g_pSystemTable->ConOut);

    il2c_initialize__();
}

void il2c_shutdown()
{
    il2c_shutdown__();
}

#if defined(_MSC_VER)
int _fltused = 1;
#endif

void* __cdecl memcpy(void* to, const void* from, size_t n)
{
    uint8_t* t = to;
    const uint8_t* f = from;
    n++;
    while (--n >= 1)
        *t++ = *f++;
    return to;
}

void* __cdecl memset(void* target, int ch, size_t n)
{
    uint8_t* p = target;
    n++;
    while (--n >= 1)
        *p++ = (uint8_t)ch;
    return target;
}

int __cdecl memcmp(const void *buffer1, const void *buffer2, size_t count)
{
    const uint8_t* p1 = buffer1;
    const uint8_t* p2 = buffer2;
    count++;
    while (--count >= 1)
    {
        const uint8_t v1 = *p1++;
        const uint8_t v2 = *p2++;
        if (v1 > v2) return v1 - v2;
        if (v1 < v2) return v1 - v2;
    }
    return 0;
}

int32_t* il2c_errno__(void)
{
    static int eno = 0;
    return &eno;
}

//////////////////////////////////////////////////////////
// These functions use the UEFI services.

void* il2c_malloc__(size_t _Size)
{
    if (g_pSystemTable == NULL)
    {
        return NULL;
    }

    void* ppAllocated = NULL;
    if (g_pSystemTable->BootServices->AllocatePool(
        EfiLoaderData, _Size, &ppAllocated) == EFI_SUCCESS)
    {
        return ppAllocated;
    }
    else
    {
        return NULL;
    }
}

void il2c_free__(void* _Block)
{
    if (g_pSystemTable != NULL)
    {
        g_pSystemTable->BootServices->FreePool(_Block);
    }
}

static EFI_EVENT g_TimerEvent = NULL;

void il2c_sleep(uint32_t milliseconds)
{
    UINTN index;

    // TODO: Will cause race condition if use multithreading environment.
    if (g_TimerEvent == NULL)
    {
        g_pSystemTable->BootServices->CreateEvent(
            EVT_TIMER, 0, NULL, NULL, &g_TimerEvent);
        il2c_assert(g_TimerEvent != NULL);
    }

    g_pSystemTable->BootServices->SetTimer(
        g_TimerEvent, TimerRelative, (uint64_t)milliseconds * 1000);
    g_pSystemTable->BootServices->WaitForEvent(1, &g_TimerEvent, &index);
}

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, (CHAR16*)message);
}
#endif

#if defined(_DEBUG)
void il2c_cause_assert__(const wchar_t* pFile, int line, const wchar_t* pExpr)
{
    if (g_pSystemTable != NULL)
    {
        wchar_t buffer[14];
        il2c_i32tow(line, buffer, 10);

        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, L"assert: ");
        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, (CHAR16*)pFile);
        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, L"(");
        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, buffer);
        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, L"): ");
        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, (CHAR16*)pExpr);
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->StdErr, L"\r\n");
    }

    debug_break();
}
#endif

void il2c_write(const wchar_t* s)
{
    if ((g_pSystemTable != NULL) && (s != NULL))
    {
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
    }
}

void il2c_writeline(const wchar_t* s)
{
    if ((g_pSystemTable != NULL) && (s != NULL))
    {
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
    }
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    if ((g_pSystemTable == NULL) || (buffer == NULL) || (length < 0))
    {
        return false;
    }

    wchar_t tempBuffer[4];

    int32_t index = 0;
    while ((index + 1) < length)
    {
        UINTN waitIndex;

        tempBuffer[0] = L'_';
        tempBuffer[1] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);

    loop:
        waitIndex = 0;
        g_pSystemTable->BootServices->WaitForEvent(
            1, &(g_pSystemTable->ConIn->WaitForKey), &waitIndex);

        EFI_INPUT_KEY efi_input_key;
        if (g_pSystemTable->ConIn->ReadKeyStroke(
            g_pSystemTable->ConIn, &efi_input_key) != 0)
        {
            goto loop;
        }

        if (efi_input_key.ScanCode != SCAN_NULL)
        {
            goto loop;
        }

        tempBuffer[0] = CHAR_BACKSPACE;
        tempBuffer[1] = L' ';
        tempBuffer[2] = CHAR_BACKSPACE;
        tempBuffer[3] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);

        if (efi_input_key.UnicodeChar < 0x20)
        {
            if (efi_input_key.UnicodeChar == CHAR_BACKSPACE)
            {
                if (index >= 1)
                {
                    index--;

                    tempBuffer[0] = CHAR_BACKSPACE;
                    tempBuffer[1] = CHAR_NULL;
                    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);
                }
            }
            else if (efi_input_key.UnicodeChar == CHAR_CARRIAGE_RETURN)
            {
                break;
            }

            continue;
        }

        buffer[index++] = efi_input_key.UnicodeChar;

        tempBuffer[0] = efi_input_key.UnicodeChar;
        tempBuffer[1] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);
    }

    buffer[index] = CHAR_NULL;

    tempBuffer[0] = CHAR_CARRIAGE_RETURN;
    tempBuffer[1] = CHAR_LINEFEED;
    tempBuffer[2] = CHAR_NULL;
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);

    return true;
}

#endif
