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

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_fTime = 0.0;
    };
}


