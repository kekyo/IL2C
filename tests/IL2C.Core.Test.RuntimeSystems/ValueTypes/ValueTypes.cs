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

using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public struct ValueType1
    {
        public readonly int Value;

        public ValueType1(int value)
        {
            this.Value = value;
        }

        public string GetStringValue() =>
            this.Value.ToString();
    }

    public interface IValueTypeAccessor1
    {
        string GetStringValue();
    }

    public struct ValueType2 : IValueTypeAccessor1
    {
        public readonly int Value;

        public ValueType2(int value)
        {
            this.Value = value;
        }

        public string GetStringValue() =>
            this.Value.ToString();
    }

    public struct ValueTypeWithOverridedVirtual1
    {
        public readonly int Value;

        public ValueTypeWithOverridedVirtual1(int value)
        {
            this.Value = value;
        }

        public override string ToString() =>
            this.Value.ToString();
    }

    public interface IValueTypeOverrideAccessor
    {
        string ToString();
    }

    public struct ValueTypeWithOverridedVirtual2 : IValueTypeOverrideAccessor
    {
        public readonly int Value;

        public ValueTypeWithOverridedVirtual2(int value)
        {
            this.Value = value;
        }

        public override string ToString() =>
            this.Value.ToString();
    }

    public interface IValueTypeAccessor2
    {
        string GetStringValue();
    }

    public struct ValueTypeCombinedInterfaces : IValueTypeAccessor1, IValueTypeAccessor2
    {
        public readonly int Value;

        public ValueTypeCombinedInterfaces(int value)
        {
            this.Value = value;
        }

        public string GetStringValue() =>
            this.Value.ToString();
    }

    public struct ValueTypeCombinedExplicitlyInterfaces : IValueTypeAccessor1, IValueTypeAccessor2
    {
        public readonly int Value;

        public ValueTypeCombinedExplicitlyInterfaces(int value)
        {
            this.Value = value;
        }

        public string GetStringValue() =>
            this.Value.ToString();
        string IValueTypeAccessor1.GetStringValue() =>
            (this.Value + 100).ToString();
        string IValueTypeAccessor2.GetStringValue() =>
            (this.Value + 200).ToString();
    }

    public struct ValueTypeInheritedMethod
    {
    }

    public struct ValueTypeUpdateType1
    {
        public int Value;
        public ValueTypeUpdateType1(int value) => this.Value = value;
        public void Update(int value)
        {
            if (this.Value != 123) throw new Exception();
            this.Value = value;
        }
    }

    public interface IValueTypeUpdateType2
    {
        void Update(int value);
    }

    public struct ValueTypeUpdateType2 : IValueTypeUpdateType2
    {
        public int Value;
        public ValueTypeUpdateType2(int value) => this.Value = value;
        public void Update(int value)
        {
            if (this.Value != 123) throw new Exception();
            this.Value = value;
        }
    }

    public struct ValueTypeUpdateType3
    {
        public int Value;
        public ValueTypeUpdateType3(int value) => this.Value = value;
        public override string ToString()
        {
            if (this.Value != 123) throw new Exception();
            this.Value = 456;
            return this.Value.ToString();
        }
    }

    [Description("Value types are specialized types at the .NET type system. Because the type inherited from the System.ValueType (objref type), all method has the managed pointer at the arg0 and these instances will box and apply the pseudo vptrs. These tests are verified the IL2C can handle value types.")]
    [TestCase("123", "CallInstanceMethod", 123, IncludeTypes = new[] { typeof(ValueType1) })]
    [TestCase("123", "CallInstanceMethodDirectly", 123, IncludeTypes = new[] { typeof(ValueType2), typeof(IValueTypeAccessor1) })]
    [TestCase("123", "CallInstanceMethodBoxedInterface", 123, IncludeTypes = new[] { typeof(ValueType2), typeof(IValueTypeAccessor1) })]
    [TestCase("123", "CallCombinedInstanceMethodDirectly", 123, IncludeTypes = new[] { typeof(ValueTypeCombinedInterfaces), typeof(IValueTypeAccessor1), typeof(IValueTypeAccessor2) })]
    [TestCase("123", "CallCombinedInstanceMethodBoxedInterface1", 123, IncludeTypes = new[] { typeof(ValueTypeCombinedInterfaces), typeof(IValueTypeAccessor1), typeof(IValueTypeAccessor2) })]
    [TestCase("123", "CallCombinedInstanceMethodBoxedInterface2", 123, IncludeTypes = new[] { typeof(ValueTypeCombinedInterfaces), typeof(IValueTypeAccessor1), typeof(IValueTypeAccessor2) })]
    [TestCase("123", "CallCombinedInstanceMethodExplicitlyDirectly", 123, IncludeTypes = new[] { typeof(ValueTypeCombinedExplicitlyInterfaces), typeof(IValueTypeAccessor1), typeof(IValueTypeAccessor2) })]
    [TestCase("223", "CallCombinedInstanceMethodExplicitlyBoxedInterface1", 123, IncludeTypes = new[] { typeof(ValueTypeCombinedExplicitlyInterfaces), typeof(IValueTypeAccessor1), typeof(IValueTypeAccessor2) })]
    [TestCase("323", "CallCombinedInstanceMethodExplicitlyBoxedInterface2", 123, IncludeTypes = new[] { typeof(ValueTypeCombinedExplicitlyInterfaces), typeof(IValueTypeAccessor1), typeof(IValueTypeAccessor2) })]
    [TestCase("123", "CallOverrideMethod", 123, IncludeTypes = new[] { typeof(ValueTypeWithOverridedVirtual1) })]
    [TestCase("123", "CallOverrideMethodDirectly", 123, IncludeTypes = new[] { typeof(ValueTypeWithOverridedVirtual2), typeof(IValueTypeOverrideAccessor) })]
    [TestCase("123", "CallOverrideMethodBoxed", 123, IncludeTypes = new[] { typeof(ValueTypeWithOverridedVirtual2), typeof(IValueTypeOverrideAccessor) })]
    [TestCase("123", "CallOverrideMethodBoxedInterface", 123, IncludeTypes = new[] { typeof(ValueTypeWithOverridedVirtual2), typeof(IValueTypeOverrideAccessor) })]
    [TestCase("IL2C.RuntimeSystems.ValueTypeInheritedMethod", "CallInheritedMethod", IncludeTypes = new[] { typeof(ValueTypeInheritedMethod) })]
    [TestCase(456, "ValueTypeUpdate1", 123, 456, IncludeTypes = new[] { typeof(ValueTypeUpdateType1) })]
    [TestCase(123, "ValueTypeUpdate2", 123, 456, IncludeTypes = new[] { typeof(ValueTypeUpdateType2), typeof(IValueTypeUpdateType2) })]
    [TestCase(123, "ValueTypeUpdate2ExplicitlyBoxed", 123, 456, IncludeTypes = new[] { typeof(ValueTypeUpdateType2), typeof(IValueTypeUpdateType2) })]
    [TestCase(456, "ValueTypeUpdate3", 123, IncludeTypes = new[] { typeof(ValueTypeUpdateType3) })]
    public sealed class ValueTypes
    {
        public static string CallInstanceMethod(int value)
        {
            var v = new ValueType1(value);
            return v.GetStringValue();
        }

        public static string CallInstanceMethodDirectly(int value)
        {
            var v = new ValueType2(value);
            return v.GetStringValue();
        }

        public static string CallInstanceMethodBoxedInterface(int value)
        {
            // implicitly boxed
            IValueTypeAccessor1 v = new ValueType2(value);
            return v.GetStringValue();
        }

        public static string CallCombinedInstanceMethodDirectly(int value)
        {
            var v = new ValueTypeCombinedInterfaces(value);
            return v.GetStringValue();
        }

        public static string CallCombinedInstanceMethodBoxedInterface1(int value)
        {
            // implicitly boxed
            IValueTypeAccessor1 v = new ValueTypeCombinedInterfaces(value);
            return v.GetStringValue();
        }

        public static string CallCombinedInstanceMethodBoxedInterface2(int value)
        {
            // implicitly boxed
            IValueTypeAccessor2 v = new ValueTypeCombinedInterfaces(value);
            return v.GetStringValue();
        }

        public static string CallCombinedInstanceMethodExplicitlyDirectly(int value)
        {
            var v = new ValueTypeCombinedExplicitlyInterfaces(value);
            return v.GetStringValue();
        }

        public static string CallCombinedInstanceMethodExplicitlyBoxedInterface1(int value)
        {
            // implicitly boxed
            IValueTypeAccessor1 v = new ValueTypeCombinedExplicitlyInterfaces(value);
            return v.GetStringValue();
        }

        public static string CallCombinedInstanceMethodExplicitlyBoxedInterface2(int value)
        {
            // implicitly boxed
            IValueTypeAccessor2 v = new ValueTypeCombinedExplicitlyInterfaces(value);
            return v.GetStringValue();
        }

        public static string CallOverrideMethod(int value)
        {
            var v = new ValueTypeWithOverridedVirtual1(value);
            return v.ToString();
        }

        public static string CallOverrideMethodDirectly(int value)
        {
            var v = new ValueTypeWithOverridedVirtual2(value);
            return v.ToString();
        }

        public static string CallOverrideMethodBoxed(int value)
        {
            // implicitly boxed
            object v = new ValueTypeWithOverridedVirtual2(value);
            return v.ToString();
        }

        public static string CallOverrideMethodBoxedInterface(int value)
        {
            // implicitly boxed
            IValueTypeOverrideAccessor v = new ValueTypeWithOverridedVirtual2(value);
            return v.ToString();
        }

        public static string CallInheritedMethod()
        {
            var v = new ValueTypeInheritedMethod();
            return v.ToString();
        }

        public static int ValueTypeUpdate1(int before, int update)
        {
            var v = new ValueTypeUpdateType1(before);
            v.Update(update);
            return v.Value;
        }

        public static int ValueTypeUpdate2(int before, int update)
        {
            var v = new ValueTypeUpdateType2(before);
            ((IValueTypeUpdateType2)v).Update(update);
            return v.Value;
        }

        public static int ValueTypeUpdate2ExplicitlyBoxed(int before, int update)
        {
            var v = new ValueTypeUpdateType2(before);
            IValueTypeUpdateType2 boxed = v;
            boxed.Update(update);
            return v.Value;
        }

        public static int ValueTypeUpdate3(int before)
        {
            var v = new ValueTypeUpdateType3(before);
            var _ = v.ToString();
            return v.Value;
        }
    }
}
