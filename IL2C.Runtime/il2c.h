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

typedef void (*IL2C_MARK_HANDLER)(/* System_Object* */ void* pReference);

typedef const struct IL2C_RUNTIME_TYPE_DECL
{
    const char* pTypeName;
    const uint32_t flags;
    const uint32_t bodySize;
    /* internalcall */ const IL2C_MARK_HANDLER IL2C_MarkHandler;
    const struct IL2C_RUNTIME_TYPE_DECL* baseType;
} IL2C_RUNTIME_TYPE_DECL;

typedef int16_t (*IL2C_EXCEPTION_FILTER)(/* System_Exception* */ void* ex);

struct IL2C_EXCEPTION_FRAME
{
    IL2C_EXCEPTION_FRAME* pNext;
    IL2C_EXECUTION_FRAME* pFrame;
    /* System_Exception* */ void* ex;
    IL2C_EXCEPTION_FILTER filter;
    jmp_buf saved;
};

typedef volatile struct IL2C_REF_HEADER
{
    IL2C_REF_HEADER* pNext;
    IL2C_RUNTIME_TYPE_DECL* type;
    interlock_t gcMark;
} IL2C_REF_HEADER;

///////////////////////////////////////////////////////
// Runtime type information related declarations

// IL2C_RUNTIME_TYPE_DECL.flags
#define IL2C_TYPE_REFERENCE 0x00
#define IL2C_TYPE_VALUE 0x01
#define IL2C_TYPE_INTEGER 0x03
#define IL2C_TYPE_UNSIGNED_INTEGER 0x0b
#define IL2C_TYPE_STATIC 0x10

#define il2c_typeof(typeName) \
    (&(__##typeName##_RUNTIME_TYPE__))

#define il2c_sizeof__(type) \
    (((type)->flags & IL2C_TYPE_VALUE) ? (type)->bodySize : (uint32_t)sizeof(intptr_t))
#define il2c_sizeof(typeName) \
    (il2c_sizeof__(il2c_typeof(typeName)))

// dynamic cast operator
extern void* il2c_isinst__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE_DECL* type);
#define il2c_isinst_unsafe(pReference, typeName) \
    ((pReference)->vptr0__->il2c_isinst__(pReference, il2c_typeof(typeName)))
#define il2c_isinst(pReference, typeName) \
    (((pReference) != NULL) ? il2c_isinst_unsafe(pReference, typeName) : NULL)
extern void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE_DECL* type);
#define il2c_castclass(pReference, typeName) \
    (((pReference) != NULL) ? il2c_castclass__(pReference, il2c_typeof(typeName)) : NULL)

// static cast operators
#define il2c_cast_from_interface(typeName, interfaceTypeName, pInterface) \
    ((typeName*)(((uint8_t*)(pInterface)) - \
     (offsetof(typeName, vptr_##interfaceTypeName##__) - \
      offsetof(typeName, vptr0__))))
#define il2c_cast_to_interface(interfaceTypeName, typeName, pReference) \
    ((interfaceTypeName *)(((uint8_t*)(pReference)) + \
     (offsetof(typeName, vptr_##interfaceTypeName##__) - \
      offsetof(typeName, vptr0__))))

///////////////////////////////////////////////////////
// Garbage collector related declarations

extern void il2c_collect();

extern void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE_DECL* type, void* vptr0);
#define il2c_get_uninitialized_object(typeName) \
    il2c_get_uninitialized_object__(il2c_typeof(typeName), (void*)(&(__##typeName##_VTABLE__)))

extern void il2c_link_execution_frame(/* IL2C_EXECUTION_FRAME* */ volatile void* pNewFrame);
extern void il2c_unlink_execution_frame(/* IL2C_EXECUTION_FRAME* */ volatile void* pFrame);

extern void il2c_mark_from_handler__(/* System_Object* */ void* pReference);
#define il2c_try_mark_from_handler(pReference) \
    { void* pRef = pReference; if (pRef != NULL) il2c_mark_from_handler__(pRef); }

extern void il2c_no_mark_handler__(/* System_Object* */ void* pReference);
#define IL2C_DEFAULT_MARK_HANDLER ((IL2C_MARK_HANDLER)il2c_no_mark_handler__)

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
#include <System.InvalidCastException.h>
#include <System.IndexOutOfRangeException.h>

///////////////////////////////////////////////////////
// Boxing related declarations

extern System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType, const void* vptr0);
extern System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType, IL2C_RUNTIME_TYPE_DECL* stackType, const void* vptr0);
extern void* il2c_unbox__(
    /* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE_DECL* valueType);

#define il2c_box(pValue, valueTypeName) \
    (il2c_box__(pValue, il2c_typeof(valueTypeName), &__##valueTypeName##_VTABLE__))
#define il2c_box2(pValue, valueTypeName, stackTypeName) \
    (il2c_box2__(pValue, il2c_typeof(valueTypeName), il2c_typeof(stackTypeName), &__##valueTypeName##_VTABLE__))
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

#define il2c_try(filterName) \
    { \
        IL2C_EXCEPTION_FRAME unwind_target__; \
        int continuationIndex__ = -1; \
        il2c_link_unwind_target__(&unwind_target__, (IL2C_EXCEPTION_FILTER)(filterName)); \
        do { \
            switch (setjmp(*(jmp_buf*)&unwind_target__.saved)) { \
            case 0: // try

#define il2c_leave(continuationIndex) \
                continuationIndex__ = continuationIndex; \
                break

#define il2c_catch(filteredNumber, symbolName) \
                il2c_assert(0); /* reached if don't emit leave. */ \
            case filteredNumber : \
                il2c_assert(unwind_target__.ex != NULL); \
                symbolName = unwind_target__.ex;

#define il2c_finally \
                il2c_assert(0); /* reached if don't emit leave. */ \
            } \
        } while (0); \
        do { \
            {

#define il2c_endfinally \
                if (unwind_target__.ex != NULL) il2c_rethrow(); \
                break

#define il2c_leave_to \
                il2c_assert(0); /* reached if don't emit leave or endfinally. */ \
            } \
        } while (0); \
        il2c_unlink_unwind_target__(&unwind_target__); \
        do { \
            { \
                switch (continuationIndex__)

#define il2c_leave_bind(continuationIndex, labelName) \
                case continuationIndex : goto labelName

#define il2c_end_try \
                il2c_assert(0); /* reached if don't emit leave or endfinally. */ \
            } \
        } while (0); \
    }

///////////////////////////////////////////////////////
// Another special runtime helper functions

extern double il2c_fmod(double lhs, double rhs);
extern void il2c_break();

extern void il2c_throw_invalidcastexception__();

#ifdef __cplusplus
}
#endif

#endif
