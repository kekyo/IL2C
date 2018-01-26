/////////////////////////////////////////////////////////////
// For platform specifics:

#if defined(UEFI)

#include <intrin.h>
#include <stdint.h>
#include <wchar.h>

typedef long interlock_t;

#define GCALLOC malloc
#define GCFREE free
#define GCASSERT assert

void WriteLineToError(const wchar_t* pMessage);

#ifdef _DEBUG
#define DEBUG_WRITE(step, message) { \
    WriteLineToError(L##step); }
#else
#define DEBUG_WRITE(step, message)
#endif

#elif defined(_WDM)

#include <intrin.h>

#include <wdm.h>
#include <stdint.h>

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

struct __EXECUTION_FRAME__
{
    struct __EXECUTION_FRAME__* pNext;
    uint8_t targetCount;
    void** pTargets[];      // We have to track object references.
};

// TODO: Become store to thread local storage
static __EXECUTION_FRAME__* g_pBeginFrame__ = NULL;

static __REF_HEADER__* g_pBeginHeader__ = NULL;

//////////////////////////

static void* __gc_get_uninitialized_object_internal__(
    __RUNTIME_TYPE__ type, uintptr_t bodySize)
{
    __REF_HEADER__* pHeader = (__REF_HEADER__*)GCALLOC(sizeof(__REF_HEADER__) + bodySize);
    if (pHeader == NULL)
    {
        while (1)
        {
            __gc_collect__();

            pHeader = (__REF_HEADER__*)GCALLOC(sizeof(__REF_HEADER__) + bodySize);
            if (pHeader != NULL)
            {
                break;
            }

            // throw NotEnoughMemoryException();
            GCASSERT(0);
        }
    }

    void* pReference = ((uint8_t*)pHeader) + sizeof(__REF_HEADER__);
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
        __REF_HEADER__* pNext = g_pBeginHeader__;
        // (2)
        pHeader->pNext = pNext;
        // (3)
        if ((__REF_HEADER__*)INTERLOCKED_COMPARE_EXCHANGE_POINTER(
            &g_pBeginHeader__,
            pHeader,
            pNext) == pNext)
        {
            break;
        }
    }

    return pReference;
}

void* __gc_get_uninitialized_object__(__RUNTIME_TYPE__ type)
{
    GCASSERT(type != NULL);

    // String or Array:
    // throw new InvalidProgramException();
    GCASSERT(type->bodySize != UINTPTR_MAX);

    return __gc_get_uninitialized_object_internal__(type, type->bodySize);
}

void __gc_mark_from_handler__(void* pReference)
{
    GCASSERT(pReference != NULL);

    __REF_HEADER__* pHeader = (__REF_HEADER__*)
        (((uint8_t*)pReference) - sizeof(__REF_HEADER__));
    interlock_t currentMark = INTERLOCKED_COMPARE_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
    if (currentMark == GCMARK_NOMARK)
    {
        GCASSERT(pHeader->type != NULL);
        GCASSERT(pHeader->type->pMarkHandler != NULL);
        pHeader->type->pMarkHandler(pReference);
    }
}

//////////////////////////

void __gc_link_execution_frame__(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    GCASSERT(pNewFrame != NULL);

    ((__EXECUTION_FRAME__*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = (__EXECUTION_FRAME__*)pNewFrame;

#ifdef _DEBUG
    {
        __EXECUTION_FRAME__* p = (__EXECUTION_FRAME__*)pNewFrame;
        uint8_t index;
        for (index = 0; index < p->targetCount; index++)
        {
            GCASSERT(*p->pTargets[index] == NULL);
        }
    }
#endif
}

void __gc_unlink_execution_frame__(/* EXECUTION_FRAME__* */ void* pFrame)
{
    GCASSERT(pFrame != NULL);

    __gc_collect__();

    g_pBeginFrame__ = ((__EXECUTION_FRAME__*)pFrame)->pNext;
}

//////////////////////////

void __gc_step1_clear_gcmark__()
{
    // Clear header marks.
    __REF_HEADER__* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        pCurrentHeader->gcMark = GCMARK_NOMARK;
        pCurrentHeader = pCurrentHeader->pNext;
    }
}

void __gc_step2_mark_gcmark__()
{
    // Mark headers.
    __EXECUTION_FRAME__* pCurrentFrame = g_pBeginFrame__;
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
            __REF_HEADER__* pHeader = (__REF_HEADER__*)
                (((uint8_t*)*ppReference) - sizeof(__REF_HEADER__));
            interlock_t currentMark = INTERLOCKED_COMPARE_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
            if (currentMark == GCMARK_NOMARK)
            {
                GCASSERT(pHeader->type != NULL);
                GCASSERT(pHeader->type->pMarkHandler != NULL);

                DEBUG_WRITE("__gc_step2_mark_gcmark__", pHeader->type->pTypeName);

                pHeader->type->pMarkHandler(*ppReference);
            }
        }

        pCurrentFrame = pCurrentFrame->pNext;
    }
}

