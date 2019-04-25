////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IL2C Test: {testName}

#if defined(_MSC_VER) && defined(WIN32)

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRTDBG_MAP_ALLOC 1
#include <crtdbg.h>

#endif

#include "IL2C.Core.Test.Target.h"
#include "IL2C.Core.Test.Target_bundle.c"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main

#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
#if defined(_MSC_VER) && defined(WIN32)
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

    il2c_initialize();

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

    il2c_unlink_execution_frame(&frame__, NULL);

    ////////////////////////

    il2c_shutdown();

    return result;
}
