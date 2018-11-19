using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public class InstanceBaseType
    {
        public string GetStringFromInt32(int value)
        {
            return (value + 100).ToString();
        }
    }

    public class InstanceNewType : InstanceBaseType
    {
        public new string GetStringFromInt32(int value)
        {
            return (value + 200).ToString();
        }
    }

    public class InstanceNewVirtualType : InstanceBaseType
    {
        public new virtual string GetStringFromInt32(int value)
        {
            return (value + 200).ToString();
        }
    }

    public class InstanceNewVirtualOverrideType : InstanceNewVirtualType
    {
        public override string GetStringFromInt32(int value)
        {
            return (value + 300).ToString();
        }
    }

    public class InstanceNewCallBaseType : InstanceBaseType
    {
        public new string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class InstanceNewVirtualCallBaseType : InstanceBaseType
    {
        public new virtual string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class InstanceNewVirtualOverrideCallBaseType : InstanceNewVirtualType
    {
        public override string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class VirtualBaseType
    {
        public virtual string GetStringFromInt32(int value)
        {
            return (value + 100).ToString();
        }
    }

    public class VirtualOverrideType : VirtualBaseType
    {
        public override string GetStringFromInt32(int value)
        {
            return (value + 200).ToString();
        }
    }

    public class VirtualNewType : VirtualBaseType
    {
        public new string GetStringFromInt32(int value)
        {
            return (value + 200).ToString();
        }
    }

    public class VirtualNewVirtualType : VirtualBaseType
    {
        public new virtual string GetStringFromInt32(int value)
        {
            return (value + 200).ToString();
        }
    }

    public class VirtualNewVirtualOverrideType : VirtualNewVirtualType
    {
        public override string GetStringFromInt32(int value)
        {
            return (value + 300).ToString();
        }
    }

    public class VirtualOverrideCallBaseType : VirtualBaseType
    {
        public override string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class VirtualNewCallBaseType : VirtualBaseType
    {
        public new string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class VirtualNewVirtualCallBaseType : VirtualBaseType
    {
        public new virtual string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class VirtualOverrideOverrideCallBaseType : VirtualOverrideType
    {
        public override string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    public class VirtualNewVirtualOverrideCallBaseType : VirtualNewVirtualType
    {
        public override string GetStringFromInt32(int value)
        {
            return base.GetStringFromInt32(value) + "ABC";
        }
    }

    [TestId("TypeRelations")]
    [Description("CLR type system contains single-inheritance class types and multiple-implementation interface types. These tests are verified the IL2C can handle the member methods both simple instance methods and complex overriden virtual methods.")]
    [TestCase("223", "InstanceBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType) })]
    [TestCase("323", "InstanceNew", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewType) })]
    [TestCase("223", "InstanceNewFromBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewType) })]
    [TestCase("323", "InstanceNewVirtual", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualType) })]
    [TestCase("223", "InstanceNewVirtualFromBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualType) })]
    [TestCase("423", "InstanceNewVirtualOverride", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualType), typeof(InstanceNewVirtualOverrideType) })]
    [TestCase("223", "InstanceNewVirtualOverrideFromBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualType), typeof(InstanceNewVirtualOverrideType) })]
    [TestCase("423", "InstanceNewVirtualOverrideFromNewVirtual", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualType), typeof(InstanceNewVirtualOverrideType) })]
    [TestCase("223ABC", "InstanceNewCallBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewCallBaseType) })]
    [TestCase("223ABC", "InstanceNewVirtualCallBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualCallBaseType) })]
    [TestCase("323ABC", "InstanceNewVirtualOverrideCallBase", 123, IncludeTypes = new[] { typeof(InstanceBaseType), typeof(InstanceNewVirtualType), typeof(InstanceNewVirtualOverrideCallBaseType) })]
    [TestCase("223", "VirtualBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType) })]
    [TestCase("323", "VirtualOverride", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualOverrideType) })]
    [TestCase("323", "VirtualOverrideFromBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualOverrideType) })]
    [TestCase("323", "VirtualNew", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewType) })]
    [TestCase("223", "VirtualNewFromBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewType) })]
    [TestCase("323", "VirtualNewVirtual", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualType) })]
    [TestCase("223", "VirtualNewVirtualFromBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualType) })]
    [TestCase("423", "VirtualNewVirtualOverride", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualType), typeof(VirtualNewVirtualOverrideType) })]
    [TestCase("223", "VirtualNewVirtualOverrideFromBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualType), typeof(VirtualNewVirtualOverrideType) })]
    [TestCase("423", "VirtualNewVirtualOverrideFromNewVirtual", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualType), typeof(VirtualNewVirtualOverrideType) })]
    [TestCase("223ABC", "VirtualOverrideCallBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualOverrideCallBaseType) })]
    [TestCase("223ABC", "VirtualNewCallBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewCallBaseType) })]
    [TestCase("223ABC", "VirtualNewVirtualCallBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualCallBaseType) })]
    [TestCase("323ABC", "VirtualOverrideOverrideCallBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualOverrideType), typeof(VirtualOverrideOverrideCallBaseType) })]
    [TestCase("323ABC", "VirtualNewVirtualOverrideCallBase", 123, IncludeTypes = new[] { typeof(VirtualBaseType), typeof(VirtualNewVirtualType), typeof(VirtualNewVirtualOverrideCallBaseType) })]
    public sealed class TypeInheritance
    {
        public static string InstanceBase(int value)
        {
            var inst = new InstanceBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNew(int value)
        {
            var inst = new InstanceNewType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewFromBase(int value)
        {
            InstanceBaseType inst = new InstanceNewType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtual(int value)
        {
            var inst = new InstanceNewVirtualType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtualFromBase(int value)
        {
            InstanceBaseType inst = new InstanceNewVirtualType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtualOverride(int value)
        {
            var inst = new InstanceNewVirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtualOverrideFromBase(int value)
        {
            InstanceBaseType inst = new InstanceNewVirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtualOverrideFromNewVirtual(int value)
        {
            InstanceNewVirtualType inst = new InstanceNewVirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewCallBase(int value)
        {
            var inst = new InstanceNewCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtualCallBase(int value)
        {
            var inst = new InstanceNewVirtualCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceNewVirtualOverrideCallBase(int value)
        {
            var inst = new InstanceNewVirtualOverrideCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualBase(int value)
        {
            var inst = new VirtualBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverride(int value)
        {
            var inst = new VirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideFromBase(int value)
        {
            VirtualBaseType inst = new VirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNew(int value)
        {
            var inst = new VirtualNewType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewFromBase(int value)
        {
            VirtualBaseType inst = new VirtualNewType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtual(int value)
        {
            var inst = new VirtualNewVirtualType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtualFromBase(int value)
        {
            VirtualBaseType inst = new VirtualNewVirtualType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtualOverride(int value)
        {
            var inst = new VirtualNewVirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtualOverrideFromBase(int value)
        {
            VirtualBaseType inst = new VirtualNewVirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtualOverrideFromNewVirtual(int value)
        {
            VirtualNewVirtualType inst = new VirtualNewVirtualOverrideType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideCallBase(int value)
        {
            var inst = new VirtualOverrideCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewCallBase(int value)
        {
            var inst = new VirtualNewCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtualCallBase(int value)
        {
            var inst = new VirtualNewVirtualCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualOverrideOverrideCallBase(int value)
        {
            var inst = new VirtualOverrideOverrideCallBaseType();
            return inst.GetStringFromInt32(value);
        }

        public static string VirtualNewVirtualOverrideCallBase(int value)
        {
            var inst = new VirtualNewVirtualOverrideCallBaseType();
            return inst.GetStringFromInt32(value);
        }
    }
}
