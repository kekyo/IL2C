using System;
using System.Runtime.InteropServices;

namespace MT3620Blink
{
    internal abstract class Event : Descriptor, IEPollListener
    {
        protected Event()
            : base(Interops.eventfd(0, 0))
        {
        }

        public void Send(ulong value)
        {
            Interops.eventfd_write(this.Identity, value);
        }

        int IEPollListener.Identity => this.Identity;

        void IEPollListener.OnRaised()
        {
            Interops.eventfd_read(this.Identity, out var value);
            Received(value);
        }

        protected abstract void Received(ulong value);
    }
}
