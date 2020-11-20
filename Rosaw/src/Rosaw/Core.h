#pragma once

#ifdef RSW_PLATFORM_WINDOWS
  #ifdef RSW_BUILD_DLL
    #define ROSAW_API __declspec(dllexport)
  #else
    #define ROSAW_API __declspec(dllimport)
  #endif // RSW_BUILD_DLL
#else
  #error Rosaw supports only Windows!
#endif // RSW_PLATFORM_WINDOWS
