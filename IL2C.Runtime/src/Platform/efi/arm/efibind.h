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

#ifndef _EFI_BIND_H_
#define _EFI_BIND_H_


#define EFI_DRIVER_ENTRY_POINT(InitFunction)
#define EFI_APPLICATION_ENTRY_POINT EFI_DRIVER_ENTRY_POINT


//
// Make sure we are using the correct packing rules per EFI specification
//
#ifndef __GNUC__
#pragma pack()
#endif


#ifdef __FreeBSD__
#include <sys/stdint.h>
#elif defined(_MSC_VER) || defined(__GNUC__)
#include <stdint.h>
#else
//
// Assume standard IA-32 alignment.
// BugBug: Need to check portability of long long
//
typedef unsigned long long  uint64_t;
typedef long long           int64_t;
typedef unsigned int        uint32_t;
typedef int                 int32_t;
typedef unsigned short      uint16_t;
typedef short               int16_t;
typedef unsigned char       uint8_t;
typedef signed char         int8_t;
#endif

typedef uint64_t   UINT64;
typedef int64_t    INT64;
typedef uint32_t   UINT32;
typedef int32_t    INT32;
typedef uint16_t   UINT16;
typedef int16_t    INT16;
typedef uint8_t    UINT8;
typedef int8_t     INT8;

#undef VOID
#define VOID    void

//
// Native integer size in stdint.h
//
typedef uint32_t  UINTN;
typedef int32_t   INTN;

#define EFIERR(a)           (0x80000000 | a)
#define EFI_ERROR_MASK      0x80000000
#define EFIERR_OEM(a)       (0xc0000000 | a)

//
// Processor specific defines
//
#define EFI_MAX_BIT       0x80000000
#define MAX_2_BITS        0xC0000000

//
// Maximum legal IA-32 address
//
#define EFI_MAX_ADDRESS   0xFFFFFFFF

//
//  Bad pointer value to use in check builds.
//  if you see this value you are using uninitialized or free'ed data
//
#define EFI_BAD_POINTER          0xAFAFAFAF
#define EFI_BAD_POINTER_AS_BYTE  0xAF

#define EFI_DEADLOOP()    { volatile UINTN __iii; __iii = 1; while (__iii); }

//
// Inject a break point in the code to assist debugging for NT Emulation Environment
// For real hardware, just put in a halt loop. Don't do a while(1) because the
// compiler will optimize away the rest of the function following, so that you run out in
// the weeds if you skip over it with a debugger.
//
#define EFI_BREAKPOINT EFI_DEADLOOP()


//
// Memory Fence forces serialization, and is needed to support out of order
//  memory transactions. The Memory Fence is mainly used to make sure IO
//  transactions complete in a deterministic sequence, and to syncronize locks
//  an other MP code. Currently no memory fencing is required.
//
#define MEMORY_FENCE()

//
// Some compilers don't support the forward reference construct:
//  typedef struct XXXXX. The forward reference is required for
//  ANSI compatibility.
//
// The following macro provide a workaround for such cases.
//


#ifdef EFI_NO_INTERFACE_DECL
  #define EFI_FORWARD_DECLARATION(x)
#else
  #define EFI_FORWARD_DECLARATION(x) typedef struct _##x x
#endif


//
// Some C compilers optimize the calling conventions to increase performance.
// EFIAPI is used to make all public APIs follow the standard C calling
// convention.
//
#define EFIAPI



//
// For symbol name in GNU assembly code, an extra "_" is necessary
//
#if defined(__GNUC__)
  ///
  /// Private worker functions for ASM_PFX()
  ///
  #define _CONCATENATE(a, b)  __CONCATENATE(a, b)
  #define __CONCATENATE(a, b) a ## b

  ///
  /// The __USER_LABEL_PREFIX__ macro predefined by GNUC represents the prefix
  /// on symbols in assembly language.
  ///
  #define ASM_PFX(name) _CONCATENATE (__USER_LABEL_PREFIX__, name)

#endif

#define INTERFACE_DECL(x) struct x

#endif
