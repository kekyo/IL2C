using System;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Translators;
using Mono.Cecil;

namespace IL2C.ILConveters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        private static readonly string[] empty = new string[0];
        private static readonly Func<IExtractContext, string[]> emptyFunc = _ => empty;

        public override OpCode OpCode => OpCodes.Nop;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return emptyFunc;
        }
    }

    internal sealed class RetConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ret;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            if (decodeContext.ReturnType.MemberEquals(CecilHelper.VoidType))
            {
                return _ => new [] { "return" };
            }

            var si = decodeContext.PopStack();
            var returnType = decodeContext.ReturnType;

            decodeContext.prepareContext.RegisterType(returnType);

            var offset = decodeContext.Current.Offset;

            return lookupper =>
            {
                var rightExpression = lookupper.GetRightExpression(returnType, si);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid return operation: Offset={0}, StackType={1}, ReturnType={2}",
                        offset,
                        si.TargetType.FullName,
                        returnType.FullName);
                }

                return new[] { string.Format(
                    "return {0}",
                    rightExpression) };
            };
        }

        internal sealed class InitobjConverter : InlineTypeConverter
        {
            public override OpCode OpCode => OpCodes.Initobj;

            public override Func<IExtractContext, string[]> Apply(
                TypeDefinition type, DecodeContext decodeContext)
            {
                var si = decodeContext.PopStack();
                if (si.TargetType.IsByReference == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid type at stack: Offset={0}, TokenType={1}, StackType={2}",
                        decodeContext.Current.Offset,
                        type.FullName,
                        si.TargetType.FullName);
                }

                decodeContext.prepareContext.RegisterIncludeFile("string.h");

                return lookupper =>
                {
                    var typeName = lookupper.GetCLanguageTypeName(type);

                    return new[] { string.Format(
                        "memset({0}, 0x00, sizeof({1}))",
                        si.SymbolName,
                        typeName) };
                };
            }
        }

        internal sealed class NewobjConverter : InlineMethodConverter
        {
            public override OpCode OpCode => OpCodes.Newobj;

            public override Func<IExtractContext, string[]> Apply(
                MethodDefinition method, DecodeContext decodeContext)
            {
                if (method.IsConstructor == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid new object constructor: Offset={0}, Method={1}",
                        decodeContext.Current.Offset,
                        method.GetFullMemberName());
                }

                var type = method.DeclaringType;

                if (type.IsClass == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid new object type: Offset={0}, Method={1}",
                        decodeContext.Current.Offset,
                        method.GetFullMemberName());
                }

                var pairParameters = method.Parameters
                    .Reverse()
                    .Select(parameter => new Utilities.RightExpressionGivenParameter(
                        parameter.ParameterType, decodeContext.PopStack()))
                    .Reverse()
                    .ToList();

                var thisSymbolName = decodeContext.PushStack(type);

                // Insert this reference.
                pairParameters.Insert(0,
                    new Utilities.RightExpressionGivenParameter(
                        type, new SymbolInformation(thisSymbolName, type)));

                var offset = decodeContext.Current.Offset;

                return lookupper =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters.ToArray(), lookupper, offset);

                    var dereferencedTypeName = lookupper.GetCLanguageTypeName(
                        type, TypeNameFlags.Dereferenced);

                    return new[] { string.Format(
                        "__{0}_NEW__(&{1})",
                        dereferencedTypeName,
                        parameterString) };
                };
            }
        }
    }
}
