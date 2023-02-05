#include <GLFW/glfw3.h>
#include <chrono>

#include "ggmaker/core/application.h"

#include "ggmaker/core/log.h"

namespace gg
{
	Application::Application(const std::string& title, int width, int height) : title(title), size({ width, height })
	{
		GG_LOG_SET_LOG_LEVEL(Log::LogLevel::TRACE);

		if (!glfwInit())
		{
			GG_LOG_ERROR("Failed to initialize GLWF");
			exit(EXIT_FAILURE);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		window = createWindow(title, size);

		if (!window)
		{
			GG_LOG_ERROR("Failed to create GLFW window");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
	}

	Application::~Application()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	Application::Application(const Application& other) : window(createWindow(other.title, other.size)), title(other.title), size(other.size)
	{
	}

	Application& Application::operator=(const Application& other)
	{
		if (this != &other)
		{
			window = createWindow(other.title, other.size);
			title = other.title;
			size = other.size;
		}
		return *this;
	}

	GLFWwindow* Application::createWindow(const std::string& title, const std::array<int, 2>& size)
	{
		return glfwCreateWindow(size[0], size[1], title.c_str(), nullptr, nullptr);
	}


	void Application::run()
	{
		GG_LOG_TRACE("Starting ggmaker engine");

		init();

		short elapsedMilliseconds = 0;

		auto startTime = std::chrono::steady_clock::now();
		auto endTime = std::chrono::steady_clock::now();

		while(!glfwWindowShouldClose(window))
		{
			startTime = std::chrono::steady_clock::now();

			update(elapsedMilliseconds);
			render();

			glfwSwapBuffers(window);
			glfwPollEvents();

			endTime = std::chrono::steady_clock::now();

			elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		}
	}

	void Application::init()
	{
	}

	void Application::update(short elapsedMilliseconds)
	{
	}

	void Application::render()
	{
	}
}
