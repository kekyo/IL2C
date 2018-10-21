#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int64

System_String* System_Int64_ToString(int64_t* this__)
{
    wchar_t buffer[24];

    il2c_i64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Int64_RUNTIME_TYPE__ = {
    "System.Int64",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int64),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
