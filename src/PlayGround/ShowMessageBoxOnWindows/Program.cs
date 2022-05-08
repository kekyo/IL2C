using System;
using System.Runtime.InteropServices;

namespace GettingStartedIL2C
{
    public static class Program
    {
        public enum MessageBoxOptions : uint
        {
            MB_OK = 0,
            MB_OKCANCEL,
            MB_ABORTRETRYIGNORE,
            MB_YESNOCANCEL,
            MB_YESNO,
            MB_RETRYCANCEL,
            MB_CANCELTRYCONTINUE,
        }

        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        public static extern int MessageBoxW(
           IntPtr hWnd, string text, string caption, MessageBoxOptions options);

        public static int Main() => 
            MessageBoxW(
                IntPtr.Zero,
                "Hello world with IL2C!", "Getting started IL2C",
                MessageBoxOptions.MB_YESNOCANCEL);
    }
}
