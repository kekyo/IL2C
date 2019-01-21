#ifndef __MT3620Blink_MT3620Blink_IEPollListener_H__
#define __MT3620Blink_MT3620Blink_IEPollListener_H__

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

typedef struct MT3620Blink_IEPollListener MT3620Blink_IEPollListener;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef const struct MT3620Blink_IEPollListener_VTABLE_DECL___ MT3620Blink_IEPollListener_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.IEPollListener

// [1-2-2] Interface VTable layout
struct MT3620Blink_IEPollListener_VTABLE_DECL___
{
    intptr_t offset__; // Adjustor offset
    int32_t (*get_Identity)(void* this__);
    void (*OnRaised)(void* this__);
};

// [1-1-2] Interface layout
struct MT3620Blink_IEPollListener
{
    MT3620Blink_IEPollListener_VTABLE_DECL__* vptr0__;
};

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_IEPollListener);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

#ifdef __cplusplus
}
#endif

#endif
