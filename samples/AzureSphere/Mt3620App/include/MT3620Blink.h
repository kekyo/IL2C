// [13-1] This is MT3620Blink native code translated by IL2C, do not edit.

#ifndef __MT3620Blink_H__
#define __MT3620Blink_H__

#pragma once

///////////////////////////////////////////////////////////////////////////
// [13-2] Assembly references:

#include <mscorlib.h>

///////////////////////////////////////////////////////////////////////////
// [13-3] Import native headers:

#include <sys/eventfd.h>
#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <applibs/gpio.h>

///////////////////////////////////////////////////////////////////////////
// [13-4] Type pre definitions:

#include "MT3620Blink/MT3620Blink/epoll_data_t.h"
#include "MT3620Blink/MT3620Blink/epoll_event.h"
#include "MT3620Blink/MT3620Blink/GPIO_OutputMode_Type.h"
#include "MT3620Blink/MT3620Blink/Descriptor.h"
#include "MT3620Blink/MT3620Blink/GpioOutput.h"
#include "MT3620Blink/MT3620Blink/GpioInput.h"
#include "MT3620Blink/MT3620Blink/IEPollListener.h"
#include "MT3620Blink/MT3620Blink/Event.h"
#include "MT3620Blink/MT3620Blink/Application.h"
#include "MT3620Blink/MT3620Blink/timespec.h"
#include "MT3620Blink/MT3620Blink/itimerspec.h"
#include "MT3620Blink/MT3620Blink/Timer.h"
#include "MT3620Blink/MT3620Blink/GPIO_Value_Type.h"
#include "MT3620Blink/MT3620Blink/Interops.h"
#include "MT3620Blink/MT3620Blink/Program.h"

///////////////////////////////////////////////////////////////////////////
// [13-5] Type body definitions:

#define MT3620Blink_DECL_TYPE_BODY__ 1

#include "MT3620Blink/MT3620Blink/epoll_data_t.h"
#include "MT3620Blink/MT3620Blink/epoll_event.h"
#include "MT3620Blink/MT3620Blink/GPIO_OutputMode_Type.h"
#include "MT3620Blink/MT3620Blink/Descriptor.h"
#include "MT3620Blink/MT3620Blink/GpioOutput.h"
#include "MT3620Blink/MT3620Blink/GpioInput.h"
#include "MT3620Blink/MT3620Blink/IEPollListener.h"
#include "MT3620Blink/MT3620Blink/Event.h"
#include "MT3620Blink/MT3620Blink/Application.h"
#include "MT3620Blink/MT3620Blink/timespec.h"
#include "MT3620Blink/MT3620Blink/itimerspec.h"
#include "MT3620Blink/MT3620Blink/Timer.h"
#include "MT3620Blink/MT3620Blink/GPIO_Value_Type.h"
#include "MT3620Blink/MT3620Blink/Interops.h"
#include "MT3620Blink/MT3620Blink/Program.h"

#endif
