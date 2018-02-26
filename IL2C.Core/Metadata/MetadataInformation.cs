using System;

namespace IL2C.Metadata
{
    public interface IMetadataInformation
        : IEquatable<IMetadataInformation>
        , IComparable<IMetadataInformation>
        , IComparable
    {
        string UniqueName { get; }

        IMetadataContext Context { get; }
    }

    internal abstract class MetadataInformation
        : IMetadataInformation
    {
        protected MetadataInformation(MetadataContext context)
        {
            this.Context = context;
        }

        internal readonly MetadataContext Context;

        IMetadataContext IMetadataInformation.Context => this.Context;
        public abstract string UniqueName { get; }

        public int CompareTo(IMetadataInformation other)
        {
            return StringComparer.Ordinal.Compare(this.UniqueName, other.UniqueName);
        }

        int IComparable.CompareTo(object obj)
        {
            return StringComparer.Ordinal.Compare(this.UniqueName, ((IMetadataInformation)obj).UniqueName);
        }

        public bool Equals(IMetadataInformation other)
        {
            return StringComparer.Ordinal.Equals(this.UniqueName, other.UniqueName);
        }

        public override bool Equals(object obj)
        {
            return this.Equals(obj as IMetadataInformation);
        }

        public override int GetHashCode()
        {
            return this.UniqueName.GetHashCode();
        }

        public override string ToString()
        {
            return this.UniqueName;
        }
    }

    internal abstract class MetadataInformation<TReference, TDefinition>
        : MetadataInformation
        where TDefinition : class, TReference
    {
        protected MetadataInformation(TReference member, MetadataContext context)
            : base(context)
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

        protected virtual TDefinition OnResolve(TReference member)
        {
            return (TDefinition)member;
        }
    }
}
