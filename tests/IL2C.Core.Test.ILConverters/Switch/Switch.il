.class public IL2C.ILConverters.Switch
{
    .method public static string TestSwitch(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        switch (label0, label1, label2, label3)
        ldstr "Out of range"
        ret
label0:
        ldstr "0"
        ret
label1:
        ldstr "1"
        ret
label2:
        ldstr "2"
        ret
label3:
        ldstr "3"
        ret
    }
}
