#include "ggmaker/core/log.h"

#include <iostream>

namespace gg {

	Log& Log::getInstance() {
		static Log instance;
		return instance;
	}

	void Log::init(LogLevel logLevel) {
		this->logLevel = logLevel;
	}

	void Log::trace(std::string text) {
		if (logLevel <= LogLevel::TRACE)
			std::cout << text << std::endl;
	}

	void Log::debug(std::string text) {
		if (logLevel <= LogLevel::DEBUG)
			std::cout << text << std::endl;
	}

	void Log::info(std::string text) {
		if (logLevel <= LogLevel::INFO)
			std::cout << text << std::endl;
	}

	void Log::warning(std::string text) {
		if (logLevel <= LogLevel::WARNING)
			std::cout << text << std::endl;
	}

	void Log::error(std::string text) {
		if (logLevel <= LogLevel::ERROR)
			std::cout << text << std::endl;
	}

}
