#ifndef __IL2C_H__
#define __IL2C_H__

#pragma once

#if defined(_DEBUG)
#define IL2C_USE_LINE_INFORMATION
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && defined(_WIN32)
#include <intrin.h>
#include <setjmp.h> // TODO:

#elif defined(__GNUC__)

#if defined(__x86_64__) || defined(__i386__)
#include <x86intrin.h>
#elif defined(__ARM_NEON__)
#include <arm_neon.h>
#elif defined(__IWMMXT__)
#include <arm_neon.h>
#endif

#include <setjmp.h>
#else

#include <setjmp.h>

#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <float.h>

#if defined(_MSC_VER) && defined(UEFI)
#if defined(_DEBUG)
extern void il2c_cause_assert__(const wchar_t* pFile, int line, const wchar_t* pExpr);
#define il2c_cause_assert_(pFile, line, pExpr) il2c_cause_assert__(L##pFile, line, L##pExpr)
#define il2c_cause_assert(pFile, line, pExpr) il2c_cause_assert_(pFile, line, pExpr)
#define il2c_assert(expr) do { if (!(expr)) il2c_cause_assert(__FILE__, __LINE__, #expr); } while (0)
#else
#define il2c_assert(expr)
#endif
extern int32_t* il2c_errno__(void);
#define il2c_errno (*il2c_errno__())
#else
#include <assert.h>
#include <errno.h>
#define il2c_assert assert
#define il2c_errno errno
#endif

#define il2c_setjmp setjmp
#define IL2C_JUMP_BUFFER jmp_buf

///////////////////////////////////////////////////////
// Initialize / shutdown runtime

#if defined(_WIN32)
#if defined(UEFI)
extern void il2c_initialize(void* imageHandle, void* pSystemTable);
extern void il2c_shutdown();
#elif defined(_WDM)
extern void il2c_initialize(void);  // TODO:
extern void il2c_shutdown(void);
#else
extern void il2c_initialize(void);
extern void il2c_shutdown(void);
#endif
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
#define IL2C_TYPE_INTEGER 0x03
#define IL2C_TYPE_VARIABLE 0x04
#define IL2C_TYPE_UNSIGNED_INTEGER 0x0b
#define IL2C_TYPE_STATIC 0x10
#define IL2C_TYPE_INTERFACE 0x20

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
    (((pReference) != NULL) ? il2c_isinst__(pReference, il2c_typeof(typeName)) : NULL)

extern void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type);
#define il2c_castclass(pReference, typeName) \
    (((pReference) != NULL) ? il2c_castclass__(pReference, il2c_typeof(typeName)) : NULL)

// static cast operators
#define il2c_adjustor_offset(typeName, interfaceTypeName) \
    (offsetof(typeName, vptr_##interfaceTypeName##__) - offsetof(typeName, vptr0__))
#define il2c_adjusted_reference(pRawReference) \
    ((void*)((intptr_t)(pRawReference) - (**(const intptr_t**)(pRawReference))))

#define il2c_cast_to_interface__(interfaceTypeName, offset, pReference) \
    ((interfaceTypeName*)(((uint8_t*)(pReference)) + (offset)))
#define il2c_cast_to_interface(interfaceTypeName, typeName, pReference) \
    ((pReference != NULL) ? \
        il2c_cast_to_interface__(interfaceTypeName, il2c_adjustor_offset(typeName, interfaceTypeName), (pReference)) : \
        NULL)

// Complex but cost effective cast operator. We can use only boxed value.
#define il2c_cast_from_boxed_to_interface(interfaceTypeName, size, interfaceIndex, pReference) \
    il2c_cast_to_interface__(interfaceTypeName, sizeof(System_ValueType) + (size) + (interfaceIndex) * sizeof(void*), (pReference))

///////////////////////////////////////////////////////
// Garbage collector related declarations

extern void il2c_collect(void);

#if defined(IL2C_USE_LINE_INFORMATION)
extern void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type, const char* pFile, int line);
#define il2c_get_uninitialized_object(typeName) \
    il2c_get_uninitialized_object__(il2c_typeof(typeName), __FILE__, __LINE__)

extern void il2c_link_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pNewFrame, const char* pFile, int line);
extern void il2c_unlink_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pFrame, const char* pFile, int line);
#define il2c_link_execution_frame(pNewFrame) il2c_link_execution_frame__(pNewFrame, __FILE__, __LINE__)
#define il2c_unlink_execution_frame(pFrame) il2c_unlink_execution_frame__(pFrame, __FILE__, __LINE__)
#else
extern void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type);
#define il2c_get_uninitialized_object(typeName) \
    il2c_get_uninitialized_object__(il2c_typeof(typeName))

extern void il2c_link_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pNewFrame);
extern void il2c_unlink_execution_frame__(/* IL2C_EXECUTION_FRAME* */ volatile void* pFrame);
#define il2c_link_execution_frame(pNewFrame) il2c_link_execution_frame__(pNewFrame)
#define il2c_unlink_execution_frame(pFrame) il2c_unlink_execution_frame__(pFrame)
#endif

extern const uintptr_t* il2c_initializer_count;
extern void il2c_register_static_fields(/* IL2C_STATIC_FIELDS* */ volatile void* pStaticFields);

///////////////////////////////////////////////////////
// Basic exceptions

extern void il2c_throw_nullreferenceexception__(void);
extern void il2c_throw_invalidcastexception__(void);
extern void il2c_throw_indexoutofrangeexception__(void);
extern void il2c_throw_formatexception__(void);

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

// Independent types for IL2C core.
#include "System/Console.h"
#include "System/IDisposable.h"
#include "System/Threading/Interlocked.h"
#include "System/Threading/ThreadStart.h"
#include "System/Threading/Thread.h"

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

extern void il2c_throw__(System_Exception* ex);
#define il2c_throw(ex) \
    il2c_throw__((System_Exception*)ex)

extern void il2c_rethrow(void);
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
                il2c_assert(0); /* reached if don't emit leave. */ \
            case filteredNumber : \
                il2c_assert(unwind_target_##nestedIndex##__.ex != NULL); \
                symbolName = unwind_target_##nestedIndex##__.ex;

#define il2c_finally(nestedIndex) \
                il2c_assert(0); /* reached if don't emit leave. */ \
            } \
            break; \
        } \
        while (1) { \
            {

#define il2c_endfinally(nestedIndex) \
                if (unwind_target_##nestedIndex##__.ex != NULL) il2c_rethrow(); \
                break

#define il2c_leave_to(nestedIndex) \
            } \
            break; \
        } \
        il2c_unlink_unwind_target__(&unwind_target_##nestedIndex##__); \
        while (1) { \
            {

#define il2c_leave_bind(nestedIndex, continuationIndex, labelName) \
                if (continuationIndex_##nestedIndex##__ == continuationIndex) goto labelName

#define il2c_leave_through(nestedIndex, continuationIndex, parentNestedIndex) \
                if (continuationIndex_##nestedIndex##__ == continuationIndex) \
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
