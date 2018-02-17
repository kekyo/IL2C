using System;

namespace IL2C.Translators
{
    internal enum TypeNameFlags
    {
        // Type name is strict printable
        Strict = 0,
        // Type name dereferenced if OR or MR
        Dereferenced = 1,
        // Type name become pointer if not OR and MR
        ForcePointer = 2,
        // Type name inserted struct prefix
        StructPrefix = 3,
        // Type name inserted struct prefix and dereferenced if OR or MR
        DereferencedWithStructPrefix = 4,
        // Type name inserted struct prefix and become pointer if not OR and MR
        ForcePointerWithStructPrefix = 5,
    }
}
