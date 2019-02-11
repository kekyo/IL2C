#ifndef __IL2C_H__
#define __IL2C_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////
// Runtime stack frame types

typedef struct IL2C_EXECUTION_FRAME IL2C_EXECUTION_FRAME;
typedef struct IL2C_REF_HEADER IL2C_REF_HEADER;
typedef void(*IL2C_MARK_HANDLER)(void*);

/////////////////////////////////////////////////////////////
// Garbage collector related declarations

extern void il2c_initialize();
extern void il2c_shutdown();

extern void il2c_collect();

extern void il2c_get_uninitialized_object(
    void** ppReference, uint16_t bodySize, IL2C_MARK_HANDLER pMarkHandler);

extern void il2c_link_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pNewFrame);
extern void il2c_unlink_execution_frame(/* IL2C_EXECUTION_FRAME* */ void* pFrame);

extern void il2c_mark_from_handler(void* pReference);
#define il2c_try_mark_from_handler(pReference) \
    if ((pReference) != NULL) il2c_mark_from_handler(pReference)

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;
#define __System_Object_SIZEOF__() (0)

static void System_Object__ctor(System_Object* this__)
{
}

static void __System_Object_MARK_HANDLER__(void* pReference)
{
}

extern void __System_Object_NEW__(System_Object** ppReference);

#ifdef __cplusplus
}
#endif

#endif
