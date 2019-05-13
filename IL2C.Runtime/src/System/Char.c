#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Char

System_String* System_Char_ToString(wchar_t* this__)
{
    wchar_t buffer[2];

    buffer[0] = *this__;
    buffer[1] = L'\0';
    return il2c_new_string(buffer);
}

int32_t System_Char_GetHashCode(wchar_t* this__)
{
    il2c_assert(this__ != NULL);

    return (int32_t)*this__;
}

bool System_Char_Equals__System_Char(wchar_t* this__, wchar_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Char_Equals__System_Object(wchar_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    wchar_t rhs = *il2c_unbox(obj, System_Char);
    return *this__ == rhs;
}

bool System_Char_TryParse__System_String_System_Char_REF(System_String* s, wchar_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t ch = *(s->string_body__);
    *result = ch;
    return ch != L'\0';
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Char);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Char);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Char,
    "System.Char",
    IL2C_TYPE_UNSIGNED_INTEGER,
    sizeof(System_Char),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
