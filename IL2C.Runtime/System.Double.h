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
extern IL2C_RUNTIME_TYPE_DECL __System_Double_RUNTIME_TYPE__;

extern System_String* System_Double_ToString(double* this__);

#ifdef __cplusplus
}
#endif

#endif
