using System;

namespace WDM.Code
{
    public sealed class InterceptCDRomDevice
    {
        private readonly IntPtr pFrom;
        private readonly IntPtr pTo;
        private readonly int size;

        public InterceptCDRomDevice(IntPtr pFrom, IntPtr pTo, int size)
        {
            Wdm.DbgPrint("Hello driver constructor called!!");

            this.pFrom = pFrom;
            this.pTo = pTo;
            this.size = size;
        }

        public unsafe uint ReadCompleted(IntPtr pBuffer, int offset, int size)
        {
            var result = Wdm.memmem(pBuffer + offset, size, pFrom, this.size);
            if (result != IntPtr.Zero)
            {
                Wdm.memcpy(result, pTo, this.size);
            }

            return 0; // STATUS_SUCCESS
        }
    }
}
