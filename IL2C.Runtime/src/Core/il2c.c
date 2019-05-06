#include <il2c_private.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////

typedef volatile struct IL2C_ROOT_REFERENCES_DECL IL2C_ROOT_REFERENCES;
typedef struct IL2C_MONITOR_LOCK_BLOCK_INFORMATION_DECL IL2C_MONITOR_LOCK_BLOCK_INFORMATION;
typedef void(*il2c_sighandler)(int sig);

extern IL2C_REF_HEADER* g_pBeginHeader__;
extern IL2C_ROOT_REFERENCES* g_pRootReferences__;
extern IL2C_ROOT_REFERENCES* g_pFixedReferences__;
extern IL2C_STATIC_FIELDS* g_pBeginStaticFields__;

extern IL2C_MONITOR_LOCK_BLOCK_INFORMATION* g_MonitorLockBlockInformations__[7];
extern IL2C_MONITOR_LOCK g_GlobalLockForCollect__;

#if defined(_DEBUG)
extern int64_t g_CollectCountBreak;
#endif

#if defined(IL2C_USE_SIGNAL)
extern il2c_sighandler g_SIGSEGV_saved;
extern il2c_noreturn__ void il2c_SIGSEGV_handler(int sig);
#endif

extern IL2C_TLS_INDEX g_TlsIndex__;

// The initializer count produces when works the type initializer.
// "il2c_initializer_count" will compare the local type counter,
// the translated code have to initialize first using static members if count value different.
static uintptr_t g_InitializerCount = 0;
const uintptr_t* il2c_initializer_count = &g_InitializerCount;

extern void il2c_collect_for_final_shutdown__(void);

/////////////////////////////////////////////////////////////
// Runtime cast functions

uint32_t il2c_sizeof__(IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);

    return ((type)->flags & IL2C_TYPE_VALUE) ?
        (uint32_t)(type)->bodySize :
        (uint32_t)sizeof(intptr_t);
}

void* il2c_isinst__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    System_Object* pAdjustedReference = il2c_adjusted_reference(pReference);
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
    IL2C_RUNTIME_TYPE currentType = pHeader->type;

    if (type->flags & IL2C_TYPE_INTERFACE)
    {
        do
        {
            IL2C_IMPLEMENTED_INTERFACE* pInterface =
                (IL2C_IMPLEMENTED_INTERFACE*)(((IL2C_MARK_TARGET*)(currentType + 1)) + currentType->markTarget);
            uintptr_t index;
            for (index = 0;
                il2c_likely__(index < currentType->interfaceCount);
                index++, pInterface++)
            {
                il2c_assert((pInterface->type->flags & IL2C_TYPE_INTERFACE) == IL2C_TYPE_INTERFACE);

                if (il2c_unlikely__(pInterface->type == type))
                {
                    uintptr_t offset = *(const uintptr_t*)(pInterface->vptr0);
                    return (void*)(((uint8_t*)pAdjustedReference) + offset);
                }
            }

            currentType = currentType->baseType;
        }
        while (il2c_likely__(currentType != NULL));
    }
    else
    {
        do
        {
            if (il2c_unlikely__(currentType == type))
            {
                return pReference;
            }
            currentType = currentType->baseType;
        }
        while (il2c_likely__(currentType != NULL));
    }

    return NULL;
}

void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    void* p = il2c_isinst__(pReference, type);
    if (il2c_unlikely__(p == NULL))
    {
        il2c_throw_invalidcastexception__();
    }

    return p;
}

/////////////////////////////////////////////////////////////
// Boxing related functions

// +----------------------+
// | IL2C_REF_HEADER      |
// +----------------------+ <-- pBoxed        -----------------------------------------------
// | vptr0__              | <-- pVTable0        | System_ValueType                         ^
// +----------------------+                   -----------                                  |
// |        :             |                     ^                                          | bodySize
// | (value data)         | Copy from pValue    | type->bodySize                           |
// |        :             |                     v                                          |
// +----------------------+                   ---------------------------                  |
// | vptr_IFoo__          |                     | (optional implemented interface vptr)    |
// +----------------------+                   ---------------------------                  |
// | vptr_IBar__          |                     | (optional implemented interface vptr)    v
// +----------------------+                   -----------------------------------------------

