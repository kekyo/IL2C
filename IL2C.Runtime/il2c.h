#ifndef __IL2C_H__
#define __IL2C_H__

#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WDM) || defined(UEFI)
#include <intrin.h>

#pragma intrinsic(memset)
#pragma intrinsic(memcpy)

typedef long interlock_t;
#else
typedef uint8_t interlock_t;
#endif

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef struct IL2C_EXECUTION_FRAME IL2C_EXECUTION_FRAME;
typedef struct IL2C_REF_HEADER IL2C_REF_HEADER;

typedef void(*IL2C_MARK_HANDLER)(void*);

typedef const struct
{
    const char* pTypeName;
    uintptr_t bodySize;
    IL2C_MARK_HANDLER pMarkHandler;
} IL2C_RUNTIME_TYPE_DECL;

typedef IL2C_RUNTIME_TYPE_DECL* IL2C_RUNTIME_TYPE;

struct IL2C_REF_HEADER
{
    IL2C_REF_HEADER* pNext;
    IL2C_RUNTIME_TYPE type;
    union
    {
        interlock_t gcMark;
        intptr_t reserved0__;
    };
};

/////////////////////////////////////////////////////////////
// Runtime type information related declarations

#define il2c_typeof(typeName) (__##typeName##_RUNTIME_TYPE__)
#define il2c_sizeof(typeName) (il2c_typeof(typeName)->bodySize)
#define il2c_get_vtable(typeName, this__) \
    ((__##typeName##_TYPE_DEF_TYPE__*)((((IL2C_REF_HEADER*)(this__)) - 1)->type))

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;
typedef struct System_String System_String;

static void System_Object__ctor(System_Object* this__)
{
}

extern System_String* __System_Object_ToString__(System_Object* this__);
extern int32_t __System_Object_GetHashCode__(System_Object* this__);
extern void __System_Object_Finalize__(System_Object* this__);
extern bool __System_Object_Equals__(System_Object* this__, System_Object* obj);

extern const IL2C_RUNTIME_TYPE __System_Object_RUNTIME_TYPE__;

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t(*GetHashCode)(System_Object* this__);
    void(*Finalize)(System_Object* this__);
    bool(*Equals)(System_Object* this__, System_Object* obj);
} __System_Object_TYPE_DEF_TYPE__;

#define System_Object_ToString(/* System_Object* */ this__) \
    (il2c_get_vtable(System_Object, this__)->ToString(this__))
#define System_Object_GetHashCode(/* System_Object* */ this__) \
    (il2c_get_vtable(System_Object, this__)->GetHashCode(this__))
#define System_Object_Finalize(/* System_Object* */ this__) \
    (il2c_get_vtable(System_Object, this__)->Finalize(this__))
#define System_Object_Equals(/* System_Object* */ this__, /* System_Object* */ obj) \
    (il2c_get_vtable(System_Object, this__, obj)->Equals(this__, obj))

/////////////////////////////////////////////////////////////
// Garbage collector related declarations

extern void il2c_initialize();
extern void il2c_shutdown();

extern void il2c_collect();

extern void* il2c_get_uninitialized_object(IL2C_RUNTIME_TYPE type);

extern void il2c_link_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pNewFrame);
extern void il2c_unlink_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pFrame);

extern void il2c_mark_from_handler(void* pReference);
#define il2c_try_mark_from_handler(pReference) \
    if ((pReference) != NULL) il2c_mark_from_handler(pReference)

/////////////////////////////////////////////////////////////
// System.ValueType

typedef struct System_ValueType System_ValueType;

static void System_ValueType__ctor(System_ValueType* this__)
{
}

extern System_String* __System_ValueType_ToString__(System_ValueType* this__);
extern int32_t __System_ValueType_GetHashCode__(System_ValueType* this__);
extern bool __System_ValueType_Equals__(System_ValueType* this__, System_Object* obj);

extern const IL2C_RUNTIME_TYPE __System_ValueType_RUNTIME_TYPE__;

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_ValueType* this__);
    int32_t(*GetHashCode)(System_ValueType* this__);
    void(*Finalize)(System_Object* this__);
    bool(*Equals)(System_ValueType* this__, System_Object* obj);
} __System_ValueType_TYPE_DEF_TYPE__;

