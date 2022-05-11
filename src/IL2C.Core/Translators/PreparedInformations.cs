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
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedInformations
    {
        internal readonly ITypeInformation[] Types;
        internal readonly IReadOnlyDictionary<IMethodInformation, PreparedMethodInformation> Functions;

        internal PreparedInformations(
            ITypeInformation[] types,
            IReadOnlyDictionary<IMethodInformation, PreparedMethodInformation> functions)
        {
            this.Types = types;
            this.Functions = functions;
        }

        public int Count => this.Functions.Count;

        public bool TryGet(string methodName, out PreparedMethodInformation? preparedFunction)
        {
            preparedFunction = this.Functions
                .Where(entry => entry.Key.UniqueName == methodName)
                .Select(entry => entry.Value)
                .FirstOrDefault();
            return preparedFunction != null;
        }
    }
}
