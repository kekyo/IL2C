#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.IntPtr

const intptr_t System_IntPtr_Zero = (intptr_t)0;

System_String* System_IntPtr_ToString(intptr_t* this__)
{
    il2c_assert(this__ != NULL);

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

bool System_IntPtr_Equals__System_IntPtr(intptr_t* this__, intptr_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_IntPtr_Equals__System_Object(intptr_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    intptr_t rhs = *il2c_unbox(obj, System_IntPtr);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_IntPtr);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_IntPtr);

IL2C_RUNTIME_TYPE_BEGIN(
    System_IntPtr,
    "System.IntPtr",
    IL2C_TYPE_INTEGER,
    sizeof(System_IntPtr),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
