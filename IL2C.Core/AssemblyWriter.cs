using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C
{
    public enum DebugInformationOptions
    {
        None,
        CommentOnly,
        Full
    }

    public static class AssemblyWriter
    {
        private static void InternalConvertType(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            if (declaredType.IsPrimitive
                || !(declaredType.IsValueType || declaredType.IsClass || declaredType.IsInterface))
            {
                return;
            }

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// [1] {0}",
                declaredType.FriendlyName);

            // IL2C vtable model case [1]:
            //
            // public class A : IB {
            //   public int F1;
            //   public string F2;
            //   public virtual int Calc(int a, int b);
            // }
            // public interface IB {
            //   int Calc(int a, int b);
            // }
            //
            // +----------------------+
            // | IL2C_REF_HEADER      |
            // +----------------------+ <-- this__       __A_VTABLE__
            // | vptr0__              | -------------> +--------------------+
            // +----------------------+                | ILC2_RuntimeCast() |
            // | vptr_A_IB__          | ----------+    | ToString()         |
            // +----------------------+           |    | GetHashCode()      |
            // | int F1               |           |    | Finalize()         |
            // | string F2            |           |    | Equals()           |
            // +----------------------+           |    | Calc()             |
            //                                    |    +--------------------+
            //                                    |      __A_IB_VTABLE__
            //                                    +--> +------------------------------+
            //                                         | ILC2_RuntimeCast() [with AT] |
            //                                         | ToString() [with AT]         |
            //                                         | GetHashCode() [with AT]      |
            //                                         | Finalize() [with AT]         |
            //                                         | Equals() [with AT]           |
            //                                         | Calc() [with AT]             |
            //                                         +------------------------------+

            var virtualMethods = declaredType.CalculatedVirtualMethods;
            var overrideMethods = declaredType.OverrideMethods;
            var newSlotMethods = declaredType.NewSlotMethods;
            var overrideBaseMethods = declaredType.OverrideBaseMethods;

            // If virtual method collection doesn't contain newslot method at this declared type:
            if (!newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-2-1] {0} vtable layout (Same as {1})",
                    declaredType.MemberTypeName,
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "typedef __{0}_VTABLE_DECL__ __{1}_VTABLE_DECL__;",
                    declaredType.BaseType.MangledName,
                    declaredType.MangledName);
            }
            // Require new vtable layout.
            else
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-2-2] {0} vtable layout (Derived from {1})",
                    declaredType.MemberTypeName,
                    declaredType.BaseType.FriendlyName);

                // Important: The vtable structure definition marked for "const",
                //    because these vtables place into the ".rdata" section or same location.
                //    Many small system have very tiny space for RAM (writable memory),
                //    IL2C has to efficient memory space, vtable can place into ROM location.
                tw.WriteLine("typedef const struct");
                tw.WriteLine("{");
                using (var _ = tw.Shift())
                {
                    tw.WriteLine(
                        "/* internalcall */ void* (*il2c_isinst__)(void* this__, IL2C_RUNTIME_TYPE_DECL* type);");
                    foreach (var (method, overloadIndex) in virtualMethods)
                    {
                        tw.WriteLine(
                            "{0};",
                            method.GetCLanguageFunctionPrototype(overloadIndex));
                    }
                }

                tw.WriteLine(
                    "}} __{0}_VTABLE_DECL__;",
                    declaredType.MangledName);
            }

            // Delegate types doesn't write the layout structure because it's same as System.MulticastDelegate.
            if (declaredType.IsDelegate)
            {
            }
            // Write a enum:
            else if (declaredType.IsEnum)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-1] {0} layout",
                    declaredType.MemberTypeName);

                // Emit enum values:
                //   Unfortunately the enum type at C language has not the underlying type.
                //   IL2C emits the enum types using not C language syntax.
                foreach (var field in declaredType.Fields.Where(field => field.HasConstant))
                {
                    tw.WriteLine(
                        "static const {0} {1}_{2} = {3};",
                        declaredType.CLanguageTypeName,
                        declaredType.MangledName,
                        field.Name,
                        Utilities.GetCLanguageExpression(field.DeclaredValue));
                }
            }
            // Write a class/interface/struct:
            else
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-1] {0} layout",
                    declaredType.MemberTypeName);

                tw.WriteLine(
                    "struct {0}",
                    declaredType.MangledName);
                tw.WriteLine("{");

                using (var _ = tw.Shift())
                {
                    // Emit vptr (class/interface)
                    if (declaredType.IsClass || declaredType.IsInterface)
                    {
                        tw.WriteLine(
                            "__{0}_VTABLE_DECL__* vptr0__;",
                            declaredType.MangledName);
                    }

                    // TODO: If value type implements interfaces, how to assigns vptr into value type?
                    //   (We often have to resolve at enum types...)
                    var fields = declaredType.
                        Traverse(type => type.BaseType).
                        Reverse().
                        SelectMany(type =>
                        {
                            var vptrs = type.InterfaceTypes
                                .Select(interfaceType => new
                                {
                                    Name = string.Format(
                                        "vptr_{0}__",
                                        interfaceType.MangledName),
                                    TypeName = string.Format(
                                        "__{0}_VTABLE_DECL__*",
                                        interfaceType.MangledName)
                                });

                            var thisFields = type.Fields
                                .Where(field => !field.IsStatic)
                                .Select(field => new
                                {
                                    field.Name,
                                    TypeName = field.FieldType.CLanguageTypeName
                                });

                            return vptrs.Concat(thisFields);
                        }).
                        ToArray();

                    foreach (var field in fields)
                    {
                        tw.WriteLine(
                            "{0} {1};",
                            field.TypeName,
                            field.Name);
                    }
                }

                tw.WriteLine("};");
            }

            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() && !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-5-1] Vtable (Same as {0})",
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "#define __{0}_VTABLE__ __{1}_VTABLE__",
                    declaredType.MangledName,
                    declaredType.BaseType.MangledName);
            }
            // Require new vtable.
            else
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-5-2] Vtable (Derived from {0})",
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "extern __{0}_VTABLE_DECL__ __{0}_VTABLE__;",
                    declaredType.MangledName);
            }

            tw.WriteLine();
            tw.WriteLine(
                "// [1-4] Runtime type information");
            tw.WriteLine(
                "extern IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__;",
                declaredType.MangledName);
        }

        private static void InternalConvertToPrototypes(
            CodeTextWriter tw,
            ITypeInformation[] types,
            Func<ITypeInformation, bool> predictType,
            Func<IFieldInformation, bool> predictField,
            Func<IMethodInformation, bool> predictMethod)
        {
            tw.WriteLine();
            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("extern \"C\" {");
            tw.WriteLine("#endif");

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1] Types:");
            tw.WriteLine();

            // Output prototypes.
            foreach (var type in types
                .Where(type => predictType(type)))
            {
                // Unfortunately the enum type at C language has not the underlying type.
                // IL2C emits the enum types using not C language syntax.
                if (type.IsEnum)
                {
                    tw.WriteLine(
                        "typedef {0} {1};",
                        type.ElementType.CLanguageTypeName,
                        type.MangledName);
                }
                // The delegate derived types are same as System.MulticastDelegate.
                else if (type.IsDelegate)
                {
                    tw.WriteLine(
                        "typedef System_MulticastDelegate {0};",
                        type.MangledName);
                }
                else
                {
                    tw.WriteLine(
                        "typedef struct {0} {0};",
                        type.MangledName);
                }
            }

            // Output value type and object reference type.
            foreach (var type in types.
                Where(predictType))
            {
                tw.WriteLine();
                InternalConvertType(
                    tw,
                    type);
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-2] Public static fields:");

            foreach (var type in types.
                Where(type => !type.IsEnum))
            {
                tw.WriteLine();

                foreach (var field in type.Fields
                    .Where(field => field.IsPublic && field.IsStatic && predictField(field)))
                {
                    tw.WriteLine(
                        "extern {0};",
                        field.GetCLanguageStaticPrototype(false));
                }
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-3] Methods:");

            foreach (var type in types.
                Where(type => !type.IsEnum))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [2-4] Member methods: {0}",
                    type.FriendlyName);
                tw.WriteLine();

                if (!type.IsStatic)
                {
                    if (!type.IsInterface)
                    {
                        if (type.IsDelegate)
                        {
                            // TODO: Another types can maybe transfer same method.
                            tw.WriteLine(
                                "#define __{0}_IL2C_MarkHandler__ __System_MulticastDelegate_IL2C_MarkHandler__",
                                type.MangledName);
                        }
                        else
                        {
                            tw.WriteLine(
                                "extern /* internalcall */ void __{0}_IL2C_MarkHandler__({1} this__);",
                                type.MangledName,
                                type.CLanguageThisTypeName);
                        }
                    }
                }

                foreach (var method in type.DeclaredMethods.
                    Where(predictMethod))
                {
                    tw.WriteLine(
                        "extern {0}{1};",
                        method.IsStatic ?
                            "/* static */ " :
                            method.IsVirtual ?
                                (method.IsReuseSlot ? "/* override */ " : "/* virtual */ ") :
                                string.Empty,
                        method.CLanguageFunctionPrototype);
                }

                if (!type.IsStatic)
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "// [2-5] Virtual methods: {0}",
                        type.FriendlyName);
                    tw.WriteLine();

