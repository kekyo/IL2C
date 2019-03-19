// It uses for internal purpose only.

#ifndef __MSVC_UEFI_H__
#define __MSVC_UEFI_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Visual C++ (UEFI)

#if defined(_MSC_VER) && defined(UEFI)

#include <intrin.h>
#include <stdint.h>
#include <wchar.h>
#include <malloc.h>

// Compatibility symbols (required platform depended functions)
extern wchar_t* il2c_i32tow(int32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u32tow(uint32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_i64tow(int64_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u64tow(uint64_t value, wchar_t* buffer, int radix);
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
#define il2c_check_heap()

extern void* il2c_malloc(size_t size);
extern void il2c_free(void* p);

#define il2c_mcalloc(elementType, name, size) \
    elementType* name = il2c_malloc(size)
#define il2c_mcfree(name) \
    il2c_free(name)

#define il2c_iand(pDest, newValue) _InterlockedAnd((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ior(pDest, newValue) _InterlockedOr((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_iinc(pDest) _InterlockedIncrement((interlock_t*)(pDest))
#define il2c_idec(pDest) _InterlockedDecrement((interlock_t*)(pDest))
#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_memory_barrier() MemoryBarrier()

extern void il2c_sleep(uint32_t milliseconds);
#define il2c_longjmp longjmp

// UEFI enviuronment: multithreading feature not supported.
typedef intptr_t IL2C_TLS_INDEX;
#define il2c_tls_alloc() ((IL2C_TLS_INDEX)0)
#define il2c_tls_free(tlsIndex) (tlsIndex = 0)
#define il2c_get_tls_value(tlsIndex) ((void*)(tlsIndex))
#define il2c_set_tls_value(tlsIndex, value) (tlsIndex = (intptr_t)(value))

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE void
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) ((void)0)
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*

// TODO: has to get real handle
#define il2c_get_current_thread__() ((intptr_t)0)
#define il2c_get_current_thread_id__() ((int32_t)0)
#define il2c_create_thread__(entryPoint, parameter) ((intptr_t)-1)
#define il2c_resume_thread__(handle) ((void)0)
#define il2c_join_thread__(handle) ((void)0)

#endif

#ifdef __cplusplus
}
#endif

#endif
