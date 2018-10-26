using System.Reflection;
using System.Threading.Tasks;

namespace IL2C
{
    public struct TestCaseInformation
    {
        public readonly string Id;
        public readonly string Name;
        public readonly MethodInfo Method;
        public readonly MethodBase[] AdditionalMethods;
        public readonly object Expected;
        public readonly object[] Arguments;
        public readonly TestCaseAsserts Assert;

        public TestCaseInformation(
            string id, string name, object expected, TestCaseAsserts assert,
            MethodInfo method, MethodBase[] additionalMethods, object[] arguments)
        {
            this.Id = id;
            this.Name = name;
            this.Method = method;
            this.AdditionalMethods = additionalMethods;
            this.Expected = expected;
            this.Arguments = arguments;
            this.Assert = assert;
        }

        public Task ExecuteTestAsync(string categoryName) =>
            TestFramework.ExecuteTestAsync(
                categoryName, this.Id, this.Name, this.Expected, this.Assert,
                this.Method, this.AdditionalMethods, this.Arguments);

        public override string ToString()
        {
            return this.Name;
        }
    }
}
