using System.Linq;
using System.Runtime.InteropServices;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IFieldInformation : IMemberInformation
    {
        bool IsPublic { get; }
        bool IsPrivate { get; }
        bool IsFamily { get; }
        bool IsFamilyOrAssembly { get; }
        bool IsFamilyAndAssembly { get; }

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

        public override string AttributeDescription
        {
            get
            {
                var scope = this.IsPublic ?
                    "public" :
                    this.IsFamily ?
                    "protected" :
                    this.IsFamilyOrAssembly ?
                    "protected internal" :
                    this.IsFamilyAndAssembly ?
                    "private protected" :
                    this.IsPrivate ?
                    "private" :
                    "internal";
                var attribute1 = this.HasConstant ?
                    "const" :
                    this.IsStatic ?
                    "static" :
                    string.Empty;

                return string.Join(" ",
                    new[] { scope, attribute1 }.
                    Where(a => !string.IsNullOrWhiteSpace(a)));
            }
        }

        public override string UniqueName =>
            string.Format("{0}.{1}", this.Member.DeclaringType.FullName, this.Member.Name);

        public bool IsPublic => this.Definition.IsPublic;
        public bool IsPrivate => this.Definition.IsPrivate;
        public bool IsFamily => this.Definition.IsFamily;
        public bool IsFamilyOrAssembly => this.Definition.IsFamilyOrAssembly;
        public bool IsFamilyAndAssembly => this.Definition.IsFamilyAndAssembly;

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

        public override MemberScopes CLanguageMemberScope
        {
            get
            {
                var scope = MemberScopes.HiddenOrUnknown;
                var definition = this.Definition;

                if (definition.IsPrivate)
                {
                    scope = MemberScopes.File;
                }
                else if (definition.IsFamily || definition.IsFamilyAndAssembly)
                {
                    scope = MemberScopes.Linkage;
                }
                else if (definition.IsPublic || definition.IsFamilyOrAssembly)
                {
                    scope = MemberScopes.Public;
                }

                var declaringType = this.DeclaringType;
                if (declaringType.CLanguageMemberScope < scope)
                {
                    scope = declaringType.CLanguageMemberScope;
                }

                return scope;
            }
        }

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
