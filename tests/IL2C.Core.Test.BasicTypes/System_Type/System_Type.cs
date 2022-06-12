////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C.BasicTypes
{
    public sealed class System_Type
    {
        // System.Type.ToString() implementation has concatenation for "Type: " header, but the System.RuntimeType do not.
        [TestCase("System.Int32", "ToString", 123)]
        [TestCase("System.String", "ToString", "ABC")]
        public static string ToString(object value)
        {
            return value.GetType().ToString();
        }

        [TestCase("System.Int32", "FullName", 123)]
        [TestCase("System.String", "FullName", "ABC")]
        public static string FullName(object value)
        {
            return value.GetType().FullName!;
        }

        [TestCase("System.ValueType", "BaseType", 123)]
        [TestCase("System.Object", "BaseType", "ABC")]
        public static string BaseType(object value)
        {
            return value.GetType().BaseType!.FullName!;
        }

        [TestCase(null, "Object_BaseType", Assert = TestCaseAsserts.PerfectMatch)]
        public static Type? Object_BaseType()
        {
            // TODO: We have to handle GetTypeFromHandle.
            //return typeof(object).BaseType;
            return 123.GetType().BaseType!.BaseType!.BaseType;
        }
    }
}
