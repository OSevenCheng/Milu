workspace "Milu"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Milu/vendor/GLFW/include"

include "Milu/vendor/GLFW"

project "Milu"
    location "Milu"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mlpch.h"
    pchsource "Milu/src/mlpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
	    "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
    }
	
	links
	{
	    "GLFW",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "ML_PLATFORM_WINDOWS",
            "ML_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "ML_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ML_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ML_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Milu/src",
        "Milu/vendor/spdlog/include"
    }

    links
    {
        "Milu"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

    defines
        {
            "ML_PLATFORM_WINDOWS"
        }
         
    
    filter "configurations:Debug"
        defines "ML_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ML_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ML_DIST"
        optimize "On"