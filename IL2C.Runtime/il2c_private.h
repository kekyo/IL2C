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

// Compatibility symbols (required platform depended functions)
#define il2c_itow _itow
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
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF)
#define il2c_check_heap() _CrtCheckMemory()
#define il2c_shutdown_heap() _CrtDumpMemoryLeaks()
#define il2c_malloc malloc
#define il2c_free free
#define il2c_assert assert
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_iyield() Sleep(0)

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

// Compatibility symbols (required platform depended functions)
#define il2c_itow _itow
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
#define il2c_wcslen wcslen
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()

extern void* il2c_malloc(size_t size);
extern void il2c_free(void* p);

#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_iyield()

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

// Compatibility symbols (required platform depended functions)
#define il2c_itow _itow
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
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()
#define il2c_malloc(size) ExAllocatePoolWithTag(NonPagedPool, size, 0x11231123UL)
#define il2c_free(p) ExFreePoolWithTag(p, 0x11231123UL)
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_iyield()

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

// Compatibility symbols (required platform depended functions)
#define il2c_itow _itow
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
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()
#define il2c_malloc malloc
#define il2c_free free
#define il2c_assert assert
#define il2c_icmpxchg(pDest, newValue, comperandValue) __sync_val_compare_and_swap((interlock_t*)(pDest), (interlock_t)(comperandValue), (interlock_t)(newValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) __sync_val_compare_and_swap((void**)(ppDest), (void*)(pComperandValue), (void*)(pNewValue))

#if defined(_POSIX_PRIORITY_SCHEDULING)
#include <sched.h>
#define il2c_iyield() sched_yield()
#elif defined(_WIN32)
#define il2c_iyield() Sleep(0)
#else
#define il2c_iyield()
#endif

// Support basic console features
#define il2c_putws _putws
#define il2c_fputws fputws
#define il2c_fgetws fgetws

#define DEBUG_WRITE(step, message)

#endif

///////////////////////////////////////////////////
// il2c.h

#include <il2c.h>

///////////////////////////////////////////////////
// Internal runtime definitions

// IL2C_RUNTIME_TYPE_DECL.flags
#define IL2C_TYPE_VARIABLE 0x04

// Generator macro for the trampoline virtual function using the value type.
// These are using the unsafe_unbox. Because we can understand what type the this__ pointer,
// these function only invoke from the (known value type) trampoline vtable.
#define IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(typeName) \
static System_String* typeName##_ToString_Trampoline_VFunc__(System_ValueType* this__) \
{ \
    il2c_assert(this__ != NULL); \
 \
    typeName* pValue = il2c_unsafe_unbox__(this__, typeName); \
    return typeName##_ToString(pValue); \
} \
 \
static int32_t typeName##_GetHashCode_Trampoline_VFunc__(System_ValueType* this__) \
{ \
    il2c_assert(this__ != NULL); \
 \
    typeName* pValue = il2c_unsafe_unbox__(this__, typeName); \
    return typeName##_GetHashCode(pValue); \
} \
 \
static bool typeName##_Equals_1_Trampoline_VFunc__(System_ValueType* this__, System_Object* obj) \
{ \
    il2c_assert(this__ != NULL); \
 \
    typeName* pValue = il2c_unsafe_unbox__(this__, typeName); \
    return typeName##_Equals_1(pValue, obj); \
}

// Generator macro for the trampoline virtual function table using the value type.
#define IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(typeName) \
__##typeName##_VTABLE_DECL__ __##typeName##_VTABLE__ = { \
    /* internalcall */ il2c_isinst__, \
    (bool(*)(void*, System_Object*))typeName##_Equals_1_Trampoline_VFunc__, \
    (void(*)(void*))System_Object_Finalize, \
    (int32_t(*)(void*))typeName##_GetHashCode_Trampoline_VFunc__, \
    (System_String* (*)(void*))typeName##_ToString_Trampoline_VFunc__ \
}

// Generator macro for runtime type information.
#define IL2C_DECLARE_RUNTIME_TYPE(typeName, typeNameString, flags, baseTypeName) \
IL2C_RUNTIME_TYPE_DECL __##typeName##_RUNTIME_TYPE__ = { \
    typeNameString, \
    flags, \
    sizeof(typeName), \
    /* internalcall */ (IL2C_MARK_HANDLER)__##typeName##_IL2C_MarkHandler__, \
    il2c_typeof(baseTypeName) \
}

///////////////////////////////////////////////////
// Internal implements required additional headers

#include <string.h>
#include <stdlib.h>
#include <math.h>

///////////////////////////////////////////////////
// Internal runtime functions

extern void* il2c_get_uninitialized_object_internal__(IL2C_RUNTIME_TYPE_DECL* type, uintptr_t bodySize);

extern void il2c_step1_clear_gcmark__();
extern void il2c_step2_mark_gcmark__();
extern void il2c_step3_sweep_garbage__();

#ifdef __cplusplus
}
#endif

#endif
