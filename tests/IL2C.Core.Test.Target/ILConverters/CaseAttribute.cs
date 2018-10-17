using System;
using System.Linq;

namespace IL2C.ILConverters
{
    public static class Case
    {
        public const string TrapBreak = "31D1EAB1-2830-458D-9572-4363CDD8DA73";
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    public sealed class CaseAttribute : Attribute
    {
        public CaseAttribute(object expected, string methodName, params object[] args)
        {
            this.MethodName = methodName;
            this.AdditionalMethodNames = new string[0];
            this.Expected = expected;
            this.Arguments = args;
        }

        public CaseAttribute(object expected, string[] methodNames, params object[] args)
        {
            this.MethodName = methodNames[0];
            this.AdditionalMethodNames = methodNames.Skip(1).ToArray();
            this.Expected = expected;
            this.Arguments = args;
        }

        private static object ConvertTo(object value, Type targetType)
        {
            if (value == null)
            {
                return null;
            }
            else if (value.GetType() == targetType)
            {
                return value;
            }
            else if (targetType == typeof(IntPtr))
            {
                if (value is int)
                {
                    return new IntPtr((int)value);
                }
                else if (value is long)
                {
                    return new IntPtr((long)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else if (targetType == typeof(UIntPtr))
            {
                if (value is uint)
                {
                    return new UIntPtr((uint)value);
                }
                else if (value is ulong)
                {
                    return new UIntPtr((ulong)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else
            {
                return Convert.ChangeType(value, targetType);
            }
        }

        public string MethodName { get; }
        public string[] AdditionalMethodNames { get; }
        public object Expected { get; }
        public object[] Arguments { get; }
    }
}
