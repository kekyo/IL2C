// It uses for internal purpose only.

#ifndef __MSVC_WIN32_H__
#define __MSVC_WIN32_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Visual C++ (User mode Win32)

#if defined(_MSC_VER) && defined(_WIN32) && !defined(UEFI) && !defined(WDM)

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRTDBG_MAP_ALLOC 1
#include <crtdbg.h>

#include <intrin.h>
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <wchar.h>
#include <malloc.h>
#include <process.h>
#define IL2C_USE_SIGNAL
#include <signal.h>

// Compatibility symbols (required platform depended functions)
#if 1
extern wchar_t* il2c_i32tow(int32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u32tow(uint32_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_i64tow(int64_t value, wchar_t* buffer, int radix);
extern wchar_t* il2c_u64tow(uint64_t value, wchar_t* buffer, int radix);
#else
#define il2c_i32tow _itow
#define il2c_u32tow _ultow
#define il2c_i64tow _i64tow
#define il2c_u64tow _ui64tow
#endif
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
#define il2c_check_heap() _CrtCheckMemory()
#define il2c_malloc malloc
#define il2c_free free

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
typedef unsigned int(__stdcall *IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

// TODO: has to get real handle
#define il2c_get_current_thread__() ((intptr_t)GetCurrentThread())
#define il2c_get_current_thread_id__() ((int32_t)GetCurrentThreadId())
#define il2c_create_thread__(entryPoint, parameter) \
    ((intptr_t)_beginthreadex(NULL, 0, entryPoint, parameter, CREATE_SUSPENDED, NULL))
#define il2c_resume_thread__(handle) ResumeThread((HANDLE)(handle))
extern void il2c_join_thread__(intptr_t handle);
#define il2c_close_thread_handle__(handle) CloseHandle((HANDLE)(handle))

#endif

#ifdef __cplusplus
}
#endif

#endif
