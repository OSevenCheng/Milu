#include <Milu.h>

class ExampleLayer : public Milu::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate()override {
		ML_INFO("ExampleLayer::Update");
	}

	void OnEvent(Milu::Event& e) override
	{
		ML_TRACE("{0}",e);
	}
};

class Sandbox : public Milu::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Milu::Application* Milu::CreateApplication()
{
	return new Sandbox();
}