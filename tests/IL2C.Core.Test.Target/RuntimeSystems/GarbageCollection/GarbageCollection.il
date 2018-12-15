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
        call string [mscorlib]System.String::Concat(string, string)
        newobj instance void IL2C.RuntimeSystems.ObjRefInsideObjRefType::.ctor(string)
        stloc.0

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [mscorlib]System.GC::Collect()

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
        call string [mscorlib]System.String::Concat(string, string)
        call instance void IL2C.RuntimeSystems.ObjRefInsideValueTypeType::.ctor(string)

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [mscorlib]System.GC::Collect()

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
        call string [mscorlib]System.String::Concat(string, string)
        newobj instance void IL2C.RuntimeSystems.ObjRefInsideValueTypeInsideObjRefType::.ctor(string)
        stloc.0

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [mscorlib]System.GC::Collect()

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
        call string [mscorlib]System.String::Concat(string, string)
        call instance void IL2C.RuntimeSystems.ObjRefInsideObjRefInsideValueTypeType::.ctor(string)

        // Release concat string from the evaluation stack
        ldstr "dummy1"
        ldstr "dummy2"
        pop
        pop

        call void [mscorlib]System.GC::Collect()

        ldloca.s 0
        ldfld class IL2C.RuntimeSystems.ObjRefInsideObjRefType IL2C.RuntimeSystems.ObjRefInsideObjRefInsideValueTypeType::Value
        ldfld string IL2C.RuntimeSystems.ObjRefInsideObjRefType::Value
        ret
    }
}
