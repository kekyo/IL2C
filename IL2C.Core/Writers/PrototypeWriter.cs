using System;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class PrototypeWriter
    {
        public static void ConvertToPrototype(
            CodeTextWriter tw,
            ITypeInformation type,
            Func<IFieldInformation, bool> predictField,
            Func<IMethodInformation, bool> predictMethod)
        {
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1] Types:");
            tw.SplitLine();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1-1] .NET types:");
            tw.SplitLine();

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
            tw.SplitLine();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1-2] VTable types:");
            tw.SplitLine();

            // If virtual method collection doesn't contain newslot method at this declared type:
            if (!type.NewSlotMethods.Any(method => method.DeclaringType.Equals(type)))
            {
                tw.WriteLine(
                    "typedef {0}_VTABLE_DECL__ {1}_VTABLE_DECL__;",
                    type.BaseType.MangledUniqueName,
                    type.MangledUniqueName);
            }
            // Require new vtable layout.
            else
            {
                // Important: The vtable structure definition marked for "const",
                //    because these vtables place into the ".rdata" section or same location.
                //    Many small system have very tiny space for RAM (writable memory),
                //    IL2C has to efficient memory space, vtable can place into ROM location.
                tw.WriteLine(
                    "typedef const struct {0}_VTABLE_DECL___ {0}_VTABLE_DECL__;",
                    type.MangledUniqueName);
            }

            tw.SplitLine();

            // Output value type and object reference type.
            TypeWriter.InternalConvertType(tw, type);

            if (!type.IsEnum)
            {
                var staticFields = type.Fields.
                    Where(field => field.IsStatic && predictField(field)).
                    ToArray();
                if (staticFields.Length >= 1)
                {
                    tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    tw.WriteLine("// [2-2] Static fields:");
                    tw.SplitLine();

                    foreach (var field in staticFields)
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

                tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                tw.WriteLine("// [2-3] Methods:");
                tw.SplitLine();

                var methods = type.DeclaredMethods.
                    Where(predictMethod).
                    ToArray();
                if (methods.Length >= 1)
                {
                    tw.WriteLine(
                        "// [2-4] Member methods: {0}",
                        type.FriendlyName);
                    tw.SplitLine();

                    foreach (var method in methods)
                    {
                        var scope = method.IsPublic ?
                            "public" :
                            method.IsFamily ?
                            "protected" :
                            method.IsFamilyOrAssembly ?
                            "protected internal" :
                            method.IsPrivate ?
                            "private" :
                            "internal";
                        var attribute1 = method.IsStatic ?
                            "static" :
                            method.IsVirtual ?
                            (method.IsReuseSlot ? "override" : "virtual") :
                            string.Empty;
                        var attribute2 = method.IsSealed ?
                            "sealed" :
                            method.IsExtern ?
                            "extern" :
                            string.Empty;

                        tw.WriteLine(
                            "extern /* {0} */ {1};",
                            string.Join(" ", new[] { scope, attribute1, attribute2 }.Where(a => !string.IsNullOrWhiteSpace(a))),
                            method.CLanguageFunctionPrototype);
                    }
                    tw.SplitLine();
                }
            }
        }

        public static void ConvertToPrototypes(
            CodeTextWriter tw,
            ITypeInformation[] types,
            Func<ITypeInformation, bool> predictType,
            Func<IFieldInformation, bool> predictField,
            Func<IMethodInformation, bool> predictMethod)
        {
            // Sorted by the type assignable compatibility.
            // Because these types are maybe depending another (but same as the assembly) type.
            var allTypes = types.OrderByDependant();
            var predictTypes = allTypes.Where(type => predictType(type)).ToArray();

            // Output prototypes.
            foreach (var type in predictTypes)
            {
                ConvertToPrototype(tw, type, predictField, predictMethod);
            }
        }
    }
}
