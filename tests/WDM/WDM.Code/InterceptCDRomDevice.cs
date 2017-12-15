using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WDM.Code
{
    public sealed class InterceptCDRomDevice
    {
        public InterceptCDRomDevice()
        {
            Wdm.DbgPrint("Hello driver constructor called!!");
        }

        public uint ReadCompleted(IntPtr pBuffer, uint offset, uint size)
        {
            return 0; // STATUS_SUCCESS
        }
    }
}
