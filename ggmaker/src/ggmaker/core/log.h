#pragma once

#include <iostream>

#include "ggmaker/core.h"

namespace gg
{
	class GG_API Log
	{
	public:
		enum class GG_API LogLevel
		{
			TRACE,
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			FATAL,
			OFF
		};

		static Log& getInstance();
		static void setLogLevel(LogLevel logLevel);

		static LogLevel logLevel;

		template<typename T> static void log(LogLevel level, T& object)
		{
			if (logLevel <= level)
				std::cout << object << std::endl;
		}

	private:
		Log() = default;
	};

	#define GG_LOG_SET_LOG_LEVEL(...)    ::gg::Log::setLogLevel(__VA_ARGS__)

	#define GG_LOG_TRACE(...)   ::gg::Log::getInstance().log(::gg::Log::LogLevel::TRACE, __VA_ARGS__)
	#define GG_LOG_DEBUG(...)   ::gg::Log::getInstance().log(::gg::Log::LogLevel::DEBUG, __VA_ARGS__)
	#define GG_LOG_INFO(...)    ::gg::Log::getInstance().log(::gg::Log::LogLevel::INFO, __VA_ARGS__)
	#define GG_LOG_WARNING(...) ::gg::Log::getInstance().log(::gg::Log::LogLevel::WARNING, __VA_ARGS__)
	#define GG_LOG_ERROR(...)   ::gg::Log::getInstance().log(::gg::Log::LogLevel::ERROR, __VA_ARGS__)
	#define GG_LOG_FATAL(...)   ::gg::Log::getInstance().log(::gg::Log::LogLevel::FATAL, __VA_ARGS__)
}
