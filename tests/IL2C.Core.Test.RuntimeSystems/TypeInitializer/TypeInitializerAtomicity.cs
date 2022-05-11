////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Threading;

namespace IL2C.RuntimeSystems
{
    public static class TypeInitializer_Atomicity
    {
        public static readonly int Int32Value;

        static TypeInitializer_Atomicity()
        {
            Thread.Sleep(500);
            Int32Value += 123;   // actual only once.
        }
    }

    public sealed class MultipleExecutionClosure
    {
        public int Value;

        public void Run()
        {
            this.Value = TypeInitializer_Atomicity.Int32Value;
        }
    }

    public static class TypeInitializer_Atomicity_NoTypeInitializer
    {
        public static readonly int Int32Value;
    }

    public sealed class MultipleExecutionClosure_NoTypeInitializer
    {
        public int Value;

        public void Run()
        {
            this.Value = TypeInitializer_Atomicity_NoTypeInitializer.Int32Value;
        }
    }

    [TestCase(1230, "MultipleExecution", 10, IncludeTypes = new[] { typeof(MultipleExecutionClosure), typeof(TypeInitializer_Atomicity) })]
    [TestCase(0, "MultipleExecutionWithNoTypeInitializer", 40, IncludeTypes = new[] { typeof(MultipleExecutionClosure_NoTypeInitializer), typeof(TypeInitializer_Atomicity_NoTypeInitializer) })]
    [TestCase(246, "AfterInitialized", IncludeTypes = new[] { typeof(TypeInitializer_Atomicity) })]
    partial class TypeInitializer
    {
        public static int MultipleExecution(int count)
        {
            var targets = new MultipleExecutionClosure[count];
            var threads = new Thread[count];
            for (var index = 0; index < count; index++)
            {
                targets[index] = new MultipleExecutionClosure();
                threads[index] = new Thread(targets[index].Run);
            }

            for (var index = 0; index < count; index++)
            {
                threads[index].Start();
            }

            for (var index = 0; index < count; index++)
            {
                threads[index].Join();
            }

            // Will not deadlock by any suspend executing type initializer...

            var sum = 0;
            for (var index = 0; index < count; index++)
            {
                sum += targets[index].Value;
            }

            return sum;
        }

        public static int MultipleExecutionWithNoTypeInitializer(int count)
        {
            var targets = new MultipleExecutionClosure_NoTypeInitializer[count];
            var threads = new Thread[count];
            for (var index = 0; index < count; index++)
            {
                targets[index] = new MultipleExecutionClosure_NoTypeInitializer();
                threads[index] = new Thread(targets[index].Run);
            }

            for (var index = 0; index < count; index++)
            {
                threads[index].Start();
            }

            for (var index = 0; index < count; index++)
            {
                threads[index].Join();
            }

            var sum = 0;
            for (var index = 0; index < count; index++)
            {
                sum += targets[index].Value;
            }

            return sum;
        }

        public static int AfterInitialized()
        {
            var value0 = TypeInitializer_Atomicity.Int32Value;
            var value1 = TypeInitializer_Atomicity.Int32Value;

            return value0 + value1;
        }
    }
}
