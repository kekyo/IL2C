#ifndef System_UnhandledExceptionEventArgs_H__
#define System_UnhandledExceptionEventArgs_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UnhandledExceptionEventArgs

typedef struct System_UnhandledExceptionEventArgs System_UnhandledExceptionEventArgs;
typedef System_EventArgs_VTABLE_DECL__ System_UnhandledExceptionEventArgs_VTABLE_DECL__;

struct System_UnhandledExceptionEventArgs
{
    System_UnhandledExceptionEventArgs_VTABLE_DECL__* vptr0__;
    System_Object* exception__;
    bool isTerminating__;
};

#define System_UnhandledExceptionEventArgs_VTABLE__ System_EventArgs_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_UnhandledExceptionEventArgs);

extern void System_UnhandledExceptionEventArgs__ctor__System_Object_System_Boolean(
    System_UnhandledExceptionEventArgs* this__, System_Object* exception, bool isTerminating);

extern System_Object* System_UnhandledExceptionEventArgs_get_ExceptionObject(System_UnhandledExceptionEventArgs* this__);
extern bool System_UnhandledExceptionEventArgs_get_IsTerminating(System_UnhandledExceptionEventArgs* this__);

#ifdef __cplusplus
}
#endif

#endif
