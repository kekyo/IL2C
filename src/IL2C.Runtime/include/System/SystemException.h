////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_SystemException_H__
#define System_SystemException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.SystemException

typedef System_Exception System_SystemException;

typedef System_Exception_VTABLE_DECL__ System_SystemException_VTABLE_DECL__;

#define System_SystemException_VTABLE__ System_Exception_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_SystemException);

static inline void System_SystemException__ctor(System_SystemException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_SystemException__ctor__System_String(System_SystemException* this__, System_String* message)
{
    System_Exception__ctor__System_String((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
