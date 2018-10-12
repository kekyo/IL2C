# Supported IL opcodes

OpCode | Binary | Implement | Test | ILConverter
|:---|:---|:---|:---|:---|
| [nop](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Nop) | 0x0 | Implemented |  | IL2C.ILConveters.NopConverter |
| [break](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Break) | 0x1 |  |  |  |
| [ldarg.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarg_0) | 0x2 | Implemented | Test [9] | IL2C.ILConveters.Ldarg_0Converter |
| [ldarg.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarg_1) | 0x3 | Implemented | Test [9] | IL2C.ILConveters.Ldarg_1Converter |
| [ldarg.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarg_2) | 0x4 | Implemented | Test [9] | IL2C.ILConveters.Ldarg_2Converter |
| [ldarg.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarg_3) | 0x5 | Implemented | Test [9] | IL2C.ILConveters.Ldarg_3Converter |
| [ldloc.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloc_0) | 0x6 | Implemented |  | IL2C.ILConveters.Ldloc_0Converter |
| [ldloc.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloc_1) | 0x7 | Implemented |  | IL2C.ILConveters.Ldloc_1Converter |
| [ldloc.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloc_2) | 0x8 | Implemented |  | IL2C.ILConveters.Ldloc_2Converter |
| [ldloc.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloc_3) | 0x9 | Implemented |  | IL2C.ILConveters.Ldloc_3Converter |
| [stloc.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stloc_0) | 0xa | Implemented |  | IL2C.ILConveters.Stloc_0Converter |
| [stloc.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stloc_1) | 0xb | Implemented |  | IL2C.ILConveters.Stloc_1Converter |
| [stloc.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stloc_2) | 0xc | Implemented |  | IL2C.ILConveters.Stloc_2Converter |
| [stloc.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stloc_3) | 0xd | Implemented |  | IL2C.ILConveters.Stloc_3Converter |
| [ldarg.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarg_S) | 0xe | Implemented |  | IL2C.ILConveters.Ldarg_sConverter |
| [ldarga.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarga_S) | 0xf |  |  |  |
| [starg.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Starg_S) | 0x10 |  |  |  |
| [ldloc.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloc_S) | 0x11 | Implemented |  | IL2C.ILConveters.Ldloc_SConverter |
| [ldloca.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloca_S) | 0x12 | Implemented |  | IL2C.ILConveters.Ldloca_sConverter |
| [stloc.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stloc_S) | 0x13 | Implemented |  | IL2C.ILConveters.Stloc_SConverter |
| [ldnull](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldnull) | 0x14 | Implemented |  | IL2C.ILConveters.RetConverter+LdnullConverter |
| [ldc.i4.m1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_M1) | 0x15 |  |  |  |
| [ldc.i4.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_0) | 0x16 | Implemented |  | IL2C.ILConveters.Ldc_i4_0Converter |
| [ldc.i4.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_1) | 0x17 | Implemented |  | IL2C.ILConveters.Ldc_i4_1Converter |
| [ldc.i4.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_2) | 0x18 | Implemented |  | IL2C.ILConveters.Ldc_i4_2Converter |
| [ldc.i4.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_3) | 0x19 | Implemented |  | IL2C.ILConveters.Ldc_i4_3Converter |
| [ldc.i4.4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_4) | 0x1a | Implemented |  | IL2C.ILConveters.Ldc_i4_4Converter |
| [ldc.i4.5](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_5) | 0x1b | Implemented |  | IL2C.ILConveters.Ldc_i4_5Converter |
| [ldc.i4.6](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_6) | 0x1c | Implemented |  | IL2C.ILConveters.Ldc_i4_6Converter |
| [ldc.i4.7](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_7) | 0x1d | Implemented |  | IL2C.ILConveters.Ldc_i4_7Converter |
| [ldc.i4.8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_8) | 0x1e |  |  |  |
| [ldc.i4.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4_S) | 0x1f | Implemented |  | IL2C.ILConveters.Ldc_i4_sConverter |
| [ldc.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I4) | 0x20 | Implemented |  | IL2C.ILConveters.Ldc_i4Converter |
| [ldc.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_I8) | 0x21 | Implemented |  | IL2C.ILConveters.Ldc_i8Converter |
| [ldc.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_R4) | 0x22 | Implemented |  | IL2C.ILConveters.Ldc_R4Converter |
| [ldc.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldc_R8) | 0x23 | Implemented |  | IL2C.ILConveters.Ldc_R8Converter |
| [dup](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Dup) | 0x25 | Implemented |  | IL2C.ILConveters.RetConverter+DupConverter |
| [pop](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Pop) | 0x26 | Implemented |  | IL2C.ILConveters.RetConverter+PopConverter |
| [jmp](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Jmp) | 0x27 |  |  |  |
| [call](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Call) | 0x28 | Implemented |  | IL2C.ILConveters.CallConverter |
| [calli](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Calli) | 0x29 |  |  |  |
| [ret](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ret) | 0x2a | Implemented |  | IL2C.ILConveters.RetConverter |
| [br.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Br_S) | 0x2b | Implemented |  | IL2C.ILConveters.Br_sConverter |
| [brfalse.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Brfalse_S) | 0x2c | Implemented |  | IL2C.ILConveters.Brfalse_sConverter |
| [brtrue.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Brtrue_S) | 0x2d | Implemented |  | IL2C.ILConveters.Brtrue_sConverter |
| [beq.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Beq_S) | 0x2e | Implemented |  | IL2C.ILConveters.Beq_sConverter |
| [bge.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bge_S) | 0x2f |  |  |  |
| [bgt.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bgt_S) | 0x30 |  |  |  |
| [ble.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ble_S) | 0x31 |  |  |  |
| [blt.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Blt_S) | 0x32 | Implemented |  | IL2C.ILConveters.Blt_sConverter |
| [bne.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bne_Un_S) | 0x33 | Implemented |  | IL2C.ILConveters.Bne_Un_sConverter |
| [bge.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bge_Un_S) | 0x34 |  |  |  |
| [bgt.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bgt_Un_S) | 0x35 |  |  |  |
| [ble.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ble_Un_S) | 0x36 |  |  |  |
| [blt.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Blt_Un_S) | 0x37 |  |  |  |
| [br](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Br) | 0x38 | Implemented |  | IL2C.ILConveters.BrConverter |
| [brfalse](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Brfalse) | 0x39 | Implemented |  | IL2C.ILConveters.BrfalseConverter |
| [brtrue](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Brtrue) | 0x3a | Implemented |  | IL2C.ILConveters.BrtrueConverter |
| [beq](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Beq) | 0x3b |  |  |  |
| [bge](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bge) | 0x3c |  |  |  |
| [bgt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bgt) | 0x3d |  |  |  |
| [ble](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ble) | 0x3e |  |  |  |
| [blt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Blt) | 0x3f |  |  |  |
| [bne.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bne_Un) | 0x40 |  |  |  |
| [bge.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bge_Un) | 0x41 |  |  |  |
| [bgt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Bgt_Un) | 0x42 |  |  |  |
| [ble.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ble_Un) | 0x43 |  |  |  |
| [blt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Blt_Un) | 0x44 |  |  |  |
| [switch](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Switch) | 0x45 |  |  |  |
| [ldind.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_I1) | 0x46 |  |  |  |
| [ldind.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_U1) | 0x47 | Implemented |  | IL2C.ILConveters.Ldind_u1Converter |
| [ldind.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_I2) | 0x48 |  |  |  |
| [ldind.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_U2) | 0x49 |  |  |  |
| [ldind.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_I4) | 0x4a |  |  |  |
| [ldind.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_U4) | 0x4b |  |  |  |
| [ldind.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_I8) | 0x4c |  |  |  |
| [ldind.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_I) | 0x4d |  |  |  |
| [ldind.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_R4) | 0x4e |  |  |  |
| [ldind.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_R8) | 0x4f |  |  |  |
| [ldind.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldind_Ref) | 0x50 |  |  |  |
| [stind.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_Ref) | 0x51 |  |  |  |
| [stind.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_I1) | 0x52 |  |  |  |
| [stind.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_I2) | 0x53 |  |  |  |
| [stind.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_I4) | 0x54 |  |  |  |
| [stind.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_I8) | 0x55 |  |  |  |
| [stind.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_R4) | 0x56 |  |  |  |
| [stind.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_R8) | 0x57 |  |  |  |
| [add](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Add) | 0x58 | Implemented |  | IL2C.ILConveters.AddConverter |
| [sub](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Sub) | 0x59 | Implemented |  | IL2C.ILConveters.SubConverter |
| [mul](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Mul) | 0x5a | Implemented |  | IL2C.ILConveters.MulConverter |
| [div](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Div) | 0x5b | Implemented |  | IL2C.ILConveters.DivConverter |
| [div.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Div_Un) | 0x5c |  |  |  |
| [rem](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Rem) | 0x5d |  |  |  |
| [rem.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Rem_Un) | 0x5e |  |  |  |
| [and](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.And) | 0x5f | Implemented |  | IL2C.ILConveters.AndConverter |
| [or](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Or) | 0x60 |  |  |  |
| [xor](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Xor) | 0x61 |  |  |  |
| [shl](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Shl) | 0x62 |  |  |  |
| [shr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Shr) | 0x63 |  |  |  |
| [shr.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Shr_Un) | 0x64 |  |  |  |
| [neg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Neg) | 0x65 |  |  |  |
| [not](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Not) | 0x66 |  |  |  |
| [conv.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_I1) | 0x67 | Implemented |  | IL2C.ILConveters.Conv_i1Converter |
| [conv.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_I2) | 0x68 | Implemented |  | IL2C.ILConveters.Conv_i2Converter |
| [conv.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_I4) | 0x69 |  |  |  |
| [conv.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_I8) | 0x6a | Implemented |  | IL2C.ILConveters.Conv_i8Converter |
| [conv.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_R4) | 0x6b |  |  |  |
| [conv.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_R8) | 0x6c |  |  |  |
| [conv.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_U4) | 0x6d |  |  |  |
| [conv.u8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_U8) | 0x6e | Implemented |  | IL2C.ILConveters.Conv_u8Converter |
| [callvirt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Callvirt) | 0x6f | Implemented |  | IL2C.ILConveters.CallvirtConverter |
| [cpobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Cpobj) | 0x70 |  |  |  |
| [ldobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldobj) | 0x71 |  |  |  |
| [ldstr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldstr) | 0x72 | Implemented |  | IL2C.ILConveters.RetConverter+LdstrConverter |
| [newobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Newobj) | 0x73 | Implemented |  | IL2C.ILConveters.NewobjConverter |
| [castclass](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Castclass) | 0x74 | Implemented |  | IL2C.ILConveters.RetConverter+CastclassConverter |
| [isinst](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Isinst) | 0x75 |  |  |  |
| [conv.r.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_R_Un) | 0x76 |  |  |  |
| [unbox](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Unbox) | 0x79 |  |  |  |
| [throw](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Throw) | 0x7a |  |  |  |
| [ldfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldfld) | 0x7b | Implemented |  | IL2C.ILConveters.LdfldConverter |
| [ldflda](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldflda) | 0x7c |  |  |  |
| [stfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stfld) | 0x7d | Implemented |  | IL2C.ILConveters.StfldConverter |
| [ldsfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldsfld) | 0x7e | Implemented |  | IL2C.ILConveters.LdsfldConverter |
| [ldsflda](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldsflda) | 0x7f |  |  |  |
| [stsfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stsfld) | 0x80 |  |  |  |
| [stobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stobj) | 0x81 |  |  |  |
| [conv.ovf.i1.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I1_Un) | 0x82 |  |  |  |
| [conv.ovf.i2.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I2_Un) | 0x83 |  |  |  |
| [conv.ovf.i4.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I4_Un) | 0x84 |  |  |  |
| [conv.ovf.i8.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I8_Un) | 0x85 |  |  |  |
| [conv.ovf.u1.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U1_Un) | 0x86 |  |  |  |
| [conv.ovf.u2.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U2_Un) | 0x87 |  |  |  |
| [conv.ovf.u4.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U4_Un) | 0x88 |  |  |  |
| [conv.ovf.u8.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U8_Un) | 0x89 |  |  |  |
| [conv.ovf.i.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I_Un) | 0x8a |  |  |  |
| [conv.ovf.u.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U_Un) | 0x8b |  |  |  |
| [box](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Box) | 0x8c | Implemented |  | IL2C.ILConveters.BoxConverter |
| [newarr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Newarr) | 0x8d |  |  |  |
| [ldlen](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldlen) | 0x8e |  |  |  |
| [ldelema](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelema) | 0x8f |  |  |  |
| [ldelem.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_I1) | 0x90 |  |  |  |
| [ldelem.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_U1) | 0x91 |  |  |  |
| [ldelem.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_I2) | 0x92 |  |  |  |
| [ldelem.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_U2) | 0x93 |  |  |  |
| [ldelem.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_I4) | 0x94 |  |  |  |
| [ldelem.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_U4) | 0x95 |  |  |  |
| [ldelem.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_I8) | 0x96 |  |  |  |
| [ldelem.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_I) | 0x97 |  |  |  |
| [ldelem.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_R4) | 0x98 |  |  |  |
| [ldelem.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_R8) | 0x99 |  |  |  |
| [ldelem.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem_Ref) | 0x9a |  |  |  |
| [stelem.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_I) | 0x9b |  |  |  |
| [stelem.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_I1) | 0x9c |  |  |  |
| [stelem.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_I2) | 0x9d |  |  |  |
| [stelem.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_I4) | 0x9e |  |  |  |
| [stelem.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_I8) | 0x9f |  |  |  |
| [stelem.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_R4) | 0xa0 |  |  |  |
| [stelem.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_R8) | 0xa1 |  |  |  |
| [stelem.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem_Ref) | 0xa2 |  |  |  |
| [ldelem.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldelem) | 0xa3 |  |  |  |
| [stelem.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stelem) | 0xa4 |  |  |  |
| [unbox.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Unbox_Any) | 0xa5 | Implemented |  | IL2C.ILConveters.Unbox_AnyConverter |
| [conv.ovf.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I1) | 0xb3 |  |  |  |
| [conv.ovf.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U1) | 0xb4 |  |  |  |
| [conv.ovf.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I2) | 0xb5 |  |  |  |
| [conv.ovf.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U2) | 0xb6 |  |  |  |
| [conv.ovf.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I4) | 0xb7 |  |  |  |
| [conv.ovf.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U4) | 0xb8 |  |  |  |
| [conv.ovf.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I8) | 0xb9 |  |  |  |
| [conv.ovf.u8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U8) | 0xba |  |  |  |
| [refanyval](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Refanyval) | 0xc2 |  |  |  |
| [ckfinite](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ckfinite) | 0xc3 |  |  |  |
| [mkrefany](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Mkrefany) | 0xc6 |  |  |  |
| [ldtoken](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldtoken) | 0xd0 |  |  |  |
| [conv.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_U2) | 0xd1 | Implemented |  | IL2C.ILConveters.Conv_u2Converter |
| [conv.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_U1) | 0xd2 | Implemented |  | IL2C.ILConveters.Conv_u1Converter |
| [conv.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_I) | 0xd3 |  |  |  |
| [conv.ovf.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_I) | 0xd4 |  |  |  |
| [conv.ovf.u](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_Ovf_U) | 0xd5 |  |  |  |
| [add.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Add_Ovf) | 0xd6 |  |  |  |
| [add.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Add_Ovf_Un) | 0xd7 |  |  |  |
| [mul.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Mul_Ovf) | 0xd8 |  |  |  |
| [mul.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Mul_Ovf_Un) | 0xd9 |  |  |  |
| [sub.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Sub_Ovf) | 0xda |  |  |  |
| [sub.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Sub_Ovf_Un) | 0xdb |  |  |  |
| [endfinally](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Endfinally) | 0xdc |  |  |  |
| [leave](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Leave) | 0xdd |  |  |  |
| [leave.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Leave_S) | 0xde |  |  |  |
| [stind.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stind_I) | 0xdf |  |  |  |
| [conv.u](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Conv_U) | 0xe0 | Implemented |  | IL2C.ILConveters.Conv_uConverter |
| [arglist](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Arglist) | 0xfe00 |  |  |  |
| [ceq](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ceq) | 0xfe01 | Implemented |  | IL2C.ILConveters.CeqConverter |
| [cgt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Cgt) | 0xfe02 | Implemented |  | IL2C.ILConveters.CgtConverter |
| [cgt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Cgt_Un) | 0xfe03 |  |  |  |
| [clt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Clt) | 0xfe04 | Implemented |  | IL2C.ILConveters.CltConverter |
| [clt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Clt_Un) | 0xfe05 |  |  |  |
| [ldftn](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldftn) | 0xfe06 | Implemented |  | IL2C.ILConveters.LdftnConverter |
| [ldvirtftn](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldvirtftn) | 0xfe07 |  |  |  |
| [ldarg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarg) | 0xfe09 |  |  |  |
| [ldarga](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldarga) | 0xfe0a |  |  |  |
| [starg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Starg) | 0xfe0b |  |  |  |
| [ldloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloc) | 0xfe0c |  |  |  |
| [ldloca](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Ldloca) | 0xfe0d |  |  |  |
| [stloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Stloc) | 0xfe0e |  |  |  |
| [localloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Localloc) | 0xfe0f |  |  |  |
| [endfilter](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Endfilter) | 0xfe11 |  |  |  |
| [unaligned](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Unaligned) | 0xfe12 |  |  |  |
| [volatile](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Volatile) | 0xfe13 |  |  |  |
| [tail](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Tailcall) | 0xfe14 |  |  |  |
| [initobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Initobj) | 0xfe15 | Implemented |  | IL2C.ILConveters.InitobjConverter |
| [constrained](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Constrained) | 0xfe16 |  |  |  |
| [cpblk](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Cpblk) | 0xfe17 |  |  |  |
| [initblk](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Initblk) | 0xfe18 |  |  |  |
| no | 0xfe19 |  |  |  |
| [rethrow](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Rethrow) | 0xfe1a |  |  |  |
| [sizeof](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Sizeof) | 0xfe1c |  |  |  |
| [refanytype](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Refanytype) | 0xfe1d |  |  |  |
| [readonly](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.Readonly) | 0xfe1e |  |  |  |
