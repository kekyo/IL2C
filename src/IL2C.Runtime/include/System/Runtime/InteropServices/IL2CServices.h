////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_Runtime_InteropServices_IL2CServices_H__
#define System_Runtime_InteropServices_IL2CServices_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.IL2CServices

IL2C_DECLARE_RUNTIME_TYPE(System_Runtime_InteropServices_IL2CServices);

#define System_Runtime_InteropServices_IL2CServices_get_IsInNativeExecution() (true)

#ifdef __cplusplus
}
#endif

#endif
