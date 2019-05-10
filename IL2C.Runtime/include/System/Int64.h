#ifndef System_Int64_H__
#define System_Int64_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int64

typedef int64_t System_Int64;

typedef System_ValueType_VTABLE_DECL__ System_Int64_VTABLE_DECL__;

extern System_Int64_VTABLE_DECL__ System_Int64_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Int64);

extern /* virtual */ System_String* System_Int64_ToString(int64_t* this__);
extern /* virtual */ int32_t System_Int64_GetHashCode(int64_t* this__);
extern bool System_Int64_Equals__System_Int64(int64_t* this__, int64_t obj);
extern /* virtual */ bool System_Int64_Equals__System_Object(int64_t* this__, System_Object* obj);
extern /* static */ bool System_Int64_TryParse__System_String_System_Int64_REF(System_String* s, int64_t* result);

#ifdef __cplusplus
}
#endif

#endif
