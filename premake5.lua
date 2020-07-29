workspace "Brigerad"
    architecture "x64"
    startproject "ARM_DisassemblerExplorer"

    configurations
    {
        "DebugFr",
        "ReleaseFr",
        "DistFr",
        "DebugEn",
        "ReleaseEn",
        "DistEn"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution folder)
IncludeDir = {}
IncludeDir["GLFW"] = "Brigerad/vendor/GLFW/include"
IncludeDir["Glad"] = "Brigerad/vendor/Glad/include"
IncludeDir["ImGui"] = "Brigerad/vendor/ImGui"
IncludeDir["glm"] = "Brigerad/vendor/glm"
IncludeDir["stb_image"] = "Brigerad/vendor/stb_image"
IncludeDir["freetype"] = "Brigerad/vendor/freetype"

group "Dependencies"
    include "Brigerad/vendor/GLFW"
    include "Brigerad/vendor/Glad"
    include "Brigerad/vendor/ImGui"
    include "Brigerad/vendor/freetype"

group ""

project "Brigerad"
    location "Brigerad"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "brpch.h"
    pchsource "Brigerad/src/brpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/glm/**.hpp",
        "%{prj.name}/vendor/glm/**.inl",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.freetype}/include"

    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "BR_PLATFORM_WINDOWS",
            "BR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        links
        {
            "GLFW",
            "Glad",
            "ImGui",
            "freetype",
            "opengl32.lib"
        }

        excludes
        {
            "%{prj.name}/src/Platform/Linux/**.h",
            "%{prj.name}/src/Platform/Linux/**.cpp",
        }

        disablewarnings
        {
            "26812",
            "26495",
            "26450",
            "26444",
            "26498"
        }

    filter "system:linux"
        systemversion "latest"

        defines
        {
            "BR_PLATFORM_LINUX",
            "GLFW_INCLUDE_NONE",
            "IGNORE_FREETYPE"
        }

        links
        {
            "GL",
            "m",
            "dl",
            "Xinerama",
            "Xrandr",
            "Xi",
            "Xcursor",
            "X11",
            "Xxf86vm",
            "pthread",
            "GLFW",
            "Glad",
            "ImGui",
            "freetype"
        }

        excludes
        {
            "%{prj.name}/src/Platform/Windows/**.h",
            "%{prj.name}/src/Platform/Windows/**.cpp",
            "%{prj.name}/src/Brigerad/UI/Text.cpp"
        }

    filter "configurations:DebugFr"
        defines 
        {
            "BR_DEBUG",
            "BR_ENABLE_ASSERTS",
            "BR_PROFILE",
            "BUILD_FR"
        }
        runtime "Debug"
        symbols "on"
        
    filter "configurations:ReleaseFr"
        defines 
        {
            "BR_RELEASE",
            "BUILD_FR"
        }
        runtime "Release"
        optimize "on"
        
    filter "configurations:DistFr"
        defines 
        {
            "BR_DIST",
            "BUILD_FR"
        }
        runtime "Release"
        optimize "on"

    filter "configurations:DebugEn"
        defines 
        {
            "BR_DEBUG",
            "BR_ENABLE_ASSERTS",
            "BR_PROFILE",
            "BUILD_EN"
        }
        runtime "Debug"
        symbols "on"
        
    filter "configurations:ReleaseEn"
        defines 
        {
            "BR_RELEASE",
            "BUILD_EN"
        }
        runtime "Release"
        optimize "on"
        
    filter "configurations:DistEn"
        defines 
        {
            "BR_DIST",
            "BUILD_EN"
        }
        runtime "Release"
        optimize "on"


project "ARM_DisassemblerExplorer"
        location "ARM_DisassemblerExplorer"
        kind "ConsoleApp"

        language "C++"
        cppdialect "C++17"
        staticruntime "On"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }
    
        includedirs
        {
            "%{prj.name}/src",
            "Brigerad/vendor/spdlog/include",
            "Brigerad/vendor",
            "Brigerad/src",
            "%{IncludeDir.glm}",
        }

        filter "system:windows"
            systemversion "latest"
    
            defines
            {
                "BR_PLATFORM_WINDOWS",
            }

            links
            {
                "Brigerad",
                "GLFW",
                "Glad",
                "ImGui",
                "freetype",
                "opengl32.lib",
                "Shlwapi.lib",
                "propsys.lib"
            }
            
            excludes
            {
                "%{prj.name}/src/platform/Linux/**.h",
                "%{prj.name}/src/platform/Linux/**.cpp",
            }

            disablewarnings
            {
                "26812"
            }
    
        filter "system:linux"
            systemversion "latest"

            defines
            {
                "BR_PLATFORM_LINUX"
            }

            links
            {
                "Brigerad",
                "GL",
                "m",
                "dl",
                "Xinerama",
                "Xrandr",
                "Xi",
                "Xcursor",
                "X11",
                "Xxf86vm",
                "pthread",
                "GLFW",
                "Glad",
                "ImGui",
                "freetype",
            }

            excludes
            {
                "%{prj.name}/src/platform/Windows/**.h",
                "%{prj.name}/src/platform/Windows/**.cpp",
            }

            postbuildcommands{"cp -r assets ../bin/" .. outputdir .. "/%{prj.name}"}
            

        filter "configurations:DebugFr"
            defines 
            {
                "BR_DEBUG",
                "BR_ENABLE_ASSERTS",
                "BR_PROFILE",
                "BUILD_FR"
            }
            runtime "Debug"
            symbols "on"
            
        filter "configurations:ReleaseFr"
            defines 
            {
                "BR_RELEASE",
                "BUILD_FR"
            }
            runtime "Release"
            optimize "on"
            
        filter "configurations:DistFr"
            defines 
            {
                "BR_DIST",
                "BUILD_FR"
            }
            runtime "Release"
            optimize "on"

        filter "configurations:DebugEn"
            defines 
            {
                "BR_DEBUG",
                "BR_ENABLE_ASSERTS",
                "BR_PROFILE",
                "BUILD_EN"
            }
            runtime "Debug"
            symbols "on"
            
        filter "configurations:ReleaseEn"
            defines 
            {
                "BR_RELEASE",
                "BUILD_EN"
            }
            runtime "Release"
            optimize "on"
            
        filter "configurations:DistEn"
            defines 
            {
                "BR_DIST",
                "BUILD_EN"
            }
            runtime "Release"
            optimize "on"
