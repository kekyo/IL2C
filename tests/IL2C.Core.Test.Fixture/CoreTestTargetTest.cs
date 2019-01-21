using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [SetUpFixture]
    [Parallelizable(ParallelScope.All)]
    public sealed class CoreTestTargetTestSetup
    {
        [OneTimeSetUp]
        [Parallelizable(ParallelScope.All)]
        public static Task OneTimeSetUpAsync()
        {
#if DEBUG
            return TestFramework.SetupRequirementsAsync(false);
#else
            return TestFramework.SetupRequirementsAsync(true);
#endif
        }
    }

    // Generate NUnit dynamic test cases for TestCaseAttribute related from IL2C.Core.Test.Target assembly.
    [CoreTestTarget]
    [Parallelizable(ParallelScope.All)]
    public sealed class CoreTestTargetTest
    {
    }
}
