#include <il2c_combined.c>
#include "test.h"

{body}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main()
{
    il2c_initialize();

    {function}({arguments});

    int result = 0;
    wprintf(L"Success\n");

    il2c_shutdown();

    return result;
}
