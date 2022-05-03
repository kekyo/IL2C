////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

namespace IL2C.Translators
{
    public struct Label
    {
        public readonly int Offset;

        public Label(int offset)
        {
            this.Offset = offset;
        }

        public override string ToString() =>
            string.Format("IL_{0:x4}", this.Offset);
    }
}
