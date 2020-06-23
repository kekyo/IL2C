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
using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    internal struct DeclaredValuesInformation
    {
        public readonly string SymbolName;
        public readonly IFieldInformation[] DeclaredFields;
        public readonly ITypeInformation[] HintTypes;
        public readonly byte[] ResourceData;

        public DeclaredValuesInformation(
            string symbolName, IFieldInformation[] declaredFields, ITypeInformation[] hintTypes, byte[] resourceData)
        {
            this.SymbolName = symbolName;
            this.DeclaredFields = declaredFields;
            this.HintTypes = hintTypes;
            this.ResourceData = resourceData;
        }
    }

    internal interface IExtractContext
    {
        IMetadataContext MetadataContext { get; }
        IAssemblyInformation Assembly { get; }
        TargetPlatforms TargetPlatform { get; }

        string GetExceptionNestedFrameIndexName();

        string GetRightExpression(ITypeInformation lhsType, IVariableInformation rhs);
        string GetRightExpression(ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression);

        string GetSymbolName(IVariableInformation variable);

        IReadOnlyDictionary<MemberScopes, IEnumerable<ITypeInformation>> EnumerateRegisteredTypes();
        IEnumerable<ITypeInformation> EnumerateRegisteredTypesByDeclaringType(ITypeInformation declaringType);
        IEnumerable<string> EnumerateRequiredImportIncludeFileNames();
        IEnumerable<(string symbolName, string value)> ExtractConstStrings();
        IEnumerable<DeclaredValuesInformation> ExtractDeclaredValues();
    }

    internal interface IExtractContextHost
        : IExtractContext
    {
        IDisposable BeginLocalVariablePrefix(Func<ILocalVariableInformation, string> prefixGenerator);
        void SetNestedExceptionFrameIndexName(string nestedIndexName);
    }
}
