using System;
using System.ComponentModel;
using System.Threading;

namespace IL2C.RuntimeSystems
{
    public sealed class RunAndFinishClosure
    {
        private int a;
        private int b;
        public int Result;

        public RunAndFinishClosure(int a, int b)
        {
            this.a = a;
            this.b = b;
        }

        public void Run()
        {
            this.Result = this.a + this.b;
        }
    }

    public sealed class RunAndFinishClosureWithParameter
    {
        private int a;
        public int Result;

        public RunAndFinishClosureWithParameter(int a)
        {
            this.a = a;
        }

        public void Run(object parameter)
        {
            var b = (int)parameter;
            this.Result = this.a + b;
        }
    }

    public sealed class WillGetDifferentThreadIdClosure
    {
        public readonly int TestThreadId;
        public int RunThreadId;

        public WillGetDifferentThreadIdClosure()
        {
            this.TestThreadId = Thread.CurrentThread.ManagedThreadId;
        }

        public void Run()
        {
            this.RunThreadId = Thread.CurrentThread.ManagedThreadId;
        }
    }

    [Description("These tests are verified the IL2C can handle threading features.")]
    [TestCase(333, "RunAndFinishInstanceMethod", 111, 222, IncludeTypes = new[] { typeof(RunAndFinishClosure) })]
    [TestCase(333, "RunAndFinishInstanceWithParameterMethod", 111, 222, IncludeTypes = new[] { typeof(RunAndFinishClosureWithParameter) })]
    [TestCase(true, "MultipleRunAndFinishInstanceMethod", 100, 10, IncludeTypes = new[] { typeof(RunAndFinishClosure) })]
    [TestCase(true, "MultipleRunAndFinishInstanceMethod", 100, 100, IncludeTypes = new[] { typeof(RunAndFinishClosure) })]
    [TestCase(true, "WillGetDifferentThreadId", IncludeTypes = new[] { typeof(WillGetDifferentThreadIdClosure) })]
    public sealed class Threading
    {
        public static int RunAndFinishInstanceMethod(int a, int b)
        {
            var target = new RunAndFinishClosure(a, b);
            var thread = new Thread(target.Run);
            thread.Start();
            thread.Join();

            return target.Result;
        }

        public static int RunAndFinishInstanceWithParameterMethod(int a, int b)
        {
            var target = new RunAndFinishClosureWithParameter(a);
            var thread = new Thread(target.Run);
            thread.Start(b);
            thread.Join();

            return target.Result;
        }

        public static bool MultipleRunAndFinishInstanceMethod(int a, int count)
        {
            var targets = new RunAndFinishClosure[count];
            var threads = new Thread[count];
            for (var index = 0; index < count; index++)
            {
                targets[index] = new RunAndFinishClosure(a, index);
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

            for (var index = 0; index < count; index++)
            {
                if (targets[index].Result != (a + index))
                {
                    return false;
                }
            }

            return true;
        }

        public static bool WillGetDifferentThreadId()
        {
            var target = new WillGetDifferentThreadIdClosure();
            var thread = new Thread(target.Run);
            thread.Start();
            thread.Join();

            return target.TestThreadId != target.RunThreadId;
        }
    }
}
