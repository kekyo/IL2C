using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [Parallelizable(ParallelScope.All)]
    public sealed class RuntimeSystemsTest
    {
        [DynamicTest(typeof(IL2C.RuntimeSystems.EnumTypes))]
        public static Task EnumTypes(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        [DynamicTest(
            typeof(IL2C.RuntimeSystems.DelegateTypes),
            typeof(IL2C.RuntimeSystems.MulticastDelegateTypes),
            typeof(IL2C.RuntimeSystems.DelegateTypesWithVirtual1),
            typeof(IL2C.RuntimeSystems.DelegateTypesWithVirtual2))]
        public static Task DelegateTypes(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        [DynamicTest(typeof(IL2C.RuntimeSystems.ArrayTypes))]
        public static Task ArrayTypes(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        [DynamicTest(typeof(IL2C.RuntimeSystems.ValueTypes))]
        public static Task ValueTypes(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        [DynamicTest(typeof(IL2C.RuntimeSystems.ExceptionHandling))]
        public static Task ExceptionHandling(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        [DynamicTest(
            typeof(IL2C.RuntimeSystems.InvalidCastExceptions),
            typeof(IL2C.RuntimeSystems.ArrayIndexOutOfRangeExceptions),
            typeof(IL2C.RuntimeSystems.NullReferenceExceptions))]
        public static Task ExceptionThrownByCLI(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        [DynamicTest(
            typeof(IL2C.RuntimeSystems.TypeInheritance),
            typeof(IL2C.RuntimeSystems.TypeImplements),
            typeof(IL2C.RuntimeSystems.TypeInheritanceAndImplements))]
        public static Task TypeRelations(TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
    }
}
