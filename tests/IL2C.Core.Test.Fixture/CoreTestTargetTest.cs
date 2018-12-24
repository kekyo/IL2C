using NUnit.Framework;
using System.Threading.Tasks;

namespace IL2C
{
    [SetUpFixture]
    public sealed class CoreTestTargetTestSetup
    {
        [OneTimeSetUp]
        public static Task OneTimeSetUpAsync()
        {
#if DEBUG
            return GccDriver.SetupRequirementsAsync(false);
#else
            return GccDriver.SetupRequirementsAsync(true);
#endif
        }
    }

    // Generate NUnit dynamic test cases for TestCaseAttribute related from IL2C.Core.Test.Target assembly.
    [CoreTestTarget]
    public sealed class CoreTestTargetTest
    {
    }
}
