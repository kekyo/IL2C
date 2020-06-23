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

#ifndef System_AppDomain_H__
#define System_AppDomain_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.AppDomain

typedef struct System_AppDomain System_AppDomain;

typedef System_Object_VTABLE_DECL__ System_AppDomain_VTABLE_DECL__;

struct System_AppDomain
{
    System_AppDomain_VTABLE_DECL__* vptr0__;
    System_UnhandledExceptionEventHandler* unhandledExceptionEventHandler__;
};

#define System_AppDomain_VTABLE__ System_Object_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_AppDomain);

extern void System_AppDomain_add_UnhandledException__System_UnhandledExceptionEventHandler(System_AppDomain* this__, System_UnhandledExceptionEventHandler* value);
extern void System_AppDomain_remove_UnhandledException__System_UnhandledExceptionEventHandler(System_AppDomain* this__, System_UnhandledExceptionEventHandler* value);
extern /* static */ System_AppDomain* System_AppDomain_get_CurrentDomain(void);

extern void il2c_invoke_unhandled_exception_on_the_current_domain__(System_Object* exception);

#ifdef __cplusplus
}
#endif

#endif
