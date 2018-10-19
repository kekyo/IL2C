using System;
using System.Linq;

namespace IL2C
{
    public static class Case
    {
        // The expected value tests causing break opcode.
        public const string CauseBreak = "31D1EAB1-2830-458D-9572-4363CDD8DA73";
    }

    // It's test case attribute contains expected value, method name and argument values at overall.
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    public sealed class TestCaseAttribute : Attribute
    {
        public TestCaseAttribute(object expected, string methodName, params object[] args)
        {
            this.MethodName = methodName;
            this.AdditionalMethodNames = new string[0];
            this.Expected = expected;
            this.Arguments = args;
        }

        // This overload contains additional methods, those are used from the test method (first methodName entry.)
        public TestCaseAttribute(object expected, string[] methodNames, params object[] args)
        {
            this.MethodName = methodNames[0];   // test method
            this.AdditionalMethodNames = methodNames.Skip(1).ToArray();   // additionals
            this.Expected = expected;
            this.Arguments = args;
        }

        public string MethodName { get; }
        public string[] AdditionalMethodNames { get; }
        public object Expected { get; }
        public object[] Arguments { get; }
    }
}
