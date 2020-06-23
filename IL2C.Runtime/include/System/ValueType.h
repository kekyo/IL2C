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

#ifndef System_ValueType_H__
#define System_ValueType_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.ValueType

typedef struct System_ValueType System_ValueType;

typedef System_Object_VTABLE_DECL__ System_ValueType_VTABLE_DECL__;

struct System_ValueType
{
    System_ValueType_VTABLE_DECL__* vptr0__;
};

extern System_ValueType_VTABLE_DECL__ System_ValueType_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_ValueType);

extern /* virtual */ System_String* System_ValueType_ToString(System_ValueType* this__);
extern /* virtual */ int32_t System_ValueType_GetHashCode(System_ValueType* this__);
extern /* virtual */ bool System_ValueType_Equals__System_Object(System_ValueType* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
