#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Byte

System_String* System_Byte_ToString(uint8_t* this__)
{
    wchar_t buffer[5];

    il2c_itow(*this__, buffer, 4);
    return il2c_new_string(buffer);
}

int32_t System_Byte_GetHashCode(uint8_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Byte_Equals(uint8_t* this__, uint8_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Byte_Equals_1(uint8_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uint8_t rhs = *il2c_unbox(obj, System_Byte);
    return *this__ == rhs;
}

bool System_Byte_TryParse(System_String* s, uint8_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    unsigned long value = il2c_wcstoul(s->string_body__, &endPtr, 10);
    *result = (uint8_t)value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    return ((s->string_body__ != endPtr) && (errno == 0) && (value <= 255)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Byte);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Byte);

IL2C_RUNTIME_TYPE_BEGIN(System_Byte, "System.Byte", IL2C_TYPE_UNSIGNED_INTEGER, sizeof(System_Byte), System_ValueType, 0, 0)
IL2C_RUNTIME_TYPE_END();
