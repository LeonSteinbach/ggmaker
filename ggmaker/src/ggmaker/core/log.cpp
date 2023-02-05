#include "ggmaker/core/log.h"

namespace gg
{
	Log::LogLevel Log::logLevel = LogLevel::TRACE;

	Log& Log::getInstance()
	{
		static Log instance;
		return instance;
	}

	void Log::setLogLevel(LogLevel _logLevel)
	{
		logLevel = _logLevel;
	}
}
