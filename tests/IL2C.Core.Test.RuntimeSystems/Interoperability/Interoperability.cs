/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
    [TestCase(null, new[] { "InternalCallWithUnicodeStringArgument", "OutputDebugString1" }, "ABC", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
    [TestCase(null, new[] { "DllImportWithUnicodeStringArgument", "OutputDebugString2" }, "ABC", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
    [TestCase(12345678, "TransparencyForNativePointer", 12345678)]
    [TestCase(12345678, "TransparencyForNativePointerInsideNativeType", 12345678, IncludeTypes = new[] { typeof(NativePointerInside) })]
    [TestCase("ABCDEF", new[] { "BypassObjRefWithObjRefHandle", "ConcatAndToObjRefHandle" }, "ABC", "DEF")]
    public sealed class Interoperability
    {
        [NativeMethod("windows.h", SymbolName = "OutputDebugStringW", CharSet = NativeCharSet.Unicode)]
        [MethodImpl(MethodImplOptions.InternalCall)]
        private static extern void OutputDebugString1(string message);

        public static void InternalCallWithUnicodeStringArgument(string message)
        {
            OutputDebugString1(message);
        }

        [DllImport("kernel32", EntryPoint = "OutputDebugStringW")]
        private static extern void OutputDebugString2(string message);

        public static void DllImportWithUnicodeStringArgument(string message)
        {
            OutputDebugString2(message);
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
