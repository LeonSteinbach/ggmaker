#pragma once

#include <iostream>

namespace gg {
	class Log {
	public:
		static enum class LogLevel {
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
		LogLevel logLevel;
	public:
		static Log& getInstance();
		void init(LogLevel logLevel);

		void trace(std::string text);
		void debug(std::string text);
		void info(std::string text);
		void warning(std::string text);
		void error(std::string text);
		void fatal(std::string text);
	};

}

#define GG_LOG_INIT(...)       ::gg::Log::getInstance().init(__VA_ARGS__)

#define GG_LOG_TRACE(...)   ::gg::Log::getInstance().trace(__VA_ARGS__)
#define GG_LOG_DEBUG(...)   ::gg::Log::getInstance().debug(__VA_ARGS__)
#define GG_LOG_INFO(...)    ::gg::Log::getInstance().info(__VA_ARGS__)
#define GG_LOG_WARNING(...) ::gg::Log::getInstance().warning(__VA_ARGS__)
#define GG_LOG_ERROR(...)   ::gg::Log::getInstance().error(__VA_ARGS__)
#define GG_LOG_FATAL(...)   ::gg::Log::getInstance().fatal(__VA_ARGS__)
