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

using Internal.TypeSystem;
using System;
using System.Text;

// Based on:
// https://github.com/dotnet/runtime/blob/main/src/coreclr/tools/Common/TypeSystem/Common/Utilities/DebugNameFormatter.cs#L11

namespace IL2C.Internal
{
    internal sealed class ILVerifierNameFormatter :
        TypeNameFormatter<ILVerifierNameFormatter.Void, ILVerifierNameFormatter.Void>
    {
        public struct Void
        {
            public static Void Value => default(Void);
        }

        public static readonly ILVerifierNameFormatter Instance = new ILVerifierNameFormatter();

        public override Void AppendName(StringBuilder sb, ArrayType type, Void _ = default)
        {
            AppendName(sb, type.ElementType, _);
            if (!type.IsSzArray && type.Rank == 1)
            {
                sb.Append("[*]");
            }
            else
            {
                sb.Append('[');
                sb.Append(',', type.Rank - 1);
                sb.Append(']');
            }
            return Void.Value;
        }

        public override Void AppendName(StringBuilder sb, ByRefType type, Void _ = default)
        {
            AppendName(sb, type.ParameterType, _);
            sb.Append('&');
            return Void.Value;
        }

        public override Void AppendName(StringBuilder sb, PointerType type, Void _ = default)
        {
            AppendName(sb, type.ParameterType, _);
            sb.Append('*');
            return Void.Value;
        }

        public override Void AppendName(StringBuilder sb, FunctionPointerType type, Void _ = default)
        {
            MethodSignature signature = type.Signature;
            sb.Append("(*");
            AppendName(sb, signature.ReturnType, _);
            sb.Append(")(");
            for (int i = 0; i < signature.Length; i++)
            {
                if (i > 0)
                {
                    sb.Append(',');
                }
                AppendName(sb, signature[i], _);
            }
            sb.Append(')');
            return Void.Value;
        }

        public override Void AppendName(StringBuilder sb, GenericParameterDesc type, Void _ = default)
        {
            sb.Append(type.DiagnosticName);
            return Void.Value;
        }

        public override Void AppendName(StringBuilder sb, SignatureMethodVariable type, Void _ = default)
        {
            sb.Append("!!");
            sb.Append(type.Index.ToString());
            return Void.Value;
        }

        public override Void AppendName(StringBuilder sb, SignatureTypeVariable type, Void _ = default)
        {
            sb.Append("!");
            sb.Append(type.Index.ToString());
            return Void.Value;
        }

        protected override Void AppendNameForNestedType(StringBuilder sb, DefType nestedType, DefType containingType, Void _ = default)
        {
            AppendName(sb, containingType, _);
            sb.Append('+');
            sb.Append(nestedType.DiagnosticName);
            return Void.Value;
        }

        protected override Void AppendNameForNamespaceType(StringBuilder sb, DefType type, Void _ = default)
        {
            int length = sb.Length;
            try
            {
                switch (type.Category)
                {
                    case TypeFlags.Void:
                        sb.Append("void");
                        return Void.Value;
                    case TypeFlags.Boolean:
                        sb.Append("bool");
                        return Void.Value;
                    case TypeFlags.Char:
                        sb.Append("char");
                        return Void.Value;
                    case TypeFlags.SByte:
                        sb.Append("sbyte");
                        return Void.Value;
                    case TypeFlags.Byte:
                        sb.Append("byte");
                        return Void.Value;
                    case TypeFlags.Int16:
                        sb.Append("short");
                        return Void.Value;
                    case TypeFlags.UInt16:
                        sb.Append("ushort");
                        return Void.Value;
                    case TypeFlags.Int32:
                        sb.Append("int");
                        return Void.Value;
                    case TypeFlags.UInt32:
                        sb.Append("uint");
                        return Void.Value;
                    case TypeFlags.Int64:
                        sb.Append("long");
                        return Void.Value;
                    case TypeFlags.UInt64:
                        sb.Append("ulong");
                        return Void.Value;
                    case TypeFlags.IntPtr:
                        sb.Append("System.IntPtr");
                        return Void.Value;
                    case TypeFlags.UIntPtr:
                        sb.Append("System.UIntPtr");
                        return Void.Value;
                    case TypeFlags.Single:
                        sb.Append("float");
                        return Void.Value;
                    case TypeFlags.Double:
                        sb.Append("double");
                        return Void.Value;
                    default:
                        if (type.IsString)
                        {
                            sb.Append("string");
                            return Void.Value;
                        }
                        if (type.IsObject)
                        {
                            sb.Append("object");
                            return Void.Value;
                        }
                        NamespaceQualify(sb, type, _);
                        sb.Append(type.DiagnosticName);
                        break;
                }
            }
            catch
            {
                sb.Length = length;
                NamespaceQualify(sb, type, _);
                sb.Append(type.DiagnosticName);
            }
            return Void.Value;
        }

        private void NamespaceQualify(StringBuilder sb, DefType type, Void _ = default)
        {
            string diagnosticNamespace = type.DiagnosticNamespace;
            if (!string.IsNullOrEmpty(diagnosticNamespace))
            {
                sb.Append(diagnosticNamespace);
                sb.Append('.');
            }
        }

        protected override Void AppendNameForInstantiatedType(StringBuilder sb, DefType type, Void _ = default)
        {
            AppendName(sb, type.GetTypeDefinition(), _);
            sb.Append('<');
            for (int i = 0; i < type.Instantiation.Length; i++)
            {
                if (i != 0)
                {
                    sb.Append(',');
                }
                AppendName(sb, type.Instantiation[i], _);
            }
            sb.Append('>');
            return Void.Value;
        }

        protected override DefType GetContainingType(DefType possibleInnerType, Void _ = default)
        {
            try
            {
                return possibleInnerType.ContainingType;
            }
            catch
            {
                return null;
            }
        }
    }
}
