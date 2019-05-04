// Referrer translated code.
#include <GettingStartedIL2C.h>

int main()
{
    // Initialize the IL2C runtime.
    il2c_initialize();

    // Invoke (translated) the C# code.
    GettingStartedIL2C_Program_Main();

    // Shutdown the IL2C runtime.
    il2c_shutdown();

    return 0;
}
