#ifndef __IL2C_H__
#define __IL2C_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <float.h>

///////////////////////////////////////////////////////
// Initialize / shutdown runtime

extern void il2c_initialize();
extern void il2c_shutdown();

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef long interlock_t;

typedef struct IL2C_EXECUTION_FRAME IL2C_EXECUTION_FRAME;
typedef struct IL2C_REF_HEADER IL2C_REF_HEADER;

typedef void (*IL2C_MARK_HANDLER)(void*);

typedef const struct
{
    const char* pTypeName;
    uint32_t flags;
    uint32_t bodySize;
    /* internalcall */ IL2C_MARK_HANDLER IL2C_MarkHandler;
} IL2C_RUNTIME_TYPE_DECL;

struct IL2C_REF_HEADER
{
    IL2C_REF_HEADER* pNext;
    IL2C_RUNTIME_TYPE_DECL* type;
    interlock_t gcMark;
};

///////////////////////////////////////////////////////
// Runtime type information related declarations

// IL2C_RUNTIME_TYPE_DECL.flags
#define IL2C_TYPE_STANDARD 0x00

#define il2c_typeof(typeName) (&__##typeName##_RUNTIME_TYPE__)
#define il2c_sizeof(typeName) (il2c_typeof(typeName)->bodySize)

// dynamic cast operator
#define il2c_runtime_cast(pReference, typeName) \
    ((typeName*)((pReference)->vptr0__->IL2C_RuntimeCast((pReference), il2c_typeof(typeName))))

// static cast operators
#define il2c_cast_from_interface(typeName, interfaceTypeName, pInterface) \
    ((typeName*)(((intptr_t)(pInterface)) - \
     (offsetof(typeName, vptr_##interfaceTypeName##__) - \
      offsetof(typeName, vptr0__))))
#define il2c_cast_to_interface(interfaceTypeName, typeName, pReference) \
    ((interfaceTypeName *)(((intptr_t)(pReference)) + \
     (offsetof(typeName, vptr_##interfaceTypeName##__) - \
      offsetof(typeName, vptr0__))))

///////////////////////////////////////////////////////
// Garbage collector related declarations

extern void il2c_collect();

extern void* il2c_get_uninitialized_object(IL2C_RUNTIME_TYPE_DECL* type);

extern void il2c_link_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pNewFrame);
extern void il2c_unlink_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pFrame);

extern void il2c_mark_from_handler(void* pReference);
#define il2c_try_mark_from_handler(pReference) \
    { void* pRef = pReference; if (pRef != NULL) il2c_mark_from_handler(pRef); }

///////////////////////////////////////////////////////
// The basis types

// It's pseudo referenced-type null value used by ldnull.
typedef void* untyped_ptr;

// TODO: Runtime-related types
//   System.Array
//   System.Enum
//   System.Delegate, System.MulticastDelegate
//   System.Exception
//   System.Type

#include <System.Object.h>
#include <System.ValueType.h>
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

///////////////////////////////////////////////////////
// Boxing related declarations

extern System_Object* il2c_box1__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType);
extern System_Object* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType, IL2C_RUNTIME_TYPE_DECL* stackType);
extern void* il2c_unbox__(
    System_Object* pObject, IL2C_RUNTIME_TYPE_DECL* valueType);

#define il2c_box1(pValue, valueTypeName) \
    (il2c_box1__(pValue, il2c_typeof(valueTypeName)))
#define il2c_box2(pValue, valueTypeName, stackTypeName) \
    (il2c_box2__(pValue, il2c_typeof(valueTypeName), il2c_typeof(stackTypeName)))
#define il2c_unbox(pObject, valueTypeName) \
    (il2c_unbox__(pObject, il2c_typeof(valueTypeName)))

///////////////////////////////////////////////////////
// Another special runtime helper functions

extern double il2c_fmod(double lhs, double rhs);
extern void il2c_break();

#ifdef __cplusplus
}
#endif

#endif