#if defined(IL2C_USE_LINE_INFORMATION)
System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, const char* pFile, int line)
#else
System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType)
#endif
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);

    uintptr_t bodySize = sizeof(System_ValueType) +
        valueType->bodySize +
        valueType->interfaceCount * sizeof(void*);  // interface vptrs
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize,
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_ValueType* pBoxed = (System_ValueType*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)pBoxed;

    il2c_assert(pBoxed->vptr0__ == valueType->vptr0);

    memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), pValue, valueType->bodySize);

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return pBoxed;
}

// Boxing with widing/narrowing combination for signed/unsigned integer value.
// NOTE: This implemenation makes safer for endian order.
#if defined(IL2C_USE_LINE_INFORMATION)
System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType, const char* pFile, int line)
#else
System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType)
#endif
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert(stackType != NULL);

    // Require type conversion  (OK: IL2C_TYPE_INTEGER || IL2C_TYPE_UNSIGNED_INTEGER)
    il2c_assert(
        ((valueType->flags & IL2C_TYPE_INTEGER) == IL2C_TYPE_INTEGER) &&
        ((stackType->flags & IL2C_TYPE_INTEGER) == IL2C_TYPE_INTEGER));
    il2c_assert((valueType->bodySize <= 8) && (stackType->bodySize <= 8));
    il2c_assert((valueType->bodySize >= 1) && (stackType->bodySize >= 1));

    // TODO: value type --> interface type

    union _v { // Lesser stack spaces for this combined variables.
        int8_t i1;
        int16_t i2;
        int32_t i4;
        int64_t i8;
        uint8_t u1;
        uint16_t u2;
        uint32_t u4;
        uint64_t u8;
    } v;
    v.u8 = 0;

    // Destination integer value is unsigned.
    const bool vui = (valueType->flags & IL2C_TYPE_UNSIGNED_INTEGER) == IL2C_TYPE_UNSIGNED_INTEGER;
    // Source integer value is unsigned.
    const bool sui = (stackType->flags & IL2C_TYPE_UNSIGNED_INTEGER) == IL2C_TYPE_UNSIGNED_INTEGER;

    // Destination size
    switch (valueType->bodySize)
    {
    case 1:
        // Source size
        switch (stackType->bodySize)
        {
        case 2:
            if (vui && sui) v.u1 = (uint8_t)*(uint16_t*)pValue;
            else if (vui) v.u1 = (uint8_t)*(int16_t*)pValue;
            else if (sui) v.i1 = (int8_t)*(uint16_t*)pValue;
            else v.i1 = (int8_t)*(int16_t*)pValue;
            break;
        case 4:
            if (vui && sui) v.u1 = (uint8_t)*(uint32_t*)pValue;
            else if (vui) v.u1 = (uint8_t)*(int32_t*)pValue;
            else if (sui) v.i1 = (int8_t)*(uint32_t*)pValue;
            else v.i1 = (int8_t)*(int32_t*)pValue;
            break;
        default:
            il2c_throw_invalidcastexception__();
        }
        break;
    case 2:
        // Source size
        switch (stackType->bodySize)
        {
        case 1:
            if (vui && sui) v.u2 = (uint16_t)*(uint8_t*)pValue;
            else if (vui) v.u2 = (uint16_t)*(int8_t*)pValue;
            else if (sui) v.i2 = (int16_t)*(uint8_t*)pValue;
            else v.i2 = (int16_t)*(int8_t*)pValue;
            break;
        case 4:
            if (vui && sui) v.u2 = (uint16_t)*(uint32_t*)pValue;
            else if (vui) v.u2 = (uint16_t)*(int32_t*)pValue;
            else if (sui) v.i2 = (int16_t)*(uint32_t*)pValue;
            else v.i2 = (int16_t)*(int32_t*)pValue;
            break;
        default:
            il2c_throw_invalidcastexception__();
        }
        break;
    case 4:
        // Source size
        switch (stackType->bodySize)
        {
        case 1:
            if (vui && sui) v.u4 = (uint32_t)*(uint8_t*)pValue;
            else if (vui) v.u4 = (uint32_t)*(int8_t*)pValue;
            else if (sui) v.i4 = (int32_t)*(uint8_t*)pValue;
            else v.i4 = (int32_t)*(int8_t*)pValue;
            break;
        case 2:
            if (vui && sui) v.u4 = (uint32_t)*(uint16_t*)pValue;
            else if (vui) v.u4 = (uint32_t)*(int16_t*)pValue;
            else if (sui) v.i4 = (int32_t)*(uint16_t*)pValue;
            else v.i4 = (int32_t)*(int16_t*)pValue;
            break;
        case 8:   // Hmm, the ECMA-335 not contains this conversion but .NET CLR 4 can do it.
            if (vui && sui) v.u4 = (uint32_t)*(uint64_t*)pValue;
            else if (vui) v.u4 = (uint32_t)*(int64_t*)pValue;
            else if (sui) v.i4 = (int32_t)*(uint64_t*)pValue;
            else v.i4 = (int32_t)*(int64_t*)pValue;
            break;
        default:
            il2c_throw_invalidcastexception__();
        }
        break;
    default:
        il2c_throw_invalidcastexception__();
    }

    const uintptr_t bodySize = sizeof(System_ValueType) +
        valueType->bodySize +
        valueType->interfaceCount * sizeof(void*);  // interface vptrs
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize,
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_ValueType* pBoxed = (System_ValueType*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)pBoxed;

    il2c_assert(pBoxed->vptr0__ == valueType->vptr0);

    switch (valueType->bodySize)
    {
    case 1:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i1, 1);
        break;
    case 2:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i2, 2);
        break;
    case 4:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i4, 4);
        break;
    case 8:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i8, 8);
        break;
    }

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return pBoxed;
}

