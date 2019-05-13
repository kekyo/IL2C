#ifndef System_Int32_H__
#define System_Int32_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int32

typedef int32_t System_Int32;

typedef System_ValueType_VTABLE_DECL__ System_Int32_VTABLE_DECL__;

extern System_Int32_VTABLE_DECL__ System_Int32_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Int32);

extern /* virtual */ System_String* System_Int32_ToString(int32_t* this__);
extern /* virtual */ int32_t System_Int32_GetHashCode(int32_t* this__);
extern bool System_Int32_Equals__System_Int32(int32_t* this__, int32_t obj);
extern /* virtual */ bool System_Int32_Equals__System_Object(int32_t* this__, System_Object* obj);
extern /* static */ bool System_Int32_TryParse__System_String_System_Int32_REF(System_String* s, int32_t* result);

#ifdef __cplusplus
}
#endif

#endif
