#pragma once

#define HZ_DYNAMIC_LINK 0
#ifdef ML_PLATFORM_WINDOWS
#if HZ_DYNAMIC_LINK
	#ifdef ML_BUILD_DLL
		#define MILU_API __declspec(dllexport)
	#else
        #define MILU_API __declspec(dllimport)

	#endif
#else
    #define MILU_API
#endif
#else
	#error Milu only support Windows
#endif

#ifdef HZ_DEBUG
#define HZ_ENABLE_ASSERTS
#endif

#ifdef ML_ENABLE_ASSERTS
    #define ML_ASSERT(x,...) { if(!(x)){ML_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
    #define ML_CORE_ASSERT(x,...) { if(!(x)){ML_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
    #define ML_ASSERT(x,...)     
    #define ML_CORE_ASSERT(x,...)
#endif // ML_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define ML_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)