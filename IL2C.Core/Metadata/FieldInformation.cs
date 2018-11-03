using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IFieldInformation : IMemberInformation
    {
        bool IsPublic { get; }
        bool IsFamily { get; }
        bool IsFamilyOrAssembly { get; }

        bool IsStatic { get; }
        bool HasConstant { get; }

        ITypeInformation FieldType { get; }
        object DeclaredValue { get; }

        string GetCLanguageStaticPrototype(bool requireInitializerExpression);
    }

    internal sealed class FieldInformation
        : MemberInformation<FieldReference, FieldDefinition>
        , IFieldInformation
    {
        public FieldInformation(FieldReference field, ModuleInformation module)
            : base(field, module)
        {
        }

        public override string MetadataTypeName => "Field";

        public override string MemberTypeName => this.IsStatic
            ? "Static field"
            : "Field";

        public bool IsPublic => this.Definition.IsPublic;
        public bool IsFamily => this.Definition.IsFamily;
        public bool IsFamilyOrAssembly => this.Definition.IsFamilyOrAssembly;

        public bool IsStatic => this.Definition.IsStatic;
        public bool HasConstant => this.Definition.HasConstant;

        public ITypeInformation FieldType =>
            this.MetadataContext.GetOrAddType(this.Member.FieldType);

        public object DeclaredValue =>
            this.HasConstant ?
                this.Definition.Constant :
                this.Definition.InitialValue;

        public string GetCLanguageStaticPrototype(bool requireInitializerExpression)
        {
            var initializer = requireInitializerExpression ?
                string.Empty :
                string.Format(
                    " = {0}",
                    Utilities.ToCLanguageExpression(this.DeclaredValue ?? 0));

            return string.Format(
                "{0} {1}{2}",
                this.FieldType.CLanguageTypeName,
                this.MangledName,
                initializer);
        }

        public override bool IsCLanguagePublicScope => this.Definition.IsPublic;
        public override bool IsCLanguageLinkageScope => !this.Definition.IsPublic && !this.Definition.IsPrivate;
        public override bool IsCLanguageFileScope => this.Definition.IsPrivate;

        protected override FieldDefinition OnResolve(FieldReference member)
        {
            return member.Resolve();
        }
    }
}
