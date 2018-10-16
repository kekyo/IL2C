#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int32

System_String* System_Int32_ToString(int32_t* this__)
{
    wchar_t buffer[14];
    
    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

bool System_Int32_TryParse(System_String* s, int32_t* result)
{
	wchar_t* endPtr;

    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

	*result = wcstol(s->string_body__, &endPtr, 10);
	return ((s->string_body__ != endPtr) && (errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE__ = {
    "System.Int32", sizeof(System_Int32), /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
