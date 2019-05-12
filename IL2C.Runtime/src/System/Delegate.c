#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Delegate

int32_t System_Delegate_GetHashCode(System_Delegate* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    System_Type* pType = System_Object_GetType((System_Object*)this__);
    return pType->vptr0__->GetHashCode(pType);
}

bool System_Delegate_Equals__System_Object(System_Delegate* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    if (System_Object_ReferenceEquals__System_Object_System_Object((System_Object*)this__, obj))
    {
        return true;
    }

    System_Delegate* rhs = il2c_isinst(obj, System_Delegate);
    if (rhs == NULL)
    {
        return false;
    }

    il2c_assert(rhs->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(rhs->count__ >= 1);

    if (this__->count__ != rhs->count__)
    {
        return false;
    }

    return memcmp(
        this__->methodtbl__,
        rhs->methodtbl__,
        this__->count__ * sizeof(IL2C_METHOD_TABLE)) == 0;
}

System_Delegate* System_Delegate_Combine__System_Delegate_System_Delegate(System_Delegate* a, System_Delegate* b)
{
    if (a == NULL)
    {
        if (b == NULL)
        {
            return NULL;
        }
        else
        {
            il2c_assert(b->vptr0__ == &System_Delegate_VTABLE__);
            il2c_assert(b->count__ >= 1);
            return b;
        }
    }
    else
    {
        if (b == NULL)
        {
            il2c_assert(a->vptr0__ == &System_Delegate_VTABLE__);
            il2c_assert(a->count__ >= 1);
            return a;
        }
    }

    il2c_assert(a->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(a->count__ >= 1);
    il2c_assert(b->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(b->count__ >= 1);

    // Requires same delegate type.
    IL2C_REF_HEADER* pHeaderA = il2c_get_header__(a);
    IL2C_REF_HEADER* pHeaderB = il2c_get_header__(b);
    if (pHeaderA->type != pHeaderB->type)
    {
        // https://docs.microsoft.com/en-us/dotnet/api/system.delegate.combine
        // TODO: throw new ArgumentException
        il2c_assert(0);
    }

    const uintptr_t count = a->count__ + b->count__;
    const uintptr_t size = sizeof(System_Delegate) +
        (uintptr_t)(count - 1 /* included System_Delegate */) * sizeof(IL2C_METHOD_TABLE);

#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        pHeaderA->type,
        size,
        __FILE__,
        __LINE__);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        __FILE__, __LINE__);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        pHeaderA->type,
        size);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_Delegate* dlg = (System_Delegate*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)dlg;

    il2c_assert(dlg->vptr0__ == &System_Delegate_VTABLE__);

    struct IL2C_METHOD_TABLE_DECL* pMethodtbl = (struct IL2C_METHOD_TABLE_DECL*)&dlg->methodtbl__[0];
    memcpy(&pMethodtbl[0], &a->methodtbl__[0], a->count__ * sizeof(IL2C_METHOD_TABLE));
    memcpy(&pMethodtbl[a->count__], &b->methodtbl__[0], b->count__ * sizeof(IL2C_METHOD_TABLE));
    
    dlg->count__ = count;

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return dlg;
}

