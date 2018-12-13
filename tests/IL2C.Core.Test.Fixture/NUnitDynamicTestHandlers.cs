using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace IL2C
{
    internal sealed class TestMethod
        : NUnit.Framework.Internal.TestMethod, NUnit.Framework.Interfaces.ITest
    {
        private string className;
        private string methodName;

        public TestMethod(
            NUnit.Framework.Interfaces.IMethodInfo methodInfo,
            NUnit.Framework.Interfaces.ITest parentSuite)
            : base(methodInfo, parentSuite as NUnit.Framework.Internal.ParameterizedMethodSuite)
        {
        }

        public new string ClassName => className ?? base.ClassName;

        public override string MethodName => methodName ?? base.MethodName;

        internal void SetMethod(string className, string methodName)
        {
            this.className = className;
            this.methodName = methodName;
        }
    }

    internal sealed class TestCaseBuilder : NUnit.Framework.Internal.Builders.NUnitTestCaseBuilder
    {
        private readonly NUnit.Framework.Internal.Randomizer _randomizer = NUnit.Framework.Internal.Randomizer.CreateRandomizer();
        private readonly NUnit.Framework.Internal.TestNameGenerator _nameGenerator = new NUnit.Framework.Internal.TestNameGenerator();

        public TestCaseBuilder()
        {
        }

        public new NUnit.Framework.Internal.TestMethod BuildTestMethod(
            NUnit.Framework.Interfaces.IMethodInfo method, NUnit.Framework.Internal.Test parentSuite, NUnit.Framework.Internal.TestCaseParameters parms)
        {
            TestMethod testMethod = new TestMethod(method, parentSuite)
            {
                Seed = _randomizer.Next()
            };

            //CheckTestMethodAttributes(testMethod);

            // DIRTY: NUnit's NUnitTestCaseBuilder class does collusion with the TestMethod class sharing internal field for the 'parms'.
            //  It private method sets the parms.
            //CheckTestMethodSignature(testMethod, parms);
            var t = typeof(NUnit.Framework.Internal.TestMethod);
            var f = t.GetField("parms", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            f.SetValue(testMethod, parms);

            if (parms == null || parms.Arguments == null)
            {
                testMethod.ApplyAttributesToTest(method.MethodInfo);
            }
            string fullName = testMethod.Method.TypeInfo.FullName;
            if (parentSuite != null)
            {
                fullName = parentSuite.FullName;
            }
            if (parms != null)
            {
                parms.ApplyToTest(testMethod);
                if (parms.TestName != null)
                {
                    testMethod.Name = (parms.TestName.Contains("{") ? new NUnit.Framework.Internal.TestNameGenerator(parms.TestName).GetDisplayName(testMethod, parms.OriginalArguments) : parms.TestName);
                }
                //else if (parms.ArgDisplayNames != null)
                //{
                //    testMethod.Name = testMethod.Name + "(" + string.Join(", ", parms.ArgDisplayNames) + ")";
                //}
                else
                {
                    testMethod.Name = _nameGenerator.GetDisplayName(testMethod, parms.OriginalArguments);
                }
            }
            else
            {
                testMethod.Name = _nameGenerator.GetDisplayName(testMethod, null);
            }
            testMethod.FullName = fullName + "." + testMethod.Name;
            return testMethod;
        }
    }

    [AttributeUsage(AttributeTargets.Method)]
    public sealed class AAATestAttribute
        : NUnit.Framework.TestCaseSourceAttribute, NUnit.Framework.Interfaces.ITestBuilder
    {
        public AAATestAttribute(string name)
            : base(name)
        {
        }

        public new IEnumerable<NUnit.Framework.Internal.TestMethod> BuildFrom(
            NUnit.Framework.Interfaces.IMethodInfo method,
            NUnit.Framework.Internal.Test suite)
        {
            var testCases = base.BuildFrom(method, suite).
                ToArray();

            return testCases;
        }
    }

    [AttributeUsage(AttributeTargets.Method)]
    public sealed class DynamicTestAttribute
        : NUnit.Framework.NUnitAttribute, NUnit.Framework.Interfaces.ITestBuilder, NUnit.Framework.Interfaces.IImplyFixture
    {
        private readonly TestCaseBuilder _builder = new TestCaseBuilder();

        public DynamicTestAttribute(params Type[] targetTypes)
        {
            this.TargetTypes = targetTypes;
        }

        public Type[] TargetTypes { get; }

        public IEnumerable<NUnit.Framework.Internal.TestMethod> BuildFrom(
            NUnit.Framework.Interfaces.IMethodInfo method,
            NUnit.Framework.Internal.Test suite)
        {
            var testCases = this.TargetTypes.
                SelectMany(TestUtilities.GetTestCaseInformations).
                Select(testCase => _builder.BuildTestMethod(
                    method,
                    suite,
                    new NUnit.Framework.Internal.TestCaseParameters(new object[] { testCase }))).
                ToArray();

            return testCases;
        }
    }
}
