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

System_Type* System_Type_get_BaseType(System_Type* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    if (this__->type__->baseType == NULL)
    {
        return NULL;
    }

    System_Type* pType = il2c_get_uninitialized_object(System_Type);
    pType->type__ = this__->type__->baseType;

    return pType;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_OBJECT_VTABLE(System_Type);
IL2C_DECLARE_RUNTIME_TYPE(System_Type, "System.Type", IL2C_TYPE_STANDARD, System_Object);
