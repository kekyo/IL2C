#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt16

System_String* System_UInt16_ToString(uint16_t* this__)
{
    wchar_t buffer[7];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_UInt16_GetHashCode(uint16_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_UInt16_Equals(uint16_t* this__, uint16_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_UInt16_Equals_1(uint16_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uint16_t rhs = *il2c_unbox(obj, System_UInt16);
    return *this__ == rhs;
}

bool System_UInt16_TryParse(System_String* s, uint16_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    unsigned long value = il2c_wcstoul(s->string_body__, &endPtr, 10);
    *result = (uint16_t)value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    return ((s->string_body__ != endPtr) && (errno == 0) && (value <= 65535)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_UInt16);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_UInt16);

IL2C_RUNTIME_TYPE_BEGIN(System_UInt16, "System.UInt16", IL2C_TYPE_UNSIGNED_INTEGER, sizeof(System_UInt16), System_ValueType, 0, 0)
IL2C_RUNTIME_TYPE_END();
