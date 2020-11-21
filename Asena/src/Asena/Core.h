#pragma once

#ifdef AE_PLATFORM_WINDOWS
  #ifdef AE_BUILD_DLL
    #define ASENA_API __declspec(dllexport)
  #else
    #define ASENA_API __declspec(dllimport)
  #endif // AE_BUILD_DLL
#else
  #error Asena supports only Windows!
#endif // AE_PLATFORM_WINDOWS
