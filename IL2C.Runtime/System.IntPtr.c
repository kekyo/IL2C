#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.IntPtr

const System_IntPtr System_IntPtr_Zero = 0;

System_String* System_IntPtr_ToString(intptr_t* this__)
{
    wchar_t buffer[24];

    il2c_i64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_IntPtr_RUNTIME_TYPE__ = {
    "System.IntPtr", sizeof(System_IntPtr), /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
