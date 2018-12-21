using System;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class PrototypeWriter
    {
        public static void InternalConvertToPrototypes(
            CodeTextWriter tw,
            ITypeInformation[] types,
            Func<ITypeInformation, bool> predictType,
            Func<IFieldInformation, bool> predictField,
            Func<IMethodInformation, bool> predictMethod)
        {
            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("extern \"C\" {");
            tw.WriteLine("#endif");
            tw.SplitLine();

            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1] Types:");
            tw.SplitLine();

            var predictTypes = types.
                Where(type => predictType(type)).
                ToArray();

            // Output prototypes.
            foreach (var type in predictTypes)
            {
                // If it applied native type attribute.
                if (type.NativeType != null)
                {
                    tw.WriteLine(
                        "typedef {0} {1};",
                        type.CLanguageNativeTypeName,
                        type.MangledUniqueName);
                }
                // Unfortunately the enum type at C language has not the underlying type.
                // IL2C emits the enum types don't use C language syntax.
                else if (type.IsEnum)
                {
                    tw.WriteLine(
                        "typedef {0} {1};",
                        type.ElementType.CLanguageTypeName,
                        type.MangledUniqueName);
                }
                // The delegate derived types are same as System.MulticastDelegate.
                else if (type.IsDelegate)
                {
                    tw.WriteLine(
                        "typedef System_MulticastDelegate {0};",
                        type.MangledUniqueName);
                }
                else
                {
                    tw.WriteLine(
                        "typedef struct {0} {0};",
                        type.MangledUniqueName);
                }
            }
            tw.SplitLine();

            // Output value type and object reference type.
            foreach (var type in predictTypes)
            {
                TypeWriter.InternalConvertType(
                    tw,
                    type);
            }
            tw.SplitLine();

            var typesExcludeEnums = predictTypes.
                Where(type => !type.IsEnum).
                ToArray();
            if (typesExcludeEnums.Any(t => t.Fields.
                Any(field => field.IsStatic && predictField(field))))
            {
                tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                tw.WriteLine("// [2-2] Static fields:");
                tw.SplitLine();

                foreach (var type in typesExcludeEnums)
                {
                    foreach (var field in type.Fields.
                        Where(field => field.IsStatic && predictField(field)))
                    {
                        if (field.NativeValue != null)
                        {
                            tw.WriteLine(
                                "#define {0} {1}",
                                field.MangledUniqueName,
                                field.CLanguageNativeSymbolName);
                        }
                        else
                        {
                            tw.WriteLine(
                            "extern {0};",
                            field.GetCLanguageStaticPrototype(false));
                        }
                    }

                    tw.SplitLine();
                }
            }

            if (typesExcludeEnums.Length >= 1)
            {
                tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                tw.WriteLine("// [2-3] Methods:");
                tw.SplitLine();

                foreach (var type in typesExcludeEnums)
                {
                    var methods = type.DeclaredMethods.
                        Where(predictMethod).
                        ToArray();

                    if (methods.Length >= 1)
                    {
                        tw.WriteLine(
                            "// [2-4] Member methods: {0}",
                            type.FriendlyName);
                        tw.SplitLine();

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
                        tw.SplitLine();
                    }
                }
            }

            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("}");
            tw.WriteLine("#endif");
            tw.SplitLine();
        }
    }
}