void* il2c_unbox__(/* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE valueType)
{
    if (il2c_unlikely__(pReference == NULL))
    {
        if (il2c_unlikely__(valueType->flags & IL2C_TYPE_VALUE))
        {
            il2c_throw_nullreferenceexception__();
        }
        return NULL;
    }

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pReference) - sizeof(IL2C_REF_HEADER));
    if (il2c_unlikely__(pHeader->type != valueType))
    {
        il2c_throw_invalidcastexception__();
    }

    return il2c_unsafe_unbox__(pReference, void);
}

/////////////////////////////////////////////////////////////
// IL2C runtime initialzer / shutdown

void il2c_initialize__(void)
{
    g_InitializerCount++;

    g_TlsIndex__ = il2c_tls_alloc();

    g_pBeginHeader__ = NULL;
    g_pBeginStaticFields__ = NULL;
    g_pRootReferences__ = NULL;
    g_pFixedReferences__ = NULL;

    memset(&g_MonitorLockBlockInformations__[0], 0, sizeof g_MonitorLockBlockInformations__);

    il2c_initialize_monitor_lock__(&g_GlobalLockForCollect__);

#if defined(_DEBUG)
    g_CollectCountBreak = -1;
#endif

#ifdef IL2C_USE_SIGNAL
    g_SIGSEGV_saved = signal(SIGSEGV, il2c_SIGSEGV_handler);
#endif
}

void il2c_shutdown__(void)
{
    il2c_collect_for_final_shutdown__();

#ifdef IL2C_USE_SIGNAL
    signal(SIGSEGV, g_SIGSEGV_saved);
#endif

    il2c_destroy_monitor_lock__(&g_GlobalLockForCollect__);

    il2c_tls_free(g_TlsIndex__);
}
