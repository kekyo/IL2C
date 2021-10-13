using IL2C.ILConverters;
using IL2C.Metadata;
using IL2C.Translators;
using Mono.Cecil.Cil;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.ILConveters
{
    internal sealed class SwitchConverter : ILConverter<Instruction[]>
    {
        public override OpCode OpCode => OpCodes.Switch;

        public override ExpressionEmitter Prepare(Instruction[] operands, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (!si.TargetType.IsInt32Type)
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack for switch: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si.TargetType.FriendlyName);

            var labels = new string[operands.Length];
            int i;

            for (i = 0; i < operands.Length; i++)
            {
                labels[i] = decodeContext.EnqueueNewPath(operands[i].Offset);
            }

            return (extractContext, _) => 
                {
                    var result = new string[labels.Length + 1];
                    result[0] = $"switch ({extractContext.GetSymbolName(si)}) {{\n    ";
                    for (int q = 0; q < labels.Length; q++)
                    {
                        var caseStr = $"case {q}: goto {labels[q]}";
                        if (q == 0) result[q] += caseStr; else result[q] = caseStr;
                    }
                    result[result.Length - 1] = "default: }";
                    return result;
                };
        }
    }
}
