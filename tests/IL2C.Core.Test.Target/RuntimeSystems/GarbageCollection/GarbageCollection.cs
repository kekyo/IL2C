using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;

namespace IL2C.RuntimeSystems
{
    public class ObjRefInsideObjRefType
    {
        public string Value;

        public ObjRefInsideObjRefType(string value) => this.Value = value;
    }

    public struct ObjRefInsideValueTypeType
    {
        public string Value;

        public ObjRefInsideValueTypeType(string value) => this.Value = value;
    }

    public class ObjRefInsideValueTypeInsideObjRefType
    {
        public ObjRefInsideValueTypeType Value;

        public ObjRefInsideValueTypeInsideObjRefType(string value) =>
            this.Value = new ObjRefInsideValueTypeType(value);
    }

    public struct ObjRefInsideObjRefInsideValueTypeType
    {
        public ObjRefInsideObjRefType Value;

        public ObjRefInsideObjRefInsideValueTypeType(string value) =>
            this.Value = new ObjRefInsideObjRefType(value);
    }

    public struct MultipleInsideValueTypeType
    {
        public string Value1;
        public ObjRefInsideValueTypeType Value2;
        public ObjRefInsideObjRefType Value3;

        public MultipleInsideValueTypeType(string value1, string value2, string value3)
        {
            this.Value1 = value1;
            this.Value2 = new ObjRefInsideValueTypeType(value2);
            this.Value3 = new ObjRefInsideObjRefType(value3);
        }
    }

    [Description("These tests are verified the IL2C manages tracing the object references and collect garbages from the heap memory.")]
    [TestCase("ABCDEF", "ObjRefInsideObjRef", IncludeTypes = new[] { typeof(ObjRefInsideObjRefType) })]
    [TestCase("ABCDEF", "ObjRefInsideValueType", IncludeTypes = new[] { typeof(ObjRefInsideValueTypeType) })]
    [TestCase("ABCDEF", "ObjRefInsideValueTypeInsideObjRef", IncludeTypes = new[] { typeof(ObjRefInsideValueTypeInsideObjRefType), typeof(ObjRefInsideValueTypeType) })]
    [TestCase("ABCDEF", "ObjRefInsideObjRefInsideValueType", IncludeTypes = new[] { typeof(ObjRefInsideObjRefInsideValueTypeType), typeof(ObjRefInsideObjRefType) })]
    [TestCase("ABCDEF1", "MultipleInsideValueType", 0, IncludeTypes = new[] { typeof(MultipleInsideValueTypeType), typeof(ObjRefInsideValueTypeType), typeof(ObjRefInsideObjRefType) })]
    [TestCase("ABCDEF2", "MultipleInsideValueType", 1, IncludeTypes = new[] { typeof(MultipleInsideValueTypeType), typeof(ObjRefInsideValueTypeType), typeof(ObjRefInsideObjRefType) })]
    [TestCase("ABCDEF3", "MultipleInsideValueType", 2, IncludeTypes = new[] { typeof(MultipleInsideValueTypeType), typeof(ObjRefInsideValueTypeType), typeof(ObjRefInsideObjRefType) })]
    public sealed class GarbageCollection
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjRefInsideObjRef();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjRefInsideValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjRefInsideValueTypeInsideObjRef();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjRefInsideObjRefInsideValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string MultipleInsideValueType(int index);
    }
}
