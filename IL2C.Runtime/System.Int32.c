#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int32

System_String* System_Int32_ToString(int32_t* this__)
{
    il2c_assert(this__ != NULL);

    wchar_t buffer[14];
    
    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Int32_GetHashCode(int32_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Int32_Equals(int32_t* this__, int32_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Int32_Equals_1(int32_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int32_t rhs = il2c_unbox(obj, System_Int32);
    return *this__ == rhs;
}

bool System_Int32_TryParse(System_String* s, int32_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

	*result = wcstol(s->string_body__, &endPtr, 10);
	return ((s->string_body__ != endPtr) && (errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Int32_IL2C_RuntimeCast__(int32_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Int32)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Int32_VTABLE_DECL__ __System_Int32_VTABLE__ = {
    /* internalcall */ __System_Int32_IL2C_RuntimeCast__,
    System_Int32_ToString,
    System_Int32_GetHashCode,
    (void(*)(System_Int32*))System_Object_Finalize,
    System_Int32_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE__ = {
    "System.Int32",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int32),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
