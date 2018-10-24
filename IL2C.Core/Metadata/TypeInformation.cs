using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Rocks;

namespace IL2C.Metadata
{
    public interface ITypeInformation : IMemberInformation
    {
        bool IsValidDefinition { get; }

        bool IsPublic { get; }
        bool IsNestedPublic { get; }
        bool IsNestedFamily { get; }
        bool IsNestedFamilyOrAssembly { get; }

        bool IsStatic { get; }

        bool IsValueType { get; }
        bool IsClass { get; }
        bool IsInterface { get; }
        bool IsEnum { get; }
        bool IsArray { get; }
        bool IsDelegate { get; }
        bool IsByReference { get; }
        bool IsPointer { get; }
        bool IsPrimitive { get; }
        bool IsNumericPrimitive { get; }

        bool IsInt32StackFriendlyType { get; }
        bool IsInt64StackFriendlyType { get; }
        bool IsFloatStackFriendlyType { get; }
        bool IsIntPtrStackFriendlyType { get; }

        bool IsVoidType { get; }
        bool IsObjectType { get; }
        bool IsValueTypeType { get; }
        bool IsDelegateType { get; }
        bool IsBooleanType { get; }
        bool IsByteType { get; }
        bool IsSByteType { get; }
        bool IsInt16Type { get; }
        bool IsUInt16Type { get; }
        bool IsInt32Type { get; }
        bool IsUInt32Type { get; }
        bool IsInt64Type { get; }
        bool IsUInt64Type { get; }
        bool IsIntPtrType { get; }
        bool IsUIntPtrType { get; }
        bool IsSingleType { get; }
        bool IsDoubleType { get; }
        bool IsCharType { get; }
        bool IsStringType { get; }

        bool IsUntypedReferenceType { get; }

        int SizeOfValue { get; }
        object EmptyValue { get; }

        ITypeInformation BaseType { get; }
        ITypeInformation ElementType { get; }
        ITypeInformation[] InterfaceTypes { get; }
        ITypeInformation[] NestedTypes { get; }

        IFieldInformation[] Fields { get; }
        IMethodInformation[] DeclaredMethods { get; }

        string CLanguageTypeName { get; }
        string CLanguageThisTypeName { get; }

        bool IsAssignableFrom(ITypeInformation rhs);

        ITypeInformation MakeByReference();
    }

