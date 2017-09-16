using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal abstract class ILConverter
    {
        protected ILConverter()
        {
        }

        public abstract OpCode OpCode { get; }

        public abstract string Apply(object operand, Stack<string> stack);
    }

    internal sealed class NopConverter : ILConverter
    {
        public NopConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Nop;

        public override string Apply(object operand, Stack<string> stack)
        {
            return null;
        }
    }

    internal sealed class Ldc_i4_1Converter : ILConverter
    {
        public Ldc_i4_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldc_I4_1;

        public override string Apply(object operand, Stack<string> stack)
        {
            stack.Push("1");
            return null;
        }
    }

    internal sealed class Ldc_i4_2Converter : ILConverter
    {
        public Ldc_i4_2Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldc_I4_2;

        public override string Apply(object operand, Stack<string> stack)
        {
            stack.Push("2");
            return null;
        }
    }

    internal sealed class Stloc_0Converter : ILConverter
    {
        public Stloc_0Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_0;

        public override string Apply(object operand, Stack<string> stack)
        {
            var data0 = stack.Pop();
            return string.Format("local0 = {0};", data0);
        }
    }

    internal sealed class Stloc_1Converter : ILConverter
    {
        public Stloc_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_1;

        public override string Apply(object operand, Stack<string> stack)
        {
            var data0 = stack.Pop();
            return string.Format("local1 = {0};", data0);
        }
    }

    internal sealed class Stloc_2Converter : ILConverter
    {
        public Stloc_2Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_2;

        public override string Apply(object operand, Stack<string> stack)
        {
            var data0 = stack.Pop();
            return string.Format("local2 = {0};", data0);
        }
    }

    internal sealed class Stloc_3Converter : ILConverter
    {
        public Stloc_3Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_3;

        public override string Apply(object operand, Stack<string> stack)
        {
            var data0 = stack.Pop();
            return string.Format("local3 = {0};", data0);
        }
    }

    internal sealed class Ldloc_0Converter : ILConverter
    {
        public Ldloc_0Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_0;

        public override string Apply(object operand, Stack<string> stack)
        {
            stack.Push("local0");
            return null;
        }
    }

    internal sealed class Ldloc_1Converter : ILConverter
    {
        public Ldloc_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_1;

        public override string Apply(object operand, Stack<string> stack)
        {
            stack.Push("local1");
            return null;
        }
    }

    internal sealed class Ldloc_2Converter : ILConverter
    {
        public Ldloc_2Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_2;

        public override string Apply(object operand, Stack<string> stack)
        {
            stack.Push("local2");
            return null;
        }
    }

    internal sealed class Ldloc_3Converter : ILConverter
    {
        public Ldloc_3Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_3;

        public override string Apply(object operand, Stack<string> stack)
        {
            stack.Push("local3");
            return null;
        }
    }

    internal sealed class AddConverter : ILConverter
    {
        public AddConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Add;

        public override string Apply(object operand, Stack<string> stack)
        {
            var data0 = stack.Pop();
            var data1 = stack.Pop();
            var add = string.Format("{0} + {1}", data0, data1);
            stack.Push(add);
            return null;
        }
    }

    internal sealed class Br_sConverter : ILConverter
    {
        public Br_sConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Br_S;

        public override string Apply(object operand, Stack<string> stack)
        {
            Debug.Assert(((byte)0).Equals(operand));
            return null;
        }
    }

    internal sealed class RetConverter : ILConverter
    {
        public RetConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Ret;

        public override string Apply(object operand, Stack<string> stack)
        {
            var data0 = stack.Pop();
            return string.Format("return {0};", data0);
        }
    }
}
