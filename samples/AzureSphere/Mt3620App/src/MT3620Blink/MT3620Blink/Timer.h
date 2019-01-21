#ifndef __MT3620Blink_MT3620Blink_Timer_H__
#define __MT3620Blink_MT3620Blink_Timer_H__

#pragma once

// This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

typedef struct MT3620Blink_Timer MT3620Blink_Timer;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef const struct MT3620Blink_Timer_VTABLE_DECL___ MT3620Blink_Timer_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Timer

// [1-2-3] Class VTable layout (Derived from MT3620Blink.Descriptor)
struct MT3620Blink_Timer_VTABLE_DECL___
{
    intptr_t offset__; // Adjustor offset
    bool (*Equals)(void* this__, System_Object* obj);
    void (*Finalize)(void* this__);
    int32_t (*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    void (*Dispose)(void* this__);
    void (*Raised)(void* this__);
};

// [1-1-2] Class layout
struct MT3620Blink_Timer
{
    MT3620Blink_Timer_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
    MT3620Blink_IEPollListener_VTABLE_DECL__* vptr_MT3620Blink_IEPollListener__;
};

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Timer);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Timer

extern /* protected */ void MT3620Blink_Timer__ctor(MT3620Blink_Timer* this__);
extern /* public */ void MT3620Blink_Timer_SetInterval(MT3620Blink_Timer* this__, int64_t nsec);

#ifdef __cplusplus
}
#endif

#endif
