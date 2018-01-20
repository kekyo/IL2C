#include "Generated/UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from
//   https://github.com/cupnes/bare_metal_uefi/blob/master/020_echoback/BOOTX64.c

typedef unsigned long long EFI_STATUS;
typedef void *EFI_HANDLE;

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
		void *_buf;
		EFI_STATUS (*ReadKeyStroke)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *, EFI_INPUT_KEY*);
	} *ConIn;

	void *_buf2;

	struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
		void *_buf;
		EFI_STATUS (*OutputString)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *, const wchar_t*);
	} *ConOut;

	unsigned long long _buf3[3];

	struct EFI_BOOT_SERVICES {
		char _buf1[24];

		// Task Priority Services
		unsigned long long _buf2[2];

		unsigned long long _buf3[3];

		// Memory Services
		EFI_STATUS (*AllocatePool)(
			EFI_MEMORY_TYPE PoolType,
			unsigned long long Size,
			void **Buffer);
		EFI_STATUS (*FreePool)(
			void *Buffer);
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

void ReadLine(wchar_t* pBuffer, size_t length)
{
	wchar_t buffer[] = { L'\0', L'\0', L'\0' };
	uint32_t index = 0;

	while ((index + 1) < length)
	{
		EFI_INPUT_KEY efi_input_key;
		g_pSystemTable->ConIn->ReadKeyStroke(g_pSystemTable->ConIn, &efi_input_key);

		if (efi_input_key.UnicodeChar == L'\r')
		{
			break;
		}

		pBuffer[index] = efi_input_key.UnicodeChar;

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

	__gc_initialize__();

	UEFI_Code_PolishNotation_Main();

	__gc_shutdown__();

	return 0;
}
