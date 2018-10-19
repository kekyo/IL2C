#include <il2c_combined.h>
#include "test.h"

{body}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Test: {testName}

#include <stdio.h>

int main()
{
    il2c_initialize();

    ////////////////////////

    {locals}

    ////////////////////////

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        {frames}
    } __executionFrame__;

    __executionFrame__.targetCount = {frameCount};
    {frameInitializers}
    il2c_link_execution_frame(&__executionFrame__);

    ////////////////////////

    {argInitializers}
    {function}({arguments});

    int result = 0;
    wprintf(L"Success\n");

    ////////////////////////

    il2c_unlink_execution_frame(&__executionFrame__);

    ////////////////////////

    il2c_shutdown();

    return result;
}
