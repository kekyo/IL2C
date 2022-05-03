#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UnhandledExceptionEventArgs

void System_UnhandledExceptionEventArgs__ctor__System_Object_System_Boolean(
    System_UnhandledExceptionEventArgs* this__, System_Object* exception, bool isTerminating)
{
    this__->exception__ = exception;
    this__->isTerminating__ = isTerminating;
}

System_Object* System_UnhandledExceptionEventArgs_get_ExceptionObject(System_UnhandledExceptionEventArgs* this__)
{
    il2c_assert(this__ != NULL);
    return this__->exception__;
}

bool System_UnhandledExceptionEventArgs_get_IsTerminating(System_UnhandledExceptionEventArgs* this__)
{
    il2c_assert(this__ != NULL);
    return this__->isTerminating__;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(
    System_UnhandledExceptionEventArgs,
    "System.UnhandledExceptionEventArgs",
    IL2C_TYPE_REFERENCE,
    sizeof(System_UnhandledExceptionEventArgs),
    System_EventArgs,
    1, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(System_UnhandledExceptionEventArgs, exception__)
IL2C_RUNTIME_TYPE_END();
