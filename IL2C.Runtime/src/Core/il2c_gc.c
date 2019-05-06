#include <il2c_private.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////

extern IL2C_TLS_INDEX g_TlsIndex__;

extern IL2C_REF_HEADER* g_pBeginHeader__;
extern IL2C_ROOT_REFERENCES* g_pRootReferences__;
extern IL2C_ROOT_REFERENCES* g_pFixedReferences__;
extern IL2C_STATIC_FIELDS* g_pBeginStaticFields__;

// Stop the world global lock.
IL2C_MONITOR_LOCK g_GlobalLockForCollect__;

interlock_t g_CollectionMarkIndex__ = 0; //  IL2C_CHARACTERISTIC_MARK_INDEX;
static interlock_t g_ExecutingCollection__ = 0;
volatile uint32_t g_PendingRemains__ = 0;

#if defined(_DEBUG)
static uint32_t g_CollectCount = 0;

// For GC debugging purpose.
// Refer g_CollectCount log value and set number to the variable on start debugging.
int64_t g_CollectCountBreak = -1;
#endif

typedef struct IL2C_MONITOR_LOCK_BLOCK_INFORMATION_DECL IL2C_MONITOR_LOCK_BLOCK_INFORMATION;
extern void il2c_release_monitor_lock_from_objref__(IL2C_REF_HEADER* pHeader);
extern void il2c_release_all_monitor_lock_for_final_shutdown__(void);
extern void il2c_unregister_all_root_references_for_final_shutdown__(IL2C_ROOT_REFERENCES** ppRootReferences);

/////////////////////////////////////////////////////////////
// Internal GC mark handlers

// Has to ignore if objref is const.  (NOT const and initialized and NOT marked)
// HACK: It's shame the icmpxchg may cause system fault if header is placed at read-only memory (CONST).
//   (at x86/x64 cause, another platform may cause)
// TODO: Reduce flags calculation.
#define TRY_GET_HEADER(pHeader, pAdjustedReference) \
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference); \
    if (il2c_unlikely__(((pHeader->characteristic & \
        (IL2C_CHARACTERISTIC_CONST | IL2C_CHARACTERISTIC_MARK_INDEX)) ^ IL2C_CHARACTERISTIC_MARK_INDEX) == \
        g_CollectionMarkIndex__))

static void il2c_mark_handler_recursive__(void* pTarget, IL2C_RUNTIME_TYPE type, const uint8_t offset);

