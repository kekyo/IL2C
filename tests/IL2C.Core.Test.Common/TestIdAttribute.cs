////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C
{
    [AttributeUsage(AttributeTargets.Class)]
    public sealed class TestIdAttribute : Attribute
    {
        public TestIdAttribute(string id)
        {
            this.Id = id;
        }

        public string Id { get; }
    }
}
