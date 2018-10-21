#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt64

System_String* System_UInt64_ToString(uint64_t* this__)
{
    wchar_t buffer[24];

    il2c_ui64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_UInt64_RUNTIME_TYPE__ = {
    "System.UInt64",
    IL2C_TYPE_INTEGER,
    sizeof(System_UInt64),
    &__System_ValueType_VTABLE__,  // TODO:
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
