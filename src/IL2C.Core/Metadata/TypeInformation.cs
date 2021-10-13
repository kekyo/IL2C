////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Rocks;

using IL2C.Metadata.Attributes;
using IL2C.Internal;

namespace IL2C.Metadata
{
    public interface ITypeInformation : IMemberInformation
    {
        string ScopeName { get; }

        bool IsIgnoreTranslation { get; }

        bool IsPublic { get; }
        bool IsNotPublic { get; }
        bool IsNestedPublic { get; }
        bool IsNestedPrivate { get; }
        bool IsNestedFamily { get; }
        bool IsNestedFamilyOrAssembly { get; }
        bool IsNestedFamilyAndAssembly { get; }

        bool IsAbstract { get; }
        bool IsStatic { get; }
        bool IsSealed { get; }

        bool IsValueType { get; }
        bool IsReferenceType { get; }
        bool IsClass { get; }
        bool IsInterface { get; }
        bool IsEnum { get; }
        bool IsArray { get; }
        bool IsDelegate { get; }
        bool IsException { get; }
        bool IsByReference { get; }
        bool IsPointer { get; }
        bool IsPrimitive { get; }
        bool IsIntegerPrimitive { get; }
        bool IsNumericPrimitive { get; }
        bool IsUnsigned { get; }

        bool IsInt32StackFriendlyType { get; }
        bool IsInt64StackFriendlyType { get; }
        bool IsFloatStackFriendlyType { get; }
        bool IsIntPtrStackFriendlyType { get; }

        bool IsVoidType { get; }
        bool IsObjectType { get; }
        bool IsValueTypeType { get; }
        bool IsEnumType { get; }
        bool IsDelegateType { get; }
        bool IsMulticastDelegateType { get; }
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
        bool IsBoxedType { get; }

        bool IsRequiredTraverse { get; }

        int InternalStaticSizeOfValue { get; }
        object InternalStaticEmptyValue { get; }

        ITypeInformation BaseType { get; }
        ITypeInformation ElementType { get; }
        ITypeInformation[] InterfaceTypes { get; }
        ITypeInformation[] NestedTypes { get; }

        IFieldInformation[] Fields { get; }
        IMethodInformation[] DeclaredMethods { get; }
        IMethodInformation[] DeclaredAllInheritedMethods { get; }

        IMethodInformation[] DeclaredOverrideMethods { get; }
        IMethodInformation[] DeclaredNewslotMethods { get; }

        IMethodInformation[] AllOverrideMethods { get; }
        IMethodInformation[] AllNewslotMethods { get; }
        (IMethodInformation, IMethodInformation[])[] AllCombinedMethods { get; }

        string GetCLanguageTypeName(
            string symbolName = null,
            bool cArrayExpression = false,
            bool nativeType = false,
            bool isInterop = false);

        string CLanguageTypeName { get; }
        string CLanguageInteropTypeName { get; }
        string CLanguageThisTypeName { get; }
        string CLanguageStaticSizeOfExpression { get; }

        int CalculateInterfaceIndex(ITypeInformation interfaceType);

        bool IsAssignableFrom(ITypeInformation rhs);

        ITypeInformation MakeByReference();
        ITypeInformation MakeArray();

        Type ResolveToRuntimeType();

        NativeTypeAttributeInformation NativeType { get; }
        string CLanguageNativeTypeName { get; }
    }

    internal class TypeInformation
        : MemberInformation<TypeReference, TypeReference>, ITypeInformation
    {
        private static readonly ITypeInformation[] emptyTypes = new ITypeInformation[0];
        private static readonly IFieldInformation[] emptyFields = new IFieldInformation[0];
        private static readonly IMethodInformation[] emptyMethods = new IMethodInformation[0];

        private readonly Func<MemberReference, bool> memberFilter;

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
            Func<MemberReference, bool> memberFilter)
            : base(type, module)
        {
            this.memberFilter = memberFilter;
        }

        public override string MetadataTypeName => "Type";

        public string ScopeName =>
            string.Join(".", this.FriendlyName.
                Split(new[] { '.' }, StringSplitOptions.RemoveEmptyEntries).
                Reverse().
                Skip(1).
                Reverse());

        public override string MemberTypeName =>
            this.IsEnum ?
            "Enum" :
            this.IsValueType ?
                "Struct" :
                this.IsInterface ?
                    "Interface" :
                    this.IsDelegate ?
                        "Delegate" :
                        this.IsArray ?
                            "Array" :
                            "Class";

