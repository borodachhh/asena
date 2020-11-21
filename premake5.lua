workspace "Asena"
  architecture "x64"
  startproject "Sandbox"

  configurations
  {
      "Debug",
      "Release",
      "Dist"
  }

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Asena"
  location "Asena"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outdir .. "/%{prj.name}")

  files
  {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
      "%{prj.name}/vendor/spdlog/include"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "AE_PLATFORM_WINDOWS",
        "AE_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outdir .. "/Sandbox/")
    }

    filter "configurations:Debug"
      defines "AE_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "AE_RELEASE"
      optimize "On"

    filter "configurations:Dist"
      defines "AE_DIST"
      optimize "On"


project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outdir .. "/%{prj.name}")

  files
  {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
      "Asena/vendor/spdlog/include",
      "Asena/src"
  }

  links
  {
      "Asena"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "AE_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "AE_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "AE_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "AE_DIST"
    optimize "On"
