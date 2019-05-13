#include <il2c_private.H>

///////////////////////////////////////////////////
// Lack for threading support

#if defined(IL2C_NO_THREADING)

intptr_t g_TLS0;

#endif
