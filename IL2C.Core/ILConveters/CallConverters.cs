using System;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class CallConverterUtilities
    {
        public static string[] Apply(MethodInfo method, DecodeContext decodeContext)
        {
            var parameters = method.GetSafeParameters();
            var pairParameters = parameters
                .Reverse()
                .Select(parameter => new Utilities.RightExpressionGivenParameter(
                    parameter.ParameterType, decodeContext.PopStack()))
                .Reverse()
                .ToArray();

            // TODO: Support void

            var targetType = method.ReturnType;
            if ((targetType == typeof(byte))
                || (targetType == typeof(sbyte))
                || (targetType == typeof(short))
                || (targetType == typeof(ushort)))
            {
                targetType = typeof(int);
            }

            var resultName = decodeContext.PushStack(targetType);

            var methodName = Utilities.GetFullMemberName(method);
            var functionName = methodName.ManglingSymbolName();
            var parameterString =
                Utilities.GetGivenParameterDeclaration(pairParameters, decodeContext);

            return new[] { string.Format(
                "{0} = {1}({2})",
                resultName,
                functionName,
                parameterString) };
        }
    }

    internal sealed class CallConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Call;

        public override string[] Apply(int methodToken, DecodeContext decodeContext)
        {
            try
            {
                var method = (MethodInfo)decodeContext.ResolveMethod(methodToken);

                return CallConverterUtilities.Apply(method, decodeContext);
            }
            catch (ArgumentException)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token: ILByteIndex={0}, Token={1:x2}",
                    decodeContext.ILByteIndex,
                    methodToken);
            }
        }
    }

    internal sealed class CallvirtConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Callvirt;

        public override string[] Apply(int methodToken, DecodeContext decodeContext)
        {
            try
            {
                var method = (MethodInfo)decodeContext.ResolveMethod(methodToken);
                if (method.IsStatic)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid method token (static): ILByteIndex={0}, Token={1:x2}",
                        decodeContext.ILByteIndex,
                        methodToken);
                }

                // TODO: Support virtual method

                return CallConverterUtilities.Apply(method, decodeContext);
            }
            catch (ArgumentException)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token: ILByteIndex={0}, Token={1:x2}",
                    decodeContext.ILByteIndex,
                    methodToken);
            }
        }
    }
}
