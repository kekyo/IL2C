// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_WDM_H__
#define IL2C_PRIVATE_WDM_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Windows driver model

#if defined(_WDM) && defined(_MSC_VER)

#define IL2C_USE_ITOW

#include "heap.h"

#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <wdm.h>

#include "msvc.h"
#include "strings.h"
    
extern void il2c_sleep(uint32_t milliseconds);

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
#define il2c_try_enter_monitor_lock__(pLock) KeAcquireSpinLock(pLock, pCookie)
#define il2c_exit_monitor_lock__(pLock) KeReleaseSpinLock(pLock, pCookie)
#define il2c_destroy_monitor_lock__(pLock) DeleteCriticalSection(pLock)

#endif

#ifdef __cplusplus
}
#endif

#endif
