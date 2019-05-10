#ifndef System_Single_H__
#define System_Single_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Single

typedef float System_Single;

typedef System_ValueType_VTABLE_DECL__ System_Single_VTABLE_DECL__;

extern System_Single_VTABLE_DECL__ System_Single_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Single);

extern /* virtual */ System_String* System_Single_ToString(float* this__);
extern /* virtual */ int32_t System_Single_GetHashCode(float* this__);
extern bool System_Single_Equals__System_Single(float* this__, float obj);
extern /* virtual */ bool System_Single_Equals__System_Object(float* this__, System_Object* obj);
extern /* static */ bool System_Single_TryParse__System_String_System_Single_REF(System_String* s, float* result);

#ifdef __cplusplus
}
#endif

#endif
