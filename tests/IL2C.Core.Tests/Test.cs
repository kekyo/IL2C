using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    public sealed class Test
    {
        [TestCase("ByteMainBody")]
        public static Task TestTarget(string testName)
        {
            return TestFramework.ExecuteTestAsync(typeof(Target), testName);
        }
    }
}
