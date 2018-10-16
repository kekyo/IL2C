using System;

namespace IL2C.Metadata
{
    // It's pseudo referenced-type null value used by ldnull.
    internal sealed class UntypedReferenceTypeInformation
        : ITypeInformation
    {
        public static readonly ITypeInformation UntypedReferenceType = new UntypedReferenceTypeInformation();

        private UntypedReferenceTypeInformation()
        {
        }

        public bool IsValidDefinition => false;

        public bool IsPublic => false;
        public bool IsNestedPublic => false;
        public bool IsNestedFamily => false;
        public bool IsNestedFamilyOrAssembly => false;
        public bool IsStatic => false;

        public bool IsValueType => true;
        public bool IsClass => false;
        public bool IsInterface => false;
        public bool IsEnum => false;
        public bool IsDelegate => false;
        public bool IsByReference => false;
        public bool IsPointer => false;
        public bool IsPrimitive => false;
        public bool IsNumericPrimitive => false;

        public bool IsInt32StackFriendlyType => false;
        public bool IsInt64StackFriendlyType => false;
        public bool IsFloatStackFriendlyType => false;
        public bool IsIntPtrStackFriendlyType => false;

        public bool IsVoidType => false;
        public bool IsObjectType => false;
        public bool IsValueTypeType => false;
        public bool IsDelegateType => false;

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

        public ITypeInformation BaseType => null;
        public ITypeInformation ElementType => throw new NotImplementedException();
        public ITypeInformation[] InterfaceTypes => throw new NotImplementedException();
        public ITypeInformation[] NestedTypes => throw new NotImplementedException();
        public ITypeInformation StackableType => throw new NotImplementedException();
        public IFieldInformation[] Fields => throw new NotImplementedException();
        public IMethodInformation[] DeclaredMethods => throw new NotImplementedException();
        public IMethodInformation[] OverridedMethods => throw new NotImplementedException();
        public IMethodInformation[] VirtualMethods => throw new NotImplementedException();

        public string CLanguageTypeName => "untyped_ptr";
        public string CLanguageThisTypeName => throw new NotImplementedException();
        public string MemberTypeName => throw new NotImplementedException();
        public IModuleInformation DeclaringModule => throw new NotImplementedException();
        public ITypeInformation DeclaringType => throw new NotImplementedException();

        public bool IsCLanguagePublicScope => false;
        public bool IsCLanguageLinkageScope => false;
        public bool IsCLanguageFileScope => false;

        public string UniqueName => "untyped_ptr";
        public string Name => "untyped_ptr";
        public string FriendlyName => "untyped_ptr";
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

        public bool IsAssignableFrom(ITypeInformation rhs)
        {
            throw new NotImplementedException();
        }

        public ITypeInformation MakeByReference()
        {
            throw new NotImplementedException();
        }
    }
}
