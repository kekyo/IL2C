using System;
using System.Linq;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    [Parallelizable(ParallelScope.All)]
    public sealed class ILConvertersTest
    {
        #region Nop
        public static readonly TestCaseInformation[] _Nop = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Nop>();
        [Test]
        public static Task Nop([ValueSource(nameof(_Nop))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Break
        public static readonly TestCaseInformation[] _Break = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Break>();
        [Test]
        public static Task Break([ValueSource(nameof(_Break))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldnull
        public static readonly TestCaseInformation[] _Ldnull = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldnull>();
        [Test]
        public static Task Ldnull([ValueSource(nameof(_Ldnull))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldstr
        public static readonly TestCaseInformation[] _Ldstr = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldstr>();
        [Test]
        public static Task Ldstr([ValueSource(nameof(_Ldstr))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Branch
        public static readonly TestCaseInformation[] _Br_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Br_s>();
        [Test]
        public static Task Br_s([ValueSource(nameof(_Br_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Br = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Br>();
        [Test]
        public static Task Br([ValueSource(nameof(_Br))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Brtrue_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brtrue_s>();
        [Test]
        public static Task Brtrue_s([ValueSource(nameof(_Brtrue_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Brtrue = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brtrue>();
        [Test]
        public static Task Brtrue([ValueSource(nameof(_Brtrue))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Brfalse_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brfalse_s>();
        [Test]
        public static Task Brfalse_s([ValueSource(nameof(_Brfalse_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Brfalse = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brfalse>();
        [Test]
        public static Task Brfalse([ValueSource(nameof(_Brfalse))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Call
        public static readonly TestCaseInformation[] _Call =
            TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call>().
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call_Newslot>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call_Virtual>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call_Newslot_Virtual>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call_Overload>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call_Overload_Virtual>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call_Overload_Newslot_Virtual>()).
            ToArray();
        [Test]
        public static Task Call([ValueSource(nameof(_Call))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Callvirt =
            TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt>().
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived1>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived2>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived1_Newslot>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived1_Newslot_Virtual>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived2_Newslot>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived2_Newslot_Virtual>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived3_Newslot>()).
            Concat(TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Callvirt_Derived3_Newslot_Virtual>()).
            ToArray();
        [Test]
        public static Task Callvirt([ValueSource(nameof(_Callvirt))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Ret
        public static readonly TestCaseInformation[] _Ret = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ret>();
        [Test]
        public static Task Ret([ValueSource(nameof(_Ret))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldarg
        public static readonly TestCaseInformation[] _Ldarg_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_0>();
        [Test]
        public static Task Ldarg_0([ValueSource(nameof(_Ldarg_0))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldarg_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_1>();
        [Test]
        public static Task Ldarg_1([ValueSource(nameof(_Ldarg_1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldarg_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_2>();
        [Test]
        public static Task Ldarg_2([ValueSource(nameof(_Ldarg_2))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldarg_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_3>();
        [Test]
        public static Task Ldarg_3([ValueSource(nameof(_Ldarg_3))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldarg_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_s>();
        [Test]
        public static Task Ldarg_s([ValueSource(nameof(_Ldarg_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldarg = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg>();
        [Test]
        public static Task Ldarg([ValueSource(nameof(_Ldarg))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldarga_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarga_s>();
        [Test]
        public static Task Ldarga_s([ValueSource(nameof(_Ldarga_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldc
        public static readonly TestCaseInformation[] _Ldc_i4_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_0>();
        [Test]
        public static Task Ldc_i4_0([ValueSource(nameof(_Ldc_i4_0))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_1>();
        [Test]
        public static Task Ldc_i4_1([ValueSource(nameof(_Ldc_i4_1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_2>();
        [Test]
        public static Task Ldc_i4_2([ValueSource(nameof(_Ldc_i4_2))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_3>();
        [Test]
        public static Task Ldc_i4_3([ValueSource(nameof(_Ldc_i4_3))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_4 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_4>();
        [Test]
        public static Task Ldc_i4_4([ValueSource(nameof(_Ldc_i4_4))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_5 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_5>();
        [Test]
        public static Task Ldc_i4_5([ValueSource(nameof(_Ldc_i4_5))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_6 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_6>();
        [Test]
        public static Task Ldc_i4_6([ValueSource(nameof(_Ldc_i4_6))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_7 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_7>();
        [Test]
        public static Task Ldc_i4_7([ValueSource(nameof(_Ldc_i4_7))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_8 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_8>();
        [Test]
        public static Task Ldc_i4_8([ValueSource(nameof(_Ldc_i4_8))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_m1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_m1>();
        [Test]
        public static Task Ldc_i4_m1([ValueSource(nameof(_Ldc_i4_m1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_s>();
        [Test]
        public static Task Ldc_i4_s([ValueSource(nameof(_Ldc_i4_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i4 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4>();
        [Test]
        public static Task Ldc_i4([ValueSource(nameof(_Ldc_i4))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_i8 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i8>();
        [Test]
        public static Task Ldc_i8([ValueSource(nameof(_Ldc_i8))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_r4 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_r4>();
        [Test]
        public static Task Ldc_r4([ValueSource(nameof(_Ldc_r4))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldc_r8 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_r8>();
        [Test]
        public static Task Ldc_r8([ValueSource(nameof(_Ldc_r8))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Ldloc
        public static readonly TestCaseInformation[] _Ldloc_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_0>();
        [Test]
        public static Task Ldloc_0([ValueSource(nameof(_Ldloc_0))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldloc_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_1>();
        [Test]
        public static Task Ldloc_1([ValueSource(nameof(_Ldloc_1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldloc_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_2>();
        [Test]
        public static Task Ldloc_2([ValueSource(nameof(_Ldloc_2))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldloc_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_3>();
        [Test]
        public static Task Ldloc_3([ValueSource(nameof(_Ldloc_3))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldloc_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_s>();
        [Test]
        public static Task Ldloc_s([ValueSource(nameof(_Ldloc_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Ldloca_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloca_s>();
        [Test]
        public static Task Ldloca_s([ValueSource(nameof(_Ldloca_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Stloc
        public static readonly TestCaseInformation[] _Stloc_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_0>();
        [Test]
        public static Task Stloc_0([ValueSource(nameof(_Stloc_0))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Stloc_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_1>();
        [Test]
        public static Task Stloc_1([ValueSource(nameof(_Stloc_1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Stloc_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_2>();
        [Test]
        public static Task Stloc_2([ValueSource(nameof(_Stloc_2))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Stloc_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_3>();
        [Test]
        public static Task Stloc_3([ValueSource(nameof(_Stloc_3))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Stloc_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_s>();
        [Test]
        public static Task Stloc_s([ValueSource(nameof(_Stloc_s))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Dup
        public static readonly TestCaseInformation[] _Dup = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Dup>();
        [Test]
        public static Task Dup([ValueSource(nameof(_Dup))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Arithmetical
        public static readonly TestCaseInformation[] _Add = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Add>();
        [Test]
        public static Task Add([ValueSource(nameof(_Add))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Sub = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Sub>();
        [Test]
        public static Task Sub([ValueSource(nameof(_Sub))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Mul = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Mul>();
        [Test]
        public static Task Mul([ValueSource(nameof(_Mul))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Div = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Div>();
        [Test]
        public static Task Div([ValueSource(nameof(_Div))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Rem = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Rem>();
        [Test]
        public static Task Rem([ValueSource(nameof(_Rem))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Logical
        public static readonly TestCaseInformation[] _And = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.And>();
        [Test]
        public static Task And([ValueSource(nameof(_And))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Or = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Or>();
        [Test]
        public static Task Or([ValueSource(nameof(_Or))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Xor = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Xor>();
        [Test]
        public static Task Xor([ValueSource(nameof(_Xor))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Conv
        public static readonly TestCaseInformation[] _Conv_i1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_i1>();
        [Test]
        public static Task Conv_i1([ValueSource(nameof(_Conv_i1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Conv_i2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_i2>();
        [Test]
        public static Task Conv_i2([ValueSource(nameof(_Conv_i2))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Conv_i = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_i>();
        [Test]
        public static Task Conv_i([ValueSource(nameof(_Conv_i))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Conv_u1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_u1>();
        [Test]
        public static Task Conv_u1([ValueSource(nameof(_Conv_u1))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Conv_u2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_u2>();
        [Test]
        public static Task Conv_u2([ValueSource(nameof(_Conv_u2))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Box
        public static readonly TestCaseInformation[] _Box = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Box>();
        [Test]
        public static Task Box([ValueSource(nameof(_Box))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);

        public static readonly TestCaseInformation[] _Unbox_any = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Unbox_any>();
        [Test]
        public static Task Unbox_any([ValueSource(nameof(_Unbox_any))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion

        #region Cast
        public static readonly TestCaseInformation[] _Isinst = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Isinst>();
        [Test]
        public static Task Isinst([ValueSource(nameof(_Isinst))] TestCaseInformation caseInfo) =>
            TestFramework.ExecuteTestAsync(caseInfo);
        #endregion
    }
}
