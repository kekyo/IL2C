#include "il2c_private.h"

#include "debugbreak.h"

/////////////////////////////////////////////////////////////

// TODO: Support finalizer
#define GCMARK_NOMARK ((interlock_t)1)
#define GCMARK_LIVE ((interlock_t)0)
#define GCMARK_CONST ((interlock_t)2)

typedef volatile struct IL2C_EXECUTION_FRAME
{
    uint8_t objRefCount__;
    uint8_t objRefRefCount__;
    IL2C_EXECUTION_FRAME* pNext__;
    void* pReferences__[1];
    // void** ppReferences__[];
} IL2C_EXECUTION_FRAME;

// TODO: Become store to thread local storage
static IL2C_EXECUTION_FRAME* g_pBeginFrame__ = NULL;
static IL2C_EXCEPTION_FRAME* g_pTopUnwindTarget__ = NULL;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;

//////////////////////////

void* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE_DECL* type, uintptr_t bodySize)
{
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
            il2c_collect();

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
    if (bodySize >= 1)
    {
        // Guarantee cleared body
        il2c_memset(pReference, 0, bodySize);
    }

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

        il2c_iyield();
    }

    return pReference;
}

void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE_DECL* type, void* vptr0)
{
    il2c_assert(type != NULL);
    il2c_assert(vptr0 != NULL);

    // String, Delegate or Array (IL2C_TYPE_VARIABLE):
    // throw new InvalidProgramException();
    il2c_assert((type->flags & IL2C_TYPE_VARIABLE) == 0);
    il2c_assert(type->bodySize >= sizeof(void*));   // vptr0

    void** ppReference = il2c_get_uninitialized_object_internal__(type, type->bodySize);
    *ppReference = vptr0;
    return ppReference;
}

void il2c_mark_from_handler__(/* System_Object* */ void* pReference)
{
    il2c_assert(pReference != NULL);

    // Has to ignore if objref is const.
    // HACK: It's shame the icmpxchg may cause system fault if header is placed at read-only memory.
    //   (at x86/x64 cause, another platform may cause)
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pReference);
    if (pHeader->gcMark == GCMARK_CONST)
    {
        return;
    }

    interlock_t currentMark = il2c_icmpxchg(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
    if (currentMark == GCMARK_NOMARK)
    {
        il2c_assert(pHeader->type != NULL);
        il2c_assert(pHeader->type->IL2C_MarkHandler != NULL);
        pHeader->type->IL2C_MarkHandler(pReference);
    }
}

void il2c_no_mark_handler__(/* System_Object* */ void* pReference)
{
    il2c_assert(pReference != NULL);

    // Nothing to do.
    // We can use this function only when the runtime type has no member fields
    // (it contains maybe objref.)
}

//////////////////////////

void il2c_link_execution_frame(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    il2c_assert(pNewFrame != NULL);

    ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ = g_pBeginFrame__;
    g_pBeginFrame__ = (IL2C_EXECUTION_FRAME*)pNewFrame;
}

void il2c_unlink_execution_frame(/* EXECUTION_FRAME__* */ void* pFrame)
{
    il2c_assert(pFrame != NULL);

    // TODO: always collect
    il2c_collect();

    g_pBeginFrame__ = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext__;
}

//////////////////////////

void il2c_step1_clear_gcmark__()
{
    // Clear header marks.
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        // (Exclude GCMARK_CONST)
        if (pCurrentHeader->gcMark == GCMARK_LIVE)
        {
            pCurrentHeader->gcMark = GCMARK_NOMARK;
        }
        pCurrentHeader = pCurrentHeader->pNext;
    }
}

