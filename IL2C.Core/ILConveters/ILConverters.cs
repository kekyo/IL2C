using System;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        private static readonly string[] empty = new string[0];

        public override OpCode OpCode => OpCodes.Nop;

        public override string[] Apply(DecodeContext decodeContext)
        {
            return empty;
        }
    }

    internal sealed class RetConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ret;

        public override bool IsEndOfPath => true;

        public override string[] Apply(DecodeContext decodeContext)
        {
            if (decodeContext.ReturnType == typeof(void))
            {
                return new [] { "return" };
            }

            var si = decodeContext.PopStack();
            var returnType = decodeContext.ReturnType;

            var rightExpression = decodeContext.TranslateContext.GetRightExpression(returnType, si);
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
        }

        internal sealed class InitobjConverter : InlineTypeConverter
        {
            public override OpCode OpCode => OpCodes.Initobj;

            public override string[] Apply(int typeToken, DecodeContext decodeContext)
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

                    decodeContext.TranslateContext.RegisterIncludeFile("string.h");

                    return new[] { string.Format(
                        "memset({0}, 0x00, sizeof({1}))",
                        si.SymbolName,
                        decodeContext.TranslateContext.GetCLanguageTypeName(type)) };
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

            public override string[] Apply(int constructorToken, DecodeContext decodeContext)
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

                    decodeContext.TranslateContext.RegisterIncludeFile("stdlib.h");
                    decodeContext.TranslateContext.RegisterIncludeFile("string.h");

                    // Hoge* p = (Hoge)malloc(sizeof(Hoge));
                    // memset(p, 0, sizeof(Hoge));
                    // Hoge__ctor(p);

                    var constructorName = Utilities.GetFullMemberName(constructor)
                        .ManglingSymbolName();
                    var typeName = decodeContext.TranslateContext.GetCLanguageTypeName(
                        type);
                    var dereferencedTypeName = decodeContext.TranslateContext.GetCLanguageTypeName(
                        type, true);
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters.ToArray(), decodeContext);

                    return new[]
                    {
                        string.Format(
                            "{0} = ({1})malloc(sizeof({2}))",
                            thisSymbolName,
                            typeName,
                            dereferencedTypeName),
                        string.Format(
                            "memset({0}, 0x00, sizeof({1}))",
                            thisSymbolName,
                            dereferencedTypeName),
                        string.Format(
                            "{0}({1})",
                            constructorName,
                            parameterString)
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
