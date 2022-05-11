////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_GC_H__
#define System_GC_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.GC

IL2C_DECLARE_RUNTIME_TYPE(System_GC);

extern /* static */ void System_GC_SuppressFinalize__System_Object(System_Object* obj);
extern /* static */ void System_GC_ReRegisterForFinalize__System_Object(System_Object* obj);
extern /* static */ void System_GC_WaitForPendingFinalizers(void);
extern /* static */ void System_GC_Collect(void);
#define System_GC_Collect__System_Int32(generation) System_GC_Collect()

#ifdef __cplusplus
}
#endif

#endif
