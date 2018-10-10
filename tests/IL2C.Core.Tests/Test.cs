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
        [TestCaseExplicit("Square", 2)]
        public static Task TestTarget(string testName, object[] args)
        {
            return TestFramework.ExecuteTestAsync(typeof(TestTarget), testName, args);
        }
    }
}
