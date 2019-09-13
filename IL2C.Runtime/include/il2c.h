/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef IL2C_H__
#define IL2C_H__

#pragma once

#if defined(_DEBUG)
#define IL2C_USE_LINE_INFORMATION
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)

#if defined(_WDM) || defined(UEFI)
#undef _WIN32
#endif

#include <intrin.h>

#define il2c_assume__(expr) __assume(expr)
#define il2c_likely__(expr) (expr)
#define il2c_unlikely__(expr) (expr)
#define il2c_noreturn__ __declspec(noreturn)

#elif defined(__GNUC__)

#if defined(__x86_64__) || defined(__i386__)
#include <x86intrin.h>
#elif defined(__ARM_NEON__)
#include <arm_neon.h>
#elif defined(__IWMMXT__)
#include <arm_neon.h>
#endif

#define il2c_assume__(expr) do { if (!(expr)) __builtin_unreachable(); } while (0)
#define il2c_likely__(expr) __builtin_expect(!!(expr), 1)
#define il2c_unlikely__(expr) __builtin_expect(!!(expr), 0)
#define il2c_noreturn__ __attribute__((noreturn))

#else

#define il2c_assume__(expr) ((void)0)
#define il2c_likely__(expr) (expr)
#define il2c_unlikely__(expr) (expr)
#define il2c_noreturn__

#endif

#include <stdint.h>

#if defined(UEFI)

#if defined(_M_IX86)

typedef struct il2c_jmp_buf_t
{
    uint32_t Edx;
    uint32_t Ebx;
    uint32_t Esp;
    uint32_t Ebp;
    uint32_t Esi;
    uint32_t Edi;
    uint32_t Eip;
} *il2c_jmp_buf;

extern int __fastcall il2c_setjmp(il2c_jmp_buf jb);
extern void __fastcall il2c_longjmp(il2c_jmp_buf jb, int retval);

#elif defined(_M_X64)

typedef unsigned __int64 uint128_t[2];

typedef struct il2c_jmp_buf_t
{
    uint64_t Frame;
    uint64_t Rbx;
    uint64_t Rsp;
    uint64_t Rbp;
    uint64_t Rsi;
    uint64_t Rdi;
    uint64_t R12;
    uint64_t R13;
    uint64_t R14;
    uint64_t R15;
    uint64_t Rip;
    uint32_t MxCsr;
    uint16_t FpCsr;
    uint16_t Spare;
    uint128_t Xmm6;
    uint128_t Xmm7;
    uint128_t Xmm8;
    uint128_t Xmm9;
    uint128_t Xmm10;
    uint128_t Xmm11;
    uint128_t Xmm12;
    uint128_t Xmm13;
    uint128_t Xmm14;
    uint128_t Xmm15;
} *il2c_jmp_buf;

extern int il2c_setjmp(il2c_jmp_buf jb);
extern void il2c_longjmp(il2c_jmp_buf jb, int retval);

#endif

#define IL2C_JUMP_BUFFER il2c_jmp_buf

#if defined(_DEBUG)
extern void il2c_cause_assert__(const wchar_t* pFile, int line, const wchar_t* pExpr);
#define il2c_cause_assert_(pFile, line, pExpr) il2c_cause_assert__(L##pFile, line, L##pExpr)
#define il2c_cause_assert(pFile, line, pExpr) il2c_cause_assert_(pFile, line, pExpr)
#define il2c_assert__(expr, pFile, line) do { if (!(expr)) il2c_cause_assert(pFile, line, #expr); } while (0)
#define il2c_assert(expr) il2c_assert__(expr, __FILE__, __LINE__)
extern double il2c_fmod(double x, double y);
#else
#define il2c_assert__(expr, pFile, line) il2c_assume__(expr)
#define il2c_assert(expr) il2c_assume__(expr)
#define il2c_fmod fmod
#endif

extern int32_t* il2c_errno__(void);
#define il2c_errno (*il2c_errno__())

#else

#include <setjmp.h>
#include <errno.h>
#include <assert.h>

#define IL2C_JUMP_BUFFER jmp_buf
#define il2c_setjmp setjmp
#define il2c_longjmp longjmp
#define il2c_errno errno
#define il2c_fmod fmod

