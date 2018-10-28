using System;

namespace IL2C.Metadata
{
    public struct VariableInformation
        : IOperandPrintable
    {
        internal VariableInformation(
            IMethodInformation declaredMethod,
            int index,
            string symbolName, 
            ITypeInformation targetType)
        {
            this.Index = index;
            this.SymbolName = symbolName;
            this.TargetType = targetType;
            this.DeclaredMethod = declaredMethod;
        }

        public int Index { get; }
        public string SymbolName { get; }
        public ITypeInformation TargetType { get; }
        public IMethodInformation DeclaredMethod { get; }

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
