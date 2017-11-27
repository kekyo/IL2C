using Mono.Cecil;

namespace IL2C.Translators
{
    public struct Parameter
    {
        public readonly string Name;
        public readonly TypeReference ParameterType;

        public Parameter(string name, TypeReference parameterType)
        {
            this.Name = name;
            this.ParameterType = parameterType;
        }
    }
}
