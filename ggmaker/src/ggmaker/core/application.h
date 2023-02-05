#pragma once

#include <array>

#include "ggmaker/core.h"
#include <GLFW/glfw3.h>

namespace gg
{
	class GG_API Application
	{
	protected:
		GLFWwindow* window;
		const char* title;
		std::array<int, 2> size;

	public:
		Application(const char* title, int width, int height);
		~Application();

		virtual void run();
		virtual void init();
		virtual void update(short elapsedMilliseconds);
		virtual void render();
	};
}
