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

        public abstract string Apply(object operand, ApplyContext context);
    }

    internal sealed class NopConverter : ILConverter
    {
        public NopConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Nop;

        public override string Apply(object operand, ApplyContext context)
        {
            return null;
        }
    }

    internal sealed class Conv_i8Converter : ILConverter
    {
        public Conv_i8Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Conv_I8;

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            if (data0 is int)
            {
                context.EvaluationStack.Push(data0 + "LL");
            }
            else
            {
                context.EvaluationStack.Push("(int64_t)" + data0);
            }
            return null;
        }
    }

    internal sealed class Ldc_i4_1Converter : ILConverter
    {
        public Ldc_i4_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldc_I4_1;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push(1);
            return null;
        }
    }

    internal sealed class Ldc_i4_2Converter : ILConverter
    {
        public Ldc_i4_2Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldc_I4_2;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push(2);
            return null;
        }
    }

    internal sealed class Ldc_i4Converter : ILConverter
    {
        public Ldc_i4Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldc_I4;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push(operand);
            return null;
        }
    }

    internal sealed class Ldc_i8Converter : ILConverter
    {
        public Ldc_i8Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldc_I8;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push(operand + "LL");
            return null;
        }
    }

    internal sealed class Stloc_0Converter : ILConverter
    {
        public Stloc_0Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_0;

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            return string.Format("local0 = {0};", data0);
        }
    }

    internal sealed class Stloc_1Converter : ILConverter
    {
        public Stloc_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_1;

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            return string.Format("local1 = {0};", data0);
        }
    }

    internal sealed class Stloc_2Converter : ILConverter
    {
        public Stloc_2Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_2;

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            return string.Format("local2 = {0};", data0);
        }
    }

    internal sealed class Stloc_3Converter : ILConverter
    {
        public Stloc_3Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Stloc_3;

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            return string.Format("local3 = {0};", data0);
        }
    }

    internal sealed class Ldloc_0Converter : ILConverter
    {
        public Ldloc_0Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_0;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push("local0");
            return null;
        }
    }

    internal sealed class Ldloc_1Converter : ILConverter
    {
        public Ldloc_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_1;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push("local1");
            return null;
        }
    }

    internal sealed class Ldloc_2Converter : ILConverter
    {
        public Ldloc_2Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_2;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push("local2");
            return null;
        }
    }

    internal sealed class Ldloc_3Converter : ILConverter
    {
        public Ldloc_3Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldloc_3;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push("local3");
            return null;
        }
    }

    internal sealed class Ldarg_0Converter : ILConverter
    {
        public Ldarg_0Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldarg_0;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push(context.Parameters[0].Name);
            return null;
        }
    }

    internal sealed class Ldarg_1Converter : ILConverter
    {
        public Ldarg_1Converter()
        {
        }

        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override string Apply(object operand, ApplyContext context)
        {
            context.EvaluationStack.Push(context.Parameters[1].Name);
            return null;
        }
    }

    internal sealed class AddConverter : ILConverter
    {
        public AddConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Add;

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            var data1 = context.EvaluationStack.Pop();
            var add = string.Format("{0} + {1}", data0, data1);
            context.EvaluationStack.Push(add);
            return null;
        }
    }

    internal sealed class Br_sConverter : ILConverter
    {
        public Br_sConverter()
        {
        }

        public override OpCode OpCode => OpCodes.Br_S;

        public override string Apply(object operand, ApplyContext context)
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

        public override string Apply(object operand, ApplyContext context)
        {
            var data0 = context.EvaluationStack.Pop();
            return string.Format("return {0};", data0);
        }
    }
}
