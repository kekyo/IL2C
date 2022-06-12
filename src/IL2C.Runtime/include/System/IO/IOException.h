////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_IO_IOException_H__
#define System_IO_IOException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IO.IOException

typedef System_SystemException System_IO_IOException;

typedef System_SystemException_VTABLE_DECL__ System_IO_IOException_VTABLE_DECL__;

#define System_IO_IOException_VTABLE__ System_SystemException_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_IO_IOException);

static inline void System_IO_IOException__ctor(System_IO_IOException* this__)
{
    System_SystemException__ctor((System_SystemException*)this__);
}

static inline void System_IO_IOException__ctor__System_String(System_IO_IOException* this__, System_String* message)
{
    System_SystemException__ctor__System_String((System_SystemException*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
