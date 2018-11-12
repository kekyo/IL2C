////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IL2C Test: {testName}

#include <il2c_combined.h>
#include "test.h"

{body}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main

#include <stdio.h>

int main()
{
    il2c_initialize();

#if defined(_MSC_VER) && defined(_WIN32)
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#if _DEBUG
    _crtBreakAlloc = -1;
#endif
#endif

    ////////////////////////
    // Argument and expected values.

    {constants}

    ////////////////////////
    // Construct tracking values.

    {locals}

    struct /* IL2C_EXECUTION_FRAME */
    {
        uint8_t objRefCount__;
        uint8_t objRefRefCount__;
        IL2C_EXECUTION_FRAME* pNext__;
        {frames}
    } frame__ = { {frameCount}, 0 };

    {frameInitializers}
    il2c_link_execution_frame(&frame__);

    ////////////////////////
    // Construct required type arguments.

    {arguments}

    ////////////////////////
    // Execute target function.

    {function}({argumentList});

    int result = 0;
    wprintf(L"Success\n");

    ////////////////////////
    // Destruct frames.

    il2c_unlink_execution_frame(&frame__);

    ////////////////////////

    il2c_shutdown();

    return result;
}
