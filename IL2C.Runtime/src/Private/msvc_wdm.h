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
#define il2c_memory_barrier() MemoryBarrier()
    
extern void il2c_sleep(uint32_t milliseconds);
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

#define il2c_get_current_thread__() ((intptr_t)PsGetCurrentThread())
#define il2c_get_current_thread_id__() ((int32_t)PsGetCurrentThreadId())
#define il2c_create_thread__(entryPoint, parameter) \
    ((intptr_t)PsCreateSystemThread(NULL, 0, entryPoint, parameter, CREATE_SUSPENDED, NULL))
#define il2c_resume_thread__(handle)
extern void il2c_join_thread__(intptr_t handle);
#define il2c_close_thread_handle__(handle) NtClose((HANDLE)(handle))

typedef KSPIN_LOCK IL2C_MONITOR_LOCK;
#define il2c_initialize_monitor_lock__(pLock) InitializeCriticalSection(pLock)
#define il2c_enter_monitor_lock__(pLock) KeAcquireSpinLock(pLock, pCookie)  // TODO: Spinlock can't nested locking
#define il2c_exit_monitor_lock__(pLock) KeReleaseSpinLock(pLock, pCookie)
#define il2c_destroy_monitor_lock__(pLock) DeleteCriticalSection(pLock)

#endif

#ifdef __cplusplus
}
#endif

#endif
