using System;

namespace IL2C.ILConverters
{
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    public sealed class CaseAttribute : Attribute
    {
        public CaseAttribute(object expected, string methodName, params object[] args)
        {
            this.MethodName = methodName;
            this.Expected = expected;
            this.Arguments = args;
        }

        public CaseAttribute(object expected, Type targetType, string methodName)
        {
            this.MethodName = methodName;
            this.Expected = ConvertTo(expected, targetType);
            this.Arguments = new object[0];
        }

        public CaseAttribute(object expected, Type targetType, string methodName, object arg0)
        {
            this.MethodName = methodName;
            this.Expected = ConvertTo(expected, targetType);
            this.Arguments = new[] { ConvertTo(arg0, targetType) };
        }

        private static object ConvertTo(object value, Type targetType)
        {
            if (targetType == typeof(IntPtr))
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
        public object Expected { get; }
        public object[] Arguments { get; }
    }
}
