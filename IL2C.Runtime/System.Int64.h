#ifndef __System_Int64_H__
#define __System_Int64_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int64

typedef int64_t System_Int64;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(int64_t* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(int64_t* this__);
    int32_t(*GetHashCode)(int64_t* this__);
    void(*Finalize)(int64_t* this__);
    bool(*Equals)(int64_t* this__, System_Object* obj);
} __System_Int64_VTABLE_DECL__;

extern __System_Int64_VTABLE_DECL__ __System_Int64_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Int64_RUNTIME_TYPE__;

extern System_String* System_Int64_ToString(int64_t* this__);
extern int32_t System_Int64_GetHashCode(int64_t* this__);
extern bool System_Int64_Equals(int64_t* this__, int64_t obj);
extern bool System_Int64_Equals_1(int64_t* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
