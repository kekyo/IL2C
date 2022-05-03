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

#ifndef System_Runtime_InteropServices_GCHandle_H__
#define System_Runtime_InteropServices_GCHandle_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.GCHandle

typedef intptr_t System_Runtime_InteropServices_GCHandle;

typedef System_Object_VTABLE_DECL__ System_Runtime_InteropServices_GCHandle_VTABLE_DECL__;

extern System_Runtime_InteropServices_GCHandle_VTABLE_DECL__ System_Runtime_InteropServices_GCHandle_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Runtime_InteropServices_GCHandle);

extern System_Object* System_Runtime_InteropServices_GCHandle_get_Target(System_Runtime_InteropServices_GCHandle* this__);
extern void System_Runtime_InteropServices_GCHandle_set_Target__System_Object(System_Runtime_InteropServices_GCHandle* this__, System_Object* value);
extern void System_Runtime_InteropServices_GCHandle_Free(System_Runtime_InteropServices_GCHandle* this__);
extern intptr_t System_Runtime_InteropServices_GCHandle_AddrOfPinnedObject(System_Runtime_InteropServices_GCHandle* this__);

extern /* static */ System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc__System_Object(System_Object* value);
extern /* static */ System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc__System_Object_System_Runtime_InteropServices_GCHandleType(System_Object* value, System_Runtime_InteropServices_GCHandleType type);

#define System_Runtime_InteropServices_GCHandle_FromIntPtr__System_IntPtr(value) ((System_Runtime_InteropServices_GCHandle)value)
#define System_Runtime_InteropServices_GCHandle_ToIntPtr__System_Runtime_InteropServices_GCHandle(value) ((intptr_t)value)

extern /* virtual */ int32_t System_Runtime_InteropServices_GCHandle_GetHashCode(System_Runtime_InteropServices_GCHandle* this__);
extern /* virtual */ bool System_Runtime_InteropServices_GCHandle_Equals__System_Object(System_Runtime_InteropServices_GCHandle* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
