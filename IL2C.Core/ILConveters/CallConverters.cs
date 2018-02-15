using System;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class CallConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            MethodReference method, DecodeContext decodeContext)
        {
            var parameters = method.GetSafeParameters();
            var pairParameters = parameters
                .Reverse()
                .Select(parameter => new Utilities.RightExpressionGivenParameter(
                    parameter.ParameterType, decodeContext.PopStack()))
                .Reverse()
                .ToArray();

            var methodName = method.GetFullMemberName(MethodNameTypes.Index);
            var functionName = methodName.ManglingSymbolName();
            var offset = decodeContext.Current.Offset;

            // System.Object's constructor calls ignored.
            var md = method.Resolve();
            if (md.IsConstructor && md.DeclaringType.IsObjectType())
            {
                return _ => new string[0];
            }

            if (method.ReturnType.IsVoidType())
            {
                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters, extractContext, offset);
                    return new[]
                    {
                        string.Format(
                            "{0}({1})",
                            functionName,
                            parameterString)
                    };
                };
            }
            else
            {
                var targetType = method.ReturnType.GetStackableType();
                var resultName = decodeContext.PushStack(targetType);

                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters, extractContext, offset);
                    return new[]
                    {
                        string.Format(
                            "{0} = {1}({2})",
                            resultName,
                            functionName,
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
            MethodReference method, DecodeContext decodeContext)
        {
            return CallConverterUtilities.Apply(method, decodeContext);
        }
    }

    internal sealed class CallvirtConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Callvirt;

        public override Func<IExtractContext, string[]> Apply(
            MethodReference method, DecodeContext decodeContext)
        {
            var md = method.Resolve();

            if (md.IsStatic)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token (static): Offset={0}, Method={1}",
                    decodeContext.Current.Offset,
                    md.GetFullMemberName());
            }

            // TODO: Support virtual method

            return CallConverterUtilities.Apply(md, decodeContext);
        }
    }
}
