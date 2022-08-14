#pragma once

#include "ggmaker/core.h"

namespace gg {

	class GG_API Application {
	private:
		// Scene manager
	protected:
		void Init();
		void Update();
		void Render();
	public:
		Application();
		virtual ~Application();

		void Run();
	};
}
