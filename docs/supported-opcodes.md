# Supported IL opcodes

* Number of opcode implementations: 140 / 219
* Number of opcode tests: 930 [81 / 219]

OpCode | Binary | Implement | Test | ILConverter
|:---|:---|:---|:---|:---|
| [add](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.add) | 0x58 | Implemented | [Test [13]](../tests/IL2C.Core.Test.ILConverters/Add) | IL2C.ILConverters.AddConverter |
| [add.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.add_ovf) | 0xd6 |  |  |  |
| [add.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.add_ovf_un) | 0xd7 |  |  |  |
| [and](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.and) | 0x5f | Implemented | [Test [5]](../tests/IL2C.Core.Test.ILConverters/And) | IL2C.ILConverters.AndConverter |
| [arglist](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.arglist) | 0xfe00 |  |  |  |
| [beq](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.beq) | 0x3b | Implemented |  | IL2C.ILConverters.BeqConverter |
| [beq.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.beq_s) | 0x2e | Implemented |  | IL2C.ILConverters.Beq_sConverter |
| [bge](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge) | 0x3c | Implemented |  | IL2C.ILConverters.BgeConverter |
| [bge.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge_s) | 0x2f | Implemented |  | IL2C.ILConverters.Bge_sConverter |
| [bge.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge_un) | 0x41 |  |  |  |
| [bge.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bge_un_s) | 0x34 |  |  |  |
| [bgt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt) | 0x3d | Implemented |  | IL2C.ILConverters.BgtConverter |
| [bgt.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt_s) | 0x30 | Implemented |  | IL2C.ILConverters.Bgt_sConverter |
| [bgt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt_un) | 0x42 | Implemented |  | IL2C.ILConverters.Bgt_UnConverter |
| [bgt.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bgt_un_s) | 0x35 | Implemented |  | IL2C.ILConverters.Bgt_Un_sConverter |
| [ble](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble) | 0x3e | Implemented |  | IL2C.ILConverters.BleConverter |
| [ble.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble_s) | 0x31 | Implemented |  | IL2C.ILConverters.Ble_sConverter |
| [ble.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble_un) | 0x43 |  |  |  |
| [ble.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ble_un_s) | 0x36 |  |  |  |
| [blt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt) | 0x3f | Implemented |  | IL2C.ILConverters.BltConverter |
| [blt.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt_s) | 0x32 | Implemented |  | IL2C.ILConverters.Blt_sConverter |
| [blt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt_un) | 0x44 |  |  |  |
| [blt.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.blt_un_s) | 0x37 |  |  |  |
| [bne.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bne_un) | 0x40 | Implemented |  | IL2C.ILConverters.Bne_UnConverter |
| [bne.un.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.bne_un_s) | 0x33 | Implemented |  | IL2C.ILConverters.Bne_Un_sConverter |
| [box](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.box) | 0x8c | Implemented | [Test [78]](../tests/IL2C.Core.Test.ILConverters/Box) | IL2C.ILConverters.BoxConverter |
| [br](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.br) | 0x38 | Implemented | [Test [1]](../tests/IL2C.Core.Test.ILConverters/Br) | IL2C.ILConverters.BrConverter |
| [br.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.br_s) | 0x2b | Implemented | [Test [1]](../tests/IL2C.Core.Test.ILConverters/Br_s) | IL2C.ILConverters.Br_sConverter |
| [break](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.break) | 0x1 | Implemented | [Test [1]](../tests/IL2C.Core.Test.ILConverters/Break) | IL2C.ILConverters.BreakConverter |
| [brfalse](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brfalse) | 0x39 | Implemented | [Test [10]](../tests/IL2C.Core.Test.ILConverters/Brfalse) | IL2C.ILConverters.BrfalseConverter |
| [brfalse.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brfalse_s) | 0x2c | Implemented | [Test [10]](../tests/IL2C.Core.Test.ILConverters/Brfalse_s) | IL2C.ILConverters.Brfalse_sConverter |
| [brtrue](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brtrue) | 0x3a | Implemented | [Test [10]](../tests/IL2C.Core.Test.ILConverters/Brtrue) | IL2C.ILConverters.BrtrueConverter |
| [brtrue.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.brtrue_s) | 0x2d | Implemented | [Test [10]](../tests/IL2C.Core.Test.ILConverters/Brtrue_s) | IL2C.ILConverters.Brtrue_sConverter |
| [call](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.call) | 0x28 | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Call) | IL2C.ILConverters.CallConverter |
| [calli](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.calli) | 0x29 |  |  |  |
| [callvirt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.callvirt) | 0x6f | Implemented | [Test [23]](../tests/IL2C.Core.Test.ILConverters/Callvirt) | IL2C.ILConverters.CallvirtConverter |
| [castclass](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.castclass) | 0x74 | Implemented |  | IL2C.ILConverters.CastclassConverter |
| [ceq](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ceq) | 0xfe01 | Implemented |  | IL2C.ILConverters.CeqConverter |
| [cgt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cgt) | 0xfe02 | Implemented |  | IL2C.ILConverters.CgtConverter |
| [cgt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cgt_un) | 0xfe03 | Implemented |  | IL2C.ILConverters.Cgt_unConverter |
| [ckfinite](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ckfinite) | 0xc3 |  |  |  |
| [clt](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.clt) | 0xfe04 | Implemented |  | IL2C.ILConverters.CltConverter |
| [clt.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.clt_un) | 0xfe05 | Implemented |  | IL2C.ILConverters.Clt_unConverter |
| [constrained](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.constrained) | 0xfe16 | Implemented |  | IL2C.ILConverters.ConstrainedConverter |
| [conv.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i) | 0xd3 | Implemented | [Test [12]](../tests/IL2C.Core.Test.ILConverters/Conv_i) | IL2C.ILConverters.Conv_iConverter |
| [conv.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i1) | 0x67 | Implemented | [Test [23]](../tests/IL2C.Core.Test.ILConverters/Conv_i1) | IL2C.ILConverters.Conv_i1Converter |
| [conv.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i2) | 0x68 | Implemented | [Test [22]](../tests/IL2C.Core.Test.ILConverters/Conv_i2) | IL2C.ILConverters.Conv_i2Converter |
| [conv.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i4) | 0x69 | Implemented | [Test [20]](../tests/IL2C.Core.Test.ILConverters/Conv_i4) | IL2C.ILConverters.Conv_i4Converter |
| [conv.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_i8) | 0x6a | Implemented | [Test [20]](../tests/IL2C.Core.Test.ILConverters/Conv_i8) | IL2C.ILConverters.Conv_i8Converter |
| [conv.ovf.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i) | 0xd4 |  |  |  |
| [conv.ovf.i.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i_un) | 0x8a |  |  |  |
| [conv.ovf.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i1) | 0xb3 |  |  |  |
| [conv.ovf.i1.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i1_un) | 0x82 |  |  |  |
| [conv.ovf.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i2) | 0xb5 |  |  |  |
| [conv.ovf.i2.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i2_un) | 0x83 |  |  |  |
| [conv.ovf.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i4) | 0xb7 |  |  |  |
| [conv.ovf.i4.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i4_un) | 0x84 |  |  |  |
| [conv.ovf.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i8) | 0xb9 |  |  |  |
| [conv.ovf.i8.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_i8_un) | 0x85 |  |  |  |
| [conv.ovf.u](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u) | 0xd5 |  |  |  |
| [conv.ovf.u.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u_un) | 0x8b |  |  |  |
| [conv.ovf.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u1) | 0xb4 |  |  |  |
| [conv.ovf.u1.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u1_un) | 0x86 |  |  |  |
| [conv.ovf.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u2) | 0xb6 |  |  |  |
| [conv.ovf.u2.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u2_un) | 0x87 |  |  |  |
| [conv.ovf.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u4) | 0xb8 |  |  |  |
| [conv.ovf.u4.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u4_un) | 0x88 |  |  |  |
| [conv.ovf.u8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u8) | 0xba |  |  |  |
| [conv.ovf.u8.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_ovf_u8_un) | 0x89 |  |  |  |
| [conv.r.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_r_un) | 0x76 |  |  |  |
| [conv.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_r4) | 0x6b | Implemented | [Test [19]](../tests/IL2C.Core.Test.ILConverters/Conv_r4) | IL2C.ILConverters.Conv_r4Converter |
| [conv.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_r8) | 0x6c | Implemented | [Test [19]](../tests/IL2C.Core.Test.ILConverters/Conv_r8) | IL2C.ILConverters.Conv_r8Converter |
| [conv.u](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u) | 0xe0 | Implemented | [Test [12]](../tests/IL2C.Core.Test.ILConverters/Conv_u) | IL2C.ILConverters.Conv_uConverter |
| [conv.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u1) | 0xd2 | Implemented | [Test [22]](../tests/IL2C.Core.Test.ILConverters/Conv_u1) | IL2C.ILConverters.Conv_u1Converter |
| [conv.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u2) | 0xd1 | Implemented | [Test [21]](../tests/IL2C.Core.Test.ILConverters/Conv_u2) | IL2C.ILConverters.Conv_u2Converter |
| [conv.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u4) | 0x6d | Implemented | [Test [19]](../tests/IL2C.Core.Test.ILConverters/Conv_u4) | IL2C.ILConverters.Conv_u4Converter |
| [conv.u8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.conv_u8) | 0x6e | Implemented | [Test [19]](../tests/IL2C.Core.Test.ILConverters/Conv_u8) | IL2C.ILConverters.Conv_u8Converter |
| [cpblk](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cpblk) | 0xfe17 |  |  |  |
| [cpobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.cpobj) | 0x70 |  |  |  |
| [div](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.div) | 0x5b | Implemented | [Test [9]](../tests/IL2C.Core.Test.ILConverters/Div) | IL2C.ILConverters.DivConverter |
| [div.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.div_un) | 0x5c |  |  |  |
| [dup](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.dup) | 0x25 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Dup) | IL2C.ILConverters.DupConverter |
| [endfilter](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.endfilter) | 0xfe11 |  |  |  |
| [endfinally](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.endfinally) | 0xdc | Implemented |  | IL2C.ILConverters.EndfinallyConverter |
| [initblk](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.initblk) | 0xfe18 |  |  |  |
| [initobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.initobj) | 0xfe15 | Implemented |  | IL2C.ILConverters.InitobjConverter |
| [isinst](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.isinst) | 0x75 | Implemented | [Test [4]](../tests/IL2C.Core.Test.ILConverters/Isinst) | IL2C.ILConverters.IsinstConverter |
| [jmp](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.jmp) | 0x27 |  |  |  |
| [ldarg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg) | 0xfe09 | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Ldarg) | IL2C.ILConverters.LdargConverter |
| [ldarg.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_0) | 0x2 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldarg_0) | IL2C.ILConverters.Ldarg_0Converter |
| [ldarg.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_1) | 0x3 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldarg_1) | IL2C.ILConverters.Ldarg_1Converter |
| [ldarg.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_2) | 0x4 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldarg_2) | IL2C.ILConverters.Ldarg_2Converter |
| [ldarg.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_3) | 0x5 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldarg_3) | IL2C.ILConverters.Ldarg_3Converter |
| [ldarg.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarg_s) | 0xe | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Ldarg_s) | IL2C.ILConverters.Ldarg_sConverter |
| [ldarga](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarga) | 0xfe0a |  |  |  |
| [ldarga.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldarga_s) | 0xf | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Ldarga_s) | IL2C.ILConverters.Ldarga_sConverter |
| [ldc.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4) | 0x20 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4) | IL2C.ILConverters.Ldc_i4Converter |
| [ldc.i4.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_0) | 0x16 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_0) | IL2C.ILConverters.Ldc_i4_0Converter |
| [ldc.i4.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_1) | 0x17 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_1) | IL2C.ILConverters.Ldc_i4_1Converter |
| [ldc.i4.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_2) | 0x18 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_2) | IL2C.ILConverters.Ldc_i4_2Converter |
| [ldc.i4.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_3) | 0x19 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_3) | IL2C.ILConverters.Ldc_i4_3Converter |
| [ldc.i4.4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_4) | 0x1a | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_4) | IL2C.ILConverters.Ldc_i4_4Converter |
| [ldc.i4.5](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_5) | 0x1b | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_5) | IL2C.ILConverters.Ldc_i4_5Converter |
| [ldc.i4.6](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_6) | 0x1c | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_6) | IL2C.ILConverters.Ldc_i4_6Converter |
| [ldc.i4.7](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_7) | 0x1d | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_7) | IL2C.ILConverters.Ldc_i4_7Converter |
| [ldc.i4.8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_8) | 0x1e | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_8) | IL2C.ILConverters.Ldc_i4_8Converter |
| [ldc.i4.m1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_m1) | 0x15 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_m1) | IL2C.ILConverters.Ldc_i4_m1Converter |
| [ldc.i4.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i4_s) | 0x1f | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i4_s) | IL2C.ILConverters.Ldc_i4_sConverter |
| [ldc.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_i8) | 0x21 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_i8) | IL2C.ILConverters.Ldc_i8Converter |
| [ldc.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_r4) | 0x22 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_r4) | IL2C.ILConverters.Ldc_r4Converter |
| [ldc.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldc_r8) | 0x23 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Ldc_r8) | IL2C.ILConverters.Ldc_r8Converter |
| [ldelem.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem) | 0xa3 |  |  |  |
| [ldelem.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i) | 0x97 |  |  |  |
| [ldelem.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i1) | 0x90 | Implemented |  | IL2C.ILConverters.Ldelem_i1Converter |
| [ldelem.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i2) | 0x92 | Implemented |  | IL2C.ILConverters.Ldelem_i2Converter |
| [ldelem.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i4) | 0x94 | Implemented |  | IL2C.ILConverters.Ldelem_i4Converter |
| [ldelem.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_i8) | 0x96 | Implemented |  | IL2C.ILConverters.Ldelem_i8Converter |
| [ldelem.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_r4) | 0x98 | Implemented |  | IL2C.ILConverters.Ldelem_r4Converter |
| [ldelem.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_r8) | 0x99 | Implemented |  | IL2C.ILConverters.Ldelem_r8Converter |
| [ldelem.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_ref) | 0x9a | Implemented |  | IL2C.ILConverters.Ldelem_refConverter |
| [ldelem.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_u1) | 0x91 | Implemented |  | IL2C.ILConverters.Ldelem_u1Converter |
| [ldelem.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_u2) | 0x93 | Implemented |  | IL2C.ILConverters.Ldelem_u2Converter |
| [ldelem.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelem_u4) | 0x95 | Implemented |  | IL2C.ILConverters.Ldelem_u4Converter |
| [ldelema](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldelema) | 0x8f | Implemented |  | IL2C.ILConverters.LdelemaConverter |
| [ldfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldfld) | 0x7b | Implemented |  | IL2C.ILConverters.LdfldConverter |
| [ldflda](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldflda) | 0x7c | Implemented |  | IL2C.ILConverters.LdfldaConverter |
| [ldftn](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldftn) | 0xfe06 | Implemented |  | IL2C.ILConverters.LdftnConverter |
| [ldind.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i) | 0x4d | Implemented |  | IL2C.ILConverters.Ldind_iConverter |
| [ldind.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i1) | 0x46 | Implemented |  | IL2C.ILConverters.Ldind_i1Converter |
| [ldind.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i2) | 0x48 | Implemented |  | IL2C.ILConverters.Ldind_i2Converter |
| [ldind.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i4) | 0x4a | Implemented |  | IL2C.ILConverters.Ldind_i4Converter |
| [ldind.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_i8) | 0x4c | Implemented |  | IL2C.ILConverters.Ldind_i8Converter |
| [ldind.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_r4) | 0x4e | Implemented |  | IL2C.ILConverters.Ldind_r4Converter |
| [ldind.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_r8) | 0x4f | Implemented |  | IL2C.ILConverters.Ldind_r8Converter |
| [ldind.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_ref) | 0x50 | Implemented |  | IL2C.ILConverters.Ldind_refConverter |
| [ldind.u1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_u1) | 0x47 | Implemented |  | IL2C.ILConverters.Ldind_u1Converter |
| [ldind.u2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_u2) | 0x49 | Implemented |  | IL2C.ILConverters.Ldind_u2Converter |
| [ldind.u4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldind_u4) | 0x4b | Implemented |  | IL2C.ILConverters.Ldind_u4Converter |
| [ldlen](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldlen) | 0x8e | Implemented |  | IL2C.ILConverters.LdlenConverters |
| [ldloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc) | 0xfe0c |  |  |  |
| [ldloc.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_0) | 0x6 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldloc_0) | IL2C.ILConverters.Ldloc_0Converter |
| [ldloc.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_1) | 0x7 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldloc_1) | IL2C.ILConverters.Ldloc_1Converter |
| [ldloc.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_2) | 0x8 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldloc_2) | IL2C.ILConverters.Ldloc_2Converter |
| [ldloc.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_3) | 0x9 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldloc_3) | IL2C.ILConverters.Ldloc_3Converter |
| [ldloc.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloc_s) | 0x11 | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Ldloc_s) | IL2C.ILConverters.Ldloc_SConverter |
| [ldloca](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloca) | 0xfe0d |  |  |  |
| [ldloca.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldloca_s) | 0x12 | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Ldloca_s) | IL2C.ILConverters.Ldloca_sConverter |
| [ldnull](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldnull) | 0x14 | Implemented | [Test [3]](../tests/IL2C.Core.Test.ILConverters/Ldnull) | IL2C.ILConverters.LdnullConverter |
| [ldobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldobj) | 0x71 | Implemented | [Test [5]](../tests/IL2C.Core.Test.ILConverters/Ldobj) | IL2C.ILConverters.LdobjConverter |
| [ldsfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldsfld) | 0x7e | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldsfld) | IL2C.ILConverters.LdsfldConverter |
| [ldsflda](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldsflda) | 0x7f | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Ldsflda) | IL2C.ILConverters.LdsfldaConverter |
| [ldstr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldstr) | 0x72 | Implemented | [Test [1]](../tests/IL2C.Core.Test.ILConverters/Ldstr) | IL2C.ILConverters.LdstrConverter |
| [ldtoken](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldtoken) | 0xd0 | Implemented |  | IL2C.ILConverters.LdtokenConverters |
| [ldvirtftn](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ldvirtftn) | 0xfe07 | Implemented |  | IL2C.ILConverters.LdvirtftnConverter |
| [leave](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.leave) | 0xdd |  |  |  |
| [leave.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.leave_s) | 0xde | Implemented |  | IL2C.ILConverters.Leave_sConverter |
| [localloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.localloc) | 0xfe0f |  |  |  |
| [mkrefany](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mkrefany) | 0xc6 |  |  |  |
| [mul](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mul) | 0x5a | Implemented | [Test [9]](../tests/IL2C.Core.Test.ILConverters/Mul) | IL2C.ILConverters.MulConverter |
| [mul.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mul_ovf) | 0xd8 |  |  |  |
| [mul.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.mul_ovf_un) | 0xd9 |  |  |  |
| [neg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.neg) | 0x65 | Implemented |  | IL2C.ILConverters.NegConverter |
| [newarr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.newarr) | 0x8d | Implemented |  | IL2C.ILConverters.NewarrConverter |
| [newobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.newobj) | 0x73 | Implemented |  | IL2C.ILConverters.NewobjConverter |
| no | 0xfe19 |  |  |  |
| [nop](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.nop) | 0x0 | Implemented | [Test [1]](../tests/IL2C.Core.Test.ILConverters/Nop) | IL2C.ILConverters.NopConverter |
| [not](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.not) | 0x66 | Implemented |  | IL2C.ILConverters.NotConverter |
| [or](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.or) | 0x60 | Implemented | [Test [5]](../tests/IL2C.Core.Test.ILConverters/Or) | IL2C.ILConverters.OrConverter |
| [pop](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.pop) | 0x26 | Implemented |  | IL2C.ILConverters.PopConverter |
| [readonly](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.readonly) | 0xfe1e |  |  |  |
| [refanytype](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.refanytype) | 0xfe1d |  |  |  |
| [refanyval](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.refanyval) | 0xc2 |  |  |  |
| [rem](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.rem) | 0x5d | Implemented | [Test [9]](../tests/IL2C.Core.Test.ILConverters/Rem) | IL2C.ILConverters.RemConverter |
| [rem.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.rem_un) | 0x5e |  |  |  |
| [ret](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.ret) | 0x2a | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Ret) | IL2C.ILConverters.RetConverter |
| [rethrow](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.rethrow) | 0xfe1a | Implemented |  | IL2C.ILConverters.RethrowConverter |
| [shl](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.shl) | 0x62 | Implemented |  | IL2C.ILConverters.ShiftLeftConverter |
| [shr](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.shr) | 0x63 | Implemented |  | IL2C.ILConverters.ShiftRightConverter |
| [shr.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.shr_un) | 0x64 | Implemented |  | IL2C.ILConverters.ShiftRightUnConverter |
| [sizeof](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sizeof) | 0xfe1c | Implemented |  | IL2C.ILConverters.SizeofConverter |
| [starg](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.starg) | 0xfe0b | Implemented |  | IL2C.ILConverters.StargConverter |
| [starg.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.starg_s) | 0x10 | Implemented |  | IL2C.ILConverters.StargSConverter |
| [stelem.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem) | 0xa4 | Implemented | [Test [42]](../tests/IL2C.Core.Test.ILConverters/Stelem) | IL2C.ILConverters.Stelem_anyConvertersConverter |
| [stelem.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i) | 0x9b |  |  |  |
| [stelem.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i1) | 0x9c | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_i1) | IL2C.ILConverters.Stelem_i1ConvertersConverter |
| [stelem.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i2) | 0x9d | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_i2) | IL2C.ILConverters.Stelem_i2ConvertersConverter |
| [stelem.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i4) | 0x9e | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_i4) | IL2C.ILConverters.Stelem_i4ConvertersConverter |
| [stelem.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_i8) | 0x9f | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_i8) | IL2C.ILConverters.Stelem_i8ConvertersConverter |
| [stelem.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_r4) | 0xa0 | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_r4) | IL2C.ILConverters.Stelem_r4ConvertersConverter |
| [stelem.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_r8) | 0xa1 | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_r8) | IL2C.ILConverters.Stelem_r8ConvertersConverter |
| [stelem.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stelem_ref) | 0xa2 | Implemented | [Test [6]](../tests/IL2C.Core.Test.ILConverters/Stelem_ref) | IL2C.ILConverters.Stelem_refConvertersConverter |
| [stfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stfld) | 0x7d | Implemented |  | IL2C.ILConverters.StfldConverter |
| [stind.i](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i) | 0xdf |  |  |  |
| [stind.i1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i1) | 0x52 | Implemented |  | IL2C.ILConverters.Stind_i1Converter |
| [stind.i2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i2) | 0x53 | Implemented |  | IL2C.ILConverters.Stind_i2Converter |
| [stind.i4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i4) | 0x54 | Implemented |  | IL2C.ILConverters.Stind_i4Converter |
| [stind.i8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_i8) | 0x55 | Implemented |  | IL2C.ILConverters.Stind_i8Converter |
| [stind.r4](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_r4) | 0x56 | Implemented |  | IL2C.ILConverters.Stind_r4Converter |
| [stind.r8](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_r8) | 0x57 | Implemented |  | IL2C.ILConverters.Stind_r8Converter |
| [stind.ref](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stind_ref) | 0x51 | Implemented |  | IL2C.ILConverters.Stind_RefConverter |
| [stloc](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc) | 0xfe0e |  |  |  |
| [stloc.0](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_0) | 0xa | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Stloc_0) | IL2C.ILConverters.Stloc_0Converter |
| [stloc.1](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_1) | 0xb | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Stloc_1) | IL2C.ILConverters.Stloc_1Converter |
| [stloc.2](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_2) | 0xc | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Stloc_2) | IL2C.ILConverters.Stloc_2Converter |
| [stloc.3](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_3) | 0xd | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Stloc_3) | IL2C.ILConverters.Stloc_3Converter |
| [stloc.s](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stloc_s) | 0x13 | Implemented | [Test [17]](../tests/IL2C.Core.Test.ILConverters/Stloc_s) | IL2C.ILConverters.Stloc_SConverter |
| [stobj](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stobj) | 0x81 |  |  |  |
| [stsfld](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.stsfld) | 0x80 | Implemented | [Test [16]](../tests/IL2C.Core.Test.ILConverters/Stsfld) | IL2C.ILConverters.StsfldConverter |
| [sub](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sub) | 0x59 | Implemented | [Test [11]](../tests/IL2C.Core.Test.ILConverters/Sub) | IL2C.ILConverters.SubConverter |
| [sub.ovf](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sub_ovf) | 0xda |  |  |  |
| [sub.ovf.un](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.sub_ovf_un) | 0xdb |  |  |  |
| [switch](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.switch) | 0x45 | Implemented | [Test [8]](../tests/IL2C.Core.Test.ILConverters/Switch) | IL2C.ILConveters.SwitchConverter |
| [tail](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.tailcall) | 0xfe14 |  |  |  |
| [throw](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.throw) | 0x7a | Implemented |  | IL2C.ILConverters.ThrowConverter |
| [unaligned](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.unaligned) | 0xfe12 |  |  |  |
| [unbox](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.unbox) | 0x79 |  |  |  |
| [unbox.any](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.unbox_any) | 0xa5 | Implemented | [Test [2]](../tests/IL2C.Core.Test.ILConverters/Unbox_any) | IL2C.ILConverters.Unbox_AnyConverter |
| [volatile](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.volatile) | 0xfe13 |  |  |  |
| [xor](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.emit.opcodes.xor) | 0x61 | Implemented | [Test [5]](../tests/IL2C.Core.Test.ILConverters/Xor) | IL2C.ILConverters.XorConverter |
