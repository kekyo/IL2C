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
extern int32_t System_Array_GetLowerBound(System_Array* this__, int32_t dimension);
extern int32_t System_Array_GetUpperBound(System_Array* this__, int32_t dimension);

/////////////////////////////////////////////////
// Array special functions

extern void il2c_throw_indexoutofrangeexception__();

// It made identical type expression for array type.
#define il2c_array(elementTypeName) \
    System_Array

#define il2c_array_item0ptr__(array) \
    (((uint8_t*)array) + sizeof(System_Array))
static inline void* il2c_array_item__(
    System_Array* array, uint32_t elementSize, intptr_t index)
{
    il2c_assert(array != NULL); // TODO: NullReferenceException

    il2c_assert(array->vptr0__ == &__System_Array_VTABLE__);
    il2c_assert(array->elementType__ != NULL);
    il2c_assert(array->Length >= 0);
    il2c_assert(elementSize == il2c_sizeof__(array->elementType__));

    if ((index < 0) || (index >= array->Length))
    {
        il2c_throw_indexoutofrangeexception__();
    }

    return il2c_array_item0ptr__(array) + elementSize * index;
}
#define il2c_array_item(array, elementTypeName, index) \
    (*(elementTypeName*)il2c_array_item__(array, sizeof(elementTypeName), index))

extern System_Array* il2c_new_array__(
    IL2C_RUNTIME_TYPE_DECL* elementType, intptr_t length);
#define il2c_new_array(elementTypeName, length) \
    ((il2c_array(elementTypeName)*)il2c_new_array__(il2c_typeof(elementTypeName), length))

#ifdef __cplusplus
}
#endif

#endif
