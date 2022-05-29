////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_NotImplementedException_H__
#define System_NotImplementedException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.NotImplementedException

typedef System_SystemException System_NotImplementedException;

typedef System_SystemException_VTABLE_DECL__ System_NotImplementedException_VTABLE_DECL__;

#define System_NotImplementedException_VTABLE__ System_SystemException_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_NotImplementedException);

static inline void System_NotImplementedException__ctor(System_NotImplementedException* this__)
{
    System_SystemException__ctor((System_SystemException*)this__);
}

static inline void System_NotImplementedException__ctor__System_String(System_NotImplementedException* this__, System_String* message)
{
    System_SystemException__ctor__System_String((System_SystemException*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
