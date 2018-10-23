#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt32

System_String* System_UInt32_ToString(uint32_t* this__)
{
    wchar_t buffer[14];

    il2c_ultow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_UInt32_GetHashCode(uint32_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_UInt32_Equals(uint32_t* this__, uint32_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_UInt32_Equals_1(uint32_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uint32_t rhs = il2c_unbox(obj, System_UInt32);
    return *this__ == rhs;
}

bool System_UInt32_TryParse(System_String* s, uint32_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    *result = il2c_wcstoul(s->string_body__, &endPtr, 10);
    return ((s->string_body__ != endPtr) && (errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_UInt32_IL2C_RuntimeCast__(uint32_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_UInt32)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_UInt32_VTABLE_DECL__ __System_UInt32_VTABLE__ = {
    /* internalcall */ __System_UInt32_IL2C_RuntimeCast__,
    System_UInt32_ToString,
    System_UInt32_GetHashCode,
    (void(*)(System_UInt32*))System_Object_Finalize,
    System_UInt32_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_UInt32_RUNTIME_TYPE__ = {
    "System.UInt32",
    IL2C_TYPE_INTEGER,
    sizeof(System_UInt32),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
