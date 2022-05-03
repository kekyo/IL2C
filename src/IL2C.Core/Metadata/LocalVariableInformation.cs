////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C.Metadata
{
    public interface ILocalVariableInformation
        : IVariableInformation
    {
        string ExtractSymbolName(string prefix = null);
    }

    internal sealed class LocalVariableInformation
        : VariableInformation, ILocalVariableInformation
    {
        public LocalVariableInformation(
            IMethodInformation declaredMethod,
            int index,
            string symbolName,
            ITypeInformation targetType,
            object hintInformation = null)
            : base(declaredMethod, index, symbolName, targetType, hintInformation)
        {
        }

        public string ExtractSymbolName(string prefix = null) =>
            string.IsNullOrWhiteSpace(prefix) ?
                this.UnsafeCLanguageSymbolName :
                (prefix + this.UnsafeCLanguageSymbolName);
    }
}
