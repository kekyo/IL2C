#ifndef System_GC_H__
#define System_GC_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.GC

IL2C_DECLARE_RUNTIME_TYPE(System_GC);

extern /* static */ void System_GC_SuppressFinalize(System_Object* obj);
extern /* static */ void System_GC_ReRegisterForFinalize(System_Object* obj);
#define System_GC_WaitForPendingFinalizers() ((void)0)
extern /* static */ void System_GC_Collect(void);

#ifdef __cplusplus
}
#endif

#endif
