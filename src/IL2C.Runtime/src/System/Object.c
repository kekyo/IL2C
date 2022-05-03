#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Object

System_String* System_Object_ToString(System_Object* this__)
{
    il2c_assert(this__ != NULL);

    System_Type* pType = System_Object_GetType(this__);
    return System_Type_get_FullName(pType);
}

int32_t System_Object_GetHashCode(System_Object* this__)
{
    il2c_assert(this__ != NULL);

    return (int32_t)(intptr_t)this__;
}

System_Type* System_Object_GetType(System_Object* this__)
{
    il2c_assert(this__ != NULL);

    System_Type* pType = il2c_get_uninitialized_object(System_Type);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(this__);
    pType->type__ = pHeader->type;

    return pType;
}

void System_Object_Finalize(System_Object* this__)
{
    // Caution: This function only uses for GC tracking, don't access this__ pointer inside this function.
    //   Because we can't understand what's this__ pointer at here, the pointer came from objref [O] or byref [&].
}

bool System_Object_Equals__System_Object(System_Object* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    return ((intptr_t)this__) == ((intptr_t)obj);
}

bool System_Object_ReferenceEquals__System_Object_System_Object(System_Object* objA, System_Object* objB)
{
    return ((intptr_t)objA) == ((intptr_t)objB);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

System_Object_VTABLE_DECL__ System_Object_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Object_Equals__System_Object,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString
};

const uintptr_t System_Object_RUNTIME_TYPE__[] = {
    (uintptr_t)("System.Object"),
    IL2C_TYPE_REFERENCE,
    sizeof(System_Object),
    (uintptr_t)NULL,
    (uintptr_t)&System_Object_VTABLE__,
    0,
    0
};
