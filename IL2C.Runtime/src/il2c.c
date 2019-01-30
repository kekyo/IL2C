#include "il2c_private.h"

#include "debugbreak.h"

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
    void* pReferences__[1];     // objRefCount__
    // IL2C_VALUE_DESCRIPTOR valueDescriptors__[];  // valueCount__
} IL2C_EXECUTION_FRAME;

// TODO: Become store to thread local storage
static IL2C_EXECUTION_FRAME* g_pBeginFrame__ = NULL;
static IL2C_EXCEPTION_FRAME* g_pTopUnwindTarget__ = NULL;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;
static volatile bool g_ExecutingCollection__ = false;

static void il2c_collect__(interlock_t comparand);

/////////////////////////////////////////////////////////////
// Instance allocator functions

void* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE type, uintptr_t bodySize)
{
    // TODO: always collect
    il2c_collect__(GCMARK_LIVE);

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
            il2c_collect__(GCMARK_LIVE);

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
    il2c_memset(pReference, 0, bodySize);

    pHeader->pNext = NULL;
    pHeader->type = type;
    pHeader->gcMark = GCMARK_NOMARK;

    // Safe link both headers.
    while (1)
    {
        // (1)
        IL2C_REF_HEADER* pNext = g_pBeginHeader__;
        // (2)
        pHeader->pNext = pNext;
        // (3)
        if ((IL2C_REF_HEADER*)il2c_icmpxchgptr(
            &g_pBeginHeader__,
            pHeader,
            pNext) == pNext)
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

void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);
    il2c_assert(type->vptr0 != NULL);

    // String, Delegate or Array (IL2C_TYPE_VARIABLE):
    // throw new InvalidProgramException();
    il2c_assert((type->flags & IL2C_TYPE_VARIABLE) == 0);
    il2c_assert(type->bodySize >= sizeof(void*));   // vptr0

    // Setup vptr0
    uint8_t* pReference = il2c_get_uninitialized_object_internal__(type, type->bodySize);
    *((const void**)pReference) = type->vptr0;

    // Setup interface vptrs.
    il2c_setup_interface_vptrs(type, pReference);

    return pReference;
}

/////////////////////////////////////////////////////////////
// Execution frame linker functions

