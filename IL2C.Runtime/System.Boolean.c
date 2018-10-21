#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Boolean

IL2C_CONST_STRING(System_Boolean_True, L"True");
IL2C_CONST_STRING(System_Boolean_False, L"False");
System_String* System_Boolean_ToString(bool* this__)
{
    return *this__ ? System_Boolean_True : System_Boolean_False;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Boolean_RUNTIME_TYPE__ = {
    "System.Boolean",
    IL2C_TYPE_INTEGER,
    sizeof(System_Boolean),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
