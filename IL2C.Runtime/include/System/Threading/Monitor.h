#ifndef System_Threading_Monitor_H__
#define System_Threading_Monitor_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Threading.Monitor

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Monitor);

extern /* static */ void System_Threading_Monitor_Enter__System_Object(System_Object* obj);
extern /* static */ void System_Threading_Monitor_Enter__System_Object_System_Boolean_REF(System_Object* obj, bool* lockTaken);
extern /* static */ bool System_Threading_Monitor_TryEnter__System_Object(System_Object* obj);
extern /* static */ void System_Threading_Monitor_TryEnter__System_Object_System_Boolean_REF(System_Object* obj, bool* lockTaken);
extern /* static */ void System_Threading_Monitor_Exit__System_Object(System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
