////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.InteropServices;

using NUnit.Framework;
using NUnit.Framework.Interfaces;
using NUnit.Framework.Internal;

namespace IL2C
{
    [IgnoreTranslation]
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Method | AttributeTargets.Assembly, AllowMultiple = false, Inherited = true)]
    public sealed class SetCultureAttribute : PropertyAttribute, IApplyToContext
    {
        public readonly string CultureName;

        public SetCultureAttribute(string cultureName) =>
            this.CultureName = cultureName;

        public void ApplyToContext(TestExecutionContext context)
        {
            var culture = new System.Globalization.CultureInfo(this.CultureName, false);
            context.CurrentCulture = culture;
            context.CurrentUICulture = culture;
        }
    }
}
