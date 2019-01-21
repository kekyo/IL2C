#ifndef __MT3620Blink_MT3620Blink_Application_H__
#define __MT3620Blink_MT3620Blink_Application_H__

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

typedef struct MT3620Blink_Application MT3620Blink_Application;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Application_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Application

// [1-1-2] Class layout
struct MT3620Blink_Application
{
    MT3620Blink_Application_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_Application_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Application);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Application

extern /* public sealed */ void MT3620Blink_Application__ctor(MT3620Blink_Application* this__);
extern /* public sealed */ void MT3620Blink_Application_RegisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target);
extern /* public sealed */ void MT3620Blink_Application_UnregisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target);
extern /* public sealed */ void MT3620Blink_Application_Run(MT3620Blink_Application* this__);

#ifdef __cplusplus
}
#endif

#endif
