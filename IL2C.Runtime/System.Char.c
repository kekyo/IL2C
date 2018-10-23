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

    return *this__;
}

bool System_Char_Equals(wchar_t* this__, wchar_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Char_Equals_1(wchar_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    wchar_t rhs = il2c_unbox(obj, System_Char);
    return *this__ == rhs;
}

bool System_Char_TryParse(System_String* s, wchar_t* result)
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

void* __System_Char_IL2C_RuntimeCast__(wchar_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Char)) return this__;

    // BUG: TODO: All value types are invalid upcasting to ValueType type.
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Char_VTABLE_DECL__ __System_Char_VTABLE__ = {
    /* internalcall */ __System_Char_IL2C_RuntimeCast__,
    System_Char_ToString,
    System_Char_GetHashCode,
    (void(*)(System_Char*))System_Object_Finalize,
    System_Char_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Char_RUNTIME_TYPE__ = {
    "System.Char",
    IL2C_TYPE_INTEGER,
    sizeof(System_Char),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
