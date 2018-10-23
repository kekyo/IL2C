#ifndef __System_Char_H__
#define __System_Char_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Char

typedef wchar_t System_Char;
extern IL2C_RUNTIME_TYPE_DECL __System_Char_RUNTIME_TYPE__;

extern System_String* System_Char_ToString(wchar_t* this__);

#ifdef __cplusplus
}
#endif

#endif
