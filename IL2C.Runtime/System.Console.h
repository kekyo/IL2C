#ifndef __System_Console_H__
#define __System_Console_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Console

extern IL2C_RUNTIME_TYPE_DECL __System_Console_RUNTIME_TYPE__;

extern /* static */ void System_Console_Write_9(System_String* value);
extern /* static */ void System_Console_WriteLine();
extern /* static */ void System_Console_WriteLine_6(int32_t value);
extern /* static */ void System_Console_WriteLine_10(System_String* value);

extern /* static */ System_String* System_Console_ReadLine();

#ifdef __cplusplus
}
#endif

#endif
