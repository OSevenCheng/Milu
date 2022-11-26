#include "mlpch.h"
#include "Application.h"

#include "Events/Event.h"

#include "Log.h"

namespace Milu
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_pWindow = std::unique_ptr<Window>(Window::Create());
		m_pWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application() {}

	void Application::PushLayer(Layer* pLayer)
	{
		m_LayerStack.PushLayer(pLayer);
	}
	void Application::PushOverlay(Layer* pLayer)
	{
		m_LayerStack.PushOverlay(pLayer);
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		ML_CORE_TRACE("{0}", e);
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)//from top to bottom when handling events
		{
			(*--it)->OnEvent(e);
			if (e.HasHandled())
				break;
		}
	}
	
	void Application::Run() 
	{
		//WindowResizeEvent e(1920, 1080);
		//ML_TRACE(e);
		while (m_bRunning)
		{
			for (Layer* layer : m_LayerStack)//from bottom to top when rendering
			{
				layer->OnUpdate();
			}
			m_pWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_bRunning = false;
		return true;
	}
}