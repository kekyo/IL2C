#ifndef __System_Int16_H__
#define __System_Int16_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int16

typedef int16_t System_Int16;
extern IL2C_RUNTIME_TYPE_DECL __System_Int16_RUNTIME_TYPE__;

extern System_String* System_Int16_ToString(int16_t* this__);

#ifdef __cplusplus
}
#endif

#endif
