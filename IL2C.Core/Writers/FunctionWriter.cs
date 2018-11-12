using System.Linq;

using Mono.Cecil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.Writers
{
    internal static class FunctionWriter
    {
        private static void InternalConvertFromFunction(
            CodeTextWriter tw,
            IExtractContextHost extractContext,
            PreparedMethodInformation preparedMethod,
            DebugInformationOptions debugInformationOption)
        {
            var locals = preparedMethod.Method.LocalVariables;

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine(
                "// [3] {0}{1}",
                preparedMethod.Method.IsVirtual ? "Virtual: " : string.Empty,
                preparedMethod.Method.FriendlyName);

            var codeStream = preparedMethod.Method.CodeStream;

            // Write exception filters:
            if (codeStream.ExceptionHandlers.Length >= 1)
            {
                tw.WriteLine();
                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-1] Exception filters:");
                tw.WriteLine();

                for (var handlerIndex = 0;
                    handlerIndex < codeStream.ExceptionHandlers.Length;
                    handlerIndex++)
                {
                    var handler = codeStream.ExceptionHandlers[handlerIndex];

                    var filterName = string.Format(
                        "__{0}_ExceptionFilter{1}__",
                        preparedMethod.Method.CLanguageFunctionName,
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
                                    "if (il2c_isinst_unsafe(ex, {0})) return {1};",
                                    catchHandler.CatchType.MangledName,
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
                }
            }

            // Start function:
            tw.WriteLine();
            tw.WriteLine("//-------------------");
            tw.WriteLine("// [3-2] Function body:");
            tw.WriteLine();
            tw.WriteLine(preparedMethod.Method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                if (!preparedMethod.Method.IsStatic)
                {
                    tw.WriteLine("il2c_assert(this__ != NULL);");
                    tw.WriteLine();
                }

                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-3] Local variables (only value type):");
                tw.WriteLine();

                foreach (var local in preparedMethod.Method.LocalVariables.
                    Where(local => local.TargetType.IsValueType))
                {
                    tw.WriteLine(
                        "{0} {1};",
                        local.TargetType.CLanguageTypeName,
                        extractContext.GetSymbolName(local));
                }

                tw.WriteLine();
                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-4] Evaluation stacks (only value type):");
                tw.WriteLine();

                foreach (var stack in preparedMethod.Stacks.
                    Where(stack => stack.TargetType.IsValueType))
                {
                    tw.WriteLine(
                        "{0} {1};",
                        stack.TargetType.CLanguageTypeName,
                        extractContext.GetSymbolName(stack));
                }

                var objRefEntries = locals.
                    Concat(preparedMethod.Stacks).
                    Where(v => !v.TargetType.IsValueType).  // Only objref
                    ToArray();

                if (objRefEntries.Length >= 1)
                {
                    tw.WriteLine();
                    tw.WriteLine("//-------------------");
                    tw.WriteLine("// [3-5] Setup execution frame:");
                    tw.WriteLine();

                    tw.WriteLine("struct /* IL2C_EXECUTION_FRAME */");
                    tw.WriteLine("{");

                    using (var __ = tw.Shift())
                    {
                        tw.WriteLine("uint8_t objRefCount__;");
                        tw.WriteLine("uint8_t objRefRefCount__;");
                        tw.WriteLine("IL2C_EXECUTION_FRAME* pNext__;");

                        foreach (var objRefEntry in objRefEntries)
                        {
                            tw.WriteLine(
                                "{0} {1};",
                                objRefEntry.TargetType.CLanguageTypeName,
                                extractContext.GetSymbolName(objRefEntry));
                        }
                    }

                    // Important NULL assigner (p = NULL):
                    //   Because these variables are pointer (of object reference 'O' type).
                    //   So GC will traverse these variables just setup the stack frame.
                    // TODO: https://github.com/kekyo/IL2C/issues/12
                    tw.WriteLine("}} frame__ = {{ {0}, 0 }};", objRefEntries.Length);
                    tw.WriteLine();

                    tw.WriteLine("il2c_link_execution_frame(&frame__);");
                }

                tw.WriteLine();
                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-6] IL body:");
                tw.WriteLine();

                // Set symbol prefix to make valid access variables.
                using (var __ = extractContext.BeginLocalVariablePrefix(
                    local => local.TargetType.IsValueType ? null : "frame__."))
                {
                    // Construct exception handler controller.
                    var exceptionHandlerController = new ExceptionHandlerController(
                        codeStream.ExceptionHandlers,
                        (handler, handlerIndex) =>
                        {
                            // Reached try block:
                            var filterName = string.Format(
                                "__{0}_ExceptionFilter{1}__",
                                preparedMethod.Method.CLanguageFunctionName,
                                handlerIndex);
                            tw.WriteLine("il2c_try({0})", filterName);
                            tw.WriteLine("{");
                            tw.Shift();
                        },
                        (handler, handlerIndex) =>
                        {
                            // Reached try end block:
                            tw.Shift(-1);
                            tw.WriteLine("}");
                        },
                        (catchHandler, catchHandlerIndex) =>
                        {
                            switch (catchHandler.CatchHandlerType)
                            {
                                case ExceptionCatchHandlerTypes.Catch:
                                    // Reached catch block:
                                    tw.WriteLine(
                                        "il2c_catch({0}, {1})  // catch ({2})",
                                        catchHandlerIndex + 1,
                                        extractContext.GetSymbolName(preparedMethod.CatchVariables[catchHandler.CatchStart]),
                                        catchHandler.CatchType.MangledName);
                                    break;
                                case ExceptionCatchHandlerTypes.Finally:
                                    // Reached finally block:
                                    tw.WriteLine("il2c_finally");
                                    break;
                            }
                            tw.WriteLine("{");
                            tw.Shift();
                        },
                        (catchHandler, catchHandlerIndex) =>
                        {
                            // Reached catch end block:
                            tw.Shift(-1);
                            tw.WriteLine("}");
                        },
                        (handler, handlerIndex) =>
                        {
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
                                    Select(h => new { handler = h, continuationIndex = entry.Key, entry.Value.targetOffset }).
                                    // Only first item.
                                    Take(1)).
                                // ... is current handler?
                                Where(entry => entry.handler.Equals(handler)).
                                ToArray();
                            if (bindEntries.Length >= 1)
                            {
                                tw.WriteLine("il2c_leave_to");
                                tw.WriteLine("{");
                                using (var ___ = tw.Shift())
                                {
                                    foreach (var bind in bindEntries)
                                    {
                                        var labelName = preparedMethod.LabelNames[bind.targetOffset];
                                        tw.WriteLine("il2c_leave_bind({0}, {1});", bind.continuationIndex, labelName);
                                    }
                                }
                                tw.WriteLine("}");
                            }

                            // Reached end of entire try block.
                            tw.WriteLine("il2c_end_try;");
                        });

                    // Traverse code fragments.
                    var canWriteSequencePoint = true;
                    foreach (var ci in codeStream)
                    {
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

                        // 3: Write the line preprocessor directive if available.
                        if (canWriteSequencePoint && ci.Debug.Any())
                        {
                            var sp = ci.Debug.First();
                            switch (debugInformationOption)
                            {
                                case DebugInformationOptions.Full:
                                    tw.Parent.WriteLine(
                                        "#line {0} \"{1}\"",
                                        sp.Line,
                                        sp.Path.Replace("\\", "\\\\"));
                                    break;
                                case DebugInformationOptions.CommentOnly:
                                    tw.Parent.WriteLine(
                                        "/* {0}({1}): */",
                                        sp.Path.Replace("\\", "\\\\"),
                                        sp.Line);
                                    break;
                            }

                            canWriteSequencePoint = false;
                        }

                        // 4: Generate source code fragments and write.
                        if (debugInformationOption != DebugInformationOptions.None)
                        {
                            // Write debugging information.
                            tw.WriteLine(
                                "/* {0} */",
                                ci);
                        }

                        var sourceCodes = preparedMethod.Generators[ci.Offset](extractContext);
                        foreach (var sourceCode in sourceCodes)
                        {
                            // Dirty hack:
                            //   Write unlink execution frame code if cause exiting method.
                            if (sourceCode.StartsWith("return")
                                && (objRefEntries.Length >= 1))
                            {
                                tw.WriteLine(
                                    "il2c_unlink_execution_frame(&frame__);");
                            }

                            tw.WriteLine(
                                "{0};",
                                sourceCode);

                            canWriteSequencePoint = true;
                        }
                    }

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

            tw.WriteLine("}");
        }

        private static void InternalConvertFromDelegateFunction(
            CodeTextWriter tw,
            IMethodInformation method)
        {
            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [4] Abstract: {0}", method.FriendlyName);
            tw.WriteLine();

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
        }

        private static void InternalConvertFromAbstractFunction(
            CodeTextWriter tw,
            IMethodInformation method)
        {
            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [5] Abstract: {0}", method.FriendlyName);
            tw.WriteLine();

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
        }

        private static void InternalConvertFromPInvokeFunction(
            CodeTextWriter tw,
            IMethodInformation method,
            PInvokeInfo pinvokeInfo)
        {
            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [6] P/Invoke: {0}", method.FriendlyName);
            tw.WriteLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                var arguments = string.Join(
                    ", ",
                    method.Parameters.
                        Select(parameter => parameter.GetMarshaledInExpression()));

                if (method.ReturnType.IsVoidType)
                {
                    tw.WriteLine("{0}({1});", pinvokeInfo.EntryPoint, arguments);
                }
                else
                {
                    tw.WriteLine("return {0}({1});", pinvokeInfo.EntryPoint, arguments);
                }
            }

            tw.WriteLine("}");
        }

        private static void InternalConvertFromDelegateInvoker(
            CodeTextWriter tw,
            IExtractContext extractContext,
            IMethodInformation method)
        {
            if (method.Parameters.Length == 0)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid delegate invoker. Name={0}",
                    method.FriendlyName);
            }

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [11-2] Delegate invoker: {0}", method.FriendlyName);
            tw.WriteLine();

            // DIRTY:
            //   Cause undefined symbol error at C compilation if "System.Delegate" type on the mscorlib assembly
            //   contains the fields with different symbol name.

            var thisName = method.Parameters[0].ParameterName;

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            using (var _ = tw.Shift())
            {
                tw.WriteLine(
                    "il2c_assert({0} != NULL);",
                    thisName);
                tw.WriteLine(
                    "il2c_assert({0}->vptr0__ == &__System_Delegate_VTABLE__);",
                    thisName);
                tw.WriteLine(
                    "il2c_assert({0}->count__ >= 1);",
                    thisName);
                tw.WriteLine();
                if (!method.ReturnType.IsVoidType)
                {
                    tw.WriteLine(
                        "{0} result;",
                        method.ReturnType.CLanguageTypeName);
                }
                tw.WriteLine(
                    "int32_t index = 0;");
                tw.WriteLine(
                    "do",
                    thisName);
                tw.WriteLine(
                    "{");

                using (var __ = tw.Shift())
                {
                    tw.WriteLine(
                        "IL2C_METHOD_TABLE_DECL* pMethodtbl = &{0}->methodtbl__[index];",
                        thisName);

                    if (method.ReturnType.IsVoidType)
                    {
                        tw.WriteLine(
                            "if (pMethodtbl->target != NULL)");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "((void (*)(System_Object*{0}))(pMethodtbl->methodPtr))(pMethodtbl->target{1});",
                                string.Join(string.Empty, method.Parameters.
                                    Skip(1).
                                    Select(p => string.Format(", {0}", p.TargetType.CLanguageTypeName))),
                                string.Join(string.Empty, method.Parameters.
                                    Skip(1).
                                    Select(p => string.Format(", {0}", p.ParameterName))));
                        }
                        tw.WriteLine(
                            "else");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "((void (*)({0}))(pMethodtbl->methodPtr))({1});",
                                string.Join(", ", method.Parameters.
                                    Skip(1).
                                    Select(p => p.TargetType.CLanguageTypeName)),
                                string.Join(", ", method.Parameters.
                                    Skip(1).
                                    Select(p => p.ParameterName)));
                        }
                    }
                    else
                    {
                        tw.WriteLine(
                            "if (pMethodtbl->target != NULL)",
                            thisName);
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "result = (({0} (*)(System_Object*{1}))(pMethodtbl->methodPtr))(pMethodtbl->target{2});",
                                method.ReturnType.CLanguageTypeName,
                                string.Join(string.Empty, method.Parameters.
                                    Skip(1).
                                    Select(p => string.Format(", {0}", p.TargetType.CLanguageTypeName))),
                                string.Join(string.Empty, method.Parameters.
                                    Skip(1).
                                    Select(p => string.Format(", {0}", p.ParameterName))));
                        }
                        tw.WriteLine(
                            "else");
                        using (var ___ = tw.Shift())
                        {
                            tw.WriteLine(
                                "result = (({0} (*)({1}))(pMethodtbl->methodPtr))({2});",
                                method.ReturnType.CLanguageTypeName,
                                string.Join(", ", method.Parameters.
                                    Skip(1).
                                    Select(p => p.TargetType.CLanguageTypeName)),
                                string.Join(", ", method.Parameters.
                                    Skip(1).
                                    Select(p => p.ParameterName)));
                        }
                    }

                    tw.WriteLine(
                        "index++;");
                }
                tw.WriteLine(
                    "}");
                tw.WriteLine(
                    "while (index < this__->count__);");
                if (!method.ReturnType.IsVoidType)
                {
                    tw.WriteLine(
                        "return result;");
                }
            }

            tw.WriteLine("}");
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
                // DllImport
                var pinvokeInfo = method.PInvokeInfo;
                if (pinvokeInfo != null)
                {
                    InternalConvertFromPInvokeFunction(
                        tw,
                        method,
                        pinvokeInfo);
                    return;
                }

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

                throw new InvalidProgramSequenceException(
                    "Unknown internallcall method declaration. Name={0}",
                    method.FriendlyName);
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
