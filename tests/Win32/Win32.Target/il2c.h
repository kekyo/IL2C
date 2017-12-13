#ifndef __IL2C_H__
#define __IL2C_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
typedef long interlock_t;
#else
typedef uint8_t interlock_t;
#endif

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef struct __EXECUTION_FRAME__ __EXECUTION_FRAME__;
typedef struct __REF_HEADER__ __REF_HEADER__;

/////////////////////////////////////////////////////////////
// Runtime type information related declarations

typedef void(*__MARK_HANDLER__)(void*);

typedef const struct __RUNTIME_TYPE_DEF__
{
    const char* pTypeName;
    uint16_t bodySize;
    __MARK_HANDLER__ pMarkHandler;
} __RUNTIME_TYPE_DEF__;

typedef __RUNTIME_TYPE_DEF__* __RUNTIME_TYPE__;

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
    typeName##__ctor

#define __new_ovl__(ppReference, typeName, overloadIndex) \
    __gc_get_uninitialized_object__((void**)ppReference, __typeof__(typeName)); \
    typeName##__ctor_##overloadIndex

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;

static void System_Object__ctor(System_Object* __this)
{
}

extern const __RUNTIME_TYPE__ __System_Object_RUNTIME_TYPE__;

/////////////////////////////////////////////////////////////
// System.ValueType

typedef struct System_ValueType System_ValueType;

static void System_ValueType__ctor(System_ValueType* __this)
{
}

extern const __RUNTIME_TYPE__ __System_ValueType_RUNTIME_TYPE__;

/////////////////////////////////////////////////////////////
// Boxing related declarations

extern System_Object* __box__(void* pValue, __RUNTIME_TYPE__ type);
extern void* __unbox__(System_Object* pObject, __RUNTIME_TYPE__ type);

/////////////////////////////////////////////////////////////
// Primitive types

typedef uint8_t System_Byte;
extern const __RUNTIME_TYPE__ __System_Byte_RUNTIME_TYPE__;

typedef int8_t System_SByte;
extern const __RUNTIME_TYPE__ __System_SByte_RUNTIME_TYPE__;

typedef int16_t System_Int16;
extern const __RUNTIME_TYPE__ __System_Int16_RUNTIME_TYPE__;

typedef uint16_t System_UInt16;
extern const __RUNTIME_TYPE__ __System_UInt16_RUNTIME_TYPE__;

typedef int32_t System_Int32;
extern const __RUNTIME_TYPE__ __System_Int32_RUNTIME_TYPE__;

typedef uint32_t System_UInt32;
extern const __RUNTIME_TYPE__ __System_UInt32_RUNTIME_TYPE__;

typedef int64_t System_Int64;
extern const __RUNTIME_TYPE__ __System_Int64_RUNTIME_TYPE__;

typedef uint64_t System_UInt64;
extern const __RUNTIME_TYPE__ __System_UInt64_RUNTIME_TYPE__;

/////////////////////////////////////////////////////////////
// System.String

typedef struct System_String
{
    const char* pString;
} System_String;

extern const __RUNTIME_TYPE__ __System_String_RUNTIME_TYPE__;

// Binary layout compatible: __REF_HEADER__ + System_String.
typedef const struct __CONST_STRING__
{
    void* _0;
    __RUNTIME_TYPE__ __stringType;
    interlock_t _1;
    const char* __pString;
} __CONST_STRING__;

extern __RUNTIME_TYPE_DEF__ __System_String_RUNTIME_TYPE_DEF__;

#define __DEFINE_CONST_STRING__(name, pString) \
    static __CONST_STRING__ __##name##_const_string__ = { NULL, &__System_String_RUNTIME_TYPE_DEF__, 0, pString }; \
    static System_String* const name = ((System_String*)&(__##name##_const_string__.__pString))

extern void __new_string__(System_String** ppReference, const char* pString);

extern System_String* System_String_Concat_6(System_String* str0, System_String* str1);

#ifdef __cplusplus
}
#endif

#endif
