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

// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_ARDUINO_ALL_H__
#define IL2C_PRIVATE_ARDUINO_ALL_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Arduino

#if defined(ARDUINO) && defined(__GNUC__)

#define IL2C_USE_FMOD
#define IL2C_USE_ITOW
#define IL2C_USE_TWTOI
#define IL2C_USE_WTOI
#define IL2C_USE_FREERTOS
//#define IL2C_USE_PTHREAD
//#define IL2C_USE_NO_THREADING

#include "heap.h"

#include <arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>

#include "gcc.h"
#include "strings.h"

#include "freertos.h"
#include "pthread.h"
#include "no-threading.h"

extern void il2c_sleep(uint32_t milliseconds);

#endif

#ifdef __cplusplus
}
#endif

#endif
