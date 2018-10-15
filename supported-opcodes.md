# Supported IL opcodes

OpCode | Binary | Implement | Test | ILConverter
|:---|:---|:---|:---|:---|
| [nop](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.nop) | 0x0 | Implemented |  | IL2C.ILConverters.NopConverter |
| [break](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.break) | 0x1 |  |  |  |
| [ldarg.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_0) | 0x2 | Implemented | Test [16] | IL2C.ILConverters.Ldarg_0Converter |
| [ldarg.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_1) | 0x3 | Implemented | Test [16] | IL2C.ILConverters.Ldarg_1Converter |
| [ldarg.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_2) | 0x4 | Implemented | Test [16] | IL2C.ILConverters.Ldarg_2Converter |
| [ldarg.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_3) | 0x5 | Implemented | Test [16] | IL2C.ILConverters.Ldarg_3Converter |
| [ldloc.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_0) | 0x6 | Implemented | Test [16] | IL2C.ILConverters.Ldloc_0Converter |
| [ldloc.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_1) | 0x7 | Implemented |  | IL2C.ILConverters.Ldloc_1Converter |
| [ldloc.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_2) | 0x8 | Implemented |  | IL2C.ILConverters.Ldloc_2Converter |
| [ldloc.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_3) | 0x9 | Implemented |  | IL2C.ILConverters.Ldloc_3Converter |
| [stloc.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_0) | 0xa | Implemented |  | IL2C.ILConverters.Stloc_0Converter |
| [stloc.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_1) | 0xb | Implemented |  | IL2C.ILConverters.Stloc_1Converter |
| [stloc.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_2) | 0xc | Implemented |  | IL2C.ILConverters.Stloc_2Converter |
| [stloc.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_3) | 0xd | Implemented |  | IL2C.ILConverters.Stloc_3Converter |
| [ldarg.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_s) | 0xe | Implemented | Test [17] | IL2C.ILConverters.Ldarg_sConverter |
| [ldarga.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarga_s) | 0xf |  |  |  |
| [starg.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.starg_s) | 0x10 |  |  |  |
| [ldloc.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_s) | 0x11 | Implemented |  | IL2C.ILConverters.Ldloc_SConverter |
| [ldloca.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloca_s) | 0x12 | Implemented |  | IL2C.ILConverters.Ldloca_sConverter |
| [stloc.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_s) | 0x13 | Implemented |  | IL2C.ILConverters.Stloc_SConverter |
| [ldnull](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldnull) | 0x14 | Implemented | Test [3] | IL2C.ILConverters.LdnullConverter |
| [ldc.i4.m1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_m1) | 0x15 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_m1Converter |
| [ldc.i4.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_0) | 0x16 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_0Converter |
| [ldc.i4.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_1) | 0x17 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_1Converter |
| [ldc.i4.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_2) | 0x18 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_2Converter |
| [ldc.i4.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_3) | 0x19 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_3Converter |
| [ldc.i4.4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_4) | 0x1a | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_4Converter |
| [ldc.i4.5](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_5) | 0x1b | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_5Converter |
| [ldc.i4.6](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_6) | 0x1c | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_6Converter |
| [ldc.i4.7](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_7) | 0x1d | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_7Converter |
| [ldc.i4.8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_8) | 0x1e | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_8Converter |
| [ldc.i4.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_s) | 0x1f | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4_sConverter |
| [ldc.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4) | 0x20 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i4Converter |
| [ldc.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i8) | 0x21 | Implemented | Test [2] | IL2C.ILConverters.Ldc_i8Converter |
| [ldc.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_r4) | 0x22 | Implemented |  | IL2C.ILConverters.Ldc_R4Converter |
| [ldc.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_r8) | 0x23 | Implemented |  | IL2C.ILConverters.Ldc_R8Converter |
| [dup](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.dup) | 0x25 | Implemented |  | IL2C.ILConverters.DupConverter |
| [pop](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.pop) | 0x26 | Implemented |  | IL2C.ILConverters.PopConverter |
| [jmp](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.jmp) | 0x27 |  |  |  |
| [call](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.call) | 0x28 | Implemented |  | IL2C.ILConverters.CallConverter |
| [calli](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.calli) | 0x29 |  |  |  |
| [ret](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ret) | 0x2a | Implemented |  | IL2C.ILConverters.RetConverter |
| [br.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.br_s) | 0x2b | Implemented |  | IL2C.ILConverters.Br_sConverter |
| [brfalse.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brfalse_s) | 0x2c | Implemented |  | IL2C.ILConverters.Brfalse_sConverter |
| [brtrue.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brtrue_s) | 0x2d | Implemented |  | IL2C.ILConverters.Brtrue_sConverter |
| [beq.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.beq_s) | 0x2e | Implemented |  | IL2C.ILConverters.Beq_sConverter |
| [bge.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge_s) | 0x2f |  |  |  |
| [bgt.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt_s) | 0x30 |  |  |  |
| [ble.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble_s) | 0x31 |  |  |  |
| [blt.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt_s) | 0x32 | Implemented |  | IL2C.ILConverters.Blt_sConverter |
| [bne.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bne_un_s) | 0x33 | Implemented |  | IL2C.ILConverters.Bne_Un_sConverter |
| [bge.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge_un_s) | 0x34 |  |  |  |
| [bgt.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt_un_s) | 0x35 |  |  |  |
| [ble.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble_un_s) | 0x36 |  |  |  |
| [blt.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt_un_s) | 0x37 |  |  |  |
| [br](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.br) | 0x38 | Implemented |  | IL2C.ILConverters.BrConverter |
| [brfalse](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brfalse) | 0x39 | Implemented |  | IL2C.ILConverters.BrfalseConverter |
| [brtrue](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brtrue) | 0x3a | Implemented |  | IL2C.ILConverters.BrtrueConverter |
| [beq](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.beq) | 0x3b |  |  |  |
| [bge](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge) | 0x3c |  |  |  |
| [bgt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt) | 0x3d |  |  |  |
| [ble](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble) | 0x3e |  |  |  |
| [blt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt) | 0x3f |  |  |  |
| [bne.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bne_un) | 0x40 |  |  |  |
| [bge.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge_un) | 0x41 |  |  |  |
| [bgt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt_un) | 0x42 |  |  |  |
| [ble.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble_un) | 0x43 |  |  |  |
| [blt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt_un) | 0x44 |  |  |  |
| [switch](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.switch) | 0x45 |  |  |  |
| [ldind.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i1) | 0x46 |  |  |  |
| [ldind.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_u1) | 0x47 | Implemented |  | IL2C.ILConverters.Ldind_u1Converter |
| [ldind.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i2) | 0x48 |  |  |  |
| [ldind.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_u2) | 0x49 |  |  |  |
| [ldind.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i4) | 0x4a |  |  |  |
| [ldind.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_u4) | 0x4b |  |  |  |
| [ldind.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i8) | 0x4c |  |  |  |
| [ldind.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i) | 0x4d |  |  |  |
| [ldind.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_r4) | 0x4e |  |  |  |
| [ldind.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_r8) | 0x4f |  |  |  |
| [ldind.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_ref) | 0x50 |  |  |  |
| [stind.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_ref) | 0x51 |  |  |  |
| [stind.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i1) | 0x52 |  |  |  |
| [stind.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i2) | 0x53 |  |  |  |
| [stind.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i4) | 0x54 |  |  |  |
| [stind.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i8) | 0x55 |  |  |  |
| [stind.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_r4) | 0x56 |  |  |  |
| [stind.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_r8) | 0x57 |  |  |  |
| [add](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.add) | 0x58 | Implemented |  | IL2C.ILConverters.AddConverter |
| [sub](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sub) | 0x59 | Implemented |  | IL2C.ILConverters.SubConverter |
| [mul](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mul) | 0x5a | Implemented |  | IL2C.ILConverters.MulConverter |
| [div](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.div) | 0x5b | Implemented |  | IL2C.ILConverters.DivConverter |
| [div.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.div_un) | 0x5c |  |  |  |
| [rem](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.rem) | 0x5d |  |  |  |
| [rem.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.rem_un) | 0x5e |  |  |  |
| [and](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.and) | 0x5f | Implemented |  | IL2C.ILConverters.AndConverter |
| [or](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.or) | 0x60 |  |  |  |
| [xor](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.xor) | 0x61 |  |  |  |
| [shl](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.shl) | 0x62 |  |  |  |
| [shr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.shr) | 0x63 |  |  |  |
| [shr.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.shr_un) | 0x64 |  |  |  |
| [neg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.neg) | 0x65 |  |  |  |
| [not](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.not) | 0x66 |  |  |  |
| [conv.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i1) | 0x67 | Implemented |  | IL2C.ILConverters.Conv_i1Converter |
| [conv.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i2) | 0x68 | Implemented |  | IL2C.ILConverters.Conv_i2Converter |
| [conv.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i4) | 0x69 |  |  |  |
| [conv.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i8) | 0x6a | Implemented |  | IL2C.ILConverters.Conv_i8Converter |
| [conv.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_r4) | 0x6b |  |  |  |
| [conv.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_r8) | 0x6c |  |  |  |
| [conv.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u4) | 0x6d | Implemented |  | IL2C.ILConverters.Conv_u4Converter |
| [conv.u8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u8) | 0x6e | Implemented |  | IL2C.ILConverters.Conv_u8Converter |
| [callvirt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.callvirt) | 0x6f | Implemented |  | IL2C.ILConverters.CallvirtConverter |
| [cpobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cpobj) | 0x70 |  |  |  |
| [ldobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldobj) | 0x71 |  |  |  |
| [ldstr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldstr) | 0x72 | Implemented |  | IL2C.ILConverters.LdstrConverter |
| [newobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.newobj) | 0x73 | Implemented |  | IL2C.ILConverters.NewobjConverter |
| [castclass](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.castclass) | 0x74 | Implemented |  | IL2C.ILConverters.CastclassConverter |
| [isinst](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.isinst) | 0x75 |  |  |  |
| [conv.r.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_r_un) | 0x76 |  |  |  |
| [unbox](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.unbox) | 0x79 |  |  |  |
| [throw](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.throw) | 0x7a |  |  |  |
| [ldfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldfld) | 0x7b | Implemented |  | IL2C.ILConverters.LdfldConverter |
| [ldflda](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldflda) | 0x7c |  |  |  |
| [stfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stfld) | 0x7d | Implemented |  | IL2C.ILConverters.StfldConverter |
| [ldsfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldsfld) | 0x7e | Implemented |  | IL2C.ILConverters.LdsfldConverter |
| [ldsflda](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldsflda) | 0x7f |  |  |  |
| [stsfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stsfld) | 0x80 |  |  |  |
| [stobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stobj) | 0x81 |  |  |  |
| [conv.ovf.i1.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i1_un) | 0x82 |  |  |  |
| [conv.ovf.i2.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i2_un) | 0x83 |  |  |  |
| [conv.ovf.i4.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i4_un) | 0x84 |  |  |  |
| [conv.ovf.i8.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i8_un) | 0x85 |  |  |  |
| [conv.ovf.u1.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u1_un) | 0x86 |  |  |  |
| [conv.ovf.u2.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u2_un) | 0x87 |  |  |  |
| [conv.ovf.u4.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u4_un) | 0x88 |  |  |  |
| [conv.ovf.u8.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u8_un) | 0x89 |  |  |  |
| [conv.ovf.i.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i_un) | 0x8a |  |  |  |
| [conv.ovf.u.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u_un) | 0x8b |  |  |  |
| [box](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.box) | 0x8c | Implemented |  | IL2C.ILConverters.BoxConverter |
| [newarr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.newarr) | 0x8d |  |  |  |
| [ldlen](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldlen) | 0x8e |  |  |  |
| [ldelema](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelema) | 0x8f |  |  |  |
| [ldelem.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i1) | 0x90 |  |  |  |
| [ldelem.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_u1) | 0x91 |  |  |  |
| [ldelem.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i2) | 0x92 |  |  |  |
| [ldelem.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_u2) | 0x93 |  |  |  |
| [ldelem.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i4) | 0x94 |  |  |  |
| [ldelem.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_u4) | 0x95 |  |  |  |
| [ldelem.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i8) | 0x96 |  |  |  |
| [ldelem.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i) | 0x97 |  |  |  |
| [ldelem.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_r4) | 0x98 |  |  |  |
| [ldelem.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_r8) | 0x99 |  |  |  |
| [ldelem.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_ref) | 0x9a |  |  |  |
| [stelem.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i) | 0x9b |  |  |  |
| [stelem.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i1) | 0x9c |  |  |  |
| [stelem.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i2) | 0x9d |  |  |  |
| [stelem.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i4) | 0x9e |  |  |  |
| [stelem.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i8) | 0x9f |  |  |  |
| [stelem.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_r4) | 0xa0 |  |  |  |
| [stelem.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_r8) | 0xa1 |  |  |  |
| [stelem.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_ref) | 0xa2 |  |  |  |
| [ldelem.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem) | 0xa3 |  |  |  |
| [stelem.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem) | 0xa4 |  |  |  |
| [unbox.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.unbox_any) | 0xa5 | Implemented |  | IL2C.ILConverters.Unbox_AnyConverter |
| [conv.ovf.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i1) | 0xb3 |  |  |  |
| [conv.ovf.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u1) | 0xb4 |  |  |  |
| [conv.ovf.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i2) | 0xb5 |  |  |  |
| [conv.ovf.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u2) | 0xb6 |  |  |  |
| [conv.ovf.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i4) | 0xb7 |  |  |  |
| [conv.ovf.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u4) | 0xb8 |  |  |  |
| [conv.ovf.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i8) | 0xb9 |  |  |  |
| [conv.ovf.u8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u8) | 0xba |  |  |  |
| [refanyval](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.refanyval) | 0xc2 |  |  |  |
| [ckfinite](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ckfinite) | 0xc3 |  |  |  |
| [mkrefany](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mkrefany) | 0xc6 |  |  |  |
| [ldtoken](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldtoken) | 0xd0 |  |  |  |
| [conv.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u2) | 0xd1 | Implemented |  | IL2C.ILConverters.Conv_u2Converter |
| [conv.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u1) | 0xd2 | Implemented |  | IL2C.ILConverters.Conv_u1Converter |
| [conv.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i) | 0xd3 | Implemented |  | IL2C.ILConverters.Conv_iConverter |
| [conv.ovf.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i) | 0xd4 |  |  |  |
| [conv.ovf.u](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u) | 0xd5 |  |  |  |
| [add.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.add_ovf) | 0xd6 |  |  |  |
| [add.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.add_ovf_un) | 0xd7 |  |  |  |
| [mul.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mul_ovf) | 0xd8 |  |  |  |
| [mul.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mul_ovf_un) | 0xd9 |  |  |  |
| [sub.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sub_ovf) | 0xda |  |  |  |
| [sub.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sub_ovf_un) | 0xdb |  |  |  |
| [endfinally](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.endfinally) | 0xdc |  |  |  |
| [leave](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.leave) | 0xdd |  |  |  |
| [leave.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.leave_s) | 0xde |  |  |  |
| [stind.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i) | 0xdf |  |  |  |
| [conv.u](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u) | 0xe0 | Implemented |  | IL2C.ILConverters.Conv_uConverter |
| [arglist](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.arglist) | 0xfe00 |  |  |  |
| [ceq](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ceq) | 0xfe01 | Implemented |  | IL2C.ILConverters.CeqConverter |
| [cgt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cgt) | 0xfe02 | Implemented |  | IL2C.ILConverters.CgtConverter |
| [cgt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cgt_un) | 0xfe03 |  |  |  |
| [clt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.clt) | 0xfe04 | Implemented |  | IL2C.ILConverters.CltConverter |
| [clt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.clt_un) | 0xfe05 |  |  |  |
| [ldftn](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldftn) | 0xfe06 | Implemented |  | IL2C.ILConverters.LdftnConverter |
| [ldvirtftn](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldvirtftn) | 0xfe07 |  |  |  |
| [ldarg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg) | 0xfe09 | Implemented | Test [17] | IL2C.ILConverters.LdargConverter |
| [ldarga](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarga) | 0xfe0a |  |  |  |
| [starg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.starg) | 0xfe0b |  |  |  |
| [ldloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc) | 0xfe0c |  |  |  |
| [ldloca](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloca) | 0xfe0d |  |  |  |
| [stloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc) | 0xfe0e |  |  |  |
| [localloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.localloc) | 0xfe0f |  |  |  |
| [endfilter](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.endfilter) | 0xfe11 |  |  |  |
| [unaligned](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.unaligned) | 0xfe12 |  |  |  |
| [volatile](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.volatile) | 0xfe13 |  |  |  |
| [tail](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.tailcall) | 0xfe14 |  |  |  |
| [initobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.initobj) | 0xfe15 | Implemented |  | IL2C.ILConverters.InitobjConverter |
| [constrained](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.constrained) | 0xfe16 |  |  |  |
| [cpblk](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cpblk) | 0xfe17 |  |  |  |
| [initblk](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.initblk) | 0xfe18 |  |  |  |
| no | 0xfe19 |  |  |  |
| [rethrow](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.rethrow) | 0xfe1a |  |  |  |
| [sizeof](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sizeof) | 0xfe1c |  |  |  |
| [refanytype](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.refanytype) | 0xfe1d |  |  |  |
| [readonly](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.readonly) | 0xfe1e |  |  |  |
