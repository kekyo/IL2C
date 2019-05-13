#ifndef System_FormatException_H__
#define System_FormatException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.FormatException

typedef System_Exception System_FormatException;

typedef System_Exception_VTABLE_DECL__ System_FormatException_VTABLE_DECL__;

#define System_FormatException_VTABLE__ System_Exception_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_FormatException);

static inline void System_FormatException__ctor(System_FormatException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_FormatException__ctor__System_String(System_FormatException* this__, System_String* message)
{
    System_Exception__ctor__System_String((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
