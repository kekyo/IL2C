using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    [TestId("ExceptionThrownByCLI")]
    [TestCase(false, "NullReference", "ABC")]
    [TestCase(true, "NullReference", null)]
    [TestCase(false, "NullReferenceTwoTimes", "ABC")]   // Test for re-register signal handler
    [TestCase(true, "NullReferenceTwoTimes", null)]
    [TestCase(false, "NullReferenceAtTheUnbox", (object)123)]
    [TestCase(true, "NullReferenceAtTheUnbox", null)]
    public sealed class NullReferenceExceptions
    {
        public static bool NullReference(object v)
        {
            try
            {
                var r = v.ToString();
            }
            catch (NullReferenceException ex)
            {
                return ex.Message == "Object reference not set to an instance of an object.";
            }
            return false;
        }

        public static bool NullReferenceTwoTimes(object v)
        {
            try
            {
                var r = v.ToString();
            }
            catch (NullReferenceException ex)
            {
                if (ex.Message != "Object reference not set to an instance of an object.")
                {
                    return false;
                }
            }

            try
            {
                var r = v.ToString();
            }
            catch (NullReferenceException ex)
            {
                return ex.Message == "Object reference not set to an instance of an object.";
            }

            return false;
        }

        public static bool NullReferenceAtTheUnbox(object value)
        {
            try
            {
                var v = (int)value;
            }
            catch (NullReferenceException ex)
            {
                return ex.Message == "Object reference not set to an instance of an object.";
            }

            return false;
        }
    }
}
