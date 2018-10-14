using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C.ILConverters
{
    [TestFixture]
    public static class ILConverterTest
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
                return string.Format(
                    "{0}.{1}",
                    this.Method.DeclaringType.Name,
                    this.Method.Name);
            }
        }

        public static readonly CaseInfo[] TargetCases =
            (from type in typeof(CaseAttribute).Assembly.GetTypes()
             from testCase in type.GetCustomAttributes<CaseAttribute>(true)
             let method = type.GetMethod(testCase.MethodName, BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly)
             where method != null
             orderby method.DeclaringType.FullName, method.Name
             select new CaseInfo(method, testCase.Expected, testCase.Arguments))
            .ToArray();

        [Test]
        public static Task TestCase(
            [ValueSource("TargetCases")] CaseInfo caseInfo)
        {
            return TestFramework.ExecuteTestAsync(caseInfo.Method, caseInfo.Expected, caseInfo.Arguments);
        }
    }
}
