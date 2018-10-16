#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt32

System_String* System_UInt32_ToString(uint32_t* this__)
{
    wchar_t buffer[14];

    il2c_ultow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_UInt32_RUNTIME_TYPE__ = {
    "System.UInt32", sizeof(System_UInt32), /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