#if defined(_DEBUG)
#define il2c_assert__(expr, pFile, line) assert(expr)
#define il2c_assert(expr) assert(expr)
#else
#define il2c_assert__(expr, pFile, line) il2c_assume__(expr)
#define il2c_assert(expr) il2c_assume__(expr)
#endif

#endif

#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <float.h>
#include <math.h>

///////////////////////////////////////////////////////
// Initialize / shutdown runtime

#if defined(UEFI)
#undef WIN32
extern void il2c_initialize(void* imageHandle, void* pSystemTable);
extern void il2c_shutdown();
#endif

#if defined(_WDM)
#undef WIN32
extern void il2c_initialize(void);
extern void il2c_shutdown(void);
#endif

#if defined(_WIN32)
extern void il2c_initialize(void);
extern void il2c_shutdown(void);
#endif

#if defined(__linux__)
extern void il2c_initialize(void);
extern void il2c_shutdown(void);
#endif

#if defined(ARDUINO)
extern void il2c_initialize(void);
extern void il2c_shutdown(void);
#endif

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef volatile long interlock_t;

typedef volatile struct IL2C_GC_TRACKING_INFORMATION_DECL IL2C_GC_TRACKING_INFORMATION;
typedef IL2C_GC_TRACKING_INFORMATION IL2C_EXECUTION_FRAME;
typedef IL2C_GC_TRACKING_INFORMATION IL2C_STATIC_FIELDS;

typedef volatile struct IL2C_EXCEPTION_FRAME_DECL IL2C_EXCEPTION_FRAME;
typedef volatile struct IL2C_REF_HEADER_DECL IL2C_REF_HEADER;

typedef const struct IL2C_RUNTIME_TYPE_DECL* IL2C_RUNTIME_TYPE;

typedef int16_t (*IL2C_EXCEPTION_FILTER)(/* System_Exception* */ void* ex);

struct IL2C_EXCEPTION_FRAME_DECL
{
    IL2C_EXCEPTION_FRAME* pNext;
    IL2C_EXECUTION_FRAME* pFrame;
    /* System_Exception* */ void* ex;
    IL2C_EXCEPTION_FILTER filter;
    IL2C_JUMP_BUFFER saved;
};

struct IL2C_REF_HEADER_DECL
{
    IL2C_REF_HEADER* pNext;
    IL2C_RUNTIME_TYPE type;
    interlock_t characteristic;
};

///////////////////////////////////////////////////////
// Runtime type information related declarations

#define IL2C_DECLARE_RUNTIME_TYPE(typeName) \
extern const uintptr_t typeName##_RUNTIME_TYPE__[]

// IL2C_RUNTIME_TYPE_DECL.flags
#define IL2C_TYPE_REFERENCE 0x00
#define IL2C_TYPE_VALUE 0x01
#define IL2C_TYPE_INTEGER (0x02 | IL2C_TYPE_VALUE)
#define IL2C_TYPE_WITH_MARK_HANDLER 0x04
#define IL2C_TYPE_VARIABLE 0x08
#define IL2C_TYPE_UNSIGNED_INTEGER (0x10 | IL2C_TYPE_INTEGER)
#define IL2C_TYPE_STATIC 0x20
#define IL2C_TYPE_INTERFACE 0x40

