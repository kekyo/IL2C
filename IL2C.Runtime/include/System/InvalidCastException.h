#ifndef System_InvalidCastException_H__
#define System_InvalidCastException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.InvalidCastException

typedef System_Exception System_InvalidCastException;

typedef System_Exception_VTABLE_DECL__ System_InvalidCastException_VTABLE_DECL__;

#define System_InvalidCastException_VTABLE__ System_Exception_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_InvalidCastException);

static inline void System_InvalidCastException__ctor(System_InvalidCastException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_InvalidCastException__ctor__System_String(System_InvalidCastException* this__, System_String* message)
{
    System_Exception__ctor__System_String((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
