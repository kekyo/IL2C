using System;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IFieldInformation : IMemberInformation
    {
        bool IsStatic { get; }
        bool HasConstant { get; }

        ITypeInformation FieldType { get; }
        object ConstantValue { get; }
    }

    internal sealed class FieldInformation
        : MemberInformation<FieldReference, FieldDefinition>
        , IFieldInformation
    {
        private readonly Lazy<TypeInformation> fieldType;

        public FieldInformation(FieldReference field, ModuleInformation module)
            : base(field, module)
        {
            fieldType = this.Context.LazyGetOrAddMember(
                () => this.Member.FieldType,
                type => new TypeInformation(type, module));
        }

        public bool IsStatic => this.Definition.IsStatic;
        public bool HasConstant => this.Definition.HasConstant;

        public ITypeInformation FieldType => fieldType.Value;

        public object ConstantValue => this.Definition.Constant;

        protected override FieldDefinition OnResolve(FieldReference member)
        {
            return member.Resolve();
        }
    }
}
