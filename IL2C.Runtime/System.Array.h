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
    uint8_t Item[1];    // Element body
};

#define  __System_Array_VTABLE__ __System_Object_VTABLE__
extern IL2C_RUNTIME_TYPE_DECL __System_Array_RUNTIME_TYPE__;

extern /* internalcall */ void __System_Array_IL2C_MarkHandler__(System_Array* this__);

extern int32_t System_Array_getLength(System_Array* this__);

/////////////////////////////////////////////////
// Predefine basic element types

#define IL2C_DECLARE_ARRAY_TYPE(elementTypeName) \
typedef struct System_Array_##elementTypeName \
{ \
    __System_Array_VTABLE_DECL__* vptr0__; \
 \
    IL2C_RUNTIME_TYPE_DECL* elementType__; \
    uintptr_t Length; \
    elementTypeName Item[1]; \
} System_Array_##elementTypeName

/////////////////////////////////////////////////
// Array special functions

#define il2c_array(elementTypeName) \
    System_Array_##elementTypeName

extern System_Array* il2c_new_array__(
    IL2C_RUNTIME_TYPE_DECL* elementType, intptr_t length);
#define il2c_new_array(elementTypeName, length) \
    ((System_Array_##elementTypeName*)il2c_new_array__(il2c_typeof(elementTypeName), length))

#ifdef __cplusplus
}
#endif

#endif
