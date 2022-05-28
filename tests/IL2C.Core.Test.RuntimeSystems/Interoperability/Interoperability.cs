////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

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

    [Description("These tests are verified the IL2C manages interoperability with the P/Invoke and IL2C/Invoke method and internalcall method.")]
    public sealed class Interoperability
    {
        [NativeType("time.h", SymbolName = "struct tm")]
        internal struct tm
        {
            public int tm_sec;
            public int tm_min;
            public int tm_hour;
            public int tm_mday;
            public int tm_mon;
            public int tm_year;
            public int tm_wday;
            public int tm_yday;
            public int tm_isdst;
        }

        [NativeMethod("time.h")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern long mktime(in tm tmValue);

        [TestCase(1666496096L, new[] { "IL2CInvokeMkTime", "mktime" })]
        public static long IL2CInvokeMkTime()
        {
            // 2022/10/23 12:34:56
            var tmValue = new tm
            {
                tm_year = 2022 - 1900,
                tm_mon = 10 - 1,
                tm_mday = 23,
                tm_hour = 12,
                tm_min = 34,
                tm_sec = 56,
                tm_wday = 0,
                tm_yday = 0,
                tm_isdst = 0,
            };
            return mktime(tmValue);
        }

        [DllImport("libc", EntryPoint = "wcslen")]
        private static extern IntPtr wcslen(string message);

        [TestCase(3, new[] { "PInvokeWcsLen", "wcslen" }, "ABC", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static int PInvokeWcsLen(string message)
        {
            return wcslen(message).ToInt32();
        }

        [TestCase(12345678, "TransparencyForNativePointer", 12345678)]
        public static IntPtr TransparencyForNativePointer(IntPtr value)
        {
            NativePointer np = value;
            IntPtr ip = np;
            return ip;
        }

        [TestCase(12345678, "TransparencyForNativePointerInsideNativeType", 12345678, IncludeTypes = new[] { typeof(NativePointerInside) })]
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

        [TestCase("ABCDEF", new[] { "BypassObjRefWithObjRefHandle", "ConcatAndToObjRefHandle" }, "ABC", "DEF")]
        public static string BypassObjRefWithObjRefHandle(string a, string b)
        {
            var objRefHandle = ConcatAndToObjRefHandle(a, b);
            var handle = GCHandle.FromIntPtr(objRefHandle);
            var result = (string)handle.Target!;
            handle.Free();
            return result;
        }
    }
}
