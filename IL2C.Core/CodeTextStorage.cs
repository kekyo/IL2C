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

using IL2C.Internal;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace IL2C
{
    public class CodeTextStorage
    {
        private readonly TextWriter logw;
        private readonly string basePath;
        private readonly bool enableCpp;
        private readonly string indent;
        private readonly Stack<string> scopeNames = new Stack<string>();

        public CodeTextStorage(TextWriter logw, string basePath, bool enableCpp, string indent)
        {
            this.logw = logw;
            this.basePath = basePath;
            this.enableCpp = enableCpp;
            this.indent = indent;
        }

        public CodeTextWriter CreateTextWriter(string fileName, string ext)
        {
            var scopedPath = Path.Combine(scopeNames.Reverse().ToArray());
            var path = Path.Combine(basePath, scopedPath, fileName + ext);
            var tw = this.OnCreateTextWriter(Path.GetFullPath(path));

            logw.Write("IL2C: Writing: \"{0}\" ...", path);

            return new InternalCodeTextWriter(logw, tw, path, indent);
        }

        public CodeTextWriter CreateSourceCodeWriter(string fileName)
        {
            return this.CreateTextWriter(fileName, enableCpp ? ".cpp" : ".c");
        }

        public CodeTextWriter CreateHeaderWriter(string fileName)
        {
            return this.CreateTextWriter(fileName, ".h");
        }

        protected virtual TextWriter OnCreateTextWriter(string path)
        {
            var directoryPath = Path.GetDirectoryName(path);
            try
            {
                if (!Directory.Exists(directoryPath))
                {
                    Directory.CreateDirectory(directoryPath);
                }
            }
            catch
            {
            }

            var fs = new FileStream(path, FileMode.Create, FileAccess.ReadWrite, FileShare.None, 65536, true);
            return new StreamWriter(fs, Encoding.UTF8);
        }

        public IDisposable EnterScope(string scopeName, bool splitScope = true)
        {
            scopeNames.Push(splitScope ? Utilities.GetCLanguageScopedPath(scopeName) : scopeName);
            return new ScopeDisposer(this);
        }

        private sealed class InternalCodeTextWriter : CodeTextWriter
        {
            private TextWriter logw;

            public InternalCodeTextWriter(TextWriter logw, TextWriter tw, string relatedPath, string indent)
                : base(tw, relatedPath, indent)
            {
                this.logw = logw;
            }

            public override void Dispose()
            {
                if (logw != null)
                {
                    base.Dispose();
                    logw.WriteLine(" Done.");
                    logw = null;
                }
            }
        }

        private sealed class ScopeDisposer : IDisposable
        {
            private CodeTextStorage parent;

            public ScopeDisposer(CodeTextStorage parent)
            {
                this.parent = parent;
            }

            public void Dispose()
            {
                if (parent != null)
                {
                    parent.scopeNames.Pop();
                    parent = null;
                }
            }
        }
    }
}