        public override string AttributeDescription
        {
            get
            {
                var scope = (this.IsPublic || this.IsNestedPublic) ?
                    "public" :
                    this.IsNestedFamily?
                    "protected" :
                    this.IsNestedFamilyOrAssembly?
                    "protected internal" :
                    this.IsNestedFamilyAndAssembly ?
                    "private protected" :
                    this.IsNestedPrivate?
                    "private" :
                    "internal";
                var attribute1 = !this.IsClass ?
                    string.Empty :
                    this.IsStatic ?
                    "static" :
                    this.IsAbstract ?
                    "abstract" :
                    this.IsSealed ?
                    "sealed" :
                    string.Empty;
                var typeName = this.IsEnum ?
                    "enum" :
                    this.IsDelegate ?
                    "delegate" :
                    this.IsInterface ?
                    "interface" :
                    this.IsValueType ?
                    "struct" :
                    this.IsPointer ?
                    "pointer" :
                    "class";

                return string.Join(" ",
                    new[] { scope, attribute1, typeName }.
                    Where(a => !string.IsNullOrWhiteSpace(a)));
            }
        }

        public bool IsIgnoreTranslation =>
            this.Definition is TypeDefinition definition &&
            definition.CustomAttributes.
            Any(ca => ca.AttributeType.FullName == "System.Runtime.InteropServices.IgnoreTranslationAttribute");

        public bool IsPublic => (this.Definition as TypeDefinition)?.IsPublic ?? false;
        public bool IsNotPublic => (this.Definition as TypeDefinition)?.IsNotPublic ?? false;
        public bool IsNestedPublic => (this.Definition as TypeDefinition)?.IsNestedPublic ?? false;
        public bool IsNestedPrivate => (this.Definition as TypeDefinition)?.IsNestedPrivate ?? false;
        public bool IsNestedFamily => (this.Definition as TypeDefinition)?.IsNestedFamily ?? false;
        public bool IsNestedFamilyOrAssembly => (this.Definition as TypeDefinition)?.IsNestedFamilyOrAssembly ?? false;
        public bool IsNestedFamilyAndAssembly => (this.Definition as TypeDefinition)?.IsNestedFamilyAndAssembly ?? false;
        public bool IsAbstract => (this.Definition as TypeDefinition)?.IsAbstract ?? false;

