#ifndef __System_Single_H__
#define __System_Single_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Single

typedef float System_Single;

typedef __System_ValueType_VTABLE_DECL__ __System_Single_VTABLE_DECL__;

extern __System_Single_VTABLE_DECL__ __System_Single_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Single_RUNTIME_TYPE__;

#define __System_Single_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Single_ToString(float* this__);
extern /* virtual */ int32_t System_Single_GetHashCode(float* this__);
extern bool System_Single_Equals(float* this__, float obj);
extern /* virtual */ bool System_Single_Equals_1(float* this__, System_Object* obj);
extern /* static */ bool System_Single_TryParse(System_String* s, float* result);

#ifdef __cplusplus
}
#endif

#endif
