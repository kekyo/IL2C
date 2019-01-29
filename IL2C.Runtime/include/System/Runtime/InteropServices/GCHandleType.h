#ifndef System_Runtime_InteropServices_GCHandleType_H__
#define System_Runtime_InteropServices_GCHandleType_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.GCHandleType

typedef int32_t System_Runtime_InteropServices_GCHandleType;

// TODO: Weak references
//static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_Weak = 0;
//static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_WeakResurrection = 1;
static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_Normal = 2;
static const System_Runtime_InteropServices_GCHandleType System_Runtime_InteropServices_GCHandleType_Pinned = 3;

#ifdef __cplusplus
}
#endif

#endif
