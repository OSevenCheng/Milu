#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Milu
{
	class MILU_API Log
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

//Core log macros 
//Tips __VA_ARGS__ means ... when you write a macro
#define ML_CORE_TRACE(...)   ::Milu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ML_CORE_INFO(...)    ::Milu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ML_CORE_WARN(...)    ::Milu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ML_CORE_ERROR(...)   ::Milu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ML_CORE_FATAL(...)   ::Milu::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Core client macros 
#define ML_TRACE(...)        ::Milu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ML_INFO(...)         ::Milu::Log::GetClientLogger()->info(__VA_ARGS__)
#define ML_WARN(...)         ::Milu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ML_ERROR(...)        ::Milu::Log::GetClientLogger()->error(__VA_ARGS__)
#define ML_FATAL(...)        ::Milu::Log::GetClientLogger()->fatal(__VA_ARGS__)