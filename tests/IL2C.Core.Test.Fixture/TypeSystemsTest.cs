using System;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    [Parallelizable(ParallelScope.All)]
    public sealed class TypeSystemsTest
    {
        #region Int32
        public static readonly TestCaseInformation[] _System_Int32 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Int32>();
        [Test]
        public static Task System_Int32([ValueSource("_System_Int32")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");
        #endregion
    }
}
