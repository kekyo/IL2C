#ifndef System_Threading_ParameterizedThreadStart_H__
#define System_Threading_ParameterizedThreadStart_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Threading.ParameterizedThreadStart

typedef System_MulticastDelegate System_Threading_ParameterizedThreadStart;

typedef System_MulticastDelegate_VTABLE_DECL__ System_Threading_ParameterizedThreadStart_VTABLE_DECL__;

#define System_Threading_ParameterizedThreadStart_VTABLE__ System_MulticastDelegate_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_ParameterizedThreadStart);

extern /* public sealed */ void System_Threading_ParameterizedThreadStart_Invoke(System_Threading_ParameterizedThreadStart* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
