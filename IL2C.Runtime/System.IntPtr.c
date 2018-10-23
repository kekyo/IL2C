#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.IntPtr

const intptr_t System_IntPtr_Zero = (intptr_t)0;

System_String* System_IntPtr_ToString(intptr_t* this__)
{
    wchar_t buffer[24];

    il2c_i64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_IntPtr_GetHashCode(intptr_t* this__)
{
    il2c_assert(this__ != NULL);

    int64_t value = *this__;
    return (int32_t)value ^ (int32_t)(value >> 32);
}

bool System_IntPtr_Equals(intptr_t* this__, intptr_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_IntPtr_Equals_1(intptr_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    intptr_t rhs = il2c_unbox(obj, System_IntPtr);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_IntPtr_IL2C_RuntimeCast__(intptr_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_IntPtr)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_IntPtr_VTABLE_DECL__ __System_IntPtr_VTABLE__ = {
    /* internalcall */ __System_IntPtr_IL2C_RuntimeCast__,
    System_IntPtr_ToString,
    System_IntPtr_GetHashCode,
    (void(*)(System_IntPtr*))System_Object_Finalize,
    System_IntPtr_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_IntPtr_RUNTIME_TYPE__ = {
    "System.IntPtr",
    IL2C_TYPE_INTEGER,
    sizeof(System_IntPtr),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
