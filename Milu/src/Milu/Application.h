#pragma once
#include "Core.h"

#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Milu
{
	class MILU_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* pLayer);
		void PushOverlay(Layer* pLayer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_pWindow;
		bool m_bRunning = true;
		LayerStack m_LayerStack;
	};

	// To be define in a client
	Application* CreateApplication();
}


