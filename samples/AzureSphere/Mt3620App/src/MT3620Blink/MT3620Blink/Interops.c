// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Interops

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Interops

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.close(System.Int32 fd)

int32_t MT3620Blink_Interops_close(int32_t fd)
{
    return close(fd);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.nanosleep(MT3620Blink.timespec& req, MT3620Blink.timespec& rem)

void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* req, MT3620Blink_timespec* rem)
{
    nanosleep(req, rem);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.timerfd_create(System.Int32 clockid, System.Int32 flags)

int32_t MT3620Blink_Interops_timerfd_create(int32_t clockid, int32_t flags)
{
    return timerfd_create(clockid, flags);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.timerfd_settime(System.Int32 fd, System.Int32 flags, MT3620Blink.itimerspec& new_value, MT3620Blink.itimerspec& old_value)

int32_t MT3620Blink_Interops_timerfd_settime(int32_t fd, int32_t flags, MT3620Blink_itimerspec* new_value, MT3620Blink_itimerspec* old_value)
{
    return timerfd_settime(fd, flags, new_value, old_value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.timerfd_read(System.Int32 fd, System.UInt64& timerData, System.UIntPtr size)

int32_t MT3620Blink_Interops_timerfd_read(int32_t fd, uint64_t* timerData, uintptr_t size)
{
    return read(fd, timerData, size);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.eventfd(System.UInt32 initval, System.Int32 flags)

int32_t MT3620Blink_Interops_eventfd(uint32_t initval, int32_t flags)
{
    return eventfd(initval, flags);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.eventfd_write(System.Int32 fd, System.UInt64 value)

int32_t MT3620Blink_Interops_eventfd_write(int32_t fd, uint64_t value)
{
    return eventfd_write(fd, value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.eventfd_read(System.Int32 fd, System.UInt64& value)

int32_t MT3620Blink_Interops_eventfd_read(int32_t fd, uint64_t* value)
{
    return eventfd_read(fd, value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_OpenAsOutput(System.Int32 gpioId, MT3620Blink.GPIO_OutputMode_Type outputMode, MT3620Blink.GPIO_Value_Type initialValue)

int32_t MT3620Blink_Interops_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue)
{
    return GPIO_OpenAsOutput(gpioId, outputMode, initialValue);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_SetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type value)

int32_t MT3620Blink_Interops_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value)
{
    return GPIO_SetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_OpenAsInput(System.Int32 gpioId)

int32_t MT3620Blink_Interops_GPIO_OpenAsInput(int32_t gpioId)
{
    return GPIO_OpenAsInput(gpioId);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_GetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type& value)

int32_t MT3620Blink_Interops_GPIO_GetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type* value)
{
    return GPIO_GetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.epoll_create1(System.Int32 flags)

int32_t MT3620Blink_Interops_epoll_create1(int32_t flags)
{
    return epoll_create1(flags);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.epoll_ctl(System.Int32 epollfd, System.Int32 op, System.Int32 fd, MT3620Blink.epoll_event& ev)

int32_t MT3620Blink_Interops_epoll_ctl(int32_t epollfd, int32_t op, int32_t fd, MT3620Blink_epoll_event* ev)
{
    return epoll_ctl(epollfd, op, fd, ev);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.epoll_wait(System.Int32 epollfd, MT3620Blink.epoll_event& ev, System.Int32 maxevents, System.Int32 timeout)

int32_t MT3620Blink_Interops_epoll_wait(int32_t epollfd, MT3620Blink_epoll_event* ev, int32_t maxevents, int32_t timeout)
{
    return epoll_wait(epollfd, ev, maxevents, timeout);
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Interops, "MT3620Blink.Interops", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Interops), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
