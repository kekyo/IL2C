#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Console

extern void ReadLine(wchar_t* pBuffer, uint16_t length);

void System_Console_Write_9(System_String* value)
{
    // TODO: NullReferenceException
    il2c_assert(value != NULL);

    il2c_assert(value->string_body__ != NULL);
	il2c_fputws(value->string_body__, stdout);
}

void System_Console_WriteLine()
{
	il2c_putws(L"");
}

void System_Console_WriteLine_6(int32_t value)
{
    wchar_t buf[20];
    il2c_itow(value, buf, 10);
	il2c_putws(buf);
}

void System_Console_WriteLine_10(System_String* value)
{
    // TODO: NullReferenceException
    il2c_assert(value != NULL);

    il2c_assert(value->string_body__ != NULL);
	il2c_putws(value->string_body__);
}

// TODO: limitation
#define MAX_READLINE 128

System_String* System_Console_ReadLine()
{
    wchar_t buffer[MAX_READLINE];

	il2c_fgetws(buffer, MAX_READLINE, stdin);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_Console_RUNTIME_TYPE__ = {
    "System.Console",
    IL2C_TYPE_STANDARD,
    0,
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
