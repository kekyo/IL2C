using System;
using System.Globalization;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace IL2C
{
    internal sealed class LogWriter : System.IO.TextWriter
    {
        private readonly TaskLoggingHelper taskLogger;
        private readonly StringBuilder sb = new StringBuilder();

        public LogWriter(TaskLoggingHelper taskLogger)
            : base(CultureInfo.InvariantCulture)
        {
            this.taskLogger = taskLogger;
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
            taskLogger.LogMessage(
                MessageImportance.High,
                "{0}{1}",
                sb,
                value);
            sb.Clear();
        }

        public override void WriteLine(object value)
        {
            this.WriteLine(value?.ToString()??string.Empty);
        }
    }
}
