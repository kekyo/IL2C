#ifndef __System_Int32_H__
#define __System_Int32_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int32

typedef int32_t System_Int32;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(int32_t* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(int32_t* this__);
    int32_t(*GetHashCode)(int32_t* this__);
    void(*Finalize)(int32_t* this__);
    bool(*Equals)(int32_t* this__, System_Object* obj);
} __System_Int32_VTABLE_DECL__;

extern __System_Int32_VTABLE_DECL__ __System_Int32_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE__;

extern System_String* System_Int32_ToString(int32_t* this__);
extern int32_t System_Int32_GetHashCode(int32_t* this__);
extern bool System_Int32_Equals(int32_t* this__, int32_t obj);
extern bool System_Int32_Equals_1(int32_t* this__, System_Object* obj);
extern bool System_Int32_TryParse(System_String* s, int32_t* result);

#ifdef __cplusplus
}
#endif

#endif
