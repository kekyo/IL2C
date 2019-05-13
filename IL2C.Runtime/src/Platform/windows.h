// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_WINDOWS_H__
#define IL2C_PRIVATE_WINDOWS_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Windows Win32 API related

#if defined(_WIN32)

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <process.h>
#define IL2C_USE_SIGNAL
#include <signal.h>

#if defined(_MSC_VER)
#include "msvc.h"
#elif defined(__GNUC__)
#include "gcc.h"
#endif

#include "strings.h"

#define il2c_sleep(milliseconds) Sleep((DWORD)milliseconds)

//////////////////////////////////////////////////
// Win32 API threading support

typedef DWORD IL2C_TLS_INDEX;
#define il2c_tls_alloc() ((IL2C_TLS_INDEX)TlsAlloc())
#define il2c_tls_free(tlsIndex) TlsFree((DWORD)(tlsIndex))
#define il2c_get_tls_value(tlsIndex) TlsGetValue((DWORD)(tlsIndex))
#define il2c_set_tls_value(tlsIndex, value) TlsSetValue((DWORD)(tlsIndex), value)

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE unsigned int __stdcall
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) _endthreadex(value); return value
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*
typedef unsigned int(__stdcall *IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

extern intptr_t il2c_get_current_thread__(void);
#define il2c_get_current_thread_id__() ((int32_t)GetCurrentThreadId())
#define il2c_create_thread__(entryPoint, parameter) \
    ((intptr_t)_beginthreadex(NULL, 0, entryPoint, parameter, CREATE_SUSPENDED, NULL))
#define il2c_resume_thread__(handle) ResumeThread((HANDLE)(handle))
extern void il2c_join_thread__(intptr_t handle);
#define il2c_close_thread_handle__(handle) CloseHandle((HANDLE)(handle))

typedef CRITICAL_SECTION IL2C_MONITOR_LOCK;
#define il2c_initialize_monitor_lock__(pLock) InitializeCriticalSection(pLock)
#define il2c_enter_monitor_lock__(pLock) EnterCriticalSection(pLock)
#define il2c_try_enter_monitor_lock__(pLock) (TryEnterCriticalSection(pLock) != FALSE)
#define il2c_exit_monitor_lock__(pLock) LeaveCriticalSection(pLock)
#define il2c_destroy_monitor_lock__(pLock) DeleteCriticalSection(pLock)

#endif

#ifdef __cplusplus
}
#endif

#endif
