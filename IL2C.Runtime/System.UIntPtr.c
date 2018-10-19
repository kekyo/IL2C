#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UIntPtr

const System_UIntPtr System_UIntPtr_Zero = 0;

System_String* System_UIntPtr_ToString(uintptr_t* this__)
{
    wchar_t buffer[24];

    il2c_ui64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_UIntPtr_RUNTIME_TYPE__ = {
    "System.UIntPtr",
    IL2C_TYPE_INTEGER,
    sizeof(System_UIntPtr),
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
