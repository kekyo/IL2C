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

    [AttributeUsage(AttributeTargets.Method)]
    public sealed class DynamicTestAttribute
        : NUnit.Framework.NUnitAttribute, NUnit.Framework.Interfaces.ITestBuilder, NUnit.Framework.Interfaces.IImplyFixture
    {
        private readonly NUnit.Framework.Internal.Randomizer _randomizer =
            NUnit.Framework.Internal.Randomizer.CreateRandomizer();

        public DynamicTestAttribute(params Type[] targetTypes)
        {
            this.TargetTypes = targetTypes;
        }

        public Type[] TargetTypes { get; }

        private NUnit.Framework.Internal.TestMethod BuildTestMethod(
            NUnit.Framework.Interfaces.IMethodInfo method,
            NUnit.Framework.Internal.Test parentSuite,
            TestCaseInformation testCase)
        {
            var testMethod = new TestMethod(method, parentSuite, testCase.Method.DeclaringType.FullName, testCase.Method.Name)
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

        public IEnumerable<NUnit.Framework.Internal.TestMethod> BuildFrom(
            NUnit.Framework.Interfaces.IMethodInfo method,
            NUnit.Framework.Internal.Test suite)
        {
            var testCases = this.TargetTypes.
                SelectMany(TestUtilities.GetTestCaseInformations).
                Select(testCase => this.BuildTestMethod(method, suite, testCase)).
                ToArray();

            return testCases;
        }
    }
}
