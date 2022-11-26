#include "mlpch.h"
#include "Application.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Milu
{
	Application::Application() {
		m_pWindow = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application() {}
	void Application::Run() 
	{
		//WindowResizeEvent e(1920, 1080);
		//ML_TRACE(e);
		while (m_bRunning)
		{
			m_pWindow->OnUpdate();
		}
	}
}