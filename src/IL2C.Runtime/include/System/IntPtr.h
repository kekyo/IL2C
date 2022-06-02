////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#ifndef System_IntPtr_H__
#define System_IntPtr_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IntPtr

typedef intptr_t System_IntPtr;

typedef System_ValueType_VTABLE_DECL__ System_IntPtr_VTABLE_DECL__;

extern System_IntPtr_VTABLE_DECL__ System_IntPtr_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_IntPtr);

extern /* virtual */ System_String* System_IntPtr_ToString(intptr_t* this__);
extern /* virtual */ int32_t System_IntPtr_GetHashCode(intptr_t* this__);
extern bool System_IntPtr_Equals__System_IntPtr(intptr_t* this__, intptr_t obj);
extern /* virtual */ bool System_IntPtr_Equals__System_Object(intptr_t* this__, System_Object* obj);

extern const intptr_t System_IntPtr_Zero;

extern intptr_t* System_IntPtr_Zero_REF__;

#define System_IntPtr_ToInt32(this__) ((int32_t)*(this__))
#define System_IntPtr_ToInt64(this__) ((int64_t)*(this__))

#define System_IntPtr_get_Size() (sizeof(intptr_t))

#define System_IntPtr_op_Explicit__System_Int32(value) ((intptr_t)(value))
#define System_IntPtr_op_Explicit__System_Int64(value) ((intptr_t)(value))
#define System_IntPtr_op_Addition__System_IntPtr_System_Int32(lhs, rhs) (((intptr_t)(lhs)) + ((intptr_t)(rhs)))
#define System_IntPtr_op_Equality__System_IntPtr_System_IntPtr(lhs, rhs) (((intptr_t)(lhs)) == ((intptr_t)(rhs)))
#define System_IntPtr_op_Inequality__System_IntPtr_System_IntPtr(lhs, rhs) (((intptr_t)(lhs)) != ((intptr_t)(rhs)))

#ifdef __cplusplus
}
#endif

#endif