void __gc_step3_sweep_garbage__()
{
    // Sweep garbage if gcmark isn't marked.
    __REF_HEADER__** ppUnlinkTarget = &g_pBeginHeader__;
    __REF_HEADER__* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        __REF_HEADER__* pNext = pCurrentHeader->pNext;
        if (pCurrentHeader->gcMark != GCMARK_LIVE)
        {
            // Very important link steps: because cause misread on purpose this instance is living.
            *ppUnlinkTarget = pNext;

            DEBUG_WRITE("__gc_step3_sweep_garbage__", pCurrentHeader->type->pTypeName);

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

void __gc_collect__()
{
    __gc_step1_clear_gcmark__();
    __gc_step2_mark_gcmark__();
    __gc_step3_sweep_garbage__();
}

void __gc_initialize__()
{
#ifdef _CRTDBG_ALLOC_MEM_DF
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
}

void __gc_shutdown__()
{
    __gc_collect__();

#ifdef _CRTDBG_ALLOC_MEM_DF
    _CrtDumpMemoryLeaks();
#endif
}

/////////////////////////////////////////////////////////////
// Boxing related functions

System_Object* __box__(void* pValue, __RUNTIME_TYPE__ type)
{
    void* pBoxed = __gc_get_uninitialized_object__(type);
    memcpy(pBoxed, pValue, type->bodySize);
    return (System_Object*)pBoxed;
}

void* __unbox__(System_Object* pObject, __RUNTIME_TYPE__ type)
{
    __REF_HEADER__* pHeader = (__REF_HEADER__*)
        (((uint8_t*)pObject) - sizeof(__REF_HEADER__));
    if (pHeader->type != type)
    {
        // new InvalidCastException();
        GCASSERT(0);
    }

    return pObject;
}

/////////////////////////////////////////////////////////////
// System.Object

__DEFINE_CONST_STRING__(System_Object_name, L"System.Object");
System_String* __System_Object_ToString__(System_Object* __this)
{
    return System_Object_name;
}

int32_t __System_Object_GetHashCode__(System_Object* __this)
{
    return (int32_t)(intptr_t)__this;
}

void __System_Object_Finalize__(System_Object* __this)
{
    DEBUG_WRITE("System.Object.Finalize", "called.");
}

bool __System_Object_Equals__(System_Object* __this, System_Object* obj)
{
    return ((intptr_t)__this) == ((intptr_t)obj);
}

/////////////////////////////////////////////////////////////
// System.ValueType

__DEFINE_CONST_STRING__(System_ValueType_name, L"System.ValueType");
System_String* __System_ValueType_ToString__(System_ValueType* __this)
{
    return System_ValueType_name;
}

int32_t __System_ValueType_GetHashCode__(System_ValueType* __this)
{
    // TODO:
    return (int32_t)(intptr_t)__this;
}

bool __System_ValueType_Equals__(System_ValueType* __this, System_Object* obj)
{
    // TODO:
    return false;
}

/////////////////////////////////////////////////////////////
// Basic type informations

static void __Dummy_MARK_HANDLER__(void* pReference)
{
}

static __RUNTIME_TYPE_DEF__ __System_Object_RUNTIME_TYPE_DEF__ = {
    "System.Object", 0, __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_Object_RUNTIME_TYPE__ = &__System_Object_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_ValueType_RUNTIME_TYPE_DEF__ = {
    "System.ValueType", 0, __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_ValueType_RUNTIME_TYPE__ = &__System_ValueType_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_IntPtr_RUNTIME_TYPE_DEF__ = {
    "System.IntPtr", sizeof(System_IntPtr), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_IntPtr_RUNTIME_TYPE__ = &__System_IntPtr_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_Byte_RUNTIME_TYPE_DEF__ = {
    "System.Byte", sizeof(System_Byte), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_Byte_RUNTIME_TYPE__ = &__System_Byte_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_SByte_RUNTIME_TYPE_DEF__ = {
    "System.SByte", sizeof(System_SByte), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_SByte_RUNTIME_TYPE__ = &__System_SByte_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_Int16_RUNTIME_TYPE_DEF__ = {
    "System.Int16", sizeof(System_Int16), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_Int16_RUNTIME_TYPE__ = &__System_Int16_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_UInt16_RUNTIME_TYPE_DEF__ = {
    "System.UInt16", sizeof(System_UInt16), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_UInt16_RUNTIME_TYPE__ = &__System_UInt16_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_Int32_RUNTIME_TYPE_DEF__ = {
    "System.Int32", sizeof(System_Int32), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_Int32_RUNTIME_TYPE__ = &__System_Int32_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_UInt32_RUNTIME_TYPE_DEF__ = {
    "System.UInt32", sizeof(System_UInt32), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_UInt32_RUNTIME_TYPE__ = &__System_UInt32_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_Int64_RUNTIME_TYPE_DEF__ = {
    "System.Int64", sizeof(System_Int64), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_Int64_RUNTIME_TYPE__ = &__System_Int64_RUNTIME_TYPE_DEF__;

static __RUNTIME_TYPE_DEF__ __System_UInt64_RUNTIME_TYPE_DEF__ = {
    "System.UInt64", sizeof(System_UInt64), __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_UInt64_RUNTIME_TYPE__ = &__System_UInt64_RUNTIME_TYPE_DEF__;

const System_IntPtr System_IntPtr_Zero = 0;

// TODO: Reimplement by managed code.
extern bool twtoi(const wchar_t *_Str, int32_t* value);

bool System_Int32_TryParse(System_String* s, int32_t* result)
{
    // TODO: NullReferenceException
    GCASSERT(s != NULL);

    GCASSERT(result != NULL);
    GCASSERT(s->pBody != NULL);

    return twtoi(s->pBody, result);
}

/////////////////////////////////////////////////////////////
// System.String

__RUNTIME_TYPE_DEF__ __System_String_RUNTIME_TYPE_DEF__ = {
    "System.String", UINTPTR_MAX, __Dummy_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __System_String_RUNTIME_TYPE__ = &__System_String_RUNTIME_TYPE_DEF__;

static System_String* __new_string_internal__(uintptr_t size)
{
    uintptr_t bodySize = sizeof(System_String) + size;
    System_String* pString = __gc_get_uninitialized_object_internal__(
        __System_String_RUNTIME_TYPE__,
        bodySize);
    wchar_t* pBody = (wchar_t*)(((uint8_t*)pString) + sizeof(System_String));
    pString->pBody = pBody;
    return pString;
}

System_String* __new_string__(const wchar_t* pBody)
{
    GCASSERT(pBody != NULL);

    uintptr_t size = (uintptr_t)(wcslen(pBody) + 1) * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(size);
    memcpy((wchar_t*)(pString->pBody), pBody, size);

    return pString;
}

System_String* System_String_Concat_6(System_String* str0, System_String* str1)
{
    GCASSERT(str0 != NULL);
    GCASSERT(str1 != NULL);
    GCASSERT(str0->pBody != NULL);
    GCASSERT(str1->pBody != NULL);

    uintptr_t str0Size = (uintptr_t)wcslen(str0->pBody) * sizeof(wchar_t);
    uintptr_t str1Size = (uintptr_t)wcslen(str1->pBody) * sizeof(wchar_t);

    System_String* pString = __new_string_internal__(str0Size + str1Size + sizeof(wchar_t));
    memcpy((wchar_t*)(pString->pBody), str0->pBody, str0Size);
    memcpy(((uint8_t*)(pString->pBody)) + str0Size, str1->pBody, str1Size + sizeof(wchar_t));

    return pString;
}

System_String* System_String_Substring(System_String* __this, int32_t startIndex)
{
    GCASSERT(__this != NULL);
    GCASSERT(__this->pBody != NULL);

    // TODO: IndexOutOfRangeException
    GCASSERT(startIndex >= 0);

    if (startIndex == 0)
    {
        return __this;
    }

    int32_t thisLength = (int32_t)wcslen(__this->pBody);
    // TODO: IndexOutOfRangeException
    GCASSERT(startIndex < thisLength);

    uintptr_t newSize = (uintptr_t)(thisLength - startIndex + 1) * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(newSize);
    memcpy((wchar_t*)(pString->pBody), __this->pBody + startIndex, newSize);

    return pString;
}

System_String* System_String_Substring_1(System_String* __this, int32_t startIndex, int32_t length)
{
    GCASSERT(__this != NULL);
    GCASSERT(__this->pBody != NULL);

    // TODO: IndexOutOfRangeException
    GCASSERT(startIndex >= 0);
    GCASSERT(length >= 0);

    int32_t thisLength = (int32_t)wcslen(__this->pBody);
    // TODO: IndexOutOfRangeException
    GCASSERT((startIndex + length) <= thisLength);

    if ((startIndex == 0) && (length == thisLength))
    {
        return __this;
    }

    uintptr_t newSize = (uintptr_t)length * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(newSize + sizeof(wchar_t));
    memcpy((wchar_t*)(pString->pBody), __this->pBody + startIndex, newSize);
    ((wchar_t*)(pString->pBody))[length] = L'\0';

    return pString;
}

wchar_t System_String_get_Chars(System_String* __this, int32_t index)
{
    GCASSERT(__this != NULL);
    GCASSERT(__this->pBody != NULL);

    // TODO: IndexOutOfRangeException
    GCASSERT(index >= 0);
    GCASSERT(index < wcslen(__this->pBody));

    return __this->pBody[index];
}

int32_t System_String_get_Length(System_String* __this)
{
    GCASSERT(__this != NULL);
    GCASSERT(__this->pBody != NULL);

    return (int32_t)wcslen(__this->pBody);
}

bool System_String_IsNullOrWhiteSpace(System_String* value)
{
    if (value == NULL)
    {
        return true;
    }

    GCASSERT(value->pBody != NULL);

    uint32_t index = 0;
    while (true)
    {
        wchar_t ch = value->pBody[index];
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

    GCASSERT(value->pBody != NULL);
    Write(value->pBody);
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

    GCASSERT(value->pBody != NULL);
    WriteLine(value->pBody);
}

#define MAX_READLINE 128

System_String* System_Console_ReadLine()
{
    wchar_t buffer[MAX_READLINE];

    ReadLine(buffer, MAX_READLINE);
    return __new_string__(buffer);
}
