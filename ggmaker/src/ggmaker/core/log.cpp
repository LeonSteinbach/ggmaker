#include "ggmaker/core/log.h"

namespace gg
{
	Log& Log::getInstance()
	{
		static Log instance;
		return instance;
	}

	void Log::init(LogLevel logLevel)
	{
		this->logLevel = logLevel;
	}
}
