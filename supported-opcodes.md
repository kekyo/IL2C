# Supported IL opcodes

OpCode | Status | ILConverter
|:---|:---|:---|
| add | Implemented | IL2C.ILConveters.AddConverter |
| add.ovf |  |  |
| add.ovf.un |  |  |
| and | Implemented | IL2C.ILConveters.AndConverter |
| arglist |  |  |
| beq |  |  |
| beq.s | Implemented | IL2C.ILConveters.Beq_sConverter |
| bge |  |  |
| bge.s |  |  |
| bge.un |  |  |
| bge.un.s |  |  |
| bgt |  |  |
| bgt.s |  |  |
| bgt.un |  |  |
| bgt.un.s |  |  |
| ble |  |  |
| ble.s |  |  |
| ble.un |  |  |
| ble.un.s |  |  |
| blt |  |  |
| blt.s | Implemented | IL2C.ILConveters.Blt_sConverter |
| blt.un |  |  |
| blt.un.s |  |  |
| bne.un |  |  |
| bne.un.s | Implemented | IL2C.ILConveters.Bne_Un_sConverter |
| box | Implemented | IL2C.ILConveters.BoxConverter |
| br | Implemented | IL2C.ILConveters.BrConverter |
| br.s | Implemented | IL2C.ILConveters.Br_sConverter |
| break |  |  |
| brfalse | Implemented | IL2C.ILConveters.BrfalseConverter |
| brfalse.s | Implemented | IL2C.ILConveters.Brfalse_sConverter |
| brtrue | Implemented | IL2C.ILConveters.BrtrueConverter |
| brtrue.s | Implemented | IL2C.ILConveters.Brtrue_sConverter |
| call | Implemented | IL2C.ILConveters.CallConverter |
| calli |  |  |
| callvirt | Implemented | IL2C.ILConveters.CallvirtConverter |
| castclass | Implemented | IL2C.ILConveters.RetConverter+CastclassConverter |
| ceq | Implemented | IL2C.ILConveters.CeqConverter |
| cgt | Implemented | IL2C.ILConveters.CgtConverter |
| cgt.un |  |  |
| ckfinite |  |  |
| clt | Implemented | IL2C.ILConveters.CltConverter |
| clt.un |  |  |
| constrained. |  |  |
| conv.i |  |  |
| conv.i1 | Implemented | IL2C.ILConveters.Conv_i1Converter |
| conv.i2 | Implemented | IL2C.ILConveters.Conv_i2Converter |
| conv.i4 |  |  |
| conv.i8 | Implemented | IL2C.ILConveters.Conv_i8Converter |
| conv.ovf.i |  |  |
| conv.ovf.i.un |  |  |
| conv.ovf.i1 |  |  |
| conv.ovf.i1.un |  |  |
| conv.ovf.i2 |  |  |
| conv.ovf.i2.un |  |  |
| conv.ovf.i4 |  |  |
| conv.ovf.i4.un |  |  |
| conv.ovf.i8 |  |  |
| conv.ovf.i8.un |  |  |
| conv.ovf.u |  |  |
| conv.ovf.u.un |  |  |
| conv.ovf.u1 |  |  |
| conv.ovf.u1.un |  |  |
| conv.ovf.u2 |  |  |
| conv.ovf.u2.un |  |  |
| conv.ovf.u4 |  |  |
| conv.ovf.u4.un |  |  |
| conv.ovf.u8 |  |  |
| conv.ovf.u8.un |  |  |
| conv.r.un |  |  |
| conv.r4 |  |  |
| conv.r8 |  |  |
| conv.u | Implemented | IL2C.ILConveters.Conv_uConverter |
| conv.u1 | Implemented | IL2C.ILConveters.Conv_u1Converter |
| conv.u2 | Implemented | IL2C.ILConveters.Conv_u2Converter |
| conv.u4 |  |  |
| conv.u8 | Implemented | IL2C.ILConveters.Conv_u8Converter |
| cpblk |  |  |
| cpobj |  |  |
| div | Implemented | IL2C.ILConveters.DivConverter |
| div.un |  |  |
| dup | Implemented | IL2C.ILConveters.RetConverter+DupConverter |
| endfilter |  |  |
| endfinally |  |  |
| initblk |  |  |
| initobj | Implemented | IL2C.ILConveters.InitobjConverter |
| isinst |  |  |
| jmp |  |  |
| ldarg |  |  |
| ldarg.0 | Implemented | IL2C.ILConveters.Ldarg_0Converter |
| ldarg.1 | Implemented | IL2C.ILConveters.Ldarg_1Converter |
| ldarg.2 | Implemented | IL2C.ILConveters.Ldarg_2Converter |
| ldarg.3 | Implemented | IL2C.ILConveters.Ldarg_3Converter |
| ldarg.s | Implemented | IL2C.ILConveters.Ldarg_sConverter |
| ldarga |  |  |
| ldarga.s |  |  |
| ldc.i4 | Implemented | IL2C.ILConveters.Ldc_i4Converter |
| ldc.i4.0 | Implemented | IL2C.ILConveters.Ldc_i4_0Converter |
| ldc.i4.1 | Implemented | IL2C.ILConveters.Ldc_i4_1Converter |
| ldc.i4.2 | Implemented | IL2C.ILConveters.Ldc_i4_2Converter |
| ldc.i4.3 | Implemented | IL2C.ILConveters.Ldc_i4_3Converter |
| ldc.i4.4 | Implemented | IL2C.ILConveters.Ldc_i4_4Converter |
| ldc.i4.5 | Implemented | IL2C.ILConveters.Ldc_i4_5Converter |
| ldc.i4.6 | Implemented | IL2C.ILConveters.Ldc_i4_6Converter |
| ldc.i4.7 | Implemented | IL2C.ILConveters.Ldc_i4_7Converter |
| ldc.i4.8 |  |  |
| ldc.i4.m1 |  |  |
| ldc.i4.s | Implemented | IL2C.ILConveters.Ldc_i4_sConverter |
| ldc.i8 | Implemented | IL2C.ILConveters.Ldc_i8Converter |
| ldc.r4 |  |  |
| ldc.r8 |  |  |
| ldelem.any |  |  |
| ldelem.i |  |  |
| ldelem.i1 |  |  |
| ldelem.i2 |  |  |
| ldelem.i4 |  |  |
| ldelem.i8 |  |  |
| ldelem.r4 |  |  |
| ldelem.r8 |  |  |
| ldelem.ref |  |  |
| ldelem.u1 |  |  |
| ldelem.u2 |  |  |
| ldelem.u4 |  |  |
| ldelema |  |  |
| ldfld | Implemented | IL2C.ILConveters.LdfldConverter |
| ldflda |  |  |
| ldftn | Implemented | IL2C.ILConveters.LdftnConverter |
| ldind.i |  |  |
| ldind.i1 |  |  |
| ldind.i2 |  |  |
| ldind.i4 |  |  |
| ldind.i8 |  |  |
| ldind.r4 |  |  |
| ldind.r8 |  |  |
| ldind.ref |  |  |
| ldind.u1 | Implemented | IL2C.ILConveters.Ldind_u1Converter |
| ldind.u2 |  |  |
| ldind.u4 |  |  |
| ldlen |  |  |
| ldloc |  |  |
| ldloc.0 | Implemented | IL2C.ILConveters.Ldloc_0Converter |
| ldloc.1 | Implemented | IL2C.ILConveters.Ldloc_1Converter |
| ldloc.2 | Implemented | IL2C.ILConveters.Ldloc_2Converter |
| ldloc.3 | Implemented | IL2C.ILConveters.Ldloc_3Converter |
| ldloc.s | Implemented | IL2C.ILConveters.Ldloc_SConverter |
| ldloca |  |  |
| ldloca.s | Implemented | IL2C.ILConveters.Ldloca_sConverter |
| ldnull | Implemented | IL2C.ILConveters.RetConverter+LdnullConverter |
| ldobj |  |  |
| ldsfld | Implemented | IL2C.ILConveters.LdsfldConverter |
| ldsflda |  |  |
| ldstr | Implemented | IL2C.ILConveters.RetConverter+LdstrConverter |
| ldtoken |  |  |
| ldvirtftn |  |  |
| leave |  |  |
| leave.s |  |  |
| localloc |  |  |
| mkrefany |  |  |
| mul | Implemented | IL2C.ILConveters.MulConverter |
| mul.ovf |  |  |
| mul.ovf.un |  |  |
| neg |  |  |
| newarr |  |  |
| newobj | Implemented | IL2C.ILConveters.NewobjConverter |
| no. |  |  |
| nop | Implemented | IL2C.ILConveters.NopConverter |
| not |  |  |
| or |  |  |
| pop | Implemented | IL2C.ILConveters.RetConverter+PopConverter |
| readonly. |  |  |
| refanytype |  |  |
| refanyval |  |  |
| rem |  |  |
| rem.un |  |  |
| ret | Implemented | IL2C.ILConveters.RetConverter |
| rethrow |  |  |
| shl |  |  |
| shr |  |  |
| shr.un |  |  |
| sizeof |  |  |
| starg |  |  |
| starg.s |  |  |
| stelem.any |  |  |
| stelem.i |  |  |
| stelem.i1 |  |  |
| stelem.i2 |  |  |
| stelem.i4 |  |  |
| stelem.i8 |  |  |
| stelem.r4 |  |  |
| stelem.r8 |  |  |
| stelem.ref |  |  |
| stfld | Implemented | IL2C.ILConveters.StfldConverter |
| stind.i |  |  |
| stind.i1 |  |  |
| stind.i2 |  |  |
| stind.i4 |  |  |
| stind.i8 |  |  |
| stind.r4 |  |  |
| stind.r8 |  |  |
| stind.ref |  |  |
| stloc |  |  |
| stloc.0 | Implemented | IL2C.ILConveters.Stloc_0Converter |
| stloc.1 | Implemented | IL2C.ILConveters.Stloc_1Converter |
| stloc.2 | Implemented | IL2C.ILConveters.Stloc_2Converter |
| stloc.3 | Implemented | IL2C.ILConveters.Stloc_3Converter |
| stloc.s | Implemented | IL2C.ILConveters.Stloc_SConverter |
| stobj |  |  |
| stsfld |  |  |
| sub | Implemented | IL2C.ILConveters.SubConverter |
| sub.ovf |  |  |
| sub.ovf.un |  |  |
| switch |  |  |
| tail. |  |  |
| throw |  |  