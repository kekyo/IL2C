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
extern IL2C_RUNTIME_TYPE_DECL __System_Single_RUNTIME_TYPE__;

extern System_String* System_Single_ToString(float* this__);

#ifdef __cplusplus
}
#endif

#endif
