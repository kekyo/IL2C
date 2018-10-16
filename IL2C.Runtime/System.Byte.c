#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Byte

System_String* System_Byte_ToString(uint8_t* this__)
{
    wchar_t buffer[5];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE__ = {
    "System.Byte", sizeof(System_Byte), /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
