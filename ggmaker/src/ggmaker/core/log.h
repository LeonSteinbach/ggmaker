#pragma once

#include <iostream>

namespace gg
{
	class Log
	{
	public:
		enum class LogLevel
		{
			TRACE,
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			FATAL,
			OFF
		};

	private:
		static Log instance;
		LogLevel logLevel = LogLevel::TRACE;

	public:
		static Log& getInstance();
		void init(LogLevel logLevel);

		template<typename T> void trace(T& object)
		{
			if (logLevel <= LogLevel::TRACE)
				std::cout << object << std::endl;
		}

		template<typename T> void debug(T& object)
		{
			if (logLevel <= LogLevel::DEBUG)
				std::cout << object << std::endl;
		}

		template<typename T> void info(T& object)
		{
			if (logLevel <= LogLevel::INFO)
				std::cout << object << std::endl;
		}

		template<typename T> void warning(T& object)
		{
			if (logLevel <= LogLevel::WARNING)
				std::cout << object << std::endl;
		}

		template<typename T> void error(T& object)
		{
			if (logLevel <= LogLevel::ERROR)
				std::cout << object << std::endl;
		}

		template<typename T> void fatal(T& object)
		{
			if (logLevel <= LogLevel::FATAL)
				std::cout << object << std::endl;
		}
	};
}

#define GG_LOG_INIT(...)    ::gg::Log::getInstance().init(__VA_ARGS__)

#define GG_LOG_TRACE(...)   ::gg::Log::getInstance().trace(__VA_ARGS__)
#define GG_LOG_DEBUG(...)   ::gg::Log::getInstance().debug(__VA_ARGS__)
#define GG_LOG_INFO(...)    ::gg::Log::getInstance().info(__VA_ARGS__)
#define GG_LOG_WARNING(...) ::gg::Log::getInstance().warning(__VA_ARGS__)
#define GG_LOG_ERROR(...)   ::gg::Log::getInstance().error(__VA_ARGS__)
#define GG_LOG_FATAL(...)   ::gg::Log::getInstance().fatal(__VA_ARGS__)
