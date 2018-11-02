#ifndef __System_Double_H__
#define __System_Double_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Double

typedef double System_Double;

typedef __System_ValueType_VTABLE_DECL__ __System_Double_VTABLE_DECL__;

extern __System_Double_VTABLE_DECL__ __System_Double_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Double_RUNTIME_TYPE__;

#define __System_Double_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Double_ToString(double* this__);
extern /* virtual */ int32_t System_Double_GetHashCode(double* this__);
extern bool System_Double_Equals(double* this__, double obj);
extern /* virtual */ bool System_Double_Equals_1(double* this__, System_Object* obj);
extern /* static */ bool System_Double_TryParse(System_String* s, double* result);

#ifdef __cplusplus
}
#endif

#endif
