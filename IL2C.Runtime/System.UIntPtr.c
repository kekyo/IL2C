#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UIntPtr

const uintptr_t System_UIntPtr_Zero = (uintptr_t)0;

System_String* System_UIntPtr_ToString(uintptr_t* this__)
{
    wchar_t buffer[24];

    il2c_ui64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_UIntPtr_GetHashCode(uintptr_t* this__)
{
    il2c_assert(this__ != NULL);

    uint64_t value = *this__;
    return (int32_t)value ^ (int32_t)(value >> 32);
}

bool System_UIntPtr_Equals(uintptr_t* this__, uintptr_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_UIntPtr_Equals_1(uintptr_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uintptr_t rhs = il2c_unbox(obj, System_UIntPtr);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_UIntPtr_IL2C_RuntimeCast__(uintptr_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_UIntPtr)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_UIntPtr_VTABLE_DECL__ __System_UIntPtr_VTABLE__ = {
    /* internalcall */ __System_UIntPtr_IL2C_RuntimeCast__,
    System_UIntPtr_ToString,
    System_UIntPtr_GetHashCode,
    (void(*)(System_UIntPtr*))System_Object_Finalize,
    System_UIntPtr_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_UIntPtr_RUNTIME_TYPE__ = {
    "System.UIntPtr",
    IL2C_TYPE_INTEGER,
    sizeof(System_UIntPtr),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
