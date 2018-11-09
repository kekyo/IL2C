#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Exception

void System_Exception__ctor(System_Exception* this__)
{
    il2c_assert(this__ != NULL);
}

void System_Exception__ctor_1(System_Exception* this__, System_String* message)
{
    il2c_assert(this__ != NULL);

    // The message argument doesn't check
    this__->message__ = message;
}

System_String* System_Exception_get_Message(System_Exception* this__)
{
    il2c_assert(this__ != NULL);

    return this__->message__;
}

IL2C_CONST_STRING(System_Exception_separator, L": ");
System_String* System_Exception_ToString(System_Exception* this__)
{
    il2c_assert(this__ != NULL);

    // TODO: We have to generate the stack trace? can do that?
    System_Type* type = System_Object_GetType((System_Object*)this__);
    System_String* typeName = System_Type_get_FullName(type);
    System_String* str = System_String_Concat_5(typeName, System_Exception_separator, this__->message__);
    return str;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void __System_Exception_IL2C_MarkHandler__(System_Exception* this__)
{
    il2c_assert(this__ != NULL);

    il2c_try_mark_from_handler(this__->message__);
}

__System_Exception_VTABLE_DECL__ __System_Exception_VTABLE__ = {
    /* internalcall */ il2c_isinst__,
    (bool(*)(void*, System_Object*))System_Object_Equals,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String*(*)(void*))System_Exception_ToString,
    (System_String*(*)(void*))System_Exception_get_Message,
};

IL2C_DECLARE_RUNTIME_TYPE(System_Exception, "System.Exception", IL2C_TYPE_REFERENCE, System_Object);
