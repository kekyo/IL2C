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

            // Output prototypes.
            foreach (var type in types.
                Where(type => predictType(type)))
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
            tw.SplitLine();

            // Output value type and object reference type.
            foreach (var type in types.
                Where(predictType))
            {
                TypeWriter.InternalConvertType(
                    tw,
                    type);
            }
            tw.SplitLine();

            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-2] Public static fields:");
            tw.SplitLine();

            foreach (var type in types.
                Where(type => !type.IsEnum))
            {
                foreach (var field in type.Fields
                    .Where(field => field.IsPublic && field.IsStatic && predictField(field)))
                {
                    tw.WriteLine(
                        "extern {0};",
                        field.GetCLanguageStaticPrototype(false));
                }

                tw.SplitLine();
            }

            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-3] Methods:");
            tw.SplitLine();

            foreach (var type in types.
                Where(type => !type.IsEnum))
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

            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("}");
            tw.WriteLine("#endif");
            tw.SplitLine();
        }
    }
}
