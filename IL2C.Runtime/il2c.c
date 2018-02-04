/////////////////////////////////////////////////////////////
// For platform specifics:

#if defined(UEFI)

#include <intrin.h>
#include <stdint.h>
#include <wchar.h>

#pragma intrinsic(memset)
#pragma intrinsic(memcpy)

typedef long interlock_t;

#define GCALLOC malloc
#define GCFREE free
#define GCASSERT assert

void WriteLineToError(const wchar_t* pMessage);

#if !defined(_DEBUG)
#define DEBUG_WRITE(step, message) { \
    WriteLineToError(L##step); }
#else
#define DEBUG_WRITE(step, message)
#endif

#elif defined(_WDM)

#include <intrin.h>
#include <wdm.h>
#include <stdint.h>
#include <wchar.h>

#pragma intrinsic(memset)
#pragma intrinsic(memcpy)

typedef long interlock_t;

#define GCASSERT ASSERT
#define GCALLOC(size) ExAllocatePoolWithTag(NonPagedPool, size, 0x11231123UL)
#define GCFREE(p) ExFreePoolWithTag(p, 0x11231123UL)

#ifdef DBG
#define DEBUG_WRITE(step, message) { \
    char buffer[256]; \
    strcpy(buffer, step); \
    strcat(buffer, ": "); \
    strcat(buffer, message); \
    strcat(buffer, "\r\n"); \
    DbgPrint(buffer); }
#else
#define DEBUG_WRITE(step, message)
#endif

#elif defined(_WIN32)

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRTDBG_MAP_ALLOC 1
#include <crtdbg.h>
#include <intrin.h>

#define GCALLOC malloc
#define GCFREE free
#define GCASSERT assert

#include <stdint.h>
#include <wchar.h>

#pragma intrinsic(memset)
#pragma intrinsic(memcpy)

typedef long interlock_t;

#include <windows.h>

#ifdef _DEBUG
#define DEBUG_WRITE(step, message) { \
    char buffer[256]; \
    strcpy(buffer, step); \
    strcat(buffer, ": "); \
    strcat(buffer, message); \
    strcat(buffer, "\r\n"); \
    OutputDebugStringA(buffer); }
#else
#define DEBUG_WRITE(step, message)
#endif

#else

#include <stdint.h>

typedef uint8_t interlock_t;

static interlock_t _InterlockedCompareExchange(interlock_t* p, interlock_t v, interlock_t c)
{
    interlock_t cv = *p;
    if (cv == c)
    {
        *p = v;
    }
    return cv;
}

static void* _InterlockedCompareExchangePointer(void** p, void* v, void* c)
{
    void* cv = *p;
    if (cv == c)
    {
        *p = v;
    }
    return cv;
}

#define GCALLOC(size) malloc(size)
#define GCFREE(p) free(p)
#define GCASSERT assert

#define DEBUG_WRITE(step, message)

#endif

#define INTERLOCKED_COMPARE_EXCHANGE(p, v, c) (interlock_t)_InterlockedCompareExchange((interlock_t*)p, (interlock_t)v, (interlock_t)c)
#define INTERLOCKED_COMPARE_EXCHANGE_POINTER(p, v, c) (void*)_InterlockedCompareExchangePointer((void**)p, (void*)v, (void*)c)

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <il2c.h>

/////////////////////////////////////////////////////////////

// TODO: Support finalizer
#define GCMARK_NOMARK ((interlock_t)1)
#define GCMARK_LIVE ((interlock_t)0)

struct IL2C_EXECUTION_FRAME
{
    IL2C_EXECUTION_FRAME* pNext;
    uint8_t targetCount;
    void** pTargets[];      // We have to track object references.
};

// TODO: Become store to thread local storage
static IL2C_EXECUTION_FRAME* g_pBeginFrame__ = NULL;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;

//////////////////////////

static void* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE type, uintptr_t bodySize)
{
    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)GCALLOC(sizeof(IL2C_REF_HEADER) + bodySize);
    if (pHeader == NULL)
    {
        while (1)
        {
            il2c_collect();

            pHeader = (IL2C_REF_HEADER*)GCALLOC(sizeof(IL2C_REF_HEADER) + bodySize);
            if (pHeader != NULL)
            {
                break;
            }

            // throw NotEnoughMemoryException();
            GCASSERT(0);
        }
    }

    void* pReference = ((uint8_t*)pHeader) + sizeof(IL2C_REF_HEADER);
    if (bodySize >= 1)
    {
        memset(pReference, 0, bodySize);
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
        if ((IL2C_REF_HEADER*)INTERLOCKED_COMPARE_EXCHANGE_POINTER(
            &g_pBeginHeader__,
            pHeader,
            pNext) == pNext)
        {
            break;
        }
    }

    return pReference;
}

