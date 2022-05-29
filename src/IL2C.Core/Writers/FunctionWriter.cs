////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System.Linq;
using System.Diagnostics;

using IL2C.Metadata;
using IL2C.Translators;
using IL2C.ILConverters;
using IL2C.Internal;

namespace IL2C.Writers
{
    internal static class FunctionWriter
    {
        private static void InternalConvertExecutionFrame(
            CodeTextWriter tw,
            IExtractContextHost extractContext,
            PreparedMethodInformation preparedMethod,
            ILocalVariableInformation[] objRefEntries,
            ILocalVariableInformation[] valueEntries)
        {
            tw.WriteLine("//-------------------");
            tw.WriteLine("// [3-7] Declare execution frame:");
            tw.SplitLine();

            tw.WriteLine(
                "typedef struct {0}_EXECUTION_FRAME_DECL",
                preparedMethod.Method.CLanguageFunctionFullName);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                tw.WriteLine("const IL2C_EXECUTION_FRAME* pNext__;");
                tw.WriteLine("const uint16_t objRefCount__;");
                tw.WriteLine("const uint16_t valueCount__;");

                if (objRefEntries.Length >= 1)
                {
                    tw.WriteLine("//-------------------- objref");
                    var objrefNames = objRefEntries.
                        Select(oe => extractContext.GetSymbolName(oe)).
                        RenameDuplicatingSymbols();
                    foreach (var (objRefEntry, name) in
                        objRefEntries.Zip(objrefNames, (oe, on) => (oe, on)))
                    {
                        tw.WriteLine(
                            "{0} {1};",
                            objRefEntry.TargetType.CLanguageTypeName,
                            name);
                    }
                }

                if (valueEntries.Length >= 1)
                {
                    tw.WriteLine("//-------------------- value type");
                    var valueNames = valueEntries.
                        Select(ve => extractContext.GetSymbolName(ve)).
                        RenameDuplicatingSymbols();
                    foreach (var (valueEntry, name) in
                        valueEntries.Zip(valueNames, (ve, vn) => (ve, vn)))
                    {
                        tw.WriteLine(
                            "const IL2C_RUNTIME_TYPE {0}_type__;",
                            name);
                        tw.WriteLine(
                            "const {0}* {1}_value_ptr__;",
                            valueEntry.TargetType.CLanguageTypeName,
                            name);
                    }
                }
            }

            tw.WriteLine(
                "}} {0}_EXECUTION_FRAME__;",
                preparedMethod.Method.CLanguageFunctionFullName);
            tw.SplitLine();
        }

        private static void InternalConvertSetupExecutionFrame(
            CodeTextWriter tw,
            IExtractContextHost extractContext,
            PreparedMethodInformation preparedMethod,
            ILocalVariableInformation[] objRefEntries,
            ILocalVariableInformation[] valueEntries,
            DebugInformationWriteController debugInformationController)
        {
            tw.WriteLine("//-------------------");
            tw.WriteLine("// [3-5] Setup execution frame:");
            tw.SplitLine();

            // Important NULL assigner (p = NULL):
            //   Because these variables are pointer (of object reference 'O' type).
            //   So GC will traverse these variables just setup the stack frame.
            debugInformationController.WriteInformationBeforeCode(tw);
            tw.WriteLine(
                "{0}_EXECUTION_FRAME__ frame__ =",
                preparedMethod.Method.CLanguageFunctionFullName);
            using (var __ = tw.Shift())
            {
                if (valueEntries.Length >= 1)
                {
                    tw.WriteLine(
                        "{{ NULL, {0}, {1}, {2} }};",
                        objRefEntries.Length,
                        valueEntries.Length,
                        string.Join(
                            ", ",
                            objRefEntries.Select(___ => "NULL").
                            Concat(valueEntries.
                                Select(valueEntry =>
                                    string.Format(
                                        "il2c_typeof({0}), NULL",
                                        valueEntry.TargetType.MangledUniqueName)))));
                }
                else
                {
                    // Make short initializer expression if value type not included,
                    // maybe C compiler makes better code.
                    tw.WriteLine(
                        "{{ NULL, {0} }};",
                        objRefEntries.Length);
                }
            }

            foreach (var valueEntry in valueEntries)
            {
                debugInformationController.WriteInformationBeforeCode(tw);
                tw.WriteLine(
                    "frame__.{0}_value_ptr__ = &{0};",
                    extractContext.GetSymbolName(valueEntry));
            }

            debugInformationController.WriteInformationBeforeCode(tw);
            tw.WriteLine("il2c_link_execution_frame(&frame__);");
            tw.SplitLine();
        }

