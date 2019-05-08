namespace IL2C.RuntimeSystems
{
    public delegate void CSharpEventDelegate(int value);

    public sealed class CSharpEventReceiver
    {
        public int Value;

        public void Receiver1(int value)
        {
            this.Value += value;
        }

        public void Receiver2(int value)
        {
            this.Value += value * 2;
        }

        public void Receiver3(int value)
        {
            this.Value += value * 3;
        }
    }

    public sealed class CSharpEventImpl
    {
        public event CSharpEventDelegate TestEvent;

        public void DoEvent(int value)
        {
            this.TestEvent?.Invoke(value);
        }
    }

    // It's hacked special cases for the C# Roslyn compiler.
    // The C# event member will contain Interlocked.CompareExchange<T>() generic method.
    // It can't translate naturally in current version's IL2C.
    // So it handles the case with hacky code at IL2C.ILConverters.CallConverterUtilities.
    // This test case validates it.
    [TestId("DelegateTypes")]
    [TestCase(6123, "AddCSharpEvent", 1000, IncludeTypes = new[] { typeof(CSharpEventImpl), typeof(CSharpEventDelegate), typeof(CSharpEventReceiver) })]
    [TestCase(4123, "RemoveCSharpEvent", 1000, IncludeTypes = new[] { typeof(CSharpEventImpl), typeof(CSharpEventDelegate), typeof(CSharpEventReceiver) })]
    public sealed class CSharpEvent
    {
        public static int AddCSharpEvent(int value)
        {
            var receiver = new CSharpEventReceiver();
            receiver.Value = 123;

            var instance = new CSharpEventImpl();
            instance.TestEvent += receiver.Receiver1;
            instance.TestEvent += receiver.Receiver2;
            instance.TestEvent += receiver.Receiver3;

            instance.DoEvent(value);

            return receiver.Value;
        }

        public static int RemoveCSharpEvent(int value)
        {
            var receiver = new CSharpEventReceiver();
            receiver.Value = 123;

            var instance = new CSharpEventImpl();
            instance.TestEvent += receiver.Receiver1;
            instance.TestEvent += receiver.Receiver2;
            instance.TestEvent += receiver.Receiver3;
            instance.TestEvent -= receiver.Receiver2;

            instance.DoEvent(value);

            return receiver.Value;
        }
    }
}
