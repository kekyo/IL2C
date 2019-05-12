using System;

using IL2C.Metadata.Attributes;

namespace IL2C.Metadata.Specialized
{
    // This is pseudo referenced-type null value used by ldnull opcode.
    // It's explained the 'intptr_t' by the C compiler macro named 'untyped_ptr'.
    // Because the ldnull opcode pushes 'null' value for the anonymous objref type 'O'.
    internal sealed class UntypedReferenceTypeInformation
        : ITypeInformation
    {
        public static readonly ITypeInformation UntypedReferenceType = new UntypedReferenceTypeInformation();

        private UntypedReferenceTypeInformation()
        {
        }

        public string MetadataTypeName => "Type";
        public string AttributeDescription => string.Empty;

        public string ScopeName => string.Empty;

        public bool IsValidDefinition => false;

        public bool IsPublic => false;
        public bool IsNotPublic => false;
        public bool IsNestedPublic => false;
        public bool IsNestedPrivate => false;
        public bool IsNestedFamily => false;
        public bool IsNestedFamilyOrAssembly => false;
        public bool IsNestedFamilyAndAssembly => false;

        public bool IsAbstract => false;
        public bool IsStatic => false;
        public bool IsSealed => false;

        public bool IsValueType => false;
        public bool IsReferenceType => false;
        public bool IsClass => false;
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

        public bool IsUntypedReferenceType => true;
        public bool IsBoxedType => false;

        public bool IsRequiredTraverse => false;

        public int InternalStaticSizeOfValue => 0;
        public object InternalStaticEmptyValue => null;

        public ITypeInformation BaseType => null;
        public ITypeInformation ElementType => throw new NotImplementedException();
        public ITypeInformation[] InterfaceTypes => throw new NotImplementedException();
        public ITypeInformation[] NestedTypes => throw new NotImplementedException();

        public IFieldInformation[] Fields => throw new NotImplementedException();
        public IMethodInformation[] DeclaredMethods => throw new NotImplementedException();
        public IMethodInformation[] DeclaredAllInheritedMethods => throw new NotImplementedException();
        public (IMethodInformation method, int overloadIndex)[] CalculatedVirtualMethods => throw new NotImplementedException();
        public IMethodInformation[] DeclaredOverrideMethods => throw new NotImplementedException();
        public IMethodInformation[] DeclaredNewslotMethods => throw new NotImplementedException();
        public IMethodInformation[] AllOverrideMethods => throw new NotImplementedException();
        public IMethodInformation[] AllNewslotMethods => throw new NotImplementedException();
        public (IMethodInformation, IMethodInformation[])[] AllCombinedMethods => throw new NotImplementedException();

        public string GetCLanguageTypeName(string symbolName = null, bool cArrayExpression = false, bool nativeType = false) =>
            "untyped_ptr" + ((symbolName != null) ? (" " + symbolName) : string.Empty);

        public string CLanguageTypeName => "untyped_ptr";
        public string CLanguageThisTypeName => throw new NotImplementedException();
        public string CLanguageStaticSizeOfExpression => "sizeof(untyped_ptr)";

        public string MemberTypeName => throw new NotImplementedException();
        public IModuleInformation DeclaringModule => throw new NotImplementedException();
        public ITypeInformation DeclaringType => throw new NotImplementedException();

        public MemberScopes CLanguageMemberScope => MemberScopes.HiddenOrUnknown;
        public bool IsCLanguagePublicScope => false;
        public bool IsCLanguageLinkageScope => false;
        public bool IsCLanguageFileScope => false;

        public string UniqueName => "untyped_ptr";
        public string Name => "untyped_ptr";
        public string FriendlyName => "untyped_ptr";
        public string MangledUniqueName => "untyped_ptr";
        public string MangledName => "untyped_ptr";

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
            throw new NotImplementedException();

        public bool IsAssignableFrom(ITypeInformation rhs)
        {
            // untyped type <-- Class
            // untyped type <-- Interface
            // untyped type <-- ByReference (special case: this direction is valid, but reverse direction is invalid)
            // untyped type <-- Pointer
            return rhs.IsClass || rhs.IsInterface || rhs.IsByReference || rhs.IsPointer;
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
