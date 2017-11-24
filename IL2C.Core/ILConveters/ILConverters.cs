using System;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using IL2C.Translators;

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
            if (decodeContext.ReturnType == typeof(void))
            {
                return _ => new [] { "return" };
            }

            var si = decodeContext.PopStack();
            var returnType = decodeContext.ReturnType;

            decodeContext.prepareContext.RegisterType(returnType);

            return lookupper =>
            {
                var rightExpression = lookupper.GetRightExpression(returnType, si);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid return operation: ILByteIndex={0}, StackType={1}, ReturnType={2}",
                        decodeContext.ILByteIndex,
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

            public override Func<IExtractContext, string[]> Apply(int typeToken, DecodeContext decodeContext)
            {
                try
                {
                    var type = decodeContext.ResolveType(typeToken);

                    var si = decodeContext.PopStack();
                    if (si.TargetType.IsByRef == false)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid type at stack: ILByteIndex={0}, TokenType={1}, StackType={2}",
                            decodeContext.ILByteIndex,
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
                catch (ArgumentException)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid type token: ILByteIndex={0}, Token={1:x2}",
                        decodeContext.ILByteIndex,
                        typeToken);
                }
            }
        }

        internal sealed class NewobjConverter : InlineMethodConverter
        {
            public override OpCode OpCode => OpCodes.Newobj;

            public override Func<IExtractContext, string[]> Apply(int constructorToken, DecodeContext decodeContext)
            {
                try
                {
                    var constructor = (ConstructorInfo)decodeContext.ResolveMethod(
                        constructorToken);
                    var type = constructor.DeclaringType;

                    if (type.IsClass == false)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid new object type: ILByteIndex={0}, Token={1:x2}",
                            decodeContext.ILByteIndex,
                            constructorToken);
                    }

                    var parameters = constructor.GetParameters();
                    var pairParameters = parameters
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

                    var ilByteIndex = decodeContext.ILByteIndex;

                    return lookupper =>
                    {
                        var parameterString = Utilities.GetGivenParameterDeclaration(
                            pairParameters.ToArray(), lookupper, ilByteIndex);

                        var dereferencedTypeName = lookupper.GetCLanguageTypeName(
                            type, TypeNameFlags.Dereferenced);

                        return new[] { string.Format(
                            "__{0}_NEW__(&{1})",
                            dereferencedTypeName,
                            parameterString) };
                    };
                }
                catch (ArgumentException)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid contructor token: ILByteIndex={0}, Token={1:x2}",
                        decodeContext.ILByteIndex,
                        constructorToken);
                }
            }
        }
    }
}
