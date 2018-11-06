using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    internal struct DeclaredValuesInformation
    {
        public readonly string SymbolName;
        public readonly IFieldInformation[] DeclaredFields;
        public readonly ITypeInformation[] HintTypes;
        public readonly byte[] ResourceData;

        public DeclaredValuesInformation(
            string symbolName, IFieldInformation[] declaredFields, ITypeInformation[] hintTypes, byte[] resourceData)
        {
            this.SymbolName = symbolName;
            this.DeclaredFields = declaredFields;
            this.HintTypes = hintTypes;
            this.ResourceData = resourceData;
        }
    }

    internal interface IExtractContext
    {
        IMetadataContext MetadataContext { get; }
        IAssemblyInformation Assembly { get; }

        string GetRightExpression(ITypeInformation lhsType, VariableInformation rhs);
        string GetRightExpression(ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression);
        IEnumerable<string> EnumerateRequiredIncludeFileNames();
        IEnumerable<string> EnumerateRequiredPrivateIncludeFileNames();
        IEnumerable<IFieldInformation> ExtractStaticFields();
        IEnumerable<(string symbolName, string value)> ExtractConstStrings();
        IEnumerable<DeclaredValuesInformation> ExtractDeclaredValues();
    }
}
