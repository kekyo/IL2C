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
