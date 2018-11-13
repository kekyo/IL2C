using System.Linq;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IParameterInformation
        : IVariableInformation
    {
        string ParameterName { get; }
        bool IsParamArray { get; }
    }

    internal sealed class ParameterInformation
        : VariableInformation, IParameterInformation
    {
        private static readonly CustomAttribute[] empty = new CustomAttribute[0];

        private readonly CustomAttribute[] customAttributes;

        public ParameterInformation(
            IMethodInformation declaredMethod,
            int index,
            string symbolName, 
            ITypeInformation targetType,
            CustomAttribute[] customAttributes,
            object hintInformation = null)
            : base(declaredMethod, index, symbolName, targetType, hintInformation)
        {
            this.customAttributes = customAttributes;
        }

        public string ParameterName => symbolName;

        public bool IsParamArray =>
            customAttributes.Any(attribute => attribute.AttributeType.FullName == "System.ParamArrayAttribute");
    }
}
