////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_Attribute_H__
#define System_Attribute_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Attribute

typedef struct System_Attribute System_Attribute;
typedef System_Object_VTABLE_DECL__ System_Attribute_VTABLE_DECL__;

struct System_Attribute
{
    System_Attribute_VTABLE_DECL__* vptr0__;
};

#define System_Attribute_VTABLE__ System_Object_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_Attribute);

static inline void System_Attribute__ctor(System_Attribute* this__)
{
}

#ifdef __cplusplus
}
#endif

#endif
