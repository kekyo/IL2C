#pragma once

#include <stdint.h>
#include <memory.h>

intptr_t __memmem(intptr_t p1, int32_t s1, intptr_t p2, int32_t s2);
void __memcpy(intptr_t pDest, intptr_t pSource, int32_t size);
