#include <il2c_private.h>

#include "efi/efi.h"

//////////////////////////////////////////////////
// Visual C++

// UEFI
#if defined(_MSC_VER) && defined(UEFI)

static EFI_SYSTEM_TABLE* g_pSystemTable = NULL;

#if 0
// Can't enable intrinsic inlined memcpy/memset with VC++'s /GL and /LTCG options.
// So these are simple implementations for thiers.
void* il2c_memcpy(void* to, const void* from, size_t n)
{
    uint8_t* t = to;
    const uint8_t* f = from;
    n++;
    while (--n >= 1)
        *t++ = *f++;
    return to;
}

void* il2c_memset(void* target, int ch, size_t n)
{
    uint8_t* p = target;
    n++;
    while (--n >= 1)
        *p++ = ch;
    return target;
}
#endif

bool il2c_twtoi(const wchar_t *_Str, int32_t* value)
{
    char sign = 0;

    for (;; _Str++)
    {
        wchar_t ch = *_Str;
        if ((ch == L' ') || (ch == L'\t'))
        {
            continue;
        }

        if (ch == L'-')
        {
            sign = -1;
            _Str++;
        }
        else if (ch == L'+')
        {
            sign = 1;
            _Str++;
        }
        else if ((*_Str < L'0') || (*_Str > L'9'))
        {
            return false;
        }

        break;
    }

    bool f = false;
    int32_t n = 0;
    while ((*_Str >= L'0') && (*_Str <= L'9'))
    {
        n = n * 10 + *_Str++ - L'0';
        f = true;
    }

    if (!f) return false;

    if (sign != 0) *value = sign * n;
    else *value = n;

    return true;
}

void il2c_itow(int32_t value, wchar_t* p)
{
    wchar_t *j;
    wchar_t b[6];

    if (value < 0)
    {
        *p++ = L'-';
        value = -value;
    }

    j = &b[5];
    *j-- = 0;

    do
    {
        *j-- = value % 10 + L'0';
        value /= 10;
    } while (value);

    do
    {
        *p++ = *++j;
    } while (*j);
}

char* il2c_itoa(int i, char* d)
{
    char *j, *a = d;
    char b[6];

    if (i < 0)
    {
        *a++ = '-';
        i = -i;
    }
    j = &b[5];
    *j-- = 0;
    do
    {
        *j-- = i % 10 + '0';
        i /= 10;
    } while (i);
    do
    {
        *a++ = *++j;
    } while (*j);

    return d;
}

void* il2c_malloc(size_t _Size)
{
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

void il2c_free(void* _Block)
{
    g_pSystemTable->BootServices->FreePool(_Block);
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

void il2c_debug_write(const char* format, ...)
{
    va_list va;
    char buffer[128];

    va_start(va, format);
    il2c_assert(format != NULL);
    vsprintf(buffer, format, va);
    g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, (wchar_t*)pMessage);
    g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, L"\r\n");
    va_end(va);
}

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (wchar_t*)pMessage);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (wchar_t*)pMessage);
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);

    while ((index + 1) < length)
    {
        unsigned long long waitIndex;

        buffer[0] = L'_';
        buffer[1] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);

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

        buffer[0] = CHAR_BACKSPACE;
        buffer[1] = L' ';
        buffer[2] = CHAR_BACKSPACE;
        buffer[3] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);

        if (efi_input_key.UnicodeChar < 0x20)
        {
            if (efi_input_key.UnicodeChar == CHAR_BACKSPACE)
            {
                if (index >= 1)
                {
                    index--;

                    buffer[0] = CHAR_BACKSPACE;
                    buffer[1] = CHAR_NULL;
                    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);
                }
            }
            else if (efi_input_key.UnicodeChar == CHAR_CARRIAGE_RETURN)
            {
                break;
            }

            continue;
        }

        pBuffer[index++] = efi_input_key.UnicodeChar;

        buffer[0] = efi_input_key.UnicodeChar;
        buffer[1] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);
    }

    pBuffer[index] = CHAR_NULL;

    buffer[0] = CHAR_CARRIAGE_RETURN;
    buffer[1] = CHAR_LINEFEED;
    buffer[2] = CHAR_NULL;
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);

    return true;
}

void il2c_initialize(void* imageHandle, void* pSystemTable)
{
    // Setup interop pointer
    g_pSystemTable = pSystemTable;

    // Disable default auto-reset watchdog timer
    g_pSystemTable->BootServices->SetWatchdogTimer(0, 0, 0, NULL);

    // Clear screen
    //g_pSystemTable->ConOut->ClearScreen(g_pSystemTable->ConOut);

    il2c_initialize__();
}

void il2c_shutdown()
{
    il2c_shutdown__();
}

#endif
