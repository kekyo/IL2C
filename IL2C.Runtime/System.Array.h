#ifndef __System_Array_H__
#define __System_Array_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Array

typedef struct System_Array System_Array;

typedef __System_Object_VTABLE_DECL__ __System_Array_VTABLE_DECL__;

struct System_Array
{
    __System_Array_VTABLE_DECL__* vptr0__;

    IL2C_RUNTIME_TYPE_DECL* elementType__;
    uintptr_t Length;
};

#define  __System_Array_VTABLE__ __System_Object_VTABLE__
extern IL2C_RUNTIME_TYPE_DECL __System_Array_RUNTIME_TYPE__;

extern /* internalcall */ void __System_Array_IL2C_MarkHandler__(System_Array* this__);

extern int32_t System_Array_getLength(System_Array* this__);

/////////////////////////////////////////////////
// Array special functions

// It made identical type expression for array type.
#define il2c_array(elementTypeName) \
    System_Array

#define il2c_array_item(array, elementTypeName, index) \
    (((elementTypeName*)(((intptr_t)array) + sizeof(System_Array)))[index])

extern System_Array* il2c_new_array__(
    IL2C_RUNTIME_TYPE_DECL* elementType, intptr_t length);
#define il2c_new_array(elementTypeName, length) \
    ((il2c_array(elementTypeName)*)il2c_new_array__(il2c_typeof(elementTypeName), length))

#ifdef __cplusplus
}
#endif

#endif
