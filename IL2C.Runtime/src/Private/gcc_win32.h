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
extern wchar_t* il2c_i32tow(int32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u32tow(uint32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_i64tow(int64_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u64tow(uint64_t value, wchar_t* buffer, int radix);
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
#define il2c_malloc malloc
#define il2c_free free

#define il2c_mcalloc(elementType, name, size) \
    const uint32_t name_csize__ = (uint32_t)(size); \
    const bool is_name_heaped__ = name_csize__ >= 256U; \
    elementType* name = is_name_heaped__ ? il2c_malloc(name_csize__) : alloca(name_csize__)
#define il2c_mcfree(name) \
    do { if (is_name_heaped__) il2c_free(name); } while (0)

#define il2c_iand(pDest, newValue) __sync_fetch_and_and((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ior(pDest, newValue) __sync_fetch_and_or((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_iinc(pDest) __sync_add_and_fetch((interlock_t*)(pDest), 1)
#define il2c_idec(pDest) __sync_sub_and_fetch((interlock_t*)(pDest), 1)
#define il2c_ixchg(pDest, newValue) __sync_lock_test_and_set((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) __sync_lock_test_and_set((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) __sync_val_compare_and_swap((interlock_t*)(pDest), (interlock_t)(comperandValue), (interlock_t)(newValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) __sync_val_compare_and_swap((void**)(ppDest), (void*)(pComperandValue), (void*)(pNewValue))
#define il2c_memory_barrier() __sync_synchronize()

#define il2c_sleep(milliseconds) Sleep((DWORD)milliseconds)
#define il2c_longjmp longjmp

typedef DWORD IL2C_TLS_INDEX;
#define il2c_tls_alloc() ((IL2C_TLS_INDEX)TlsAlloc())
#define il2c_tls_free(tlsIndex) TlsFree((DWORD)(tlsIndex))
#define il2c_get_tls_value(tlsIndex) TlsGetValue((DWORD)(tlsIndex))
#define il2c_set_tls_value(tlsIndex, value) TlsSetValue((DWORD)(tlsIndex), value)

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE unsigned int __stdcall
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) _endthreadex(value); return value
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*
typedef unsigned int (__stdcall *IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

extern intptr_t il2c_get_current_thread__(void);
#define il2c_get_current_thread_id__() ((int32_t)GetCurrentThreadId())
#define il2c_create_thread__(entryPoint, parameter) \
    ((intptr_t)_beginthreadex(NULL, 0, entryPoint, parameter, CREATE_SUSPENDED, NULL))
#define il2c_resume_thread__(handle) ResumeThread((HANDLE)handle)
extern void il2c_join_thread__(intptr_t handle);
#define il2c_close_thread_handle__(handle) CloseHandle((HANDLE)(handle))

#endif

#ifdef __cplusplus
}
#endif

#endif
