#include <il2c_private.h>

///////////////////////////////////////////////////
// Windows Win32 API related

#if defined(_WIN32)

void il2c_initialize(void)
{
#if defined(_MSC_VER)
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();

#if defined(_MSC_VER)
    _CrtDumpMemoryLeaks();
#endif
}

//////////////////////////////////////////////////
// Win32 API threading support

intptr_t il2c_get_current_thread__(void)
{
    HANDLE processHandle = GetCurrentProcess();
    HANDLE handle;

    // Get real thread handle from pseudo handle.
    BOOL result = DuplicateHandle(
        processHandle,
        GetCurrentThread(),
        processHandle,
        &handle,
        0,
        FALSE,
        DUPLICATE_SAME_ACCESS);
    il2c_assert(result == TRUE);
    ((void)result);

    return (intptr_t)handle;
}

void il2c_join_thread__(intptr_t handle)
{
    il2c_assert(handle != 0);

    while (1)
    {
        MSG msg;
        DWORD result = MsgWaitForMultipleObjects(
            1,
            (const HANDLE*)(&handle),
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

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    OutputDebugStringW(message);
}
#endif

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);
    fputws(s, stdout);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);
    _putws(s);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);

    const wchar_t* p = fgetws(buffer, length - 1, stdin);
    if (p != NULL)
    {
        wchar_t* cr = wcschr(buffer, L'\r');
        wchar_t* lf = wcschr(buffer, L'\n');
        if ((cr != NULL) || (lf != NULL))
        {
            if ((cr != NULL) && (lf != NULL) && ((lf - cr) == 1))
            {
                *cr = L'\0';
                return true;
            }
            if (lf != NULL)
            {
                *lf = L'\0';
                return true;
            }
            if (cr != NULL)
            {
                *cr = L'\0';
                return true;
            }
        }
    }

    return false;
}

#endif
