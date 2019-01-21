#ifndef __MT3620Blink_MT3620Blink_Descriptor_H__
#define __MT3620Blink_MT3620Blink_Descriptor_H__

#pragma once

// This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

typedef struct MT3620Blink_Descriptor MT3620Blink_Descriptor;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef const struct MT3620Blink_Descriptor_VTABLE_DECL___ MT3620Blink_Descriptor_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Descriptor

// [1-2-3] Class VTable layout (Derived from System.Object)
struct MT3620Blink_Descriptor_VTABLE_DECL___
{
    intptr_t offset__; // Adjustor offset
    bool (*Equals)(void* this__, System_Object* obj);
    void (*Finalize)(void* this__);
    int32_t (*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    void (*Dispose)(void* this__);
};

// [1-1-2] Class layout
struct MT3620Blink_Descriptor
{
    MT3620Blink_Descriptor_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t _Identity_k__BackingField;
};

// [1-5-2] VTable (Derived from System.Object)
extern MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Descriptor_VTABLE__;

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Descriptor);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Descriptor

extern /* public */ void MT3620Blink_Descriptor__ctor(MT3620Blink_Descriptor* this__, int32_t fd);
extern /* public virtual */ void MT3620Blink_Descriptor_Dispose(MT3620Blink_Descriptor* this__);
extern /* protected */ int32_t MT3620Blink_Descriptor_get_Identity(MT3620Blink_Descriptor* this__);

#ifdef __cplusplus
}
#endif

#endif
