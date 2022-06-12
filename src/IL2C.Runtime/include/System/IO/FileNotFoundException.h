////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_IO_FileNotFoundException_H__
#define System_IO_FileNotFoundException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IO.IOException

typedef System_IO_IOException System_IO_FileNotFoundException;

typedef System_IO_IOException_VTABLE_DECL__ System_IO_FileNotFoundException_VTABLE_DECL__;

#define System_IO_FileNotFoundException_VTABLE__ System_IO_IOException_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_IO_FileNotFoundException);

static inline void System_IO_FileNotFoundException__ctor(System_IO_FileNotFoundException* this__)
{
    System_IO_IOException__ctor((System_IO_IOException*)this__);
}

static inline void System_IO_FileNotFoundException__ctor__System_String(System_IO_FileNotFoundException* this__, System_String* message)
{
    System_IO_IOException__ctor__System_String((System_IO_IOException*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
