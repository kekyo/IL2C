/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using IL2C.Internal;
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
            this.Member.GetUniqueName();
        public override string Name =>
            MetadataUtilities.TrimGenericIdentifier(this.Member.Name);
        public override string MangledUniqueName =>
            this.Member.GetMangledUniqueName();
        public override string MangledName =>
            Utilities.GetMangledName(this.Name);
        public override string FriendlyName =>
            this.UniqueName;

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
            this.Member.GetUniqueName();
    }
}
