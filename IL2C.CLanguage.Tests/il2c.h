#ifndef __IL2C_H__
#define __IL2C_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef struct __EXECUTION_FRAME__ __EXECUTION_FRAME__;
typedef struct __REF_HEADER__ __REF_HEADER__;

/////////////////////////////////////////////////////////////
// Runtime type information related declarations

typedef void(*__MARK_HANDLER__)(void*);

typedef struct __RUNTIME_TYPE_DEF__
{
    const char* pTypeName;
    const uint16_t bodySize;
    const __MARK_HANDLER__ pMarkHandler;
} __RUNTIME_TYPE_DEF__;

typedef const __RUNTIME_TYPE_DEF__* __RUNTIME_TYPE__;

#define __typeof__(typeName) (__##typeName##_RUNTIME_TYPE__)
#define __sizeof__(typeName) (__typeof__(typeName)->bodySize)

/////////////////////////////////////////////////////////////
// Garbage collector related declarations

extern void __gc_initialize__();
extern void __gc_shutdown__();

extern void __gc_collect__();

extern void __gc_get_uninitialized_object__(void** ppReference, __RUNTIME_TYPE__ type);

extern void __gc_link_execution_frame__(/* __EXECUTION_FRAME__* */ void* pNewFrame);
extern void __gc_unlink_execution_frame__(/* __EXECUTION_FRAME__* */ void* pFrame);

extern void __gc_mark_from_handler__(void* pReference);
#define __TRY_MARK_FROM_HANDLER__(pReference) \
    if ((pReference) != NULL) __gc_mark_from_handler__(pReference)

#define __new__(ppReference, typeName) \
    __gc_get_uninitialized_object__((void**)ppReference, __typeof__(typeName)); \
    typeName##__ctor/* (...) */

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;

static void System_Object__ctor(System_Object* __this)
{
}

extern __RUNTIME_TYPE__ __System_Object_RUNTIME_TYPE__;

/////////////////////////////////////////////////////////////
// Boxing related declarations

extern System_Object* __box__(void* pValue, __RUNTIME_TYPE__ type);
extern void* __unbox__(System_Object* pObject, __RUNTIME_TYPE__ type);

/////////////////////////////////////////////////////////////
// Primitive types

typedef uint8_t System_Byte;
extern __RUNTIME_TYPE__ __System_Byte_RUNTIME_TYPE__;

typedef int8_t System_SByte;
extern __RUNTIME_TYPE__ __System_SByte_RUNTIME_TYPE__;

typedef int16_t System_Int16;
extern __RUNTIME_TYPE__ __System_Int16_RUNTIME_TYPE__;

typedef uint16_t System_UInt16;
extern __RUNTIME_TYPE__ __System_UInt16_RUNTIME_TYPE__;

typedef int32_t System_Int32;
extern __RUNTIME_TYPE__ __System_Int32_RUNTIME_TYPE__;

typedef uint32_t System_UInt32;
extern __RUNTIME_TYPE__ __System_UInt32_RUNTIME_TYPE__;

typedef int64_t System_Int64;
extern __RUNTIME_TYPE__ __System_Int64_RUNTIME_TYPE__;

typedef uint64_t System_UInt64;
extern __RUNTIME_TYPE__ __System_UInt64_RUNTIME_TYPE__;

#ifdef __cplusplus
}
#endif

#endif
