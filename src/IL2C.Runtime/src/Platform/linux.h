////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_LINUX_H__
#define IL2C_PRIVATE_LINUX_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Linux

#if defined(__linux__) && defined(__GNUC__)

#define IL2C_USE_PTHREAD
#define IL2C_USE_ITOW

#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#define IL2C_USE_SIGNAL
#include <signal.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include <dlfcn.h>

#include "gcc.h"
#include "strings.h"
#include "pthread.h"

extern void il2c_sleep(uint32_t milliseconds);

#endif

#ifdef __cplusplus
}
#endif

#endif
