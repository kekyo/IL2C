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

#ifndef System_RuntimeFieldHandle_H__
#define System_RuntimeFieldHandle_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.RuntimeFieldHandle

typedef struct System_RuntimeFieldHandle System_RuntimeFieldHandle;

struct System_RuntimeFieldHandle
{
    uintptr_t size__;
    const void* field__;
};

IL2C_DECLARE_RUNTIME_TYPE(System_RuntimeFieldHandle);

#ifdef __cplusplus
}
#endif

#endif
