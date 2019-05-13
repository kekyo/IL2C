#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Double

System_String* System_Double_ToString(double* this__)
{
    wchar_t buffer[26];

    il2c_snwprintf(buffer, 26, L"%.15g", *this__);
    return il2c_new_string(buffer);
}

int32_t System_Double_GetHashCode(double* this__)
{
    il2c_assert(this__ != NULL);

    il2c_assert(sizeof(double) == sizeof(int64_t));
    return (int32_t)*(int64_t*)this__ ^ (int32_t)(*(int64_t*)this__ >> 32);
}

bool System_Double_Equals__System_Double(double* this__, double obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Double_Equals__System_Object(double* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    double rhs = *il2c_unbox(obj, System_Double);
    return *this__ == rhs;
}

bool System_Double_TryParse__System_String_System_Double_REF(System_String* s, double* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    double value = il2c_wcstod(s->string_body__, &endPtr);
    *result = value;

    // We have to use a literal value of max instead standard C symbol named *_MAX.
    // Because it's rarely different between .NET and C implementation.
    // Strict value expression from: https://github.com/dotnet/corefx/blob/master/src/Common/src/CoreLib/System/Double.cs

    // TODO: NaN, INF
    return ((s->string_body__ != endPtr) && (il2c_errno == 0) &&
        (value <= 1.7976931348623157E+308) && (value >= -1.7976931348623157E+308)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Double);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Double);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Double,
    "System.Double",
    IL2C_TYPE_VALUE,
    sizeof(System_Double),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
