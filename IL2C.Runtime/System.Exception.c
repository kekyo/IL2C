#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Exception

void System_Exception__ctor(System_Exception* this__)
{
    il2c_assert(this__ != NULL);
}

// TODO:
IL2C_CONST_STRING(System_Exception_message, L"System.Exception");
System_String* System_Exception_ToString(System_Exception* this__)
{
    il2c_assert(this__ != NULL);

    return System_Exception_message;
}

/////////////////////////////////////////////////
// Exception special functions

extern IL2C_EXCEPTION_FRAME* g_pTopUnwindTarget;

void il2c_link_unwind_target__(IL2C_EXCEPTION_FRAME** ppLastUnwindTarget, IL2C_EXCEPTION_FRAME* pUnwindTarget)
{
    il2c_assert(ppLastUnwindTarget != NULL);
    il2c_assert(pUnwindTarget != NULL);

    *ppLastUnwindTarget = g_pTopUnwindTarget;
    g_pTopUnwindTarget = pUnwindTarget;
}

void il2c_unlink_unwind_target__(IL2C_EXCEPTION_FRAME* pLastUnwindTarget)
{
    il2c_assert(pLastUnwindTarget != NULL);

    g_pTopUnwindTarget = pLastUnwindTarget;
}

void il2c_throw__(System_Exception* ex)
{
    il2c_assert(ex != NULL);

    g_pTopUnwindTarget->ex = ex;
    longjmp((void*)g_pTopUnwindTarget->saved, 1);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

__System_Exception_VTABLE_DECL__ __System_Exception_VTABLE__ = {
    /* internalcall */ il2c_isinst__,
    (bool(*)(void*, System_Object*))System_Object_Equals,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Exception_ToString,
};

IL2C_DECLARE_RUNTIME_TYPE(System_Exception, "System.Exception", IL2C_TYPE_REFERENCE, System_Object);
