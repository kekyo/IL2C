#include <il2c.h>

{body}

//////////////////////////////////////////////////////

#include <stdio.h>

int main()
{
    il2c_initialize();

    {type} expected;
    {type} actual;

#if {isRefType} // expected value is reference type
    expected = NULL;
    actual = NULL;

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        {type}* expected__;
        {type}* actual__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.expected__ = &expected;
    __executionFrame__.actual__ = &actual;
    il2c_link_execution_frame(&__executionFrame__);
#endif

    expected = {expected};
    actual = {function}({arguments});

    int result;
    if ({equality}) { wprintf(L"Success\n"); result = 0; }
    else { wprintf(L"Failed: {type}: expected={format}, actual={format}\n", {expectedExpression}, {actualExpression}); result = 1; }

#if {isRefType} // expected value is reference type
    il2c_unlink_execution_frame(&__executionFrame__);
#endif

    il2c_shutdown();

    return result;
}
