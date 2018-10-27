#ifndef __System_Type_H__
#define __System_Type_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Type

typedef struct System_Type System_Type;

typedef const struct
{
    /* internalcall */ void* (*il2c_isinst__)(void* this__, IL2C_RUNTIME_TYPE_DECL* type);
    bool(*Equals)(void* this__, System_Object* obj);
    void(*Finalize)(void* this__);
    int32_t(*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    System_Type* (*get_BaseType)(void* this__);
    System_String* (*get_FullName)(void* this__);
} __System_Type_VTABLE_DECL__;

struct System_Type
{
    __System_Type_VTABLE_DECL__* vptr0__;
    IL2C_RUNTIME_TYPE_DECL* type__;
};

extern __System_Type_VTABLE_DECL__ __System_Type_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Type_RUNTIME_TYPE__;

#define __System_Type_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Type_ToString(System_Type* this__);
extern /* virtual */ int32_t System_Type_GetHashCode(System_Type* this__);
extern bool System_Type_Equals(System_Type* this__, System_Type* obj);
extern /* virtual */ bool System_Type_Equals_1(System_Type* this__, System_Object* obj);
extern /* virtual */ System_Type* System_Type_get_BaseType(System_Type* this__);
extern /* virtual */ System_String* System_Type_get_FullName(System_Type* this__);

#ifdef __cplusplus
}
#endif

#endif
