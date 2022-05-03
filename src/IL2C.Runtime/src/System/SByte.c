#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.SByte

System_String* System_SByte_ToString(int8_t* this__)
{
    il2c_assert(this__ != NULL);

    wchar_t buffer[5];

    il2c_i32tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_SByte_GetHashCode(int8_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_SByte_Equals__System_SByte(int8_t* this__, int8_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_SByte_Equals__System_Object(int8_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int8_t rhs = *il2c_unbox(obj, System_SByte);
    return *this__ == rhs;
}

bool System_SByte_TryParse__System_String_System_SByte_REF(System_String* s, int8_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    long value = il2c_wtoi32(s->string_body__, &endPtr, 10);
    *result = (int8_t)value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    return ((s->string_body__ != endPtr) && (il2c_errno == 0) && (value <= 127) && (value >= -128)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_SByte);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_SByte);

IL2C_RUNTIME_TYPE_BEGIN(
    System_SByte,
    "System.SByte",
    IL2C_TYPE_INTEGER,
    sizeof(System_SByte),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
