using System;

namespace IL2C.Metadata
{
    public struct VariableInformation
        : IOperandPrintable
    {
        public readonly int Index;
        public readonly string SymbolName;
        public readonly ITypeInformation TargetType;

        internal VariableInformation(int index, string symbolName, ITypeInformation targetType)
        {
            this.Index = index;
            this.SymbolName = symbolName;
            this.TargetType = targetType;
        }

        public bool Equals(VariableInformation rhs)
        {
            return this.Index.Equals(rhs.Index)
                && this.SymbolName.Equals(rhs.SymbolName)
                && this.TargetType.Equals(rhs.TargetType);
        }

        public override bool Equals(object rhs)
        {
            if (rhs is VariableInformation)
            {
                return this.Equals((VariableInformation)rhs);
            }
            else
            {
                return false;
            }
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
