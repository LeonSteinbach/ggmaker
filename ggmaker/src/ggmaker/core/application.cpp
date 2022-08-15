#include <GLFW/glfw3.h>

#include "ggmaker/core/application.h"
#include "ggmaker/core/log.h"

#include <iostream>

namespace gg {

	Application::Application() {}

	Application::~Application() {}

	void Application::run() {
		GG_LOG_INIT(Log::LogLevel::TRACE);

		GG_LOG_TRACE("test");
	}

	void Application::init() {

	}

	void Application::update() {

	}

	void Application::render() {

	}

}
