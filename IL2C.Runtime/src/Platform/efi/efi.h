/* $FreeBSD: releng/11.1/sys/boot/efi/include/efi.h 292625 2015-12-22 20:40:34Z emaste $ */
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

    efi.h

Abstract:

    Public EFI header files



Revision History

--*/

//
// Build flags on input
//  EFI32
//  EFI_DEBUG               - Enable debugging code
//  EFI_NT_EMULATOR         - Building for running under NT
//

#ifndef _EFI_INCLUDE_
#define _EFI_INCLUDE_

#pragma once

#define EFI_FIRMWARE_VENDOR         L"INTEL"
#define EFI_FIRMWARE_MAJOR_REVISION 14
#define EFI_FIRMWARE_MINOR_REVISION 62
#define EFI_FIRMWARE_REVISION ((EFI_FIRMWARE_MAJOR_REVISION <<16) | (EFI_FIRMWARE_MINOR_REVISION))

#if defined(_M_IX86) || defined(__i386__)
#include "i386/efibind.h"
#elif defined(_M_AMD64) || defined(_M_X64) || defined(__x86_64__)
#include "amd64/efibind.h"
#elif defined(_M_ARM) || (defined(__arm__) && defined(__thumb__))
#include "arm/efibind.h"
#elif defined(_M_ARM64) || (defined(__arm__) && !defined(__thumb__))
#include "arm64/efibind.h"
#endif

#include "efidef.h"
#include "efidebug.h"
#include "efidevp.h"
#include "efiprot.h"
#include "eficon.h"
#include "efiser.h"
#include "efi_nii.h"
#include "efipxebc.h"
#include "efinet.h"
#include "efiapi.h"
#include "efifs.h"
#include "efierr.h"
#include "efigop.h"

#define EFI_STRINGIZE(a)                #a 
#define EFI_PROTOCOL_DEFINITION(a)      EFI_STRINGIZE(Protocol/a/a.h) 

#define EFI_GUID_DEFINITION(a) EFI_STRINGIZE(Guid/a/a##.h) 
#define EFI_GUID_STRING(guidpointer, shortstring, longstring)

#endif
