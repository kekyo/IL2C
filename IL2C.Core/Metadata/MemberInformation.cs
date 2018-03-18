using System;
using System.Diagnostics;
using System.Linq;
using System.Text;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IMemberInformation
        : IMetadataInformation
    {
        string Name { get; }
        string FriendlyName { get; }
        string MangledName { get; }

        string MemberTypeName { get; }

        ITypeInformation DeclaringType { get; }
    }

    internal abstract class MemberInformation<TReference, TDefinition>
        : MetadataInformation<TReference, TDefinition>
        , IMemberInformation
        where TReference : MemberReference
        where TDefinition : TReference
    {
        private static readonly char[] replaceChars = { '.', '@', '*' };

        private readonly Lazy<TypeInformation> declaringType;

        public MemberInformation(TReference member, ModuleInformation module)
            : base(member, module.Context)
        {
            this.DeclaringModule = module;

            declaringType = this.Context.LazyGetOrAddMember(
                () => this.Member.DeclaringType,
                type => new TypeInformation(type, module));
        }

        public override string UniqueName => this.Member.FullName;
        public IModuleInformation DeclaringModule { get; }

        public string Name => this.Member.Name;

        protected static string ToMangledName(string name)
        {
            Debug.Assert(!name.Contains("*"));

            var sb = new StringBuilder(name);
            foreach (var ch in replaceChars)
            {
                sb.Replace(ch, '_');
            }
            return sb.ToString();
        }

        public virtual string FriendlyName
        {
            get
            {
                var declaringTypes = this.Member.DeclaringType
                    .Traverse(current => current.DeclaringType)
                    .Reverse()
                    .ToArray();
                var namespaceName = declaringTypes.First().Namespace;

                return string.Format(
                    "{0}.{1}.{2}",
                    namespaceName,
                    string.Join(".", declaringTypes.Select(type => type.Name)),
                    this.Member.Name);
            }
        }

        public string MangledName => ToMangledName(this.FriendlyName);

        public abstract string MemberTypeName { get; }

        public ITypeInformation DeclaringType => declaringType.Value;

        public override string ToString()
        {
            return string.Format("{0}: {1}", this.MemberTypeName, base.ToString());
        }
    }
}
