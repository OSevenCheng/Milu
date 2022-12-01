#pragma once

#include "Milu/Core.h"

namespace Milu
{
    class MILU_API Input
    {
    public:
        inline static bool IsKeyPressed(int keycode){ return s_Instance->IsKeyPressedImpl(keycode);}
        inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        inline static void GetMousePos(double pos[2]) { return s_Instance->GetMousePosImpl(pos); }
        inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
        inline static double GetMouseX() { return s_Instance->GetMouseXImpl(); }
        inline static double GetMouseY() { return s_Instance->GetMouseYImpl(); }
        
    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual void GetMousePosImpl(double pos[2]) = 0;
        virtual std::pair<float, float> GetMousePosImpl() = 0;
        virtual double GetMouseXImpl() = 0;
        virtual double GetMouseYImpl() = 0;
    private:
        static Input* s_Instance;
    };
}