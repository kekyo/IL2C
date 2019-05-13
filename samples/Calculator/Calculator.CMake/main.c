
#include <Calculator.Core.h>

int main(int argc, char** argv)
{
    ((void)argc);
    ((void)argv);

    il2c_initialize();

    Calculator_PolishNotation_Main();

    il2c_shutdown();
    return 0;
}