#define System_ValueType_ToString(/* System_Object* */ this__) \
    System_Object_ToString((System_Object*)this__)
#define System_ValueType_GetHashCode(/* System_Object* */ this__) \
    System_Object_GetHashCode((System_Object*)this__)
#define System_ValueType_Equals(/* System_Object* */ this__, /* System_Object* */ obj) \
    System_Object_Equals((System_Object*)this__, obj)

/////////////////////////////////////////////////////////////
// Boxing related declarations

extern System_Object* il2c_box(void* pValue, IL2C_RUNTIME_TYPE type);
extern void* il2c_unbox(System_Object* pObject, IL2C_RUNTIME_TYPE type);

/////////////////////////////////////////////////////////////
// Primitive types

typedef System_Object IL2C_CecilHelper_PseudoZeroType;

typedef intptr_t System_IntPtr;
extern const IL2C_RUNTIME_TYPE __System_IntPtr_RUNTIME_TYPE__;

typedef uint8_t System_Byte;
extern const IL2C_RUNTIME_TYPE __System_Byte_RUNTIME_TYPE__;

typedef int8_t System_SByte;
extern const IL2C_RUNTIME_TYPE __System_SByte_RUNTIME_TYPE__;

typedef int16_t System_Int16;
extern const IL2C_RUNTIME_TYPE __System_Int16_RUNTIME_TYPE__;

typedef uint16_t System_UInt16;
extern const IL2C_RUNTIME_TYPE __System_UInt16_RUNTIME_TYPE__;

typedef int32_t System_Int32;
extern const IL2C_RUNTIME_TYPE __System_Int32_RUNTIME_TYPE__;

typedef uint32_t System_UInt32;
extern const IL2C_RUNTIME_TYPE __System_UInt32_RUNTIME_TYPE__;

typedef int64_t System_Int64;
extern const IL2C_RUNTIME_TYPE __System_Int64_RUNTIME_TYPE__;

typedef uint64_t System_UInt64;
extern const IL2C_RUNTIME_TYPE __System_UInt64_RUNTIME_TYPE__;

extern const System_IntPtr System_IntPtr_Zero;

static System_IntPtr System_IntPtr_op_Addition(System_IntPtr lhs, int32_t rhs)
{
    return lhs + rhs;
}

static bool System_IntPtr_op_Inequality(System_IntPtr lhs, System_IntPtr rhs)
{
    return lhs != rhs;
}

extern bool System_Int32_TryParse(System_String* s, int32_t* result);

/////////////////////////////////////////////////////////////
// System.String

struct System_String
{
    const wchar_t* string_body__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_String_RUNTIME_TYPE_DEF__;
extern const IL2C_RUNTIME_TYPE __System_String_RUNTIME_TYPE__;

// Binary layout compatible: IL2C_REF_HEADER + System_String.
typedef struct
{
    const void* reserved0__;              /* IL2C_REF_HEADER* */
    const IL2C_RUNTIME_TYPE stringType__; /* IL2C_RUNTIME_TYPE */
    const intptr_t reserved1__;           /* interlock_t */
    const wchar_t* string_body__;
} IL2C_CONST_STRING_DECL;

#define IL2C_CONST_STRING(name, string_body) \
    static IL2C_CONST_STRING_DECL __##name##_const_string__ = { NULL, &__System_String_RUNTIME_TYPE_DEF__, 0, string_body }; \
    static System_String* const name = ((System_String*)&(__##name##_const_string__.string_body__))

extern System_String* il2c_new_string(const wchar_t* pString);

extern System_String* System_String_Concat_6(System_String* str0, System_String* str1);
extern System_String* System_String_Substring(System_String* this__, int32_t startIndex);
extern System_String* System_String_Substring_1(System_String* this__, int32_t startIndex, int32_t length);
extern wchar_t System_String_get_Chars(System_String* this__, int32_t index);
extern int32_t System_String_get_Length(System_String* this__);
extern bool System_String_IsNullOrWhiteSpace(System_String* value);

/////////////////////////////////////////////////////////////
// System.Console

extern void System_Console_Write_9(System_String* value);
extern void System_Console_WriteLine();
extern void System_Console_WriteLine_6(int32_t value);
extern void System_Console_WriteLine_10(System_String* value);

extern System_String* System_Console_ReadLine();

#ifdef __cplusplus
}
#endif

#endif
