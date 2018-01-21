#include "Generated/UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from
//   https://github.com/cupnes/bare_metal_uefi/blob/master/020_echoback/BOOTX64.c

typedef unsigned long long EFI_STATUS;
typedef void* EFI_HANDLE;
typedef void* EFI_EVENT;

typedef struct {
	unsigned short ScanCode;
	wchar_t UnicodeChar;
} EFI_INPUT_KEY;

typedef enum {
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef struct {
	char _buf1[44];

	struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
		void* _buf;
		EFI_STATUS (*ReadKeyStroke)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL*, EFI_INPUT_KEY*);
		EFI_EVENT WaitForKey;
	}* ConIn;

	void* _buf2;

	struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
		void* _buf;
		EFI_STATUS (*OutputString)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*, const wchar_t*);
		unsigned long long _buf2[4];
		EFI_STATUS (*ClearScreen)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*);
	}* ConOut;

	unsigned long long _buf3[3];

	struct EFI_BOOT_SERVICES {
		char _buf1[24];

		// Task Priority Services
		unsigned long long _buf2[2];

		// Memory Services
		unsigned long long _buf3[3];

		EFI_STATUS (*AllocatePool)(
			EFI_MEMORY_TYPE PoolType,
			unsigned long long Size,
			void **Buffer);
		EFI_STATUS (*FreePool)(
			void *Buffer);

		// Event & Timer Services
		unsigned long long _buf4[2];

		EFI_STATUS (*WaitForEvent)(
			unsigned long long NumberOfEvents,
			EFI_EVENT* Event,
			unsigned long long* Index);
	} *BootServices;
} EFI_SYSTEM_TABLE;

//////////////////////////////////////////////////////////////////////////
// IL2C <---> UEFI interop functions

static EFI_SYSTEM_TABLE* g_pSystemTable = NULL;

void __cdecl _wassert(
	wchar_t const* _Message,
	wchar_t const* _File,
	unsigned _Line)
{
	// TODO:
}

void* __cdecl malloc(size_t _Size)
{
	void* ppAllocated = NULL;
	if (g_pSystemTable->BootServices->AllocatePool(
		EfiLoaderData, _Size, &ppAllocated))
	{
		return ppAllocated;
	}
	else
	{
		return NULL;
	}
}

void __cdecl free(void* _Block)
{
	g_pSystemTable->BootServices->FreePool(_Block);
}

int wtoi(const wchar_t *_Str)
{
	bool sign = false;

	for (;; _Str++)
	{
		wchar_t ch = *_Str;
		if ((ch == L' ') || (ch == L'\t'))
		{
			continue;
		}

		if (ch == L'-')
		{
			sign = true;
			_Str++;
		}
		else if (ch == L'+')
		{
			_Str++;
		}

		break;
	}

	int n = 0;
	while ((*_Str >= L'0') && (*_Str <= L'9'))
	{
		n = n * 10 + *_Str++ - L'0';
	}

	return sign ? -n : n;
}

void ReadLine(wchar_t* pBuffer, uint16_t length)
{
	wchar_t buffer[] = { L'\0', L'\0', L'\0' };
	uint16_t index = 0;

	while ((index + 1) < length)
	{
		unsigned long long waitIndex = 0;
		g_pSystemTable->BootServices->WaitForEvent(
			1, &(g_pSystemTable->ConIn->WaitForKey), &waitIndex);

		EFI_INPUT_KEY efi_input_key;
		if (g_pSystemTable->ConIn->ReadKeyStroke(
			g_pSystemTable->ConIn, &efi_input_key) != 0)
		{
			continue;
		}

		if (efi_input_key.UnicodeChar == L'\r')
		{
			break;
		}

		pBuffer[index++] = efi_input_key.UnicodeChar;

		buffer[0] = efi_input_key.UnicodeChar;
		g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);
	}

	pBuffer[index] = L'\0';

	buffer[0] = L'\r';
	buffer[1] = L'\n';

	g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, buffer);
}

void Write(wchar_t const* pMessage)
{
	g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, pMessage);
}

void WriteLine(wchar_t const* pMessage)
{
	g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, pMessage);
	g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
}

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from

EFI_STATUS EfiMain(
	EFI_HANDLE imageHandle,
	EFI_SYSTEM_TABLE* pSystemTable)
{
	// Setup interop pointer
	g_pSystemTable = pSystemTable;

	g_pSystemTable->ConOut->ClearScreen(g_pSystemTable->ConOut);

	__gc_initialize__();

	UEFI_Code_PolishNotation_Main();

	__gc_shutdown__();

	return 0;
}
