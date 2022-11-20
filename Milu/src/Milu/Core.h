#pragma once

#ifdef ML_PLATFORM_WINDOWS
	#ifdef ML_BUILD_DLL
		#define MILU_API __declspec(dllexport)
	#else
        #define MILU_API __declspec(dllimport)

	#endif
#else
	#error Milu only support Windows
#endif

#define BIT(x) (1 << x)