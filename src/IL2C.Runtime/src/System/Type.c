#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Type

//IL2C_CONST_STRING(System_Type_ToString_Header, L"Type: ");
System_String* System_Type_ToString(System_Type* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    // System.Type.ToString() implementation has concatenation for "Type: " header, but the System.RuntimeType do not.
    return System_Type_get_FullName(this__);
    //return System_String_Concat_5(
    //    System_Type_ToString_Header,
    //    System_Type_get_FullName(this__));
}

int32_t System_Type_GetHashCode(System_Type* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    return (int32_t)(intptr_t)(this__->type__);
}

bool System_Type_Equals__System_Type(System_Type* this__, System_Type* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->type__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    return this__->type__ == obj->type__;
}

bool System_Type_Equals__System_Object(System_Type* this__, System_Object* obj)
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

System_Type_VTABLE_DECL__ System_Type_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Type_Equals__System_Object,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Type_GetHashCode,
    (System_String* (*)(void*))System_Type_ToString,
    (System_Type*(*)(void*))System_Type_get_BaseType,
    (System_String*(*)(void*))System_Type_get_FullName,
};

IL2C_RUNTIME_TYPE_BEGIN(
    System_Type,
    "System.Type",
    IL2C_TYPE_REFERENCE,
    sizeof(System_Type),
    System_Object,
    0, 0)
IL2C_RUNTIME_TYPE_END();
