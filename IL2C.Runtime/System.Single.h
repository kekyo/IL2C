#ifndef __System_Single_H__
#define __System_Single_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Single

typedef float System_Single;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(float* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(float* this__);
    int32_t(*GetHashCode)(float* this__);
    void(*Finalize)(float* this__);
    bool(*Equals)(float* this__, System_Object* obj);
} __System_Single_VTABLE_DECL__;

extern __System_Single_VTABLE_DECL__ __System_Single_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Single_RUNTIME_TYPE__;

extern System_String* System_Single_ToString(float* this__);
extern int32_t System_Single_GetHashCode(float* this__);
extern bool System_Single_Equals(float* this__, float obj);
extern bool System_Single_Equals_1(float* this__, System_Object* obj);
extern bool System_Single_TryParse(System_String* s, float* result);

#ifdef __cplusplus
}
#endif

#endif
