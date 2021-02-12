// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "framework.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#define FOLLY_DYNAMIC_DEF_TYPEINFO(T, str)            \
  const char *const dynamic::TypeInfo<T>::name = str; \
  //

FOLLY_DYNAMIC_DEF_TYPEINFO(std::nullptr_t, "null")
FOLLY_DYNAMIC_DEF_TYPEINFO(bool, "boolean")
FOLLY_DYNAMIC_DEF_TYPEINFO(std::string, "string")
FOLLY_DYNAMIC_DEF_TYPEINFO(double, "double")
FOLLY_DYNAMIC_DEF_TYPEINFO(int64_t, "int64")

#undef FOLLY_DYNAMIC_DEF_TYPEINFO