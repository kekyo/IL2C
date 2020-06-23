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

/* $FreeBSD: releng/11.1/sys/boot/efi/include/efifpswa.h 293724 2016-01-12 02:17:39Z smh $ */
#ifndef _EFI_FPSWA_H
#define _EFI_FPSWA_H

/*
 * EFI FP SWA Driver (Floating Point Software Assist)
 */

#define EFI_INTEL_FPSWA \
    { 0xc41b6531, 0x97b9, 0x11d3, {0x9a, 0x29, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d} }

INTERFACE_DECL(_FPSWA_INTERFACE);

typedef struct _FPSWA_RET {
    UINT64                          status;
    UINT64                          err1;
    UINT64                          err2;
    UINT64                          err3;
} FPSWA_RET;

typedef
FPSWA_RET
(EFIAPI *EFI_FPSWA) (
    IN UINTN                        TrapType,
    IN OUT VOID                     *Bundle,
    IN OUT UINT64                   *pipsr,
    IN OUT UINT64                   *pfsr,
    IN OUT UINT64                   *pisr,
    IN OUT UINT64                   *ppreds,
    IN OUT UINT64                   *pifs,
    IN OUT VOID                     *fp_state
    );

typedef struct _FPSWA_INTERFACE {
    UINT32                          Revision;
    UINT32                          Reserved;
    EFI_FPSWA                       Fpswa;
} FPSWA_INTERFACE;

#endif
