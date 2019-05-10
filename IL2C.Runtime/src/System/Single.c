#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Single

System_String* System_Single_ToString(float* this__)
{
    wchar_t buffer[16];

    il2c_snwprintf(buffer, 16, L"%.7g", *this__);
    return il2c_new_string(buffer);
}

int32_t System_Single_GetHashCode(float* this__)
{
    il2c_assert(this__ != NULL);

    il2c_assert(sizeof(float) == sizeof(int32_t));
    return *(int32_t*)this__;
}

bool System_Single_Equals__System_Single(float* this__, float obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Single_Equals__System_Object(float* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    float rhs = *il2c_unbox(obj, System_Single);
    return *this__ == rhs;
}

bool System_Single_TryParse__System_String_System_Single_REF(System_String* s, float* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    float value = il2c_wcstof(s->string_body__, &endPtr);
    *result = value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    // Strict value expression from: https://github.com/dotnet/corefx/blob/master/src/Common/src/CoreLib/System/Single.cs

    // TODO: NaN, INF
    return ((s->string_body__ != endPtr) && (il2c_errno == 0) &&
        (value <= (float)3.40282346638528859e+38) && (value >= (float)-3.40282346638528859e+38)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Single);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Single);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Single,
    "System.Single",
    IL2C_TYPE_VALUE,
    sizeof(System_Single),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
