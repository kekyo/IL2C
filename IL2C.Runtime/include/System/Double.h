#ifndef System_Double_H__
#define System_Double_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Double

typedef double System_Double;

typedef System_ValueType_VTABLE_DECL__ System_Double_VTABLE_DECL__;

extern System_Double_VTABLE_DECL__ System_Double_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Double);

extern /* virtual */ System_String* System_Double_ToString(double* this__);
extern /* virtual */ int32_t System_Double_GetHashCode(double* this__);
extern bool System_Double_Equals__System_Double(double* this__, double obj);
extern /* virtual */ bool System_Double_Equals__System_Object(double* this__, System_Object* obj);
extern /* static */ bool System_Double_TryParse__System_String_System_Double_REF(System_String* s, double* result);

#ifdef __cplusplus
}
#endif

#endif
