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

/* $FreeBSD: releng/11.1/sys/boot/efi/include/efidebug.h 292625 2015-12-22 20:40:34Z emaste $ */
#ifndef _EFI_DEBUG_H
#define _EFI_DEBUG_H

/*++

Copyright (c)  1999 - 2002 Intel Corporation. All rights reserved
This software and associated documentation (if any) is furnished
under a license and may only be used or copied in accordance
with the terms of the license. Except as permitted by such
license, no part of this software or documentation may be
reproduced, stored in a retrieval system, or transmitted in any
form or by any means without the express written consent of
Intel Corporation.

Module Name:

    efidebug.h

Abstract:

    EFI library debug functions



Revision History

--*/

extern UINTN     EFIDebug;

#if EFI_DEBUG

    #define DBGASSERT(a)        DbgAssert(__FILE__, __LINE__, #a)
    #define DEBUG(a)            DbgPrint a
    
#else

    #define DBGASSERT(a)
    #define DEBUG(a)
    
#endif

#if EFI_DEBUG_CLEAR_MEMORY

    #define DBGSETMEM(a,l)      SetMem(a,l,(CHAR8)BAD_POINTER)

#else

    #define DBGSETMEM(a,l)

#endif

#define D_INIT        0x00000001          // Initialization style messages
#define D_WARN        0x00000002          // Warnings
#define D_LOAD        0x00000004          // Load events
#define D_FS          0x00000008          // EFI File system
#define D_POOL        0x00000010          // Alloc & Free's
#define D_PAGE        0x00000020          // Alloc & Free's
#define D_INFO        0x00000040          // Verbose
#define D_VARIABLE    0x00000100          // Variable
#define D_VAR         0x00000100          // Variable
#define D_BM          0x00000400          // Boot Manager 
#define D_BLKIO       0x00001000          // BlkIo Driver
#define D_BLKIO_ULTRA 0x00002000          // BlkIo Driver
#define D_NET         0x00004000          // SNI Driver
#define D_NET_ULTRA   0x00008000          // SNI Driver
#define D_UNDI        0x00010000          // UNDI Driver
#define D_LOADFILE    0x00020000          // UNDI Driver
#define D_EVENT       0x00080000          // Event messages

#define D_ERROR       0x80000000          // Error

#define D_RESERVED    0x7ff40A80          // Bits not reserved above

//
// Current Debug level of the system, value of EFIDebug
//
//#define EFI_DBUG_MASK   (D_ERROR | D_WARN | D_LOAD | D_BLKIO | D_INIT)
#define EFI_DBUG_MASK   (D_ERROR)

//
//
//

#if EFI_DEBUG

    #define ASSERT(a)               if(!(a))       DBGASSERT(a)
    #define ASSERT_LOCKED(l)        if(!(l)->Lock) DBGASSERT(l not locked)
    #define ASSERT_STRUCT(p,t)      DBGASSERT(t not structure), p

#else

    #define ASSERT(a)               
    #define ASSERT_LOCKED(l)        
    #define ASSERT_STRUCT(p,t)      

#endif

//
// Prototypes
//

INTN
DbgAssert (
    CHAR8   *file,
    INTN    lineno,
    CHAR8   *string
    );

INTN
DbgPrint (
    INTN    mask,
    CHAR8   *format,
    ...
    );

#endif
