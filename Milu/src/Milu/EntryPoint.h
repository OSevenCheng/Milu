#pragma once

#ifdef ML_PLATFORM_WINDOWS
extern Milu::Application* Milu::CreateApplication();

int main(int* argc, char** argv)
{
	Milu::Log::Init();
	ML_CORE_WARN("Initialize Log!");
	int a = 5;
	ML_INFO("Hello! Var={0}", a);
	auto app = Milu::CreateApplication();
	app->Run();
	delete app;
}
#endif