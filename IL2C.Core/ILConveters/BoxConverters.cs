using System;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class BoxConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Box;

        public override Func<IExtractContext, string[]> Apply(
            TypeReference operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (!si.TargetType.IsValueType || !si.TargetType.MemberEquals(operand))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Offset={0}, TokenType={1}, StackType={2}",
                    decodeContext.Current.Offset,
                    operand.FullName,
                    si.TargetType.FullName);
            }

            var symbolName = decodeContext.PushStack(
                decodeContext.Module.GetSafeObjectType());

            return _ =>
            {
                return new[] { string.Format(
                    "{0} = __box__(&{1}, __typeof__({2}))",
                    symbolName,
                    si.SymbolName,
                    si.TargetType.GetFullMemberName().ManglingSymbolName()) };
            };
        }
    }

    internal sealed class Unbox_AnyConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Unbox_Any;

        public override Func<IExtractContext, string[]> Apply(
            TypeReference operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (!si.TargetType.IsObjectType())
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Offset={0}, TokenType={1}, StackType={2}",
                    decodeContext.Current.Offset,
                    operand.FullName,
                    si.TargetType.FullName);
            }

            var symbolName = decodeContext.PushStack(operand.GetStackableType());

            return extractContext =>
            {
                var typeName = extractContext.GetCLanguageTypeName(operand);

                return new[] { string.Format(
                    "{0} = *(({1}*)__unbox__({2}, __typeof__({3})))",
                    symbolName,
                    typeName,
                    si.SymbolName,
                    operand.GetFullMemberName().ManglingSymbolName()) };
            };
        }
    }
}
