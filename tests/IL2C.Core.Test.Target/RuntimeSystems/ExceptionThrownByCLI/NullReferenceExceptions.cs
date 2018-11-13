using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    [TestId("ExceptionThrownByCLI")]
    [TestCase(false, "NullReference", "ABC")]
    [TestCase(true, "NullReference", null)]
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
    }
}
