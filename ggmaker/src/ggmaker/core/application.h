#pragma once

#include "ggmaker/core.h"

namespace gg {

	class GG_API Application {
	protected:
		void init();
		void update();
		void render();
	public:
		Application();
		virtual ~Application();

		virtual void run();
	};
}