void* il2c_get_uninitialized_object(IL2C_RUNTIME_TYPE type)
{
    GCASSERT(type != NULL);

    // String or Array:
    // throw new InvalidProgramException();
    GCASSERT(type->bodySize != UINTPTR_MAX);

    return il2c_get_uninitialized_object_internal__(type, type->bodySize);
}

void il2c_mark_from_handler(void* pReference)
{
    GCASSERT(pReference != NULL);

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pReference) - sizeof(IL2C_REF_HEADER));
    interlock_t currentMark = INTERLOCKED_COMPARE_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
    if (currentMark == GCMARK_NOMARK)
    {
        GCASSERT(pHeader->type != NULL);
        GCASSERT(pHeader->type->pMarkHandler != NULL);
        pHeader->type->pMarkHandler(pReference);
    }
}

//////////////////////////

void il2c_link_execution_frame(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    GCASSERT(pNewFrame != NULL);

    ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = (IL2C_EXECUTION_FRAME*)pNewFrame;

#ifdef _DEBUG
    {
        IL2C_EXECUTION_FRAME* p = (IL2C_EXECUTION_FRAME*)pNewFrame;
        uint8_t index;
        for (index = 0; index < p->targetCount; index++)
        {
            GCASSERT(*p->pTargets[index] == NULL);
        }
    }
#endif
}

void il2c_unlink_execution_frame(/* EXECUTION_FRAME__* */ void* pFrame)
{
    GCASSERT(pFrame != NULL);

    il2c_collect();

    g_pBeginFrame__ = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext;
}

//////////////////////////

void il2c_step1_clear_gcmark__()
{
    // Clear header marks.
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        pCurrentHeader->gcMark = GCMARK_NOMARK;
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
        for (index = 0; index < pCurrentFrame->targetCount; index++)
        {
            void** ppReference = pCurrentFrame->pTargets[index];
            GCASSERT(ppReference != NULL);

            if (*ppReference == NULL)
            {
                continue;
            }

            // Marking process.
            IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
                (((uint8_t*)*ppReference) - sizeof(IL2C_REF_HEADER));
            interlock_t currentMark = INTERLOCKED_COMPARE_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
            if (currentMark == GCMARK_NOMARK)
            {
                GCASSERT(pHeader->type != NULL);
                GCASSERT(pHeader->type->pMarkHandler != NULL);

                DEBUG_WRITE("il2c_step2_mark_gcmark__", pHeader->type->pTypeName);

                pHeader->type->pMarkHandler(*ppReference);
            }
        }

        pCurrentFrame = pCurrentFrame->pNext;
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
        if (pCurrentHeader->gcMark != GCMARK_LIVE)
        {
            // Very important link steps: because cause misread on purpose this__ instance is living.
            *ppUnlinkTarget = pNext;

            DEBUG_WRITE("il2c_step3_sweep_garbage__", pCurrentHeader->type->pTypeName);

            // Heap discarded
            GCFREE(pCurrentHeader);

            pCurrentHeader = pNext;
        }
        else
        {
            ppUnlinkTarget = &pCurrentHeader->pNext;
            pCurrentHeader = pNext;
        }
    }
}

//////////////////////////

void il2c_collect()
{
    il2c_step1_clear_gcmark__();
    il2c_step2_mark_gcmark__();
    il2c_step3_sweep_garbage__();
}

void il2c_initialize()
{
#ifdef _CRTDBG_ALLOC_MEM_DF
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
}

void il2c_shutdown()
{
    il2c_collect();

#ifdef _CRTDBG_ALLOC_MEM_DF
    _CrtDumpMemoryLeaks();
#endif
}

/////////////////////////////////////////////////////////////
// Boxing related functions

System_Object* il2c_box(void* pValue, IL2C_RUNTIME_TYPE type)
{
    void* pBoxed = il2c_get_uninitialized_object(type);
    memcpy(pBoxed, pValue, type->bodySize);
    return (System_Object*)pBoxed;
}

void* il2c_unbox(System_Object* pObject, IL2C_RUNTIME_TYPE type)
{
    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pObject) - sizeof(IL2C_REF_HEADER));
    if (pHeader->type != type)
    {
        // new InvalidCastException();
        GCASSERT(0);
    }

    return pObject;
}

/////////////////////////////////////////////////////////////
// System.Object

static void __Dummy_MARK_HANDLER__(void* pReference)
{
}

