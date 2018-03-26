using System;
using System.Text;

namespace IL2C.Metadata
{
    public interface IMetadataInformation
        : IEquatable<IMetadataInformation>
        , IComparable<IMetadataInformation>
        , IComparable
    {
        string UniqueName { get; }
        string Name { get; }
        string FriendlyName { get; }
        string MangledName { get; }

        IMetadataContext Context { get; }
    }

    internal abstract class MetadataInformation
        : IMetadataInformation
    {
        private static readonly char[] replaceChars = {
            '.', ',', '@', '+', '-', '*', '/', '^', '\\', '#', '%', '&', '$', '?', '!', '=', '~', '|',
            '(', ')', '<', '>', '[', ']', '{', '}', '\'', '"', '`', ';', ':', ' ' };

        protected MetadataInformation(MetadataContext metadataContext)
        {
            this.MetadataContext = metadataContext;
        }

        internal readonly MetadataContext MetadataContext;
        IMetadataContext IMetadataInformation.Context =>
            this.MetadataContext;

        public abstract string UniqueName { get; }
        public abstract string Name { get; }
        public abstract string FriendlyName { get; }

        protected static string ToMangledName(string name)
        {
            var sb = new StringBuilder(name);
            foreach (var ch in replaceChars)
            {
                sb.Replace(ch, '_');
            }
            return sb.ToString();
        }

        public virtual string MangledName =>
            ToMangledName(this.FriendlyName);

        public int CompareTo(IMetadataInformation other) =>
            StringComparer.Ordinal.Compare(this.UniqueName, other.UniqueName);

        int IComparable.CompareTo(object obj) =>
            StringComparer.Ordinal.Compare(this.UniqueName, ((IMetadataInformation)obj).UniqueName);

        public bool Equals(IMetadataInformation other) =>
            StringComparer.Ordinal.Equals(this.UniqueName, other.UniqueName);

        public override bool Equals(object obj) =>
            this.Equals(obj as IMetadataInformation);

        public override int GetHashCode() =>
            this.UniqueName.GetHashCode();

        public override string ToString() =>
            this.UniqueName;
    }

    internal abstract class MetadataInformation<TReference, TDefinition>
        : MetadataInformation
        where TDefinition : class, TReference
    {
        protected MetadataInformation(TReference member, MetadataContext metadataContext)
            : base(metadataContext)
        {
            this.Member = member;
        }

        protected TReference Member { get; private set; }

        protected TDefinition Definition
        {
            get
            {
                TDefinition member = this.Member as TDefinition;
                if (member == null)
                {
                    lock (this)
                    {
                        member = this.Member as TDefinition;
                        if (member == null)
                        {
                            member = this.OnResolve(this.Member);
                            this.Member = member;
                        }
                    }
                }

                return member;
            }
        }

        protected virtual TDefinition OnResolve(TReference member) =>
            (TDefinition)member;
    }
}
