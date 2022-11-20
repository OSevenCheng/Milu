#pragma once

#ifdef ML_PLATFORM_WINDOWS

extern Milu::Application* Milu::CreateApplication();

int main(int* argc, char** argv)
{
	auto app = Milu::CreateApplication();
	app->Run();
	delete app;
}
#endif