static __System_Object_TYPE_DEF_TYPE__ __System_Object_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"System.Object",
    (intptr_t)0,
    (intptr_t)__Dummy_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __System_Object_RUNTIME_TYPE__ =
    (const IL2C_RUNTIME_TYPE)(&__System_Object_RUNTIME_TYPE_DEF__);

IL2C_CONST_STRING(System_Object_name, L"System.Object");
System_String* __System_Object_ToString__(System_Object* this__)
{
    return System_Object_name;
}

int32_t __System_Object_GetHashCode__(System_Object* this__)
{
    return (int32_t)(intptr_t)this__;
}

void __System_Object_Finalize__(System_Object* this__)
{
    DEBUG_WRITE("System.Object.Finalize", "called.");
}

bool __System_Object_Equals__(System_Object* this__, System_Object* obj)
{
    return ((intptr_t)this__) == ((intptr_t)obj);
}

/////////////////////////////////////////////////////////////
// System.ValueType

static __System_ValueType_TYPE_DEF_TYPE__ __System_ValueType_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"System.ValueType",
    (intptr_t)0,
    (intptr_t)__Dummy_MARK_HANDLER__,
    __System_ValueType_ToString__,
    __System_ValueType_GetHashCode__,
    __System_Object_Finalize__,
    __System_ValueType_Equals__,
};
const IL2C_RUNTIME_TYPE __System_ValueType_RUNTIME_TYPE__ =
    (const IL2C_RUNTIME_TYPE)(&__System_ValueType_RUNTIME_TYPE_DEF__);

IL2C_CONST_STRING(System_ValueType_name, L"System.ValueType");
System_String* __System_ValueType_ToString__(System_ValueType* this__)
{
    return System_ValueType_name;
}

int32_t __System_ValueType_GetHashCode__(System_ValueType* this__)
{
    // TODO:
    return (int32_t)(intptr_t)this__;
}

bool __System_ValueType_Equals__(System_ValueType* this__, System_Object* obj)
{
    // TODO:
    return false;
}

/////////////////////////////////////////////////////////////
// Basic type informations

