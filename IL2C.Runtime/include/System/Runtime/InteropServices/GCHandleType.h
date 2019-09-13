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

#ifndef System_Runtime_InteropServices_GCHandleType_H__
#define System_Runtime_InteropServices_GCHandleType_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.GCHandleType

typedef int32_t System_Runtime_InteropServices_GCHandleType;

// TODO: Weak references
//static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_Weak = 0;
//static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_WeakResurrection = 1;
static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_Normal = 2;
static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_Pinned = 3;

#ifdef __cplusplus
}
#endif

#endif
