#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Console

void System_Console_Write__System_String(System_String* value)
{
    if (value != NULL)
    {
        il2c_assert(value->string_body__ != NULL);
        il2c_write(value->string_body__);
    }
}

void System_Console_WriteLine(void)
{
    il2c_writeline(L"");
}

void System_Console_WriteLine__System_Int32(int32_t value)
{
    wchar_t buffer[14];
    il2c_i32tow(value, buffer, 10);
    il2c_writeline(buffer);
}

void System_Console_WriteLine__System_String(System_String* value)
{
    if (value != NULL)
    {
        il2c_assert(value->string_body__ != NULL);
        il2c_writeline(value->string_body__);
    }
}

// TODO: limitation
#define MAX_READLINE 128

System_String* System_Console_ReadLine(void)
{
    wchar_t buffer[MAX_READLINE];

    if (il2c_readline(buffer, MAX_READLINE))
    {
        return il2c_new_string(buffer);
    }
    else
    {
        return NULL;
    }
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(
    System_Console,
    "System.Console",
    System_Object);
