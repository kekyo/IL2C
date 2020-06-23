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

#ifndef System_Double_H__
#define System_Double_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Double

typedef double System_Double;

typedef System_ValueType_VTABLE_DECL__ System_Double_VTABLE_DECL__;

extern System_Double_VTABLE_DECL__ System_Double_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Double);

extern /* virtual */ System_String* System_Double_ToString(double* this__);
extern /* virtual */ int32_t System_Double_GetHashCode(double* this__);
extern bool System_Double_Equals__System_Double(double* this__, double obj);
extern /* virtual */ bool System_Double_Equals__System_Object(double* this__, System_Object* obj);
extern /* static */ bool System_Double_TryParse__System_String_System_Double_REF(System_String* s, double* result);

#ifdef __cplusplus
}
#endif

#endif
