-- premake5.lua
workspace "WeatherStationApplication"
   configurations { "Debug", "Release" }

project "WeatherStationApplication"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "src/**.h", "src/**.cpp" }
   
   links {"pthread"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      
