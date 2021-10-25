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

using IL2C.Internal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace IL2C
{
    internal sealed class TestMethod
        : NUnit.Framework.Internal.TestMethod, NUnit.Framework.Interfaces.ITest
    {
        public TestMethod(
            NUnit.Framework.Interfaces.IMethodInfo methodInfo,
            NUnit.Framework.Interfaces.ITest parentSuite,
            string className,
            string methodName)
            : base(methodInfo, parentSuite as NUnit.Framework.Internal.ParameterizedMethodSuite)
        {
            this.ClassName = className;
            this.MethodName = methodName;
        }

        public new string ClassName { get; }

        public override string MethodName { get; }

        private new void PopulateTestNode(NUnit.Framework.Interfaces.TNode thisNode, bool recursive)
        {
            thisNode.AddAttribute("id", this.Id.ToString());
            thisNode.AddAttribute("name", this.Name);
            thisNode.AddAttribute("fullname", this.FullName);
            thisNode.AddAttribute("methodname", this.MethodName);
            thisNode.AddAttribute("classname", this.ClassName);
            thisNode.AddAttribute("runstate", this.RunState.ToString());

            if (Properties.Keys.Count > 0)
                Properties.AddToXml(thisNode, recursive);
        }

        public override NUnit.Framework.Interfaces.TNode AddToXml(NUnit.Framework.Interfaces.TNode parentNode, bool recursive)
        {
            var thisNode = parentNode.AddElement(XmlElementName);

            this.PopulateTestNode(thisNode, recursive);
            thisNode.AddAttribute("seed", this.Seed.ToString());

            return thisNode;
        }

        public override string ToString()
        {
            return string.Format("{0}.{1}", this.ClassName, this.MethodName);
        }
    }

    // HACK: Depends NUnit 3.11.0 internals
    [AttributeUsage(AttributeTargets.Class)]
    public sealed class CoreTestTargetAttribute
        : NUnit.Framework.NUnitAttribute, NUnit.Framework.Interfaces.IFixtureBuilder2, NUnit.Framework.Interfaces.ITestData
    {
        private static readonly NUnit.Framework.Interfaces.IMethodInfo executeMethod =
            new NUnit.Framework.Internal.MethodWrapper(typeof(TestFramework), "ExecuteTestAsync");
        private static readonly object[] emptyArgs = new object[0];

        private readonly NUnit.Framework.Internal.Randomizer _randomizer =
            NUnit.Framework.Internal.Randomizer.CreateRandomizer();

        public CoreTestTargetAttribute(NUnit.Framework.ParallelScope parallelScope = NUnit.Framework.ParallelScope.All)
        {
            this.ParallelScope = parallelScope;

            this.Properties = new NUnit.Framework.Internal.PropertyBag();
            AddProperty(this.Properties, NUnit.Framework.Internal.PropertyNames.ParallelScope, parallelScope);
        }

        private static void AddProperty(NUnit.Framework.Interfaces.IPropertyBag propertyBag, string name, object value)
        {
            propertyBag.Add(name, value);
        }

        public string TestName => null;

        public NUnit.Framework.Interfaces.RunState RunState => NUnit.Framework.Interfaces.RunState.Runnable;

        public object[] Arguments => emptyArgs;

        public NUnit.Framework.Interfaces.IPropertyBag Properties { get; }

        public NUnit.Framework.ParallelScope ParallelScope { get; }

        private NUnit.Framework.Internal.TestMethod BuildTestMethod(
            NUnit.Framework.Internal.Test parentSuite,
            TestCaseInformation testCase)
        {
            var testMethod = new TestMethod(
                executeMethod, parentSuite, testCase.Method.DeclaringType.FullName, testCase.Method.Name)
            {
                Seed = _randomizer.Next()
            };

            var parms = new NUnit.Framework.Internal.TestCaseParameters(new object[] { testCase });

            //CheckTestMethodAttributes(testMethod);

            // DIRTY: NUnit's NUnitTestCaseBuilder class does collusion with the TestMethod class sharing internal field for the 'parms'.
            //  It private method sets the parms.
            //CheckTestMethodSignature(testMethod, parms);
            var t = typeof(NUnit.Framework.Internal.TestMethod);
            var f = t.GetField("parms", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            f.SetValue(testMethod, parms);

            parms.ApplyToTest(testMethod);

            var name = string.Format(
                "{0}({1})",
                testCase.Name,
                string.Join(",", testCase.Arguments.Select(Utilities.GetCSharpLanguageExpression)));
            testMethod.Name = name;
            testMethod.FullName = string.Format(
                "{0}.{1}.{2}",
                testCase.CategoryName,
                testCase.Id,
                name);

            return testMethod;
        }

        private IEnumerable<NUnit.Framework.Internal.TestSuite> BuildFrom(
            NUnit.Framework.Interfaces.ITypeInfo typeInfo,
            Func<MethodInfo, bool> filter)
        {
            return
                TestUtilities.ExtractTestCasesFromCoreTestTarget().
                Select(byCategory =>
                {
                    var rootSuite = new NUnit.Framework.Internal.TestSuite(byCategory.Key);
                    AddProperty(rootSuite.Properties, NUnit.Framework.Internal.PropertyNames.ParallelScope, this.ParallelScope);
                    foreach (var byId in byCategory.Value)
                    {
                        var subSuite = new NUnit.Framework.Internal.TestSuite(byId.Key);
                        AddProperty(subSuite.Properties, NUnit.Framework.Internal.PropertyNames.ParallelScope, this.ParallelScope);
                        foreach (var testCase in byId.Value.
                            Where(testCase => filter(testCase.Method)))
                        {
                            var test = this.BuildTestMethod(
                                subSuite,
                                testCase);
                            AddProperty(test.Properties, NUnit.Framework.Internal.PropertyNames.ParallelScope, this.ParallelScope);
                            subSuite.Add(test);
                        }
                        rootSuite.Add(subSuite);
                    }
                    return rootSuite;
                });
        }

        public IEnumerable<NUnit.Framework.Internal.TestSuite> BuildFrom(
            NUnit.Framework.Interfaces.ITypeInfo typeInfo)
        {
            return this.BuildFrom(typeInfo, _ => true);
        }

        public IEnumerable<NUnit.Framework.Internal.TestSuite> BuildFrom(
            NUnit.Framework.Interfaces.ITypeInfo typeInfo,
            NUnit.Framework.Interfaces.IPreFilter filter)
        {
            return this.BuildFrom(typeInfo, method => filter.IsMatch(method.DeclaringType, method));
        }
    }
}
