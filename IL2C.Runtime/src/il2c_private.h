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
#include <errno.h>
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
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF)
#define il2c_check_heap() _CrtCheckMemory()
#define il2c_shutdown_heap() _CrtDumpMemoryLeaks()
#define il2c_malloc malloc
#define il2c_free free
#define il2c_mcalloc il2c_malloc
#define Il2c_mcfree il2c_free
#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_sleep Sleep

#define il2c_longjmp longjmp

// Support basic console features
#define il2c_wwriteline _putws
#define il2c_wwrite(p) fputws(p, stdout)
#define il2c_fgetws fgetws

#if defined(IL2C_DEBUG_WRITE) && defined(_DEBUG)
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
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()

extern void* il2c_malloc(size_t size);
extern void il2c_free(void* p);
#define il2c_mcalloc il2c_malloc
#define Il2c_mcfree il2c_free

#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_sleep(milliseconds) Sleep(milliseconds)

#define il2c_longjmp longjmp

extern void WriteLineToError(const wchar_t* pMessage);

// Support basic console features
//#define il2c_wwriteline _putws
//#define il2c_wwrite fputws
//#define il2c_fgetws fgetws

#if defined(IL2C_DEBUG_WRITE) && defined(_DEBUG)
#define DEBUG_WRITE(step, message) { \
    WriteLineToError(L## #message); }
#else
#define DEBUG_WRITE(step, message)
#endif

#endif

///////////////////////////////////////////////////
// Visual C++ (Windows driver)

#if defined(_MSC_VER) && defined(_WDM)

#include <intrin.h>
#include <wdm.h>

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
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()
#define il2c_malloc(size) ExAllocatePoolWithTag(NonPagedPool, size, 0x11231123UL)
#define il2c_free(p) ExFreePoolWithTag(p, 0x11231123UL)
#define il2c_mcalloc il2c_malloc
#define Il2c_mcfree il2c_free
#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_sleep(milliseconds) Sleep(milliseconds)

#define il2c_longjmp longjmp

// Support basic console features
//#define il2c_wwriteline _putws
//#define il2c_wwrite fputws
//#define il2c_fgetws fgetws

#if defined(IL2C_DEBUG_WRITE) && defined(DBG)
#define DEBUG_WRITE(step, message) { \
    char buffer[256]; \
    strcpy(buffer, step); \
    strcat(buffer, ": "); \
    strcat(buffer, message); \
    strcat(buffer, "\r\n"); \
    DbgPrint(buffer); }
#else
#define DEBUG_WRITE(step, message)
#endif

#endif

///////////////////////////////////////////////////
// MinGW gcc (Win32)

#if defined(__GNUC__) && defined(_WIN32)

#include <x86intrin.h>
#include <stdio.h>
#include <errno.h>
#include <wchar.h>
#define IL2C_USE_SIGNAL
#include <signal.h>

#include <windows.h>

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
#define il2c_wcsicmp wcsicmp
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()
#define il2c_malloc malloc
#define il2c_free free
#define il2c_mcalloc il2c_malloc
#define Il2c_mcfree il2c_free
#define il2c_ixchg(pDest, newValue) __sync_lock_test_and_set((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) __sync_lock_test_and_set((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) __sync_val_compare_and_swap((interlock_t*)(pDest), (interlock_t)(comperandValue), (interlock_t)(newValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) __sync_val_compare_and_swap((void**)(ppDest), (void*)(pComperandValue), (void*)(pNewValue))
#define il2c_sleep Sleep

#define il2c_longjmp longjmp

// Support basic console features
#define il2c_wwriteline(p) fputws(p, stdout)    // TODO:
#define il2c_wwrite(p) fputws(p, stdout)
#define il2c_fgetws fgetws

#define DEBUG_WRITE(step, message)

#endif

///////////////////////////////////////////////////
// Another standard C platform (gcc)

#if defined(__GNUC__) && !defined(_WIN32)

#if defined(__x86_64__) || defined(__i386__)
#include <x86intrin.h>
#elif defined(__ARM_NEON__)
#include <arm_neon.h>
#elif defined(__IWMMXT__)
#include <mmintrin.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wchar.h>
#define IL2C_USE_SIGNAL
#include <signal.h>

#include <unistd.h>

#if defined(__AZURE_SPHERE__)
#include <applibs/log.h>
#endif

// Compatibility symbols (required platform depended functions)
static inline wchar_t* il2c_itow(int32_t v, wchar_t* b, size_t l) { swprintf(b, l, L"%d", v); return b; }
static inline wchar_t* il2c_ultow(uint32_t v, wchar_t* b, size_t l) { swprintf(b, l, L"%lu", v); return b; }
static inline wchar_t* il2c_i64tow(int64_t v, wchar_t* b, size_t l) { swprintf(b, l, L"%lld", v); return b; }
static inline wchar_t* il2c_ui64tow(uint64_t v, wchar_t* b, size_t l) { swprintf(b, l, L"%llu", v); return b; }
#define il2c_snwprintf swprintf
#define il2c_wcstol wcstol
#define il2c_wcstoul wcstoul
#define il2c_wcstoll wcstoll
#define il2c_wcstoull wcstoull
#define il2c_wcstof wcstof
#define il2c_wcstod wcstod
#define il2c_wcscmp wcscmp
#define il2c_wcsicmp wcscasecmp
#define il2c_wcslen wcslen
#define il2c_memcpy memcpy
#define il2c_memset memset
#define il2c_memcmp memcmp
#define il2c_initialize_heap()
#define il2c_check_heap()
#define il2c_shutdown_heap()
#define il2c_malloc malloc
#define il2c_free free
#define il2c_mcalloc il2c_malloc
#define il2c_mcfree il2c_free
#define il2c_ixchg(pDest, newValue) __sync_lock_test_and_set((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) __sync_lock_test_and_set((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) __sync_val_compare_and_swap((interlock_t*)(pDest), (interlock_t)(comperandValue), (interlock_t)(newValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) __sync_val_compare_and_swap((void**)(ppDest), (void*)(pComperandValue), (void*)(pNewValue))
#define il2c_sleep sleep

