#include "mlpch.h"
#include "LayerStack.h"

namespace Milu
{
    LayerStack::LayerStack() 
    {
    }
    LayerStack::~LayerStack() 
    {
        for (Layer* layer : m_Layers)
            delete layer;
    }

    void LayerStack::PushLayer(Layer* _pLayer) 
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, _pLayer);
        m_LayerInsertIndex++;
    }
    void LayerStack::PushOverlay(Layer* _pOverlay)
    {
        m_Layers.emplace_back(_pOverlay);
    }
    void LayerStack::PopLayer(Layer* _pLayer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), _pLayer);
        if (it != m_Layers.end())
        {
            m_Layers.erase(it);//dangerous!! not delete the pointer
            m_LayerInsertIndex--;
        }
    }
    void LayerStack::PopOverlay(Layer* _pOverlay)
    {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), _pOverlay);
        if (it != m_Layers.end())
        {
            m_Layers.erase(it);//dangerous!! not delete the pointer
        }
    }
}