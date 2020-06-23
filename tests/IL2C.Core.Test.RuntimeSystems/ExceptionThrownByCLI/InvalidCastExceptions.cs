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
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public delegate string ObjectModelInstructionsTestDelegate(string from);

    // The cast failure message different between .NET CLR 4 and IL2C.
    // Because IL2C choices short sentence by unbox operator message because better footprint.
    //   (See also "il2c_cast_failed" symbol at il2c.c)

    [Description("These tests are verified the IL2C throw some exceptions from the internal runtimes by ECMA-335 I.12.4.2.1.")]
    [TestId("ExceptionThrownByCLI")]
    [TestCase(true, "InvalidCastExceptionFromStringToString")]
    [TestCase(true, "InvalidCastExceptionFromInt32ToString", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
    [TestCase(true, new[] { "InvalidCastExceptionFromDelegateToString", "TestTarget" }, IncludeTypes = new[] { typeof(ObjectModelInstructionsTestDelegate) }, Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]
    [TestCase(true, "InvalidCastExceptionFromByteToByte")]
    [TestCase(true, "InvalidCastExceptionFromByteToInt16")]
    [TestCase(true, "InvalidCastExceptionFromByteToInt32")]
    [TestCase(true, "InvalidCastExceptionFromByteToInt64")]
    [TestCase(true, "InvalidCastExceptionFromInt16ToByte")]
    [TestCase(true, "InvalidCastExceptionFromInt16ToInt16")]
    [TestCase(true, "InvalidCastExceptionFromInt16ToInt32")]
    [TestCase(true, "InvalidCastExceptionFromInt16ToInt64")]
    [TestCase(true, "InvalidCastExceptionFromInt32ToByte")]
    [TestCase(true, "InvalidCastExceptionFromInt32ToInt16")]
    [TestCase(true, "InvalidCastExceptionFromInt32ToInt32")]
    [TestCase(true, "InvalidCastExceptionFromInt32ToInt64")]
    [TestCase(true, "InvalidCastExceptionFromInt64ToByte")]
    [TestCase(true, "InvalidCastExceptionFromInt64ToInt16")]
    [TestCase(true, "InvalidCastExceptionFromInt64ToInt32")]
    [TestCase(true, "InvalidCastExceptionFromInt64ToInt64")]
    public sealed class InvalidCastExceptions
    {
        // These cases become from ECMA-335 I.12.4.2.1 - Exceptions thrown by the CLI - Object Model Instructions

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
