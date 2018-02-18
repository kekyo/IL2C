using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Win32.Code
{
    public interface IInterfaceTestTarget
    {
        int Calc(int a, int b);
    }

    public interface IInterfaceTestTarget2
    {
        int Calc2(int a, int b);
    }

    public class InterfaceTestTargetClass : IInterfaceTestTarget, IInterfaceTestTarget2
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

        public int Calc2(int a, int b)
        {
            return a - b + Value2;
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

            IInterfaceTestTarget hoge1 = hoge;

            return hoge1.Calc(1, 2);
        }

        public static int Test3()
        {
            var hoge = new InterfaceTestTargetClass();
            hoge.Value2 = 123;

            IInterfaceTestTarget hoge1 = hoge;
            IInterfaceTestTarget2 hoge2 = (IInterfaceTestTarget2)hoge1;

            return hoge2.Calc2(1, 2);
        }
    }
}
