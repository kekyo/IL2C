#ifndef __System_Console_H__
#define __System_Console_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Console

typedef struct System_Console System_Console;

typedef __System_Object_VTABLE_DECL__ __System_Console_VTABLE_DECL__;

struct System_Console
{
    __System_Console_VTABLE_DECL__* vptr0__;
};

#define __System_Console_VTABLE__ __System_Object_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Console_RUNTIME_TYPE__;

#define __System_Console_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* static */ void System_Console_Write_9(System_String* value);
extern /* static */ void System_Console_WriteLine();
extern /* static */ void System_Console_WriteLine_6(int32_t value);
extern /* static */ void System_Console_WriteLine_10(System_String* value);

extern /* static */ System_String* System_Console_ReadLine();

#ifdef __cplusplus
}
#endif

#endif
