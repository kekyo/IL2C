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
    expected = {expected};
    actual = {function}({arguments});

    int result;
    if ({equality}) { wprintf(L"Success\n"); result = 0; }
    else { wprintf(L"Failed: {type}: expected={format}, actual={format}\n", {expectedExpression}, {actualExpression}); result = 1; }

    ////////////////////////

    il2c_unlink_execution_frame(&__executionFrame__);

    ////////////////////////

    il2c_shutdown();

    return result;
}