#define il2c_typeof(typeName) \
    ((IL2C_RUNTIME_TYPE)&(typeName##_RUNTIME_TYPE__))
#define il2c_vptrof(typeName) \
    (&(typeName##_VTABLE__))

extern uint32_t il2c_sizeof__(IL2C_RUNTIME_TYPE type);
#define il2c_sizeof(typeName) \
    (il2c_sizeof__(il2c_typeof(typeName)))

// dynamic cast operator
extern void* il2c_isinst__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type);
#define il2c_isinst(pReference, typeName) \
    (il2c_likely__((pReference) != NULL) ? il2c_isinst__(pReference, il2c_typeof(typeName)) : NULL)

extern void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type);
#define il2c_castclass(pReference, typeName) \
    (il2c_likely__((pReference) != NULL) ? il2c_castclass__(pReference, il2c_typeof(typeName)) : NULL)

// static cast operators
#define il2c_adjustor_offset(typeName, interfaceTypeName) \
    (offsetof(typeName, vptr_##interfaceTypeName##__) - offsetof(typeName, vptr0__))
#define il2c_adjusted_reference(pRawReference) \
    ((void*)((intptr_t)(pRawReference) - (**(const intptr_t**)(pRawReference))))

#define il2c_cast_to_interface__(interfaceTypeName, offset, pReference) \
    ((interfaceTypeName*)(((uint8_t*)(pReference)) + (offset)))
#define il2c_cast_to_interface(interfaceTypeName, typeName, pReference) \
    (il2c_likely__((pReference) != NULL) ? \
        il2c_cast_to_interface__(interfaceTypeName, il2c_adjustor_offset(typeName, interfaceTypeName), (pReference)) : \
        NULL)

// Complex but cost effective cast operator. We can use only boxed value.
#define il2c_cast_from_boxed_to_interface(interfaceTypeName, size, interfaceIndex, pReference) \
    il2c_cast_to_interface__(interfaceTypeName, sizeof(System_ValueType) + (size) + (interfaceIndex) * sizeof(void*), (pReference))

///////////////////////////////////////////////////////
// Garbage collector related declarations

#if defined(IL2C_USE_LINE_INFORMATION)
extern void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type, const char* pFile, int line);
#define il2c_get_uninitialized_object(typeName) \
    il2c_get_uninitialized_object__(il2c_typeof(typeName), __FILE__, __LINE__)

extern void il2c_link_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pNewFrame, const char* pFile, int line);
extern void* il2c_unlink_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pFrame, void* pReference, const char* pFile, int line);
#define il2c_link_execution_frame(pNewFrame) il2c_link_execution_frame__((pNewFrame), __FILE__, __LINE__)
#define il2c_unlink_execution_frame(pFrame, pReference) il2c_unlink_execution_frame__((pFrame), (pReference), __FILE__, __LINE__)
#else
extern void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type);
#define il2c_get_uninitialized_object(typeName) \
    il2c_get_uninitialized_object__(il2c_typeof(typeName))

extern void il2c_link_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pNewFrame);
extern void* il2c_unlink_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pFrame, void* pReference);
#define il2c_link_execution_frame(pNewFrame) il2c_link_execution_frame__(pNewFrame)
#define il2c_unlink_execution_frame(pFrame, pReference) il2c_unlink_execution_frame__((pFrame), (pReference))
#endif

extern void* il2c_cleanup_at_return__(void* pReference);
#define il2c_return() \
    il2c_cleanup_at_return__(NULL); return
#define il2c_return_unlink(pFrame) \
    il2c_unlink_execution_frame((pFrame), NULL); return
#define il2c_return_with_objref(pReference) \
    return il2c_cleanup_at_return__(pReference)
#define il2c_return_with_value(value) \
    il2c_cleanup_at_return__(NULL); return (value)
#define il2c_return_unlink_with_objref(pFrame, pReference) \
    return il2c_unlink_execution_frame((pFrame), (pReference))
#define il2c_return_unlink_with_value(pFrame, value) \
    il2c_unlink_execution_frame((pFrame), NULL); return (value)

extern const uintptr_t* il2c_initializer_count;
extern void il2c_register_static_fields(/* IL2C_STATIC_FIELDS* */ volatile void* pStaticFields);

///////////////////////////////////////////////////////
// Basic exceptions

extern il2c_noreturn__ void il2c_throw_nullreferenceexception__(void);
extern il2c_noreturn__ void il2c_throw_invalidcastexception__(void);
extern il2c_noreturn__ void il2c_throw_indexoutofrangeexception__(void);
extern il2c_noreturn__ void il2c_throw_formatexception__(void);

///////////////////////////////////////////////////////
// The basis types

// It's pseudo referenced-type null value used by ldnull.
typedef void* untyped_ptr;

