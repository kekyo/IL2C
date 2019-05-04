using NUnit.Framework;
using System.Diagnostics;

namespace IL2C
{
    [SetUpFixture]
    [Parallelizable(ParallelScope.All)]
    public sealed class CoreTestTargetTestSetup
    {
        [OneTimeSetUp]
        [Parallelizable(ParallelScope.All)]
        public static void OneTimeSetUp() =>
            Process.GetCurrentProcess().PriorityClass = ProcessPriorityClass.Idle;
    }

    // Generate NUnit dynamic test cases for TestCaseAttribute related from IL2C.Core.Test.Target assembly.
    [CoreTestTarget]
    [Parallelizable(ParallelScope.All)]
    public sealed class CoreTestTargetTest
    {
    }
}