        private static void InternalConvertExceptionFilter(
            CodeTextWriter tw,
            IExtractContextHost extractContext,
            PreparedMethodInformation preparedMethod,
            ICodeStream codeStream)
        {
            tw.WriteLine("//-------------------");
            tw.WriteLine("// [3-1] Exception filters:");
            tw.SplitLine();

            for (var handlerIndex = 0;
                handlerIndex < codeStream.ExceptionHandlers.Length;
                handlerIndex++)
            {
                var handler = codeStream.ExceptionHandlers[handlerIndex];

                var filterName = string.Format(
                    "{0}_ExceptionFilter{1}__",
                    preparedMethod.Method.CLanguageFunctionFullName,
                    handlerIndex);
                tw.WriteLine(
                    "static int16_t {0}(System_Exception* ex)",
                    filterName);
                tw.WriteLine("{");

                using (var _ = tw.Shift())
                {
                    tw.WriteLine("il2c_assert(ex != NULL);");

                    for (var catchHandlerIndex = 0;
                        catchHandlerIndex < handler.CatchHandlers.Length;
                        catchHandlerIndex++)
                    {
                        var catchHandler = handler.CatchHandlers[catchHandlerIndex];
                        if (catchHandler.CatchHandlerType == ExceptionCatchHandlerTypes.Catch)
                        {
                            tw.WriteLine(
                                "if (il2c_unlikely__(il2c_isinst__(ex, il2c_typeof({0})))) return {1};",
                                catchHandler.CatchType.MangledUniqueName,
                                catchHandlerIndex + 1);
                        }
                    }

                    // Write finally block index if contains.
                    var finallyHandler = handler.CatchHandlers.
                        Select((catchHandler, index) => new { catchHandler, index }).
                        FirstOrDefault(entry => entry.catchHandler.CatchHandlerType == ExceptionCatchHandlerTypes.Finally);
                    if (finallyHandler != null)
                    {
                        tw.WriteLine("return IL2C_FILTER_FINALLY;  // Not matched (will go to finally)");
                    }
                    else
                    {
                        tw.WriteLine("return IL2C_FILTER_NOMATCH;  // Not matched");
                    }
                }

                tw.WriteLine("}");
                tw.SplitLine();
            }
        }

