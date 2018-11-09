#ifndef __System_Exception_H__
#define __System_Exception_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Exception

typedef struct System_Exception System_Exception;

typedef __System_Object_VTABLE_DECL__ __System_Exception_VTABLE_DECL__;

struct System_Exception
{
    __System_Exception_VTABLE_DECL__* vptr0__;
};

extern __System_Exception_VTABLE_DECL__ __System_Exception_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Exception_RUNTIME_TYPE__;

#define __System_Exception_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern void System_Exception__ctor(System_Exception* this__);



typedef System_Exception System_InvalidCastException;
typedef __System_Exception_VTABLE_DECL__ __System_InvalidCastException_VTABLE_DECL__;
extern IL2C_RUNTIME_TYPE_DECL __System_InvalidCastException_RUNTIME_TYPE__;
#define __System_InvalidCastException_VTABLE__ __System_Exception_VTABLE__
#define __System_InvalidCastException_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER
static inline void System_InvalidCastException__ctor(System_InvalidCastException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}


#ifdef __cplusplus
}
#endif

#endif
