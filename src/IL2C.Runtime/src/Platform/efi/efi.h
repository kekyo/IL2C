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
