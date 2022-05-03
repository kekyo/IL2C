#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.AppDomain

void System_AppDomain_add_UnhandledException__System_UnhandledExceptionEventHandler(System_AppDomain* this__, System_UnhandledExceptionEventHandler* value)
{
    il2c_assert(this__ != NULL);

    // TODO: ArgumentNullException
    il2c_assert(value != NULL);

    this__->unhandledExceptionEventHandler__ =
        (System_UnhandledExceptionEventHandler*)System_Delegate_Combine__System_Delegate_System_Delegate(
            (System_Delegate*)this__->unhandledExceptionEventHandler__,
            (System_Delegate*)value);
}

void System_AppDomain_remove_UnhandledException__System_UnhandledExceptionEventHandler(System_AppDomain* this__, System_UnhandledExceptionEventHandler* value)
{
    il2c_assert(this__ != NULL);

    // TODO: ArgumentNullException
    il2c_assert(value != NULL);

    this__->unhandledExceptionEventHandler__ =
        (System_UnhandledExceptionEventHandler*)System_Delegate_Remove__System_Delegate_System_Delegate(
            (System_Delegate*)this__->unhandledExceptionEventHandler__,
            (System_Delegate*)value);
}

// TODO: place constant instance
static volatile System_AppDomain g_AppDomain = { 0 };

System_AppDomain* System_AppDomain_get_CurrentDomain(void)
{
// TODO: place constant instance
    return (System_AppDomain*)&g_AppDomain;
}

void il2c_invoke_unhandled_exception_on_the_current_domain__(System_Object* exception)
{
    il2c_assert(exception != NULL);

    System_UnhandledExceptionEventHandler* pHandler = g_AppDomain.unhandledExceptionEventHandler__;
    if (pHandler != NULL)
    {
        System_UnhandledExceptionEventArgs* pArgs =
            il2c_get_uninitialized_object(System_UnhandledExceptionEventArgs);
        System_UnhandledExceptionEventArgs__ctor__System_Object_System_Boolean(pArgs, exception, false);

        System_UnhandledExceptionEventHandler_Invoke(pHandler, (System_Object*)&g_AppDomain, pArgs);
    }
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(
    System_AppDomain,
    "System.AppDomain",
    IL2C_TYPE_REFERENCE,
    sizeof(System_AppDomain), 
    System_Object,
    1, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(System_AppDomain, unhandledExceptionEventHandler__)
IL2C_RUNTIME_TYPE_END();
