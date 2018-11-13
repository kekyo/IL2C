using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class TypeWriter
    {
        public static void InternalConvertType(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            if (declaredType.IsPrimitive || !(declaredType.IsValueType || declaredType.IsReferenceType))
            {
                return;
            }

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// [1] {0}",
                declaredType.FriendlyName);
            tw.SplitLine();

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
                tw.WriteLine(
                    "// [1-2-1] {0} vtable layout (Same as {1})",
                    declaredType.MemberTypeName,
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "typedef __{0}_VTABLE_DECL__ __{1}_VTABLE_DECL__;",
                    declaredType.BaseType.MangledName,
                    declaredType.MangledName);
                tw.SplitLine();
            }
            // Require new vtable layout.
            else
            {
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
                tw.SplitLine();
            }

            // Delegate types doesn't write the layout structure because it's same as System.MulticastDelegate.
            if (declaredType.IsDelegate)
            {
            }
            // Write a enum:
            else if (declaredType.IsEnum)
            {
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
                tw.SplitLine();
            }
            // Write a class/interface/struct:
            else
            {
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
                tw.SplitLine();
            }

            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() && !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine(
                    "// [1-5-1] Vtable (Same as {0})",
                    declaredType.BaseType.FriendlyName);
                tw.WriteLine(
                    "#define __{0}_VTABLE__ __{1}_VTABLE__",
                    declaredType.MangledName,
                    declaredType.BaseType.MangledName);
                tw.SplitLine();
            }
            // Require new vtable.
            else
            {
                tw.WriteLine(
                    "// [1-5-2] Vtable (Derived from {0})",
                    declaredType.BaseType.FriendlyName);
                tw.WriteLine(
                    "extern __{0}_VTABLE_DECL__ __{0}_VTABLE__;",
                    declaredType.MangledName);
                tw.SplitLine();
            }

            tw.WriteLine(
                "// [1-4] Runtime type information");
            tw.WriteLine(
                "extern IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__;",
                declaredType.MangledName);
            tw.SplitLine();
        }
    }
}
