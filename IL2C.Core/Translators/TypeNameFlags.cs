using System;

namespace IL2C.Translators
{
    [Flags]
    internal enum TypeNameFlags
    {
        Strict = 0,
        Dereferenced = 1,
        StructPrefix = 2
    }
}
