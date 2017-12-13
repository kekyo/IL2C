using System.Runtime.InteropServices;

namespace Win32.Code
{
    public class Win32
    {
        [DllImport("windows.h")]
        public static extern int GetCurrentProcessId();

        [DllImport("windows.h")]
        public static extern int GetCurrentThreadId();

        [DllImport("windows.h", EntryPoint = "OutputDebugStringA")]
        public static extern void OutputDebugString(string message);
    }
}
