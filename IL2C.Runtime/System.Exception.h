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

typedef const struct
{
    /* internalcall */ void* (*il2c_isinst__)(void* this__, IL2C_RUNTIME_TYPE_DECL* type);
    bool(*Equals)(void* this__, System_Object* obj);
    void(*Finalize)(void* this__);
    int32_t(*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    System_String* (*get_Message)(void* this__);
} __System_Exception_VTABLE_DECL__;

struct System_Exception
{
    __System_Exception_VTABLE_DECL__* vptr0__;
    System_String* message__;
};

extern __System_Exception_VTABLE_DECL__ __System_Exception_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Exception_RUNTIME_TYPE__;

extern /* internalcall */ void __System_Exception_IL2C_MarkHandler__(System_Exception* this__);

extern void System_Exception__ctor(System_Exception* this__);
extern void System_Exception__ctor_1(System_Exception* this__, System_String* message);

extern System_String* System_Exception_get_Message(System_Exception* this__);

#ifdef __cplusplus
}
#endif

#endif
