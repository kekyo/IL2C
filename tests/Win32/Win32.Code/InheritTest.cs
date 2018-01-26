using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Win32.Code
{
    public class InheritTestTargetBase1
    {
        public int Value2;
        public ClassTypeTestTarget OR2;

        public InheritTestTargetBase1()
        {
        }

        public InheritTestTargetBase1(int value)
        {
            this.Value2 = value;
        }

        public int Calc(int a)
        {
            return this.Value2 + a;
        }

        public virtual int Calc(int a, int b)
        {
            return this.Value2 + a + b;
        }
    }

    public class InheritTypeTest
    {
        public static int Test1()
        {
            var hoge3 = new InheritTestTargetBase1();
            hoge3.Value2 = 123;

            return hoge3.Calc(1);
        }

        public static int Test2()
        {
            var hoge3 = new InheritTestTargetBase1();
            hoge3.Value2 = 123;

            return hoge3.Calc(1, 2);
        }
    }
}
