#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Single

System_String* System_Single_ToString(float* this__)
{
    wchar_t buffer[14];

    il2c_snwprintf(buffer, 14, L"%.7g", *this__);
    return il2c_new_string(buffer);
}

int32_t System_Single_GetHashCode(float* this__)
{
    il2c_assert(this__ != NULL);

    il2c_assert(sizeof(float) == sizeof(int32_t));
    return *(int32_t*)this__;
}

bool System_Single_Equals(float* this__, float obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Single_Equals_1(float* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    float rhs = il2c_unbox(obj, System_Single);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Single_IL2C_RuntimeCast__(float* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Single)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Single_VTABLE_DECL__ __System_Single_VTABLE__ = {
    /* internalcall */ __System_Single_IL2C_RuntimeCast__,
    System_Single_ToString,
    System_Single_GetHashCode,
    (void(*)(System_Single*))System_Object_Finalize,
    System_Single_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Single_RUNTIME_TYPE__ = {
    "System.Single",
    IL2C_TYPE_STANDARD,
    sizeof(System_Single),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
