using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;

using IL2C.ILConveters;

namespace IL2C
{
    public sealed class ApplyContext
    {
        public readonly Stack<object> EvaluationStack = new Stack<object>();
        public readonly ParameterInfo[] Parameters;

        public ApplyContext(ParameterInfo[] parameters)
        {
            this.Parameters = parameters;
        }
    }

    internal sealed class ILData
    {
        public readonly ILConverter ILConverter;
        public readonly object Operand;

        public ILData(ILConverter ilc)
        {
            this.ILConverter = ilc;
            this.Operand = null;
        }

        public ILData(ILConverter ilc, object operand)
        {
            this.ILConverter = ilc;
            this.Operand = operand;
        }

        public string Apply(ApplyContext context)
        {
            return this.ILConverter.Apply(this.Operand, context);
        }
    }

    public static class Converter
    {
        private static readonly Dictionary<ushort, ILConverter> ilConverters;

        static Converter()
        {
            ilConverters = typeof(ILConverter)
                .Assembly
                .GetTypes()
                .Where(type => type.IsSealed && typeof(ILConverter).IsAssignableFrom(type))
                .Select(type => (ILConverter) Activator.CreateInstance(type))
                .ToDictionary(ilc => (ushort) ilc.OpCode.Value);
        }

        internal static IEnumerable<ILData> DecodeAndEnumerateOpCodes(byte[] ilBytes)
        {
            var index = 0;
            while (index < ilBytes.Length)
            {
                var byte0 = ilBytes[index++];
                if (ilConverters.TryGetValue(byte0, out var ilc) == false)
                {
                    var byte1 = ilBytes[index++];
                    var word = (ushort)(byte0 << 8 | byte1);
                    ilc = ilConverters[word];
                }

                var ilData = ilc.GetILData(ilBytes, ref index);
                yield return ilData;
            }
        }

        private static string GetCLanguageTypeName(Type type)
        {
            if (type == typeof(System.Int32))
            {
                return "int32_t";
            }
            if (type == typeof(System.Int64))
            {
                return "int64_t";
            }
            return type.FullName;
        }

        public static void Convert(TextWriter tw, MethodInfo method)
        {
            InternalConvert(
                tw,
                method.ReturnType,
                method.Name,
                method.GetParameters(),
                method.GetMethodBody());
        }

        private static void InternalConvert(
            TextWriter tw,
            Type returnType,
            string methodName,
            ParameterInfo[] parameters,
            MethodBody body)
        {
            var locals = body.LocalVariables;

            var returnTypeName =
                GetCLanguageTypeName(returnType);

            tw.WriteLine("#include <stdint.h>");

            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter =>
                    string.Format("{0} {1}", GetCLanguageTypeName(parameter.ParameterType), parameter.Name)));

            tw.WriteLine("{0} {1}({2})",
                returnTypeName,
                methodName,
                (parametersString.Length >= 1) ? parametersString : "void");
            tw.WriteLine("{");

            foreach (var local in locals)
            {
                tw.WriteLine(
                    "{0} local{1};",
                    GetCLanguageTypeName(local.LocalType),
                    local.LocalIndex);                
            }

            tw.WriteLine();

            var ilBytes = body.GetILAsByteArray();

            var context = new ApplyContext(parameters);
            foreach (var ilData in DecodeAndEnumerateOpCodes(ilBytes))
            {
                var sourceCode = ilData.Apply(context);
                if (sourceCode != null)
                {
                    tw.WriteLine(sourceCode);
                }
            }

            tw.WriteLine("}");
        }
    }
}
