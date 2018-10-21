#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int16

System_String* System_Int16_ToString(int16_t* this__)
{
    wchar_t buffer[7];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Int16_RUNTIME_TYPE__ = {
    "System.Int16",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int16),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
