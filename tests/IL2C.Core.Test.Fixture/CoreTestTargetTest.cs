using NUnit.Framework;

namespace IL2C
{
    // Generate NUnit dynamic test cases for TestCaseAttribute related from IL2C.Core.Test.Target assembly.
    [CoreTestTarget]
    [Parallelizable(ParallelScope.All)]
    public sealed class CoreTestTargetTest
    {
    }
}
