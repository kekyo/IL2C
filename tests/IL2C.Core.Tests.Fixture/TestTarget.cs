using System.Runtime.CompilerServices;

namespace IL2C
{
    public static class TestTarget
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Ldarg_0(int num);

        public static byte ByteMainBody()
        {
            var a = (byte) 1;
            var b = (byte) 2;
            var c = (byte) (a + b);
            return c;
        }

        public static sbyte SByteMainBody()
        {
            var a = (sbyte) 1;
            var b = (sbyte) 2;
            var c = (sbyte) (a + b);
            return c;
        }

        public static sbyte SByteWithMinusMainBody()
        {
            var a = (sbyte) -2;
            var b = (sbyte) 5;
            var c = (sbyte) (a + b);
            return c;
        }

        public static short Int16MainBody()
        {
            var a = (short) 1;
            var b = (short) 2;
            var c = (short) (a + b);
            return c;
        }

        public static short Int16WithMinusMainBody()
        {
            var a = (short) -2;
            var b = (short) 5;
            var c = (short) (a + b);
            return c;
        }

        public static ushort UInt16MainBody()
        {
            var a = (ushort) 1;
            var b = (ushort) 2;
            var c = (ushort) (a + b);
            return c;
        }

        private const ushort maxValueMinus5 = ushort.MaxValue - 5;

        public static ushort UInt16WithMaxValueMainBody()
        {
            var a = (ushort) maxValueMinus5;
            var b = (ushort) 2;
            var c = (ushort) (a + b);
            return c;
        }

        public static int Int32MainBody()
        {
            var a = 1;
            var b = 2;
            var c = a + b;
            return c;
        }

        public static int Int32LargeValueMainBody()
        {
            var a = 12345678;
            var b = 23456789;
            var c = a + b;
            return c;
        }

        public static int Int32WithArgumentsMainBody(int a, int b)
        {
            var c = a + b;
            return c;
        }

        public static long Int64MainBody()
        {
            var a = 1L;
            var b = 2L;
            var c = a + b;
            return c;
        }

        public static long Int64LargeValueMainBody()
        {
            var a = 1234567890123456L;
            var b = 2345678901234567L;
            var c = a + b;
            return c;
        }

        public static int ConditionalBranchMainBody(int a)
        {
            if (a > 0)
            {
                return a + 1;
            }
            else
            {
                return a + 2;
            }
        }

        public struct CallStaticMethodTestType
        {
            public static int Test(int a, short b)
            {
                return a + b;
            }
        }

        public static int CallTestMethod()
        {
            // call inst?
            return CallStaticMethodTestType.Test(1, 2);
        }

        public struct CallStaticMethodWithFieldReferencedTestType
        {
            public static int Field0 = 1;
            public static long Field1 = 2;
        }

        public static long AccessStaticFieldTestMethod()
        {
            return CallStaticMethodWithFieldReferencedTestType.Field0 +
                   CallStaticMethodWithFieldReferencedTestType.Field1;
        }

        public struct AccessValueTypeFieldTestType
        {
            public int Value1;
        }

        public static void AccessValueTypeFieldMethod()
        {
            var instance = new AccessValueTypeFieldTestType();
            instance.Value1 = 123;
        }
    }
}
