using System;

namespace MT3620Blink
{
    public abstract class Descriptor : IDisposable
    {
        public Descriptor(int fd)
        {
            if (fd < 0)
            {
                throw new Exception("Invalid descriptor: " + fd);
            }
            this.Identity = fd;
        }

        public virtual void Dispose()
        {
            if (this.Identity >= 0)
            {
                Interops.close(this.Identity);
                this.Identity = -1;
            }
        }

        protected internal int Identity { get; private set; }

        protected internal virtual void OnRaised()
        {
        }
    }
}
