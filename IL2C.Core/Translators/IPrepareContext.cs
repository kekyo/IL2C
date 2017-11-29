using Mono.Cecil;

namespace IL2C.Translators
{
    internal interface IPrepareContext
    {
        void RegisterIncludeFile(string includeFileName);
        void RegisterPrivateIncludeFile(string includeFileName);
        void RegisterType(TypeReference type);
        void RegisterStaticField(FieldReference staticField);
    }
}
