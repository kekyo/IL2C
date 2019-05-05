// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_ARDUINO_ALL_H__
#define IL2C_PRIVATE_ARDUINO_ALL_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Arduino

#if defined(ARDUINO) && defined(__GNUC__)

#define IL2C_USE_FMOD
#define IL2C_USE_ITOW
#define IL2C_USE_TWTOI
#define IL2C_USE_WTOI
#define IL2C_USE_FREERTOS
//#define IL2C_USE_PTHREAD
//#define IL2C_USE_NO_THREADING

#include "heap.h"

#include <arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>

#include "gcc.h"
#include "strings.h"

#include "freertos.h"
#include "pthread.h"
#include "no-threading.h"

extern void il2c_sleep(uint32_t milliseconds);

#endif

#ifdef __cplusplus
}
#endif

#endif
