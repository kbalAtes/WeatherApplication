-- premake5.lua
workspace "WeatherStationApplication"
   configurations { "Debug", "Release" }
   

project "WeatherStationApplication"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   links "pthread"
   files { "src/**.h", "src/**.cpp" }
   
   

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      
