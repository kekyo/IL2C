#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt16

System_String* System_UInt16_ToString(uint16_t* this__)
{
    wchar_t buffer[7];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_UInt16_RUNTIME_TYPE__ = {
    "System.UInt16",
    IL2C_TYPE_INTEGER,
    sizeof(System_UInt16),
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
