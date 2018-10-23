#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int64

System_String* System_Int64_ToString(int64_t* this__)
{
    wchar_t buffer[24];

    il2c_i64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Int64_GetHashCode(int64_t* this__)
{
    il2c_assert(this__ != NULL);

    return (int32_t)*this__ ^ (int32_t)(*this__ >> 32);
}

bool System_Int64_Equals(int64_t* this__, int64_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Int64_Equals_1(int64_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int64_t rhs = il2c_unbox(obj, System_Int64);
    return *this__ == rhs;
}

bool System_Int64_TryParse(System_String* s, int64_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    *result = il2c_wcstoll(s->string_body__, &endPtr, 10);
    return ((s->string_body__ != endPtr) && (errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Int64_IL2C_RuntimeCast__(int64_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Int64)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Int64_VTABLE_DECL__ __System_Int64_VTABLE__ = {
    /* internalcall */ __System_Int64_IL2C_RuntimeCast__,
    System_Int64_ToString,
    System_Int64_GetHashCode,
    (void(*)(System_Int64*))System_Object_Finalize,
    System_Int64_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Int64_RUNTIME_TYPE__ = {
    "System.Int64",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int64),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
