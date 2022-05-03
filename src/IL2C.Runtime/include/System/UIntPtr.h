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

#ifndef System_UIntPtr_H__
#define System_UIntPtr_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UIntPtr

typedef uintptr_t System_UIntPtr;

typedef System_ValueType_VTABLE_DECL__ System_UIntPtr_VTABLE_DECL__;

extern System_UIntPtr_VTABLE_DECL__ System_UIntPtr_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_UIntPtr);

extern /* virtual */ System_String* System_UIntPtr_ToString(uintptr_t* this__);
extern /* virtual */ int32_t System_UIntPtr_GetHashCode(uintptr_t* this__);
extern bool System_UIntPtr_Equals__System_UIntPtr(uintptr_t* this__, uintptr_t obj);
extern /* virtual */ bool System_UIntPtr_Equals__System_Object(uintptr_t* this__, System_Object* obj);

#define System_UIntPtr_op_Explicit__System_UInt32(value) ((uintptr_t)(value))
#define System_UIntPtr_op_Explicit__System_UInt64(value) ((uintptr_t)(value))
#define System_UIntPtr_op_Addition__System_UIntPtr_System_Int32(lhs, rhs) (((uintptr_t)(lhs)) + ((uintptr_t)(rhs)))

extern const System_UIntPtr System_UIntPtr_Zero;

#ifdef __cplusplus
}
#endif

#endif
