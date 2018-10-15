using System;
using System.Collections.Generic;
using System.Linq;

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

        public CaseAttribute(object expected, Type targetType, string methodName, params object[] args)
        {
            this.MethodName = methodName;
            this.Expected = ConvertTo(expected, targetType);
            this.Arguments = Pair<object, Type, object>(args)
                .Select(entry => ConvertTo(entry.Item2, entry.Item1))
                .ToArray();
        }

        private static IEnumerable<(U1, U2)> Pair<T, U1, U2>(IEnumerable<T> enumerable)
        {
            using (var e = enumerable.GetEnumerator())
            {
                while (e.MoveNext())
                {
                    var v1 = (U1)(object)e.Current;
                    if (e.MoveNext())
                    {
                        var v2 = (U2)(object)e.Current;
                        yield return (v1, v2);
                    }
                    else
                    {
                        break;
                    }
                }
            }
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
