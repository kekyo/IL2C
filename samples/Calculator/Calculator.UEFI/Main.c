
#include <Calculator.Core.h>

#include <efi.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

//////////////////////////////////////////////////////////////////////////
// IL2C <---> UEFI interop functions

static EFI_SYSTEM_TABLE* g_pSystemTable = NULL;

void Write(const wchar_t* pMessage)
{
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (wchar_t*)pMessage);
}

void WriteLine(const wchar_t* pMessage)
{
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (wchar_t*)pMessage);
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
}

void WriteLineToError(const wchar_t* pMessage)
{
    g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, (wchar_t*)pMessage);
    g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, L"\r\n");
}

void ReadLine(wchar_t* pBuffer, uint16_t length)
{
    wchar_t buffer[4];
    uint16_t index = 0;

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

void SendExternalTicker(const wchar_t* message)
{
    WriteLineToError(message);
}

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from

EFI_STATUS EfiMain(
    EFI_HANDLE imageHandle,
    EFI_SYSTEM_TABLE* pSystemTable)
{
    // Setup interop pointer
    g_pSystemTable = pSystemTable;

    // Disable default auto-reset watchdog timer
    g_pSystemTable->BootServices->SetWatchdogTimer(0, 0, 0, NULL);

    // Clear screen
    g_pSystemTable->ConOut->ClearScreen(g_pSystemTable->ConOut);

    il2c_initialize();

    Calculator_PolishNotation_Main();

    il2c_shutdown();

    return 0;
}
