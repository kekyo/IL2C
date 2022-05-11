////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_Threading_Interlocked_H__
#define System_Threading_Interlocked_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Threading.Interlocked

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Interlocked);

// TODO: Special case "System.Threading.Interlocked.CompareExchange<T>(...)"
extern void* System_Threading_Interlocked_CompareExchange_6(void* location1, void* value, void* comparand);

#ifdef __cplusplus
}
#endif

#endif