static void il2c_mark_handler_for_objref__(System_Object* pAdjustedReference)
{
    typedef void (*IL2C_MARK_HANDLER)(void* pReference);

    il2c_assert(pAdjustedReference != NULL);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
    il2c_assert(pHeader->type != NULL);
    
    // Marking with atomicity.
    const interlock_t lastCharacteristic = il2c_ixor(&pHeader->characteristic, IL2C_CHARACTERISTIC_MARK_INDEX);
    if (il2c_likely__((lastCharacteristic & IL2C_CHARACTERISTIC_MARK_INDEX) == g_CollectionMarkIndex__))
    {
        il2c_runtime_debug_log_format(
            L"il2c_mark_handler_for_objref__ [1]: pAdjustedReference=0x{0:p}, type={1:s}, lastCharacteristic=0x{2:x}",
            pAdjustedReference,
            pHeader->type->pTypeName,
            lastCharacteristic);
        // Already marked/fixed/constant
        return;
    }

    // This type has the custom mark handler.
    // Because it's variable type, can't fix pointer offsets.
    if (il2c_unlikely__((pHeader->type->flags & IL2C_TYPE_WITH_MARK_HANDLER) == IL2C_TYPE_WITH_MARK_HANDLER))
    {
        IL2C_MARK_HANDLER pMarkHandler = (IL2C_MARK_HANDLER)(pHeader->type->markTarget);
        il2c_assert(pMarkHandler != NULL);

        il2c_runtime_debug_log_format(
            L"il2c_mark_handler_for_objref__ [2]: pAdjustedReference=0x{0:p}, type={1:s}, pMarkHandler=0x{2:p}",
            pAdjustedReference,
            pHeader->type->pTypeName,
            pMarkHandler);

        // Invoke custom mark handler
        pMarkHandler(pAdjustedReference);
    }
    // This type doesn't have the custom mark handler, traverser works just now.
    else
    {
        // NOTE: If this type is (boxed) value type,
        //   we have to shift additional offset for System_ValueType (maybe only vptr0).
        const uint8_t offset = (pHeader->type->flags & IL2C_TYPE_VALUE) ?
            sizeof(System_ValueType) :
            0;

        il2c_runtime_debug_log_format(
            L"il2c_mark_handler_for_objref__ [3]: pAdjustedReference=0x{0:p}, type={1:s}, offset={2:u}",
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

    il2c_runtime_debug_log_format(
        L"il2c_mark_handler_for_value_type__: pValue=0x{0:p}, type={1:s}",
        pValue,
        valueType->pTypeName);

    // Traverse recursively.
    il2c_mark_handler_recursive__(pValue, valueType, 0);
}

static void il2c_mark_handler_recursive__(void* pTarget, IL2C_RUNTIME_TYPE type, const uint8_t offset)
{
    il2c_assert(pTarget != NULL);
    il2c_assert(type != NULL);

    // Traverse type fields recursivity.
    IL2C_MARK_TARGET* pMarkTarget = (IL2C_MARK_TARGET*)(type + 1);
    uintptr_t index;
    for (index = 0;
        il2c_likely__(index < type->markTarget);
        index++, pMarkTarget++)
    {
        void* pTargetField = (void*)(((uint8_t*)pTarget) + pMarkTarget->offset + offset);

        // Is this entry value type?
        if (il2c_unlikely__(pMarkTarget->valueType != NULL))
        {
            il2c_assert((pMarkTarget->valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);
            il2c_assert(pTargetField != NULL);

            il2c_runtime_debug_log_format(
                L"il2c_mark_handler_recursive__ [1]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pTargetField=0x{3:p}, fieldType={4:s}",
                pTarget,
                type->pTypeName,
                index,
                pTargetField,
                pMarkTarget->valueType->pTypeName);

            // Mark for this value.
            il2c_mark_handler_for_value_type__(pTargetField, pMarkTarget->valueType);
        }
        // This entry is objref.
        else
        {
            // This field isn't assigned.
            void* pReference = *(void**)pTargetField;
            if (il2c_unlikely__(pReference == NULL))
            {
                il2c_runtime_debug_log_format(
                    L"il2c_mark_handler_recursive__ [2]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pReference=NULL",
                    pTarget,
                    type->pTypeName,
                    index,
                    pReference);

                continue;
            }

            System_Object* pAdjustedReferenceInner = il2c_adjusted_reference(pReference);
            TRY_GET_HEADER(pHeaderInner, pAdjustedReferenceInner)
            {
                il2c_runtime_debug_log_format(
                    L"il2c_mark_handler_recursive__ [3]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pAdjustedReferenceInner=0x{3:x}, targetType={4:s}, characteristic=0x{5:x}",
                    pTarget,
                    type->pTypeName,
                    index,
                    pAdjustedReferenceInner,
                    pHeaderInner->type->pTypeName,
                    pHeaderInner->characteristic);

                // Use mark offset from type information.
                il2c_mark_handler_for_objref__(pAdjustedReferenceInner);
            }
            else
            {
                il2c_runtime_debug_log_format(
                    L"il2c_mark_handler_recursive__ [4]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pAdjustedReferenceInner=0x{3:p}, targetType={4:s}, characteristic=0x{5:x}",
                    pTarget,
                    type->pTypeName,
                    index,
                    pAdjustedReferenceInner,
                    pHeaderInner->type->pTypeName,
                    pHeaderInner->characteristic);
            }
        }
    }
}

/////////////////////////////////////////////////////////////
// GC processes

static void il2c_step2_mark_gcmark__(IL2C_GC_TRACKING_INFORMATION* pBeginFrame)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Mark headers.
    IL2C_GC_TRACKING_INFORMATION* pCurrentFrame = pBeginFrame;
    while (il2c_likely__(pCurrentFrame != NULL))
    {
        // Traverse objrefs at the current frame.
        uint16_t index;
        void** ppReference = (void**)&pCurrentFrame->pReferences__[0];
        for (index = 0; il2c_likely__(index < pCurrentFrame->objRefCount__); index++, ppReference++)
        {
            // This variable isn't assigned.
            if (il2c_unlikely__(*ppReference == NULL))
            {
                il2c_runtime_debug_log_format(
                    L"il2c_step2_mark_gcmark__ [2]: pCurrentFrame=0x{0:p}, index={1:u}, *ppReference=NULL",
                    pCurrentFrame,
                    index);
                continue;
            }

            System_Object* pAdjustedReference = il2c_adjusted_reference(*ppReference);
            TRY_GET_HEADER(pHeader, pAdjustedReference)
            {
                il2c_runtime_debug_log_format(
                    L"il2c_step2_mark_gcmark__ [3]: pCurrentFrame=0x{0:p}, index={1:u}, *ppReference=0x{2:p}, pAdjustedReference=0x{3:p}, type={4:s}, characteristic=0x{5:x}",
                    pCurrentFrame,
                    index,
                    *ppReference,
                    pAdjustedReference,
                    pHeader->type->pTypeName,
                    pHeader->characteristic);

                // Mark for this objref.
                il2c_mark_handler_for_objref__(pAdjustedReference);
            }
            else
            {
                il2c_runtime_debug_log_format(
                    L"il2c_step2_mark_gcmark__ [4]: pCurrentFrame=0x{0:p}, index={1:u}, *ppReference=0x{2:p}, pAdjustedReference=0x{3:p}, type={4:s}, characteristic=0x{5:x}",
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
        for (index = 0; il2c_likely__(index < pCurrentFrame->valueCount__); index++, pValueDesc++)
        {
            il2c_assert(pValueDesc->ptr_value != NULL);
            il2c_assert(pValueDesc->type_value != NULL);
            il2c_assert((pValueDesc->type_value->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

            il2c_runtime_debug_log_format(
                L"il2c_step2_mark_gcmark__ [5]: pCurrentFrame=0x{0:p}, index={1:u}, type={2:s}, pValue={3:p}",
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

static void il2c_step2_mark_gcmark_for_root_referfences__(IL2C_ROOT_REFERENCES* pRootReferences)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    while (il2c_likely__(pRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            // This slot is assigned.
            System_Object* pAdjustedReference = (System_Object*)*ppReference;
            if (il2c_likely__(pAdjustedReference != NULL))
            {
                TRY_GET_HEADER(pHeader, pAdjustedReference)
                {
                    il2c_runtime_debug_log_format(
                        L"il2c_step2_mark_gcmark_for_root_referfences__ [1]: pRootReferences=0x{0:p}, index={1:u}, pAdjustedReference=0x{2:p}, type={3:s}, characteristic=0x{4:x}",
                        pRootReferences,
                        index,
                        pAdjustedReference,
                        pHeader->type->pTypeName,
                        pHeader->characteristic);

                    // Mark for this objref.
                    il2c_mark_handler_for_objref__(pAdjustedReference);
                }
                else
                {
                    il2c_runtime_debug_log_format(
                        L"il2c_step2_mark_gcmark_for_root_referfences__ [2]: pRootReferences=0x{0:p}, index={1:u}, pAdjustedReference=0x{2:p}, type={3:s}, characteristic=0x{4:x}",
                        pRootReferences,
                        index,
                        pAdjustedReference,
                        pHeader->type->pTypeName,
                        pHeader->characteristic);
                }
            }
        }

        pRootReferences = pRootReferences->pNext;
    }
}

static uintptr_t il2c_step3_sweep_garbage__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Detected pending instances
    g_PendingRemains__ = 0;
    // Detected instance remains
    uintptr_t remains = 0;

    // =================================================================
    // Step 1: Collect unmarked instances and call finalizers.

    IL2C_REF_HEADER** ppUnlinkTarget = &g_pBeginHeader__;
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    IL2C_REF_HEADER* pScheduledHeader = NULL;
    while (il2c_likely__(pCurrentHeader != NULL))
    {
        IL2C_REF_HEADER* pNext = pCurrentHeader->pNext;
        if (il2c_unlikely__(((pCurrentHeader->characteristic &
            (IL2C_CHARACTERISTIC_INITIALIZED | IL2C_CHARACTERISTIC_MARK_INDEX)) ^
            (IL2C_CHARACTERISTIC_INITIALIZED | IL2C_CHARACTERISTIC_MARK_INDEX)) ==
            g_CollectionMarkIndex__))
        {
            // Class type overrided the finalizer:
            if (il2c_unlikely__((void*)((System_Object_VTABLE_DECL__*)(pCurrentHeader->type->vptr0))->Finalize != (void*)System_Object_Finalize))
            {
                // Do atomic set finalized flag
                interlock_t characteristic = il2c_ior(&pCurrentHeader->characteristic, IL2C_CHARACTERISTIC_FINALIZER_CALLED);
                if (il2c_likely__((characteristic & IL2C_CHARACTERISTIC_FINALIZER_CALLED) == 0))
                {
                    // Finalizer didn't call or reregistered (GC.ReRegisterForFinalize())

                    // Temporary marked (reserving resurrection)
                    il2c_ixor(&pCurrentHeader->characteristic, IL2C_CHARACTERISTIC_MARK_INDEX);

                    System_Object* pAdjustedReference = (System_Object*)(((uint8_t*)pCurrentHeader) + sizeof(IL2C_REF_HEADER));
                    il2c_assert((void*)pAdjustedReference->vptr0__ == (void*)pCurrentHeader->type->vptr0);

                    il2c_runtime_debug_log_format(
                        L"il2c_step3_sweep_garbage__ [1]: call finalizer: type={0:s}, pAdjustedReference=0x{0:p}",
                        pCurrentHeader->type->pTypeName,
                        pAdjustedReference);

                    // Call finalizer.
                    pAdjustedReference->vptr0__->Finalize(pAdjustedReference);

                    // GC don't collect current situation because finalizer perhaps made resurrection.
                    g_PendingRemains__++;
                    remains++;

                    ppUnlinkTarget = (void*)&pCurrentHeader->pNext;
                }
                else
                {
                    // Very important unlink step: because cause misread on purpose this__ instance is living.
                    *ppUnlinkTarget = pNext;

                    // Insert to free list.
                    pCurrentHeader->pNext = pScheduledHeader;
                    pScheduledHeader = pCurrentHeader;
                }
            }
            else
            {
                // Very important unlink step: because cause misread on purpose this__ instance is living.
                *ppUnlinkTarget = pNext;

                // Insert to free list.
                pCurrentHeader->pNext = pScheduledHeader;
                pScheduledHeader = pCurrentHeader;
            }
        }
        else
        {
            ppUnlinkTarget = (void*)&pCurrentHeader->pNext;
            remains++;
        }

        // Next
        pCurrentHeader = pNext;
    }

    // =================================================================
    // Step 2: Free collected instances.

    while (il2c_likely__(pScheduledHeader != NULL))
    {
        IL2C_REF_HEADER* pNext = pScheduledHeader->pNext;

        il2c_runtime_debug_log_format(
            L"il2c_step3_sweep_garbage__ [2]: free: type={0:s}, pObject=0x{1:p}, characteristic=0x{2:x}",
            pScheduledHeader->type->pTypeName,
            ((uint8_t*)pScheduledHeader) + sizeof(IL2C_REF_HEADER),
            pScheduledHeader->characteristic);

        // Simply ignore if this instance didn't mark ACQUIRED.
        if (il2c_unlikely__(pScheduledHeader->characteristic & IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK))
        {
            // Monitor lock discarded.
            il2c_release_monitor_lock_from_objref__(pScheduledHeader);
        }

        // Heap discarded.
        il2c_free((void*)pScheduledHeader);

        // Next
        pScheduledHeader = pNext;
    }

    return remains;
}

#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
static void il2c_enter_for_collect__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    IL2C_ROOT_REFERENCES* pRootReferences = g_pRootReferences__;
    while (il2c_likely__(pRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            // This slot is assigned.
            IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)*ppReference;
            if (il2c_likely__(pRuntimeThread != NULL))
            {
                il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);

                il2c_enter_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);
            }
        }

        pRootReferences = pRootReferences->pNext;
    }
}

static void il2c_exit_for_collect__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    IL2C_ROOT_REFERENCES* pRootReferences = g_pRootReferences__;
    while (il2c_likely__(pRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            // This slot is assigned.
            IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)*ppReference;
            if (il2c_likely__(pRuntimeThread != NULL))
            {
                il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);

                il2c_exit_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);
            }
        }

        pRootReferences = pRootReferences->pNext;
    }
}
#endif

////////////////////////////////////////////////////////////////////////////////////////

#if defined(IL2C_USE_LINE_INFORMATION)
void il2c_collect__(const char* pFile, int line)
#else
void il2c_collect__(void)
#endif
{
    // Ignores reentrant by the finalizers.
    if (il2c_unlikely__(il2c_iinc(&g_ExecutingCollection__) >= 2))
    {
        il2c_idec(&g_ExecutingCollection__);
        return;
    }

#if defined(_DEBUG)
    const uint32_t collectCount = g_CollectCount++;
    if (il2c_unlikely__(g_CollectCountBreak != -1))
    {
        il2c_assert(collectCount != (uint32_t)g_CollectCountBreak);
    }
#endif

    // Take GC locks.
    il2c_enter_monitor_lock__(&g_GlobalLockForCollect__);
#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
    il2c_enter_for_collect__();
#endif

#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_runtime_debug_log_format(
        L"il2c_collect__: begin: {0:u}: Header=0x{1:p}, StaticFields=0x{2:p}, markIndex={3:x}, {4:s}({5:d})",
        collectCount,
        g_pBeginHeader__,
        g_pBeginStaticFields__,
        g_CollectionMarkIndex__,
        pFile, line);
#elif defined(_DEBUG)
    il2c_runtime_debug_log(
        L"il2c_collect__: begin: {0:u}: Header=0x{1:p}, StaticFields=0x{2:p}, markIndex={3:x}",
        collectCount,
        g_pBeginHeader__,
        g_pBeginStaticFields__,
        g_CollectionMarkIndex__);
#else
    il2c_runtime_debug_log(L"il2c_collect__: begin");
#endif

    //////////////////////////////////////////////////
    // GC Step 1:

    // Note: Traditional mark-sweep GC's first step is clearing markings.
    //   The IL2C GC skips this step and mark/clear flag indicates with inverse arithmetic
    //   between g_CollectionMarkIndex__ and characteristic's MARK_INDEX.
    //   The instances characteristic MARK_INDEX will indicate last stats, so makes NOT MARKED if inversed this flag.
    il2c_ixor(&g_CollectionMarkIndex__, IL2C_CHARACTERISTIC_MARK_INDEX);

    il2c_check_heap();

    //////////////////////////////////////
    // GC Step 2:

    il2c_step2_mark_gcmark__(g_pBeginStaticFields__);
    il2c_check_heap();

    il2c_step2_mark_gcmark_for_root_referfences__(g_pRootReferences__);
    il2c_check_heap();
    il2c_step2_mark_gcmark_for_root_referfences__(g_pFixedReferences__);
    il2c_check_heap();

    //////////////////////////////////////////////////
    // GC Step 3:

    il2c_step3_sweep_garbage__();
    il2c_check_heap();

#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_runtime_debug_log_format(
        L"il2c_collect__: finished: {0:u}: pendingRemains={1:u}, {2:s}({3:d})",
        collectCount,
        g_PendingRemains__,
        pFile,
        line);
