#include "mlpch.h"
#include "WindowsInput.h"

#include "Milu/Application.h"
#include <GLFW/glfw3.h>
namespace Milu
{
    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePosImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return { (float)xpos, (float)ypos };
    }

    void WindowsInput::GetMousePosImpl(double pos[2])
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        glfwGetCursorPos(window, pos, pos+1);
    }
    double WindowsInput::GetMouseXImpl()
    {
        auto [x, y] = GetMousePosImpl();
        return x;
    }
    double WindowsInput::GetMouseYImpl()
    {
        auto [x, y] = GetMousePosImpl();
        return y;
    }
}
