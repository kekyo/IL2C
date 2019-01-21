#ifndef __MT3620Blink_MT3620Blink_epoll_event_H__
#define __MT3620Blink_MT3620Blink_epoll_event_H__

#pragma once

// This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <MT3620Blink.h>

#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <time.h>
#include <applibs/gpio.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

typedef struct epoll_event MT3620Blink_epoll_event;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef System_ValueType_VTABLE_DECL__ MT3620Blink_epoll_event_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.epoll_event

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_epoll_event_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_epoll_event);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

#ifdef __cplusplus
}
#endif

#endif
