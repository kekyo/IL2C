using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C.ILConverters
{
    public struct CaseInfo
    {
        public readonly MethodInfo Method;
        public readonly object Expected;
        public readonly object[] Arguments;

        public CaseInfo(MethodInfo method, object expected, object[] arguments)
        {
            this.Method = method;
            this.Expected = expected;
            this.Arguments = arguments;
        }

        private static string PrettyPrint(object value)
        {
            return
                (value == null) ? "null" :
                (value is string) ? ("\"" + value + "\"") :
                value.ToString();
        }

        public override string ToString()
        {
            return this.Method.Name;
        }
    }
}
