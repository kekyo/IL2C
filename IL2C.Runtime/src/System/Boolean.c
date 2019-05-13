#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Boolean

IL2C_CONST_STRING(System_Boolean_True, L"True");
IL2C_CONST_STRING(System_Boolean_False, L"False");
System_String* System_Boolean_ToString(bool* this__)
{
    return *this__ ? System_Boolean_True : System_Boolean_False;
}

int32_t System_Boolean_GetHashCode(bool* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Boolean_Equals__System_Boolean(bool* this__, bool obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Boolean_Equals__System_Object(bool* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    bool rhs = *il2c_unbox(obj, System_Boolean);
    return *this__ == rhs;
}

bool System_Boolean_TryParse__System_String_System_Boolean_REF(System_String* s, bool* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    if (il2c_wcsicmp(il2c_c_str(s), il2c_c_str(System_Boolean_True)) == 0)
    {
        *result = true;
        return true;
    }
    if (il2c_wcsicmp(il2c_c_str(s), il2c_c_str(System_Boolean_False)) == 0)
    {
        *result = false;
        return true;
    }

    *result = false;
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Boolean);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Boolean);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Boolean,
    "System.Boolean",
    IL2C_TYPE_UNSIGNED_INTEGER,
    sizeof(System_Boolean),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
