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

bool System_Boolean_Equals(bool* this__, bool obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Boolean_Equals_1(bool* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    bool rhs = il2c_unbox(obj, System_Boolean);
    return *this__ == rhs;
}

bool System_Boolean_TryParse(System_String* s, bool* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    if (wcsicmp(il2c_c_str(s), il2c_c_str(System_Boolean_True)) == 0)
    {
        *result = true;
        return true;
    }
    if (wcsicmp(il2c_c_str(s), il2c_c_str(System_Boolean_False)) == 0)
    {
        *result = false;
        return true;
    }

    *result = false;
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Boolean_IL2C_RuntimeCast__(bool* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Boolean)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Boolean_VTABLE_DECL__ __System_Boolean_VTABLE__ = {
    /* internalcall */ __System_Boolean_IL2C_RuntimeCast__,
    System_Boolean_ToString,
    System_Boolean_GetHashCode,
    (void(*)(System_Boolean*))System_Object_Finalize,
    System_Boolean_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Boolean_RUNTIME_TYPE__ = {
    "System.Boolean",
    IL2C_TYPE_INTEGER,
    sizeof(System_Boolean),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
