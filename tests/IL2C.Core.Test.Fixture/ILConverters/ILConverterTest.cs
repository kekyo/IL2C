using System;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C.ILConverters
{
    [TestFixture]
    [Parallelizable(ParallelScope.All)]
    public sealed class ILConverterTest
    {
        #region Test infrastructure
        private static CaseInfo CreateCaseInfo(string name, MethodInfo method, MethodInfo[] additionalMethods, CaseAttribute testCase) =>
            new CaseInfo(name, method, additionalMethods,
                Case.TrapBreak.Equals(testCase.Expected) ?
                    TestFramework.Expected_TrapBreak :
                    TestUtilities.ConvertTo(testCase.Expected, method.ReturnType),
                testCase.Arguments.
                    Zip(method.GetParameters().Select(p => p.ParameterType), (arg, type) => TestUtilities.ConvertTo(arg, type)).
                    ToArray());

        private static CaseInfo[] GetTargetCases<T>()
        {
            var caseInfos =
                (from testCase in typeof(T).GetCustomAttributes<CaseAttribute>(true)
                 let method = typeof(T).GetMethod(
                     testCase.MethodName, BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly)    // Static method only for test entry
                 where method != null
                 let additionalMethods =
                    testCase.AdditionalMethodNames.
                    Select(amn => typeof(T).GetMethod(
                        amn, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly)).   // Both instance or static method
                    ToArray()
                 group new { testCase, method, additionalMethods } by method.Name).
                 SelectMany(g =>
                 {
                     var a = g.ToArray();
                     return (a.Length == 1) ?
                        a.Select(entry => CreateCaseInfo(entry.method.Name, entry.method, entry.additionalMethods, entry.testCase)) :
                        a.Select((entry, index) => CreateCaseInfo(entry.method.Name + "_" + index, entry.method, entry.additionalMethods, entry.testCase));
                    }).
                 OrderBy(caseInfo => caseInfo.Name).
                 ToArray();
            return caseInfos;
        }

        private static Task ExecuteTestAsync(CaseInfo caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo.Name, caseInfo.Method, caseInfo.AdditionalMethods, caseInfo.Expected, caseInfo.Arguments);
        #endregion

        #region Nop
        public static readonly CaseInfo[] _Nop = GetTargetCases<IL2C.ILConverters.Nop>();
        [Test]
        public static Task Nop([ValueSource("_Nop")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Break
        public static readonly CaseInfo[] _Break = GetTargetCases<IL2C.ILConverters.Break>();
        [Test]
        public static Task Break([ValueSource("_Break")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldnull
        public static readonly CaseInfo[] _Ldnull = GetTargetCases<IL2C.ILConverters.Ldnull>();
        [Test]
        public static Task Ldnull([ValueSource("_Ldnull")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldstr
        public static readonly CaseInfo[] _Ldstr = GetTargetCases<IL2C.ILConverters.Ldstr>();
        [Test]
        public static Task Ldstr([ValueSource("_Ldstr")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Branch
        public static readonly CaseInfo[] _Br_s = GetTargetCases<IL2C.ILConverters.Br_s>();
        [Test]
        public static Task Br_s([ValueSource("_Br_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Br = GetTargetCases<IL2C.ILConverters.Br>();
        [Test]
        public static Task Br([ValueSource("_Br")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Brtrue_s = GetTargetCases<IL2C.ILConverters.Brtrue_s>();
        [Test]
        public static Task Brtrue_s([ValueSource("_Brtrue_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Brtrue = GetTargetCases<IL2C.ILConverters.Brtrue>();
        [Test]
        public static Task Brtrue([ValueSource("_Brtrue")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Brfalse_s = GetTargetCases<IL2C.ILConverters.Brfalse_s>();
        [Test]
        public static Task Brfalse_s([ValueSource("_Brfalse_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Brfalse = GetTargetCases<IL2C.ILConverters.Brfalse>();
        [Test]
        public static Task Brfalse([ValueSource("_Brfalse")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Ret
        public static readonly CaseInfo[] _Ret = GetTargetCases<IL2C.ILConverters.Ret>();
        [Test]
        public static Task Ret([ValueSource("_Ret")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldarg
        public static readonly CaseInfo[] _Ldarg_0 = GetTargetCases<IL2C.ILConverters.Ldarg_0>();
        [Test]
        public static Task Ldarg_0([ValueSource("_Ldarg_0")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldarg_1 = GetTargetCases<IL2C.ILConverters.Ldarg_1>();
        [Test]
        public static Task Ldarg_1([ValueSource("_Ldarg_1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldarg_2 = GetTargetCases<IL2C.ILConverters.Ldarg_2>();
        [Test]
        public static Task Ldarg_2([ValueSource("_Ldarg_2")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldarg_3 = GetTargetCases<IL2C.ILConverters.Ldarg_3>();
        [Test]
        public static Task Ldarg_3([ValueSource("_Ldarg_3")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldarg_s = GetTargetCases<IL2C.ILConverters.Ldarg_s>();
        [Test]
        public static Task Ldarg_s([ValueSource("_Ldarg_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldarg = GetTargetCases<IL2C.ILConverters.Ldarg>();
        [Test]
        public static Task Ldarg([ValueSource("_Ldarg")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldc
        public static readonly CaseInfo[] _Ldc_i4_0 = GetTargetCases<IL2C.ILConverters.Ldc_i4_0>();
        [Test]
        public static Task Ldc_i4_0([ValueSource("_Ldc_i4_0")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_1 = GetTargetCases<IL2C.ILConverters.Ldc_i4_1>();
        [Test]
        public static Task Ldc_i4_1([ValueSource("_Ldc_i4_1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_2 = GetTargetCases<IL2C.ILConverters.Ldc_i4_2>();
        [Test]
        public static Task Ldc_i4_2([ValueSource("_Ldc_i4_2")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_3 = GetTargetCases<IL2C.ILConverters.Ldc_i4_3>();
        [Test]
        public static Task Ldc_i4_3([ValueSource("_Ldc_i4_3")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_4 = GetTargetCases<IL2C.ILConverters.Ldc_i4_4>();
        [Test]
        public static Task Ldc_i4_4([ValueSource("_Ldc_i4_4")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_5 = GetTargetCases<IL2C.ILConverters.Ldc_i4_5>();
        [Test]
        public static Task Ldc_i4_5([ValueSource("_Ldc_i4_5")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_6 = GetTargetCases<IL2C.ILConverters.Ldc_i4_6>();
        [Test]
        public static Task Ldc_i4_6([ValueSource("_Ldc_i4_6")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_7 = GetTargetCases<IL2C.ILConverters.Ldc_i4_7>();
        [Test]
        public static Task Ldc_i4_7([ValueSource("_Ldc_i4_7")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_8 = GetTargetCases<IL2C.ILConverters.Ldc_i4_8>();
        [Test]
        public static Task Ldc_i4_8([ValueSource("_Ldc_i4_8")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_m1 = GetTargetCases<IL2C.ILConverters.Ldc_i4_m1>();
        [Test]
        public static Task Ldc_i4_m1([ValueSource("_Ldc_i4_m1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4_s = GetTargetCases<IL2C.ILConverters.Ldc_i4_s>();
        [Test]
        public static Task Ldc_i4_s([ValueSource("_Ldc_i4_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i4 = GetTargetCases<IL2C.ILConverters.Ldc_i4>();
        [Test]
        public static Task Ldc_i4([ValueSource("_Ldc_i4")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_i8 = GetTargetCases<IL2C.ILConverters.Ldc_i8>();
        [Test]
        public static Task Ldc_i8([ValueSource("_Ldc_i8")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_r4 = GetTargetCases<IL2C.ILConverters.Ldc_r4>();
        [Test]
        public static Task Ldc_r4([ValueSource("_Ldc_r4")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldc_r8 = GetTargetCases<IL2C.ILConverters.Ldc_r8>();
        [Test]
        public static Task Ldc_r8([ValueSource("_Ldc_r8")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldloc
        public static readonly CaseInfo[] _Ldloc_0 = GetTargetCases<IL2C.ILConverters.Ldloc_0>();
        [Test]
        public static Task Ldloc_0([ValueSource("_Ldloc_0")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldloc_1 = GetTargetCases<IL2C.ILConverters.Ldloc_1>();
        [Test]
        public static Task Ldloc_1([ValueSource("_Ldloc_1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldloc_2 = GetTargetCases<IL2C.ILConverters.Ldloc_2>();
        [Test]
        public static Task Ldloc_2([ValueSource("_Ldloc_2")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldloc_3 = GetTargetCases<IL2C.ILConverters.Ldloc_3>();
        [Test]
        public static Task Ldloc_3([ValueSource("_Ldloc_3")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldloc_s = GetTargetCases<IL2C.ILConverters.Ldloc_s>();
        [Test]
        public static Task Ldloc_s([ValueSource("_Ldloc_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Ldloca_s = GetTargetCases<IL2C.ILConverters.Ldloca_s>();
        [Test]
        public static Task Ldloca_s([ValueSource("_Ldloca_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Stloc
        public static readonly CaseInfo[] _Stloc_0 = GetTargetCases<IL2C.ILConverters.Stloc_0>();
        [Test]
        public static Task Stloc_0([ValueSource("_Stloc_0")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Stloc_1 = GetTargetCases<IL2C.ILConverters.Stloc_1>();
        [Test]
        public static Task Stloc_1([ValueSource("_Stloc_1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Stloc_2 = GetTargetCases<IL2C.ILConverters.Stloc_2>();
        [Test]
        public static Task Stloc_2([ValueSource("_Stloc_2")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Stloc_3 = GetTargetCases<IL2C.ILConverters.Stloc_3>();
        [Test]
        public static Task Stloc_3([ValueSource("_Stloc_3")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Stloc_s = GetTargetCases<IL2C.ILConverters.Stloc_s>();
        [Test]
        public static Task Stloc_s([ValueSource("_Stloc_s")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Dup
        public static readonly CaseInfo[] _Dup = GetTargetCases<IL2C.ILConverters.Dup>();
        [Test]
        public static Task Dup([ValueSource("_Dup")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Arithmetical
        public static readonly CaseInfo[] _Add = GetTargetCases<IL2C.ILConverters.Add>();
        [Test]
        public static Task Add([ValueSource("_Add")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Sub = GetTargetCases<IL2C.ILConverters.Sub>();
        [Test]
        public static Task Sub([ValueSource("_Sub")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Mul = GetTargetCases<IL2C.ILConverters.Mul>();
        [Test]
        public static Task Mul([ValueSource("_Mul")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Div = GetTargetCases<IL2C.ILConverters.Div>();
        [Test]
        public static Task Div([ValueSource("_Div")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Rem = GetTargetCases<IL2C.ILConverters.Rem>();
        [Test]
        public static Task Rem([ValueSource("_Rem")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Logical
        public static readonly CaseInfo[] _And = GetTargetCases<IL2C.ILConverters.And>();
        [Test]
        public static Task And([ValueSource("_And")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Or = GetTargetCases<IL2C.ILConverters.Or>();
        [Test]
        public static Task Or([ValueSource("_Or")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Xor = GetTargetCases<IL2C.ILConverters.Xor>();
        [Test]
        public static Task Xor([ValueSource("_Xor")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion

        #region Conv
        public static readonly CaseInfo[] _Conv_i1 = GetTargetCases<IL2C.ILConverters.Conv_i1>();
        [Test]
        public static Task Conv_i1([ValueSource("_Conv_i1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Conv_i2 = GetTargetCases<IL2C.ILConverters.Conv_i2>();
        [Test]
        public static Task Conv_i2([ValueSource("_Conv_i2")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Conv_i = GetTargetCases<IL2C.ILConverters.Conv_i>();
        [Test]
        public static Task Conv_i([ValueSource("_Conv_i")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Conv_u1 = GetTargetCases<IL2C.ILConverters.Conv_u1>();
        [Test]
        public static Task Conv_u1([ValueSource("_Conv_u1")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);

        public static readonly CaseInfo[] _Conv_u2 = GetTargetCases<IL2C.ILConverters.Conv_u2>();
        [Test]
        public static Task Conv_u2([ValueSource("_Conv_u2")] CaseInfo caseInfo) =>
            ExecuteTestAsync(caseInfo);
        #endregion
    }
}
