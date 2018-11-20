using System;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class CallConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            IMethodInformation method, DecodeContext decodeContext, bool isVirtualCall)
        {
            // ECMA-335 I.12.4.1.4: Virtual calling convention

            var pairParameters = method.Parameters.
                Reverse().
                Select(parameter =>
                {
                    var arg = decodeContext.PopStack();

                    // Adjust offset if it's virtual method and arg0.
                    if (isVirtualCall && (parameter.Index == 0))
                    {
                        return new
                        {
                            Type = parameter.TargetType,
                            Variable = arg,
                            Format = "il2c_adjusted_reference({0})"
                        };
                    }
                    else
                    {
                        return new
                        {
                            Type = parameter.TargetType,
                            Variable = arg,
                            Format = "{0}"
                        };
                    }
                }).
                Reverse().
                ToArray();

            var codeInformation = decodeContext.CurrentCode;

            if (method.ReturnType.IsVoidType)
            {
                // HACK: If we will call the RuntimeHelpers.InitializeArray, we can memoize array type hint.
                //   (See LdtokenConverter.)
                if (method.FriendlyName.StartsWith(
                    "System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray"))
                {
                    Debug.Assert(pairParameters.Length == 2);
                    Debug.Assert(pairParameters[1].Variable.HintInformation is string);

                    decodeContext.PrepareContext.RegisterDeclaredValuesHintType(
                        (string)pairParameters[1].Variable.HintInformation,
                        pairParameters[0].Variable.TargetType);
                }

                return extractContext =>
                {
                    var parameters = pairParameters.Select(parameter =>
                        new Utilities.RightExpressionGivenParameter(
                            parameter.Type,
                            parameter.Variable,
                            string.Format(parameter.Format, extractContext.GetSymbolName(parameter.Variable)))).
                        ToArray();

                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        parameters,
                        extractContext,
                        codeInformation);

                    if (isVirtualCall && method.IsVirtual && !method.IsSealed)
                    {
                        var overloadIndex = method.DeclaringType.CalculatedVirtualMethods.
                            First(entry => entry.method.Equals(method)).
                            overloadIndex;

                        return new[]
                        {
                            // TODO: interface member vptr
                            string.Format(
                                "{0}->vptr0__->{1}({2})",
                                extractContext.GetSymbolName(pairParameters[0].Variable),
                                method.GetCLanguageDeclarationName(overloadIndex),
                                parameterString)
                        };
                    }
                    else
                    {
                        return new[]
                        {
                            string.Format(
                                "{0}({1})",
                                method.CLanguageFunctionName,
                                parameterString)
                        };
                    }
                };
            }
            else
            {
                var result = decodeContext.PushStack(method.ReturnType);

                return extractContext =>
                {
                    var parameters = pairParameters.Select(parameter =>
                        new Utilities.RightExpressionGivenParameter(
                            parameter.Type,
                            parameter.Variable,
                            string.Format(parameter.Format, extractContext.GetSymbolName(parameter.Variable)))).
                        ToArray();

                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        parameters, extractContext, codeInformation);

                    if (isVirtualCall && method.IsVirtual && !method.IsSealed)
                    {
                        var overloadIndex = method.DeclaringType.CalculatedVirtualMethods.
                            First(entry => entry.method.Equals(method)).
                            overloadIndex;

                        return new[]
                        {
                            // TODO: interface member vptr
                            string.Format(
                                "{0} = {1}->vptr0__->{2}({3})",
                                extractContext.GetSymbolName(result),
                                extractContext.GetSymbolName(pairParameters[0].Variable),
                                method.GetCLanguageDeclarationName(overloadIndex),
                                parameterString)
                        };
                    }
                    else
                    {
                        return new[]
                        {
                            string.Format(
                                "{0} = {1}({2})",
                                extractContext.GetSymbolName(result),
                                method.CLanguageFunctionName,
                                parameterString)
                        };
                    }
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
            return CallConverterUtilities.Apply(method, decodeContext, false);
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

            return CallConverterUtilities.Apply(method, decodeContext, true);
        }
    }
}
