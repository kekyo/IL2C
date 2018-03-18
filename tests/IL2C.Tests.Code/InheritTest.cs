using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IL2C.Tests
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

    public class InheritTestTarget2 : InheritTestTargetBase1
    {
        public InheritTestTarget2()
        {
        }

        public InheritTestTarget2(int value)
            : base(value)
        {
        }

        public new int Calc(int a)
        {
            return this.Value2 + a + 10000;
        }

        public override int Calc(int a, int b)
        {
            return this.Value2 + a + b + 10000;
        }
    }

    public class InheritTypeTest
    {
        public static int Test1()
        {
            var hoge = new InheritTestTargetBase1();
            hoge.Value2 = 123;

            return hoge.Calc(1);
        }

        public static int Test2()
        {
            var hoge = new InheritTestTargetBase1();
            hoge.Value2 = 123;

            return hoge.Calc(1, 2);
        }

        public static int Test3()
        {
            var hoge = new InheritTestTarget2();
            hoge.Value2 = 123;

            return hoge.Calc(1, 2);
        }

        public static int Test4()
        {
            InheritTestTargetBase1 hoge = new InheritTestTarget2();
            hoge.Value2 = 123;

            return hoge.Calc(1, 2);
        }

        public static int Test5()
        {
            object hoge = new InheritTestTarget2();
            InheritTestTarget2 hoge2 = (InheritTestTarget2) hoge;
            hoge2.Value2 = 123;

            return hoge2.Calc(1, 2);
        }
    }
}
