#ifndef __IL2C_H__
#define __IL2C_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WDM) || defined(UEFI)
#include <intrin.h>

typedef long interlock_t;
#include <stdint.h>
#else
#include <stdint.h>
typedef uint8_t interlock_t;
#endif

#include <stdbool.h>
#include <wchar.h>

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef struct IL2C_EXECUTION_FRAME IL2C_EXECUTION_FRAME;
typedef struct IL2C_REF_HEADER IL2C_REF_HEADER;

typedef void (*IL2C_MARK_HANDLER)(void*);

typedef const struct
{
    const char* pTypeName;
    uintptr_t bodySize;
    /* internalcall */ IL2C_MARK_HANDLER IL2C_MarkHandler;
} IL2C_RUNTIME_TYPE_DECL;

struct IL2C_REF_HEADER
{
    IL2C_REF_HEADER* pNext;
    IL2C_RUNTIME_TYPE_DECL* type;
    union
    {
        interlock_t gcMark;
        intptr_t reserved0__;
    };
};

/////////////////////////////////////////////////////////////
// Runtime type information related declarations

#define il2c_typeof(typeName) (&__##typeName##_RUNTIME_TYPE__)
#define il2c_sizeof(typeName) (il2c_typeof(typeName)->bodySize)

// dynamic cast operator
#define il2c_runtime_cast(pReference, typeName) \
    ((typeName##*)((pReference)->vptr0__->IL2C_RuntimeCast((pReference), il2c_typeof(typeName))))

// static cast operators
#define il2c_cast_from_interface(typeName, interfaceTypeName, pInterface) \
    ((typeName##*)(((uint8_t*)(pInterface)) - \
     (offsetof(typeName, vptr_##interfaceTypeName##__) - \
      offsetof(typeName, vptr0__))))
#define il2c_cast_to_interface(interfaceTypeName, typeName, pReference) \
    ((interfaceTypeName##*)(((uint8_t*)(pReference)) + \
     (offsetof(typeName, vptr_##interfaceTypeName##__) - \
      offsetof(typeName, vptr0__))))

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;
typedef struct System_String System_String;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __System_Object_VTABLE_DECL__;

struct System_Object
{
    __System_Object_VTABLE_DECL__* vptr0__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_Object_RUNTIME_TYPE__;

static void System_Object__ctor(System_Object* this__)
{
}

extern /* internalcall */ void __System_Object_IL2C_MarkHandler__(System_Object* this__);
extern /* internalcall */ void* __System_Object_IL2C_RuntimeCast__(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ System_String* __System_Object_ToString__(System_Object* this__);
extern /* virtual */ int32_t __System_Object_GetHashCode__(System_Object* this__);
extern /* virtual */ void __System_Object_Finalize__(System_Object* this__);
extern /* virtual */ bool __System_Object_Equals__(System_Object* this__, System_Object* obj);

#define System_Object_ToString(/* System_Object* */ this__) \
    ((this__)->vptr0__->ToString((this__)))
#define System_Object_GetHashCode(/* System_Object* */ this__) \
    ((this__)->vptr0__->GetHashCode((this__)))
#define System_Object_Finalize(/* System_Object* */ this__) \
    ((this__)->vptr0__->Finalize((this__)))
#define System_Object_Equals(/* System_Object* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals((this__), (obj)))

/////////////////////////////////////////////////////////////
// Garbage collector related declarations

extern void il2c_initialize();
extern void il2c_shutdown();

extern void il2c_collect();

extern void* il2c_get_uninitialized_object(IL2C_RUNTIME_TYPE_DECL* type);

extern void il2c_link_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pNewFrame);
extern void il2c_unlink_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pFrame);

extern void il2c_mark_from_handler(void* pReference);
#define il2c_try_mark_from_handler(pReference) \
    if ((pReference) != NULL) il2c_mark_from_handler(pReference)

/////////////////////////////////////////////////////////////
// System.ValueType

typedef struct System_ValueType System_ValueType;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_ValueType* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_ValueType* this__);
    int32_t (*GetHashCode)(System_ValueType* this__);
    void (*Finalize)(System_ValueType* this__);
    bool (*Equals)(System_ValueType* this__, System_Object* obj);
} __System_ValueType_VTABLE_DECL__;

struct System_ValueType
{
    __System_ValueType_VTABLE_DECL__* vptr0__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_ValueType_RUNTIME_TYPE__;
extern __System_ValueType_VTABLE_DECL__ __System_ValueType_VTABLE__;

static void System_ValueType__ctor(System_ValueType* this__)
{
}

extern /* internalcall */ void __System_ValueType_IL2C_MarkHandler__(System_ValueType* this__);
extern /* internalcall */ void* __System_ValueType_IL2C_RuntimeCast__(System_ValueType* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ System_String* __System_ValueType_ToString__(System_ValueType* this__);
extern /* virtual */ int32_t __System_ValueType_GetHashCode__(System_ValueType* this__);
extern /* virtual */ bool __System_ValueType_Equals__(System_ValueType* this__, System_Object* obj);

#define System_ValueType_ToString(/* System_ValueType* */ this__) \
    ((this__)->vptr0__->ToString((this__)))
#define System_ValueType_GetHashCode(/* System_ValueType* */ this__) \
    ((this__)->vptr0__->GetHashCode((this__)))
#define System_ValueType_Finalize(/* System_ValueType* */ this__) \
    ((this__)->vptr0__->Finalize((this__)))
#define System_ValueType_Equals(/* System_ValueType* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals((this__), (obj)))

/////////////////////////////////////////////////////////////
// Boxing related declarations

extern System_Object* il2c_box(void* pValue, IL2C_RUNTIME_TYPE_DECL* type);
extern void* il2c_unbox(System_Object* pObject, IL2C_RUNTIME_TYPE_DECL* type);

/////////////////////////////////////////////////////////////
// Primitive types

typedef System_Object IL2C_CecilHelper_PseudoZeroType;

typedef intptr_t System_IntPtr;
extern IL2C_RUNTIME_TYPE_DECL __System_IntPtr_RUNTIME_TYPE__;

typedef uint8_t System_Byte;
extern IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE__;

typedef int8_t System_SByte;
extern IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE__;

typedef int16_t System_Int16;
extern IL2C_RUNTIME_TYPE_DECL __System_Int16_RUNTIME_TYPE__;

typedef uint16_t System_UInt16;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt16_RUNTIME_TYPE__;

typedef int32_t System_Int32;
extern IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE__;

typedef uint32_t System_UInt32;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt32_RUNTIME_TYPE__;

typedef int64_t System_Int64;
extern IL2C_RUNTIME_TYPE_DECL __System_Int64_RUNTIME_TYPE__;

typedef uint64_t System_UInt64;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt64_RUNTIME_TYPE__;

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

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_String* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_String* this__);
    int32_t(*GetHashCode)(System_String* this__);
    void(*Finalize)(System_String* this__);
    bool(*Equals)(System_String* this__, System_Object* obj);
} __System_String_VTABLE_DECL__;

struct System_String
{
    // Instance's vptr
    __System_String_VTABLE_DECL__* vptr0__;

    const wchar_t* string_body__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_String_RUNTIME_TYPE__;
extern __System_String_VTABLE_DECL__ __System_String_VTABLE__;

// Binary layout compatible: IL2C_REF_HEADER + System_String.
// +----------------------+                -------------------------
// | IL2C_REF_HEADER      |                                      ^
// +----------------------+ <-- pString    -------               |
// | vptr0__              |                  ^                   | IL2C_CONST_STRING_DECL
// +----------------------+                  | System_String     |
// | string_body__        | ----+            v                   v
// +----------------------+     |          -------------------------
//                              |
//                              |
// +----------------------+     |
// |        :             | <---+
// | (Literal string)     |
// |        :             |
// +----------------------+

typedef struct
{
    // IL2C_REF_HEADER
    const void* pNext;
    IL2C_RUNTIME_TYPE_DECL* type;
    const intptr_t gcMark;           // Pretty hack: const string always marked (GCMARK_LIVE:0)

    // Instance's vptr
    __System_String_VTABLE_DECL__* vptr0__;

    const wchar_t* string_body__;
} IL2C_CONST_STRING_DECL;

#define IL2C_CONST_STRING(name, string_body) \
    static IL2C_CONST_STRING_DECL __##name##_CONST_STRING__ = { \
        NULL, &__System_String_RUNTIME_TYPE__, /* GCMARK_LIVE */ 0, &__System_String_VTABLE__, string_body }; \
    static System_String* const name = ((System_String*)&(__##name##_CONST_STRING__.vptr0__))

extern System_String* il2c_new_string(const wchar_t* pString);

extern /* internalcall */ void __System_String_IL2C_MarkHandler__(System_String* this__);
extern /* internalcall */ void* __System_String_IL2C_RuntimeCast__(System_String* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ System_String* __System_String_ToString__(System_String* this__);
extern /* virtual */ int32_t __System_String_GetHashCode__(System_String* this__);

#define System_String_ToString(/* System_String* */ this__) \
    ((this__)->vptr0__->ToString((this__)))
#define System_String_GetHashCode(/* System_String* */ this__) \
    ((this__)->vptr0__->GetHashCode((this__)))
#define System_String_Finalize(/* System_String* */ this__) \
    ((this__)->vptr0__->Finalize((this__)))
#define System_String_Equals(/* System_String* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals((this__), (obj)))

extern System_String* System_String_Concat_6(System_String* str0, System_String* str1);
extern System_String* System_String_Substring(System_String* this__, int32_t startIndex);
extern System_String* System_String_Substring_1(System_String* this__, int32_t startIndex, int32_t length);
extern wchar_t System_String_get_Chars(System_String* this__, int32_t index);
extern int32_t System_String_get_Length(System_String* this__);
extern bool System_String_IsNullOrWhiteSpace(System_String* value);
extern bool System_String_op_Equality(System_String* lhs, System_String* rhs);

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
