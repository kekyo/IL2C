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
#define IL2C_USE_SIGNAL
#include <signal.h>

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
#define il2c_wcsicmp _wcsicmp
#define il2c_wcslen wcslen
#define il2c_initialize_heap() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF)
#define il2c_check_heap() _CrtCheckMemory()
#define il2c_shutdown_heap() _CrtDumpMemoryLeaks()
#define il2c_malloc malloc
#define il2c_free free
#define il2c_mcalloc il2c_malloc
#define il2c_mcfree il2c_free
#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_sleep(milliseconds) Sleep((DWORD)milliseconds)
#define il2c_longjmp longjmp

#endif

#ifdef __cplusplus
}
#endif

#endif
