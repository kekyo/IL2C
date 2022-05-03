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

#ifndef System_UnhandledExceptionEventArgs_H__
#define System_UnhandledExceptionEventArgs_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UnhandledExceptionEventArgs

typedef struct System_UnhandledExceptionEventArgs System_UnhandledExceptionEventArgs;
typedef System_EventArgs_VTABLE_DECL__ System_UnhandledExceptionEventArgs_VTABLE_DECL__;

struct System_UnhandledExceptionEventArgs
{
    System_UnhandledExceptionEventArgs_VTABLE_DECL__* vptr0__;
    System_Object* exception__;
    bool isTerminating__;
};

#define System_UnhandledExceptionEventArgs_VTABLE__ System_EventArgs_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_UnhandledExceptionEventArgs);

extern void System_UnhandledExceptionEventArgs__ctor__System_Object_System_Boolean(
    System_UnhandledExceptionEventArgs* this__, System_Object* exception, bool isTerminating);

extern System_Object* System_UnhandledExceptionEventArgs_get_ExceptionObject(System_UnhandledExceptionEventArgs* this__);
extern bool System_UnhandledExceptionEventArgs_get_IsTerminating(System_UnhandledExceptionEventArgs* this__);

#ifdef __cplusplus
}
#endif

#endif
