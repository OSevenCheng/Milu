#pragma once
#include "Milu/Window.h"

#include <GLFW/glfw3.h>

namespace Milu
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.iWidth; }
        inline unsigned int GetHeight() const override { return m_Data.iHeight; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        GLFWwindow* m_pWindow;
        struct WindowData
        {
            std::string strTitle;
            unsigned int iWidth, iHeight;
            bool bVSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}


