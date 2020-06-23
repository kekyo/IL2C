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

#ifndef IL2C_PRIVATE_STRINGS_H__
#define IL2C_PRIVATE_STRINGS_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// String manipulators compatibility

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#if defined(_WIN32)
#define il2c_snwprintf _snwprintf
#define il2c_wtoi32 wcstol
#define il2c_wtou32 wcstoul
#define il2c_wtoi64 wcstoll
#define il2c_wtou64 wcstoull
#define il2c_wcstof wcstof
#define il2c_wcstod wcstod
#define il2c_wcscpy wcscpy
#define il2c_wcscmp wcscmp
#define il2c_wcsicmp _wcsicmp
#define il2c_wcslen wcslen
#elif defined(__GNUC__)
#define il2c_snwprintf swprintf
#define il2c_wtoi32 wcstol
#define il2c_wtou32 wcstoul
#define il2c_wtoi64 wcstoll
#define il2c_wtou64 wcstoull
#define il2c_wcstof wcstof
#define il2c_wcstod wcstod
#define il2c_wcscpy wcscpy
#define il2c_wcscmp wcscmp
#define il2c_wcsicmp wcscasecmp
#define il2c_wcslen wcslen
#endif

#if defined(IL2C_USE_ITOW)
extern wchar_t* il2c_i32tow(int32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u32tow(uint32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_i64tow(int64_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u64tow(uint64_t value, wchar_t* buffer, int radix);
#elif defined(_WIN32)
#define il2c_i32tow _itow
#define il2c_u32tow _ultow
#define il2c_i64tow _i64tow
#define il2c_u64tow _ui64tow
#elif defined(__GNUC__)
#define il2c_i32tow itow
#define il2c_u32tow ultow
#define il2c_i64tow i64tow
#define il2c_u64tow ui64tow
#endif

#if defined(IL2C_USE_TWTOI)
extern bool il2c_twtoi(const wchar_t *_Str, int32_t* value);
#endif

#if defined(IL2C_USE_WTOI)
extern long il2c_wtoi32(const wchar_t *nptr, wchar_t **endptr, int base);
#endif

#ifdef __cplusplus
}
#endif

#endif
