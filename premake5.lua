-- premake5.lua
workspace "WeatherStationApplication"
   configurations { "Debug", "Release" }
   links {"pthread"}

project "WeatherStationApplication"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "src/**.h", "src/**.cpp" }
   
   

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      
