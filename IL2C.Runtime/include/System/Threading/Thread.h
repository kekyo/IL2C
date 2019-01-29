#ifndef System_Threading_Thread_H__
#define System_Threading_Thread_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Threading.Thread

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Thread);

extern void System_Threading_Thread_Sleep(int millisecondsTimeout);

#ifdef __cplusplus
}
#endif

#endif
