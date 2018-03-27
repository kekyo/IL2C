using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    internal interface IExtractContext
    {
        IMetadataContext MetadataContext { get; }
        IAssemblyInformation Assembly { get; }

        string GetRightExpression(ITypeInformation lhsType, VariableInformation rhs);
        string GetRightExpression(ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression);
        IEnumerable<string> EnumerateRequiredIncludeFileNames();
        IEnumerable<string> EnumerateRequiredPrivateIncludeFileNames();
        IEnumerable<IFieldInformation> ExtractStaticFields();
        IEnumerable<KeyValuePair<string, string>> ExtractConstStrings();
    }
}
