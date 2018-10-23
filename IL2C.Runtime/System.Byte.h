#ifndef __System_Byte_H__
#define __System_Byte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Byte

typedef uint8_t System_Byte;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(uint8_t* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(uint8_t* this__);
    int32_t(*GetHashCode)(uint8_t* this__);
    void(*Finalize)(uint8_t* this__);
    bool(*Equals)(uint8_t* this__, System_Object* obj);
} __System_Byte_VTABLE_DECL__;

extern __System_Byte_VTABLE_DECL__ __System_Byte_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE__;

extern System_String* System_Byte_ToString(uint8_t* this__);
extern int32_t System_Byte_GetHashCode(uint8_t* this__);
extern bool System_Byte_Equals(uint8_t* this__, uint8_t obj);
extern bool System_Byte_Equals_1(uint8_t* this__, System_Object* obj);
extern bool System_Byte_TryParse(System_String* s, uint8_t* result);

#ifdef __cplusplus
}
#endif

#endif
