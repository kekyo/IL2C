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

#ifndef System_Threading_Monitor_H__
#define System_Threading_Monitor_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Threading.Monitor

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Monitor);

extern /* static */ void System_Threading_Monitor_Enter__System_Object(System_Object* obj);
extern /* static */ void System_Threading_Monitor_Enter__System_Object_System_Boolean_REF(System_Object* obj, bool* lockTaken);
extern /* static */ bool System_Threading_Monitor_TryEnter__System_Object(System_Object* obj);
extern /* static */ void System_Threading_Monitor_TryEnter__System_Object_System_Boolean_REF(System_Object* obj, bool* lockTaken);
extern /* static */ void System_Threading_Monitor_Exit__System_Object(System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
