////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using IL2C.Internal;
using IL2C.Metadata.Attributes;

namespace IL2C.Metadata.Specialized
{
    // This is pseudo boxed value-type used by box opcode.
    // It's explained the 'System.ValueType' by the C compiler macro named 'il2c_boxedtype(T)'.
    internal sealed class BoxedValueTypeInformation
        : ITypeInformation
    {
        private readonly ITypeInformation boxedType;

        public BoxedValueTypeInformation(ITypeInformation boxedType)
        {
            this.boxedType = boxedType;
        }

        public string MetadataTypeName => "Type";
        public string AttributeDescription => string.Empty;

        public string ScopeName => string.Empty;

        public bool IsValidDefinition => false;
        public bool IsIgnoreTranslation => false;

        public bool IsPublic => false;
        public bool IsNotPublic => false;
        public bool IsNestedPublic => false;
        public bool IsNestedPrivate => false;
        public bool IsNestedFamily => false;
        public bool IsNestedFamilyOrAssembly => false;
        public bool IsNestedFamilyAndAssembly => false;

        public bool IsAbstract => false;
        public bool IsStatic => false;
        public bool IsSealed => true;

        public bool IsValueType => false;
        public bool IsReferenceType => true;
        public bool IsClass => true;
        public bool IsInterface => false;
        public bool IsEnum => false;
        public bool IsArray => false;
        public bool IsDelegate => false;
        public bool IsException => false;
        public bool IsByReference => false;
        public bool IsPointer => false;
        public bool IsPrimitive => false;
        public bool IsIntegerPrimitive => false;
        public bool IsNumericPrimitive => false;
        public bool IsUnsigned => false;

        public bool IsInt32StackFriendlyType => false;
        public bool IsInt64StackFriendlyType => false;
        public bool IsFloatStackFriendlyType => false;
        public bool IsIntPtrStackFriendlyType => false;

        public bool IsVoidType => false;
        public bool IsObjectType => false;
        public bool IsValueTypeType => false;
        public bool IsEnumType => false;
        public bool IsDelegateType => false;
        public bool IsMulticastDelegateType => false;

        public bool IsBooleanType => false;
        public bool IsByteType => false;
        public bool IsSByteType => false;
        public bool IsInt16Type => false;
        public bool IsUInt16Type => false;
        public bool IsInt32Type => false;
        public bool IsUInt32Type => false;
        public bool IsInt64Type => false;
        public bool IsUInt64Type => false;
        public bool IsIntPtrType => false;
        public bool IsUIntPtrType => false;
        public bool IsSingleType => false;
        public bool IsDoubleType => false;
        public bool IsCharType => false;
        public bool IsStringType => false;

        public bool IsUntypedReferenceType => false;
        public bool IsBoxedType => true;

        public bool IsRequiredTraverse => false;

        public int InternalStaticSizeOfValue => 0;
        public object InternalStaticEmptyValue => null;

        public ITypeInformation BaseType => boxedType.BaseType;
        public ITypeInformation ElementType => boxedType;
        public ITypeInformation[] InterfaceTypes => boxedType.InterfaceTypes;
        public ITypeInformation[] NestedTypes => throw new NotImplementedException();

        public IFieldInformation[] Fields => throw new NotImplementedException();
        public IMethodInformation[] DeclaredMethods => throw new NotImplementedException();
        public IMethodInformation[] DeclaredAllInheritedMethods => throw new NotImplementedException();
        public IMethodInformation[] DeclaredOverrideMethods => throw new NotImplementedException();
        public IMethodInformation[] DeclaredNewslotMethods => throw new NotImplementedException();
        public IMethodInformation[] AllOverrideMethods => throw new NotImplementedException();
        public IMethodInformation[] AllNewslotMethods => throw new NotImplementedException();
        public (IMethodInformation, IMethodInformation[])[] AllCombinedMethods => throw new NotImplementedException();

        public string GetCLanguageTypeName(
            string symbolName = null, bool cArrayExpression = false, bool nativeType = false, bool isInterop = false) =>
            string.Format("{0}{1}",
                isInterop ? this.CLanguageInteropTypeName : this.CLanguageTypeName, (symbolName != null) ? (" " + symbolName) : string.Empty);

        public string CLanguageTypeName => string.Format("il2c_boxedtype({0})*", boxedType.MangledUniqueName);
        public string CLanguageInteropTypeName => string.Format("il2c_boxedtype({0})*", boxedType.MangledUniqueName);
        public string CLanguageThisTypeName => throw new NotImplementedException();
        public string CLanguageStaticSizeOfExpression => string.Format("sizeof({0})", this.CLanguageTypeName);

        public string MemberTypeName => throw new NotImplementedException();
        public IModuleInformation DeclaringModule => throw new NotImplementedException();
        public ITypeInformation DeclaringType => throw new NotImplementedException();

        public MemberScopes CLanguageMemberScope => MemberScopes.HiddenOrUnknown;

        public string UniqueName => string.Format("boxedtype<{0}>", boxedType.MangledUniqueName);
        public string Name => this.UniqueName;
        public string FriendlyName => this.UniqueName;

        public string MangledUniqueName =>
            SymbolManipulator.GetMangledName(this.UniqueName);
        public string MangledName =>
            SymbolManipulator.GetMangledName(this.Name);

        public IMetadataContext Context => throw new NotImplementedException();

        public int CompareTo(IMetadataInformation other)
        {
            throw new NotImplementedException();
        }

        public int CompareTo(object obj)
        {
            throw new NotImplementedException();
        }

        public bool Equals(IMetadataInformation other)
        {
            return object.ReferenceEquals(this, other);
        }

        public int CalculateInterfaceIndex(ITypeInformation interfaceType) =>
            boxedType.CalculateInterfaceIndex(interfaceType);

        public bool IsAssignableFrom(ITypeInformation rhs)
        {
            return rhs.Equals(boxedType);
        }

        public ITypeInformation MakeByReference() =>
            throw new NotImplementedException();
        public ITypeInformation MakeArray() =>
            throw new NotImplementedException();

        public Type ResolveToRuntimeType() =>
            throw new NotImplementedException();

        public NativeTypeAttributeInformation NativeType => null;
        public string CLanguageNativeTypeName =>
            this.GetCLanguageTypeName(null, true, true);
    }
}
