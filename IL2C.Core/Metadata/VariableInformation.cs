using System.Linq;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public struct VariableInformation
        : IOperandPrintable
    {
        private static readonly CustomAttribute[] empty = new CustomAttribute[0];
        private readonly CustomAttribute[] customAttributes;

        internal VariableInformation(
            IMethodInformation declaredMethod,
            int index,
            string symbolName,
            ITypeInformation targetType)
            : this(declaredMethod, index, symbolName, targetType, empty)
        {
        }

        internal VariableInformation(
            IMethodInformation declaredMethod,
            int index,
            string symbolName, 
            ITypeInformation targetType,
            CustomAttribute[] customAttributes)
        {
            this.Index = index;
            this.SymbolName = symbolName;
            this.TargetType = targetType;
            this.DeclaredMethod = declaredMethod;
            this.customAttributes = customAttributes;
        }

        public int Index { get; }
        public string SymbolName { get; }
        public ITypeInformation TargetType { get; }
        public IMethodInformation DeclaredMethod { get; }

        public bool IsParamArray =>
            customAttributes.Any(attribute => attribute.AttributeType.FullName == "System.ParamArrayAttribute");

        public bool Equals(VariableInformation rhs)
        {
            return this.Index.Equals(rhs.Index) &&
                this.SymbolName.Equals(rhs.SymbolName) &&
                this.TargetType.Equals(rhs.TargetType) &&
                this.DeclaredMethod.Equals(rhs.DeclaredMethod);
        }

        public override bool Equals(object rhs)
        {
            return this.Equals((VariableInformation)rhs);
        }

        public override int GetHashCode()
        {
            return this.Index.GetHashCode() ^
                this.SymbolName.GetHashCode() ^
                this.TargetType.GetHashCode() ^
                this.DeclaredMethod.GetHashCode();
        }

        public override string ToString() =>
            string.Format("{0}: {1}", this.TargetType.FriendlyName, this.SymbolName);

        string IOperandPrintable.PrintableString => this.SymbolName;
    }
}
