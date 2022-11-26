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

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		ML_CORE_TRACE("{0}", e);
	}
	
	void Application::Run() 
	{
		//WindowResizeEvent e(1920, 1080);
		//ML_TRACE(e);
		while (m_bRunning)
		{
			
			m_pWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_bRunning = false;
		return true;
	}
}