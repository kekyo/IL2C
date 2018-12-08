.class public IL2C.RuntimeSystems.ValueTypes
{
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
}