void il2c_step2_mark_gcmark__()
{
    // Mark headers.
    IL2C_EXECUTION_FRAME* pCurrentFrame = g_pBeginFrame__;
    while (pCurrentFrame != NULL)
    {
        // Traverse current frame.
        uint8_t index;
        for (index = 0; index < pCurrentFrame->objRefCount__; index++)
        {
            void* pReference = pCurrentFrame->pReferences__[index];
            if (pReference == NULL)
            {
                continue;
            }

            // Has to ignore if objref is const.
            // HACK: It's shame the icmpxchg may cause system fault if header is placed at read-only memory.
            //   (at x86/x64 cause, another platform may cause)
            IL2C_REF_HEADER* pHeader = il2c_get_header__(pReference);
            if (pHeader->gcMark == GCMARK_CONST)
            {
                continue;
            }

            // Marking process.
            interlock_t currentMark = il2c_icmpxchg(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
            if (currentMark == GCMARK_NOMARK)
            {
                il2c_assert(pHeader->type != NULL);
                il2c_assert(pHeader->type->IL2C_MarkHandler != NULL);

                DEBUG_WRITE("il2c_step2_mark_gcmark__", pHeader->type->pTypeName);

                pHeader->type->IL2C_MarkHandler(pReference);
            }
        }

        pCurrentFrame = pCurrentFrame->pNext__;
    }
}

void il2c_step3_sweep_garbage__()
{
    // Sweep garbage if gcmark isn't marked.
    IL2C_REF_HEADER** ppUnlinkTarget = &g_pBeginHeader__;
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        IL2C_REF_HEADER* pNext = pCurrentHeader->pNext;
        if (pCurrentHeader->gcMark == GCMARK_NOMARK)
        {
            // Very important link steps: because cause misread on purpose this__ instance is living.
            *ppUnlinkTarget = pNext;

            DEBUG_WRITE("il2c_step3_sweep_garbage__", pCurrentHeader->type->pTypeName);

            // Heap discarded
            il2c_free((void*)pCurrentHeader);

            pCurrentHeader = pNext;
        }
        else
        {
            ppUnlinkTarget = (void*)&pCurrentHeader->pNext;
            pCurrentHeader = pNext;
        }
    }
}

//////////////////////////

void il2c_collect()
{
    il2c_check_heap();
    il2c_step1_clear_gcmark__();
    il2c_check_heap();
    il2c_step2_mark_gcmark__();
    il2c_check_heap();
    il2c_step3_sweep_garbage__();
    il2c_check_heap();
}

void il2c_initialize()
{
    il2c_initialize_heap();

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
    g_pTopUnwindTarget__ = NULL;
}

void il2c_shutdown()
{
    il2c_assert(g_pTopUnwindTarget__ == NULL);

    il2c_collect();

    il2c_shutdown_heap();
}

/////////////////////////////////////////////////////////////
// Runtime cast function

void* il2c_isinst__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(pReference);
    IL2C_RUNTIME_TYPE_DECL* currentType = pHeader->type;
    do
    {
        if (currentType == type)
        {
            return pReference;
        }
        currentType = currentType->baseType;
    }
    while (currentType != NULL);

    return NULL;
}

// MEMO: Hmm, the unbox failed message different to the castclass opcode...
//   IL2C choices short sentence by unbox operator message because better footprint.
//   .NET 4 castclass message format: "Unable to cast object of type 'Foo.Bar' to type 'System.String'."
IL2C_CONST_STRING(il2c_cast_failed, L"Specified cast is not valid.");

static void il2c_throw_invalidcastexception__()
{
    System_InvalidCastException* ex = il2c_get_uninitialized_object(System_InvalidCastException);
    System_InvalidCastException__ctor_1(ex, il2c_cast_failed);
    il2c_throw(ex);
}

void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    void* p = il2c_isinst__(pReference, type);
    if (p != NULL)
    {
        return p;
    }

    il2c_throw_invalidcastexception__();
}

/////////////////////////////////////////////////////////////
// Boxing related functions

// +----------------------+
// | IL2C_REF_HEADER      |
// +----------------------+ <-- pBoxed        ---------------------------
// | vptr0__              | <-- pVTable0        | System_ValueType    ^
// +----------------------+                   -----------             |
// |        :             |                     ^                     | bodySize
// | (value data)         | Copy from pValue    | type->bodySize      |
// |        :             |                     v                     v
// +----------------------+                   ---------------------------

System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType, const void* vptr0)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert(vptr0 != NULL);

    uintptr_t bodySize = sizeof(System_ValueType) + valueType->bodySize;
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);

    pBoxed->vptr0__ = vptr0;
    il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), pValue, valueType->bodySize);

    return pBoxed;
}

