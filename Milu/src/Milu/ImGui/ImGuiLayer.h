#pragma once

#include "Milu/Layer.h"

#include "Milu/Events/MouseEvent.h"
#include "Milu/Events/KeyEvent.h"
#include "Milu/Events/ApplicationEvent.h"

namespace Milu
{
    class MILU_API ImGuiLayer: public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& e);
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizedEvent(WindowResizedEvent& e);
        
    private:
        float m_fTime = 0.0;
    };
}


