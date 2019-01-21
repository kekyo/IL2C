using System;
using System.Collections.Generic;
using System.Linq;

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

        string GetExceptionNestedFrameIndexName();

        string GetRightExpression(ITypeInformation lhsType, IVariableInformation rhs);
        string GetRightExpression(ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression);

        string GetSymbolName(IVariableInformation variable);

        IReadOnlyDictionary<MemberScopes, IEnumerable<ITypeInformation>> EnumerateRegisteredTypes();
        IEnumerable<ITypeInformation> EnumerateRegisteredTypesByDeclaringType(ITypeInformation declaringType);
        IEnumerable<string> EnumerateRequiredImportIncludeFileNames();
        IEnumerable<IFieldInformation> ExtractStaticFields();
        IEnumerable<(string symbolName, string value)> ExtractConstStrings();
        IEnumerable<DeclaredValuesInformation> ExtractDeclaredValues();
    }

    internal interface IExtractContextHost
        : IExtractContext
    {
        IDisposable BeginLocalVariablePrefix(Func<ILocalVariableInformation, string> prefixGenerator);
        void SetNestedExceptionFrameIndexName(string nestedIndexName);
    }
}
