// It uses for internal purpose only.

#ifndef __GCC_WIN32_H__
#define __GCC_WIN32_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// MinGW gcc (Win32)

#if defined(__GNUC__) && defined(_WIN32)

#include <x86intrin.h>
#include <stdio.h>
#include <wchar.h>
#include <malloc.h>
#define IL2C_USE_SIGNAL
#include <signal.h>

#include <windows.h>

// Compatibility symbols (required platform depended functions)
#define il2c_itow(v, b, l) _itow(v, b, 10)
#define il2c_ultow _ultow
#define il2c_i64tow _i64tow
#define il2c_ui64tow _ui64tow
#define il2c_snwprintf _snwprintf
#define il2c_wcstol wcstol
#define il2c_wcstoul wcstoul
#define il2c_wcstoll wcstoll
#define il2c_wcstoull wcstoull
#define il2c_wcstof wcstof
#define il2c_wcstod wcstod
#define il2c_wcscmp wcscmp
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen
#define il2c_check_heap()
#define il2c_malloc malloc
#define il2c_free free

#define il2c_mcalloc(name, size) \
    name = (((size) >= 256) ? il2c_malloc(size) : alloca(size)); \
    const bool is_##name##_heaped__ = ((size) >= 256)
#define il2c_mcfree(name) \
    do { if (is_##name##_heaped__) il2c_free(name); } while (0)

#define il2c_iand(pDest, newValue) __sync_fetch_and_and((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ior(pDest, newValue) __sync_fetch_and_or((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_iinc(pDest) __sync_add_and_fetch((interlock_t*)(pDest), 1)
#define il2c_idec(pDest) __sync_sub_and_fetch((interlock_t*)(pDest), 1)
#define il2c_ixchg(pDest, newValue) __sync_lock_test_and_set((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) __sync_lock_test_and_set((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) __sync_val_compare_and_swap((interlock_t*)(pDest), (interlock_t)(comperandValue), (interlock_t)(newValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) __sync_val_compare_and_swap((void**)(ppDest), (void*)(pComperandValue), (void*)(pNewValue))
#define il2c_sleep(milliseconds) Sleep((DWORD)milliseconds)
#define il2c_longjmp longjmp

#endif

#ifdef __cplusplus
}
#endif

#endif
