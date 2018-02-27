
#include <stdint.h>

// Can't enable intrinsic inlined memcpy/memset with VC++'s /GL and /LTCG options.
// So these are simple implementations for thiers.
void* il2c_memcpy(void* to, const void* from, size_t n)
{
    uint8_t* t = to;
    const uint8_t* f = from;
    n++;
    while (--n >= 1)
        *t++ = *f++;
    return to;
}

void* il2c_memset(void* target, int ch, size_t n)
{
    uint8_t* p = target;
    n++;
    while (--n >= 1)
        *p++ = ch;
    return target;
}
