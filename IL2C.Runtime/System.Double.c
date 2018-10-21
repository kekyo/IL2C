#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Double

System_String* System_Double_ToString(double* this__)
{
    wchar_t buffer[24];

    il2c_snwprintf(buffer, 24, L"%.15g", *this__);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Double_RUNTIME_TYPE__ = {
    "System.Double",
    IL2C_TYPE_STANDARD,
    sizeof(System_Double),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