#elif defined(_DEBUG)
    il2c_runtime_debug_log_format(
        L"il2c_collect__: finished: {0:u}: pendingRemains={1:u}",
        collectCount,
        g_PendingRemains__);
#else
    il2c_runtime_debug_log_format(
        L"il2c_collect__: finished: pendingRemains={0:u}",
        g_PendingRemains__);
#endif

    // Release GC locks.
#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
    il2c_exit_for_collect__();
#endif
    il2c_exit_monitor_lock__(&g_GlobalLockForCollect__);

    il2c_idec(&g_ExecutingCollection__);
}

////////////////////////////////////////////////////////////////////////////////////////

void il2c_collect_for_final_shutdown__(void)
{
    const interlock_t executingCollection = il2c_iinc(&g_ExecutingCollection__);
    il2c_assert(executingCollection == 1);

#if defined(_DEBUG)
    const uint32_t collectCount = g_CollectCount++;
    if (il2c_unlikely__(g_CollectCountBreak != -1))
    {
        il2c_assert(collectCount != (uint32_t)g_CollectCountBreak);
    }
#endif

    // Take GC locks.
    il2c_enter_monitor_lock__(&g_GlobalLockForCollect__);
#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
    il2c_enter_for_collect__();
#endif

    il2c_check_heap();

#if defined(_DEBUG)
    il2c_runtime_debug_log_format(
        L"il2c_collect_for_final_shutdown__: begin: {0:u}: Header=0x{1:p}, StaticFields=0x{2:p}, markIndex={3:x}",
        collectCount,
        g_pBeginHeader__,
        g_pBeginStaticFields__,
        g_CollectionMarkIndex__);
#else
    il2c_runtime_debug_log(
        L"il2c_collect_for_final_shutdown__: begin");
#endif

    // Exhaust all instances
    while (1)
    {
        //////////////////////////////////////////////////
        // GC Step 1:

        // Note: Traditional mark-sweep GC's first step is clearing markings.
        //   The IL2C GC skips this step and mark/clear flag indicates with inverse arithmetic
        //   between g_CollectionMarkIndex__ and characteristic's MARK_INDEX.
        //   The instances characteristic MARK_INDEX will indicate last stats, so makes NOT MARKED if inversed this flag.
        il2c_ixor(&g_CollectionMarkIndex__, IL2C_CHARACTERISTIC_MARK_INDEX);

        //////////////////////////////////////
        // GC Step 2:

        // The final GC step has to ignore both static fields, root references and fixed references.
        // Step 3 collects all instances if GC doesn't have collecting problems ;)
        il2c_unregister_all_root_references_for_final_shutdown__(&g_pRootReferences__);
        il2c_check_heap();
        il2c_unregister_all_root_references_for_final_shutdown__(&g_pFixedReferences__);
        il2c_check_heap();

        //////////////////////////////////////////////////
        // GC Step 3:

        const uintptr_t remains = il2c_step3_sweep_garbage__();
        il2c_check_heap();
        if (remains == 0)
        {
            break;
        }
    }

    // Release monitor locks.
    il2c_release_all_monitor_lock_for_final_shutdown__();

#if defined(_DEBUG)
    il2c_runtime_debug_log_format(
        L"il2c_collect_for_final_shutdown__: finished: {0:u}",
        collectCount);
#else
    il2c_runtime_debug_log(
        L"il2c_collect_for_final_shutdown__: finished");
#endif

    // Release GC locks.
#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
    il2c_exit_for_collect__();
#endif
    il2c_exit_monitor_lock__(&g_GlobalLockForCollect__);

    il2c_idec(&g_ExecutingCollection__);
}

