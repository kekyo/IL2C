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

using ILVerify;
using Internal.IL;
using Internal.TypeSystem;
using Internal.TypeSystem.Ecma;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text;

#pragma warning disable CS0436

namespace IL2C.Internal
{
    internal sealed class ILVerifier
    {
        private sealed class Resolver : IResolver
        {
            private readonly Assembly assembly;
            private readonly string[] assemblyBasePaths;

            public Resolver(Assembly assembly)
            {
                this.assembly = assembly;
                this.assemblyBasePaths =
                    new[] { this.assembly.Location }.
                    Concat(AppDomain.CurrentDomain.GetAssemblies().
                        Where(a => !a.IsDynamic).
                        Select(a => a.Location)).
                    Select(Path.GetDirectoryName).
                    Distinct().
                    ToArray();
            }

            public static PEReader GetReader(string path)
            {
                var reader = new PEReader(
                    File.OpenRead(path),
                    PEStreamOptions.PrefetchEntireImage | PEStreamOptions.PrefetchMetadata | PEStreamOptions.LeaveOpen);
                reader.TryOpenAssociatedPortablePdb(
                    path,
                    pdbName => File.Exists(pdbName) ? File.OpenRead(pdbName) : null,
                    out var provider,
                    out var pdbPath);
                return reader;
            }

            public PEReader Resolve(string simpleName)
            {
                var path = assemblyBasePaths.SelectMany(basePath =>
                    Directory.EnumerateFiles(basePath, "*.dll")).
                    FirstOrDefault(path => Path.GetFileNameWithoutExtension(path) == simpleName);
                return (path != null) ? GetReader(path) : null;
            }
        }

        private static EcmaModule GetModule(Verifier verifier, PEReader reader) =>
            // DIRTY: Verifier.GetModule() marked internal... why?
            (EcmaModule)verifier.GetType().GetMethod("GetModule", BindingFlags.NonPublic | BindingFlags.Instance).
            Invoke(verifier, new object[] { reader });

        private readonly Dictionary<string, Dictionary<string, (VerificationResult result, string instruction)[]>> results = new();

        public ILVerifier()
        {
        }

        private static string GetTypeFullName(TypeDesc type) =>
            ILVerifierNameFormatter.Instance.FormatName(type, default);

        private static string GetMethodFullName(MethodDesc method)
        {
            var stringBuilder = new StringBuilder();
            stringBuilder.Append(GetTypeFullName(method.OwningType));
            stringBuilder.Append('.');
            stringBuilder.Append(method.DiagnosticName);
            return stringBuilder.ToString();
        }


        public (VerificationResult result, string instruction)[] Verify(MethodInfo method)
        {
            lock (this.results)
            {
                if (!this.results.TryGetValue(
                    method.Module.Assembly.FullName,
                    out var assemblyResults))
                {
                    var resolver = new Resolver(method.Module.Assembly);
                    var verifier = new Verifier(resolver, new VerifierOptions()
                    {
                        IncludeMetadataTokensInErrorMessages = false,
                    });

                    var san = (ThisAssembly.AssemblyMetadata.TargetFramework == "net48") ?
                        "mscorlib" : "netstandard";
                    verifier.SetSystemModuleName(method.Module.Assembly.
                        GetReferencedAssemblies().
                        First(an => an.Name == san));

                    var reader = Resolver.GetReader(method.Module.Assembly.Location);

                    var temp = verifier.Verify(reader).
                        GroupBy(r => r.Method).
                        ToDictionary(g => g.Key, g => g.ToArray());

                    var module = GetModule(verifier, reader);

                    assemblyResults = temp.
                        Select(e => (method: module.GetMethod(e.Key), results: e.Value)).
                        ToDictionary(
                            e => GetMethodFullName(e.method),
                            e => e.results.Select(r =>
                                ((r.ErrorArguments != null) &&   // BUG?
                                 r.TryGetArgumentValue("Offset", out int offset)) ?
                                    (r, $"[0x{offset:x4}]: {(ILOpCode)EcmaMethodIL.Create((EcmaMethod)e.method).GetILBytes()[offset]}") : (r, "(No offset)")
                        ).
                        ToArray());

                    this.results.Add(
                        method.Module.Assembly.FullName,
                        assemblyResults);
                }

                if (assemblyResults.TryGetValue(
                    $"{method.DeclaringType.FullName}.{method.Name}",
                    out var results))
                {
                    return results;
                }
                else
                {
                    return Array.Empty<(VerificationResult result, string instruction)>();
                }
            }
        }
    }
}
