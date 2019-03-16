// It uses for internal purpose only.

#ifndef __MSVC_WDM_H__
#define __MSVC_WDM_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Visual C++ (Windows driver)

#if defined(_MSC_VER) && defined(_WDM)

#include <intrin.h>
#include <wdm.h>
#include <malloc.h>

// Compatibility symbols (required platform depended functions)
#define il2c_i32tow _itow
#define il2c_u32tow _ultow
#define il2c_i64tow _i64tow
#define il2c_u64tow _ui64tow
#define il2c_snwprintf _snwprintf
#define il2c_wtoi32 wcstol
#define il2c_wtou32 wcstoul
#define il2c_wtoi64 wcstoll
#define il2c_wtou64 wcstoull
#define il2c_wcstof wcstof
#define il2c_wcstod wcstod
#define il2c_wcscpy wcscpy
#define il2c_wcscmp wcscmp
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen
#define il2c_check_heap()
#define il2c_malloc(size) ExAllocatePoolWithTag(NonPagedPool, size, 0x11231123UL)
#define il2c_free(p) ExFreePoolWithTag(p, 0x11231123UL)

#define il2c_mcalloc(elementType, name, size) \
    const uint32_t name_csize__ = (uint32_t)(size); \
    const bool is_name_heaped__ = name_csize__ >= 256U; \
    elementType* name = is_name_heaped__ ? il2c_malloc(name_csize__) : _alloca(name_csize__)
#define il2c_mcfree(name) \
    do { if (is_name_heaped__) il2c_free(name); } while (0)

#define il2c_iand(pDest, newValue) _InterlockedAnd((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ior(pDest, newValue) _InterlockedOr((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_iinc(pDest) _InterlockedIncrement((interlock_t*)(pDest))
#define il2c_idec(pDest) _InterlockedDecrement((interlock_t*)(pDest))
#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
extern void il2c_sleep(uint32_t milliseconds);

#define il2c_longjmp longjmp

#endif

#ifdef __cplusplus
}
#endif

#endif
