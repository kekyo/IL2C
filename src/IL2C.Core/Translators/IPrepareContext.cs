////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using Mono.Cecil;

using IL2C.Metadata;

namespace IL2C.Translators
{
    internal interface IPrepareContext
    {
        IMetadataContext MetadataContext { get; }
        IAssemblyInformation Assembly { get; }

        void RegisterImportIncludeFile(string includeFileName);
        void RegisterType(ITypeInformation type, MemberScopes scope);
        void RegisterType(ITypeInformation type, IMethodInformation declaringMethod);
        string RegisterConstString(string value);
        string RegisterDeclaredValues(IFieldInformation declaredField, byte[] resourceData);
        void RegisterDeclaredValuesHintType(string symbolName, ITypeInformation type);
    }
}
