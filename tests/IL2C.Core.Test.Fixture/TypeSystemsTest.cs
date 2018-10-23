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

        public static readonly TestCaseInformation[] _System_Int16 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Int16>();
        [Test]
        public static Task System_Int16([ValueSource("_System_Int16")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Int32 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Int32>();
        [Test]
        public static Task System_Int32([ValueSource("_System_Int32")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Int64 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Int64>();
        [Test]
        public static Task System_Int64([ValueSource("_System_Int64")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_SByte = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_SByte>();
        [Test]
        public static Task System_SByte([ValueSource("_System_SByte")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_UInt16 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_UInt16>();
        [Test]
        public static Task System_UInt16([ValueSource("_System_UInt16")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_UInt32 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_UInt32>();
        [Test]
        public static Task System_UInt32([ValueSource("_System_UInt32")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_UInt64 = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_UInt64>();
        [Test]
        public static Task System_UInt64([ValueSource("_System_UInt64")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Single = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Single>();
        [Test]
        public static Task System_Single([ValueSource("_System_Single")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Double = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Double>();
        [Test]
        public static Task System_Double([ValueSource("_System_Double")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");

        public static readonly TestCaseInformation[] _System_Char = TestUtilities.GetTestCaseInformations<IL2C.TypeSystems.System_Char>();
        [Test]
        public static Task System_Char([ValueSource("_System_Char")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync("TypeSystems");
    }
}
