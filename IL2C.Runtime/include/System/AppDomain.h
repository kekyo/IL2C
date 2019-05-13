#ifndef System_AppDomain_H__
#define System_AppDomain_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.AppDomain

typedef struct System_AppDomain System_AppDomain;

typedef System_Object_VTABLE_DECL__ System_AppDomain_VTABLE_DECL__;

struct System_AppDomain
{
    System_AppDomain_VTABLE_DECL__* vptr0__;
    System_UnhandledExceptionEventHandler* unhandledExceptionEventHandler__;
};

#define System_AppDomain_VTABLE__ System_Object_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_AppDomain);

extern void System_AppDomain_add_UnhandledException__System_UnhandledExceptionEventHandler(System_AppDomain* this__, System_UnhandledExceptionEventHandler* value);
extern void System_AppDomain_remove_UnhandledException__System_UnhandledExceptionEventHandler(System_AppDomain* this__, System_UnhandledExceptionEventHandler* value);
extern /* static */ System_AppDomain* System_AppDomain_get_CurrentDomain(void);

extern void il2c_invoke_unhandled_exception_on_the_current_domain__(System_Object* exception);

#ifdef __cplusplus
}
#endif

#endif
