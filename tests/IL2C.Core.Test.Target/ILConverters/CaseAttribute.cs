using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

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

        public CaseAttribute(object expected, Type expectedType, string methodName, params object[] args)
        {
            this.MethodName = methodName;
            this.Arguments = args;

            if (expectedType == typeof(IntPtr))
            {
                if (expected is int)
                {
                    this.Expected = new IntPtr((int)expected);
                }
                else if (expected is long)
                {
                    this.Expected = new IntPtr((long)expected);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else if (expectedType == typeof(UIntPtr))
            {
                if (expected is uint)
                {
                    this.Expected = new UIntPtr((uint)expected);
                }
                else if (expected is ulong)
                {
                    this.Expected = new UIntPtr((ulong)expected);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else
            {
                this.Expected = Convert.ChangeType(expected, expectedType);
            }
        }

        public string MethodName { get; }
        public object Expected { get; }
        public object[] Arguments { get; }
    }
}
