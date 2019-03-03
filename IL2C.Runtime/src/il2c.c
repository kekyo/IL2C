#include <il2c_private.h>
#include "Private/debugbreak.h"

/////////////////////////////////////////////////////////////

typedef const struct IL2C_VALUE_DESCRIPTOR_DECL
{
    const IL2C_RUNTIME_TYPE type_value;
    const void* ptr_value;
} IL2C_VALUE_DESCRIPTOR;

typedef volatile struct IL2C_EXECUTION_FRAME_DECL
{
    IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    volatile void* pReferences__[1];     // objRefCount__
    // IL2C_VALUE_DESCRIPTOR valueDescriptors__[];  // valueCount__
} IL2C_EXECUTION_FRAME;

typedef volatile struct IL2C_FIXED_INSTANCES_DECL IL2C_FIXED_INSTANCES;

struct IL2C_FIXED_INSTANCES_DECL
{
    IL2C_FIXED_INSTANCES* pNext;
    volatile void* pReferences[3];
};

// TODO: Become store to thread local storage
static IL2C_EXECUTION_FRAME* g_pBeginFrame__ = NULL;
static IL2C_EXCEPTION_FRAME* g_pTopUnwindTarget__ = NULL;

static IL2C_EXECUTION_FRAME* g_pBeginStaticFields__ = NULL;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;
static IL2C_FIXED_INSTANCES* g_pFixedInstances__ = NULL;
static interlock_t g_ExecutingCollection__ = 0;

#if defined(_DEBUG)
static void il2c_collect__(bool finalShutdown, const char* pFile, int line);
#else
static void il2c_collect__(bool finalShutdown);
#endif

// The initializer count produces when works the type initializer.
// "il2c_initializer_count" will compare the local type counter,
// the translated code have to initialize first using static members if count value different.
static uintptr_t g_InitializerCount = 0;
const uintptr_t* il2c_initializer_count = &g_InitializerCount;

/////////////////////////////////////////////////////////////
// Instance allocator functions

#if defined(_DEBUG)
void* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE type, uintptr_t bodySize, const char* pFile, int line)
#else
void* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE type, uintptr_t bodySize)
#endif
{
    // TODO: always collect
#if defined(_DEBUG)
    il2c_collect__(false, pFile, line);
#else
    il2c_collect__(false);
#endif

    // +----------------------+ <-- pHeader
    // | IL2C_REF_HEADER      |
    // +----------------------+ <-- pReference   -------
    // |          :           |                    ^
    // | (Instance body)      |                    | bodySize
    // |          :           |                    v
    // +----------------------+                  -------

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)il2c_malloc(sizeof(IL2C_REF_HEADER) + bodySize);
    if (pHeader == NULL)
    {
        while (1)
        {
            // Cannot allocate: force collecting
#if defined(_DEBUG)
            il2c_collect__(false, pFile, line);
#else
            il2c_collect__(false);
#endif

            // Retry
            pHeader = (IL2C_REF_HEADER*)il2c_malloc(sizeof(IL2C_REF_HEADER) + bodySize);
            if (pHeader != NULL)
            {
                break;
            }

            // throw NotEnoughMemoryException();
            il2c_assert(0);
        }
    }

    void* pReference = ((uint8_t*)pHeader) + sizeof(IL2C_REF_HEADER);
    // Guarantee cleared body
    memset(pReference, 0, bodySize);

    pHeader->pNext = NULL;
    pHeader->type = type;
    pHeader->characteristic = 0;

    // Safe link both headers.
    while (1)
    {
        IL2C_REF_HEADER* pNext = g_pBeginHeader__;
        pHeader->pNext = pNext;
        if ((IL2C_REF_HEADER*)il2c_icmpxchgptr(&g_pBeginHeader__, pHeader, pNext) == pNext)
        {
            break;
        }
    }

    return pReference;
}

static void il2c_setup_interface_vptrs(IL2C_RUNTIME_TYPE type, void* pReference)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    // Setup interface vptrs.
    IL2C_IMPLEMENTED_INTERFACE* pInterface =
        (IL2C_IMPLEMENTED_INTERFACE*)(((IL2C_MARK_TARGET*)(type + 1)) + type->markTarget);
    uintptr_t index;
    for (index = 0;
        index < type->interfaceCount;
        index++, pInterface++)
    {
        il2c_assert((pInterface->type->flags & IL2C_TYPE_INTERFACE) == IL2C_TYPE_INTERFACE);

        // The interface vptr offset placed at vptr[0].
        uintptr_t offset = *(const uintptr_t*)(pInterface->vptr0);
        *((const void**)(((uint8_t*)pReference) + offset)) = pInterface->vptr0;
    }
}

