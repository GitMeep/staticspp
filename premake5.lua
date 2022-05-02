workspace "statics++"
    configurations {"Debug", "Release"}

project "statics++"
    kind "ConsoleApp"
    language "C++"
    targetdir "build/bin"
    cppdialect "C++17"
    toolset "gcc"

    files { "./src/**.h", "./src/**.cpp" }
    defines { "SPP_VER=\"1\"" }
    includedirs { 
        "lib/eigen/"
    }
    links {
        "pthread",
        "icuuc:static",
        "ssl",
        "crypto",
        "cryptopp",
        "z",
        "fmt",
        "curl",
        "bsoncxx",
        "mongocxx",
        "PocoFoundation",
        "PocoNet",
        "PocoNetSSL"
    }

    filter "configurations:Debug"
        buildoptions { "-rdynamic" }
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"