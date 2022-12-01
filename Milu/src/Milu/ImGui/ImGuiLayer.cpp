#include "mlpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenglRenderer.h"
#include "GLFW/glfw3.h"

#include "Milu/Application.h"

namespace Milu
{
    ImGuiLayer::ImGuiLayer()
        :Layer("ImGuiLayer")
    {

    }
    ImGuiLayer::~ImGuiLayer()
    {

    }
    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        ImGui_ImplOpenGL3_Init("#version 410");
    }
    void ImGuiLayer::OnDetach()
    {

    }
    void ImGuiLayer::OnUpdate()
    {
        Application& app = Application::Get();
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        float time = (float)glfwGetTime();
        io.DeltaTime = m_fTime > 0.0f?(time - m_fTime) : (1.0f / 60.0f);
        m_fTime = time;

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    void ImGuiLayer::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseButtonPressedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<KeyTypedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnKeyTypedEvent));
        dispatcher.Dispatch<WindowResizedEvent>(ML_BIND_EVENT_FUNC(ImGuiLayer::OnWindowResizedEvent));
    }
    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;
        return false;//the event has been handled on this layer
    }
    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;
        return false;
    }
    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos  =  ImVec2(e.GetX(),e.GetY());
        return false;
    }
    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel += e.GetOffset();
        io.MouseWheelH += e.GetHOffset();
        return false;
    }
    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = true;

        io.KeyCtrl =  io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT]   || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt =   io.KeysDown[GLFW_KEY_LEFT_ALT]     || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER]   || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

        return false;
    }
    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = false;
        return false;
    }
    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        
        io.AddInputCharacter(e.GetKeyCode());
        return false;
    }
    bool ImGuiLayer::OnWindowResizedEvent(WindowResizedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

        return false;
    }
}