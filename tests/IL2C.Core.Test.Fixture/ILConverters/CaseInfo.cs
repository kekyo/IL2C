using System.Reflection;

namespace IL2C.ILConverters
{
    public struct CaseInfo
    {
        public readonly string Name;
        public readonly MethodInfo Method;
        public readonly MethodBase[] AdditionalMethods;
        public readonly object Expected;
        public readonly object[] Arguments;

        public CaseInfo(string name, MethodInfo method, MethodBase[] additionalMethods, object expected, object[] arguments)
        {
            this.Name = name;
            this.Method = method;
            this.AdditionalMethods = additionalMethods;
            this.Expected = expected;
            this.Arguments = arguments;
        }

        public override string ToString()
        {
            return this.Name;
        }
    }
}
