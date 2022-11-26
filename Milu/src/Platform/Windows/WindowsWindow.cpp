#include "mlpch.h"
#include "WindowsWindow.h"

#include "Milu/Events/ApplicationEvent.h"
#include "Milu/Events/MouseEvent.h"
#include "Milu/Events/KeyEvent.h"

#include <glad/glad.h>

namespace Milu
{
    static bool s_bGLFWInitialized = false;
    static void GLFWErrorCallback(int error, const char* decription)
    {
        ML_CORE_ERROR("GLFW Error ({0}): {1}", error, decription);
    }
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
            glfwSetErrorCallback(GLFWErrorCallback);
            s_bGLFWInitialized = true;
        }

        m_pWindow = glfwCreateWindow((int)props.iWidth, (int)props.iHeight, m_Data.strTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_pWindow);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        ML_CORE_ASSERT(status, "failed to initialize Glad!");
        glfwSetWindowUserPointer(m_pWindow, &m_Data);
        glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowResizeEvent e(width, height);
            
            data.iWidth = width;
            data.iHeight = height;
            data.EventCallback(e);
        });
        glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent e;
            data.EventCallback(e);
        });
        glfwSetKeyCallback(m_pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent e(key, 0);
                    data.EventCallback(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleaseEvent e(key);
                    data.EventCallback(e);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent e(key, 1);
                    data.EventCallback(e);
                    break;
                }
            }
        });
        glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent e(button);
                    data.EventCallback(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleaseEvent e(button);
                    data.EventCallback(e);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_pWindow, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent e((float)xoffset, (float)yoffset);
            data.EventCallback(e);
        });

        glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* window, double xpos, double ypos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMoveEvent e((float)xpos, (float)ypos);
            data.EventCallback(e);
        });

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