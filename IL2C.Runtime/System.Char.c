#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Char

System_String* System_Char_ToString_1(wchar_t* this__)
{
    wchar_t buffer[2];

    buffer[0] = *this__;
    buffer[1] = L'\0';
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Char_RUNTIME_TYPE__ = {
    "System.Char",
    IL2C_TYPE_INTEGER,
    sizeof(System_Char),
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
