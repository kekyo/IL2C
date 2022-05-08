////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_Console_H__
#define System_Console_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Console

IL2C_DECLARE_RUNTIME_TYPE(System_Console);

extern /* static */ void System_Console_Write__System_String(System_String* value);
extern /* static */ void System_Console_WriteLine(void);
extern /* static */ void System_Console_WriteLine__System_Int32(int32_t value);
extern /* static */ void System_Console_WriteLine__System_Int64(int64_t value);
extern /* static */ void System_Console_WriteLine__System_String(System_String* value);

extern /* static */ System_String* System_Console_ReadLine(void);

#ifdef __cplusplus
}
#endif

#endif
