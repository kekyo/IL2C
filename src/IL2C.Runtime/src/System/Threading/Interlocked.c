////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.Interlocked

void* System_Threading_Interlocked_CompareExchange_6(void* location1, void* value, void* comparand)
{
    return il2c_icmpxchgptr(location1, value, comparand);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(
    System_Threading_Interlocked,
    "System.Threading.Interlocked",
    System_Object);
