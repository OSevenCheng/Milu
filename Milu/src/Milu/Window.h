#pragma once
#include "mlpch.h"

#include "Milu/Core.h"
#include "Milu/Events/Event.h"

namespace Milu 
{
    struct WindowProps
    {
        std::string strTitle;
        unsigned int iWidth;
        unsigned int iHeight;
        
        WindowProps(const std::string& title = " Milu Engien",
            unsigned int width = 1280,
            unsigned int height = 720)
            :
            strTitle(title), iWidth(width), iHeight(height)
        {

        }
    };

    class MILU_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}