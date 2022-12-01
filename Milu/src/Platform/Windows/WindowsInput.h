#pragma once
#include "Milu/Input.h"
namespace Milu
{
    class WindowsInput :
        public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePosImpl() override;
        virtual void GetMousePosImpl(double pos[2]) override;
        virtual double GetMouseXImpl() override;
        virtual double GetMouseYImpl() override;
    };
}
