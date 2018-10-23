#ifndef __System_SByte_H__
#define __System_SByte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.SByte

typedef int8_t System_SByte;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(int8_t* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(int8_t* this__);
    int32_t(*GetHashCode)(int8_t* this__);
    void(*Finalize)(int8_t* this__);
    bool(*Equals)(int8_t* this__, System_Object* obj);
} __System_SByte_VTABLE_DECL__;

extern __System_SByte_VTABLE_DECL__ __System_SByte_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE__;

extern System_String* System_SByte_ToString(int8_t* this__);
extern int32_t System_SByte_GetHashCode(int8_t* this__);
extern bool System_SByte_Equals(int8_t* this__, int8_t obj);
extern bool System_SByte_Equals_1(int8_t* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
