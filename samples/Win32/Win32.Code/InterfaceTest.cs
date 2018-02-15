using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Win32.Code
{
    public interface InterfaceTestTarget
    {
        int Calc(int a, int b);
    }

    public class InterfaceTestTargetClass : InterfaceTestTarget
    {
        public int Value2;
        public ClassTypeTestTarget OR2;

        public InterfaceTestTargetClass()
        {
        }

        public int Calc(int a, int b)
        {
            return a + b + Value2;
        }
    }

    public class InterfaceTypeTest
    {
        public static int Test1()
        {
            var hoge = new InterfaceTestTargetClass();
            hoge.Value2 = 123;

            return hoge.Calc(1, 2);
        }

        public static int Test2()
        {
            var hoge = new InterfaceTestTargetClass();
            hoge.Value2 = 123;

            InterfaceTestTarget hoge2 = hoge;

            return hoge2.Calc(1, 2);
        }
    }
}
