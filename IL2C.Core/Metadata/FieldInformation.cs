using System;
using System.Diagnostics;

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
        object ConstantValue { get; }

        string GetCLanguagePrototype(bool requireInitializerExpression);
    }

    internal sealed class FieldInformation
        : MemberInformation<FieldReference, FieldDefinition>
        , IFieldInformation
    {
        private readonly Lazy<TypeInformation> fieldType;

        public FieldInformation(FieldReference field, ModuleInformation module)
            : base(field, module)
        {
            fieldType = this.MetadataContext.LazyGetOrAddMember(
                () => this.Member.FieldType,
                type => new TypeInformation(type, module));
        }

        public override string MemberTypeName => this.IsStatic
            ? "Static field"
            : "Field";

        public bool IsPublic => this.Definition.IsPublic;
        public bool IsFamily => this.Definition.IsFamily;
        public bool IsFamilyOrAssembly => this.Definition.IsFamilyOrAssembly;

        public bool IsStatic => this.Definition.IsStatic;
        public bool HasConstant => this.Definition.HasConstant;

        public ITypeInformation FieldType => fieldType.Value;

        public object ConstantValue => this.Definition.Constant;

        public string GetCLanguagePrototype(bool requireInitializerExpression)
        {
            var initializer = String.Empty;
            if (requireInitializerExpression)
            {
                if (this.FieldType.IsNumericPrimitive)
                {
                    // TODO: numericPrimitive and (literal or readonly static) ?
                    Debug.Assert(this.IsStatic);
                    var value = this.HasConstant ? this.ConstantValue : 0;

                    Debug.Assert(value != null);

                    initializer = this.FieldType.IsInt64Type
                        ? String.Format(" = {0}LL", value)
                        : String.Format(" = {0}", value);
                }
                else if (this.FieldType.IsValueType == false)
                {
                    initializer = " = NULL";
                }
            }

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