#include "System/Object.h"
#include "System/Type.h"
#include "System/ValueType.h"
#include "System/Array.h"
#include "System/Char.h"
#include "System/String.h"
#include "System/Boolean.h"
#include "System/Byte.h"
#include "System/Int16.h"
#include "System/Int32.h"
#include "System/Int64.h"
#include "System/SByte.h"
#include "System/UInt16.h"
#include "System/UInt32.h"
#include "System/UInt64.h"
#include "System/IntPtr.h"
#include "System/UIntPtr.h"
#include "System/Single.h"
#include "System/Double.h"
#include "System/Enum.h"
#include "System/Delegate.h"
#include "System/MulticastDelegate.h"
#include "System/RuntimeFieldHandle.h"
#include "System/Runtime/CompilerServices/RuntimeHelpers.h"
#include "System/Exception.h"
#include "System/NullReferenceException.h"
#include "System/InvalidCastException.h"
#include "System/IndexOutOfRangeException.h"
#include "System/IFormatProvider.h"
#include "System/IFormattable.h"
#include "System/FormatException.h"
#include "System/GC.h"
#include "System/Runtime/InteropServices/GCHandleType.h"
#include "System/Runtime/InteropServices/GCHandle.h"
#include "System/Runtime/InteropServices/NativePointer.h"
#include "System/IDisposable.h"
#include "System/Threading/Interlocked.h"
#include "System/Threading/Monitor.h"
#include "System/Threading/ThreadStart.h"
#include "System/Threading/ParameterizedThreadStart.h"
#include "System/Threading/Thread.h"
#include "System/EventArgs.h"
#include "System/UnhandledExceptionEventArgs.h"
#include "System/UnhandledExceptionEventHandler.h"
#include "System/AppDomain.h"

// Independent types for IL2C core.
#include "System/Console.h"

///////////////////////////////////////////////////////
// Boxing related declarations

// It made identical type expression for boxed value type.
#define il2c_boxedtype(valueTypeName) \
    System_ValueType

#if defined(IL2C_USE_LINE_INFORMATION)
extern System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, const char* pFile, int line);
extern System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType, const char* pFile, int line);

#define il2c_box(pValue, valueTypeName) \
    (il2c_box__(pValue, il2c_typeof(valueTypeName), __FILE__, __LINE__))
#define il2c_box2(pValue, valueTypeName, stackTypeName) \
    (il2c_box2__(pValue, il2c_typeof(valueTypeName), il2c_typeof(stackTypeName), __FILE__, __LINE__))
#else
extern System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType);
extern System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType);

#define il2c_box(pValue, valueTypeName) \
    (il2c_box__(pValue, il2c_typeof(valueTypeName)))
#define il2c_box2(pValue, valueTypeName, stackTypeName) \
    (il2c_box2__(pValue, il2c_typeof(valueTypeName), il2c_typeof(stackTypeName)))
#endif