#if defined(_DEBUG)
void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type, const char* pFile, int line)
#else
void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type)
#endif
{
    il2c_assert(type != NULL);
    il2c_assert(type->vptr0 != NULL);

    // String, Delegate or Array (IL2C_TYPE_VARIABLE):
    // throw new InvalidProgramException();
    il2c_assert((type->flags & IL2C_TYPE_VARIABLE) == 0);
    il2c_assert(type->bodySize >= sizeof(void*));   // vptr0

    // Setup vptr0
#if defined(_DEBUG)
    uint8_t* pReference = il2c_get_uninitialized_object_internal__(type, type->bodySize, pFile, line);
#else
    uint8_t* pReference = il2c_get_uninitialized_object_internal__(type, type->bodySize);
#endif
    *((const void**)pReference) = type->vptr0;

    // Setup interface vptrs.
    il2c_setup_interface_vptrs(type, pReference);

    return pReference;
}

/////////////////////////////////////////////////////////////
// Execution frame linker functions

#if defined(_DEBUG)
void il2c_link_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pNewFrame, const char* pFile, int line)
#else
void il2c_link_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pNewFrame)
#endif
{
    il2c_assert(pNewFrame != NULL);
    il2c_assert(((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ == NULL);

    while (1)
    {
        IL2C_EXECUTION_FRAME* pNext = g_pBeginFrame__;
        ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ = pNext;
        if (il2c_icmpxchgptr(&g_pBeginFrame__, pNewFrame, pNext) == pNext)
        {
            break;
        }
    }
}

#if defined(_DEBUG)
void il2c_unlink_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pFrame, const char* pFile, int line)
#else
void il2c_unlink_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pFrame)
#endif
{
    il2c_assert(pFrame != NULL);

    // TODO: always collect
#if defined(_DEBUG)
    il2c_collect__(false, pFile, line);
#else
    il2c_collect__(false);
#endif

    g_pBeginFrame__ = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext__;
}

/////////////////////////////////////////////////////////////
// Static fields tracing functions

void il2c_register_static_fields(/* IL2C_EXECUTION_FRAME* */ volatile void* pStaticFields)
{
    il2c_assert(pStaticFields != NULL);

    IL2C_EXECUTION_FRAME* p = pStaticFields;

    memset((void*)&(p->pReferences__[0]), 0,
        (p->objRefCount__ * sizeof(void*)) + (p->valueCount__ * sizeof(IL2C_VALUE_DESCRIPTOR)));

    while (1)
    {
        IL2C_EXECUTION_FRAME* pNext = g_pBeginStaticFields__;
        p->pNext__ = pNext;
        if (il2c_icmpxchgptr(&g_pBeginStaticFields__, p, pNext) == pNext)
        {
            break;
        }
    }
}

/////////////////////////////////////////////////////////////
// GC fixed instance manipulator functions

void il2c_register_fixed_instance__(void* pReference)
{
    il2c_assert(pReference != NULL);

    // TODO: O(n) order
    IL2C_FIXED_INSTANCES* pCurrentFixedInstances = g_pFixedInstances__;
    volatile void* volatile* ppFreeReference = NULL;
    while (pCurrentFixedInstances != NULL)
    {
        uint8_t index;
        volatile void* volatile* ppReference;
        for (index = 0, ppReference = &pCurrentFixedInstances->pReferences[0];
            index < sizeof(pCurrentFixedInstances->pReferences) / sizeof(void*);
            index++, ppReference++)
        {
            if (*ppReference == pReference)
            {
                // Already registered
                return;
            }
            if (*ppReference == NULL)
            {
                ppFreeReference = ppReference;
            }
        }

        pCurrentFixedInstances = pCurrentFixedInstances->pNext;
    }

    if (ppFreeReference != NULL)
    {
        *ppFreeReference = pReference;
        return;
    }

    pCurrentFixedInstances = il2c_malloc(sizeof(IL2C_FIXED_INSTANCES));
    memset((void*)pCurrentFixedInstances, 0, sizeof(IL2C_FIXED_INSTANCES));

    pCurrentFixedInstances->pReferences[0] = pReference;

    while (1)
    {
        IL2C_FIXED_INSTANCES* pNext = g_pFixedInstances__;
        pCurrentFixedInstances->pNext = pNext;
        if (il2c_icmpxchgptr(&g_pFixedInstances__, pCurrentFixedInstances, pNext) == pNext)
        {
            break;
        }
    }
}

