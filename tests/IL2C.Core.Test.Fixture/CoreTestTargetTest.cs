////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

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
