////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_UnhandledExceptionEventHandler_H__
#define System_UnhandledExceptionEventHandler_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UnhandledExceptionEventHandler

typedef System_MulticastDelegate System_UnhandledExceptionEventHandler;

typedef System_MulticastDelegate_VTABLE_DECL__ System_UnhandledExceptionEventHandler_VTABLE_DECL__;

#define System_UnhandledExceptionEventHandler_VTABLE__ System_MulticastDelegate_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_UnhandledExceptionEventHandler);

extern void System_UnhandledExceptionEventHandler_Invoke(
    System_UnhandledExceptionEventHandler* this__, System_Object* sender, System_UnhandledExceptionEventArgs* e);

#ifdef __cplusplus
}
#endif

#endif
