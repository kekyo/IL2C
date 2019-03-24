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
