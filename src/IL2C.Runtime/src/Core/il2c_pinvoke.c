////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#include <il2c_private.h>

#if defined(_MSC_VER)
// function declared with 'noreturn' has non-void return type
#pragma warning(disable:4646)
// function declared with 'noreturn' has a return statement
#pragma warning(disable:4645)
#endif

/////////////////////////////////////////////////////////////
// P/Invoke runtime

#if defined(_WIN32)
IL2C_CONST_STRING(il2c_dll_not_found_message, L"Dll not found.");

void* il2c_pinvoke_get_function__(const wchar_t* pDllName, const char* pEntryPointName)
{
    il2c_assert(pDllName != NULL);
    il2c_assert(pEntryPointName != NULL);

    HMODULE handle = LoadLibraryW(pDllName);
    if (handle != NULL)
    {
        void* pFunc = (void*)GetProcAddress(handle, pEntryPointName);
        if (pFunc != NULL)
        {
            return pFunc;
        }
    }

#if 1  // TODO: Improves with error message (FormatMessage API)
    System_IO_FileNotFoundException* ex = il2c_get_uninitialized_object(System_IO_FileNotFoundException);
    System_IO_FileNotFoundException__ctor__System_String(ex, il2c_dll_not_found_message);
    il2c_throw(ex);
    il2c_assert(false);
    return NULL;
#else
    // https://github.com/dotnet/runtime/blob/6d0bcc4cc7cf98e661c91d4f2abace2c5bd282a5/src/coreclr/vm/nativelibrary.cpp
    switch (GetLastError())
    {
    case ERROR_FILE_NOT_FOUND:
    case ERROR_PATH_NOT_FOUND:
    case ERROR_MOD_NOT_FOUND:
    case ERROR_DLL_NOT_FOUND:
    case ERROR_ACCESS_DENIED:
        System_IO_FileNotFoundException* ex = il2c_get_uninitialized_object(System_IO_FileNotFoundException);
        System_IO_FileNotFoundException__ctor__System_String(ex, il2c_dll_not_found_message);
        il2c_throw(ex);
        il2c_assert(false);
        return NULL;
    default:
        System_IO_FileNotFoundException* ex = il2c_get_uninitialized_object(System_IO_FileNotFoundException);
        System_IO_FileNotFoundException__ctor__System_String(ex, il2c_dll_not_found_message);
        il2c_throw(ex);
        il2c_assert(false);
        return NULL;
    }
#endif
}
#elif defined(__linux__)
IL2C_CONST_STRING(il2c_dll_not_found_message, L"Dll not found.");

void* il2c_pinvoke_get_function__(const wchar_t* pDllName, const char* pEntryPointName)
{
    il2c_assert(pDllName != NULL);
    il2c_assert(pEntryPointName != NULL);

    void* handle = dlopen(pDllName, RTLD_LAZY);
    if (handle != NULL)
    {
        void* pFunc = (void*)dlsym(handle, pEntryPointName);
        if (pFunc != NULL)
        {
            return pFunc;
        }
    }

    // TODO: Improves with error message (dlerror API)
    System_IO_FileNotFoundException* ex = il2c_get_uninitialized_object(System_IO_FileNotFoundException);
    System_IO_FileNotFoundException__ctor__System_String(ex, il2c_dll_not_found_message);
    il2c_throw(ex);
    il2c_assert(false);
    return NULL;
}
#else
IL2C_CONST_STRING(il2c_not_implemented_message, L"Not implemented.");

il2c_noreturn__ void* il2c_pinvoke_get_function__(const wchar_t* pDllName, const char* pEntryPointName)
{
    il2c_assert(pDllName != NULL);
    il2c_assert(pEntryPointName != NULL);

    System_NotImplementedException* ex = il2c_get_uninitialized_object(System_NotImplementedException);
    System_NotImplementedException__ctor__System_String(ex, il2c_not_implemented_message);
    il2c_throw(ex);
    il2c_assert(false);
    return NULL;
}
#endif