/////////////////////////////////////////////////////////////
// Default GC mark handlers for using from externals.

void il2c_default_mark_handler_for_objref__(void* pReference)
{
    il2c_assert(pReference != NULL);

    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    System_Object * pAdjustedReference = il2c_adjusted_reference(pReference);
    TRY_GET_HEADER(pHeader, pAdjustedReference)
    {
        il2c_runtime_debug_log_format(
            L"il2c_default_mark_handler_for_objref__ [1]: pReference=0x{0:p}, pAdjustedReference=0x{1:p}, type={2:s}, characteristic=0x{3:x}",
            pReference,
            pAdjustedReference,
            pHeader->type->pTypeName,
            pHeader->characteristic);

        // Traverse recursively.
        il2c_mark_handler_for_objref__(pAdjustedReference);
    }
    else
    {
        il2c_runtime_debug_log_format(
            L"il2c_default_mark_handler_for_objref__ [2]: pReference=0x{0:p}, pAdjustedReference=0x{1:p}, type={2:s}, characteristic=0x{3:x}",
            pReference,
            pAdjustedReference,
            pHeader->type->pTypeName,
            pHeader->characteristic);
    }
}

void il2c_default_mark_handler_for_value_type__(void* pValue, IL2C_RUNTIME_TYPE valueType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert((valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Traverse recursively.
    il2c_mark_handler_recursive__(pValue, valueType, 0);
}

void il2c_default_mark_handler_for_tracking_information__(IL2C_GC_TRACKING_INFORMATION* pTrackingInformation)
{
    il2c_assert(pTrackingInformation != NULL);

    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Traverse recursively.
    il2c_step2_mark_gcmark__(pTrackingInformation);
}