        public bool IsStatic
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return (definition?.IsAbstract ?? false) && (definition?.IsSealed ?? false);
            }
        }
        public bool IsSealed
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return definition?.IsSealed ?? false || this.Member.IsValueType;
            }
        }

        public bool IsValueType => this.Member.IsValueType;
        public bool IsReferenceType
        {
            get
            {
                if (this.Member.IsValueType || this.Member.IsPointer)
                {
                    return false;
                }

                if (this.Member.IsArray)
                {
                    return true;
                }

                var def = this.Definition as TypeDefinition;
                if (def == null)
                {
                    return false;
                }

                return def.IsClass || def.IsInterface;
            }
        }
        public bool IsClass =>
            !this.Member.IsValueType &&
            ((this.Definition as TypeDefinition)?.IsClass ?? false);
        public bool IsInterface =>
            !this.Member.IsValueType &&
            ((this.Definition as TypeDefinition)?.IsInterface ?? false);
        public bool IsEnum => (this.Definition as TypeDefinition)?.IsEnum ?? false;
        public bool IsArray => this.Member.IsArray;
        public bool IsDelegate => !this.Member.IsValueType && this.MetadataContext.DelegateType.IsAssignableFrom(this);
        public bool IsException => !this.Member.IsValueType && this.MetadataContext.ExceptionType.IsAssignableFrom(this);

        public bool IsByReference => this.Member.IsByReference;
        public bool IsPointer => this.Member.IsPointer;
        public bool IsPrimitive => this.Member.IsPrimitive;
        public bool IsIntegerPrimitive => this.Member.IsPrimitive &&
            (this.Equals(this.MetadataContext.ByteType) ||
             this.Equals(this.MetadataContext.SByteType) ||
             this.Equals(this.MetadataContext.Int16Type) ||
             this.Equals(this.MetadataContext.UInt16Type) ||
             this.Equals(this.MetadataContext.Int32Type) ||
             this.Equals(this.MetadataContext.UInt32Type) ||
             this.Equals(this.MetadataContext.Int64Type) ||
             this.Equals(this.MetadataContext.UInt64Type) ||
             this.Equals(this.MetadataContext.CharType));
        public bool IsNumericPrimitive => this.Member.IsPrimitive &&
            (this.IsIntegerPrimitive ||
             this.Equals(this.MetadataContext.IntPtrType) ||
             this.Equals(this.MetadataContext.UIntPtrType) ||
             this.Equals(this.MetadataContext.SingleType) ||
             this.Equals(this.MetadataContext.DoubleType));
        public bool IsUnsigned => this.Member.IsPrimitive &&
            (this.Equals(this.MetadataContext.ByteType) ||
             this.Equals(this.MetadataContext.UInt16Type) ||
             this.Equals(this.MetadataContext.UInt32Type) ||
             this.Equals(this.MetadataContext.UInt64Type) ||
             this.Equals(this.MetadataContext.UIntPtrType) ||
             this.Equals(this.MetadataContext.CharType));

        public bool IsInt32StackFriendlyType =>
            (this.IsIntegerPrimitive || this.IsBooleanType || this.IsEnum) &&
            (this.InternalStaticSizeOfValue >= 1) && (this.InternalStaticSizeOfValue <= 4);

        public bool IsInt64StackFriendlyType =>
            (this.IsIntegerPrimitive || this.IsBooleanType || this.IsEnum) &&
            (this.InternalStaticSizeOfValue >= 1) && (this.InternalStaticSizeOfValue <= 8);

        public bool IsFloatStackFriendlyType =>
            this.Equals(this.MetadataContext.SingleType) ||
            this.Equals(this.MetadataContext.DoubleType);

        public bool IsIntPtrStackFriendlyType =>
            this.IsPointer ||
            this.Equals(this.MetadataContext.IntPtrType) ||
            this.Equals(this.MetadataContext.UIntPtrType);

        public bool IsVoidType => this.Equals(this.MetadataContext.VoidType);
        public bool IsObjectType => this.Equals(this.MetadataContext.ObjectType);
        public bool IsValueTypeType => this.Equals(this.MetadataContext.ValueTypeType);
        public bool IsEnumType => this.Equals(this.MetadataContext.EnumType);
        public bool IsDelegateType => this.Equals(this.MetadataContext.DelegateType);
        public bool IsMulticastDelegateType => this.Equals(this.MetadataContext.MulticastDelegateType);

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
        public bool IsBoxedType => false;

        public bool IsRequiredTraverse =>
            (this.Member.IsValueType &&
             !this.Member.IsPrimitive && !this.Member.IsPointer && !this.IsByReference && !this.IsEnum &&
             this.Fields.Where(f => f.FieldType.FriendlyName != this.Member.FullName).Any(f => f.FieldType.IsRequiredTraverse)) ||
            this.IsReferenceType;

        private static int InternalGetStaticSizeOfValue(ITypeInformation type) =>
            // Recently, the bool type is usually defined by 1byte space type.
            (type.IsByteType || type.IsSByteType || type.IsBooleanType) ? 1 :
            (type.IsInt16Type || type.IsUInt16Type || type.IsCharType) ? 2 :
            (type.IsInt32Type || type.IsUInt32Type || type.IsSingleType) ? 4 :
            (type.IsInt64Type || type.IsUInt64Type || type.IsDoubleType || type.IsIntPtrType || type.IsUIntPtrType) ? 8 :
            type.IsEnum ? InternalGetStaticSizeOfValue(type.ElementType) :  // Enum size is element (underlying) type size.
            0;  // TODO: throw

        public int InternalStaticSizeOfValue => InternalGetStaticSizeOfValue(this);

        public object InternalStaticEmptyValue
        {
            get
            {
                if (this.IsReferenceType) return null;
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
                if (this.IsEnum) return this.ElementType.InternalStaticEmptyValue;
                return null;
            }
        }

        public ITypeInformation BaseType =>
            (this.Definition is ArrayType) ?
                this.MetadataContext.ArrayType :
                this.MetadataContext.GetOrAddType(
                    (this.Definition as TypeDefinition)?.BaseType);
        public ITypeInformation ElementType
        {
            get
            {
                var definition =
                    (this.Member.IsArray || this.Member.IsByReference || this.Member.IsPointer) ?
                        this.Member.GetElementType() :
                        this.IsEnum ?
                            ((TypeDefinition)this.Definition).GetEnumUnderlyingType() :
                            null;
                return (definition != null) ?
                    this.MetadataContext.GetOrAddType(definition) :
                    null;
            }
        }

        public ITypeInformation[] InterfaceTypes
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return (definition != null) ?
                    this.MetadataContext.GetOrAddTypes(definition.Interfaces.
                        Select(interfaceImpl => interfaceImpl.InterfaceType).
                        Where(type => memberFilter(type))) :
                    emptyTypes;
            }
        }
        public ITypeInformation[] NestedTypes
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return (definition != null) ?
                    this.MetadataContext.GetOrAddTypes(definition.NestedTypes.Where(type => memberFilter(type))) :
                    emptyTypes;
            }
        }
        public IFieldInformation[] Fields
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return (definition != null) ?
                    this.MetadataContext.GetOrAddFields(definition.Fields.Where(field => memberFilter(field))) :
                    emptyFields;
            }
        }
        public IMethodInformation[] DeclaredMethods
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                return (definition != null) ?
                    this.MetadataContext.GetOrAddMethods(definition.Methods.Where(type => memberFilter(type))) :
                    emptyMethods;
            }
        }
        public IMethodInformation[] DeclaredAllInheritedMethods =>
            ((ITypeInformation)this).
            Traverse(type => type.BaseType).
            SelectMany(type => type.DeclaredMethods).
            Where(m =>
                !m.IsConstructor &&
                !m.IsStatic &&
                (m.IsVirtual || m.IsOverridedOrImplemented)).
            Distinct(MetadataUtilities.VirtualMethodSignatureComparer).
            ToArray();

        private IEnumerable<IMethodInformation> EnumerateNewslotMethods() =>
            ((ITypeInformation)this).
                Traverse(type => type.BaseType).
                Reverse().
                SelectMany(type => type.DeclaredMethods.OrderByOverloadPriority().SelectMany(entry => entry.Value)).
                FilterByNewslots();
        private IEnumerable<IMethodInformation> EnumerateMostOverrideMethods() =>
            ((ITypeInformation)this).
                Traverse(type => type.BaseType).
                Reverse().
                SelectMany(type => type.DeclaredMethods.OrderByOverloadPriority().SelectMany(entry => entry.Value)).
                FilterAndOrderByMostOverrides();
        private IEnumerable<(IMethodInformation newslotMethod, IMethodInformation[] reuseslotMethods)> EnumerateCombinedMethods() =>
            ((ITypeInformation)this).
                Traverse(type => type.BaseType).
                Reverse().
                SelectMany(type => type.DeclaredMethods.OrderByOverloadPriority().SelectMany(entry => entry.Value)).
                OrderByMostOverrides();

        public IMethodInformation[] DeclaredOverrideMethods =>
            EnumerateMostOverrideMethods().
            // Only declared in this type.
            Where(method =>method.DeclaringType.Equals(this)).
            ToArray();
        public IMethodInformation[] DeclaredNewslotMethods =>
            EnumerateNewslotMethods().
            // Only declared in this type.
            Where(method => method.DeclaringType.Equals(this)).
            ToArray();

        public IMethodInformation[] AllOverrideMethods =>
            EnumerateMostOverrideMethods().
            ToArray();
        public IMethodInformation[] AllNewslotMethods =>
            EnumerateNewslotMethods().
            ToArray();
        public (IMethodInformation, IMethodInformation[])[] AllCombinedMethods =>
            EnumerateCombinedMethods().
            ToArray();

        public override MemberScopes CLanguageMemberScope
        {
            get
            {
                var definition = this.Definition as TypeDefinition;
                if (definition != null)
                {
                    if (definition.IsNestedPrivate)
                    {
                        return MemberScopes.File;
                    }
                    else if (definition.IsNotPublic ||
                        definition.IsNestedAssembly ||
                        definition.IsNestedFamilyAndAssembly)
                    {
                        return MemberScopes.Linkage;
                    }
                    else if (definition.IsPublic ||
                        definition.IsNestedPublic ||
                        definition.IsNestedFamily ||
                        definition.IsNestedFamilyOrAssembly)
                    {
                        return MemberScopes.Public;
                    }
                }
                return MemberScopes.HiddenOrUnknown;
            }
        }

        public string GetCLanguageTypeName(
            string symbolName = null,
            bool cArrayExpression = false,
            bool isNativeType = false,
            bool isInterop = false)
        {
            var sn = (symbolName != null) ? (" " + symbolName) : string.Empty;

            if (this.IsByReference || this.IsPointer)
            {
                return string.Format(
                    "{0}*{1}",
                    this.ElementType.GetCLanguageTypeName(null, false, isNativeType, isInterop),
                    sn);
            }

            else if (this.IsArray)
            {
                if (cArrayExpression)
                {
                    return string.Format(
                        "{0}{1}[]",
                        this.ElementType.GetCLanguageTypeName(null, true, isNativeType, isInterop),
                        sn);
                }
                else
                {
                    return string.Format(
                        "il2c_arraytype({0})*{1}",
                        this.ElementType.MangledUniqueName,
                        sn);
                }
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
            else if (isInterop && this.IsStringType)
            {
                typeName = "const wchar_t*";
            }
            else
            {
                typeName = isNativeType ?
                    (this.NativeType?.SymbolName ?? this.Name) :
                    this.MangledUniqueName;
                if (this.IsReferenceType)
                {
                    typeName += "*";
                }
            }

            Debug.Assert(typeName != null);

            return typeName + sn;
        }

        public string CLanguageTypeName =>
            this.GetCLanguageTypeName();

        public string CLanguageInteropTypeName =>
            this.GetCLanguageTypeName(null, false, false, true);

        public string CLanguageThisTypeName =>
            this.IsValueType ? (this.CLanguageTypeName + "*") : this.CLanguageTypeName;

        public string CLanguageStaticSizeOfExpression
        {
            get
            {
                // The class type contains surely one or more vptrs.
                if (this.IsClass || (this.Fields.Length >= 1))
                {
                    return string.Format("sizeof({0})", this.MangledUniqueName);
                }
                else if (this.IsInterface)
                {
                    throw new NotImplementedException();
                }
                else
                {
                    return "0";
                }
            }
        }

        public int CalculateInterfaceIndex(ITypeInformation interfaceType) =>
            ((ITypeInformation)this).
                Traverse(type => type.BaseType).
                SelectMany(type => type.InterfaceTypes).
                Distinct(). // Important operator sequence: distinct --> reverse
                Reverse().  // Because all interface types overrided by derived class type,
                Select((t, i) => new { t, i }).
                FirstOrDefault(entry => entry.t.Equals(interfaceType))?.i ?? -1;

        public bool IsAssignableFrom(ITypeInformation rhs)
        {
            if (this.Equals(rhs))
            {
                return true;
            }

            // Class <-- untyped type
            // Interface <-- untyped type
            // Pointer <-- untyped type
            if ((this.IsClass || this.IsInterface || this.IsPointer) &&
                rhs.IsUntypedReferenceType)
            {
                return true;
            }

            // BaseClass <-- DerivedClass
            // BaseClass <-- DerivedArray
            if (this.IsClass && (rhs.IsClass || rhs.IsArray))
            {
                return rhs.
                    Traverse(type => type.BaseType, true).
                    Any(this.Equals);
            }

            // BaseArray <-- DerivedArray (covariant)
            if (this.IsArray && rhs.IsArray)
            {
                return rhs.
                    Traverse(type => type.BaseType, true).
                    Any(type => type.IsArray && this.ElementType.Equals(type.ElementType));
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
                return rhs.
                    Traverse(type => type.BaseType).
                    Any(type => type.InterfaceTypes.Any(this.Equals));
            }

            // HACK: Special case lhs is runtime handles.
            if (this.MetadataContext.RuntimeFieldHandle.Equals(this) &&
                rhs.IsUntypedReferenceType)
            {
                return true;
            }

            return false;
        }

        public ITypeInformation MakeByReference() =>
            this.MetadataContext.GetOrAddType(this.Definition.MakeByReferenceType());

        public ITypeInformation MakeArray() =>
            this.MetadataContext.GetOrAddType(this.Definition.MakeArrayType());

        public Type ResolveToRuntimeType()
        {
            if (this.IsArray)
            {
                return this.ElementType.ResolveToRuntimeType().MakeArrayType();
            }
            if (this.IsByReference)
            {
                return this.ElementType.ResolveToRuntimeType().MakeByRefType();
            }
            if (this.IsPointer)
            {
                return this.ElementType.ResolveToRuntimeType().MakePointerType();
            }

            return typeof(object).Assembly.GetType(this.FriendlyName);
        }

        public NativeTypeAttributeInformation NativeType =>
            (this.Definition as TypeDefinition)?.CustomAttributes.
                Where(ca => ca.AttributeType.FullName == NativeTypeAttributeInformation.FullName).
                Select(ca => new NativeTypeAttributeInformation(ca)).
                FirstOrDefault();

        public string CLanguageNativeTypeName =>
            this.GetCLanguageTypeName(null, true, true);

        protected override TypeReference OnResolve(TypeReference member)
        {
            return (member.GetType() == typeof(TypeReference)) ? member.Resolve() : member;
        }
    }
}
