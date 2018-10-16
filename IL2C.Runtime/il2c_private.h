// It uses for internal purpose only.

#ifndef __IL2C_PRIVATE_H__
#define __IL2C_PRIVATE_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef long interlock_t;

///////////////////////////////////////////////////
// Visual C++ (User mode Win32)

#if defined(_MSC_VER) && defined(_WIN32)

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRTDBG_MAP_ALLOC 1
#include <crtdbg.h>

#include <intrin.h>
#include <windows.h>
#include <stdio.h>
#include <assert.h>

// Compatibility symbols
#define il2c_itow _itow
#define il2c_ultow _ultow
#define il2c_i64tow _i64tow
#define il2c_ui64tow _ui64tow
#define il2c_snwprintf _snwprintf
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_malloc malloc
#define il2c_free free
#define il2c_assert assert

// Support basic console features
#define il2c_putws _putws
#define il2c_fputws fputws
#define il2c_fgetws fgetws

#ifdef _DEBUG
#define DEBUG_WRITE(step, message) { \
    char buffer[256]; \
    strcpy(buffer, step); \
    strcat(buffer, ": "); \
    strcat(buffer, message); \
    strcat(buffer, "\r\n"); \
    OutputDebugStringA(buffer); }
#else
#define DEBUG_WRITE(step, message)
#endif

#endif

///////////////////////////////////////////////////
// Visual C++ (UEFI)

#if defined(_MSC_VER) && defined(UEFI)

#include <intrin.h>

// Compatibility symbols
#define il2c_itow _itow
#define il2c_ultow _ultow
#define il2c_i64tow _i64tow
#define il2c_ui64tow _ui64tow
#define il2c_snwprintf _snwprintf

extern void* il2c_memcpy(void* to, const void* from, size_t n);
extern void* il2c_memset(void* target, int ch, size_t n);

extern void* il2c_malloc(size_t size);
extern void il2c_free(void* p);

extern void WriteLineToError(const wchar_t* pMessage);

// Support basic console features
//#define il2c_putws _putws
//#define il2c_fputws fputws
//#define il2c_fgetws fgetws

#if defined(_DEBUG)
#define DEBUG_WRITE(step, message) { \
    WriteLineToError(L## #message); }
#define il2c_assert(actual) if (!(actual)) DEBUG_WRITE(0, #actual)
#else
#define DEBUG_WRITE(step, message)
#define il2c_assert(actual)
#endif

#endif

///////////////////////////////////////////////////
// Visual C++ (Windows driver)

#if defined(_MSC_VER) && defined(_WDM)

#include <intrin.h>
#include <wdm.h>

// Compatibility symbols
#define il2c_itow _itow
#define il2c_ultow _ultow
#define il2c_i64tow _i64tow
#define il2c_ui64tow _ui64tow
#define il2c_snwprintf _snwprintf
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_malloc(size) ExAllocatePoolWithTag(NonPagedPool, size, 0x11231123UL)
#define il2c_free(p) ExFreePoolWithTag(p, 0x11231123UL)

// Support basic console features
//#define il2c_putws _putws
//#define il2c_fputws fputws
//#define il2c_fgetws fgetws

#ifdef DBG
#define DEBUG_WRITE(step, message) { \
    char buffer[256]; \
    strcpy(buffer, step); \
    strcat(buffer, ": "); \
    strcat(buffer, message); \
    strcat(buffer, "\r\n"); \
    DbgPrint(buffer); }
#define il2c_assert(actual) if (!(actual)) DEBUG_WRITE(0, #actual)
#else
#define DEBUG_WRITE(step, message)
#define il2c_assert(actual)
#endif

#endif

///////////////////////////////////////////////////
// Another standard C platform (included gcc)

#if !defined(_MSC_VER)

#include <x86intrin.h>
#include <assert.h>
#include <stdio.h>
#include <wchar.h>

// Compatibility symbols
#define il2c_itow _itow
#define il2c_ultow _ultow
#define il2c_i64tow _i64tow
#define il2c_ui64tow _ui64tow
#define il2c_snwprintf _snwprintf
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_malloc malloc
#define il2c_free free
#define il2c_assert assert

static interlock_t _InterlockedCompareExchange(interlock_t* p, interlock_t v, interlock_t c)
{
    interlock_t cv = *p;
    if (cv == c)
    {
        *p = v;
    }
    return cv;
}

static void* _InterlockedCompareExchangePointer(void** p, void* v, void* c)
{
    void* cv = *p;
    if (cv == c)
    {
        *p = v;
    }
    return cv;
}

// Support basic console features
#define il2c_putws _putws
#define il2c_fputws fputws
#define il2c_fgetws fgetws

#define DEBUG_WRITE(step, message)

#endif

///////////////////////////////////////////////////
// Monitor declarations

#define INTERLOCKED_COMPARE_EXCHANGE(p, v, c) (interlock_t)_InterlockedCompareExchange((interlock_t*)p, (interlock_t)v, (interlock_t)c)
#define INTERLOCKED_COMPARE_EXCHANGE_POINTER(p, v, c) (void*)_InterlockedCompareExchangePointer((void**)p, (void*)v, (void*)c)

///////////////////////////////////////////////////
// il2c.h

#include <il2c.h>

///////////////////////////////////////////////////
// Internal implements required additional headers

#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////
// Internal runtime functions

void* il2c_get_uninitialized_object_internal__(IL2C_RUNTIME_TYPE_DECL* type, uintptr_t bodySize);

void il2c_step1_clear_gcmark__();
void il2c_step2_mark_gcmark__();
void il2c_step3_sweep_garbage__();

#ifdef __cplusplus
}
#endif

#endif
