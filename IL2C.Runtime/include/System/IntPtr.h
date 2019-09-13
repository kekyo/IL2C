/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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

#define System_IntPtr_op_Explicit__System_Int32(value) ((intptr_t)(value))
#define System_IntPtr_op_Explicit__System_Int64(value) ((intptr_t)(value))
#define System_IntPtr_op_Addition__System_IntPtr_System_Int32(lhs, rhs) (((intptr_t)(lhs)) + ((intptr_t)(rhs)))
#define System_IntPtr_op_Inequality__System_IntPtr_System_IntPtr(lhs, rhs) (((intptr_t)(lhs)) != ((intptr_t)(rhs)))

#ifdef __cplusplus
}
#endif

#endif
