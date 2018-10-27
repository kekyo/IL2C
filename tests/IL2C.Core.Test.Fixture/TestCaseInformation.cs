using System.Reflection;

namespace IL2C
{
    public struct TestCaseInformation
    {
        public readonly string CategoryName;
        public readonly string Id;
        public readonly string Name;
        public readonly MethodInfo Method;
        public readonly MethodBase[] AdditionalMethods;
        public readonly object Expected;
        public readonly object[] Arguments;
        public readonly TestCaseAsserts Assert;
        public readonly bool IncludeBaseTypes;

        public TestCaseInformation(
            string categoryName, string id, string name, object expected, TestCaseAsserts assert, bool includeBaseTypes,
            MethodInfo method, MethodBase[] additionalMethods, object[] arguments)
        {
            this.CategoryName = categoryName;
            this.Id = id;
            this.Name = name;
            this.Method = method;
            this.AdditionalMethods = additionalMethods;
            this.Expected = expected;
            this.Arguments = arguments;
            this.Assert = assert;
            this.IncludeBaseTypes = includeBaseTypes;
        }

        public override string ToString()
        {
            // For test explorer friendly format.
            return this.Name;
        }
    }
}
