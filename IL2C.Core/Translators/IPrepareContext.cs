using System;
using System.Reflection;

namespace IL2C.Translators
{
    internal interface IPrepareContext
    {
        void RegisterIncludeFile(string includeFileName);
        void RegisterPrivateIncludeFile(string includeFileName);
        void RegisterType(Type type);
        void RegisterStaticField(FieldInfo staticField);
    }
}