void il2c_unregister_fixed_instance__(void* pReference)
{
    il2c_assert(pReference != NULL);

    // TODO: O(n) order
    IL2C_FIXED_INSTANCES* pCurrentFixedInstances = g_pFixedInstances__;
    while (pCurrentFixedInstances != NULL)
    {
        uint8_t index;
        volatile void* volatile* ppReference; 
        for (index = 0, ppReference = &pCurrentFixedInstances->pReferences[0];
            index < sizeof(pCurrentFixedInstances->pReferences) / sizeof(void*);
            index++, ppReference++)
        {
            if (*ppReference == pReference)
            {
                // Found, unregister.
                *ppReference = NULL;
                return;
            }
        }

        pCurrentFixedInstances = pCurrentFixedInstances->pNext;
    }
}

static void il2c_unregister_all_fixed_instance_for_final_shutdown__(void)
{
    while (1)
    {
        IL2C_FIXED_INSTANCES* pCurrent = g_pFixedInstances__;
        if (pCurrent == NULL)
        {
            break;
        }

        g_pFixedInstances__ = pCurrent->pNext;
        il2c_free((void*)pCurrent);
    }
}

/////////////////////////////////////////////////////////////
// GC Mark handler

typedef void(*IL2C_MARK_HANDLER)(void* pReference);

// Has to ignore if objref is const.
// HACK: It's shame the icmpxchg may cause system fault if header is placed at read-only memory (CONST).
//   (at x86/x64 cause, another platform may cause)
#define TRY_GET_HEADER(pHeader, pReference) \
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pReference); \
    if ((pHeader->characteristic & (IL2C_CHARACTERISTIC_CONST | IL2C_CHARACTERISTIC_LIVE)) == 0)

static void il2c_mark_handler_recursive__(void* p, IL2C_RUNTIME_TYPE type, const uint8_t offset);

static void il2c_mark_handler_for_objref__(void* pAdjustedReference)
{
    il2c_assert(pAdjustedReference != NULL);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
    il2c_assert(pHeader->type != NULL);
    
    // Marking with atomicity.
    interlock_t characteristic = il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_LIVE);
    if ((characteristic & IL2C_CHARACTERISTIC_LIVE) == IL2C_CHARACTERISTIC_LIVE)
    {
        il2c_debug_write_format(
            "il2c_mark_handler_for_objref__ [1]: pAdjustedReference=0x%p, type=%s, characteristic=0x%08x",
            pAdjustedReference,
            pHeader->type->pTypeName,
            characteristic);
        // Already marked/fixed/constant
        return;
    }

    // This type has the custom mark handler.
    // Because it's variable type, can't fix pointer offsets.
    if ((pHeader->type->flags & IL2C_TYPE_VARIABLE) == IL2C_TYPE_VARIABLE)
    {
        IL2C_MARK_HANDLER pMarkHandler = (IL2C_MARK_HANDLER)(pHeader->type->markTarget);
        if (pMarkHandler != NULL)
        {
            il2c_debug_write_format(
                "il2c_mark_handler_for_objref__ [2]: pAdjustedReference=0x%p, type=%s, pMarkHandler=0x%p",
                pAdjustedReference,
                pHeader->type->pTypeName,
                pMarkHandler);

            // Invoke custom mark handler
            pMarkHandler(pAdjustedReference);
        }
    }
    // This type doesn't have the custom mark handler, traverser works just now.
    else
    {
        // NOTE: If this type is (boxed) value type,
        //   we have to shift additional offset for System_ValueType (maybe only vptr0).
        const uint8_t offset = (pHeader->type->flags & IL2C_TYPE_VALUE) ?
            sizeof(System_ValueType) :
            0;

        il2c_debug_write_format(
            "il2c_mark_handler_for_objref__ [3]: pAdjustedReference=0x%p, type=%s, offset=%u",
            pAdjustedReference,
            pHeader->type->pTypeName,
            offset);

        // Traverse recursively.
        il2c_mark_handler_recursive__(pAdjustedReference, pHeader->type, offset);
    }
}

