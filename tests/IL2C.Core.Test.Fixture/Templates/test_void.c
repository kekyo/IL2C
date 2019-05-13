////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IL2C Test: {testName}

#if defined(_MSC_VER) && defined(_WIN32)

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRTDBG_MAP_ALLOC 1
#include <crtdbg.h>

#endif

#include "{assemblyName}.h"
#include "{assemblyName}_bundle.c"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main

#include <stdio.h>

int main(int argc__, char** argv__)
{
    ((void)argc__);
    ((void)argv__);

#if defined(_MSC_VER) && defined(_WIN32) && defined(_DEBUG)
    _crtBreakAlloc = -1;
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

    {function}({argumentList});

    int result = 0;
    wprintf(L"Success\n");

    ////////////////////////
    // Destruct frames.

    il2c_unlink_execution_frame(&frame__, NULL);

    ////////////////////////

    il2c_shutdown();

    return result;
}
