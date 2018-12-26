using System.Runtime.InteropServices;

namespace MT3620Blink
{
    public interface IEPollListener
    {
        int Identity { get; }
        void OnRaised();
    }

    public sealed class Application : Descriptor
    {
        public Application()
            : base(Interops.epoll_create1(0))
        {
        }

        public void RegisterDescriptor(IEPollListener target)
        {
            var handle = GCHandle.Alloc(target, GCHandleType.Pinned);

            var ev = new epoll_event {
                events = Interops.EPOLLIN,
                data = new epoll_data_t { ptr = GCHandle.ToIntPtr(handle) }
            };

            Interops.epoll_ctl(
                this.Identity,
                Interops.EPOLL_CTL_ADD,
                target.Identity,
                ref ev);
        }

        public void UnregisterDescriptor(IEPollListener target)
        {
            var handle = GCHandle.Alloc(target, GCHandleType.Pinned);
            handle.Free();

            var ev = new epoll_event();

            Interops.epoll_ctl(
                this.Identity,
                Interops.EPOLL_CTL_DEL,
                target.Identity,
                ref ev);
        }

        public void Run()
        {
            while (true)
            {
                var ev = new epoll_event();
                var numEventsOccurred = Interops.epoll_wait(this.Identity, ref ev, 1, -1);

                if (numEventsOccurred == -1)
                {
                    break;
                }
                if (numEventsOccurred == 1)
                {
                    var handle = GCHandle.FromIntPtr(ev.data.ptr);
                    var target = (IEPollListener)handle.Target;
                    target.OnRaised();
                }
            }
        }
    }
}
