#ifndef __IL2C_H__
#define __IL2C_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#include <intrin.h>
#include <setjmp.h> // TODO:
#else
#include <x86intrin.h>
#include <setjmp.h>
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <float.h>
#include <assert.h>

#define il2c_assert assert
#define il2c_setjmp setjmp
#define IL2C_JUMP_BUFFER jmp_buf

///////////////////////////////////////////////////////
// Initialize / shutdown runtime

extern void il2c_initialize();
extern void il2c_shutdown();

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef long interlock_t;

typedef volatile struct IL2C_EXECUTION_FRAME IL2C_EXECUTION_FRAME;
typedef volatile struct IL2C_EXCEPTION_FRAME IL2C_EXCEPTION_FRAME;
typedef volatile struct IL2C_REF_HEADER IL2C_REF_HEADER;

typedef const struct IL2C_RUNTIME_TYPE_DECL* IL2C_RUNTIME_TYPE;

typedef int16_t (*IL2C_EXCEPTION_FILTER)(/* System_Exception* */ void* ex);

struct IL2C_EXCEPTION_FRAME
{
    IL2C_EXCEPTION_FRAME* pNext;
    IL2C_EXECUTION_FRAME* pFrame;
    /* System_Exception* */ void* ex;
    IL2C_EXCEPTION_FILTER filter;
    IL2C_JUMP_BUFFER saved;
};

typedef volatile struct IL2C_REF_HEADER
{
    IL2C_REF_HEADER* pNext;
    IL2C_RUNTIME_TYPE type;
    interlock_t gcMark;
} IL2C_REF_HEADER;

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
    ((void*)((uint8_t*)(pRawReference) - (**(const intptr_t**)(pRawReference))))

//#define il2c_cast_from_interface(typeName, interfaceTypeName, pInterface) \
//    ((pReference != NULL) ? \
//        ((typeName*)(((uint8_t*)(pInterface)) - \
//         il2c_adjustor_offset(typeName, interfaceTypeName))) : \
//        NULL)

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

extern void il2c_collect();

extern void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type);
#define il2c_get_uninitialized_object(typeName) \
    il2c_get_uninitialized_object__(il2c_typeof(typeName))

extern void il2c_link_execution_frame(/* IL2C_EXECUTION_FRAME* */ volatile void* pNewFrame);
extern void il2c_unlink_execution_frame(/* IL2C_EXECUTION_FRAME* */ volatile void* pFrame);

///////////////////////////////////////////////////////
// The basis types

// It's pseudo referenced-type null value used by ldnull.
typedef void* untyped_ptr;

#include <System.Object.h>
#include <System.Type.h>
#include <System.ValueType.h>
#include <System.Array.h>
#include <System.Char.h>
#include <System.String.h>
#include <System.Boolean.h>
#include <System.Byte.h>
#include <System.Int16.h>
#include <System.Int32.h>
#include <System.Int64.h>
#include <System.SByte.h>
#include <System.UInt16.h>
#include <System.UInt32.h>
#include <System.UInt64.h>
#include <System.IntPtr.h>
#include <System.UIntPtr.h>
#include <System.Single.h>
#include <System.Double.h>
#include <System.Enum.h>
#include <System.Delegate.h>
#include <System.MulticastDelegate.h>
#include <System.RuntimeFieldHandle.h>
#include <System.Runtime.CompilerServices.RuntimeHelpers.h>
#include <System.Exception.h>
#include <System.NullReferenceException.h>
#include <System.InvalidCastException.h>
#include <System.IndexOutOfRangeException.h>
#include <System.GC.h>

///////////////////////////////////////////////////////
// Boxing related declarations

// It made identical type expression for boxed value type.
#define il2c_boxedtype(valueTypeName) \
    System_ValueType

extern System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType);
extern System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType);
extern void* il2c_unbox__(
    /* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE valueType);

#define il2c_box(pValue, valueTypeName) \
    (il2c_box__(pValue, il2c_typeof(valueTypeName)))
#define il2c_box2(pValue, valueTypeName, stackTypeName) \
    (il2c_box2__(pValue, il2c_typeof(valueTypeName), il2c_typeof(stackTypeName)))
#define il2c_unbox(pObject, valueTypeName) \
    ((valueTypeName*)il2c_unbox__(pObject, il2c_typeof(valueTypeName)))
#define il2c_unsafe_unbox__(pObject, typeName) \
    ((typeName*)(((uint8_t*)pObject) + sizeof(System_ValueType)))

/////////////////////////////////////////////////
// Exception special functions

extern void il2c_throw__(System_Exception* ex);
#define il2c_throw(ex) \
    il2c_throw__((System_Exception*)ex)

extern void il2c_rethrow();
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
extern void il2c_break();

extern void il2c_throw_nullreferenceexception__();
extern void il2c_throw_invalidcastexception__();

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

#define IL2C_RUNTIME_TYPE_MARK_TARGET(typeName, fieldName) \
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
