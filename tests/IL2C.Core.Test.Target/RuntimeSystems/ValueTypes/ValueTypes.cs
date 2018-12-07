using System;
using System.ComponentModel;
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

    public interface IValueTypeAccessor
    {
        string GetStringValue();
    }

    public struct ValueType2 : IValueTypeAccessor
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
    [TestCase("123", "CallInstanceMethodDirectly", 123, IncludeTypes = new[] { typeof(ValueType2), typeof(IValueTypeAccessor) })]
    [TestCase("123", "CallInstanceMethodBoxedInterface", 123, IncludeTypes = new[] { typeof(ValueType2), typeof(IValueTypeAccessor) })]
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
            IValueTypeAccessor v = new ValueType2(value);
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
