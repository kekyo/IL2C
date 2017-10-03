using System;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

using IL2C;

namespace IL2C.ILConveters
{
    internal sealed class CallConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Call;

        public override string Apply(int methodToken, DecodeContext context)
        {
            try
            {
                var method = (MethodInfo)context.Module.ResolveMethod(methodToken);

                var parameters = method.GetParameters();

                var pairParameters = parameters
                    .Reverse()
                    .Select(parameter => new { parameter, si = context.PopStack() })
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

                var resultName = context.PushStack(targetType);

                var methodName = Utilities.GetFullMethodName(method);
                var functionName = methodName.Replace(".", "_");

                return string.Format(
                    "{0} = {1}({2})",
                    resultName,
                    functionName,
                    string.Join(", ", pairParameters.Select(entry =>
                    {
                        var rightExpression = Utilities.GetRightExpression(
                            entry.parameter.ParameterType, entry.si);
                        if (rightExpression == null)
                        {
                            throw new InvalidProgramSequenceException(
                                "Invalid parameter type: ILByteIndex={0}, StackType={1}, ParameterType={2}",
                                context.ILByteIndex,
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
                    context.ILByteIndex,
                    methodToken);
            }
        }
    }
}
