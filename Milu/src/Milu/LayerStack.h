#pragma once
#include "mlpch.h"

#include "Milu/Core.h"
#include "Layer.h"

namespace Milu
{
    class MILU_API LayerStack final
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* _pLayer);     //insert a layer at m_LayerInsert, and m_LayerInsert++
        void PushOverlay(Layer* _pOverlay); //pushback a layer without changing m_LayerInsert
        void PopLayer(Layer* _pLayer);      //remove a layer and m_LayerInsert--
        void PopOverlay(Layer* _pOverlay);  //find a layer from m_LayerInsert to the end, and remove it

        std::vector<Layer*>::iterator begin() {
            return m_Layers.begin();
        }
        std::vector<Layer*>::iterator end() {
            return m_Layers.end();
        }
    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
};

