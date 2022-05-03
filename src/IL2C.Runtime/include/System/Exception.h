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

#ifndef System_Exception_H__
#define System_Exception_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Exception

typedef struct System_Exception System_Exception;

typedef const struct
{
    intptr_t offset__; // Adjustor offset
    bool(*Equals__System_Object)(void* this__, System_Object* obj);
    void(*Finalize)(void* this__);
    int32_t(*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    System_String* (*get_Message)(void* this__);
} System_Exception_VTABLE_DECL__;

struct System_Exception
{
    System_Exception_VTABLE_DECL__* vptr0__;
    System_String* message__;
};

extern System_Exception_VTABLE_DECL__ System_Exception_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Exception);

extern void System_Exception__ctor(System_Exception* this__);
extern void System_Exception__ctor__System_String(System_Exception* this__, System_String* message);

extern System_String* System_Exception_get_Message(System_Exception* this__);

#ifdef __cplusplus
}
#endif

#endif
