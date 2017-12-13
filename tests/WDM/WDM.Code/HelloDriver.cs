using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WDM.Code
{
    public sealed class HelloDriver
    {
        public HelloDriver()
        {
            Wdm.DbgPrint("Hello driver constructor called!!");
        }

        public uint Read(IntPtr pIrp, IntPtr pStackLocation)
        {
            return 0; // STATUS_SUCCESS
        }
    }
}
