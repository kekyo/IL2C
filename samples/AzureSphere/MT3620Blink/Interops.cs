using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

using IL2C;

namespace MT3620Blink
{
    [NativeType("time.h", SymbolName = "struct timespec")]
    internal struct timespec
    {
        public int tv_sec;
        public int tv_nsec;
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
        //void* ptr;
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
        // timer

        [NativeMethod("time.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void nanosleep(ref timespec time, ref timespec dummy);

        //////////////////////////////////////////////////////////////////////
        // gpio

        [NativeValue("mt3620_rdb.h")]
        public static readonly int MT3620_RDB_LED1_RED;

        [NativeMethod("applibs/gpio.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int GPIO_OpenAsOutput(
            int gpioId, GPIO_OutputMode_Type outputMode, GPIO_Value_Type initialValue);

        [NativeMethod("applibs/gpio.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int GPIO_SetValue(int gpioFd, GPIO_Value_Type value);

        //////////////////////////////////////////////////////////////////////
        // epoll

        [NativeValue("sys/epoll.h")]
        public static readonly int EPOLL_CTL_ADD;
        [NativeValue("sys/epoll.h")]
        public static readonly int EPOLLIN;

        [NativeMethod("sys/epoll.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int epoll_create1(int flags);

        [NativeMethod("sys/epoll.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int epoll_ctl(int epollfd, int op, int fd, ref epoll_event ev);

        [NativeMethod("sys/epoll.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int epoll_wait(int epollfd, ref epoll_event ev, int maxevents, int timeout);
    }
}
