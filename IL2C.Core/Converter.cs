using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

namespace IL2C
{
    public static class Converter
    {
        internal static IEnumerable<ILData> DecodeAndEnumerateOpCodes(DecodeContext context)
        {
            while (true)
            {
                var labelName = context.MakeLabel();
                if (context.TryDecode(out var ilc) == false)
                {
                    break;
                }

                var operand = ilc.DecodeOperand(context);
                yield return new ILData(labelName, ilc, operand);

                if (ilc.IsEndOfPath)
                {
                    yield break;
                }
            }
        }

        public static void Convert(TextWriter tw, MethodInfo method, string indent)
        {
            InternalConvert(
                tw,
                method.ReturnType,
                method.Name,
                method.GetParameters(),
                method.GetMethodBody(),
                indent);
        }

        private static void InternalConvert(
            TextWriter tw,
            Type returnType,
            string methodName,
            ParameterInfo[] parameters,
            MethodBody body,
            string indent)
        {
            var locals = body.LocalVariables;

            var returnTypeName =
                Utilities.GetCLanguageTypeName(returnType);

            tw.WriteLine("#include <stdint.h>");

            tw.WriteLine();

            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    Utilities.GetCLanguageTypeName(parameter.ParameterType),
                    parameter.Name)));

            tw.WriteLine("{0} {1}({2})",
                returnTypeName,
                methodName,
                (parametersString.Length >= 1) ? parametersString : "void");
            tw.WriteLine("{");

            foreach (var local in locals)
            {
                tw.WriteLine(
                    "{0}{1} local{2};",
                    indent,
                    Utilities.GetCLanguageTypeName(local.LocalType),
                    local.LocalIndex);                
            }

            tw.WriteLine();

            var decodeContext = new DecodeContext(
                methodName, parameters, locals, body.GetILAsByteArray());

            var bodySourceCode = new List<string>();
            while (decodeContext.TryDequeueNextPath())
            {
                bodySourceCode.AddRange(
                    from ilData in DecodeAndEnumerateOpCodes(decodeContext)
                    let sourceCode = ilData.ILConverter.Apply(ilData.Operand, decodeContext)
                    where sourceCode != null
                    select string.Format("{0}: {1};", ilData.LabelName, sourceCode));
            }

            foreach (var si in decodeContext.ExtractStacks())
            {
                tw.WriteLine(
                    "{0}{1} {2};",
                    indent,
                    Utilities.GetCLanguageTypeName(si.TargetType),
                    si.SymbolName);
            }

            tw.WriteLine();

            foreach (var sourceCode in bodySourceCode)
            {
                tw.WriteLine(indent + sourceCode);
            }

            tw.WriteLine("}");
        }
    }
}
