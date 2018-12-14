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
        const IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        {frames}
    } frame__ = { NULL, {frameCount}, 0 };

    il2c_link_execution_frame(&frame__);

    ////////////////////////
    // Construct required type arguments.

    {arguments}

    ////////////////////////
    // Execute target function.

    {actual} = {function}({argumentList});

    int result;
    if ({equality}) { wprintf(L"Success\n"); result = 0; }
    else { wprintf(L"Failed: {type}: expected={format}, actual={format}\n", {expectedExpression}, {actualExpression}); result = 1; }

    ////////////////////////
    // Destruct frames.

    il2c_unlink_execution_frame(&frame__);

    ////////////////////////

    il2c_shutdown();

    return result;
}
