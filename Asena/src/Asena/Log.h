#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Asena {

  class ASENA_API Log
  {
  public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };

}

// Core log macros
#define AE_CORE_TRACE(...) ::Asena::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define AE_CORE_INFO(...)  ::Asena::Log::GetCoreLogger()->info(__VA_ARGS__);
#define AE_CORE_WARN(...)  ::Asena::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define AE_CORE_ERROR(...) ::Asena::Log::GetCoreLogger()->error(__VA_ARGS__);
#define AE_CORE_FATAL(...) ::Asena::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client log macros
#define AE_TRACE(...)      ::Asena::Log::GetClientLogger()->trace(__VA_ARGS__);
#define AE_INFO(...)       ::Asena::Log::GetClientLogger()->info(__VA_ARGS__);
#define AE_WARN(...)       ::Asena::Log::GetClientLogger()->warn(__VA_ARGS__);
#define AE_ERROR(...)      ::Asena::Log::GetClientLogger()->error(__VA_ARGS__);
#define AE_FATAL(...)      ::Asena::Log::GetClientLogger()->fatal(__VA_ARGS__);