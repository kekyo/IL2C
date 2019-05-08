using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public struct NativePointerInside
    {
        public NativePointer Pointer;
    }

    [Description("These tests are verified the IL2C manages interoperability with the P/Invoke adn IL2C/Invoke method and internalcall method.")]
    [TestCase(null, new[] { "InternalCallWithUnicodeStringArgument", "OutputDebugString" }, "ABC", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
    [TestCase(12345678, "TransparencyForNativePointer", 12345678)]
    [TestCase(12345678, "TransparencyForNativePointerInsideNativeType", 12345678, IncludeTypes = new[] { typeof(NativePointerInside) })]
    [TestCase("ABCDEF", new[] { "BypassObjRefWithObjRefHandle", "ConcatAndToObjRefHandle" }, "ABC", "DEF")]
    public sealed class Interoperability
    {
        [NativeMethod("windows.h", SymbolName = "OutputDebugStringW", CharSet = NativeCharSet.Unicode)]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern void OutputDebugString(string message);

        public static void InternalCallWithUnicodeStringArgument(string message)
        {
            OutputDebugString(message);
        }

        public static IntPtr TransparencyForNativePointer(IntPtr value)
        {
            NativePointer np = value;
            IntPtr ip = np;
            return ip;
        }

        public static IntPtr TransparencyForNativePointerInsideNativeType(IntPtr value)
        {
            NativePointerInside npi;
            npi.Pointer = value;
            IntPtr ip = npi.Pointer;
            return ip;
        }

        private static IntPtr ConcatAndToObjRefHandle(string a, string b)
        {
            var c = a + b;
            var handle = GCHandle.Alloc(c, GCHandleType.Pinned);
            return GCHandle.ToIntPtr(handle);
        }

        public static string BypassObjRefWithObjRefHandle(string a, string b)
        {
            var objRefHandle = ConcatAndToObjRefHandle(a, b);
            var handle = GCHandle.FromIntPtr(objRefHandle);
            var result = (string)handle.Target;
            handle.Free();
            return result;
        }
    }
}