#define il2c_longjmp longjmp

#if defined(__AZURE_SPHERE__)
#define il2c_write Log_Debug
static inline void il2c_writeline(const char* p) {
    size_t l = strlen(p);
    char* d = il2c_mcalloc(l + 2);
    il2c_memcpy(d, p, l);
    d[l] = '\n';
    d[l + 1] = '\0';
    il2c_write(d);
    il2c_mcfree(d);
}
static inline void il2c_wwrite(const wchar_t* p) {
    size_t l = il2c_wcslen(p);
    char* d = il2c_mcalloc(l + 1);
    size_t i;
    for (i = 0; i < l; i++) d[i] = (char)(p[i]);
    d[i] = '\0';
    il2c_write(d);
    il2c_mcfree(d);
}
static inline void il2c_wwriteline(const wchar_t* p) {
    size_t l = il2c_wcslen(p);
    char* d = il2c_mcalloc(l + 2);
    size_t i;
    for (i = 0; i < l; i++) d[i] = (char)(p[i]);
    d[i++] = '\n';
    d[i] = '\0';
    il2c_write(d);
    il2c_mcfree(d);
}
#define il2c_fgetws fgetws

#if defined(IL2C_DEBUG_WRITE) && defined(_DEBUG)
#define DEBUG_WRITE(step, message) { \
    il2c_write(step); \
    il2c_write(": "); \
    il2c_writeline(message); }
#else
#define DEBUG_WRITE(step, message)
#endif
#else
// Support basic console features
#define il2c_wwrite(p) fputws(p, stdout)
//#define il2c_wwrite fputws
#define il2c_fgetws fgetws
#define DEBUG_WRITE(step, message)
#endif

#endif

///////////////////////////////////////////////////
// il2c.h

#include <il2c.h>

///////////////////////////////////////////////////
// Internal runtime definitions

typedef const struct IL2C_MARK_TARGET_DECL
{
    const IL2C_RUNTIME_TYPE valueType;
    const uintptr_t offset;
} IL2C_MARK_TARGET;

typedef const struct IL2C_IMPLEMENTED_INTERFACE_DECL
{
    const IL2C_RUNTIME_TYPE type;
    const void* vptr0;
} IL2C_IMPLEMENTED_INTERFACE;

struct IL2C_RUNTIME_TYPE_DECL
{
    const char* pTypeName;
    const uintptr_t flags;
    const uintptr_t bodySize;       // uint32_t
    const IL2C_RUNTIME_TYPE baseType;
    const void* vptr0;
    const uintptr_t markTarget;     // mark target count / custom mark handler (only variable type)
    const uintptr_t interfaceCount;
    //IL2C_MARK_TARGET markTargets[markTarget];
    //IL2C_IMPLEMENTED_INTERFACE interfaces[interfaceCount];
};

// TODO: shrink for interface types
//struct IL2C_RUNTIME_TYPE_DECL
//{
//    const char* pTypeName;
//    const uintptr_t flags;
//    const uintptr_t interfaceCount;
// ---------------------------------------
//    const uintptr_t bodySize;       // uint32_t
//    const IL2C_RUNTIME_TYPE baseType;
//    const void* vptr0;
//    const uintptr_t markTarget;     // mark target count / custom mark handler (only variable type)
//    //IL2C_IMPLEMENTED_INTERFACE interfaces[interfaceCount];
//    //const void* markTargets[markTarget];
//};

#define GCMARK_NOMARK ((interlock_t)0)
#define GCMARK_LIVE ((interlock_t)1)
#define GCMARK_FIXED ((interlock_t)2)
#define GCMARK_CONST ((interlock_t)3)   // For GCHandle

#define il2c_get_header__(pReference) \
    ((IL2C_REF_HEADER*)(((uint8_t*)(pReference)) - sizeof(IL2C_REF_HEADER)))

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
typeName##_VTABLE_DECL__ typeName##_VTABLE__ = { \
    0, \
    (bool(*)(void*, System_Object*))typeName##_Equals_1_Trampoline_VFunc__, \
    (void(*)(void*))System_Object_Finalize, \
    (int32_t(*)(void*))typeName##_GetHashCode_Trampoline_VFunc__, \
    (System_String* (*)(void*))typeName##_ToString_Trampoline_VFunc__ \
}

///////////////////////////////////////////////////
// Internal implements required additional headers

#include <string.h>
#include <stdlib.h>
#include <math.h>

///////////////////////////////////////////////////
// Internal runtime functions

extern void* il2c_get_uninitialized_object_internal__(IL2C_RUNTIME_TYPE type, uintptr_t bodySize);

extern void il2c_default_mark_handler__(void* pReference);

extern void il2c_step1_clear_gcmark__(interlock_t comparand);
extern void il2c_step2_mark_gcmark__(void);
extern void il2c_step3_sweep_garbage__(void);

#ifdef __cplusplus
}
#endif

#endif
