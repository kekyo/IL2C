#include <MT3620Blink.h>

int main(int argc, char *argv[])
{
    // Setup il2c runtime
    il2c_initialize();

    // Execute C# Main method.
    int32_t result = MT3620Blink_Program_Main();

    // Teardown il2c runtime
    il2c_shutdown();

    return result;
}
