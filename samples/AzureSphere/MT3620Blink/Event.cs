using System;
using System.Runtime.InteropServices;

namespace MT3620Blink
{
    internal abstract class Event : Descriptor, IEPollListener
    {
        [NativeValue("sys/eventfd.h")]
        private static readonly int EFD_NONBLOCK;
        [NativeValue("sys/eventfd.h")]
        private static readonly int EFD_SEMAPHORE;

        protected Event()
            : base(Interops.eventfd(0, EFD_NONBLOCK | EFD_SEMAPHORE))
        {
        }

        public void Pulse()
        {
            Interops.eventfd_write(this.Identity, 1);
        }

        int IEPollListener.Identity => this.Identity;

        void IEPollListener.OnRaised()
        {
            Interops.eventfd_read(this.Identity, out var value);
            Received();
        }

        protected abstract void Received();
    }
}
