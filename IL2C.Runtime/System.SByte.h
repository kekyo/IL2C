#ifndef __System_SByte_H__
#define __System_SByte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.SByte

typedef int8_t System_SByte;
extern IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE__;

extern System_String* System_SByte_ToString(int8_t* this__);

#ifdef __cplusplus
}
#endif

#endif
