using System;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IMemberInformation
        : IMetadataInformation
    {
        string MemberTypeName { get; }

        IModuleInformation DeclaringModule { get; }
        ITypeInformation DeclaringType { get; }

        bool IsCLanguagePublicScope { get; }
        bool IsCLanguageLinkageScope { get; }
        bool IsCLanguageFileScope { get; }
    }

    internal abstract class MemberInformation<TReference, TDefinition>
        : MetadataInformation<TReference, TDefinition>
        , IMemberInformation
        , IOperandPrintable
        where TReference : MemberReference
        where TDefinition : TReference
    {
        private readonly Lazy<TypeInformation> declaringType;

        public MemberInformation(TReference member, ModuleInformation module)
            : base(member, module.MetadataContext)
        {
            this.DeclaringModule = module;

            declaringType = this.MetadataContext.LazyGetOrAddMember(
                () => this.Member.DeclaringType,
                type => new TypeInformation(type, module));
        }

        public override string UniqueName =>
            this.Member.FullName;
        public override string Name =>
            this.Member.Name;
        public override string FriendlyName =>
            this.Member.GetFriendlyName();

        public abstract string MemberTypeName { get; }

        internal ModuleInformation DeclaringModule { get; }
        IModuleInformation IMemberInformation.DeclaringModule => this.DeclaringModule;

        public ITypeInformation DeclaringType => declaringType.Value;

        public abstract bool IsCLanguagePublicScope { get; }
        public abstract bool IsCLanguageLinkageScope { get; }
        public abstract bool IsCLanguageFileScope { get; }

        public override string ToString() =>
            string.Format("{0}: {1}", this.MemberTypeName, base.ToString());

        string IOperandPrintable.PrintableString =>
            this.Member.GetFriendlyName();
    }
}
