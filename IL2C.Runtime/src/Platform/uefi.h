// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_UEFI_H__
#define IL2C_PRIVATE_UEFI_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// UEFI

#if defined(UEFI) && defined(_MSC_VER)

//#define IL2C_USE_FMOD
#define IL2C_USE_ITOW
//#define IL2C_USE_TWTOI
#define IL2C_USE_WTOI
#define IL2C_NO_THREADING

#include "heap.h"

#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>

// Can't enable intrinsic inlined memcpy/memset/memcmp with VC++'s /GL and /LTCG options in uefi release build.
// So these are simple implementations for thiers.
#pragma function(memcpy, memset, memcmp)
extern void* __cdecl memcpy(void* to, const void* from, size_t n);
extern void* __cdecl memset(void* target, int ch, size_t n);
extern int __cdecl memcmp(const void *buffer1, const void *buffer2, size_t count);

#include "msvc.h"
#include "strings.h"
#include "no-threading.h"

#define il2c_snwprintf _snwprintf
extern long il2c_wtoi32(const wchar_t *nptr, wchar_t **endptr, int base);
#define il2c_wtou32 wcstoul
#define il2c_wtoi64 wcstoll
#define il2c_wtou64 wcstoull
#define il2c_wcstof wcstof
#define il2c_wcstod wcstod
#define il2c_wcscpy wcscpy
#define il2c_wcscmp wcscmp
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen

extern void il2c_sleep(uint32_t milliseconds);

#endif

#ifdef __cplusplus
}
#endif

#endif
