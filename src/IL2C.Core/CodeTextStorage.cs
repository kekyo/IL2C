////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

using IL2C.Internal;

namespace IL2C
{
    public class CodeTextStorage
    {
        public readonly string BasePath;

        private readonly ILogger logger;
        private readonly bool produceCpp;
        private readonly string indent;
        private readonly Stack<string> scopeNames = new Stack<string>();

        public CodeTextStorage(ILogger logger, string basePath, bool produceCpp, string indent)
        {
            this.logger = logger;
            this.BasePath = Path.GetFullPath(basePath);
            this.produceCpp = produceCpp;
            this.indent = indent;
        }

        public CodeTextWriter CreateTextWriter(string fileName, string ext)
        {
            var scopedPath = Path.Combine(scopeNames.Reverse().ToArray());
            var path = Path.Combine(this.BasePath, scopedPath, fileName + ext);
            var tw = this.OnCreateTextWriter(path);

            return new InternalCodeTextWriter(this.logger, tw, path, indent);
        }

        public CodeTextWriter CreateSourceCodeWriter(string fileName)
        {
            return this.CreateTextWriter(fileName, produceCpp ? ".cpp" : ".c");
        }

        public CodeTextWriter CreateHeaderWriter(string fileName)
        {
            return this.CreateTextWriter(fileName, ".h");
        }

        protected virtual TextWriter OnCreateTextWriter(string path)
        {
            var directoryPath = Utilities.SafeGetDirectoryName(path);
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
            private ILogger? logger;

            public InternalCodeTextWriter(ILogger logger, TextWriter tw, string relatedPath, string indent)
                : base(tw, relatedPath, indent)
            {
                this.logger = logger;
            }

            public override void Dispose()
            {
                if (this.logger != null)
                {
                    base.Dispose();
                    this.logger.Trace($"Translated: \"{base.RelatedPath}\"");
                    this.logger = null;
                }
            }
        }

        private sealed class ScopeDisposer : IDisposable
        {
            private CodeTextStorage? parent;

            public ScopeDisposer(CodeTextStorage parent)
            {
                this.parent = parent;
            }

            public void Dispose()
            {
                if (this.parent != null)
                {
                    this.parent.scopeNames.Pop();
                    this.parent = null;
                }
            }
        }
    }
}
