using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace IL2C
{
    public class CodeTextWriter : IDisposable
    {
        private readonly string oneIndent;
        private int indentCount = 0;
        private string indent = string.Empty;
        private bool split = false;

        public CodeTextWriter(TextWriter tw, string relatedPath, string indent)
        {
            this.Parent = tw;
            this.RelatedPath = relatedPath;
            this.oneIndent = indent;
        }

        public virtual void Dispose()
        {
            this.Parent.Dispose();
        }

        public TextWriter Parent { get; }
        public string RelatedPath { get; }

        private void UpdateIndent(int shiftCount)
        {
            split = false;
            indentCount += shiftCount;
            indent = string.Join(string.Empty, Enumerable.Range(0, indentCount).Select(_ => oneIndent));
        }

        public IDisposable Shift(int shiftCount = 1)
        {
            Debug.Assert(shiftCount != 0);

            if (split)
            {
                this.Parent.WriteLine();
                split = false;
            }
            this.UpdateIndent(shiftCount);
            return new Unshifter(this, 0 - shiftCount);
        }

        public void SplitLine()
        {
            split = true;
        }

        private void InternalWriteLine(string indent, string message)
        {
            if (split)
            {
                this.Parent.WriteLine();
                split = false;
            }
            this.Parent.WriteLine(indent + message);
        }

        private void InternalWriteLine(string indent, string format, object[] args)
        {
            if (split)
            {
                this.Parent.WriteLine();
                split = false;
            }
            this.Parent.WriteLine(indent + format, args);
        }

        public void WriteLine(string message)
        {
            this.InternalWriteLine(indent, message);
        }

        public void WriteLine(string format, params object[] args)
        {
            this.InternalWriteLine(indent, format, args);
        }

        public void WriteLineIgnoreIndent(string message)
        {
            this.InternalWriteLine(string.Empty, message);
        }

        public void WriteLineIgnoreIndent(string format, params object[] args)
        {
            this.InternalWriteLine(string.Empty, format, args);
        }

        public void Flush()
        {
            this.Parent.Flush();
        }

        public static CodeTextWriter Create(TextWriter tw, string relatedPath, string indent)
        {
            return new CodeTextWriter(tw, relatedPath, indent);
        }

        public static CodeTextWriter Create(Stream stream, string relatedPath, string indent)
        {
            return new CodeTextWriter(new StreamWriter(stream, Encoding.UTF8), relatedPath, indent);
        }

        private sealed class Unshifter : IDisposable
        {
            private CodeTextWriter parent;
            private int shiftCount;

            public Unshifter(CodeTextWriter parent, int shiftCount)
            {
                this.parent = parent;
                this.shiftCount = shiftCount;
            }

            public void Dispose()
            {
                if (parent != null)
                {
                    parent.UpdateIndent(shiftCount);
                    parent = null;
                    shiftCount = 0;
                }
            }
        }
    }
}
