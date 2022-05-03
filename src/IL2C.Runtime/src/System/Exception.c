#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Exception

void System_Exception__ctor(System_Exception* this__)
{
    il2c_assert(this__ != NULL);
}

void System_Exception__ctor__System_String(System_Exception* this__, System_String* message)
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
    System_String* str = System_String_Concat__System_String_System_String_System_String(typeName, System_Exception_separator, this__->message__);
    return str;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

System_Exception_VTABLE_DECL__ System_Exception_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Object_Equals__System_Object,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String*(*)(void*))System_Exception_ToString,
    (System_String*(*)(void*))System_Exception_get_Message
};

IL2C_RUNTIME_TYPE_BEGIN(
    System_Exception,
    "System.Exception",
    IL2C_TYPE_REFERENCE,
    sizeof(System_Exception),
    System_Object,
    1, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(System_Exception, message__)
IL2C_RUNTIME_TYPE_END();