    internal sealed class TypeInformation
        : MemberInformation<TypeReference, TypeReference>, ITypeInformation
    {
        private readonly Lazy<TypeInformation> baseType;
        private readonly Lazy<TypeInformation> elementType;
        private readonly Lazy<TypeInformation[]> interfaceTypes;
        private readonly Lazy<TypeInformation[]> nestedTypes;
        private readonly Lazy<FieldInformation[]> fields;
        private readonly Lazy<MethodInformation[]> declaredMethods;
        private readonly Lazy<IMethodInformation[]> virtualMethods;
        private readonly Lazy<string> cLanguageTypeName;

        public TypeInformation(TypeReference type, ModuleInformation module)
            : this(type, module, _ => true)
        {
        }

        internal TypeInformation(
            TypeReference type, ModuleInformation module,
            HashSet<string> validMethods)
            : this(type, module, m => validMethods.Contains(m.Name))
        {
        }

        internal TypeInformation(
            TypeReference type, ModuleInformation module,
            Func<MethodDefinition, bool> filterMethod)
            : base(type, module)
        {
            baseType = this.MetadataContext.LazyGetOrAddMember(
                () => (this.Definition as TypeDefinition)?.BaseType,
                baseType => new TypeInformation(baseType, module));

            elementType = this.MetadataContext.LazyGetOrAddMember(
                () => this.Member.GetElementType(),
                elementType => new TypeInformation(elementType, module));

            interfaceTypes = this.MetadataContext.LazyGetOrAddMembers(
                () => (this.Definition as TypeDefinition)?.Interfaces.Select(interfaceImpl => interfaceImpl.InterfaceType),
                interfaceType => new TypeInformation(interfaceType, module));

            nestedTypes = this.MetadataContext.LazyGetOrAddMembers(
                () => (this.Definition as TypeDefinition)?.NestedTypes,
                nestedType => new TypeInformation(nestedType, module));

            fields = this.MetadataContext.LazyGetOrAddMembers(
                () => (this.Definition as TypeDefinition)?.Fields,
                field => new FieldInformation(field, module));

            declaredMethods = this.MetadataContext.LazyGetOrAddMembers(
                () => (this.Definition as TypeDefinition)?.Methods.Where(filterMethod),
                method => new MethodInformation(method, module));

            virtualMethods = Lazy.Create(
                () => this.DeclaredMethods.Where(method => method.IsVirtual).ToArray());

            cLanguageTypeName = Lazy.Create(
                () =>
                {
                    if (this.IsByReference || this.IsPointer)
                    {
                        return string.Format(
                            "{0}*",
                            this.ElementType.CLanguageTypeName);
                    }

                    string typeName = null;
                    if (this.Member.IsPrimitive)
                    {
                        if (this.IsBooleanType)
                        {
                            typeName = "bool";
                        }
                        else if (this.IsByteType)
                        {
                            typeName = "uint8_t";
                        }
                        else if (this.IsSByteType)
                        {
                            typeName = "int8_t";
                        }
                        else if (this.IsInt16Type)
                        {
                            typeName = "int16_t";
                        }
                        else if (this.IsUInt16Type)
                        {
                            typeName = "uint16_t";
                        }
                        else if (this.IsInt32Type)
                        {
                            typeName = "int32_t";
                        }
                        else if (this.IsUInt32Type)
                        {
                            typeName = "uint32_t";
                        }
                        else if (this.IsInt64Type)
                        {
                            typeName = "int64_t";
                        }
                        else if (this.IsUInt64Type)
                        {
                            typeName = "uint64_t";
                        }
                        else if (this.IsIntPtrType)
                        {
                            typeName = "intptr_t";
                        }
                        else if (this.IsUIntPtrType)
                        {
                            typeName = "uintptr_t";
                        }
                        else if (this.IsSingleType)
                        {
                            typeName = "float";
                        }
                        else if (this.IsDoubleType)
                        {
                            typeName = "double";
                        }
                        else if (this.IsCharType)
                        {
                            typeName = "wchar_t";
                        }
                    }
                    else if (this.IsVoidType)
                    {
                        typeName = "void";
                    }
                    else
                    {
                        typeName = this.MangledName;
                        if (!this.IsValueType)
                        {
                            typeName += "*";
                        }
                    }

                    Debug.Assert(typeName != null);

                    return typeName;
                });
        }

        public override string MetadataTypeName => "Type";

        public override string MemberTypeName => this.IsEnum
            ? "Enum"
            : this.IsValueType
                ? "Struct"
                : this.IsInterface
                    ? "Interface"
                    : "Class";

        public bool IsValidDefinition
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                if (definition != null)
                {
                    return (((this.Member.IsValueType || definition.IsClass)
                        && (definition.BaseType != null))
                        || definition.IsInterface)
                        && (this.Member.Name != "<Module>");
                }
                else
                {
                    return true;
                }
            }
        }

        public bool IsPublic => (this.Definition as TypeDefinition)?.IsPublic ?? false;
        public bool IsNestedPublic => (this.Definition as TypeDefinition)?.IsNestedPublic ?? false;
        public bool IsNestedFamily => (this.Definition as TypeDefinition)?.IsNestedFamily ?? false;
        public bool IsNestedFamilyOrAssembly => (this.Definition as TypeDefinition)?.IsNestedFamilyOrAssembly ?? false;

        public bool IsStatic
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return (definition?.IsAbstract ?? false) && (definition?.IsSealed ?? false);
            }
        }

        public bool IsValueType => this.Member.IsValueType;
        public bool IsClass => !this.Member.IsValueType && ((this.Definition as TypeDefinition)?.IsClass ?? false);
        public bool IsInterface => (this.Definition as TypeDefinition)?.IsInterface ?? false;
        public bool IsEnum => (this.Definition as TypeDefinition)?.IsEnum ?? false;
        public bool IsArray => (this.Definition as TypeDefinition)?.IsArray ?? false;
        public bool IsDelegate => this.MetadataContext.DelegateType.IsAssignableFrom(this);
        public bool IsByReference => this.Member.IsByReference;
        public bool IsPointer => this.Member.IsPointer;
        public bool IsPrimitive => this.Member.IsPrimitive;
        public bool IsNumericPrimitive => this.Member.IsPrimitive
            && (this.Equals(this.MetadataContext.ByteType)
                || this.Equals(this.MetadataContext.SByteType)
                || this.Equals(this.MetadataContext.Int16Type)
                || this.Equals(this.MetadataContext.UInt16Type)
                || this.Equals(this.MetadataContext.Int32Type)
                || this.Equals(this.MetadataContext.UInt32Type)
                || this.Equals(this.MetadataContext.Int64Type)
                || this.Equals(this.MetadataContext.UInt64Type)
                || this.Equals(this.MetadataContext.IntPtrType)
                || this.Equals(this.MetadataContext.UIntPtrType)
                || this.Equals(this.MetadataContext.SingleType)
                || this.Equals(this.MetadataContext.DoubleType)
                || this.Equals(this.MetadataContext.CharType));

        public bool IsInt32StackFriendlyType =>
            this.Equals(this.MetadataContext.ByteType)
            || this.Equals(this.MetadataContext.SByteType)
            || this.Equals(this.MetadataContext.Int16Type)
            || this.Equals(this.MetadataContext.UInt16Type)
            || this.Equals(this.MetadataContext.Int32Type)
            || this.Equals(this.MetadataContext.UInt32Type)
            || this.Equals(this.MetadataContext.BooleanType)
            || this.Equals(this.MetadataContext.CharType);

        public bool IsInt64StackFriendlyType =>
            this.Equals(this.MetadataContext.ByteType)
            || this.Equals(this.MetadataContext.SByteType)
            || this.Equals(this.MetadataContext.Int16Type)
            || this.Equals(this.MetadataContext.UInt16Type)
            || this.Equals(this.MetadataContext.Int32Type)
            || this.Equals(this.MetadataContext.UInt32Type)
            || this.Equals(this.MetadataContext.Int64Type)
            || this.Equals(this.MetadataContext.UInt64Type)
            || this.Equals(this.MetadataContext.BooleanType)
            || this.Equals(this.MetadataContext.CharType);

        public bool IsFloatStackFriendlyType =>
            this.Equals(this.MetadataContext.SingleType)
            || this.Equals(this.MetadataContext.DoubleType);

        public bool IsIntPtrStackFriendlyType =>
            this.IsPointer
            || this.Equals(this.MetadataContext.IntPtrType)
            || this.Equals(this.MetadataContext.UIntPtrType);

        public bool IsVoidType => this.Equals(this.MetadataContext.VoidType);
        public bool IsObjectType => this.Equals(this.MetadataContext.ObjectType);
        public bool IsValueTypeType => this.Equals(this.MetadataContext.ValueTypeType);
        public bool IsDelegateType => this.Equals(this.MetadataContext.DelegateType);

        public bool IsByteType => this.Equals(this.MetadataContext.ByteType);
        public bool IsSByteType => this.Equals(this.MetadataContext.SByteType);
        public bool IsInt16Type => this.Equals(this.MetadataContext.Int16Type);
        public bool IsUInt16Type => this.Equals(this.MetadataContext.UInt16Type);
        public bool IsInt32Type => this.Equals(this.MetadataContext.Int32Type);
        public bool IsUInt32Type => this.Equals(this.MetadataContext.UInt32Type);
        public bool IsInt64Type => this.Equals(this.MetadataContext.Int64Type);
        public bool IsUInt64Type => this.Equals(this.MetadataContext.UInt64Type);
        public bool IsIntPtrType => this.Equals(this.MetadataContext.IntPtrType);
        public bool IsUIntPtrType => this.Equals(this.MetadataContext.UIntPtrType);
        public bool IsSingleType => this.Equals(this.MetadataContext.SingleType);
        public bool IsDoubleType => this.Equals(this.MetadataContext.DoubleType);
        public bool IsCharType => this.Equals(this.MetadataContext.CharType);
        public bool IsStringType => this.Equals(this.MetadataContext.StringType);
        public bool IsBooleanType => this.Equals(this.MetadataContext.BooleanType);

        public bool IsUntypedReferenceType => false;

        public int SizeOfValue =>
            // Recently, the bool type is usually defined by 1byte space type.
            (this.IsByteType || this.IsSByteType || this.IsBooleanType) ? 1 :
            (this.IsInt16Type || this.IsUInt16Type || this.IsCharType) ? 2 :
            (this.IsInt32Type || this.IsUInt32Type || this.IsSingleType) ? 4 :
            (this.IsInt64Type || this.IsUInt64Type || this.IsDoubleType || this.IsIntPtrType || this.IsUIntPtrType) ? 8 :
            0;
        public object EmptyValue
        {
            get
            {
                if (this.IsClass || this.IsInterface) return null;
                if (this.IsByReference || this.IsPointer) return null;
                if (this.IsByteType) return (byte)0;
                if (this.IsSByteType) return (sbyte)0;
                if (this.IsInt16Type) return (short)0;
                if (this.IsUInt16Type) return (ushort)0;
                if (this.IsInt32Type) return (int)0;
                if (this.IsUInt32Type) return (uint)0;
                if (this.IsInt64Type) return (long)0;
                if (this.IsUInt64Type) return (ulong)0;
                if (this.IsIntPtrType) return IntPtr.Zero;
                if (this.IsUIntPtrType) return UIntPtr.Zero;
                if (this.IsSingleType) return (float)0;
                if (this.IsDoubleType) return (double)0;
                if (this.IsCharType) return (char)0;
                if (this.IsBooleanType) return false;
                return null;
            }
        }

        public ITypeInformation BaseType => baseType.Value;
        public ITypeInformation ElementType => elementType.Value;
        public ITypeInformation[] InterfaceTypes => interfaceTypes.Value;
        public ITypeInformation[] NestedTypes => nestedTypes.Value;

        public IFieldInformation[] Fields => fields.Value;
        public IMethodInformation[] DeclaredMethods => declaredMethods.Value;

        public override bool IsCLanguagePublicScope
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                if (definition != null)
                {
                    return definition.IsPublic || definition.IsNestedPublic
                        || definition.IsNestedFamily || definition.IsNestedFamilyOrAssembly;
                }
                else
                {
                    return false;
                }
            }
        }

        public override bool IsCLanguageLinkageScope
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                if (definition != null)
                {
                    return definition.IsNotPublic || definition.IsNestedAssembly;
                }
                else
                {
                    return false;
                }
            }
        }
            
        public override bool IsCLanguageFileScope =>
            (this.Definition as TypeDefinition)?.IsNestedPrivate ?? false;

        public string CLanguageTypeName => cLanguageTypeName.Value;
        public string CLanguageThisTypeName =>
            this.IsValueType ? (this.CLanguageTypeName + "*") : this.CLanguageTypeName;

        public bool IsAssignableFrom(ITypeInformation rhs)
        {
            if (this.Equals(rhs))
            {
                return true;
            }

            // BaseClass <-- DerivedClass
            if (this.IsClass && rhs.IsClass)
            {
                return rhs
                    .Traverse(type => type.BaseType, true)
                    .Any(this.Equals);
            }

            // System.Object <-- Any
            if (this.IsObjectType)
            {
                return true;
            }

            // System.ValueType <-- ValueType
            if (this.IsValueTypeType && rhs.IsValueType)
            {
                return true;
            }

            // IBase <-- DerivedClass
            // IBase <-- IDerived
            if (this.IsInterface)
            {
                return rhs.InterfaceTypes.Any(this.Equals);
            }

            return false;
        }

        public ITypeInformation MakeByReference()
        {
            return this.MetadataContext.GetOrAddMember(
                this.Definition.MakeByReferenceType(),
                type => new TypeInformation(type, this.DeclaringModule));
        }

        protected override void ResolveLazyValues()
        {
            var dummy1 = baseType.Value;
            var dummy2 = elementType.Value;
            var dummy3 = interfaceTypes.Value;
            var dummy4 = nestedTypes.Value;
            var dummy5 = fields.Value;
            var dummy6 = declaredMethods.Value;
            var dummy8 = virtualMethods.Value;
            var dummy9 = cLanguageTypeName.Value;
            base.ResolveLazyValues();
        }

        protected override TypeReference OnResolve(TypeReference member)
        {
            return (member.GetType() == typeof(TypeReference)) ? member.Resolve() : member;
        }
    }
}
