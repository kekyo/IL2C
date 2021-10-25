.class public IL2C.RuntimeSystems.GarbageCollection
{
    .method public static string ObjRefInsideObjRef() cil managed
    {
        .maxstack 3
        .locals init (
            [0] class IL2C.RuntimeSystems.ObjRefInsideObjRefType
    	)

        ldstr "ABC"
        ldstr "DEF"
        call string string::Concat(string, string)
        newobj instance void IL2C.RuntimeSystems.ObjRefInsideObjRefType::.ctor(string)
        stloc.0

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [netstandard]System.GC::Collect()
        call void [netstandard]System.GC::WaitForPendingFinalizers()

        ldloc.0
        ldfld string IL2C.RuntimeSystems.ObjRefInsideObjRefType::Value
        ret
    }

    .method public static string ObjRefInsideValueType() cil managed
    {
        .maxstack 3
        .locals init (
            [0] valuetype IL2C.RuntimeSystems.ObjRefInsideValueTypeType
    	)

        ldloca.s 0
        ldstr "ABC"
        ldstr "DEF"
        call string string::Concat(string, string)
        call instance void IL2C.RuntimeSystems.ObjRefInsideValueTypeType::.ctor(string)

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [netstandard]System.GC::Collect()
        call void [netstandard]System.GC::WaitForPendingFinalizers()

        ldloc.0
        ldfld string IL2C.RuntimeSystems.ObjRefInsideValueTypeType::Value
        ret
    }

    .method public static string ObjRefInsideValueTypeInsideObjRef() cil managed
    {
        .maxstack 3
        .locals init (
            [0] class IL2C.RuntimeSystems.ObjRefInsideValueTypeInsideObjRefType
    	)

        ldstr "ABC"
        ldstr "DEF"
        call string string::Concat(string, string)
        newobj instance void IL2C.RuntimeSystems.ObjRefInsideValueTypeInsideObjRefType::.ctor(string)
        stloc.0

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [netstandard]System.GC::Collect()
        call void [netstandard]System.GC::WaitForPendingFinalizers()

        ldloc.0
        ldflda valuetype IL2C.RuntimeSystems.ObjRefInsideValueTypeType IL2C.RuntimeSystems.ObjRefInsideValueTypeInsideObjRefType::Value
        ldfld string IL2C.RuntimeSystems.ObjRefInsideValueTypeType::Value
        ret
    }

    .method public static string ObjRefInsideObjRefInsideValueType() cil managed
    {
        .maxstack 3
        .locals init (
            [0] valuetype IL2C.RuntimeSystems.ObjRefInsideObjRefInsideValueTypeType
    	)

        ldloca.s 0
        ldstr "ABC"
        ldstr "DEF"
        call string string::Concat(string, string)
        call instance void IL2C.RuntimeSystems.ObjRefInsideObjRefInsideValueTypeType::.ctor(string)

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [netstandard]System.GC::Collect()
        call void [netstandard]System.GC::WaitForPendingFinalizers()

        ldloca.s 0
        ldfld class IL2C.RuntimeSystems.ObjRefInsideObjRefType IL2C.RuntimeSystems.ObjRefInsideObjRefInsideValueTypeType::Value
        ldfld string IL2C.RuntimeSystems.ObjRefInsideObjRefType::Value
        ret
    }

    .method public static string MultipleInsideValueType(int32 index) cil managed
    {
        .maxstack 5
        .locals init (
            [0] valuetype IL2C.RuntimeSystems.MultipleInsideValueTypeType
    	)

        ldloca.s 0
        ldstr "ABC"
        ldstr "DEF1"
        call string string::Concat(string, string)
        ldstr "ABC"
        ldstr "DEF2"
        call string string::Concat(string, string)
        ldstr "ABC"
        ldstr "DEF3"
        call string string::Concat(string, string)
        call instance void IL2C.RuntimeSystems.MultipleInsideValueTypeType::.ctor(string, string, string)

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        ldstr "dummy3"
        ldstr "dummy4"
        pop
        pop
        pop
        pop

        call void [netstandard]System.GC::Collect()
        call void [netstandard]System.GC::WaitForPendingFinalizers()

        ldarg.0
        ldc.i4.0
        ceq
        brfalse.s L1
        ldloca.s 0
        ldfld string IL2C.RuntimeSystems.MultipleInsideValueTypeType::Value1
        ret

    L1: ldarg.0
        ldc.i4.1
        ceq
        brfalse.s L2
        ldloca.s 0
        ldflda valuetype IL2C.RuntimeSystems.ObjRefInsideValueTypeType IL2C.RuntimeSystems.MultipleInsideValueTypeType::Value2
        ldfld string IL2C.RuntimeSystems.ObjRefInsideValueTypeType::Value
        ret

    L2: ldloca.s 0
        ldfld class IL2C.RuntimeSystems.ObjRefInsideObjRefType IL2C.RuntimeSystems.MultipleInsideValueTypeType::Value3
        ldfld string IL2C.RuntimeSystems.ObjRefInsideObjRefType::Value
        ret
    }
}
