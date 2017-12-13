using System.Runtime.InteropServices;

namespace WDM.Code
{
    public class Wdm
    {
        [DllImport("wdm.h", EntryPoint = "DbgPrint")]
        public static extern void DbgPrint(string message);

        [DllImport("wdm.h", EntryPoint = "DbgPrintEx")]
        public static extern void DbgPrint(uint componentId, uint level, string message);
    }
}
