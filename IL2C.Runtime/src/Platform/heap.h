// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_HEAP_H__
#define IL2C_PRIVATE_HEAP_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Heap compatibility

#if defined(_MSC_VER)

#if defined(_WIN32)

#define _CRTDBG_MAP_ALLOC 1
#include <crtdbg.h>
#include <stdint.h>
#include <wchar.h>
#include <malloc.h>

#define il2c_check_heap() _CrtCheckMemory()
#define il2c_malloc__ malloc
#define il2c_free__ free
#define il2c_alloca__ _alloca

#define IL2C_MCALLOC_THRESHOLD 256U

#elif defined(UEFI)

#include <stdint.h>
#include <wchar.h>

#define il2c_check_heap() ((void)0)
extern void* il2c_malloc__(size_t size);
extern void il2c_free__(void* p);

#elif defined(_WDM)

#include <stdint.h>
#include <wchar.h>

#define il2c_check_heap() ((void)0)
#define il2c_malloc__(size) ExAllocatePoolWithTag(NonPagedPool, (size), 0x11231123UL)
#define il2c_free__(p) ExFreePoolWithTag(p, 0x11231123UL)
#define il2c_alloca__ _alloca

#define IL2C_MCALLOC_THRESHOLD 32U

#endif

#elif defined(__GNUC__)

#include <stdint.h>
#include <wchar.h>
#include <malloc.h>
#if !defined(_WIN32)
#include <alloca.h>
#endif

#define il2c_check_heap() ((void)0)
#define il2c_malloc__ malloc
#define il2c_free__ free
#define il2c_alloca__ alloca

#endif

#if defined(IL2C_USE_DEBUG_HEAP)
extern int64_t g_HeapBreakAlloc__;
#if defined(IL2C_USE_LINE_INFORMATION)
extern void* il2c_malloc(size_t size, const char* pFile, int32_t line);
#else
extern void* il2c_malloc(size_t size);
#endif
extern void il2c_free(void* p);
#else
#if defined(IL2C_USE_LINE_INFORMATION)
#define il2c_malloc(size, pFile, line) il2c_malloc__(size)
#else
#define il2c_malloc il2c_malloc__
#endif
#define il2c_free il2c_free__
#endif

///////////////////////////////////////////////////
// Stack allocator compatibility

#if defined(IL2C_MCALLOC_THRESHOLD) && defined(il2c_alloca__)

#if defined(IL2C_USE_LINE_INFORMATION)
#define il2c_mcalloc(elementType, name, size) \
    const uint32_t name_csize__ = (uint32_t)(size); \
    const bool is_name_heaped__ = name_csize__ >= (IL2C_MCALLOC_THRESHOLD); \
    elementType* name = is_name_heaped__ ? il2c_malloc(name_csize__, __FILE__, __LINE__) : il2c_alloca__(name_csize__)
#define il2c_mcfree(name) \
    do { if (is_name_heaped__) il2c_free(name); } while (0)
#else
#define il2c_mcalloc(elementType, name, size) \
    const uint32_t name_csize__ = (uint32_t)(size); \
    const bool is_name_heaped__ = name_csize__ >= (IL2C_MCALLOC_THRESHOLD); \
    elementType* name = is_name_heaped__ ? il2c_malloc(name_csize__) : il2c_alloca__(name_csize__)
#define il2c_mcfree(name) \
    do { if (is_name_heaped__) il2c_free(name); } while (0)
#endif

#else

#if defined(IL2C_USE_LINE_INFORMATION)
#define il2c_mcalloc(elementType, name, size) \
    elementType* name = il2c_malloc((size), __FILE__, __LINE__)
#define il2c_mcfree(name) \
    il2c_free(name)
#else
#define il2c_mcalloc(elementType, name, size) \
    elementType* name = il2c_malloc((size))
#define il2c_mcfree(name) \
    il2c_free(name)
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif
