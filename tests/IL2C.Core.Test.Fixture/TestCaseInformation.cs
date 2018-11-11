using System;
using System.Reflection;

namespace IL2C
{
    public struct TestCaseInformation
    {
        public readonly string CategoryName;
        public readonly string Id;
        public readonly string Name;
        public readonly string Description;
        public readonly MethodInfo Method;
        public readonly Type[] AdditionalTypes;
        public readonly MethodBase[] AdditionalMethods;
        public readonly object Expected;
        public readonly object[] Arguments;
        public readonly TestCaseAsserts Assert;

        public TestCaseInformation(
            string categoryName, string id, string name, string description, object expected, TestCaseAsserts assert,
            MethodInfo method, Type[] additionalTypes, MethodBase[] additionalMethods, object[] arguments)
        {
            this.CategoryName = categoryName;
            this.Id = id;
            this.Name = name;
            this.Description = description;
            this.Method = method;
            this.AdditionalTypes = additionalTypes;
            this.AdditionalMethods = additionalMethods;
            this.Expected = expected;
            this.Arguments = arguments;
            this.Assert = assert;
        }

        public override string ToString()
        {
            // For test explorer friendly format.
            return this.Name;
        }
    }
}
