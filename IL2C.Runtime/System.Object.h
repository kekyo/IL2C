#ifndef __System_Object_H__
#define __System_Object_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;
typedef struct System_String System_String;
typedef struct System_Type System_Type;

typedef const struct
{
    /* internalcall */ void* (*il2c_isinst__)(void* this__, IL2C_RUNTIME_TYPE_DECL* type);
    bool(*Equals)(void* this__, System_Object* obj);
    void(*Finalize)(void* this__);
    int32_t(*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
} __System_Object_VTABLE_DECL__;

struct System_Object
{
    __System_Object_VTABLE_DECL__* vptr0__;
};

extern __System_Object_VTABLE_DECL__ __System_Object_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Object_RUNTIME_TYPE__;

#define __System_Object_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

static inline void System_Object__ctor(System_Object* this__)
{
}

extern /* virtual */ System_String* System_Object_ToString(System_Object* this__);
extern /* virtual */ int32_t System_Object_GetHashCode(System_Object* this__);
extern System_Type* System_Object_GetType(System_Object* this__);
extern /* virtual */ void System_Object_Finalize(System_Object* this__);
extern /* virtual */ bool System_Object_Equals(System_Object* this__, System_Object* obj);

extern /* static */ bool System_Object_ReferenceEquals(System_Object* objA, System_Object* objB);

#ifdef __cplusplus
}
#endif

#endif
