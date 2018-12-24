using System.Runtime.InteropServices;

namespace MT3620Blink
{
    internal delegate void DescriptorCallbackDelegate();

    internal sealed class Application : Descriptor
    {
        public Application()
            : base(Interops.epoll_create1(0))
        {
        }

        public void RegisterDescriptor(Descriptor target, DescriptorCallbackDelegate callback)
        {
            var handle = GCHandle.Alloc(callback, GCHandleType.Pinned);

            var ev = new epoll_event {
                events = Interops.EPOLLIN,
                data = new epoll_data_t { ptr = handle.AddrOfPinnedObject() }
            };

            Interops.epoll_ctl(
                this.Identity,
                Interops.EPOLL_CTL_ADD,
                target.Identity,
                ref ev);
        }

        public void Run()
        {
            while (true)
            {
                var ev = new epoll_event();
                var numEventsOccurred = Interops.epoll_wait(this.Identity, ref ev, 1, -1);

                if (numEventsOccurred == 1)
                {
                    var handle = GCHandle.FromIntPtr(ev.data.ptr);
                    var callback = (DescriptorCallbackDelegate)handle.Target;
                    callback();
                }
            }
        }
    }
}
