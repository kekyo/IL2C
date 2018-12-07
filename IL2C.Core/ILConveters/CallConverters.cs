using System;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;
using IL2C.Metadata.Specialized;

namespace IL2C.ILConverters
{
    internal static class CallConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            IMethodInformation method, DecodeContext decodeContext, bool isVirtualCall)
        {
            // ECMA-335 I.12.4.1.4: Virtual calling convention

            //////////////////////////////////////////////////////////
            // Step 1:

            // Constrained prefix applied, drop virtual call and hack the boxing for arg0 if required.
            //   (See ConstrainedConverter.)
            ITypeInformation requiredBoxingAtArg0ValueType = null;
            var prefixCode = decodeContext.PrefixCode;
            if (prefixCode?.OpCode == OpCodes.Constrained)
            {
                // 'The constrained. prefix is permitted only on a callvirt instruction.'
                if (!isVirtualCall)
                {
                    throw new InvalidProgramSequenceException(
                        "Cannot apply constrained prefix: Location={0}",
                        decodeContext.CurrentCode.RawLocation);
                }

                // ECMA-335 III.2.1 constrained. - (prefix) invoke a member on a value of a variable type
                var constrainedType = (ITypeInformation)(prefixCode.Operand);

                // 'If thisType is a value type...'
                if (constrainedType.IsValueType)
                {
                    // All declared methods from derived to base types.
                    var allDeclaredMethods = constrainedType.AllInheritedDeclaredMethods;

                    // '...and thisType implements method then'
                    var implementationMethod = allDeclaredMethods.First(
                        m => MetadataUtilities.VirtualMethodSignatureComparer.Equals(m, method));

                    // Drop virtual call and turn to the direct call
                    isVirtualCall = false;
                    method = implementationMethod;

                    // '...and thisType does not implement method then'
                    if (!implementationMethod.DeclaringType.Equals(constrainedType))
                    {
                        // 'ptr is dereferenced, boxed, and passed as the ‘this’ pointer to the callvirt of method'

                        // VERY DIRTY: The constrained type uses below.
                        requiredBoxingAtArg0ValueType = constrainedType;
                    }
                }
            }

            //////////////////////////////////////////////////////////
            // Step 2:

            ILocalVariableInformation requiredBoxingAtArg0PointerVariable = null;

            // Construct parameters with expressions.
            var pairParameters = method.Parameters.
                Reverse().  // arg(n - 1) ... arg0
                Select(parameter =>
                {
                    var arg = decodeContext.PopStack();

                    // Arg0
                    if (parameter.Index == 0)
                    {
                        // Required boxing at the arg0
                        if (requiredBoxingAtArg0ValueType != null)
                        {
                            if (!arg.TargetType.IsByReference)
                            {
                                throw new InvalidProgramSequenceException(
                                    "Cannot apply constrained prefix, arg0 isn't byref: Location={0}, Arg0Type={1}",
                                    decodeContext.CurrentCode.RawLocation,
                                    arg.TargetType.FriendlyName);
                            }

                            // VERY DIRTY: The arg0 (managed pointer) uses below.
                            requiredBoxingAtArg0PointerVariable = arg;

                            // VERY DIRTY: Make the boxing expression below,
                            //   it's reserving for the boxed value symbol at the evaluation stack.
                            var arg0BoxedSymbol = decodeContext.PushStack(
                                new BoxedValueTypeInformation(requiredBoxingAtArg0ValueType));
                            decodeContext.PopStack();

                            return new
                            {
                                Type = parameter.TargetType,
                                Variable = arg0BoxedSymbol,
                                Format = "{0}"
                            };
                        }
                        // Include adjust offset expression if it's virtual method
                        else if (isVirtualCall)
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

            //////////////////////////////////////////////////////////
            // Step 3:

            var codeInformation = decodeContext.CurrentCode;

            ILocalVariableInformation result;
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

                result = null;
            }
            else
            {
                result = decodeContext.PushStack(method.ReturnType);
            }

            return extractContext =>
            {
                var receiveResultExpression = (result != null) ?
                    string.Format("{0} = ", extractContext.GetSymbolName(result)) :
                    string.Empty;

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

                // Construct call expression between virtual and non-virtual.
                string callExpression;
                if (isVirtualCall && method.IsVirtual && !method.IsSealed)
                {
                    var overloadIndex = method.DeclaringType.CalculatedVirtualMethods.
                        First(entry => entry.method.Equals(method)).
                        overloadIndex;

                    callExpression = string.Format(
                        "{0}{1}->vptr0__->{2}({3})",
                        receiveResultExpression,
                        extractContext.GetSymbolName(pairParameters[0].Variable),
                        method.GetCLanguageDeclarationName(overloadIndex),
                        parameterString);
                }
                else
                {
                    callExpression = string.Format(
                        "{0}{1}({2})",
                        receiveResultExpression,
                        method.CLanguageFunctionName,
                        parameterString);
                }

                // If requires boxed arg0
                if (requiredBoxingAtArg0ValueType != null)
                {
                    Debug.Assert(requiredBoxingAtArg0PointerVariable != null);

                    // Emit call expression with boxing expression.
                    return new[] {
                        string.Format(
                            "{0} = il2c_box({1}, {2})",
                            extractContext.GetSymbolName(pairParameters[0].Variable),
                            extractContext.GetSymbolName(requiredBoxingAtArg0PointerVariable),
                            requiredBoxingAtArg0ValueType.MangledName),
                        callExpression };
                }
                else
                {
                    // Emit only call expression
                    return new[] { callExpression };
                }
            };
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
