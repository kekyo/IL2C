using System;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class CallConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            IMethodInformation method, DecodeContext decodeContext)
        {
            var pairParameters = method.Parameters
                .Reverse()
                .Select(parameter => new Utilities.RightExpressionGivenParameter(
                    parameter.TargetType, decodeContext.PopStack()))
                .Reverse()
                .ToArray();

            var codeInformation = decodeContext.CurrentCode;

            // System.Object's constructor calls ignored.
            if (method.IsConstructor && method.DeclaringType.IsObjectType)
            {
                return _ => new string[0];
            }

            if (method.ReturnType.IsVoidType)
            {
                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters, extractContext, codeInformation);
                    return new[]
                    {
                        string.Format(
                            "{0}({1})",
                            method.CLanguageFunctionName,
                            parameterString)
                    };
                };
            }
            else
            {
                var resultName = decodeContext.PushStack(
                    method.ReturnType.StackableType);

                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters, extractContext, codeInformation);
                    return new[]
                    {
                        string.Format(
                            "{0} = {1}({2})",
                            resultName,
                            method.CLanguageFunctionName,
                            parameterString)
                    };
                };
            }
        }
    }

    internal sealed class CallConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Call;

        public override Func<IExtractContext, string[]> Apply(
            IMethodInformation method, DecodeContext decodeContext)
        {
            return CallConverterUtilities.Apply(method, decodeContext);
        }
    }

    internal sealed class CallvirtConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Callvirt;

        public override Func<IExtractContext, string[]> Apply(
            IMethodInformation method, DecodeContext decodeContext)
        {
            if (method.IsStatic)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token (static): Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    method.FriendlyName);
            }

            // TODO: Support virtual method

            return CallConverterUtilities.Apply(method, decodeContext);
        }
    }
}
