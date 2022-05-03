#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Array

int32_t System_Array_getLength(System_Array* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Array_VTABLE__);
    il2c_assert(this__->elementType__ != NULL);
    il2c_assert(this__->Length >= 0);

    return (int32_t)(this__->Length);
}

int32_t System_Array_GetLowerBound__System_Int32(System_Array* this__, int32_t dimension)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Array_VTABLE__);
    il2c_assert(this__->elementType__ != NULL);
    il2c_assert(this__->Length >= 0);

    // TODO: MD array not implemented.
    if (il2c_unlikely__(dimension != 0))
    {
        il2c_throw_indexoutofrangeexception__();
    }

    // TODO: bind range not implemented.
    return 0;
}

int32_t System_Array_GetUpperBound__System_Int32(System_Array* this__, int32_t dimension)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Array_VTABLE__);
    il2c_assert(this__->elementType__ != NULL);
    il2c_assert(this__->Length >= 0);

    // TODO: MD array not implemented.
    if (il2c_unlikely__(dimension != 0))
    {
        il2c_throw_indexoutofrangeexception__();
    }

    // TODO: bind range not implemented.
    return (int32_t)(this__->Length - 1);
}

/////////////////////////////////////////////////
// Array special functions

#if defined(IL2C_USE_LINE_INFORMATION)
System_Array* il2c_new_array__(
    IL2C_RUNTIME_TYPE elementType, intptr_t length, const char* pFile, int line)
#else
System_Array* il2c_new_array__(
    IL2C_RUNTIME_TYPE elementType, intptr_t length)
#endif
{
    il2c_assert(elementType != NULL);
    
    if (il2c_unlikely__(length < 0))
    {
        // throw OverflowException
        il2c_assert(0);
    }

    const uintptr_t elementSize = il2c_sizeof__(elementType);
    il2c_assert(elementSize >= 1);

    // -1 is "uint8_t Item[1]"
    const uintptr_t size = (uintptr_t)sizeof(System_Array) + ((uintptr_t)length) * elementSize;
    
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_Array),
        size,
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_Array),
        size);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_Array* arr = (System_Array*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)arr;

    il2c_assert(arr->vptr0__ == &System_Array_VTABLE__);

    arr->elementType__ = elementType;
    arr->Length = length;

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return arr;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

static void System_Array_MarkHandler__(System_Array* arr)
{
    il2c_assert(arr != NULL);
    il2c_assert(arr->vptr0__ == &System_Array_VTABLE__);

    intptr_t index;
    if (arr->elementType__->flags & IL2C_TYPE_VALUE)
    {
        for (index = 0; il2c_likely__(index < arr->Length); index++)
        {
            void* pValue = il2c_array_itemptr__(arr, (uint32_t)(arr->elementType__->bodySize), index);
            il2c_default_mark_handler_for_value_type__(pValue, arr->elementType__);
        }
    }
    else
    {
        for (index = 0; il2c_likely__(index < arr->Length); index++)
        {
            void* pReference = il2c_array_item(arr, void*, index);
            if (pReference != NULL)
            {
                il2c_default_mark_handler_for_objref__(pReference);
            }
        }
    }
}

IL2C_RUNTIME_TYPE_BEGIN(
    System_Array,
    "System.Array",
    IL2C_TYPE_REFERENCE | IL2C_TYPE_VARIABLE | IL2C_TYPE_WITH_MARK_HANDLER,
    0,
    System_Object,
    System_Array_MarkHandler__,
    0)
IL2C_RUNTIME_TYPE_END();