void il2c_link_execution_frame(/* EXECUTION_FRAME__* */ volatile void* pNewFrame)
{
    il2c_assert(pNewFrame != NULL);
    il2c_assert(((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ == NULL);

    ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ = g_pBeginFrame__;
    g_pBeginFrame__ = (IL2C_EXECUTION_FRAME*)pNewFrame;
}

void il2c_unlink_execution_frame(/* EXECUTION_FRAME__* */ volatile void* pFrame)
{
    il2c_assert(pFrame != NULL);

    // TODO: always collect
    il2c_collect__(GCMARK_LIVE);

    g_pBeginFrame__ = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext__;
}

/////////////////////////////////////////////////////////////
// GC Mark handler

typedef void(*IL2C_MARK_HANDLER)(void* pReference);

// Has to ignore if objref is const.
// HACK: It's shame the icmpxchg may cause system fault if header is placed at read-only memory.
//   (at x86/x64 cause, another platform may cause)
#define TRY_GET_HEADER(pHeader, pReference) \
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pReference); \
    if (pHeader->gcMark == GCMARK_NOMARK)

static void il2c_mark_handler_recursive__(void* p, IL2C_RUNTIME_TYPE type, const uint8_t offset);

static void il2c_mark_handler_for_objref__(void* pAdjustedReference)
{
    il2c_assert(pAdjustedReference != NULL);

    // Marking with atomic exchange.
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
    interlock_t currentMark = il2c_icmpxchg(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
    if (currentMark != GCMARK_NOMARK)
    {
        // Already marked.
        return;
    }

    il2c_assert(pHeader->type != NULL);
    DEBUG_WRITE("il2c_mark_handler_for_objref__", pHeader->type->pTypeName);

    // This type has the custom mark handler.
    // Because it's variable type, can't fix pointer offsets.
    if ((pHeader->type->flags & IL2C_TYPE_VARIABLE) == IL2C_TYPE_VARIABLE)
    {
        IL2C_MARK_HANDLER pMarkHandler = (IL2C_MARK_HANDLER)(pHeader->type->markTarget);
        if (pMarkHandler != NULL)
        {
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

        // Traverse recursivity.
        il2c_mark_handler_recursive__(pAdjustedReference, pHeader->type, offset);
    }
}

static void il2c_mark_handler_for_value_type__(void* pValue, IL2C_RUNTIME_TYPE valueType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert((valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

    DEBUG_WRITE("il2c_mark_handler_for_value_type__", valueType->pTypeName);

    // Traverse recursivity.
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

            // Mark for this value.
            il2c_mark_handler_for_value_type__(ppField, pMarkTarget->valueType);
        }
        // This entry is objref.
        else
        {
            // This field isn't assigned.
            if (*ppField == NULL)
            {
                continue;
            }

            void* pAdjustedReferenceInner = il2c_adjusted_reference(*ppField);
            TRY_GET_HEADER(pHeaderInner, pAdjustedReferenceInner)
            {
                // Use mark offset from type information.
                il2c_mark_handler_for_objref__(pAdjustedReferenceInner);
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
// GC process

static void il2c_step1_clear_gcmark__(interlock_t comparand)
{
    // Clear header marks.
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        // (Exclude GCMARK_CONST)
        if (pCurrentHeader->gcMark <= comparand)
        {
            pCurrentHeader->gcMark = GCMARK_NOMARK;
        }
        pCurrentHeader = pCurrentHeader->pNext;
    }
}

static void il2c_step2_mark_gcmark__(void)
{
    // Mark headers.
    IL2C_EXECUTION_FRAME* pCurrentFrame = g_pBeginFrame__;
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
                continue;
            }

            void* pAdjustedReference = il2c_adjusted_reference(*ppReference);
            TRY_GET_HEADER(pHeader, pAdjustedReference)
            {
                // Mark for this objref.
                il2c_mark_handler_for_objref__(pAdjustedReference);
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
        if (pCurrentHeader->gcMark == GCMARK_NOMARK)
        {
            // Very important link steps: because cause misread on purpose this__ instance is living.
            *ppUnlinkTarget = pNext;

            // Class type overrided the finalizer:
            if ((void*)((System_Object_VTABLE_DECL__*)(pCurrentHeader->type->vptr0))->Finalize != (void*)System_Object_Finalize)
            {
                System_Object* pObject = (System_Object*)(((uint8_t*)pCurrentHeader) + sizeof(IL2C_REF_HEADER));
                il2c_assert((void*)pObject->vptr0__ == (void*)pCurrentHeader->type->vptr0);

                DEBUG_WRITE("il2c_step3_sweep_garbage__: Call finalizer", pCurrentHeader->type->pTypeName);

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

        DEBUG_WRITE("il2c_step3_sweep_garbage__: Free", pCurrentHeader->type->pTypeName);

        // Heap discarded
        il2c_free((void*)pScheduledHeader);

        // Next
        pScheduledHeader = pNext;
    }
}

static void il2c_collect__(interlock_t comparand)
{
    if (g_ExecutingCollection__)
    {
        return;
    }

    g_ExecutingCollection__ = true;

    il2c_check_heap();
    il2c_step1_clear_gcmark__(comparand);
    il2c_check_heap();
    il2c_step2_mark_gcmark__();
    il2c_check_heap();
    il2c_step3_sweep_garbage__();
    il2c_check_heap();

    g_ExecutingCollection__ = false;
}

void il2c_collect(void)
{
    il2c_collect__(GCMARK_LIVE);
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

System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);

    uintptr_t bodySize = sizeof(System_ValueType) +
        valueType->bodySize +
        valueType->interfaceCount * sizeof(void*);  // interface vptrs
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);

    pBoxed->vptr0__ = valueType->vptr0;
    il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), pValue, valueType->bodySize);

    // Setup interface vptrs.
    il2c_setup_interface_vptrs(valueType, pBoxed);

    return pBoxed;
}

// Boxing with widing/narrowing combination for signed/unsigned integer value.
// NOTE: This implemenation makes safer for endian order.
System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert(stackType != NULL);

    // Require type conversion  (OK: IL2C_TYPE_INTEGER || IL2C_TYPE_UNSIGNED_INTEGER)
    il2c_assert(((valueType->flags & IL2C_TYPE_INTEGER) == IL2C_TYPE_INTEGER) && ((stackType->flags & IL2C_TYPE_INTEGER) == IL2C_TYPE_INTEGER));
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
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);

    // vptr0 setup.
    pBoxed->vptr0__ = valueType->vptr0;

    switch (valueType->bodySize)
    {
    case 1:
        il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i1, 1);
        break;
    case 2:
        il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i2, 2);
        break;
    case 4:
        il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i4, 4);
        break;
    case 8:
        il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i8, 8);
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
    il2c_assert(g_pTopUnwindTarget__->pNext != NULL);   // Will cause unhandled exception

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

void il2c_initialize(void)
{
    il2c_initialize_heap();

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
    g_pTopUnwindTarget__ = NULL;

#ifdef IL2C_USE_SIGNAL
    g_SIGSEGV_saved = signal(SIGSEGV, il2c_SIGSEGV_handler);
#endif
}

void il2c_shutdown(void)
{
    il2c_assert(g_pTopUnwindTarget__ == NULL);

    // The final collection step has to release fixed (pinned) instances.
    il2c_collect__(GCMARK_FIXED);

#ifdef IL2C_USE_SIGNAL
    signal(SIGSEGV, g_SIGSEGV_saved);
#endif

    il2c_shutdown_heap();
}

///////////////////////////////////////////////////////
// Another special runtime helper functions

double il2c_fmod(double lhs, double rhs)
{
    return fmod(lhs, rhs);
}

void il2c_break(void)
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
