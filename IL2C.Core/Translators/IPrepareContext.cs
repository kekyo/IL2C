using Mono.Cecil;

using IL2C.Metadata;

namespace IL2C.Translators
{
    internal interface IPrepareContext
    {
        IMetadataContext MetadataContext { get; }
        IAssemblyInformation Assembly { get; }

        void RegisterIncludeFile(string includeFileName);
        void RegisterPrivateIncludeFile(string includeFileName);
        void RegisterType(ITypeInformation type);
        void RegisterStaticField(IFieldInformation staticField);
        string RegisterConstString(string operand);
    }
}
