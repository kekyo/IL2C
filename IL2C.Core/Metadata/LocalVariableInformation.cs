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
            string.IsNullOrWhiteSpace(prefix) ? symbolName : (prefix + symbolName);
    }
}