        private static void InternalConvertFromFunction(
            CodeTextWriter tw,
            IExtractContextHost extractContext,
            PreparedMethodInformation preparedMethod,
            DebugInformationOptions debugInformationOption)
        {
            var locals = preparedMethod.Method.LocalVariables;

            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine(
                "// [3] {0}{1}",
                preparedMethod.Method.IsVirtual ? "Virtual: " : string.Empty,
                preparedMethod.Method.FriendlyName);
            tw.SplitLine();

            var codeStream = preparedMethod.Method.CodeStream;
            var objRefEntries = locals.
                Concat(preparedMethod.Stacks).
                Where(v => v.TargetType.IsReferenceType).  // Only objref
                ToArray();
            var valueEntries = locals.
                Concat(preparedMethod.Stacks).
                Where(v => v.TargetType.IsValueType && v.TargetType.IsRequiredTraverse).
                ToArray();

            // Write declaring exception handlers
            if (codeStream.ExceptionHandlers.Length >= 1)
            {
                InternalConvertExceptionFilter(
                    tw,
                    extractContext,
                    preparedMethod,
                    codeStream);
            }

            // Write declaring execution frame
            if ((objRefEntries.Length >= 1) || (valueEntries.Length >= 1))
            {
                InternalConvertExecutionFrame(
                    tw,
                    extractContext,
                    preparedMethod,
                    objRefEntries,
                    valueEntries);
            }

            // Make readable debugging comment, it was splitting and reducing same informations.
            var debugInformationController =
                new DebugInformationWriteController(
                    preparedMethod.Method,
                    debugInformationOption);

            // Start function:
            tw.WriteLine("//-------------------");
            tw.WriteLine("// [3-2] Function body:");
            tw.SplitLine();
            tw.WriteLine(preparedMethod.Method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                if (!preparedMethod.Method.IsStatic)
                {
                    debugInformationController.WriteInformationBeforeCode(tw);
                    tw.WriteLine("il2c_assert(this__ != NULL);");
                    tw.SplitLine();
                }

                var localDefinitions = preparedMethod.Method.LocalVariables.
                    Where(local => !local.TargetType.IsReferenceType).
                    ToArray();
                if (localDefinitions.Length >= 1)
                {
                    tw.WriteLine("//-------------------");
                    tw.WriteLine("// [3-3] Local variables (!objref):");
                    tw.SplitLine();

                    var localNames = localDefinitions.
                        Select(local => extractContext.GetSymbolName(local)).
                        RenameDuplicatingSymbols();
                    foreach (var (local, name) in localDefinitions.
                        Zip(localNames, (local, name) => (local, name)))
                    {
                        // HACK: The local variables mark to "volatile."
                        //   Because the gcc misread these variables calculated statically (or maybe assigned to the registers)
                        //   at compile time with optimization.
                        //   It will cause the strange results for exception handling (with sjlj.)

                        // We have to initialize the local variables.
                        if (local.TargetType.IsPrimitive ||
                            local.TargetType.IsPointer ||
                            local.TargetType.IsByReference)
                        {
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine(
                                "{0}{1} {2} = {3};",
                                (codeStream.ExceptionHandlers.Length >= 1) ? "volatile " : string.Empty,
                                local.TargetType.CLanguageTypeName,
                                name,
                                SymbolManipulator.GetCLanguageExpression(local.TargetType.InternalStaticEmptyValue));
                        }
                        else
                        {
                            Debug.Assert(local.TargetType.IsValueType);

                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine(
                                "{0}{1} {2};",
                                (codeStream.ExceptionHandlers.Length >= 1) ? "volatile " : string.Empty,
                                local.TargetType.CLanguageTypeName,
                                name);

                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine(
                                "memset({0}&{1}, 0x00, sizeof {1});",
                                (codeStream.ExceptionHandlers.Length >= 1) ? "(void*)" : string.Empty,
                                name);
                        }
                    }

                    tw.SplitLine();
                }

                var stackDefinitions = preparedMethod.Stacks.
                    Where(stack => !stack.TargetType.IsReferenceType).
                    ToArray();
                if (stackDefinitions.Length >= 1)
                {
                    tw.WriteLine("//-------------------");
                    tw.WriteLine("// [3-4] Evaluation stacks (!objref):");
                    tw.SplitLine();

                    foreach (var stack in stackDefinitions)
                    {
                        var name = extractContext.GetSymbolName(stack);

                        debugInformationController.WriteInformationBeforeCode(tw);
                        tw.WriteLine(
                            "{0} {1};",
                            stack.TargetType.CLanguageTypeName,
                            name);

                        // Note: We often don't have to initalize the evaluation stack variables.
                        //   Because these variables push value at first usage.
                        //   But the value type may contains objref field,
                        //   so we have to initialize for value type.
                        if (stack.TargetType.IsRequiredTraverse)
                        {
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine(
                                "memset(&{0}, 0, sizeof {0});",
                                name);
                        }
                    }

                    tw.SplitLine();
                }

                // Write doing setup execution frame
                var executionFrameEmitted = false;
                if ((objRefEntries.Length >= 1) || (valueEntries.Length >= 1))
                {
                    InternalConvertSetupExecutionFrame(
                        tw,
                        extractContext,
                        preparedMethod, 
                        objRefEntries,
                        valueEntries,
                        debugInformationController);
                    executionFrameEmitted = true;
                }

                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-6] IL body:");
                tw.SplitLine();

                // Set symbol prefix to make valid access variables.
                using (var __ = extractContext.BeginLocalVariablePrefix(
                    local => local.TargetType.IsReferenceType ? "frame__." : null))
                {
                    // Construct exception handler controller.
                    var exceptionHandlerController = new ExceptionHandlerController(
                        codeStream.ExceptionHandlers,
                        (handler, handlerIndex, nestedIndex) =>
                        {
                            var nestedIndexName = string.Format("nest{0}", nestedIndex);
                            extractContext.SetNestedExceptionFrameIndexName(nestedIndexName);

                            // Reached try block:
                            var filterName = string.Format(
                                "{0}_ExceptionFilter{1}__",
                                preparedMethod.Method.CLanguageFunctionFullName,
                                handlerIndex);

                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine("il2c_try({0}, {1})", nestedIndexName, filterName);

                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine("{");
                            tw.Shift();
                        },
                        (handler, handlerIndex, nestedIndex) =>
                        {
                            // Reached try end block:
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.Shift(-1);
                            tw.WriteLine("}");
                        },
                        (handler, handlerIndex, nestedIndex, catchHandler, catchHandlerIndex) =>
                        {
                            var nestedIndexName = extractContext.GetExceptionNestedFrameIndexName();
                            switch (catchHandler.CatchHandlerType)
                            {
                                case ExceptionCatchHandlerTypes.Catch:
                                    // Reached catch block:
                                    debugInformationController.WriteInformationBeforeCode(tw);
                                    tw.WriteLine(
                                        "il2c_catch({0}, {1}, {2})  // catch ({3})",
                                        nestedIndexName,
                                        catchHandlerIndex + 1,
                                        extractContext.GetSymbolName(preparedMethod.CatchVariables[catchHandler.CatchStart]),
                                        catchHandler.CatchType.MangledUniqueName);
                                    break;
                                case ExceptionCatchHandlerTypes.Finally:
                                    // Reached finally block:
                                    debugInformationController.WriteInformationBeforeCode(tw);
                                    tw.WriteLine("il2c_finally({0})", nestedIndexName);
                                    break;
                            }
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine("{");
                            tw.Shift();
                        },
                        (handler, handlerIndex, nestedIndex, catchHandler, catchHandlerIndex) =>
                        {
                            // Reached catch end block:
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.Shift(-1);
                            tw.WriteLine("}");
                        },
                        (handler, handlerIndex, nestedIndex, parentHandler, parentHandlerIndex, parentNestedIndex) =>
                        {
                            var nestedIndexName = extractContext.GetExceptionNestedFrameIndexName();
                            var parentNestedIndexName = (parentNestedIndex >= 0) ? string.Format("nest{0}", parentNestedIndex) : null;

                            // Write leave bind expressions if needed.
                            // Extract the continuation fromOffset inside at mostly inner exception handler.
                            var bindEntries =
                                preparedMethod.LeaveContinuations.
                                SelectMany(entry => codeStream.ExceptionHandlers.
                                    // nested exception handlers: inner --> outer
                                    Reverse().
                                    // Is this handler contains leave continuation target?
                                    Where(h => entry.Value.fromOffsets.Any(offset => h.ContainsOffset(offset))).
                                    // Found.
                                    Select(h => new { handler = h, continuationIndex = entry.Key, entry.Value.targetOffset })).
                                // ... is current handler?
                                Where(entry => entry.handler.Equals(handler)).
                                ToArray();
                            if (bindEntries.Length >= 1)
                            {
                                debugInformationController.WriteInformationBeforeCode(tw);
                                tw.WriteLine("il2c_leave_to({0})", nestedIndexName);

                                debugInformationController.WriteInformationBeforeCode(tw);
                                tw.WriteLine("{");

                                using (var ___ = tw.Shift())
                                {
                                    foreach (var bind in bindEntries)
                                    {
                                        if ((parentNestedIndex < 0) ||
                                            codeStream.ExceptionHandlers[parentNestedIndex].ContainsOffset(bind.targetOffset))
                                        {
                                            var labelName = preparedMethod.LabelNames[bind.targetOffset];

                                            debugInformationController.WriteInformationBeforeCode(tw);
                                            tw.WriteLine(
                                                "il2c_leave_bind({0}, {1}, {2});",
                                                nestedIndexName,
                                                bind.continuationIndex,
                                                labelName);
                                        }
                                        else
                                        {
                                            debugInformationController.WriteInformationBeforeCode(tw);
                                            tw.WriteLine(
                                                "il2c_leave_through({0}, {1}, {2});",
                                                nestedIndexName, bind.continuationIndex, parentNestedIndexName);
                                        }
                                    }
                                }

                                debugInformationController.WriteInformationBeforeCode(tw);
                                tw.WriteLine("}");
                            }

                            // Reached end of entire try block.
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine("il2c_end_try({0});", nestedIndexName);

                            extractContext.SetNestedExceptionFrameIndexName(parentNestedIndexName);
                        });

                    // Traverse code fragments.
                    var emitContext = new ExpressionEmitContext(executionFrameEmitted);
                    foreach (var ci in codeStream)
                    {
                        debugInformationController.SetNextCode(ci);

                        // 1: Update the exception handler controller.
                        //    (Will write exception related sentences.)
                        exceptionHandlerController.Update(ci);

                        // 2: Write label if available and used.
                        if (preparedMethod.LabelNames.TryGetValue(ci.Offset, out var labelName))
                        {
                            using (var ___ = tw.Shift(-1))
                            {
                                tw.WriteLine("{0}:", labelName);
                            }
                        }

                        // 3: Write source code comment.
                        debugInformationController.WriteCodeComment(tw);

                        // 4: Generate source code fragments and write.
                        var sourceCodes = preparedMethod.Emitters[ci.Offset](extractContext, emitContext);
                        foreach (var sourceCode in sourceCodes)
                        {
                            debugInformationController.WriteInformationBeforeCode(tw);
                            tw.WriteLine(
                                "{0};",
                                sourceCode);
                        }
                    }

                    // If last opcode is 'endfinally' and not emitted 'ret',
                    // can't finished for exceptionHandlerController.
                    // We can check and force update the TryFinish method for this situation.
                    exceptionHandlerController.TryFinish();

                    if (!exceptionHandlerController.IsFinished)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid exception handler range. MethodName={0}, ExceptionHandlers=[{1}]",
                            preparedMethod.Method.FriendlyName,
                            string.Join(
                                ",",
                                codeStream.ExceptionHandlers.
                                    Select(handler => string.Format("[{0}]", handler))));
                    }
                }
            }

            debugInformationController.WriteInformationBeforeCode(tw);
            tw.WriteLine("}");
            tw.SplitLine();
        }

        private static void InternalConvertFromDelegateFunction(
            CodeTextWriter tw,
            IMethodInformation method)
        {
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [4] Abstract: {0}", method.FriendlyName);
            tw.SplitLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                tw.WriteLine(
                    "// WARNING: Pure virtual function called.");
                tw.WriteLine(
                    "//TODO: throw : assert(0);");

                if (method.ReturnType.IsVoidType == false)
                {
                    tw.WriteLine(
                        "return ({0}){1};",
                        method.ReturnType.CLanguageTypeName,
                        method.ReturnType.IsNumericPrimitive ? "0" : "NULL");
                }
            }

            tw.WriteLine("}");
            tw.SplitLine();
        }

        private static void InternalConvertFromAbstractFunction(
            CodeTextWriter tw,
            IMethodInformation method)
        {
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [5] Abstract: {0}", method.FriendlyName);
            tw.SplitLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                tw.WriteLine(
                    "// WARNING: Pure virtual function called.");
                tw.WriteLine(
                    "// TODO: throw : assert(0);");

                if (method.ReturnType.IsVoidType == false)
                {
                    tw.WriteLine(
                        "return ({0}){1};",
                        method.ReturnType.CLanguageTypeName,
                        method.ReturnType.IsNumericPrimitive ? "0" : "NULL");
                }
            }

            tw.WriteLine("}");
            tw.SplitLine();
        }

        private static void InternalConvertFromInternalCallFunction(
            CodeTextWriter tw,
            IMethodInformation method)
        {
            Debug.Assert(method.IsExtern);

            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine(
                "// [6] {0}: {1}",
                (method.PInvokeInformation != null) ? "P/Invoke" : "IL2C/Invoke",
                method.FriendlyName);
            tw.SplitLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);

            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                static string GetMarshaledInExpression(IParameterInformation parameter)
                {
                    // TODO: UTF8 conversion
                    // TODO: Apply MarshalAsAttribute

                    if (parameter.TargetType.IsStringType)
                    {
                        return string.Format("{0}->string_body__", parameter.ParameterName);
                    }
                    return parameter.ParameterName;
                }

                var arguments = string.Join(
                    ", ",
                    method.Parameters.Select(GetMarshaledInExpression));

                if (method.PInvokeInformation != null)
                {
                    // TODO: caching
                    tw.WriteLine(
                        "{0} = il2c_pinvoke_get_function__(L\"{1}\", \"{2}\");",
                        method.GetCLanguageFunctionTypeWithVariableName("pFunc__", true),
                        method.PInvokeInformation.Module.Name,
                        method.CLanguageInteropName);
                    if (method.ReturnType.IsVoidType)
                    {
                        tw.WriteLine(
                            "(*pFunc__)({0});",
                            arguments);
                    }
                    else
                    {
                        tw.WriteLine(
                            "return (*pFunc__)({0});",
                            arguments);
                    }
                }
                else
                {
                    if (method.ReturnType.IsVoidType)
                    {
                        tw.WriteLine(
                            "{0}({1});",
                            method.CLanguageInteropName,
                            arguments);
                    }
                    else
                    {
                        tw.WriteLine(
                            "return {0}({1});",
                            method.CLanguageInteropName,
                            arguments);
                    }
                }
            }

            tw.WriteLine("}");
            tw.SplitLine();
        }

        private static void InternalConvertFromDelegateInvoker(
            CodeTextWriter tw,
            IExtractContext extractContext,
            IMethodInformation invokeMethod)
        {
            if (invokeMethod.Parameters.Length == 0)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid delegate invoker. Name={0}",
                    invokeMethod.FriendlyName);
            }

            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [11-2] Delegate invoker: {0}", invokeMethod.FriendlyName);
            tw.SplitLine();

            // DIRTY:
            //   Cause undefined symbol error at C compilation if "System.Delegate" type on the mscorlib assembly
            //   contains the fields with different symbol name.

            var thisName = invokeMethod.Parameters[0].ParameterName;
            var delegateParameters = invokeMethod.Parameters.Skip(1).ToArray();

            tw.WriteLine(invokeMethod.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                tw.WriteLine(
                    "il2c_assert({0} != NULL);",
                    thisName);
                tw.WriteLine(
                    "il2c_assert({0}->vptr0__ == &System_Delegate_VTABLE__);",
                    thisName);
                tw.WriteLine(
                    "il2c_assert({0}->count__ >= 1);",
                    thisName);
                tw.SplitLine();

                if (!invokeMethod.ReturnType.IsVoidType)
                {
                    if (invokeMethod.ReturnType.IsReferenceType)
                    {
                        tw.WriteLine(
                            "volatile struct {0}_EXECUTION_FRAME_DECL",
                            invokeMethod.CLanguageFunctionFullName);
                        tw.WriteLine("{");
                        using (var __ = tw.Shift())
                        {
                            tw.WriteLine("IL2C_EXECUTION_FRAME* pNext__;");
                            tw.WriteLine("uint16_t objRefCount__;");
                            tw.WriteLine("uint16_t valueCount__;");
                            tw.WriteLine(
                                "{0} result;",
                                invokeMethod.ReturnType.CLanguageTypeName);
                        }
                        tw.WriteLine("} frame__ = { NULL, 1, 0 };");
                        tw.WriteLine("il2c_link_execution_frame(&frame__);");
                    }
                    else
                    {
                        tw.WriteLine(
                            "{0} result;",
                            invokeMethod.ReturnType.CLanguageTypeName);
                    }
                }

                tw.SplitLine();
                tw.WriteLine(
                    "uintptr_t index = 0;");
                tw.WriteLine(
                    "do",
                    thisName);
                tw.WriteLine(
                    "{");

                using (var __ = tw.Shift())
                {
                    tw.WriteLine(
                        "IL2C_METHOD_TABLE* pMethodtbl = &{0}->methodtbl__[index];",
                        thisName);

                    if (invokeMethod.ReturnType.IsVoidType)
                    {
                        tw.WriteLine("if (pMethodtbl->target != NULL)");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "((void (*)(System_Object*{0}))(pMethodtbl->methodPtr))(pMethodtbl->target{1});",
                                string.Join(string.Empty, delegateParameters.
                                    Select(p => string.Format(", {0}", p.TargetType.CLanguageTypeName))),
                                string.Join(string.Empty, delegateParameters.
                                    Select(p => string.Format(", {0}", p.ParameterName))));
                        }
                        tw.WriteLine("else");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "((void (*)({0}))(pMethodtbl->methodPtr))({1});",
                                (delegateParameters.Length >= 1) ?
                                    string.Join(", ", delegateParameters.
                                        Select(p => p.TargetType.CLanguageTypeName)) :
                                        "void",
                                string.Join(", ", delegateParameters.
                                    Select(p => p.ParameterName)));
                        }
                    }
                    else
                    {
                        tw.WriteLine("if (pMethodtbl->target != NULL)");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "{0}result = (({1} (*)(System_Object*{2}))(pMethodtbl->methodPtr))(pMethodtbl->target{3});",
                                invokeMethod.ReturnType.IsReferenceType ? "frame__." : string.Empty,
                                invokeMethod.ReturnType.CLanguageTypeName,
                                string.Join(string.Empty, delegateParameters.
                                    Select(p => string.Format(", {0}", p.TargetType.CLanguageTypeName))),
                                string.Join(string.Empty, delegateParameters.
                                    Select(p => string.Format(", {0}", p.ParameterName))));
                        }
                        tw.WriteLine("else");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "{0}result = (({1} (*)({2}))(pMethodtbl->methodPtr))({3});",
                                invokeMethod.ReturnType.IsReferenceType ? "frame__." : string.Empty,
                                invokeMethod.ReturnType.CLanguageTypeName,
                                (delegateParameters.Length >= 1) ?
                                    string.Join(", ", delegateParameters.
                                        Select(p => p.TargetType.CLanguageTypeName)) :
                                        "void",
                                string.Join(", ", delegateParameters.
                                    Select(p => p.ParameterName)));
                        }
                    }

                    tw.WriteLine("index++;");
                }
                tw.WriteLine("}");
                tw.WriteLine("while (il2c_likely__(index < this__->count__));");
                tw.SplitLine();

                if (invokeMethod.ReturnType.IsVoidType)
                {
                    tw.WriteLine("il2c_return();");
                }
                else
                {
                    if (invokeMethod.ReturnType.IsReferenceType)
                    {
                        tw.WriteLine("il2c_return_unlink_with_objref(&frame__, frame__.result);");
                    }
                    else
                    {
                        tw.WriteLine("il2c_return_with_value(result);");
                    }
                }
            }

            tw.WriteLine("}");
            tw.SplitLine();
        }

        public static void InternalConvertFromMethod(
            CodeTextWriter tw,
            IExtractContextHost extractContext,
            PreparedInformations preparedFunctions,
            IMethodInformation method,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.None)
        {
            if (method.IsVirtual)
            {
                if (method.IsAbstract)
                {
                    if (!method.DeclaringType.IsInterface)
                    {
                        InternalConvertFromAbstractFunction(
                            tw,
                            method);
                    }
                    return;
                }
            }

            // internalcall or DllImport
            if (method.IsExtern)
            {
                // Specialize delegate type methods:
                if (method.DeclaringType.IsDelegate && !method.DeclaringType.IsAbstract)
                {
                    // Delegate constructor
                    if (method.IsConstructor)
                    {
                        // Ignore. We have to use the "il2c_new_delegate()" instead this constructor translated body.
                        return;
                    }

                    // Delegate "Invoke"
                    if (method.Name == "Invoke")
                    {
                        InternalConvertFromDelegateInvoker(
                            tw,
                            extractContext,
                            method);
                        return;
                    }
                }

                // InternalCall or DllImport
                InternalConvertFromInternalCallFunction(
                    tw,
                    method);
                return;
            }

            if (!preparedFunctions.Functions.TryGetValue(method, out var preparedMethod))
            {
                return;
            }

            InternalConvertFromFunction(
                tw,
                extractContext,
                preparedMethod,
                debugInformationOption);
        }
    }
}
