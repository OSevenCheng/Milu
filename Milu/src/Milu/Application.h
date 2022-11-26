#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Milu
{
	class MILU_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_pWindow;
		bool m_bRunning = true;
	};

	// To be define in a client
	Application* CreateApplication();
}


