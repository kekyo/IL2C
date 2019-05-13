#ifndef System_NullReferenceException_H__
#define System_NullReferenceException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.NullReferenceException

typedef System_Exception System_NullReferenceException;

typedef System_Exception_VTABLE_DECL__ System_NullReferenceException_VTABLE_DECL__;

#define System_NullReferenceException_VTABLE__ System_Exception_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_NullReferenceException);

static inline void System_NullReferenceException__ctor(System_NullReferenceException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_NullReferenceException__ctor__System_String(System_NullReferenceException* this__, System_String* message)
{
    System_Exception__ctor__System_String((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
