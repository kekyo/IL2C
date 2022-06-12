////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#include "il2c_private.h"
#include <System/Runtime/InteropServices/IL2CServices.h>

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(
    System_Runtime_InteropServices_IL2CServices,
    "System.Runtime.InteropServices.IL2CServices",
    System_Object);
