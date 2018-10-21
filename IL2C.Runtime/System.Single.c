#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Single

System_String* System_Single_ToString(float* this__)
{
    wchar_t buffer[14];

    il2c_snwprintf(buffer, 14, L"%.7g", *this__);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Single_RUNTIME_TYPE__ = {
    "System.Single",
    IL2C_TYPE_STANDARD,
    sizeof(System_Single),
    &__System_ValueType_VTABLE__,  // TODO:
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