System_Delegate* System_Delegate_Remove__System_Delegate_System_Delegate(System_Delegate* source, System_Delegate* value)
{
    if (source == NULL)
    {
        return NULL;
    }

    il2c_assert(source->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(source->count__ >= 1);

    if (value == NULL)
    {
        return source;
    }

    il2c_assert(value->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(value->count__ >= 1);

    // Requires same delegate type.
    IL2C_REF_HEADER* pHeaderSource = il2c_get_header__(source);
    IL2C_REF_HEADER* pHeaderValue = il2c_get_header__(value);
    if (pHeaderSource->type != pHeaderValue->type)
    {
        // https://docs.microsoft.com/en-us/dotnet/api/system.delegate.remove
        // TODO: throw new ArgumentException
        il2c_assert(0);
    }

    // Can't match
    if (source->count__ < value->count__)
    {
        return source;
    }

    // Last --> First
    IL2C_METHOD_TABLE* pMethodtblValue = &value->methodtbl__[0];
    intptr_t index;
    for (index = (intptr_t)(source->count__ - value->count__); il2c_likely__(index >= 0); index--)
    {
        IL2C_METHOD_TABLE* pMethodtblSource = &source->methodtbl__[index];

        // Equals
        if (memcmp(pMethodtblValue, pMethodtblSource, value->count__ * sizeof(IL2C_METHOD_TABLE)) == 0)
        {
            // Exactly match: result's gonna be empty
            if (source->count__ <= value->count__)
            {
                return NULL;
            }

            uintptr_t count = source->count__ - value->count__;
            uintptr_t size = sizeof(System_Delegate) +
                (uintptr_t)(count - 1 /* included System_Delegate */) * sizeof(IL2C_METHOD_TABLE);

#if defined(IL2C_USE_LINE_INFORMATION)
            IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
                pHeaderSource->type,
                size,
                __FILE__,
                __LINE__);
            IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
                __FILE__, __LINE__);
#else
            IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
                pHeaderSource->type,
                size);
            IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

            System_Delegate* dlg = (System_Delegate*)(pHeader + 1);
            pThreadContext->pTemporaryReferenceAnchor = (System_Object*)dlg;

            il2c_assert(dlg->vptr0__ == &System_Delegate_VTABLE__);

            struct IL2C_METHOD_TABLE_DECL* pMethodtbl = (struct IL2C_METHOD_TABLE_DECL*)&dlg->methodtbl__[0];
            memcpy(&pMethodtbl[0], &source->methodtbl__[0], ((size_t)index) * sizeof(IL2C_METHOD_TABLE));
            memcpy(&pMethodtbl[index], &source->methodtbl__[((uintptr_t)index) + value->count__], ((size_t)count - (size_t)index) * sizeof(IL2C_METHOD_TABLE));

            dlg->count__ = count;

            // Marked instance is initialized. (and will handle by GC)
            il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

            return dlg;
        }
    }

    // Not found.
    return source;
}

/////////////////////////////////////////////////
// Delegate special functions

#if defined(IL2C_USE_LINE_INFORMATION)
System_Delegate* il2c_new_delegate__(
    IL2C_RUNTIME_TYPE delegateType, System_Object* object, intptr_t method, const char* pFile, int line)
#else
System_Delegate* il2c_new_delegate__(
    IL2C_RUNTIME_TYPE delegateType, System_Object* object, intptr_t method)
#endif
{
    il2c_assert(delegateType != NULL);
    il2c_assert(method != 0);

#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        delegateType,
        sizeof(System_Delegate),
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        delegateType,
        sizeof(System_Delegate));
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_Delegate* dlg = (System_Delegate*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)dlg;

    il2c_assert(dlg->vptr0__ == &System_Delegate_VTABLE__);

    struct IL2C_METHOD_TABLE_DECL* pMethodTbl = (struct IL2C_METHOD_TABLE_DECL*)&dlg->methodtbl__[0];
    pMethodTbl->target = object;
    pMethodTbl->methodPtr = method;

    dlg->count__ = 1;

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return dlg;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void System_Delegate_MarkHandler__(System_Delegate* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    uintptr_t index;
    for (index = 0; il2c_likely__(index < this__->count__); index++)
    {
        il2c_assert(this__->methodtbl__[index].methodPtr != 0);

        // This target is static method.
        void* pReference = this__->methodtbl__[index].target;
        if (pReference == NULL)
        {
            continue;
        }

        il2c_default_mark_handler_for_objref__(pReference);
    }
}

System_Delegate_VTABLE_DECL__ System_Delegate_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Delegate_Equals__System_Object,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Delegate_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString
};

IL2C_RUNTIME_TYPE_BEGIN(
    System_Delegate,
    "System.Delegate",
    IL2C_TYPE_REFERENCE | IL2C_TYPE_VARIABLE | IL2C_TYPE_WITH_MARK_HANDLER,
    0,
    System_Object,
    System_Delegate_MarkHandler__,
    0)
IL2C_RUNTIME_TYPE_END();
