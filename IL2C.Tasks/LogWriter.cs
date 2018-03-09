using System;
using System.Globalization;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace IL2C
{
    internal sealed class LogWriter : System.IO.TextWriter
    {
        private readonly Action<string> writer;
        private readonly StringBuilder sb = new StringBuilder();

        public LogWriter(Action<string> writer)
            : base(CultureInfo.InvariantCulture)
        {
            this.writer = writer;
        }

        public override Encoding Encoding
        {
            get
            {
                return Encoding.UTF8;
            }
        }

        public override void Flush()
        {
            this.WriteLine();
        }

        public override void Write(char ch)
        {
            sb.Append(ch);
        }

        public override void Write(char[] buffer, int index, int count)
        {
            var value = new string(buffer, index, count);
            sb.Append(value);
        }

        public override void Write(string value)
        {
            sb.Append(value);
        }

        public override void WriteLine()
        {
            this.WriteLine(string.Empty);
        }

        public override void WriteLine(string value)
        {
            sb.Append(value);
            writer(sb.ToString());
            sb.Clear();
        }

        public override void WriteLine(object value)
        {
            this.WriteLine(value?.ToString()??string.Empty);
        }
    }
}
