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

typedef __System_ValueType_VTABLE_DECL__ __System_Byte_VTABLE_DECL__;

extern __System_Byte_VTABLE_DECL__ __System_Byte_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE__;

#define __System_Byte_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Byte_ToString(uint8_t* this__);
extern /* virtual */ int32_t System_Byte_GetHashCode(uint8_t* this__);
extern bool System_Byte_Equals(uint8_t* this__, uint8_t obj);
extern /* virtual */ bool System_Byte_Equals_1(uint8_t* this__, System_Object* obj);
extern /* static */ bool System_Byte_TryParse(System_String* s, uint8_t* result);

#ifdef __cplusplus
}
#endif

#endif
