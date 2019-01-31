using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public sealed class Ldsfld_Field
    {
        public static readonly bool TrueValue = true;
    }

    [TestCase(true, "True", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(false, "False", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(byte.MaxValue, "Byte", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(short.MaxValue, "Int16", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(int.MaxValue, "Int32", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(long.MaxValue, "Int64", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(sbyte.MaxValue, "SByte", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(ushort.MaxValue, "UInt16", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(uint.MaxValue, "UInt32", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(ulong.MaxValue, "UInt64", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(int.MaxValue, "IntPtr", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(uint.MaxValue, "UIntPtr", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(3.14159274f, "Single", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase(3.1415926535897931, "Double", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase('A', "Char", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    //[TestCase("ABC", "String", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    public sealed class Ldsfld
    {
        public static bool Hoge()
        {
            return Ldsfld_Field.TrueValue;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool True();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern bool False();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern byte Byte();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern short Int16();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern int Int32();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern long Int64();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern sbyte SByte();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern ushort UInt16();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern uint UInt32();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern ulong UInt64();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern IntPtr IntPtr();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern UIntPtr UIntPtr();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern float Single();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern double Double();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern char Char();

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern string String();
    }
}
