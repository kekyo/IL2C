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
        private static (ITypeInformation type, ILocalVariableInformation variable, string format) GetArg0ParameterInformation(
            DecodeContext decodeContext,
            ref IMethodInformation method,
            IParameterInformation parameter0,
            ILocalVariableInformation arg0,
            ref ITypeInformation arg0ValueType,
            ref ILocalVariableInformation requiredBoxingAtArg0PointerVariable,
            ref ILocalVariableInformation requiredCastingAtArg0PointerVariable,
            ref bool isVirtualCall)
        {
            Debug.Assert(method.IsStatic ||
                parameter0.TargetType.Equals(method.DeclaringType) ||
                (parameter0.TargetType.IsByReference && parameter0.TargetType.ElementType.Equals(method.DeclaringType)));

            // Required boxing at the arg0
            if (arg0ValueType != null)
            {
                if (!arg0.TargetType.IsByReference)
                {
                    throw new InvalidProgramSequenceException(
                        "Cannot apply constrained prefix, arg0 isn't byref: Location={0}, Arg0Type={1}",
                        decodeContext.CurrentCode.RawLocation,
                        arg0.TargetType.FriendlyName);
                }

                // VERY DIRTY: The arg0 (managed pointer) uses below.
                requiredBoxingAtArg0PointerVariable = arg0;

                // VERY DIRTY: Make the boxing expression below,
                //   it's reserving for the boxed value symbol at the evaluation stack.
                var arg0BoxedSymbol = decodeContext.PushStack(
                    new BoxedValueTypeInformation(arg0ValueType));
                decodeContext.PopStack();

                return (parameter0.TargetType, arg0BoxedSymbol, "{0}");
            }
            // If it's virtual method
            else if (isVirtualCall)
            {
                // Invoke interface method with the inline boxed-type instance.
                //   ex: ((IFoo)foo).Bar(...)
                //   If not inlined (ex: bound to local variable), arg0 doesn't box type. Next to the else block.
                if (method.DeclaringType.IsInterface && arg0.TargetType.IsBoxedType)
                {
                    // VERY DIRTY: The arg0 (boxed value) uses below.
                    requiredCastingAtArg0PointerVariable = arg0;
                    arg0ValueType = arg0.TargetType;

                    // VERY DIRTY: Make the implicitly cast expression below,
                    //   it's reserving for the casted value symbol at the evaluation stack.
                    var arg0CastedSymbol = decodeContext.PushStack(method.DeclaringType);
                    decodeContext.PopStack();

                    return (parameter0.TargetType, arg0CastedSymbol, "il2c_adjusted_reference({0})");
                }
                // Invoke interface method with the class-type instance and
                // IL2C detected here for can cast statically.
                else if (method.DeclaringType.IsInterface &&
                    arg0.TargetType.IsClass &&
                    method.DeclaringType.IsAssignableFrom(arg0.TargetType))
                {
                    // All declared methods from derived to base types.
                    var allDeclaredMethods = arg0.TargetType.AllInheritedDeclaredMethods;

                    var m = method;
                    var implementationMethod = allDeclaredMethods.First(
                        dm => MetadataUtilities.VirtualMethodSignatureComparer.Equals(dm, m));

                    Debug.Assert(implementationMethod.DeclaringType.IsAssignableFrom(arg0.TargetType));

                    // Drop virtual call and turn to the direct call (devirtualize)
                    isVirtualCall = false;
                    method = implementationMethod;
                    return (arg0.TargetType, arg0, "il2c_adjusted_reference({0})");
                }
                else
                {
                    // Include adjust offset expression
                    return (parameter0.TargetType, arg0, "il2c_adjusted_reference({0})");
                }
            }
            else
            {
                return (parameter0.TargetType, arg0, "{0}");
            }
        }

        public static Func<IExtractContext, string[]> Apply(
            IMethodInformation method,
            DecodeContext decodeContext,
            bool isVirtualCall)
        {
            // ECMA-335 I.12.4.1.4: Virtual calling convention

            //////////////////////////////////////////////////////////
            // Step 1:

            // Constrained prefix applied, drop virtual call and hack the boxing for arg0 if required.
            //   (See ConstrainedConverter.)
            ITypeInformation arg0ValueType = null;
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
                        dm => MetadataUtilities.VirtualMethodSignatureComparer.Equals(dm, method));

                    // Drop virtual call and turn to the direct call (devirtualize)
                    isVirtualCall = false;
                    method = implementationMethod;

                    // '...and thisType does not implement method then'
                    if (!implementationMethod.DeclaringType.Equals(constrainedType))
                    {
                        // 'ptr is dereferenced, boxed, and passed as the ‘this’ pointer to the callvirt of method'

                        // VERY DIRTY: The constrained type uses below.
                        arg0ValueType = constrainedType;
                    }
                }
            }

            //////////////////////////////////////////////////////////
            // Step 2:

            ILocalVariableInformation requiredBoxingAtArg0PointerVariable = null;
            ILocalVariableInformation requiredCastingAtArg0PointerVariable = null;

            // Construct parameters with expressions.
            var pairParameters = method.Parameters.
                Reverse().  // arg(n - 1) ... arg0
                Select(parameter =>
                {
                    var arg = decodeContext.PopStack();
                    return (parameter.Index == 0) ?
                        GetArg0ParameterInformation(
                            decodeContext, ref method, parameter, arg,
                            ref arg0ValueType,
                            ref requiredBoxingAtArg0PointerVariable,
                            ref requiredCastingAtArg0PointerVariable,
                            ref isVirtualCall) :
                        (type: parameter.TargetType, variable: arg, format: "{0}");
                }).
                Reverse().
                ToArray();

            //////////////////////////////////////////////////////////
            // Step 3: Fixing special cases

            var codeInformation = decodeContext.CurrentCode;
            ILocalVariableInformation result;

            // TODO: HACK: IL2C can't handle the generic types/methods in this version.
            //   Roslyn will generate implementation for the event member with using for
            //   "System.Threading.Interlocked.CompareExchange<T>(...)" method.
            //   It's special resolver for event member.
            if ((method.UniqueName == "T System.Threading.Interlocked::CompareExchange(T&,T,T)") &&
                pairParameters[1].variable.TargetType.IsDelegate)
            {
                result = decodeContext.PushStack(pairParameters[1].variable.TargetType);

                return extractContext =>
                {
                    var parameters = pairParameters.Select(parameter =>
                        new Utilities.RightExpressionGivenParameter(
                            parameter.variable.TargetType,
                            parameter.variable,
                            string.Format(parameter.format, extractContext.GetSymbolName(parameter.variable)))).
                        ToArray();

                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        parameters,
                        extractContext,
                        codeInformation);

                    return new[]
                    {
                        string.Format(
                            "{0} = ({1})System_Threading_Interlocked_CompareExchange_6({2})",
                            extractContext.GetSymbolName(result),
                            pairParameters[1].variable.TargetType.CLanguageTypeName,
                            parameterString)
                    };
                };
            }

            if (method.ReturnType.IsVoidType)
            {
                // HACK: If we will call the RuntimeHelpers.InitializeArray, we can memoize array type hint.
                //   (See LdtokenConverter.)
                if (method.FriendlyName.StartsWith(
                    "System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray"))
                {
                    Debug.Assert(pairParameters.Length == 2);
                    Debug.Assert(pairParameters[1].variable.HintInformation is string);

                    decodeContext.PrepareContext.RegisterDeclaredValuesHintType(
                        (string)pairParameters[1].variable.HintInformation,
                        pairParameters[0].variable.TargetType);
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
                        parameter.type,
                        parameter.variable,
                        string.Format(parameter.format, extractContext.GetSymbolName(parameter.variable)))).
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
                        extractContext.GetSymbolName(pairParameters[0].variable),
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

                // If requires boxing expression
                if (requiredBoxingAtArg0PointerVariable != null)
                {
                    Debug.Assert(arg0ValueType != null);

                    // Emit call expression with boxing expression.
                    return new[] {
                        string.Format(
                            "{0} = il2c_box({1}, {2})",
                            extractContext.GetSymbolName(pairParameters[0].variable),
                            extractContext.GetSymbolName(requiredBoxingAtArg0PointerVariable),
                            arg0ValueType.MangledUniqueName),
                        callExpression };
                }
                // If requires casting expression
                else if (requiredCastingAtArg0PointerVariable != null)
                {
                    // Emit call expression with casting expression.
                    return new[] {
                        string.Format(
                            "{0} = il2c_cast_from_boxed_to_interface({1}, {2}, {3}, {4})",
                            extractContext.GetSymbolName(pairParameters[0].variable),
                            method.DeclaringType.MangledUniqueName,
                            arg0ValueType.ElementType.CLanguageStaticSizeOfExpression,
                            arg0ValueType.CalculateInterfaceIndex(method.DeclaringType),
                            extractContext.GetSymbolName(requiredCastingAtArg0PointerVariable)),
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
