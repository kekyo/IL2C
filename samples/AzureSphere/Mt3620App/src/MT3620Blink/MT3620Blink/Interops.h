#ifndef __MT3620Blink_MT3620Blink_Interops_H__
#define __MT3620Blink_MT3620Blink_Interops_H__

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

typedef struct MT3620Blink_Interops MT3620Blink_Interops;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef System_Object_VTABLE_DECL__ MT3620Blink_Interops_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Interops

// [1-1-2] Class layout
struct MT3620Blink_Interops
{
    MT3620Blink_Interops_VTABLE_DECL__* vptr0__;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Interops_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Interops);

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Static fields:

#define MT3620Blink_Interops_MT3620_RDB_LED1_RED MT3620_RDB_LED1_RED
#define MT3620Blink_Interops_MT3620_RDB_BUTTON_A MT3620_RDB_BUTTON_A
#define MT3620Blink_Interops_EPOLL_CTL_ADD EPOLL_CTL_ADD
#define MT3620Blink_Interops_EPOLLIN EPOLLIN

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Interops

extern /* public static sealed */ int32_t MT3620Blink_Interops_close(int32_t fd);
extern /* public static sealed */ void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* time, MT3620Blink_timespec* dummy);
extern /* public static sealed */ int32_t MT3620Blink_Interops_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue);
extern /* public static sealed */ int32_t MT3620Blink_Interops_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value);
extern /* public static sealed */ int32_t MT3620Blink_Interops_GPIO_OpenAsInput(int32_t gpioId);
extern /* public static sealed */ int32_t MT3620Blink_Interops_GPIO_GetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type* value);
extern /* public static sealed */ int32_t MT3620Blink_Interops_epoll_create1(int32_t flags);
extern /* public static sealed */ int32_t MT3620Blink_Interops_epoll_ctl(int32_t epollfd, int32_t op, int32_t fd, MT3620Blink_epoll_event* ev);
extern /* public static sealed */ int32_t MT3620Blink_Interops_epoll_wait(int32_t epollfd, MT3620Blink_epoll_event* ev, int32_t maxevents, int32_t timeout);

#ifdef __cplusplus
}
#endif

#endif
