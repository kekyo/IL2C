#ifndef __System_UInt16_H__
#define __System_UInt16_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UInt16

typedef uint16_t System_UInt16;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(uint16_t* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(uint16_t* this__);
    int32_t(*GetHashCode)(uint16_t* this__);
    void(*Finalize)(uint16_t* this__);
    bool(*Equals)(uint16_t* this__, System_Object* obj);
} __System_UInt16_VTABLE_DECL__;

extern __System_UInt16_VTABLE_DECL__ __System_UInt16_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt16_RUNTIME_TYPE__;

extern System_String* System_UInt16_ToString(uint16_t* this__);
extern int32_t System_UInt16_GetHashCode(uint16_t* this__);
extern bool System_UInt16_Equals(uint16_t* this__, uint16_t obj);
extern bool System_UInt16_Equals_1(uint16_t* this__, System_Object* obj);
extern bool System_UInt16_TryParse(System_String* s, uint16_t* result);

#ifdef __cplusplus
}
#endif

#endif
