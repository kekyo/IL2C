////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C.RuntimeSystems
{
    [TestId("ExceptionThrownByCLI")]
    public sealed class NullReferenceExceptions
    {
        [TestCase(false, "NullReference", "ABC")]
        [TestCase(true, "NullReference", null!)]
        public static bool NullReference(object v)
        {
            try
            {
                var r = v.ToString();
            }
            catch (NullReferenceException)
            {
                return true;
            }
            return false;
        }

        [TestCase(false, "NullReferenceTwoTimes", "ABC")]   // Test for re-register signal handler
        [TestCase(true, "NullReferenceTwoTimes", null!)]
        public static bool NullReferenceTwoTimes(object v)
        {
            var s1 = false;
            try
            {
                var r = v.ToString();
            }
            catch (NullReferenceException)
            {
                s1 = true;
            }

            var s2 = false;
            try
            {
                var r = v.ToString();
            }
            catch (NullReferenceException)
            {
                s2 = true;
            }

            return s1 && s2;
        }

        [TestCase(false, "NullReferenceAtTheUnbox", (object)123)]
        [TestCase(true, "NullReferenceAtTheUnbox", null!)]
        public static bool NullReferenceAtTheUnbox(object value)
        {
            try
            {
                var v = (int)value;
            }
            catch (NullReferenceException)
            {
                return true;
            }
            return false;
        }
    }
}
