#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int16

System_String* System_Int16_ToString(int16_t* this__)
{
    wchar_t buffer[7];

    il2c_i32tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Int16_GetHashCode(int16_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Int16_Equals__System_Int16(int16_t* this__, int16_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Int16_Equals__System_Object(int16_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int16_t rhs = *il2c_unbox(obj, System_Int16);
    return *this__ == rhs;
}

bool System_Int16_TryParse__System_String_System_Int16_REF(System_String* s, int16_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    long value = il2c_wtoi32(s->string_body__, &endPtr, 10);
    *result = (int16_t)value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    return ((s->string_body__ != endPtr) && (il2c_errno == 0) && (value <= 32767) && (value >= -32768)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Int16);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Int16);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Int16,
    "System.Int16",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int16),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
