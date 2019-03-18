#include "il2c_private.h"

// TODO:
#include <process.h>

/////////////////////////////////////////////////////////////
// System.Threading.Thread

void System_Threading_Thread__ctor(System_Threading_Thread* this__, System_Threading_ThreadStart* start)
{
    il2c_assert(this__ != NULL);

    // TODO: ArgumentNullException
    il2c_assert(start != NULL);

    this__->start__ = (System_Delegate*)start;
}

static unsigned int __stdcall System_Threading_Thread_InternalEntryPoint(void* parameter)
{
    il2c_assert(parameter != NULL);

    // Root of execution frame.
    struct
    {
        const IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_Threading_Thread* thread;
    } frame__ = { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    // Retreive Thread instance and unpin.
    frame__.thread = (System_Threading_Thread*)parameter;
    il2c_unregister_fixed_instance__(frame__.thread);

    il2c_assert(frame__.thread != NULL);
    il2c_assert(frame__.thread->vptr0__ == &System_Threading_Thread_VTABLE__);
    il2c_assert(frame__.thread->rawHandle__ != 0);

    il2c_assert(il2c_isinst(frame__.thread->start__, System_Threading_ThreadStart) != NULL);

    // TODO: catch exception.

    System_Threading_ThreadStart_Invoke((System_Threading_ThreadStart*)(frame__.thread->start__));

    il2c_unlink_execution_frame(&frame__);

    _endthreadex(0);
    return 0;
}

void System_Threading_Thread_Start(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->start__ != NULL);

    // TODO: ThreadStateException
    il2c_assert(this__->rawHandle__ == 0);

    // Fixed Thread class instance.
    il2c_register_fixed_instance__(this__);

    // TODO:
    uintptr_t rawHandle = _beginthreadex(
        NULL,
        0,
        System_Threading_Thread_InternalEntryPoint,
        (void*)this__,
        CREATE_SUSPENDED,
        NULL);

    // TODO: OutOfMemoryException
    il2c_assert(rawHandle > 0);

    this__->rawHandle__ = (intptr_t)rawHandle;
    ResumeThread((HANDLE)rawHandle);
}

void System_Threading_Thread_Join(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->start__ != NULL);

    while (1)
    {
        MSG msg;
        DWORD result = MsgWaitForMultipleObjects(
            1,
            (const HANDLE*)(&(this__->rawHandle__)),
            FALSE,
            INFINITE,
            QS_ALLEVENTS);
        switch (result)
        {
        case WAIT_OBJECT_0:
            return;
        case WAIT_OBJECT_0 + 1:
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            break;
        default:
            // TODO: ThreadAbortException?
            break;
        }
    }
}

System_Threading_Thread* System_Threading_Thread_get_CurrentThread()
{
    // TODO:
    return NULL;
}

void System_Threading_Thread_Sleep(int millisecondsTimeout)
{
    il2c_sleep((uint32_t)millisecondsTimeout);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(System_Threading_Thread, "System.Threading.Thread", IL2C_TYPE_REFERENCE, sizeof(System_Threading_Thread), System_Object, 1, 0)
IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(System_Threading_Thread, start__)
IL2C_RUNTIME_TYPE_END();
