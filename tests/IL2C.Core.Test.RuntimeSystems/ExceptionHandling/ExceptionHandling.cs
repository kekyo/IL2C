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
    [Description("These tests are verified the IL2C translates with simple and/or complext exception handling.")]
    [TestCase(123, "RaiseAndCaughtLocal", false)]
    [TestCase(456, "RaiseAndCaughtLocal", true)]
    [TestCase("ABC", "RaiseCaughtAndAccessLocal", "ABC")]
    [TestCase(null, "RaiseCaughtAndAccessLocal", null)]
    [TestCase("ABC", "RaiseCaughtNarrowingLocal", "ABC")]
    [TestCase(null, "RaiseCaughtNarrowingLocal", null)]
    [TestCase("ABC", "RaiseCaughtWildcardLocal", "ABC")]
    [TestCase(null, "RaiseCaughtWildcardLocal", null)]
    [TestCase(123, "RaiseAndCaughtMultipleHandlerLocal", 0)]
    [TestCase(456, "RaiseAndCaughtMultipleHandlerLocal", 1)]
    [TestCase(789, "RaiseAndCaughtMultipleHandlerLocal", 2)]
    [TestCase(29, "FinallyWithNonThrowingLocal", 123)]
    [TestCase(129, "FinallyWithThrowingAndNestedLocal", 123)]
    [TestCase(129, "FinallyAndCaughtWithThrowingAndNestedLocal", 123, true)]
    [TestCase(29, "FinallyAndCaughtWithThrowingAndNestedLocal", 123, false)]
    [TestCase(30, new[] { "FinallyAndCaughtWithThrowingAndNestedGlobal", "RaiseException" }, 123, false, false)]
    [TestCase(30, new[] { "FinallyAndCaughtWithThrowingAndNestedGlobal", "RaiseException" }, 123, false, true)]
    [TestCase(12, new[] { "FinallyAndCaughtWithThrowingAndNestedGlobal", "RaiseException" }, 123, true, false)]
    [TestCase(112, new[] { "FinallyAndCaughtWithThrowingAndNestedGlobal", "RaiseException" }, 123, true, true)]
    [TestCase(123, "RaiseAndNestedCaughtLocal", 123)]
    [TestCase(123, "RaiseAndNestedCaughtOuterLocal", 123)]
    [TestCase(223, "RaiseCaughtAndRethrowLocal", 123)]
    [TestCase(223, "RaiseCaughtAndThrowNewExceptionLocal", 123)]
    [TestCase(223, "FinallyThrowNewExceptionLocal", 123)]
    [TestCase(123, new[] { "RaiseAndCaughtGlobal", "RaiseException" }, false)]
    [TestCase(456, new[] { "RaiseAndCaughtGlobal", "RaiseException" }, true)]
    [TestCase(true, "RaiseCaughtAndNestedBlockLocal")]
    [TestCase(true, "RaiseCaughtAndRethrowOnNestedBlockLocal")]
    [TestCase(true, "RaiseCaughtAndRethrowOnMultipleNestedBlockLocal")]
    [TestCase(true, "RaiseCaughtAndRethrowInsideLocal")]
    [TestCase(true, "RaiseCaughtAndRethrowOutsideLocal")]
    public sealed class ExceptionHandling
    {
        public static int RaiseAndCaughtLocal(bool sw)
        {
            try
            {
                if (sw) throw new Exception();
            }
            catch (Exception)
            {
                return 456;
            }
            return 123;
        }

        public static string RaiseCaughtAndAccessLocal(string value)
        {
            try
            {
                if (value != null) throw new Exception(value);
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
            return null;
        }

        public static string RaiseCaughtNarrowingLocal(string value)
        {
            try
            {
                if (value != null) throw new InvalidCastException(value);
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
            return null;
        }

        public static string RaiseCaughtWildcardLocal(string value)
        {
            try
            {
                if (value != null) throw new Exception();
            }
            catch
            {
                return value;
            }
            return null;
        }

        public static int RaiseAndCaughtMultipleHandlerLocal(int sw)
        {
            try
            {
                if (sw == 1) throw new Exception();
                if (sw == 2) throw new InvalidCastException();
            }
            catch (InvalidCastException)
            {
                return 789;
            }
            catch (Exception)
            {
                return 456;
            }
            return 123;
        }

        public static int FinallyWithNonThrowingLocal(int value)
        {
            int r = 0;
            try
            {
                r += value;
            }
            finally
            {
                r %= 47;
            }

            return r;
        }

        public static int FinallyWithThrowingAndNestedLocal(int value)
        {
            int r = value;
            try
            {
                try
                {
                    throw new Exception();
                }
                finally
                {
                    r %= 47;
                }
            }
            catch (Exception)
            {
                r += 100;
            }

            return r;
        }

        public static int FinallyAndCaughtWithThrowingAndNestedLocal(int value, bool rethrow)
        {
            int r = 0;
            try
            {
                try
                {
                    throw new Exception();
                }
                catch (Exception)
                {
                    r += value;
                    if (rethrow) throw;
                }
                finally
                {
                    r %= 47;
                }
            }
            catch (Exception)
            {
                r += 100;
            }

            return r;
        }

        private static void RaiseException(bool sw)
        {
            if (sw) throw new Exception();
        }

        public static int FinallyAndCaughtWithThrowingAndNestedGlobal(int value, bool sw, bool rethrow)
        {
            int r = 500;
            try
            {
                try
                {
                    RaiseException(sw);
                }
                catch (Exception)
                {
                    r += value;
                    if (rethrow) throw;
                }
                finally
                {
                    r %= 47;
                }
            }
            catch (Exception)
            {
                r += 100;
            }

            return r;
        }

        public static int RaiseAndNestedCaughtLocal(int value)
        {
            int r = 0;
            try
            {
                try
                {
                    throw new Exception();
                }
                catch (Exception)
                {
                    r += value;
                }
            }
            catch (Exception)
            {
                r += 100;
            }

            return r;
        }

        public static int RaiseAndNestedCaughtOuterLocal(int value)
        {
            int r = 0;
            try
            {
                try
                {
                    throw new Exception();
                }
                catch (InvalidCastException)
                {
                    r += 100;
                }
            }
            catch (Exception)
            {
                r += value;
            }

            return r;
        }

        public static int RaiseCaughtAndRethrowLocal(int value)
        {
            int r = 0;
            try
            {
                try
                {
                    throw new Exception();
                }
                catch (Exception)
                {
                    r += 100;
                    throw;
                }
            }
            catch (Exception)
            {
                r += value;
            }

            return r;
        }

        public static int RaiseCaughtAndThrowNewExceptionLocal(int value)
        {
            int r = 0;
            try
            {
                try
                {
                    throw new Exception();
                }
                catch (Exception)
                {
                    r += 100;
                    throw new InvalidCastException();
                }
            }
            catch (InvalidCastException)
            {
                r += value;
            }

            return r;
        }

        public static int FinallyThrowNewExceptionLocal(int value)
        {
            int r = 0;
            try
            {
                try
                {
                    throw new Exception();
                }
                finally
                {
                    r += value;
                    throw new InvalidCastException();
                }
            }
            catch (InvalidCastException)
            {
                r += 100;
            }

            return r;
        }

        public static int RaiseAndCaughtGlobal(bool sw)
        {
            try
            {
                RaiseException(sw);
            }
            catch (Exception)
            {
                return 456;
            }
            return 123;
        }

        public static bool RaiseCaughtAndNestedBlockLocal()
        {
            var ex1 = new Exception();
            var ex2 = new Exception();
            try
            {
                throw ex1;
            }
            catch (Exception exo)
            {
                try
                {
                    throw ex2;
                }
                catch (Exception exi)
                {
                    return object.ReferenceEquals(ex1, exo) && object.ReferenceEquals(ex2, exi);
                }
            }
        }

        public static bool RaiseCaughtAndRethrowOnNestedBlockLocal()
        {
            var ex1 = new Exception();
            try
            {
                throw ex1;
            }
            catch (Exception exo)
            {
                try
                {
                    throw;
                }
                catch (Exception exi)
                {
                    return object.ReferenceEquals(ex1, exo) && object.ReferenceEquals(ex1, exi);
                }
            }
        }

        public static bool RaiseCaughtAndRethrowOnMultipleNestedBlockLocal()
        {
            var ex1 = new Exception();
            try
            {
                throw ex1;
            }
            catch (Exception exo)
            {
                try
                {
                    throw;
                }
                catch (Exception exi1)
                {
                    try
                    {
                        throw;
                    }
                    catch (Exception exi2)
                    {
                        return object.ReferenceEquals(ex1, exo) &&
                            object.ReferenceEquals(ex1, exi1) &&
                            object.ReferenceEquals(ex1, exi2);
                    }
                }
            }
        }

        public static bool RaiseCaughtAndRethrowInsideLocal()
        {
            var ex1 = new Exception();
            var ex2 = new Exception();
            Exception exi1_ = null;
            Exception exi2_ = null;
            try
            {
                throw ex1;
            }
            catch (Exception exo)
            {
                try
                {
                    try
                    {
                        throw ex2;
                    }
                    catch (Exception exi2)
                    {
                        exi2_ = exi2;

                        // rethrow ex2
                        throw;
                    }
                }
                catch (Exception exi1)
                {
                    // ex2
                    exi1_ = exi1;
                }

                return object.ReferenceEquals(ex1, exo) &&
                    object.ReferenceEquals(ex2, exi1_) &&  // ex2
                    object.ReferenceEquals(ex2, exi2_);
            }
        }

        public static bool RaiseCaughtAndRethrowOutsideLocal()
        {
            var ex1 = new Exception();
            var ex2 = new Exception();
            Exception exi1_ = null;
            Exception exi2_ = null;
            try
            {
                throw ex1;
            }
            catch (Exception exo)
            {
                try
                {
                    try
                    {
                        throw ex2;
                    }
                    catch (Exception exi2)
                    {
                        exi2_ = exi2;
                    }

                    // rethrow ex1
                    throw;
                }
                catch (Exception exi1)
                {
                    // ex1
                    exi1_ = exi1;
                }

                return object.ReferenceEquals(ex1, exo) &&
                    object.ReferenceEquals(ex1, exi1_) &&  // ex1
                    object.ReferenceEquals(ex2, exi2_);
            }
        }
    }
}
