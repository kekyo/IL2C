#ifndef System_SByte_H__
#define System_SByte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.SByte

typedef int8_t System_SByte;

typedef System_ValueType_VTABLE_DECL__ System_SByte_VTABLE_DECL__;

extern System_SByte_VTABLE_DECL__ System_SByte_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_SByte);

extern /* virtual */ System_String* System_SByte_ToString(int8_t* this__);
extern /* virtual */ int32_t System_SByte_GetHashCode(int8_t* this__);
extern bool System_SByte_Equals__System_SByte(int8_t* this__, int8_t obj);
extern /* virtual */ bool System_SByte_Equals__System_Object(int8_t* this__, System_Object* obj);
extern /* static */ bool System_SByte_TryParse__System_String_System_SByte_REF(System_String* s, int8_t* result);

#ifdef __cplusplus
}
#endif

#endif