static void il2c_mark_handler_for_value_type__(void* pValue, IL2C_RUNTIME_TYPE valueType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert((valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

    il2c_debug_write_format(
        "il2c_mark_handler_for_value_type__: pValue=0x%p, type=%s",
        pValue,
        valueType->pTypeName);

    // Traverse recursively.
    il2c_mark_handler_recursive__(pValue, valueType, 0);
}

static void il2c_mark_handler_recursive__(void* p, IL2C_RUNTIME_TYPE type, const uint8_t offset)
{
    il2c_assert(p != NULL);
    il2c_assert(type != NULL);

    // Traverse type fields recursivity.
    IL2C_MARK_TARGET* pMarkTarget = (IL2C_MARK_TARGET*)(type + 1);
    uintptr_t index;
    for (index = 0;
        index < type->markTarget;
        index++, pMarkTarget++)
    {
        void** ppField = (void**)(((uint8_t*)p) + pMarkTarget->offset + offset);

        // Is this entry value type?
        if (pMarkTarget->valueType != NULL)
        {
            il2c_assert((pMarkTarget->valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);
            il2c_assert(*ppField != NULL);

            il2c_debug_write_format(
                "il2c_mark_handler_recursive__ [1]: p=0x%p, type=%s, index=%u, *ppField=0x%p, fieldType=%s",
                p,
                type->pTypeName,
                index,
                *ppField,
                pMarkTarget->valueType->pTypeName);

            // Mark for this value.
            il2c_mark_handler_for_value_type__(ppField, pMarkTarget->valueType);
        }
        // This entry is objref.
        else
        {
            // This field isn't assigned.
            if (*ppField == NULL)
            {
                il2c_debug_write_format(
                    "il2c_mark_handler_recursive__ [2]: p=0x%p, type=%s, index=%u, *ppField=NULL",
                    p,
                    type->pTypeName,
                    index,
                    *ppField);

                continue;
            }

            void* pAdjustedReferenceInner = il2c_adjusted_reference(*ppField);
            TRY_GET_HEADER(pHeaderInner, pAdjustedReferenceInner)
            {
                il2c_debug_write_format(
                    "il2c_mark_handler_recursive__ [3]: p=0x%p, type=%s, index=%u, pAdjustedReferenceInner=0x%p, targetType=%s",
                    p,
                    type->pTypeName,
                    index,
                    pAdjustedReferenceInner,
                    pHeaderInner->type->pTypeName);

                // Use mark offset from type information.
                il2c_mark_handler_for_objref__(pAdjustedReferenceInner);
            }
            else
            {
                il2c_debug_write_format(
                    "il2c_mark_handler_recursive__ [4]: p=0x%p, type=%s, index=%u, pAdjustedReferenceInner=0x%p, targetType=%s, characteristic=0x%08x",
                    p,
                    type->pTypeName,
                    index,
                    pAdjustedReferenceInner,
                    pHeaderInner->type->pTypeName,
                    pHeaderInner->characteristic);
            }
        }
    }
}

void il2c_default_mark_handler__(void* pReference)
{
    il2c_assert(pReference != NULL);

    void* pAdjustedReference = il2c_adjusted_reference(pReference);
    TRY_GET_HEADER(pHeader, pAdjustedReference)
    {
        il2c_mark_handler_for_objref__(pAdjustedReference);
    }
}

/////////////////////////////////////////////////////////////
// GC processes

static void il2c_step1_clear_gcmark__(void)
{
    // Clear header marks.
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        // Drop live marking.
        il2c_iand(&pCurrentHeader->characteristic, ~IL2C_CHARACTERISTIC_LIVE);
        pCurrentHeader = pCurrentHeader->pNext;
    }
}

static void il2c_step2_mark_gcmark__(IL2C_EXECUTION_FRAME* pBeginFrame)
{
    // Mark headers.
    IL2C_EXECUTION_FRAME* pCurrentFrame = pBeginFrame;
    while (pCurrentFrame != NULL)
    {
        // Traverse objrefs at the current frame.
        uint16_t index;
        void** ppReference = (void**)&pCurrentFrame->pReferences__[0];
        for (index = 0; index < pCurrentFrame->objRefCount__; index++, ppReference++)
        {
            // This variable isn't assigned.
            if (*ppReference == NULL)
            {
                il2c_debug_write_format(
                    "il2c_step2_mark_gcmark__ [2]: pCurrentFrame=0x%p, index=%u, *ppReference=NULL",
                    pCurrentFrame,
                    index);
                continue;
            }

            void* pAdjustedReference = il2c_adjusted_reference(*ppReference);
            TRY_GET_HEADER(pHeader, pAdjustedReference)
            {
                il2c_debug_write_format(
                    "il2c_step2_mark_gcmark__ [3]: pCurrentFrame=0x%p, index=%u, *ppReference=0x%p, pAdjustedReference=0x%p, type=%s",
                    pCurrentFrame,
                    index,
                    *ppReference,
                    pAdjustedReference,
                    pHeader->type->pTypeName);

                // Mark for this objref.
                il2c_mark_handler_for_objref__(pAdjustedReference);
            }
            else
            {
                il2c_debug_write_format(
                    "il2c_step2_mark_gcmark__ [4]: pCurrentFrame=0x%p, index=%u, *ppReference=0x%p, pAdjustedReference=0x%p, type=%s, characteristic=0x%08x",
                    pCurrentFrame,
                    index,
                    *ppReference,
                    pAdjustedReference,
                    pHeader->type->pTypeName,
                    pHeader->characteristic);
            }
        }

        // Traverse value types at the current frame.
        IL2C_VALUE_DESCRIPTOR* pValueDesc =
            (IL2C_VALUE_DESCRIPTOR*)&pCurrentFrame->pReferences__[pCurrentFrame->objRefCount__];
        for (index = 0; index < pCurrentFrame->valueCount__; index++, pValueDesc++)
        {
            il2c_assert(pValueDesc->ptr_value != NULL);
            il2c_assert(pValueDesc->type_value != NULL);
            il2c_assert((pValueDesc->type_value->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

            il2c_debug_write_format(
                "il2c_step2_mark_gcmark__ [5]: pCurrentFrame=0x%p, index=%u, type=%s, pValue=%p",
                pCurrentFrame,
                index,
                pValueDesc->type_value->pTypeName,
                pValueDesc->ptr_value);

            // Mark for this value.
            il2c_mark_handler_for_value_type__((void*)pValueDesc->ptr_value, pValueDesc->type_value);
        }

        // Next frame
        pCurrentFrame = pCurrentFrame->pNext__;
    }
}

static void il2c_step3_sweep_garbage__(void)
{
    // Sweep garbage if gcmark isn't marked.
    IL2C_REF_HEADER** ppUnlinkTarget = &g_pBeginHeader__;
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    IL2C_REF_HEADER* pScheduledHeader = NULL;
    while (pCurrentHeader != NULL)
    {
        IL2C_REF_HEADER* pNext = pCurrentHeader->pNext;
        if ((pCurrentHeader->characteristic & IL2C_CHARACTERISTIC_LIVE) == 0)
        {
            // Very important unlink step: because cause misread on purpose this__ instance is living.
            *ppUnlinkTarget = pNext;

            // Class type overrided the finalizer:
            if ((void*)((System_Object_VTABLE_DECL__*)(pCurrentHeader->type->vptr0))->Finalize != (void*)System_Object_Finalize)
            {
                System_Object* pObject = (System_Object*)(((uint8_t*)pCurrentHeader) + sizeof(IL2C_REF_HEADER));
                il2c_assert((void*)pObject->vptr0__ == (void*)pCurrentHeader->type->vptr0);

                il2c_debug_write_format(
                    "il2c_step3_sweep_garbage__: call finalizer: type=%s, pObject=0x%p",
                    pCurrentHeader->type->pTypeName,
                    pObject);

                // Call finalizer.
                pObject->vptr0__->Finalize(pObject);
            }

            // Insert to free list.
            pCurrentHeader->pNext = pScheduledHeader;
            pScheduledHeader = pCurrentHeader;
        }
        else
        {
            ppUnlinkTarget = (void*)&pCurrentHeader->pNext;
        }

        // Next
        pCurrentHeader = pNext;
    }

    while (pScheduledHeader != NULL)
    {
        IL2C_REF_HEADER* pNext = pScheduledHeader->pNext;

        il2c_debug_write_format(
            "il2c_step3_sweep_garbage__: free: type=%s, pObject=0x%p",
            pScheduledHeader->type->pTypeName,
            ((uint8_t*)pScheduledHeader) + sizeof(IL2C_REF_HEADER));

        // Heap discarded
        il2c_free((void*)pScheduledHeader);

        // Next
        pScheduledHeader = pNext;
    }
}

#if defined(_DEBUG)
static uint32_t g_CollectCount = 0;

// For GC debugging purpose.
// Refer g_CollectCount log value and set number to the variable on start debugging.
int64_t g_CollectCountBreak = -1;
#endif

#if defined(_DEBUG)
static void il2c_collect__(bool finalShutdown, const char* pFile, int line)
#else
static void il2c_collect__(bool finalShutdown)
#endif
{
    if (il2c_iinc(&g_ExecutingCollection__) >= 2)
    {
        il2c_idec(&g_ExecutingCollection__);
        return;
    }

#if defined(_DEBUG)
    uint32_t collectCount = g_CollectCount++;
    if (g_CollectCountBreak != -1)
    {
        assert(collectCount != (uint32_t)g_CollectCountBreak);
    }
    il2c_debug_write_format(
        "il2c_collect__: begin: %d: Header=0x%p, Frame=0x%p, SFrame=0x%p, %s(%d)",
        collectCount,
        g_pBeginHeader__,
        g_pBeginFrame__,
        g_pBeginStaticFields__,
        pFile, line);
#else
    il2c_debug_write("il2c_collect__: begin");
#endif

    il2c_check_heap();

    //////////////////////////////////////////////////
    // GC Step 1:

    il2c_step1_clear_gcmark__();
    il2c_check_heap();

    //////////////////////////////////////////////////
    // GC Step 2-1:

    if (finalShutdown)
    {
        // Will release all fixed instance if final shutdown.
        il2c_unregister_all_fixed_instance_for_final_shutdown__();
        il2c_check_heap();
    }

    //////////////////////////////////////
    // GC Step 2-2:

    il2c_step2_mark_gcmark__(g_pBeginFrame__);
    il2c_check_heap();

    //////////////////////////////////////
    // GC Step 2-3:

    if (!finalShutdown)
    {
        // The final collection step has to ignore static fields.
        il2c_step2_mark_gcmark__(g_pBeginStaticFields__);
        il2c_check_heap();
    }

    //////////////////////////////////////////////////
    // GC Step 3:

    il2c_step3_sweep_garbage__();
    il2c_check_heap();

#if defined(_DEBUG)
    il2c_debug_write_format(
        "il2c_collect__: finished: %d: %s(%d)",
        collectCount,
        pFile,
        line);
#else
    il2c_debug_write("il2c_collect__: finished");
#endif

    il2c_idec(&g_ExecutingCollection__);
}

void il2c_collect(void)
{
#if defined(_DEBUG)
    il2c_collect__(false, __FILE__, __LINE__);
#else
    il2c_collect__(false);
#endif
}

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

    void* pAdjustedReference = il2c_adjusted_reference(pReference);
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
                index < currentType->interfaceCount;
                index++, pInterface++)
            {
                il2c_assert((pInterface->type->flags & IL2C_TYPE_INTERFACE) == IL2C_TYPE_INTERFACE);

                if (pInterface->type == type)
                {
                    uintptr_t offset = *(const uintptr_t*)(pInterface->vptr0);
                    return (void*)(((uint8_t*)pAdjustedReference) + offset);
                }
            }

            currentType = currentType->baseType;
        } while (currentType != NULL);
    }
    else
    {
        do
        {
            if (currentType == type)
            {
                return pReference;
            }
            currentType = currentType->baseType;
        } while (currentType != NULL);
    }

    return NULL;
}

