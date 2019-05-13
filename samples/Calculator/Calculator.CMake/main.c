
#include <Calculator.Core.h>

int main()
{
    il2c_initialize();

    Calculator_PolishNotation_Main();

    il2c_shutdown();
    return 0;
}
