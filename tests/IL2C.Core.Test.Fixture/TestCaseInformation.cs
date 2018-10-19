using System.Reflection;
using System.Threading.Tasks;

namespace IL2C
{
    public struct TestCaseInformation
    {
        public readonly string Name;
        public readonly MethodInfo Method;
        public readonly MethodBase[] AdditionalMethods;
        public readonly object Expected;
        public readonly object[] Arguments;

        public TestCaseInformation(string name, MethodInfo method, MethodBase[] additionalMethods, object expected, object[] arguments)
        {
            this.Name = name;
            this.Method = method;
            this.AdditionalMethods = additionalMethods;
            this.Expected = expected;
            this.Arguments = arguments;
        }

        public Task ExecuteTestAsync() =>
            TestFramework.ExecuteTestAsync(this.Name, this.Method, this.AdditionalMethods, this.Expected, this.Arguments);

        public override string ToString()
        {
            return this.Name;
        }
    }
}
