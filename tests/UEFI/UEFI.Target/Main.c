#include "Generated/UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from
//   https://github.com/cupnes/bare_metal_uefi/blob/master/020_echoback/BOOTX64.c

typedef unsigned long long EFI_STATUS;
typedef void *EFI_HANDLE;

struct EFI_INPUT_KEY {
	unsigned short ScanCode;
	unsigned short UnicodeChar;
};

enum EFI_MEMORY_TYPE {
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
};

typedef struct {
	char _buf1[44];
	struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
		void *_buf;
		EFI_STATUS (*ReadKeyStroke)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *, struct EFI_INPUT_KEY *);
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
		// Memory Services
		unsigned long long _buf3[3];
		EFI_STATUS (*AllocatePool)(
			enum EFI_MEMORY_TYPE PoolType,
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

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from

EFI_STATUS EfiMain(
	EFI_HANDLE imageHandle,
	EFI_SYSTEM_TABLE* pSystemTable)
{
	// Setup interop pointer
	g_pSystemTable = pSystemTable;

	struct EFI_INPUT_KEY efi_input_key;
	unsigned short str[3];

	while (1) {
		if (!pSystemTable->ConIn->ReadKeyStroke(pSystemTable->ConIn, &efi_input_key)) {
			if (efi_input_key.UnicodeChar != L'\r') {
				str[0] = efi_input_key.UnicodeChar;
				str[1] = L'\0';
			}
			else {
				str[0] = L'\r';
				str[1] = L'\n';
				str[2] = L'\0';
			}
			pSystemTable->ConOut->OutputString(pSystemTable->ConOut, str);
		}
	}

	return 0;
}
