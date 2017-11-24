using System;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class CallConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(MethodBase method, DecodeContext decodeContext)
        {
            var parameters = method.GetSafeParameters();
            var pairParameters = parameters
                .Reverse()
                .Select(parameter => new Utilities.RightExpressionGivenParameter(
                    parameter.ParameterType, decodeContext.PopStack()))
                .Reverse()
                .ToArray();

            var methodName = Utilities.GetFullMemberName(method);
            var functionName = methodName.ManglingSymbolName();

            var mi = method as MethodInfo;
            var targetType = mi?.ReturnType ?? typeof(void);
            if (targetType != typeof(void))
            {
                if ((targetType == typeof(byte))
                    || (targetType == typeof(sbyte))
                    || (targetType == typeof(short))
                    || (targetType == typeof(ushort)))
                {
                    targetType = typeof(int);
                }

                var resultName = decodeContext.PushStack(targetType);
                var ilByteIndex = decodeContext.ILByteIndex;

                return lookupper =>
                {
                    var parameterString =
                        Utilities.GetGivenParameterDeclaration(pairParameters, lookupper, ilByteIndex);
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
            else
            {
                Debug.Assert(method is ConstructorInfo);

                var ilByteIndex = decodeContext.ILByteIndex;

                return lookupper =>
                {
                    var parameterString =
                        Utilities.GetGivenParameterDeclaration(pairParameters, lookupper, ilByteIndex);
                    return new[]
                    {
                        string.Format(
                            "{0}({1})",
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

        public override Func<IExtractContext, string[]> Apply(int methodToken, DecodeContext decodeContext)
        {
            try
            {
                var method = decodeContext.ResolveMethod(methodToken);

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

        public override Func<IExtractContext, string[]> Apply(int methodToken, DecodeContext decodeContext)
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
