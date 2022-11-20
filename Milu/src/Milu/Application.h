#pragma once
#include "Core.h"

namespace Milu
{
	class MILU_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be define in a client
	Application* CreateApplication();
}


