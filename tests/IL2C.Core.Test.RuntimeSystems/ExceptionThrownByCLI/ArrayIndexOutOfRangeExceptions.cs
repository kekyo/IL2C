////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    [TestId("ExceptionThrownByCLI")]
    public sealed class ArrayIndexOutOfRangeExceptions
    {
        [TestCase(false, "ArrayIndexOutOfRangeByLoad", 0)]
        [TestCase(false, "ArrayIndexOutOfRangeByLoad", 6)]
        [TestCase(true, "ArrayIndexOutOfRangeByLoad", -1)]
        [TestCase(true, "ArrayIndexOutOfRangeByLoad", 7)]
        public static bool ArrayIndexOutOfRangeByLoad(int index)
        {
            try
            {
                var arr = new int[7];
                var v = arr[index];
            }
            catch (IndexOutOfRangeException)
            {
                return true;
            }
            return false;
        }

        [TestCase(false, "ArrayIndexOutOfRangeByStore", 0)]
        [TestCase(false, "ArrayIndexOutOfRangeByStore", 6)]
        [TestCase(true, "ArrayIndexOutOfRangeByStore", -1)]
        [TestCase(true, "ArrayIndexOutOfRangeByStore", 7)]
        public static bool ArrayIndexOutOfRangeByStore(int index)
        {
            try
            {
                var arr = new int[7];
                arr[index] = 123;
            }
            catch (IndexOutOfRangeException)
            {
                return true;
            }
            return false;
        }
    }
}
