using System;
using System.Linq;

using Mono.Cecil;

namespace IL2C.Metadata.Attributes
{
    internal static class CustomAttributeExtensions
    {
        public static T GetArgument<T>(this CustomAttribute attribute, int index)
        {
            return (T)attribute.ConstructorArguments[index].Value;
        }

        public static T GetProperty<T>(this CustomAttribute attribute, string name, Func<object, T> filter)
        {
            return attribute.Properties.
                Where(p => p.Name == name).
                Select(p => filter(p.Argument.Value)).
                FirstOrDefault();
        }

        public static T GetProperty<T>(this CustomAttribute attribute, string name)
        {
            return attribute.GetProperty(name, value => (T)value);
        }
    }
}
