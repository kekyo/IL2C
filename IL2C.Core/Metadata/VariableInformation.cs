using System;

namespace IL2C.Metadata
{
    public interface IVariableInformation
    {
        int Index { get; }
        string SymbolName { get; }
        ITypeInformation TargetType { get; }
        IMethodInformation DeclaredMethod { get; }
    }

    internal sealed class VariableInformation
        : IVariableInformation
        , IOperandPrintable
    {
        public VariableInformation(
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

        public bool Equals(IVariableInformation rhs)
        {
            return this.Index.Equals(rhs.Index)
                && this.SymbolName.Equals(rhs.SymbolName)
                && this.TargetType.Equals(rhs.TargetType);
        }

        public override bool Equals(object rhs)
        {
            return this.Equals(rhs as IVariableInformation);
        }

        public override int GetHashCode()
        {
            return this.Index.GetHashCode()
                ^ this.SymbolName.GetHashCode()
                ^ this.TargetType.GetHashCode();
        }

        public override string ToString()
        {
            return string.Format("{0}: {1}", this.SymbolName, this.TargetType.UniqueName);
        }

        string IOperandPrintable.PrintableString => this.SymbolName;
    }
}
