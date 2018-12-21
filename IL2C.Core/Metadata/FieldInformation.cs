using Mono.Cecil;
using System.Linq;
using System.Runtime.InteropServices;

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

        NativeValueAttribute NativeValue { get; }
        string CLanguageNativeSymbolName { get; }
    }

    internal sealed class FieldInformation
        : MemberInformation<FieldReference, FieldDefinition>, IFieldInformation
    {
        public FieldInformation(FieldReference field, ModuleInformation module)
            : base(field, module)
        {
        }

        public override string MetadataTypeName => "Field";

        public override string MemberTypeName => this.IsStatic
            ? "Static field"
            : "Field";

        public override string UniqueName =>
            string.Format("{0}.{1}", this.Member.DeclaringType.FullName, this.Member.Name);

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
                    Utilities.GetCLanguageExpression(this.DeclaredValue ?? 0));

            return string.Format(
                "{0} {1}{2}",
                this.FieldType.CLanguageTypeName,
                this.MangledUniqueName,
                initializer);
        }

        public override bool IsCLanguagePublicScope =>
            this.DeclaringType.IsCLanguagePublicScope &&
            this.Definition.IsPublic;
        public override bool IsCLanguageLinkageScope =>
            this.DeclaringType.IsCLanguageLinkageScope &&
            (this.Definition.IsPublic || !this.Definition.IsPrivate);
        public override bool IsCLanguageFileScope =>
            this.Definition.IsPrivate;

        public NativeValueAttribute NativeValue =>
            this.Definition.CustomAttributes.
            Where(ca => ca.AttributeType.FullName == typeof(NativeValueAttribute).FullName).
            Select(ca => new NativeValueAttribute(
                ca.ConstructorArguments[0].Value,
                ca.Properties.ToDictionary(p => p.Name, p => p.Argument.Value))).
            FirstOrDefault();

        public string CLanguageNativeSymbolName =>
            this.NativeValue?.SymbolName ?? this.Name;

        protected override FieldDefinition OnResolve(FieldReference member)
        {
            return member.Resolve();
        }
    }
}
