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
        public static readonly TestCaseInformation[] _System_Byte = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Byte>();
        [Test]
        public static Task System_Byte([ValueSource("_System_Byte")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_SByte = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_SByte>();
        [Test]
        public static Task System_SByte([ValueSource("_System_SByte")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Int16 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Int16>();
        [Test]
        public static Task System_Int16([ValueSource("_System_Int16")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Int32 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Int32>();
        [Test]
        public static Task System_Int32([ValueSource("_System_Int32")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");
    }
}
