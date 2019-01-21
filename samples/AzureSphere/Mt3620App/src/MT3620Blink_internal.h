#ifndef __MT3620Blink_internal_H__
#define __MT3620Blink_internal_H__

#pragma once

// This is MT3620Blink native code translated by IL2C, do not edit.

#include <mscorlib.h>

#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <applibs/gpio.h>

#include "MT3620Blink/MT3620Blink/GpioInput.h"
#include "MT3620Blink/MT3620Blink/GpioOutput.h"
#include "MT3620Blink/MT3620Blink/timespec.h"
#include "MT3620Blink/MT3620Blink/itimerspec.h"
#include "MT3620Blink/MT3620Blink/GPIO_OutputMode_Type.h"
#include "MT3620Blink/MT3620Blink/GPIO_Value_Type.h"
#include "MT3620Blink/MT3620Blink/epoll_data_t.h"
#include "MT3620Blink/MT3620Blink/epoll_event.h"
#include "MT3620Blink/MT3620Blink/Interops.h"
#include "MT3620Blink/MT3620Blink/Timer.h"

//////////////////////////////////////////////////////////////////////////////////
// [9-1-1] Const strings:

System_String* const MT3620Blink_string0__;

//////////////////////////////////////////////////////////////////////////////////
// [12-1-1] Declared values:

// .<PrivateImplementationDetails>.E902362F9BEE92BBA97ECE5B88B94AF4A8D3201D
extern const int64_t MT3620Blink_declaredValue0__[];

#endif
