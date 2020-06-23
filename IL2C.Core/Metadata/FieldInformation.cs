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

using System.Linq;
using System.Runtime.InteropServices;

using Mono.Cecil;

using IL2C.Metadata.Attributes;

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
        bool IsInitOnly { get; }
        bool HasConstant { get; }

        ITypeInformation FieldType { get; }
        object DeclaredValue { get; }

        NativeValueAttributeInformation NativeValue { get; }
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
                    (this.IsStatic && this.IsInitOnly) ?
                    "static readonly" :
                    this.IsStatic ?
                    "static" :
                    this.IsInitOnly ?
                    "readonly" :
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
        public bool IsInitOnly => this.Definition.IsInitOnly;
        public bool HasConstant => this.Definition.HasConstant;

        public ITypeInformation FieldType =>
            this.MetadataContext.GetOrAddType(this.Member.FieldType);

        public object DeclaredValue =>
            this.HasConstant ?
                this.Definition.Constant :
                this.Definition.InitialValue;

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

        public NativeValueAttributeInformation NativeValue =>
            this.Definition.CustomAttributes.
            Where(ca => ca.AttributeType.FullName == NativeValueAttributeInformation.FullName).
            Select(ca => new NativeValueAttributeInformation(ca)).
            FirstOrDefault();

        public string CLanguageNativeSymbolName =>
            this.NativeValue?.SymbolName ?? this.Name;

        protected override FieldDefinition OnResolve(FieldReference member)
        {
            return member.Resolve();
        }
    }
}
