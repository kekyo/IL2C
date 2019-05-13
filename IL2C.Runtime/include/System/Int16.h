#ifndef System_Int16_H__
#define System_Int16_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int16

typedef int16_t System_Int16;

typedef System_ValueType_VTABLE_DECL__ System_Int16_VTABLE_DECL__;

extern System_Int16_VTABLE_DECL__ System_Int16_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Int16);

extern /* virtual */ System_String* System_Int16_ToString(int16_t* this__);
extern /* virtual */ int32_t System_Int16_GetHashCode(int16_t* this__);
extern bool System_Int16_Equals__System_Int16(int16_t* this__, int16_t obj);
extern /* virtual */ bool System_Int16_Equals__System_Object(int16_t* this__, System_Object* obj);
extern /* static */ bool System_Int16_TryParse__System_String_System_Int16_REF(System_String* s, int16_t* result);

#ifdef __cplusplus
}
#endif

#endif
