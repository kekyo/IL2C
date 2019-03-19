// It uses for internal purpose only.

#ifndef __IL2C_PRIVATE_H__
#define __IL2C_PRIVATE_H__

#pragma once

#if defined(_DEBUG)
#define IL2C_USE_LINE_INFORMATION
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef volatile long interlock_t;

///////////////////////////////////////////////////
// Internal depended definitions

#include "Private/msvc_win32.h"
#include "Private/msvc_uefi.h"
#include "Private/msvc_wdm.h"
#include "Private/gcc_win32.h"
#include "Private/gcc_linux.h"
#include "Private/arduino_all.h"

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
extern void il2c_runtime_debug_log__(const wchar_t* message);
extern void il2c_runtime_debug_log_format__(const wchar_t* format, ...);
#define il2c_runtime_debug_log(message) il2c_runtime_debug_log__(message L"\r\n")
#define il2c_runtime_debug_log_format(format, ...) il2c_runtime_debug_log_format__(format L"\r\n", __VA_ARGS__)
#else
#define il2c_runtime_debug_log(message)
#define il2c_runtime_debug_log_format(format, ...)
#endif

extern void il2c_initialize__(void);
extern void il2c_shutdown__(void);

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

// IL2C_REF_HEADER_DECL.characteristic
#define IL2C_CHARACTERISTIC_LIVE ((interlock_t)0x40000000UL)
#define IL2C_CHARACTERISTIC_CONST ((interlock_t)0x80000000UL)

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
#include <stdarg.h>

///////////////////////////////////////////////////
// Internal runtime functions

#if defined(IL2C_USE_LINE_INFORMATION)
extern void* il2c_get_uninitialized_object_internal__(IL2C_RUNTIME_TYPE type, uintptr_t bodySize, const char* pFile, int line);
#else
extern void* il2c_get_uninitialized_object_internal__(IL2C_RUNTIME_TYPE type, uintptr_t bodySize);
#endif

extern void il2c_register_fixed_instance__(void* pReference);
extern void il2c_unregister_fixed_instance__(void* pReference);
extern void il2c_default_mark_handler__(void* pReference);

typedef volatile struct IL2C_THREAD_CONTEXT_DECL
{
    IL2C_EXECUTION_FRAME* pFrame__;
    IL2C_EXCEPTION_FRAME* pUnwindTarget__;
    volatile intptr_t rawHandle__;
} IL2C_THREAD_CONTEXT;

#if defined(IL2C_USE_LINE_INFORMATION)
extern IL2C_THREAD_CONTEXT* il2c_acquire_thread_context__(
    /* EXECUTION_FRAME__* */ volatile void* pNewFrame, const char* pFile, int line);
#else
extern IL2C_THREAD_CONTEXT* il2c_acquire_thread_context__(
    /* EXECUTION_FRAME__* */ volatile void* pNewFrame);
#endif

///////////////////////////////////////////////////////////////////
// TODO: move defs

extern void il2c_write(const wchar_t* s);
extern void il2c_writeline(const wchar_t* s);
extern bool il2c_readline(wchar_t* buffer, int32_t length);

#ifdef __cplusplus
}
#endif

#endif
