////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Reflection;

namespace IL2C
{
    public struct TestCaseInformation
    {
        public readonly string CategoryName;
        public readonly string Id;
        public readonly string Name;
        public readonly string UniqueName;
        public readonly string Description;
        public readonly MethodInfo Method;
        public readonly Type[] AdditionalTypes;
        public readonly MethodBase[] AdditionalMethods;
        public readonly object Expected;
        public readonly object[] Arguments;
        public readonly TestCaseAsserts Assert;
        public readonly string[] IgnoreILErrors;

        public TestCaseInformation(
            string categoryName, string id, string name, string uniqueName, string description, object expected, TestCaseAsserts assert,
            MethodInfo method, Type[] additionalTypes, MethodBase[] additionalMethods, object[] arguments, string[] ignoreILErrors)
        {
            this.CategoryName = categoryName;
            this.Id = id;
            this.Name = name;
            this.UniqueName = uniqueName;
            this.Description = description;
            this.Method = method;
            this.AdditionalTypes = additionalTypes;
            this.AdditionalMethods = additionalMethods;
            this.Expected = expected;
            this.Arguments = arguments;
            this.Assert = assert;
            this.IgnoreILErrors = ignoreILErrors;
        }

        public override string ToString()
        {
            // For test explorer friendly format.
            return this.Name;
        }
    }
}
