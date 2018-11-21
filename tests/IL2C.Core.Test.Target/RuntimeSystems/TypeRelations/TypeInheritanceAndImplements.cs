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

    public class InstanceNewAndNewImplementType : InstanceNewAndImplementType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 300;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceNewAndImplicitlyAndNewImplementType : InstanceImplicitlyImplementType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class VirtualImplicitlyImplementType : VirtualBaseType, IInterfaceType1
    {
    }

    public class VirtualNewAndImplementType : VirtualBaseType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class VirtualNewAndImplicitlyImplementType : VirtualImplicitlyImplementType
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class VirtualNewAndNewImplementType : VirtualNewAndImplementType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 300;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class VirtualOverrideAndImplementType : VirtualBaseType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public override string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class VirtualOverrideAndImplicitlyImplementType : VirtualImplicitlyImplementType
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public override string GetStringFromInt32(int value)
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
    [TestCase("423", "InstanceNewAndNewImplement", 123, IncludeTypes = new[] { typeof(InstanceNewAndNewImplementType), typeof(InstanceNewAndImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("423", "InstanceNewAndNewImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceNewAndNewImplementType), typeof(InstanceNewAndImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplicitlyAndNewImplement", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplicitlyAndNewImplementType), typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "InstanceNewAndImplicitlyAndNewImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceNewAndImplicitlyAndNewImplementType), typeof(InstanceImplicitlyImplementType), typeof(InstanceBaseType), typeof(IInterfaceType1) })]
    [TestCase("223", "VirtualImplicitlyImplement", 123, IncludeTypes = new[] { typeof(VirtualImplicitlyImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("223", "VirtualImplicitlyImplementFromInterface", 123, IncludeTypes = new[] { typeof(VirtualImplicitlyImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualNewAndImplement", 123, IncludeTypes = new[] { typeof(VirtualNewAndImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualNewAndImplementFromInterface", 123, IncludeTypes = new[] { typeof(VirtualNewAndImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualNewAndImplicitlyImplement", 123, IncludeTypes = new[] { typeof(VirtualNewAndImplicitlyImplementType), typeof(VirtualImplicitlyImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("223", "VirtualNewAndImplicitlyImplementFromInterface", 123, IncludeTypes = new[] { typeof(VirtualNewAndImplicitlyImplementType), typeof(VirtualImplicitlyImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("423", "VirtualNewAndNewImplement", 123, IncludeTypes = new[] { typeof(VirtualNewAndNewImplementType), typeof(VirtualNewAndImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("423", "VirtualNewAndNewImplementFromInterface", 123, IncludeTypes = new[] { typeof(VirtualNewAndNewImplementType), typeof(VirtualNewAndImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualOverrideAndImplement", 123, IncludeTypes = new[] { typeof(VirtualOverrideAndImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualOverrideAndImplementFromInterface", 123, IncludeTypes = new[] { typeof(VirtualOverrideAndImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualOverrideAndImplicitlyImplement", 123, IncludeTypes = new[] { typeof(VirtualOverrideAndImplicitlyImplementType), typeof(VirtualImplicitlyImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
    [TestCase("323", "VirtualOverrideAndImplicitlyImplementFromInterface", 123, IncludeTypes = new[] { typeof(VirtualOverrideAndImplicitlyImplementType), typeof(VirtualImplicitlyImplementType), typeof(VirtualBaseType), typeof(IInterfaceType1) })]
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

        public static string InstanceNewAndNewImplement(int value)
        {
            var inst = new InstanceNewAndNewImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndNewImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceNewAndNewImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplicitlyAndNewImplement(int value)
        {
            var inst = new InstanceNewAndImplicitlyAndNewImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewAndImplicitlyAndNewImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceNewAndImplicitlyAndNewImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualImplicitlyImplement(int value)
        {
            var inst = new VirtualImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualImplicitlyImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new VirtualImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewAndImplement(int value)
        {
            var inst = new VirtualNewAndImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewAndImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new VirtualNewAndImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewAndImplicitlyImplement(int value)
        {
            var inst = new VirtualNewAndImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewAndImplicitlyImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new VirtualNewAndImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewAndNewImplement(int value)
        {
            var inst = new VirtualNewAndNewImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewAndNewImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new VirtualNewAndNewImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideAndImplement(int value)
        {
            var inst = new VirtualOverrideAndImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideAndImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new VirtualOverrideAndImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideAndImplicitlyImplement(int value)
        {
            var inst = new VirtualOverrideAndImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideAndImplicitlyImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new VirtualOverrideAndImplicitlyImplementType();
            return inst.GetStringFromInt32(value);
        }
    }
}
