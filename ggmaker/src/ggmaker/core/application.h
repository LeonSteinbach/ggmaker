#pragma once

#include <iostream>
#include <array>

#include "ggmaker/core.h"
#include <GLFW/glfw3.h>

namespace gg
{
	class GG_API Application
	{
	protected:
		GLFWwindow* window;
		std::string title;
		std::array<int, 2> size;

		static GLFWwindow* createWindow(const std::string& title, const std::array<int, 2>& size);

	public:
		Application(const std::string& title, int width, int height);
		virtual ~Application();

		Application(const Application& other);
		Application& operator=(const Application& other);

		virtual void run();
		virtual void init();
		virtual void update(short elapsedMilliseconds);
		virtual void render();
	};
}
