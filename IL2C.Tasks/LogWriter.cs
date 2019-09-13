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
using System.Globalization;
using System.Text;

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
