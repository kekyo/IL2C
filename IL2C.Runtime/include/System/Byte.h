#ifndef System_Byte_H__
#define System_Byte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Byte

typedef uint8_t System_Byte;

typedef System_ValueType_VTABLE_DECL__ System_Byte_VTABLE_DECL__;

extern System_Byte_VTABLE_DECL__ System_Byte_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Byte);

extern /* virtual */ System_String* System_Byte_ToString(uint8_t* this__);
extern /* virtual */ int32_t System_Byte_GetHashCode(uint8_t* this__);
extern bool System_Byte_Equals__System_Byte(uint8_t* this__, uint8_t obj);
extern /* virtual */ bool System_Byte_Equals__System_Object(uint8_t* this__, System_Object* obj);
extern /* static */ bool System_Byte_TryParse__System_String_System_Byte_REF(System_String* s, uint8_t* result);

#ifdef __cplusplus
}
#endif

#endif
