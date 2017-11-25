using System;
using System.Collections.Generic;
using System.Reflection;

namespace IL2C.Translators
{
    internal interface IExtractContext
    {
        Assembly Assembly { get; }

        string GetCLanguageTypeName(Type type, TypeNameFlags flags = TypeNameFlags.Strict);
        string GetRightExpression(Type lhsType, SymbolInformation rhs);
        string GetRightExpression(Type lhsType, Type rhsType, string rhsExpression);
        IEnumerable<string> EnumerateRequiredIncludeFileNames();
        IEnumerable<string> EnumerateRequiredPrivateIncludeFileNames();
        IEnumerable<FieldInfo> ExtractStaticFields();
    }
}
