////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_Runtime_InteropServices__Attribute_H__
#define System_Runtime_InteropServices__Attribute_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices._Attribute

typedef struct System_Runtime_InteropServices__Attribute System_Runtime_InteropServices__Attribute;

typedef const struct
{
    intptr_t offset__; // Adjustor offset    
} System_Runtime_InteropServices__Attribute_VTABLE_DECL__;

struct System_Runtime_InteropServices__Attribute
{
    System_Runtime_InteropServices__Attribute_VTABLE_DECL__* vptr0__;
};

IL2C_DECLARE_RUNTIME_TYPE(System_Runtime_InteropServices__Attribute);

#ifdef __cplusplus
}
#endif

#endif
