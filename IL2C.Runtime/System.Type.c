#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Type

IL2C_CONST_STRING(System_Type_ToString_Header, L"Type: ");
System_String* System_Type_ToString(System_Type* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    return System_String_Concat_5(
        System_Type_ToString_Header,
        System_Type_get_FullName(this__));
}

int32_t System_Type_GetHashCode(System_Type* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    return (int32_t)(intptr_t)(this__->type__);
}

bool System_Type_Equals(System_Type* this__, System_Type* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    return this__->type__ == obj->type__;
}

bool System_Type_Equals_1(System_Type* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    System_Type* rhs = il2c_isinst(obj, System_Type);
    if (rhs == NULL)
    {
        return false;
    }

    return this__->type__ == rhs->type__;
}

System_String* System_Type_get_FullName(System_Type* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);
    il2c_assert(this__->type__->pTypeName != NULL);

    return il2c_new_string_from_utf8(this__->type__->pTypeName);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Type_IL2C_RuntimeCast__(System_Type* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Type)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

__System_Type_VTABLE_DECL__ __System_Type_VTABLE__ = {
    /* internalcall */ __System_Type_IL2C_RuntimeCast__,
    System_Type_ToString,
    System_Type_GetHashCode,
    (void(*)(System_Type*))System_Object_Finalize,
    System_Type_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Type_RUNTIME_TYPE__ = {
    "System.Type",
    IL2C_TYPE_STANDARD,
    sizeof(System_Type),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
