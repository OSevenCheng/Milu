#pragma once

#include "Milu/Core.h"
#include "Milu/Events/Event.h"

namespace Milu
{
    class MILU_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& e){}

        inline const std::string& GetName() const { return m_strDebugName; }
    protected:
        std::string m_strDebugName;
    };
}

