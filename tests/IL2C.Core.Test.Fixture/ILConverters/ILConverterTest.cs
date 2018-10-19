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
        #region Nop
        public static readonly TestCaseInformation[] _Nop = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Nop>();
        [Test]
        public static Task Nop([ValueSource("_Nop")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Break
        public static readonly TestCaseInformation[] _Break = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Break>();
        [Test]
        public static Task Break([ValueSource("_Break")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Ldnull
        public static readonly TestCaseInformation[] _Ldnull = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldnull>();
        [Test]
        public static Task Ldnull([ValueSource("_Ldnull")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Ldstr
        public static readonly TestCaseInformation[] _Ldstr = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldstr>();
        [Test]
        public static Task Ldstr([ValueSource("_Ldstr")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Branch
        public static readonly TestCaseInformation[] _Br_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Br_s>();
        [Test]
        public static Task Br_s([ValueSource("_Br_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Br = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Br>();
        [Test]
        public static Task Br([ValueSource("_Br")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Brtrue_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brtrue_s>();
        [Test]
        public static Task Brtrue_s([ValueSource("_Brtrue_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Brtrue = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brtrue>();
        [Test]
        public static Task Brtrue([ValueSource("_Brtrue")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Brfalse_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brfalse_s>();
        [Test]
        public static Task Brfalse_s([ValueSource("_Brfalse_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Brfalse = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Brfalse>();
        [Test]
        public static Task Brfalse([ValueSource("_Brfalse")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Call
        public static readonly TestCaseInformation[] _Call = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Call>();
        [Test]
        public static Task Call([ValueSource("_Call")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Ret
        public static readonly TestCaseInformation[] _Ret = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ret>();
        [Test]
        public static Task Ret([ValueSource("_Ret")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Ldarg
        public static readonly TestCaseInformation[] _Ldarg_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_0>();
        [Test]
        public static Task Ldarg_0([ValueSource("_Ldarg_0")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldarg_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_1>();
        [Test]
        public static Task Ldarg_1([ValueSource("_Ldarg_1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldarg_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_2>();
        [Test]
        public static Task Ldarg_2([ValueSource("_Ldarg_2")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldarg_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_3>();
        [Test]
        public static Task Ldarg_3([ValueSource("_Ldarg_3")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldarg_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg_s>();
        [Test]
        public static Task Ldarg_s([ValueSource("_Ldarg_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldarg = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldarg>();
        [Test]
        public static Task Ldarg([ValueSource("_Ldarg")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Ldc
        public static readonly TestCaseInformation[] _Ldc_i4_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_0>();
        [Test]
        public static Task Ldc_i4_0([ValueSource("_Ldc_i4_0")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_1>();
        [Test]
        public static Task Ldc_i4_1([ValueSource("_Ldc_i4_1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_2>();
        [Test]
        public static Task Ldc_i4_2([ValueSource("_Ldc_i4_2")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_3>();
        [Test]
        public static Task Ldc_i4_3([ValueSource("_Ldc_i4_3")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_4 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_4>();
        [Test]
        public static Task Ldc_i4_4([ValueSource("_Ldc_i4_4")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_5 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_5>();
        [Test]
        public static Task Ldc_i4_5([ValueSource("_Ldc_i4_5")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_6 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_6>();
        [Test]
        public static Task Ldc_i4_6([ValueSource("_Ldc_i4_6")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_7 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_7>();
        [Test]
        public static Task Ldc_i4_7([ValueSource("_Ldc_i4_7")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_8 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_8>();
        [Test]
        public static Task Ldc_i4_8([ValueSource("_Ldc_i4_8")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_m1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_m1>();
        [Test]
        public static Task Ldc_i4_m1([ValueSource("_Ldc_i4_m1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4_s>();
        [Test]
        public static Task Ldc_i4_s([ValueSource("_Ldc_i4_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i4 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i4>();
        [Test]
        public static Task Ldc_i4([ValueSource("_Ldc_i4")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_i8 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_i8>();
        [Test]
        public static Task Ldc_i8([ValueSource("_Ldc_i8")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_r4 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_r4>();
        [Test]
        public static Task Ldc_r4([ValueSource("_Ldc_r4")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldc_r8 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldc_r8>();
        [Test]
        public static Task Ldc_r8([ValueSource("_Ldc_r8")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Ldloc
        public static readonly TestCaseInformation[] _Ldloc_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_0>();
        [Test]
        public static Task Ldloc_0([ValueSource("_Ldloc_0")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldloc_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_1>();
        [Test]
        public static Task Ldloc_1([ValueSource("_Ldloc_1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldloc_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_2>();
        [Test]
        public static Task Ldloc_2([ValueSource("_Ldloc_2")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldloc_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_3>();
        [Test]
        public static Task Ldloc_3([ValueSource("_Ldloc_3")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldloc_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloc_s>();
        [Test]
        public static Task Ldloc_s([ValueSource("_Ldloc_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Ldloca_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Ldloca_s>();
        [Test]
        public static Task Ldloca_s([ValueSource("_Ldloca_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Stloc
        public static readonly TestCaseInformation[] _Stloc_0 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_0>();
        [Test]
        public static Task Stloc_0([ValueSource("_Stloc_0")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Stloc_1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_1>();
        [Test]
        public static Task Stloc_1([ValueSource("_Stloc_1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Stloc_2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_2>();
        [Test]
        public static Task Stloc_2([ValueSource("_Stloc_2")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Stloc_3 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_3>();
        [Test]
        public static Task Stloc_3([ValueSource("_Stloc_3")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Stloc_s = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Stloc_s>();
        [Test]
        public static Task Stloc_s([ValueSource("_Stloc_s")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Dup
        public static readonly TestCaseInformation[] _Dup = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Dup>();
        [Test]
        public static Task Dup([ValueSource("_Dup")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Arithmetical
        public static readonly TestCaseInformation[] _Add = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Add>();
        [Test]
        public static Task Add([ValueSource("_Add")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Sub = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Sub>();
        [Test]
        public static Task Sub([ValueSource("_Sub")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Mul = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Mul>();
        [Test]
        public static Task Mul([ValueSource("_Mul")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Div = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Div>();
        [Test]
        public static Task Div([ValueSource("_Div")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Rem = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Rem>();
        [Test]
        public static Task Rem([ValueSource("_Rem")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Logical
        public static readonly TestCaseInformation[] _And = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.And>();
        [Test]
        public static Task And([ValueSource("_And")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Or = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Or>();
        [Test]
        public static Task Or([ValueSource("_Or")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Xor = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Xor>();
        [Test]
        public static Task Xor([ValueSource("_Xor")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion

        #region Conv
        public static readonly TestCaseInformation[] _Conv_i1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_i1>();
        [Test]
        public static Task Conv_i1([ValueSource("_Conv_i1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Conv_i2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_i2>();
        [Test]
        public static Task Conv_i2([ValueSource("_Conv_i2")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Conv_i = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_i>();
        [Test]
        public static Task Conv_i([ValueSource("_Conv_i")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Conv_u1 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_u1>();
        [Test]
        public static Task Conv_u1([ValueSource("_Conv_u1")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();

        public static readonly TestCaseInformation[] _Conv_u2 = TestUtilities.GetTestCaseInformations<IL2C.ILConverters.Conv_u2>();
        [Test]
        public static Task Conv_u2([ValueSource("_Conv_u2")] TestCaseInformation caseInfo) =>
            caseInfo.ExecuteTestAsync();
        #endregion
    }
}
