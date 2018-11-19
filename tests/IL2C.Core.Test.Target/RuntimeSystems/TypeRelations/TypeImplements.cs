using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public interface IInterfaceType
    {
        string GetStringFromInt32(int value);
    }

    public class InstanceImplementType : IInterfaceType
    {
        public string GetStringFromInt32(int value)
        {
            return (value + 100).ToString();
        }
    }

    [TestId("TypeRelations")]
    [TestCase("223", "InstanceImplement", 123, IncludeTypes = new[] { typeof(InstanceImplementType), typeof(IInterfaceType) })]
    [TestCase("223", "InstanceImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceImplementType), typeof(IInterfaceType) })]
    public sealed class TypeImplements
    {
        public static string InstanceImplement(int value)
        {
            var inst = new InstanceImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceImplementFromInterface(int value)
        {
            IInterfaceType inst = new InstanceImplementType();
            return inst.GetStringFromInt32(value);
        }
    }
}
