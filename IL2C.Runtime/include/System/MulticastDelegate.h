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

#ifndef System_MulticastDelegate_H__
#define System_MulticastDelegate_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.MulticastDelegate

// Maybe all delegate derived types are same as System.Delegate internally.

typedef System_Delegate System_MulticastDelegate;

typedef System_Delegate_VTABLE_DECL__ System_MulticastDelegate_VTABLE_DECL__;

#define System_MulticastDelegate_VTABLE__ System_Delegate_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_MulticastDelegate);

// All members transfered to System.Delegate.

static inline void System_MulticastDelegate_MarkHandler__(System_MulticastDelegate* this__)
{
    System_Delegate_MarkHandler__((System_Delegate*)this__);
}

static inline int32_t System_MulticastDelegate_GetHashCode(System_MulticastDelegate* this__)
{
    return System_Delegate_GetHashCode((System_Delegate*)this__);
}

static inline bool System_MulticastDelegate_Equals__System_Object(System_MulticastDelegate* this__, System_Object* obj)
{
    return System_Delegate_Equals__System_Object((System_Delegate*)this__, obj);
}

#ifdef __cplusplus
}
#endif

#endif
