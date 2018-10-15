using System.Reflection;

namespace IL2C.ILConverters
{
    public struct CaseInfo
    {
        public readonly string Name;
        public readonly MethodInfo Method;
        public readonly object Expected;
        public readonly object[] Arguments;

        public CaseInfo(string name, MethodInfo method, object expected, object[] arguments)
        {
            this.Name = name;
            this.Method = method;
            this.Expected = expected;
            this.Arguments = arguments;
        }

        public override string ToString()
        {
            return this.Name;
        }
    }
}
