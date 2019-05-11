#include "il2c_private.h"
#include <System/Runtime/InteropServices/GCHandle.h>

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.GCHandle

System_Object* System_Runtime_InteropServices_GCHandle_get_Target(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);
    return (System_Object*)*this__;
}

void System_Runtime_InteropServices_GCHandle_set_Target__System_Object(System_Runtime_InteropServices_GCHandle* this__, System_Object* value)
{
    System_Runtime_InteropServices_GCHandle_Free(this__);

    if (value != NULL)
    {
        il2c_register_root_reference__(value, true);
    }

    *this__ = (intptr_t)value;
}

void System_Runtime_InteropServices_GCHandle_Free(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);

    System_Object* pObject = (System_Object*)*this__;
    if (pObject != NULL)
    {
        il2c_unregister_root_reference__(pObject, true);
    }

    *this__ = 0;
}

intptr_t System_Runtime_InteropServices_GCHandle_AddrOfPinnedObject(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);

    // TODO: It has to reinterpret for required pointer. ex: System_String --> string_body__
    return (intptr_t)*this__;
}

System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc__System_Object(System_Object* value)
{
    // intptr_t aliased
    return (System_Runtime_InteropServices_GCHandle)value;
}

System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc__System_Object_System_Runtime_InteropServices_GCHandleType(
    System_Object* value, System_Runtime_InteropServices_GCHandleType type)
{
    if ((type == System_Runtime_InteropServices_GCHandleType_Normal) ||
        (type == System_Runtime_InteropServices_GCHandleType_Pinned))
    {
        if (value != NULL)
        {
            il2c_register_root_reference__(value, true);
        }
    }

    // intptr_t aliased
    return (System_Runtime_InteropServices_GCHandle)value;
}

int32_t System_Runtime_InteropServices_GCHandle_GetHashCode(System_Runtime_InteropServices_GCHandle* this__)
{
    // TODO:
    //il2c_assert(0);
    return (int32_t)(intptr_t)this__;
}

bool System_Runtime_InteropServices_GCHandle_Equals__System_Object(System_Runtime_InteropServices_GCHandle* this__, System_Object* obj)
{
    // TODO:
    //il2c_assert(0);
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

static int32_t System_Runtime_InteropServices_GCHandle_GetHashCode__Trampoline_VFunc__(System_ValueType* this__)
{
    il2c_assert(this__ != NULL);

    System_Runtime_InteropServices_GCHandle* pValue = il2c_unsafe_unbox__(this__, System_Runtime_InteropServices_GCHandle);
    return System_Runtime_InteropServices_GCHandle_GetHashCode(pValue);
}

static bool System_Runtime_InteropServices_GCHandle_Equals__System_Object__Trampoline_VFunc__(System_ValueType* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    System_Runtime_InteropServices_GCHandle* pValue = il2c_unsafe_unbox__(this__, System_Runtime_InteropServices_GCHandle);
    return System_Runtime_InteropServices_GCHandle_Equals__System_Object(pValue, obj);
}

System_Runtime_InteropServices_GCHandle_VTABLE_DECL__ System_Runtime_InteropServices_GCHandle_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Runtime_InteropServices_GCHandle_Equals__System_Object__Trampoline_VFunc__,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Runtime_InteropServices_GCHandle_GetHashCode__Trampoline_VFunc__,
    (System_String* (*)(void*))System_Object_ToString
};

IL2C_RUNTIME_TYPE_BEGIN(
    System_Runtime_InteropServices_GCHandle,
    "System.Runtime.InteropServices.GCHandle",
    IL2C_TYPE_VALUE,
    sizeof(System_Runtime_InteropServices_GCHandle),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