#if true
                    tw.WriteLine("/* TODO: virtual methods [2] */");
#else
                    foreach (var method in type.VirtualMethods
                        .Where(predictMethod))
                    {
                        var functionParametersDeclaration = string.Join(
                            ", ",
                            method.Parameters
                                .Select(parameter => string.Format(
                                    "/* {0} */ {1}",
                                    type.MangledName,
                                    parameter.SymbolName)));
                        tw.WriteLine(
                            "#define {0}_{1}({2}) \\",
                            type.MangledName,
                            method.CLanguageVirtualFunctionDeclarationName,
                            functionParametersDeclaration);

                        var functionParameters = string.Join(
                            ", ",
                            method.Parameters
                                .Select(parameter => parameter.SymbolName));
                        tw.WriteLine(
                            "{0}((this__)->vptr0__->{1}({2}))",
                            indent,
                            method.CLanguageVirtualFunctionDeclarationName,
                            functionParameters);
                    }
#endif
                }
            }

            tw.WriteLine();
            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("}");
            tw.WriteLine("#endif");
        }

        private sealed class ExceptionHandlerController
        {
            private sealed class ExceptionHandlerState
            {
                public readonly ExceptionHandler Handler;
                public readonly int HandlerIndex;

                private int index = -1;
                private bool inBlock = false;

                public ExceptionHandlerState(ExceptionHandler handler, int handlerIndex)
                {
                    this.Handler = handler;
                    this.HandlerIndex = handlerIndex;
                }

                public bool Update(
                    ICodeInformation code,
                    Action<ExceptionHandler, int> tryEnd,
                    Action<ExceptionCatchHandler, int> catchStart,
                    Action<ExceptionCatchHandler, int> catchEnd)
                {
                    while (true)
                    {
                        if (index == -1)
                        {
                            if (this.Handler.TryEnd == code.Offset)
                            {
                                tryEnd(this.Handler, this.HandlerIndex);
                                index = 0;
                                continue;
                            }

                            return false;
                        }
                        
                        if (index < this.Handler.CatchHandlers.Length)
                        {
                            var catchHandler = this.Handler.CatchHandlers[index];
                            if (!inBlock)
                            {
                                if (catchHandler.CatchStart == code.Offset)
                                {
                                    catchStart(catchHandler, index);
                                    inBlock = true;
                                }

                                return false;
                            }
                            else
                            {
                                if (catchHandler.CatchEnd == code.Offset)
                                {
                                    catchEnd(catchHandler, index);
                                    inBlock = false;
                                    index++;
                                    continue;
                                }

                                return false;
                            }
                        }

                        // Require emit end-try.
                        return true;
                    }
                }
            }

            private readonly Queue<(ExceptionHandler handler, int index)> queue;
            private readonly Stack<ExceptionHandlerState> stack = new Stack<ExceptionHandlerState>();

            private readonly Action<ExceptionHandler, int> tryStart;
            private readonly Action<ExceptionHandler, int> tryEnd;
            private readonly Action<ExceptionCatchHandler, int> catchStart;
            private readonly Action<ExceptionCatchHandler, int> catchEnd;
            private readonly Action<ExceptionHandler, int> finished;

            public ExceptionHandlerController(
                ExceptionHandler[] handlers,
                Action<ExceptionHandler, int> tryStart,
                Action<ExceptionHandler, int> tryEnd,
                Action<ExceptionCatchHandler, int> catchStart,
                Action<ExceptionCatchHandler, int> catchEnd,
                Action<ExceptionHandler, int> finished)
            {
                queue = new Queue<(ExceptionHandler handler, int index)>(
                    handlers.Select((handler, index) => (handler, index)));

                this.tryStart = tryStart;
                this.tryEnd = tryEnd;
                this.catchStart = catchStart;
                this.catchEnd = catchEnd;
                this.finished = finished;
            }

            public bool IsFinished => (queue.Count == 0) && (stack.Count == 0);

            public void Update(ICodeInformation code)
            {
                while (true)
                {
                    if (queue.Count >= 1)
                    {
                        var entry = queue.Peek();
                        if (entry.handler.TryStart == code.Offset)
                        {
                            tryStart(entry.handler, entry.index);
                            queue.Dequeue();
                            stack.Push(new ExceptionHandlerState(entry.handler, entry.index));
                            continue;
                        }
                    }

                    if (stack.Count >= 1)
                    {
                        var state = stack.Peek();
                        if (state.Update(code, tryEnd, catchStart, catchEnd))
                        {
                            finished(state.Handler, state.HandlerIndex);
                            stack.Pop();
                            continue;
                        }
                    }

                    break;
                }
            }
        }

        private static void InternalConvertFromFunction(
            CodeTextWriter tw,
            IExtractContext extractContext,
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
                    tw.WriteLine(
                        "il2c_assert(this__ != NULL);");
                    tw.WriteLine();
                }

                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-3] Local variables:");
                tw.WriteLine();

                // Important NULL assigner (p = NULL):
                //   Because these variables are pointer (of object reference 'O' type).
                //   So GC will traverse these variables just setup the stack frame.
                foreach (var local in preparedMethod.Method.LocalVariables)
                {
                    tw.WriteLine(
                        "{0} {1}{2};",
                        local.TargetType.CLanguageTypeName,
                        local.SymbolName,
                        local.TargetType.IsValueType ? string.Empty : " = NULL");
                }

                tw.WriteLine();
                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-4] Evaluation stacks:");
                tw.WriteLine();

                foreach (var stack in preparedMethod.Stacks)
                {
                    tw.WriteLine(
                        "{0} {1}{2};",
                        stack.TargetType.CLanguageTypeName,
                        stack.SymbolName,
                        stack.TargetType.IsValueType ? string.Empty : " = NULL");
                }

                var frameEntries = locals.
                    Concat(preparedMethod.Stacks).
                    Where(v => !v.TargetType.IsValueType).
                    ToArray();

                if (frameEntries.Length >= 1)
                {
                    tw.WriteLine();
                    tw.WriteLine("//-------------------");
                    tw.WriteLine("// [3-5] Setup stack frame:");
                    tw.WriteLine();

                    tw.WriteLine("struct /* IL2C_EXECUTION_FRAME */");
                    tw.WriteLine("{");

                    using (var __ = tw.Shift())
                    {
                        tw.WriteLine("IL2C_EXECUTION_FRAME* pNext;");
                        tw.WriteLine("uint8_t targetCount;");

                        foreach (var frameEntry in frameEntries)
                        {
                            tw.WriteLine(
                                "{0}* p{1};",
                                frameEntry.TargetType.CLanguageTypeName,
                                frameEntry.SymbolName);
                        }
                    }

                    tw.WriteLine("} __executionFrame__;");
                    tw.WriteLine();
                    tw.WriteLine("__executionFrame__.targetCount = {0};", frameEntries.Length);

                    foreach (var frameEntry in frameEntries)
                    {
                        tw.WriteLine(
                            "__executionFrame__.p{0} = &{0};",
                            frameEntry.SymbolName);
                    }

                    tw.WriteLine("il2c_link_execution_frame(&__executionFrame__);");
                }

                tw.WriteLine();
                tw.WriteLine("//-------------------");
                tw.WriteLine("// [3-6] IL body:");
                tw.WriteLine();

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
                                    preparedMethod.CatchExpressions[catchHandler.CatchStart],
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
                        // Reached finish:
                        tw.WriteLine("il2c_leave_to");
                        tw.WriteLine("{");
                        using (var __ = tw.Shift())
                        {
                            foreach (var entry in preparedMethod.ContinuationLabelNames)
                            {
                                tw.WriteLine("il2c_leave_bind({0}, {1});", entry.Key, entry.Value);
                            }
                        }
                        tw.WriteLine("}");
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
                        using (var __ = tw.Shift(-1))
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
                            && (frameEntries.Length >= 1))
                        {
                            tw.WriteLine(
                                "il2c_unlink_execution_frame(&__executionFrame__);");
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

        //private struct VirtualFunctionInformation
        //{
        //    public readonly string MangledTypeName;
        //    public readonly string CLanguageTypeName;
        //    public readonly string CLanguageVirtualFunctionDeclarationName;
        //    public readonly string CLanguageReturnTypeName;
        //    public readonly KeyValuePair<string, string>[] Parameters;

        //    public VirtualFunctionInformation(
        //        string mangledTypeName,
        //        string cLanguageTypeName,
        //        string cLanguageVirtualFunctionDeclarationName,
        //        string cLanguageReturnTypeName,
        //        KeyValuePair<string, string>[] parameters)
        //    {
        //        this.MangledTypeName = mangledTypeName;
        //        this.CLanguageTypeName = cLanguageTypeName;
        //        this.CLanguageVirtualFunctionDeclarationName = cLanguageVirtualFunctionDeclarationName;
        //        this.CLanguageReturnTypeName = cLanguageReturnTypeName;
        //        this.Parameters = parameters;
        //    }
        //}

        //private static VirtualFunctionInformation[] GetVirtualFunctions(
        //    ITypeInformation adjustorThunkTargetType,
        //    ITypeInformation delegationTargetType) =>
        //    adjustorThunkTargetType
        //        .DeclaredMethods.Where(m => m.IsVirtual)        // TODO: virtual method
        //        .Select(method => new VirtualFunctionInformation(
        //            method.DeclaringType.Equals(adjustorThunkTargetType)
        //                ? delegationTargetType.MangledName
        //                : method.DeclaringType.MangledName,
        //            method.DeclaringType.Equals(adjustorThunkTargetType)
        //                ? delegationTargetType.CLanguageTypeName
        //                : method.DeclaringType.CLanguageTypeName,
        //            method.CLanguageVirtualFunctionDeclarationName,
        //            method.ReturnType.CLanguageTypeName,
        //            method.GetParameters(adjustorThunkTargetType)
        //                .Select((parameter, index) => Utilities.KeyValue(
        //                    (index == 0) ? parameter.TargetType.CLanguageThisTypeName : parameter.TargetType.CLanguageTypeName,
        //                    parameter.SymbolName))
        //                .ToArray()))
        //        .ToArray();

        private static void InternalConvertTypeHelper(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [7] Runtime helpers:");

            // Enum is same as primitive numeric value type.
            // Delegate mark handler is same as System.MulticastDelegate.
            if (!declaredType.IsEnum && !declaredType.IsDelegate)
            {
                // Write mark handler:
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-5] GC's mark handler");
                tw.WriteLine(
                    "void __{0}_IL2C_MarkHandler__({1} this__)",
                    declaredType.MangledName,
                    declaredType.CLanguageThisTypeName);
                tw.WriteLine("{");

                using (var _ = tw.Shift())
                {
                    tw.WriteLine(
                        "il2c_assert(this__ != NULL);");

                    var fields = declaredType.Fields.
                        Where(field => !field.IsStatic && !field.FieldType.IsValueType).
                        ToArray();
                    if (fields.Length >= 1)
                    {
                        tw.WriteLine();
                        tw.WriteLine(
                            "// [7-6] Try marking each object reference fields");

                        // Write unbox function if type is value type.
                        string thisRefForMarker;
                        if (declaredType.IsValueType)
                        {
                            tw.WriteLine(
                                "{0}* pValue =",
                                declaredType.CLanguageTypeName);

                            using (var __ = tw.Shift())
                            {
                                tw.WriteLine(
                                    "il2c_unsafe_unbox__(this__, {0});",
                                    declaredType.CLanguageTypeName);
                            }

                            thisRefForMarker = "pValue";
                        }
                        else
                        {
                            thisRefForMarker = "this__";
                        }

                        // Write marker expression.
                        foreach (var field in fields)
                        {
                            tw.WriteLine(
                                "il2c_try_mark_from_handler({0}->{1});",
                                thisRefForMarker,
                                field.Name);
                        }
                    }

                    // NOTE:
                    //   Invoke base class mark handler except contains NO fields.
                    //   (ex: System.Object, System.ValueType...)
                    var baseType = declaredType.BaseType;
                    if (baseType != null)
                    {
                        if (baseType.
                            Traverse(type => type.BaseType).
                            Any(type => type.Fields.Length >= 1) == false)
                        {
                            tw.WriteLine();
                            tw.WriteLine(
                                "// [7-7] Delegate checking base types");
                            tw.WriteLine(
                                "__{0}_IL2C_MarkHandler__(({1})this__);",
                                declaredType.BaseType.MangledName,
                                declaredType.BaseType.CLanguageTypeName);
                        }
                        else
                        {
                            tw.WriteLine();
                            tw.WriteLine(
                                "/* Suppressed invoke base mark handler */");
                        }
                    }
                }

                tw.WriteLine("}");
            }

            // Write trampoline virtual functions if type is value type.
            var virtualMethods = declaredType.CalculatedVirtualMethods;
            var trampolineTargets = virtualMethods.
                Where(entry => declaredType.IsValueType && entry.method.DeclaringType.Equals(declaredType)).
                Select(entry => entry.method).
                ToArray();
            foreach (var method in trampolineTargets)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-12] Trampoline virtual function: {0}",
                    method.FriendlyName);
                tw.WriteLine(
                    "static {0} {1}_Trampoline_VFunc__(System_ValueType* this__{2})",
                    method.ReturnType.CLanguageTypeName,
                    method.CLanguageFunctionName,
                    string.Concat(method.Parameters.
                        Skip(1).
                        Select(p => string.Format(", {0} {1}", p.TargetType.CLanguageTypeName, p.SymbolName))));
                tw.WriteLine(
                    "{");

                using (var _ = tw.Shift())
                {
                    tw.WriteLine(
                        "il2c_assert(this__ != NULL);");
                    tw.WriteLine();
                    tw.WriteLine(
                        "{0}* pValue =",
                        declaredType.CLanguageTypeName);

                    using (var __ = tw.Shift())
                    {
                        tw.WriteLine(
                            "il2c_unsafe_unbox__(this__, {0});",
                            declaredType.CLanguageTypeName);
                    }

                    tw.WriteLine(
                        "return {0}(pValue{1});",
                        method.CLanguageFunctionName,
                        string.Concat(method.Parameters.
                            Skip(1).
                            Select(p => string.Format(", {0}", p.SymbolName))));    // These aren't required expression evaluation.
                }

                tw.WriteLine(
                    "}");
            }

            var overrideMethods = declaredType.OverrideMethods;
            var newSlotMethods = declaredType.NewSlotMethods;
            var overrideBaseMethods = declaredType.OverrideBaseMethods;

