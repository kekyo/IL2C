#ifndef __System_Boolean_H__
#define __System_Boolean_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Boolean

typedef bool System_Boolean;
extern IL2C_RUNTIME_TYPE_DECL __System_Boolean_RUNTIME_TYPE__;

extern System_String* System_Boolean_ToString(bool* this__);

#ifdef __cplusplus
}
#endif

#endif
