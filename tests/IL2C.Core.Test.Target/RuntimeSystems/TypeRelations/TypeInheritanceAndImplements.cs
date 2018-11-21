using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public class InstanceImplicitlyImplementType : InstanceBaseType, IInterfaceType1
    {
    }

    public class InstanceNewAndImplementType : InstanceBaseType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceNewAndImplicitlyImplementType : InstanceImplicitlyImplementType
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceNewAndImplicitlyAndOverrideImplementType : InstanceImplicitlyImplementType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    [TestId("TypeRelations")]
    [TestCase("223", "InstanceImplicitlyImplement", 123, IncludeTypes = new[] { typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("223", "InstanceImplicitlyImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplement", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplicitlyImplement", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplicitlyImplementType), typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("223", "InstanceNewAndImplicitlyImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplicitlyImplementType), typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplicitlyAndOverrideImplement", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplicitlyAndOverrideImplementType), typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplicitlyAndOverrideImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplicitlyAndOverrideImplementType), typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    public sealed class TypeInheritanceAndImplements
    {
        public static string InstanceImplicitlyImplement(int value)
        {
            var inst = new InstanceImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceImplicitlyImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplement(int value)
        {
            var inst = new InstanceNewAndImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceNewAndImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplicitlyImplement(int value)
        {
            var inst = new InstanceNewAndImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplicitlyImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceNewAndImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplicitlyAndOverrideImplement(int value)
        {
            var inst = new InstanceNewAndImplicitlyAndOverrideImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplicitlyAndOverrideImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceNewAndImplicitlyAndOverrideImplementType();
            return inst.GetStringFromInt32(value);
        }
    }
}
