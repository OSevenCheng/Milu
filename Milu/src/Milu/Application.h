#pragma once
#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

#include "Milu/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_pWindow; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_pWindow;
		ImGuiLayer* m_ImGuiLayer;
		bool m_bRunning = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be define in a client
	Application* CreateApplication();
}


