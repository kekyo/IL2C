using System;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class CallConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Call;

        public override string Apply(int methodToken, DecodeContext decodeContext)
        {
            try
            {
                var method = (MethodInfo)decodeContext.TranslateContext.ResolveMethod(methodToken);

                var parameters = method.GetParameters();

                var pairParameters = parameters
                    .Reverse()
                    .Select(parameter => new { parameter, si = decodeContext.PopStack() })
                    .Reverse()
                    .ToArray();

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

                return string.Format(
                    "{0} = {1}({2})",
                    resultName,
                    functionName,
                    string.Join(", ", pairParameters.Select(entry =>
                    {
                        var rightExpression = decodeContext.TranslateContext.GetRightExpression(
                            entry.parameter.ParameterType, entry.si);
                        if (rightExpression == null)
                        {
                            throw new InvalidProgramSequenceException(
                                "Invalid parameter type: ILByteIndex={0}, StackType={1}, ParameterType={2}",
                                decodeContext.ILByteIndex,
                                entry.si.TargetType.FullName,
                                entry.parameter.ParameterType.FullName);
                        }
                        return rightExpression;
                    })));
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
