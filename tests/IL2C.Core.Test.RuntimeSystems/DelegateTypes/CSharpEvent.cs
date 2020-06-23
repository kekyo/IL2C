/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
