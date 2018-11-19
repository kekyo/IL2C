using System.Linq;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    [Parallelizable(ParallelScope.All)]
    public sealed class RuntimeSystemsTest
    {
        public static readonly TestCaseInformation[] _EnumTypes = TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.EnumTypes>();
        [Test]
        public static Task EnumTypes([ValueSource(nameof(_EnumTypes))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _DelegateTypes =
            TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.DelegateTypes>().
            Concat(TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.MulticastDelegateTypes>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.DelegateTypesWithVirtual1>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.DelegateTypesWithVirtual2>()).
            ToArray();
        [Test]
        public static Task DelegateTypes([ValueSource(nameof(_DelegateTypes))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _ArrayTypes = TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.ArrayTypes>();
        [Test]
        public static Task ArrayTypes([ValueSource(nameof(_ArrayTypes))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _ExceptionHandling =
            TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.ExceptionHandling>();
        [Test]
        public static Task ExceptionHandling([ValueSource(nameof(_ExceptionHandling))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _ExceptionThrownByCLI =
            TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.InvalidCastExceptions>().
            Concat(TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.ArrayIndexOutOfRangeExceptions>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.NullReferenceExceptions>()).
            ToArray();
        [Test]
        public static Task ExceptionThrownByCLI([ValueSource(nameof(_ExceptionThrownByCLI))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _TypeRelations =
            TestUtilities.GetTestCaseInformations<IL2C.RuntimeSystems.TypeRelations>();
        [Test]
        public static Task TypeRelations([ValueSource(nameof(_TypeRelations))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
    }
}
