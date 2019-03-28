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
            Thread.Sleep(100);
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
            Thread.Sleep(100);
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
            Thread.Sleep(100);
            this.RunThreadId = Thread.CurrentThread.ManagedThreadId;
        }
    }

    public sealed class RaceFreeWithObjectMonitorLockClosure
    {
        private readonly object obj = new Object();
        public int Value;

        public void Increment()
        {
            Monitor.Enter(obj);
            var v = this.Value;
            Thread.Sleep(10);
            this.Value = v + 1;
            Monitor.Exit(obj);
        }

        public void Run()
        {
            for (var index = 0; index < 10; index++)
            {
                this.Increment();
            }
        }
    }

    [Description("These tests are verified the IL2C can handle threading features.")]
    [TestCase(333, "RunAndFinishInstanceMethod", 111, 222, IncludeTypes = new[] { typeof(RunAndFinishClosure) })]
    [TestCase(333, "RunAndFinishInstanceWithParameterMethod", 111, 222, IncludeTypes = new[] { typeof(RunAndFinishClosureWithParameter) })]
    [TestCase(true, "MultipleRunAndFinishInstanceMethod", 100, 10, IncludeTypes = new[] { typeof(RunAndFinishClosure) })]
    [TestCase(true, "MultipleRunAndFinishInstanceMethod", 100, 100, IncludeTypes = new[] { typeof(RunAndFinishClosure) })]
    [TestCase(true, "WillGetDifferentThreadId", IncludeTypes = new[] { typeof(WillGetDifferentThreadIdClosure) })]
    [TestCase(100, "RaceFreeWithObjectMonitorLock", 10, IncludeTypes = new[] { typeof(RaceFreeWithObjectMonitorLockClosure) })]
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

        public static int RaceFreeWithObjectMonitorLock(int count)
        {
            var target = new RaceFreeWithObjectMonitorLockClosure();

            var threads = new Thread[count];
            for (var index = 0; index < count; index++)
            {
                threads[index] = new Thread(target.Run);
            }
            for (var index = 0; index < count; index++)
            {
                threads[index].Start();
            }
            for (var index = 0; index < count; index++)
            {
                threads[index].Join();
            }

            return target.Value;
        }
    }
}
