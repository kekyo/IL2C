using System.Collections.Generic;
using Mono.Cecil;

namespace IL2C.Translators
{
    internal interface IExtractContext
    {
        AssemblyDefinition Assembly { get; }

        string GetCLanguageTypeName(TypeReference type, TypeNameFlags flags = TypeNameFlags.Strict);
        string GetRightExpression(TypeReference lhsType, SymbolInformation rhs);
        string GetRightExpression(TypeReference lhsType, TypeReference rhsType, string rhsExpression);
        IEnumerable<string> EnumerateRequiredIncludeFileNames();
        IEnumerable<string> EnumerateRequiredPrivateIncludeFileNames();
        IEnumerable<FieldDefinition> ExtractStaticFields();
    }
}
