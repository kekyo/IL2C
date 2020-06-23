using System;
using System.Runtime.InteropServices;

namespace GettingStartedIL2C
{
    public static class Program
    {
        [DllImport("user32.dll")]
        public static extern int MessageBoxW(
           IntPtr hWnd, string text, string caption, int options);
        
        public static void Main()
        {
            Console.WriteLine("Hello world with IL2C!");
            //MessageBoxW(IntPtr.Zero, "Hello world with IL2C!", "Getting started IL2C", 1);
        }
    }
}
