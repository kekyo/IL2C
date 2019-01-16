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
            var scopedPath = Utilities.GetScopedPath(scopeNames);
            var path = Path.GetFullPath(Path.Combine(basePath, scopedPath, fileName + ext));
            var tw = this.OnCreateTextWriter(path);

            logw.Write("IL2C: Writing: \"{0}\" ...", path);

            return new InternalCodeTextWriter(logw, tw, indent);
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

        public IDisposable EnterScope(string scopeName)
        {
            scopeNames.Push(scopeName);
            return new ScopeDisposer(this);
        }

        private sealed class InternalCodeTextWriter : CodeTextWriter
        {
            private TextWriter logw;

            public InternalCodeTextWriter(TextWriter logw, TextWriter tw, string indent)
                : base(tw, indent)
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