extern void* il2c_unbox__(
    /* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE valueType);

#define il2c_unbox(pObject, valueTypeName) \
    ((valueTypeName*)il2c_unbox__(pObject, il2c_typeof(valueTypeName)))
#define il2c_unsafe_unbox__(pObject, typeName) \
    ((typeName*)(((uint8_t*)pObject) + sizeof(System_ValueType)))

/////////////////////////////////////////////////
// Exception special functions

extern il2c_noreturn__ void il2c_throw__(System_Exception* ex);
#define il2c_throw(ex) \
    il2c_throw__((System_Exception*)ex)
extern il2c_noreturn__ void il2c_rethrow(void);

extern void il2c_link_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget, IL2C_EXCEPTION_FILTER filter);
extern void il2c_unlink_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget);

#define IL2C_FILTER_NOMATCH (0)
#define IL2C_FILTER_FINALLY (-1)

#define il2c_try(nestIndex, filterName) \
    { \
        IL2C_EXCEPTION_FRAME unwind_target_##nestIndex##__; \
        int continuationIndex_##nestIndex##__ = -1; \
        il2c_link_unwind_target__(&unwind_target_##nestIndex##__, (IL2C_EXCEPTION_FILTER)(filterName)); \
        while (1) { \
            switch (il2c_setjmp(*(IL2C_JUMP_BUFFER*)&unwind_target_##nestIndex##__.saved)) { \
            case 0: // try

#define il2c_leave(nestedIndex, continuationIndex) \
                continuationIndex_##nestedIndex##__ = continuationIndex; \
                break

#define il2c_catch(nestedIndex, filteredNumber, symbolName) \
            case filteredNumber : \
                il2c_assert(unwind_target_##nestedIndex##__.ex != NULL); \
                symbolName = unwind_target_##nestedIndex##__.ex;

#define il2c_finally(nestedIndex) \
            } \
            break; \
        } \
        while (1) { \
            {

#define il2c_endfinally(nestedIndex) \
                if (il2c_unlikely__(unwind_target_##nestedIndex##__.ex != NULL)) il2c_rethrow(); \
                break

#define il2c_leave_to(nestedIndex) \
            } \
            break; \
        } \
        il2c_unlink_unwind_target__(&unwind_target_##nestedIndex##__); \
        while (1) { \
            {

#define il2c_leave_bind(nestedIndex, continuationIndex, labelName) \
                if (il2c_unlikely__(continuationIndex_##nestedIndex##__ == continuationIndex)) goto labelName

#define il2c_leave_through(nestedIndex, continuationIndex, parentNestedIndex) \
                if (il2c_unlikely__(continuationIndex_##nestedIndex##__ == continuationIndex)) \
                    continuationIndex_##parentNestedIndex##__ = continuationIndex

#define il2c_end_try(nestedIndex) \
            } \
            break; \
        } \
    }

///////////////////////////////////////////////////////
// Another special runtime helper functions

extern double il2c_fmod(double lhs, double rhs);

#if defined(IL2C_USE_LINE_INFORMATION)
extern void il2c_break__(const char* pFile, int line);
#define il2c_break() il2c_break__(__FILE__, __LINE__)
#else
extern void il2c_break__(void);
#define il2c_break() il2c_break__()
#endif

///////////////////////////////////////////////////////
// Generator macro for runtime type information.

#define IL2C_RUNTIME_TYPE_BEGIN__(typeName, typeNameString, flags, size, baseType, vptr0, markTarget, interfaceCount) \
const uintptr_t typeName##_RUNTIME_TYPE__[] = { \
    (uintptr_t)(typeNameString), \
    flags, \
    size, \
    (uintptr_t)baseType, \
    (uintptr_t)vptr0, \
    (uintptr_t)markTarget, \
    interfaceCount,

#define IL2C_RUNTIME_TYPE_BEGIN(typeName, typeNameString, flags, size, baseTypeName, markTarget, interfaceCount) \
    IL2C_RUNTIME_TYPE_BEGIN__(typeName, typeNameString, flags, size, il2c_typeof(baseTypeName), il2c_vptrof(typeName), markTarget, interfaceCount)

#define IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN(typeName, typeNameString, size, baseTypeName, markTarget, interfaceCount) \
    IL2C_RUNTIME_TYPE_BEGIN__(typeName, typeNameString, IL2C_TYPE_REFERENCE, size, il2c_typeof(baseTypeName), NULL, markTarget, interfaceCount)

#define IL2C_RUNTIME_TYPE_INTERFACE_BEGIN(typeName, typeNameString, interfaceCount) \
    IL2C_RUNTIME_TYPE_BEGIN__(typeName, typeNameString, IL2C_TYPE_INTERFACE, 0, NULL, NULL, 0, interfaceCount)

#define IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(typeName, fieldName) \
    0, \
    offsetof(typeName, fieldName),

#define IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_VALUE(typeName, fieldTypeName, fieldName) \
    (uintptr_t)il2c_typeof(fieldTypeName), \
    offsetof(typeName, fieldName),

#define IL2C_RUNTIME_TYPE_INTERFACE(typeName, interfaceTypeName) \
    (uintptr_t)il2c_typeof(interfaceTypeName), \
    (uintptr_t)il2c_vptrof(typeName##_##interfaceTypeName),

#define IL2C_RUNTIME_TYPE_END() \
}

#define IL2C_RUNTIME_TYPE_STATIC(typeName, typeNameString, baseTypeName) \
const uintptr_t typeName##_RUNTIME_TYPE__[] = { \
    (uintptr_t)(typeNameString), \
    IL2C_TYPE_STATIC, \
    0, \
    (uintptr_t)il2c_typeof(baseTypeName), \
    (uintptr_t)NULL, \
    0, \
    0 \
}

#ifdef __cplusplus
}
#endif

#endif