#if true
            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() && !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-10-1] Vtable (Not defined, same as {0})",
                    declaredType.BaseType.FriendlyName);
            }
            // Require new vtable.
            else
            {
                // Write virtual methods
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-10-2] Vtable");
                tw.WriteLine(
                    "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                    declaredType.MangledName);

                using (var _ = tw.Shift())
                {
                    tw.WriteLine(
                        "/* internalcall */ il2c_isinst__,",
                        declaredType.MangledName);

                    foreach (var (method, _) in virtualMethods)
                    {
                        // MEMO: Transfer trampoline virtual function if declared type is value type.
                        //   Because arg0 type is native value type pointer, but the virtual function requires boxed objref.
                        //   The trampoline unboxes from objref to target value type.
                        tw.WriteLine(
                            "({0}){1}{2},",
                            method.CLanguageFunctionTypePrototype,
                            method.CLanguageFunctionName,
                            (declaredType.IsValueType && method.DeclaringType.Equals(declaredType)) ? "_Trampoline_VFunc__" : string.Empty);
                    }
                }

                tw.WriteLine("};");
            }
#else
            // Write virtual methods
            tw.WriteLine();
            tw.WriteLine(
                "// [7-10] Vtable of {0}",
                declaredType.FriendlyName);
            tw.WriteLine(
                "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                declaredType.MangledName);
            tw.WriteLine(
                "{0}/* internalcall */ il2c_runtime_isinst,",
                indent,
                declaredType.MangledName);

            var virtualFunctions = GetVirtualFunctions(
                declaredType,
                declaredType);

            foreach (var function in virtualFunctions)
            {
                tw.WriteLine(
                    "{0}{1}_{2},",
                    indent,
                    function.MangledTypeName,
                    function.CLanguageVirtualFunctionDeclarationName);
            }

            tw.WriteLine("};");

            foreach (var interfaceType in declaredType.InterfaceTypes)
            {
                var interfaceVirtualFunctions = GetVirtualFunctions(
                    interfaceType,
                    declaredType);

                foreach (var function in interfaceVirtualFunctions)
                {
                    // Adjustor thunk will not invoke direct, so try to emit static function.
                    tw.WriteLine();
                    tw.WriteLine(
                        "// [7-11] Adjustor thunk: {0}.{1}",
                        function.CLanguageTypeName,
                        function.CLanguageVirtualFunctionDeclarationName);
                    tw.WriteLine(
                        "static {0} __{1}_{2}_AT_{3}__(",
                        function.CLanguageReturnTypeName,
                        function.CLanguageTypeName,
                        function.CLanguageVirtualFunctionDeclarationName,
                        interfaceType.MangledName);
                    tw.WriteLine(
                        "{0}{1})",
                        indent,
                        string.Join(
                            ", ",
                            function.Parameters.Select(parameter =>
                                string.Format(
                                    "{0} {1}",
                                    parameter.Key,
                                    parameter.Value))));
                    tw.WriteLine(
                        "{");
                    tw.WriteLine(
                        "{0}{1}__{2}_{3}__({4});",
                        indent,
                        (function.CLanguageReturnTypeName != "void") ? "return " : string.Empty,
                        function.CLanguageTypeName,
                        function.CLanguageVirtualFunctionDeclarationName,
                        string.Join(
                            ", ",
                            function.Parameters.Select((parameter, index) =>
                                (index == 0)
                                    // Adjust vptr offset with il2c_cast_from_interface() macro.
                                    ? string.Format(
                                        "({0}*)il2c_cast_from_interface({1}, {2}, {3})",
                                        function.CLanguageTypeName,
                                        declaredType.MangledName,
                                        interfaceType.MangledName,
                                        parameter.Value)
                                    : parameter.Value)));
                    tw.WriteLine(
                        "}");
                }

                tw.WriteLine();
                tw.WriteLine(
                    "// [7-12] Vtable of {0} (with adjustor thunk)",
                    interfaceType.FriendlyName);
                tw.WriteLine(
                    "__{0}_VTABLE_DECL__ __{1}_{0}_VTABLE__ = {{",
                    interfaceType.MangledName,
                    declaredType.MangledName);

                foreach (var function in interfaceVirtualFunctions)
                {
                    tw.WriteLine(
                        "{0}__{1}_{2}_AT_{3}__,",
                        indent,
                        function.CLanguageTypeName,
                        function.CLanguageVirtualFunctionDeclarationName,
                        interfaceType.MangledName);
                }

                tw.WriteLine("};");
            }
#endif

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine("// [7-8] Runtime type information");
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__ = {{",
                declaredType.MangledName);

            using (var _ = tw.Shift())
            {
                // Type name (UTF-8 string, C compiler embeds)
                tw.WriteLine(
                    "\"{0}\",",
                    declaredType.FriendlyName);

                // Type attribute flags
                tw.WriteLine(
                    "{0},",
                    declaredType.IsEnum ?
                        (declaredType.ElementType.IsUnsigned ? "IL2C_TYPE_UNSIGNED_INTEGER" : "IL2C_TYPE_INTEGER") :
                    declaredType.IsDelegate ? "IL2C_TYPE_VARIABLE" :
                    declaredType.IsValueType ? "IL2C_TYPE_VALUE" : "IL2C_TYPE_REFERENCE");

                // HACK: C language compiler causes error at the structure with empty member,
                //   so IL2C generate and use the emitted size literal instead sizeof(...) operator.
                tw.WriteLine(
                    declaredType.IsDelegate ? "0," : "sizeof({0}),",
                    declaredType.MangledName);

                // Mark handler
                if (declaredType.IsEnum)
                {
                    tw.WriteLine(
                        "/* internalcall */ IL2C_DEFAULT_MARK_HANDLER,");
                }
                else
                {
                    tw.WriteLine(
                        "/* internalcall */ (IL2C_MARK_HANDLER)__{0}_IL2C_MarkHandler__,",
                        declaredType.MangledName);
                }

                // Base (parent) type
                tw.WriteLine(
                    "il2c_typeof({0})",
                    declaredType.BaseType.MangledName);
            }

            tw.WriteLine("};");
        }

        private static void InternalConvertTypeHelperForInterface(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [8] Runtime helpers:");

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine("// [8-1] Runtime type information");

            // TODO: IL2C_RUNTIME_TYPE_DECL's some fields not used.
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__ = {{",
                declaredType.MangledName);

            using (var _ = tw.Shift())
            {
                tw.WriteLine(
                    "\"{0}\", 0, NULL",
                    declaredType.FriendlyName);
            }

            tw.WriteLine("};");
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

            var thisName = method.Parameters[0].SymbolName;

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
                                    Select(p => string.Format(", {0}", p.SymbolName))));
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
                                    Select(p => p.SymbolName)));
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
                                    Select(p => string.Format(", {0}", p.SymbolName))));
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
                                    Select(p => p.SymbolName)));
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

        internal static void InternalConvertFromMethod(
            CodeTextWriter tw,
            IExtractContext extractContext,
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

        internal static void InternalWriteHeader(
            CodeTextWriter twHeader,
            TranslateContext translateContext,
            PreparedInformations prepared,
            bool includeAssemblyHeader)
        {
            IExtractContext extractContext = translateContext;

            var assemblyName = Utilities.GetMangledName(extractContext.Assembly.FriendlyName);

            twHeader.WriteLine("#ifndef __{0}_H__", assemblyName);
            twHeader.WriteLine("#define __{0}_H__", assemblyName);
            twHeader.WriteLine();
            twHeader.WriteLine("#pragma once");
            twHeader.WriteLine();
            twHeader.WriteLine("#include <il2c.h>");

            if (includeAssemblyHeader)
            {
                twHeader.WriteLine();
                foreach (var fileName in extractContext.EnumerateRequiredIncludeFileNames())
                {
                    twHeader.WriteLine("#include <{0}>", fileName);
                }
            }

            // All types exclude privates
            InternalConvertToPrototypes(
                twHeader,
                prepared.Types,
                type => type.IsCLanguagePublicScope,
                field => field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly,
                method => (method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly) &&
                    prepared.Functions.ContainsKey(method));

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void WriteHeader(
            CodeTextWriter twHeader,
            TranslateContext translateContext,
            PreparedInformations prepared)
        {
            InternalWriteHeader(
                twHeader, translateContext, prepared, true);
        }

        internal static void WriteConstStrings(
            CodeTextWriter twSource,
            TranslateContext translateContext)
        {
            IExtractContext extractContext = translateContext;

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-1] Const strings:");
            twSource.WriteLine();

            foreach (var (symbolName, value) in extractContext.ExtractConstStrings())
            {
                var expr = Utilities.GetCLanguageExpression(value);
                twSource.WriteLine(
                    "IL2C_CONST_STRING({0}, {1});",
                    symbolName,
                    expr);
            }
        }

        internal static void WriteDeclaredValues(
            CodeTextWriter twSource,
            TranslateContext translateContext)
        {
            IExtractContext extractContext = translateContext;

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [12-1] Declared values:");

            foreach (var information in extractContext.ExtractDeclaredValues())
            {
                twSource.WriteLine();
                foreach (var declaredFields in information.DeclaredFields)
                {
                    twSource.WriteLine(
                        "// {0}",
                        declaredFields.FriendlyName);
                }

                var targetType = (information.HintTypes.Length == 1) ?
                    information.HintTypes[0] :
                    extractContext.MetadataContext.ByteType.MakeArray();
                Debug.Assert(targetType.IsArray);

                var elementType = targetType.ElementType.ResolveToRuntimeType();
                var values = Utilities.ResourceDataToSpecificArray(information.ResourceData, elementType);

                var lhs = targetType.GetCLanguageTypeName(information.SymbolName, true);
                var expr = Utilities.GetCLanguageExpression(values);
                twSource.WriteLine(
                    "static const {0} =",
                    lhs);
                using (var _ = twSource.Shift())
                {
                    twSource.WriteLine(
                        "{0};",
                        expr);
                }
            }
        }

        internal static void InternalWriteSourceCode(
            CodeTextWriter twSource,
            TranslateContext translateContext,
            PreparedInformations prepared,
            DebugInformationOptions debugInformationOption,
            bool includeAssemblyHeader)
        {
            IExtractContext extractContext = translateContext;

            if (includeAssemblyHeader)
            {
                twSource.WriteLine();

                foreach (var fileName in extractContext.EnumerateRequiredPrivateIncludeFileNames())
                {
                    twSource.WriteLine("#include \"{0}\"", fileName);
                }

                twSource.WriteLine("#include \"{0}.h\"", extractContext.Assembly.Name);
            }

            WriteConstStrings(twSource, translateContext);

            WriteDeclaredValues(twSource, translateContext);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-2] File scope prototypes:");

            // All types exclude publics and internals (for file scope prototypes)
            InternalConvertToPrototypes(
                twSource,
                prepared.Types,
                type => !type.IsCLanguagePublicScope,
                field => !(field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly),
                method => (method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly) &&
                    prepared.Functions.ContainsKey(method));

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-3] Declare static fields:");

            foreach (var type in prepared.Types.
                Where(type => !type.IsEnum))
            {
                twSource.WriteLine();

                // All static fields
                foreach (var field in type.Fields.
                    Where(field => field.IsStatic))
                {
                    twSource.WriteLine(
                        "{0};",
                        field.GetCLanguageStaticPrototype(true));
                }
            }

            foreach (var type in prepared.Types)
            {
                twSource.WriteLine();
                twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                twSource.WriteLine("// [9-4] Type: {0}", type.FriendlyName);

                // All methods and constructor exclude type initializer
                foreach (var method in type.DeclaredMethods)
                {
                    InternalConvertFromMethod(
                        twSource,
                        extractContext,
                        prepared,
                        method,
                        debugInformationOption);
                }

                if (type.IsClass || type.IsValueType)
                {
                    InternalConvertTypeHelper(
                        twSource,
                        type);
                }
                else if (type.IsInterface)
                {
                    InternalConvertTypeHelperForInterface(
                        twSource,
                        type);
                }
            }
        }

        public static void WriteSourceCode(
            CodeTextWriter twSource,
            TranslateContext translateContext,
            PreparedInformations prepared,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.Full)
        {
            InternalWriteSourceCode(
                twSource, translateContext, prepared, debugInformationOption, true);
        }
    }
}
