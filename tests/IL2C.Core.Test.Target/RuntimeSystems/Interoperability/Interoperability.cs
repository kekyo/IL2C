using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;

namespace IL2C.RuntimeSystems
{
    [Description("These tests are verified the IL2C manages interoperability with the P/Invoke method and internalcall method.")]
    [TestCase(null, new[] { "InternalCallWithUnicodeStringArgument", "OutputDebugString" }, "ABC", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
    public sealed class Interoperability
    {
        [NativeMethod("windows.h", EntryPoint = "OutputDebugStringW", CharSet = CharSet.Unicode)]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern void OutputDebugString(string message);

        public static void InternalCallWithUnicodeStringArgument(string message)
        {
            OutputDebugString(message);
        }
    }
}
