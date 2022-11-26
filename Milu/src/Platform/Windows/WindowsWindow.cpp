#include "mlpch.h"
#include "WindowsWindow.h"

namespace Milu
{
    static bool s_bGLFWInitialized = false;

    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.strTitle = props.strTitle;
        m_Data.iWidth = props.iWidth;

        ML_CORE_INFO("Create window {0} ({1},{2})", props.strTitle, props.iWidth, props.iHeight);

        if (!s_bGLFWInitialized)
        {
            int success = glfwInit();
            ML_CORE_ASSERT(success, "Could not initialize GLFW!");

            s_bGLFWInitialized = true;
        }

        m_pWindow = glfwCreateWindow((int)props.iWidth, (int)props.iHeight, m_Data.strTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_pWindow);
        glfwSetWindowUserPointer(m_pWindow, &m_Data);

        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_pWindow);

    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_pWindow);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.bVSync = enabled;
    }
    bool WindowsWindow::IsVSync() const
    {
        return m_Data.bVSync;
    }
}