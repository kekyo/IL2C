using System;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public enum MemberScopes
    {
        HiddenOrUnknown,
        File,
        Linkage,
        Public
    }

    public interface IMemberInformation
        : IMetadataInformation
    {
        string MemberTypeName { get; }
        string AttributeDescription { get; }

        IModuleInformation DeclaringModule { get; }
        ITypeInformation DeclaringType { get; }

        MemberScopes CLanguageMemberScope { get; }
    }

    internal abstract class MemberInformation<TReference, TDefinition>
        : MetadataInformation<TReference, TDefinition>, IMemberInformation, IOperandPrintable
        where TReference : MemberReference
        where TDefinition : TReference
    {
        public MemberInformation(TReference member, ModuleInformation module)
            : base(member, module.MetadataContext)
        {
            this.DeclaringModule = module;
        }

        public override string UniqueName =>
            this.Member.FullName;
        public override string Name =>
            this.Member.Name;
        public override string FriendlyName =>
            this.Member.GetFriendlyName();

        public abstract string MemberTypeName { get; }
        public abstract string AttributeDescription { get; }

        internal ModuleInformation DeclaringModule { get; }
        IModuleInformation IMemberInformation.DeclaringModule =>
            this.DeclaringModule;

        public ITypeInformation DeclaringType =>
            this.MetadataContext.GetOrAddType(this.Member.DeclaringType);

        public abstract MemberScopes CLanguageMemberScope { get; }

        public override string ToString() =>
            string.Format("{0}: {1}", this.MemberTypeName, this.FriendlyName);

        string IOperandPrintable.PrintableString =>
            this.Member.GetFriendlyName();
    }
}
