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
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public interface IInterfaceType1
    {
        string GetStringFromInt32(int value);
    }

    public class InstanceImplementType : IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 100;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public interface IInterfaceType2
    {
        string GetStringFromInt64(long value);
    }

    public class InstanceMultipleImplementType : IInterfaceType1, IInterfaceType2
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly long rhs2 = 200;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        public string GetStringFromInt64(long value)
        {
            return (value + rhs2).ToString();
        }
    }

    public interface IInterfaceType3
    {
        string GetStringFromInt32(int value);
    }

    public class InstanceMultipleImplementUnifiedType : IInterfaceType1, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 100;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceMultipleImplementExplicitlyType : IInterfaceType1, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs3 = 200;

        string IInterfaceType1.GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType3.GetStringFromInt32(int value)
        {
            return (value + rhs3).ToString();
        }
    }

    public class InstanceMultipleImplementCombinationType : IInterfaceType1, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs3 = 200;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType3.GetStringFromInt32(int value)
        {
            return (value + rhs3).ToString();
        }
    }

    public interface IInterfaceType4
    {
        string GetStringFromInt32(int value);
        string GetStringFromInt64(long value);
    }

    public class InstanceMultipleCombinedImplementType : IInterfaceType4
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly long rhs2 = 200;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType4.GetStringFromInt64(long value)
        {
            return (value + rhs2).ToString();
        }
    }

    public class InstanceMultipleCombinedAndParallelImplementType : IInterfaceType4
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs2 = 200;
        private readonly long rhs3 = 300;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType4.GetStringFromInt32(int value)
        {
            return (value + rhs2).ToString();
        }

        string IInterfaceType4.GetStringFromInt64(long value)
        {
            return (value + rhs3).ToString();
        }
    }

    public class InstanceMultipleCombinedImplementCombinationType1 : IInterfaceType1, IInterfaceType4
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs2 = 200;
        private readonly long rhs3 = 300;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType4.GetStringFromInt32(int value)
        {
            return (value + rhs2).ToString();
        }

        string IInterfaceType4.GetStringFromInt64(long value)
        {
            return (value + rhs3).ToString();
        }
    }

    public class InstanceMultipleCombinedImplementCombinationType2 : IInterfaceType1, IInterfaceType4
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs2 = 200;
        private readonly long rhs3 = 300;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType1.GetStringFromInt32(int value)
        {
            return (value + rhs2).ToString();
        }

        string IInterfaceType4.GetStringFromInt64(long value)
        {
            return (value + rhs3).ToString();
        }
    }

    public class InstanceMultipleImplementDepthBaseType
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 100;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceMultipleImplement1DepthType : InstanceMultipleImplementDepthBaseType, IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 200;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceMultipleImplement2DepthType : InstanceMultipleImplement1DepthType, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 300;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceMultipleImplement3DepthType : InstanceMultipleImplement2DepthType
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 400;

        public new string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    [TestId("TypeRelations")]
    [TestCase("223", "InstanceImplement", 123, IncludeTypes = new[] { typeof(InstanceImplementType), typeof(IInterfaceType1) })]
    [TestCase("223", "InstanceImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceImplementType), typeof(IInterfaceType1) })]
    [TestCase("223", "InstanceMultipleImplement1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("223", "InstanceMultipleImplementFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("323", "InstanceMultipleImplement2", 123L, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("323", "InstanceMultipleImplementFromInterface2", 123L, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("223", "InstanceMultipleImplementUnified1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementUnifiedType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementUnifiedFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementUnifiedType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementUnifiedFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementUnifiedType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementCombination", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementCombinationType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementCombinationFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementCombinationType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("323", "InstanceMultipleImplementCombinationFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementCombinationType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementExplicitlyFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementExplicitlyType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("323", "InstanceMultipleImplementExplicitlyFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementExplicitlyType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleCombinedImplement", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementType), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombined1ImplementFromInterface4", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementType), typeof(IInterfaceType4) })]
    [TestCase("323", "InstanceMultipleCombined2ImplementFromInterface4", 123L, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementType), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombinedAndParallelImplement", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedAndParallelImplementType), typeof(IInterfaceType4) })]
    [TestCase("323", "InstanceMultipleCombinedAndParallel1ImplementFromInterface4", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedAndParallelImplementType), typeof(IInterfaceType4) })]
    [TestCase("423", "InstanceMultipleCombinedAndParallel2ImplementFromInterface4", 123L, IncludeTypes = new[] { typeof(InstanceMultipleCombinedAndParallelImplementType), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombinedImplementCombination1", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType1), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombined2ImplementCombination1FromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType1), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("323", "InstanceMultipleCombined1ImplementCombination1FromInterface4", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType1), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("423", "InstanceMultipleCombined2ImplementCombination1FromInterface4", 123L, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType1), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombinedImplementCombination2", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType2), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("323", "InstanceMultipleCombined2ImplementCombination2FromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType2), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombined1ImplementCombination2FromInterface4", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType2), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("423", "InstanceMultipleCombined2ImplementCombination2FromInterface4", 123L, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementCombinationType2), typeof(IInterfaceType1), typeof(IInterfaceType4) })]
    [TestCase("523", "InstanceMultipleImplementDepth", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplement3DepthType), typeof(InstanceMultipleImplement2DepthType), typeof(InstanceMultipleImplement1DepthType), typeof(InstanceMultipleImplementDepthBaseType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("323", "InstanceMultipleImplementDepthFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplement3DepthType), typeof(InstanceMultipleImplement2DepthType), typeof(InstanceMultipleImplement1DepthType), typeof(InstanceMultipleImplementDepthBaseType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("423", "InstanceMultipleImplementDepthFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplement3DepthType), typeof(InstanceMultipleImplement2DepthType), typeof(InstanceMultipleImplement1DepthType), typeof(InstanceMultipleImplementDepthBaseType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    public sealed class TypeImplements
    {
        public static string InstanceImplement(int value)
        {
            var inst = new InstanceImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplement1(int value)
        {
            var inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplement2(long value)
        {
            var inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleImplementFromInterface2(long value)
        {
            IInterfaceType2 inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleImplementUnified1(int value)
        {
            var inst = new InstanceMultipleImplementUnifiedType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementUnifiedFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementUnifiedType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementUnifiedFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplementUnifiedType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementCombination(int value)
        {
            var inst = new InstanceMultipleImplementCombinationType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementCombinationFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementCombinationType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementCombinationFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplementCombinationType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementExplicitlyFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementExplicitlyType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementExplicitlyFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplementExplicitlyType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombinedImplement(int value)
        {
            var inst = new InstanceMultipleCombinedImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined1ImplementFromInterface4(int value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined2ImplementFromInterface4(long value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementType();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleCombinedAndParallelImplement(int value)
        {
            var inst = new InstanceMultipleCombinedAndParallelImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombinedAndParallel1ImplementFromInterface4(int value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedAndParallelImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombinedAndParallel2ImplementFromInterface4(long value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedAndParallelImplementType();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleCombinedImplementCombination1(int value)
        {
            var inst = new InstanceMultipleCombinedImplementCombinationType1();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined1ImplementCombination1FromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleCombinedImplementCombinationType1();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined1ImplementCombination1FromInterface4(int value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementCombinationType1();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined2ImplementCombination1FromInterface4(long value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementCombinationType1();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleCombinedImplementCombination2(int value)
        {
            var inst = new InstanceMultipleCombinedImplementCombinationType2();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined1ImplementCombination2FromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleCombinedImplementCombinationType2();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined1ImplementCombination2FromInterface4(int value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementCombinationType2();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined2ImplementCombination2FromInterface4(long value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementCombinationType2();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleImplementDepth(int value)
        {
            var inst = new InstanceMultipleImplement3DepthType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementDepthFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplement3DepthType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementDepthFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplement3DepthType();
            return inst.GetStringFromInt32(value);
        }
    }
}
