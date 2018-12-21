using System;

namespace MT3620Blink
{
    internal sealed class Descriptor : IDisposable
    {
        public Descriptor(int fd)
        {
            this.Identity = fd;
        }

        public void Dispose()
        {
            if (this.Identity >= 0)
            {
                Interops.close(this.Identity);
                this.Identity = -1;
            }
        }

        public int Identity { get; private set; }
    }
}