void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    void* p = il2c_isinst__(pReference, type);
    if (p == NULL)
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

#if defined(_DEBUG)
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
#if defined(_DEBUG)
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize, pFile, line);
#else
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);
#endif

    pBoxed->vptr0__ = valueType->vptr0;
    memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), pValue, valueType->bodySize);

    // Setup interface vptrs.
    il2c_setup_interface_vptrs(valueType, pBoxed);

    return pBoxed;
}

// Boxing with widing/narrowing combination for signed/unsigned integer value.
// NOTE: This implemenation makes safer for endian order.
#if defined(_DEBUG)
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

    uintptr_t bodySize = sizeof(System_ValueType) +
        valueType->bodySize +
        valueType->interfaceCount * sizeof(void*);  // interface vptrs
#if defined(_DEBUG)
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize, pFile, line);
#else
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);
#endif

    // vptr0 setup.
    pBoxed->vptr0__ = valueType->vptr0;

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

    // Setup interface vptrs.
    il2c_setup_interface_vptrs(valueType, pBoxed);

    return pBoxed;
}

void* il2c_unbox__(/* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE valueType)
{
    if (pReference == NULL)
    {
        if (valueType->flags & IL2C_TYPE_VALUE)
        {
            il2c_throw_nullreferenceexception__();
        }
        return NULL;
    }

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pReference) - sizeof(IL2C_REF_HEADER));
    if (pHeader->type != valueType)
    {
        il2c_throw_invalidcastexception__();
    }

    return il2c_unsafe_unbox__(pReference, void);
}

/////////////////////////////////////////////////
// Exception special functions

void il2c_link_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget, IL2C_EXCEPTION_FILTER filter)
{
    il2c_assert(pUnwindTarget != NULL);
    il2c_assert(filter != NULL);

    pUnwindTarget->pFrame = g_pBeginFrame__;
    pUnwindTarget->ex = NULL;   // Current caught exception
    pUnwindTarget->filter = filter;
    pUnwindTarget->pNext = il2c_ixchgptr(&g_pTopUnwindTarget__, pUnwindTarget);
}

void il2c_unlink_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget)
{
    il2c_assert(pUnwindTarget != NULL);

    IL2C_EXCEPTION_FRAME* p = il2c_ixchgptr(&g_pTopUnwindTarget__, pUnwindTarget->pNext);
    il2c_assert(p == pUnwindTarget);
    (void)p;
}

static void il2c_do_throw__(
    System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame, int16_t filterNumber)
{
    il2c_assert(ex != NULL);
    il2c_assert(pTargetFrame != NULL);

    // Update current exception frame.
    pTargetFrame->ex = ex;
    g_pTopUnwindTarget__ = pTargetFrame;

    // Update execution frame.
    g_pBeginFrame__ = pTargetFrame->pFrame;

    // Transision to target handler.
    il2c_longjmp((void*)pTargetFrame->saved, filterNumber);
}

static void il2c_throw_internal__(System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame)
{
    il2c_assert(ex != NULL);

    IL2C_EXCEPTION_FRAME* pFrame = pTargetFrame;
    IL2C_EXCEPTION_FRAME* pFinallyFrame = NULL;

    while (pFrame != NULL)
    {
        il2c_assert(pFrame->filter != NULL);
        il2c_assert(pFrame->pFrame != NULL);

        int16_t filterNumber = pFrame->filter(ex);

        // Found finally block
        if (filterNumber == IL2C_FILTER_FINALLY)
        {
            // Memoize finally frame
            if (pFinallyFrame == NULL)
            {
                pFinallyFrame = pFrame;
            }
        }
        else if (filterNumber != IL2C_FILTER_NOMATCH)
        {
            // Already found finally block
            if (pFinallyFrame != NULL)
            {
                // Send to finally
                il2c_do_throw__(ex, pFinallyFrame, IL2C_FILTER_FINALLY);
            }
            else
            {
                // NOTE: This place is the first-chance.
                // Send to catch
                il2c_do_throw__(ex, pFrame, filterNumber);
            }
        }

        // Not matched: next frame.
        pFrame = pFrame->pNext;
    }

    // Already found finally block
    if (pFinallyFrame != NULL)
    {
        // Send to finally
        il2c_do_throw__(ex, pFinallyFrame, IL2C_FILTER_FINALLY);
    }

    // TODO: Unhandled exception
    IL2C_REF_HEADER* pHeader = il2c_get_header__(ex);
    il2c_debug_write_format(
        "Throw unhandled exception: type=%s, Message=\"%ls\"",
        pHeader->type->pTypeName,
        (ex->message__->string_body__ != NULL) ? ex->message__->string_body__ : L"");

    il2c_assert(0);
}

void il2c_throw__(System_Exception* ex)
{
    il2c_assert(ex != NULL);

    // If this state is inside for caught block, skip current frame.
    // (Throwing new exception instance)
    IL2C_EXCEPTION_FRAME* pFrame =
        (g_pTopUnwindTarget__ != NULL) ?
            ((g_pTopUnwindTarget__->ex != NULL) ? g_pTopUnwindTarget__->pNext : g_pTopUnwindTarget__) :
        NULL;

    il2c_throw_internal__(ex, pFrame);
}

void il2c_rethrow(void)
{
    il2c_assert(g_pTopUnwindTarget__ != NULL);

    // If this state is inside for caught block
    if (g_pTopUnwindTarget__->ex != NULL)
    {
        // Unwind one frame.
        System_Exception* ex = g_pTopUnwindTarget__->ex;
        il2c_ixchgptr(&g_pTopUnwindTarget__, g_pTopUnwindTarget__->pNext);

        // Throw with this exception
        il2c_throw_internal__(ex, g_pTopUnwindTarget__);
    }

    // Search nearest caught exception
    IL2C_EXCEPTION_FRAME* pFrame = g_pTopUnwindTarget__->pNext;
    while (pFrame != NULL)
    {
        // Found.
        System_Exception* ex = pFrame->ex;
        if (ex != NULL)
        {
            // Throw with this exception (at the current frame)
            il2c_throw_internal__(ex, g_pTopUnwindTarget__);
        }
        pFrame = pFrame->pNext;
    }

    // InvalidProgramException
    il2c_assert(0);
}

#ifdef IL2C_USE_SIGNAL
static void il2c_SIGSEGV_handler(int sig)
{
    // NOTE 1:
    //   Run in windows, this handler called from SEH filter context from "_seh_filter_exe()".
    //   The SEH __try - __except() block contains at "__scrt_common_main_seh(),"
    //   the callgraph is:
    //     __scrt_common_main_seh() --> __try --> main() --> [SEGV] --> __except() --> _seh_filter_exe() --> handler()
    //   But the "__except(...)" expression has correct only EBP register except ESP register (!!)
    //   Therefore the "_seh_filter_exe()" called before NO any unroll stacks,
    //   the "handler()" function at deeper stack than "main(),"
    //   We can use the longjmp() and unwinding without any stack corruption.
    //   https://gist.github.com/kekyo/cc9bace942b8c2aa2484431e047d267d

    // NOTE 2:
    //   This handler allocate the NullReferenceException and finally unwind using the longjmp(),
    //   it's dangerous for some situations.
    //   For example, we'll call the "malloc()" function and if it causes SEGV (invalid pointer access) at inside malloc
    //   by the unknown issue, context is maybe unstable condition and will jump to this handler and
    //   the handler call malloc() function recursivity.
    //   It situation, all function will break and unstable our code.
    //   The IL2C currently NOT recovery it state, we'll approach for this problem:
    //     * We have to do not cause any SEGV issue at our using C runtime functions.
    //     * Unhook the handler before enter P/Invoke or external functions and
    //       rehook the handler after leave P/Invoke or external functions.
    //   These external functions may cause unknown problem and cause SEGV, we can't recover it state.
    //   https://wiki.sei.cmu.edu/confluence/display/c/SIG30-C.+Call+only+asynchronous-safe+functions+within+signal+handlers

    // Re-register
    signal(SIGSEGV, il2c_SIGSEGV_handler);

    il2c_throw_nullreferenceexception__();
}

typedef void (*il2c_sighandler)(int sig);

static il2c_sighandler g_SIGSEGV_saved = SIG_DFL;
#endif

/////////////////////////////////////////////////////////////
// IL2C runtime initialzer / shutdown

void il2c_initialize__(void)
{
    g_InitializerCount++;

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
    g_pBeginStaticFields__ = NULL;
    g_pFixedInstances__ = NULL;
    g_pTopUnwindTarget__ = NULL;

#if defined(_DEBUG)
    g_CollectCount = 0;
    g_CollectCountBreak = -1;
#endif

#ifdef IL2C_USE_SIGNAL
    g_SIGSEGV_saved = signal(SIGSEGV, il2c_SIGSEGV_handler);
#endif
}

void il2c_shutdown__(void)
{
    il2c_assert(g_pTopUnwindTarget__ == NULL);

#if defined(_DEBUG)
    il2c_collect__(true, __FILE__, __LINE__);
#else
    il2c_collect__(true);
#endif

#ifdef IL2C_USE_SIGNAL
    signal(SIGSEGV, g_SIGSEGV_saved);
#endif
}

///////////////////////////////////////////////////////
// Another special runtime helper functions

#if !defined(UEFI)
double il2c_fmod(double lhs, double rhs)
{
    return fmod(lhs, rhs);
}
#endif

#if defined(_DEBUG)
void il2c_break__(const char* pFile, int line)
#else
void il2c_break__(void)
#endif
{
    debug_break();
}

IL2C_CONST_STRING(il2c_null_reference_message, L"Object reference not set to an instance of an object.");

void il2c_throw_nullreferenceexception__(void)
{
    // TODO: can turn to static allocate for NullReferenceException?
    System_NullReferenceException* ex = il2c_get_uninitialized_object(System_NullReferenceException);
    System_NullReferenceException__ctor_1(ex, il2c_null_reference_message);
    il2c_throw(ex);
}

// NOTE: Hmm, the unbox failed message different to the castclass opcode...
//   IL2C choices short sentence by unbox operator message because better footprint.
//   .NET 4 castclass message format: "Unable to cast object of type 'Foo.Bar' to type 'System.String'."
IL2C_CONST_STRING(il2c_invalid_cast_message, L"Specified cast is not valid.");

void il2c_throw_invalidcastexception__(void)
{
    System_InvalidCastException* ex = il2c_get_uninitialized_object(System_InvalidCastException);
    System_InvalidCastException__ctor_1(ex, il2c_invalid_cast_message);
    il2c_throw(ex);
}
