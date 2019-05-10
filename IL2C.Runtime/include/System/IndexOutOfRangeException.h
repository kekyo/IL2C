#ifndef System_IndexOutOfRangeException_H__
#define System_IndexOutOfRangeException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IndexOutOfRangeException

typedef System_Exception System_IndexOutOfRangeException;

typedef System_Exception_VTABLE_DECL__ System_IndexOutOfRangeException_VTABLE_DECL__;

#define System_IndexOutOfRangeException_VTABLE__ System_Exception_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_IndexOutOfRangeException);

static inline void System_IndexOutOfRangeException__ctor(System_IndexOutOfRangeException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_IndexOutOfRangeException__ctor__System_String(System_IndexOutOfRangeException* this__, System_String* message)
{
    System_Exception__ctor__System_String((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
