////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using IL2C.Internal;
using System;
using System.ComponentModel;

namespace IL2C.Metadata
{
    public interface IVariableInformation
        : IEquatable<IVariableInformation>
    {
        int Index { get; }
        ITypeInformation TargetType { get; }
        IMethodInformation DeclaredMethod { get; }
        object HintInformation { get; }

        string UnsafeCLanguageSymbolName { get; }
    }

    internal abstract class VariableInformation
        : IVariableInformation, IOperandPrintable
    {
        private readonly string symbolName;

        protected VariableInformation(
            IMethodInformation declaredMethod,
            int index,
            string symbolName, 
            ITypeInformation targetType,
            object hintInformation = null)
        {
            this.Index = index;
            this.symbolName = symbolName;
            this.TargetType = targetType;
            this.DeclaredMethod = declaredMethod;
            this.HintInformation = hintInformation;
        }

        public int Index { get; }
        public ITypeInformation TargetType { get; }
        public IMethodInformation DeclaredMethod { get; }
        public object HintInformation { get; }

        public string UnsafeCLanguageSymbolName =>
            SymbolManipulator.GetMangledName(symbolName);

        public bool Equals(IVariableInformation rhs)
        {
            if (rhs == null)
            {
                return false;
            }

            return this.Index.Equals(rhs.Index) &&
                symbolName.Equals(rhs.UnsafeCLanguageSymbolName) &&
                this.TargetType.Equals(rhs.TargetType) &&
                this.DeclaredMethod.Equals(rhs.DeclaredMethod);
        }

        public override bool Equals(object rhs)
        {
            return this.Equals(rhs as IVariableInformation);
        }

        public override int GetHashCode()
        {
            return
                this.Index.GetHashCode() ^
                symbolName.GetHashCode() ^
                this.TargetType.GetHashCode() ^
                this.DeclaredMethod.GetHashCode();
        }

        public override string ToString() =>
            string.Format("{0}: {1}", this.TargetType.FriendlyName, symbolName);

        string IOperandPrintable.PrintableString => symbolName;
    }
}