static IL2C_RUNTIME_TYPE_DECL __System_IntPtr_RUNTIME_TYPE_DEF__ = {
    "System.IntPtr", sizeof(System_IntPtr), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_IntPtr_RUNTIME_TYPE__ = &__System_IntPtr_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE_DEF__ = {
    "System.Byte", sizeof(System_Byte), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_Byte_RUNTIME_TYPE__ = &__System_Byte_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE_DEF__ = {
    "System.SByte", sizeof(System_SByte), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_SByte_RUNTIME_TYPE__ = &__System_SByte_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_Int16_RUNTIME_TYPE_DEF__ = {
    "System.Int16", sizeof(System_Int16), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_Int16_RUNTIME_TYPE__ = &__System_Int16_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_UInt16_RUNTIME_TYPE_DEF__ = {
    "System.UInt16", sizeof(System_UInt16), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_UInt16_RUNTIME_TYPE__ = &__System_UInt16_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE_DEF__ = {
    "System.Int32", sizeof(System_Int32), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_Int32_RUNTIME_TYPE__ = &__System_Int32_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_UInt32_RUNTIME_TYPE_DEF__ = {
    "System.UInt32", sizeof(System_UInt32), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_UInt32_RUNTIME_TYPE__ = &__System_UInt32_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_Int64_RUNTIME_TYPE_DEF__ = {
    "System.Int64", sizeof(System_Int64), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_Int64_RUNTIME_TYPE__ = &__System_Int64_RUNTIME_TYPE_DEF__;

static IL2C_RUNTIME_TYPE_DECL __System_UInt64_RUNTIME_TYPE_DEF__ = {
    "System.UInt64", sizeof(System_UInt64), __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_UInt64_RUNTIME_TYPE__ = &__System_UInt64_RUNTIME_TYPE_DEF__;

const System_IntPtr System_IntPtr_Zero = 0;

// TODO: Reimplement by managed code.
extern bool twtoi(const wchar_t *_Str, int32_t* value);

bool System_Int32_TryParse(System_String* s, int32_t* result)
{
    // TODO: NullReferenceException
    GCASSERT(s != NULL);

    GCASSERT(result != NULL);
    GCASSERT(s->string_body__ != NULL);

    return twtoi(s->string_body__, result);
}

/////////////////////////////////////////////////////////////
// System.String

IL2C_RUNTIME_TYPE_DECL __System_String_RUNTIME_TYPE_DEF__ = {
    "System.String", UINTPTR_MAX, __Dummy_MARK_HANDLER__ };
const IL2C_RUNTIME_TYPE __System_String_RUNTIME_TYPE__ = &__System_String_RUNTIME_TYPE_DEF__;

static System_String* __new_string_internal__(uintptr_t size)
{
    uintptr_t bodySize = sizeof(System_String) + size;
    System_String* pString = il2c_get_uninitialized_object_internal__(
        __System_String_RUNTIME_TYPE__,
        bodySize);
    wchar_t* string_body__ = (wchar_t*)(((uint8_t*)pString) + sizeof(System_String));
    pString->string_body__ = string_body__;
    return pString;
}

System_String* il2c_new_string(const wchar_t* string_body__)
{
    GCASSERT(string_body__ != NULL);

    uintptr_t size = (uintptr_t)(wcslen(string_body__) + 1) * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(size);
    memcpy((wchar_t*)(pString->string_body__), string_body__, size);

    return pString;
}

System_String* System_String_Concat_6(System_String* str0, System_String* str1)
{
    GCASSERT(str0 != NULL);
    GCASSERT(str1 != NULL);
    GCASSERT(str0->string_body__ != NULL);
    GCASSERT(str1->string_body__ != NULL);

    uintptr_t str0Size = (uintptr_t)wcslen(str0->string_body__) * sizeof(wchar_t);
    uintptr_t str1Size = (uintptr_t)wcslen(str1->string_body__) * sizeof(wchar_t);

    System_String* pString = __new_string_internal__(str0Size + str1Size + sizeof(wchar_t));
    memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size + sizeof(wchar_t));

    return pString;
}

System_String* System_String_Substring(System_String* this__, int32_t startIndex)
{
    GCASSERT(this__ != NULL);
    GCASSERT(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    GCASSERT(startIndex >= 0);

    if (startIndex == 0)
    {
        return this__;
    }

    int32_t thisLength = (int32_t)wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    GCASSERT(startIndex < thisLength);

    uintptr_t newSize = (uintptr_t)(thisLength - startIndex + 1) * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(newSize);
    memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);

    return pString;
}

System_String* System_String_Substring_1(System_String* this__, int32_t startIndex, int32_t length)
{
    GCASSERT(this__ != NULL);
    GCASSERT(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    GCASSERT(startIndex >= 0);
    GCASSERT(length >= 0);

    int32_t thisLength = (int32_t)wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    GCASSERT((startIndex + length) <= thisLength);

    if ((startIndex == 0) && (length == thisLength))
    {
        return this__;
    }

    uintptr_t newSize = (uintptr_t)length * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(newSize + sizeof(wchar_t));
    memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);
    ((wchar_t*)(pString->string_body__))[length] = L'\0';

    return pString;
}

wchar_t System_String_get_Chars(System_String* this__, int32_t index)
{
    GCASSERT(this__ != NULL);
    GCASSERT(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    GCASSERT(index >= 0);
    GCASSERT(index < wcslen(this__->string_body__));

    return this__->string_body__[index];
}

int32_t System_String_get_Length(System_String* this__)
{
    GCASSERT(this__ != NULL);
    GCASSERT(this__->string_body__ != NULL);

    return (int32_t)wcslen(this__->string_body__);
}

bool System_String_IsNullOrWhiteSpace(System_String* value)
{
    if (value == NULL)
    {
        return true;
    }

    GCASSERT(value->string_body__ != NULL);

    uint32_t index = 0;
    while (true)
    {
        wchar_t ch = value->string_body__[index];
        switch (ch)
        {
        case L'\0':
            return true;
        case L' ':
        case L'\t':
            break;
        default:
            return false;
        }

        index++;
    }
}

/////////////////////////////////////////////////////////////
// System.Console

extern void Write(const wchar_t* pMessage);
extern void WriteLine(const wchar_t* pMessage);
extern void ReadLine(wchar_t* pBuffer, uint16_t length);

void System_Console_Write_9(System_String* value)
{
    // TODO: NullReferenceException
    GCASSERT(value != NULL);

    GCASSERT(value->string_body__ != NULL);
    Write(value->string_body__);
}

void System_Console_WriteLine()
{
    WriteLine(L"");
}

// TODO: Reimplement by managed code.
extern void itow(int32_t value, wchar_t* p);

void System_Console_WriteLine_6(int32_t value)
{
    wchar_t buf[20];
    itow(value, buf);
    WriteLine(buf);
}

void System_Console_WriteLine_10(System_String* value)
{
    // TODO: NullReferenceException
    GCASSERT(value != NULL);

    GCASSERT(value->string_body__ != NULL);
    WriteLine(value->string_body__);
}

#define MAX_READLINE 128

System_String* System_Console_ReadLine()
{
    wchar_t buffer[MAX_READLINE];

    ReadLine(buffer, MAX_READLINE);
    return il2c_new_string(buffer);
}
