#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.SByte

System_String* System_SByte_ToString(int8_t* this__)
{
    wchar_t buffer[5];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_SByte_GetHashCode(int8_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_SByte_Equals(int8_t* this__, int8_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_SByte_Equals_1(int8_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int8_t rhs = il2c_unbox(obj, System_SByte);
    return *this__ == rhs;
}

bool System_SByte_TryParse(System_String* s, int8_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    long value = il2c_wcstol(s->string_body__, &endPtr, 10);
    *result = (int8_t)value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    return ((s->string_body__ != endPtr) && (errno == 0) && (value <= 127) && (value >= -128)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_SByte_IL2C_RuntimeCast__(int8_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_SByte)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_SByte_VTABLE_DECL__ __System_SByte_VTABLE__ = {
    /* internalcall */ __System_SByte_IL2C_RuntimeCast__,
    System_SByte_ToString,
    System_SByte_GetHashCode,
    (void(*)(System_SByte*))System_Object_Finalize,
    System_SByte_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE__ = {
    "System.SByte",
    IL2C_TYPE_INTEGER,
    sizeof(System_SByte),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
