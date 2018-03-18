using System.Runtime.InteropServices;

namespace IL2C.Tests
{
    public class Win32
    {
        [DllImport("windows.h")]
        public static extern int GetCurrentProcessId();

        [DllImport("windows.h")]
        public static extern int GetCurrentThreadId();

        [DllImport("windows.h", EntryPoint = "OutputDebugStringW")]
        public static extern void OutputDebugString(string message);
    }
}
