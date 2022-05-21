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
    public delegate string ObjectModelInstructionsTestDelegate(string from);

    // The cast failure message different between .NET CLR 4 and IL2C.
    // Because IL2C choices short sentence by unbox operator message because better footprint.
    //   (See also "il2c_invalid_cast_message" symbol)

    [Description("These tests are verified the IL2C throw some exceptions from the internal runtimes by ECMA-335 I.12.4.2.1.")]
    [TestId("ExceptionThrownByCLI")]
    public sealed class InvalidCastExceptions
    {
        // These cases become from ECMA-335 I.12.4.2.1 - Exceptions thrown by the CLI - Object Model Instructions

        [TestCase(true, "InvalidCastExceptionFromStringToString", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromStringToString()
        {
            object value = "ABC";
            try
            {
                var foo = (string)value;
            }
            catch (InvalidCastException)
            {
                return false;
            }
            return true;
        }

        [TestCase(true, "InvalidCastExceptionFromInt32ToString", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt32ToString()
        {
            object value = 123;
            try
            {
                var foo = (string)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        public static string TestTarget(string from)
        {
            return from;
        }

        [TestCase(true, new[] { "InvalidCastExceptionFromDelegateToString", "TestTarget" }, IncludeTypes = new[] { typeof(ObjectModelInstructionsTestDelegate) }, Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromDelegateToString()
        {
            try
            {
                object dlg = new ObjectModelInstructionsTestDelegate(TestTarget);
                var foo = (string)dlg;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromByteToByte", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromByteToByte()
        {
            object value = (byte)123;
            try
            {
                var foo = (byte)value;
            }
            catch (InvalidCastException)
            {
                return false;
            }
            return true;
        }

        [TestCase(true, "InvalidCastExceptionFromByteToInt16", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromByteToInt16()
        {
            object value = (byte)123;
            try
            {
                var foo = (short)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromByteToInt32", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromByteToInt32()
        {
            object value = (byte)123;
            try
            {
                var foo = (int)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromByteToInt64", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromByteToInt64()
        {
            object value = (byte)123;
            try
            {
                var foo = (long)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt16ToByte", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt16ToByte()
        {
            object value = (short)123;
            try
            {
                var foo = (byte)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt16ToInt16", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt16ToInt16()
        {
            object value = (short)123;
            try
            {
                var foo = (short)value;
            }
            catch (InvalidCastException)
            {
                return false;
            }
            return true;
        }

        [TestCase(true, "InvalidCastExceptionFromInt16ToInt32", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt16ToInt32()
        {
            object value = (short)123;
            try
            {
                var foo = (int)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt16ToInt64", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt16ToInt64()
        {
            object value = (short)123;
            try
            {
                var foo = (long)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt32ToByte", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt32ToByte()
        {
            object value = 123;
            try
            {
                var foo = (byte)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt32ToInt16", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt32ToInt16()
        {
            object value = 123;
            try
            {
                var foo = (short)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt32ToInt32", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt32ToInt32()
        {
            object value = 123;
            try
            {
                var foo = (int)value;
            }
            catch (InvalidCastException)
            {
                return false;
            }
            return true;
        }

        [TestCase(true, "InvalidCastExceptionFromInt32ToInt64", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt32ToInt64()
        {
            object value = 123;
            try
            {
                var foo = (long)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt64ToByte", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt64ToByte()
        {
            object value = (long)123;
            try
            {
                var foo = (byte)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt64ToInt16", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt64ToInt16()
        {
            object value = (long)123;
            try
            {
                var foo = (short)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt64ToInt32", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt64ToInt64()
        {
            object value = (long)123;
            try
            {
                var foo = (int)value;
            }
            catch (InvalidCastException ex)
            {
                if (ex.Message != "Specified cast is not valid.")
                {
                    throw;
                }
                return true;
            }
            return false;
        }

        [TestCase(true, "InvalidCastExceptionFromInt64ToInt64", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
        public static bool InvalidCastExceptionFromInt64ToInt32()
        {
            object value = (long)123;
            try
            {
                var foo = (long)value;
            }
            catch (InvalidCastException)
            {
                return false;
            }
            return true;
        }
    }
}
