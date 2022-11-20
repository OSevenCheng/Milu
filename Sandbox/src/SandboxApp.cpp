#include <Milu.h>

class Sandbox : public Milu::Application
{
public:
	Sandbox() {

	}
	~Sandbox()
	{

	}
};

Milu::Application* Milu::CreateApplication()
{
	return new Sandbox();
}