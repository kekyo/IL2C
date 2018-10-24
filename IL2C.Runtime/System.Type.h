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
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_Type* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Type* this__);
    int32_t(*GetHashCode)(System_Type* this__);
    void(*Finalize)(System_Type* this__);
    bool(*Equals)(System_Type* this__, System_Object* obj);
} __System_Type_VTABLE_DECL__;

struct System_Type
{
    __System_Type_VTABLE_DECL__* vptr0__;
    IL2C_RUNTIME_TYPE_DECL* type__;
};

extern __System_Type_VTABLE_DECL__ __System_Type_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Type_RUNTIME_TYPE__;

extern /* internalcall */ void* __System_Type_IL2C_RuntimeCast__(System_Type* this__, IL2C_RUNTIME_TYPE_DECL* type);
#define __System_Type_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern System_String* System_Type_ToString(System_Type* this__);
extern int32_t System_Type_GetHashCode(System_Type* this__);
extern bool System_Type_Equals(System_Type* this__, System_Type* obj);
extern bool System_Type_Equals_1(System_Type* this__, System_Object* obj);
extern System_String* System_Type_get_FullName(System_Type* this__);

#ifdef __cplusplus
}
#endif

#endif
