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
            if (decodeContext.ReturnType.IsVoidType())
            {
                return _ => new [] { "return" };
            }

            var si = decodeContext.PopStack();
            var returnType = decodeContext.ReturnType;

            decodeContext.prepareContext.RegisterType(returnType);

            var offset = decodeContext.Current.Offset;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(returnType, si);
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
                TypeReference type, DecodeContext decodeContext)
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

                return extractContext =>
                {
                    var typeName = extractContext.GetCLanguageTypeName(type);

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
                MethodReference method, DecodeContext decodeContext)
            {
                var md = method.Resolve();
                if (!md.IsConstructor)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid new object constructor: Offset={0}, Method={1}",
                        decodeContext.Current.Offset,
                        md.GetFullMemberName());
                }

                var type = md.DeclaringType;
                if (type.IsValueType)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid new object type: Offset={0}, Method={1}",
                        decodeContext.Current.Offset,
                        md.GetFullMemberName());
                }

                var pairParameters = md.Parameters
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

                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters.ToArray(), extractContext, offset);

                    var dereferencedTypeName = extractContext.GetCLanguageTypeName(
                        type, TypeNameFlags.Dereferenced);

                    return new[] { string.Format(
                        "__new__(&{0}, {1})({2})",
                        thisSymbolName,
                        dereferencedTypeName,
                        parameterString) };
                };
            }
        }
    }
}
