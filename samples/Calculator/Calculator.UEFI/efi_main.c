
#include <Calculator.Core.h>

#include <stdint.h>

//////////////////////////////////////////////////////////////////////////
// UEFI interface: code refer from

uintptr_t efi_main(
    void* imageHandle,
    void* pSystemTable)
{
    il2c_initialize(imageHandle, pSystemTable);

    Calculator_PolishNotation_Main();

    il2c_shutdown();

    return 0;
}
