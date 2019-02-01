using System;
using System.Runtime.InteropServices;

namespace MT3620Blink
{
    [NativeType("time.h", SymbolName = "struct timespec")]
    internal struct timespec
    {
        public int tv_sec;
        public int tv_nsec;
    }

    [NativeType("time.h", SymbolName = "struct itimerspec")]
    internal struct itimerspec
    {
        public timespec it_interval;
        public timespec it_value;
    }

    [NativeType("applibs/gpio.h")]
    internal enum GPIO_OutputMode_Type
    {
        GPIO_OutputMode_PushPull = 0,
        GPIO_OutputMode_OpenDrain = 1,
        GPIO_OutputMode_OpenSource = 2
    }

    [NativeType("applibs/gpio.h")]
    internal enum GPIO_Value_Type
    {
        GPIO_Value_Low = 0,
        GPIO_Value_High = 1
    }

    [NativeType("sys/epoll.h")]
    internal struct epoll_data_t
    {
        public NativePointer ptr;
        public int fd;
        //uint32_t u32;
        //uint64_t u64;
    }

    [NativeType("sys/epoll.h", SymbolName = "struct epoll_event")]
    internal struct epoll_event
    {
        public uint events;
        public epoll_data_t data;
    }

    internal static class Interops
    {
        //////////////////////////////////////////////////////////////////////
        // descriptor

        [NativeMethod("unistd.h")]
        public static extern int close(int fd);

        //////////////////////////////////////////////////////////////////////
        // time

        [NativeMethod("time.h")]
        public static extern void nanosleep(
            ref timespec req,
            out timespec rem);

        //////////////////////////////////////////////////////////////////////
        // timer

        [NativeMethod("sys/timerfd.h")]
        public static extern int timerfd_create(int clockid, int flags);

        [NativeMethod("sys/timerfd.h")]
        public static extern int timerfd_settime(
            int fd, int flags,
            ref itimerspec new_value,
            out itimerspec old_value);

        [NativeMethod("unistd.h", SymbolName = "read")]
        public static extern int timerfd_read(int fd, out ulong timerData, UIntPtr size);

        //////////////////////////////////////////////////////////////////////
        // gpio

        [NativeValue("mt3620_rdb.h")]
        public static readonly int MT3620_RDB_LED1_RED;

        [NativeMethod("applibs/gpio.h")]
        public static extern int GPIO_OpenAsOutput(
            int gpioId, GPIO_OutputMode_Type outputMode, GPIO_Value_Type initialValue);

        [NativeMethod("applibs/gpio.h")]
        public static extern int GPIO_SetValue(int gpioFd, GPIO_Value_Type value);

        [NativeValue("mt3620_rdb.h")]
        public static readonly int MT3620_RDB_BUTTON_A;

        [NativeMethod("applibs/gpio.h")]
        public static extern int GPIO_OpenAsInput(int gpioId);

        [NativeMethod("applibs/gpio.h")]
        public static extern int GPIO_GetValue(int gpioFd, out GPIO_Value_Type value);

        //////////////////////////////////////////////////////////////////////
        // epoll

        [NativeValue("sys/epoll.h")]
        public static readonly int EPOLL_CTL_ADD;
        [NativeValue("sys/epoll.h")]
        public static readonly int EPOLL_CTL_DEL;
        [NativeValue("sys/epoll.h")]
        public static readonly uint EPOLLIN;

        [NativeMethod("sys/epoll.h")]
        public static extern int epoll_create1(int flags);

        [NativeMethod("sys/epoll.h")]
        public static extern int epoll_ctl(int epollfd, int op, int fd, ref epoll_event ev);

        [NativeMethod("sys/epoll.h")]
        public static extern int epoll_wait(int epollfd, ref epoll_event ev, int maxevents, int timeout);
    }
}
