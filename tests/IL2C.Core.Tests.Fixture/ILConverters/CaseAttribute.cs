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
        public CaseAttribute(string methodName, object expected, params object[] args)
        {
            this.MethodName = methodName;
            this.Expected = expected;
            this.Arguments = args;
        }

        public string MethodName { get; }
        public object Expected { get; }
        public object[] Arguments { get; }
    }
}
