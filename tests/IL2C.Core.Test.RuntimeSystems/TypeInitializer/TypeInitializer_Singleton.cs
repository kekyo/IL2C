using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.RuntimeSystems
{
    public class TypeInitializer_Singleton_Class
    {
        public int Value;

        public static TypeInitializer_Singleton_Class Default;

        static TypeInitializer_Singleton_Class()
        {
            Default = new TypeInitializer_Singleton_Class();
            Default.Value = 20;
        }
    }

    public struct TypeInitializer_Singleton_Struct
    {
        public int Value;

        public static TypeInitializer_Singleton_Struct Default;

        static TypeInitializer_Singleton_Struct()
        {
            Default = new TypeInitializer_Singleton_Struct();
            Default.Value = 10;
        }
    }

    [TestCase((int)20, "Default_Class_Value", IncludeTypes = new[] { typeof(TypeInitializer_Singleton_Class) })]
    [TestCase((int)10, "Default_Struct_Value", IncludeTypes = new[] { typeof(TypeInitializer_Singleton_Struct) })]
    public sealed class TypeInitializer_Singleton
    {
        public static int Default_Class_Value()
        {
            return TypeInitializer_Singleton_Class.Default.Value;
        }

        public static int Default_Struct_Value()
        {
            return TypeInitializer_Singleton_Struct.Default.Value;
        }
    }
}