// Boxing with widing/narrowing combination for signed/unsigned integer value.
// MEMO: This implemenation makes safer for endian order.
System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType, IL2C_RUNTIME_TYPE_DECL* stackType, const void* vptr0)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert(stackType != NULL);
    il2c_assert(vptr0 != NULL);

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
            // TODO: InvalidProgramException?
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
            // TODO: InvalidProgramException?
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
            // TODO: InvalidProgramException?
            il2c_throw_invalidcastexception__();
        }
        break;
    default:
        // TODO: InvalidProgramException?
        il2c_throw_invalidcastexception__();
    }

    uintptr_t bodySize = sizeof(System_ValueType) + valueType->bodySize;
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);

    // vptr0 setup.
    pBoxed->vptr0__ = vptr0;

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

    return pBoxed;
}

void* il2c_unbox__(/* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE_DECL* valueType)
{
    if (pReference == NULL)
    {
        if (valueType->flags & IL2C_TYPE_VALUE)
        {
            // throw NullReferenceException();
            il2c_assert(0);
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
}

static void il2c_throw_internal__(
    System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame, int16_t value)
{
    // Update current exception frame.
    pTargetFrame->ex = ex;
    g_pTopUnwindTarget__ = pTargetFrame;

    // Update execution frame.
    g_pBeginFrame__ = pTargetFrame->pFrame;

    // Transision to target handler.
    longjmp((void*)pTargetFrame->saved, value);
}

void il2c_throw__(System_Exception* ex)
{
    il2c_assert(ex != NULL);

    // If this state is inside for caught block, skip current frame.
    // (Throwing new exception instance)
    IL2C_EXCEPTION_FRAME* pCurrentFrame =
        (g_pTopUnwindTarget__->ex != NULL) ? g_pTopUnwindTarget__->pNext : g_pTopUnwindTarget__;
    IL2C_EXCEPTION_FRAME* pFinallyFrame = NULL;

    while (pCurrentFrame != NULL)
    {
        il2c_assert(pCurrentFrame->filter != NULL);
        il2c_assert(pCurrentFrame->pFrame != NULL);

        int16_t result = pCurrentFrame->filter(ex);

        // Found finally block
        if (result == IL2C_FILTER_FINALLY)
        {
            // Memoize finally frame
            if (pFinallyFrame == NULL)
            {
                pFinallyFrame = pCurrentFrame;
            }
        }
        else if (result != IL2C_FILTER_NOMATCH)
        {
            // Already found finally block
            if (pFinallyFrame != NULL)
            {
                // Send to finally
                il2c_throw_internal__(ex, pFinallyFrame, IL2C_FILTER_FINALLY);
            }
            else
            {
                // MEMO: This place is the first-chance.
                // Send to catch
                il2c_throw_internal__(ex, pCurrentFrame, result);
            }
        }

        // Not matched: next frame.
        pCurrentFrame = pCurrentFrame->pNext;
    }

    // Already found finally block
    if (pFinallyFrame != NULL)
    {
        // Send to finally
        il2c_throw_internal__(ex, pFinallyFrame, IL2C_FILTER_FINALLY);
    }

    // TODO: Unhandled exception
    il2c_assert(0);
}

void il2c_rethrow()
{
    il2c_assert(g_pTopUnwindTarget__ != NULL);
    il2c_assert(g_pTopUnwindTarget__->ex != NULL);
    il2c_assert(g_pTopUnwindTarget__->pNext != NULL);   // Will cause unhandled exception

    // Unwind one frame.
    System_Exception* ex = g_pTopUnwindTarget__->ex;
    il2c_ixchgptr(&g_pTopUnwindTarget__, g_pTopUnwindTarget__->pNext);

    il2c_throw__(ex);
}

///////////////////////////////////////////////////////
// Another special runtime helper functions

double il2c_fmod(double lhs, double rhs)
{
    return fmod(lhs, rhs);
}

void il2c_break()
{
    debug_break();
}
