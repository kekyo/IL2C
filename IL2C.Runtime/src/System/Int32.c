#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int32

System_String* System_Int32_ToString(int32_t* this__)
{
    il2c_assert(this__ != NULL);

    wchar_t buffer[14];
    
    il2c_i32tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Int32_GetHashCode(int32_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Int32_Equals__System_Int32(int32_t* this__, int32_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Int32_Equals__System_Object(int32_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int32_t rhs = *il2c_unbox(obj, System_Int32);
    return *this__ == rhs;
}

bool System_Int32_TryParse__System_String_System_Int32_REF(System_String* s, int32_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    *result = il2c_wtoi32(s->string_body__, &endPtr, 10);
    return ((s->string_body__ != endPtr) && (il2c_errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Int32);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Int32);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Int32,
    "System.Int32",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int32),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
