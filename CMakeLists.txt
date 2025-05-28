cmake_minimum_required(VERSION 3.31)
project(DiscordCPPBot LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DiscordCPPBot
        src/main.cpp
        src/bot.cpp
        src/bot.hpp)

if (MSVC)
    # Please be sure that you are using the MSVC-Compiler
    # MingGW and MinGW-64 won't work since they are not supported
    # Clang may work but is not officially tested or supported for this project.
    set(DLL_SOURCE_DIR "${CMAKE_SOURCE_DIR}/dependencies/Windows/bin")
    set(DLL_FILES
            "${DLL_SOURCE_DIR}/dpp.dll"
            "${DLL_SOURCE_DIR}/libcrypto-1_1-x64.dll"
            "${DLL_SOURCE_DIR}/libssl-1_1-x64.dll"
            "${DLL_SOURCE_DIR}/opus.dll"
            "${DLL_SOURCE_DIR}/zlib1.dll")
    foreach(dll_file IN LISTS DLL_FILES)
        add_custom_command(TARGET DiscordCPPBot POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${dll_file}"
                $<TARGET_FILE_DIR:DiscordCPPBot>)
    endforeach()

    target_include_directories(DiscordCPPBot PRIVATE
            "${CMAKE_SOURCE_DIR}/dependencies/Windows/include/dpp-10.1")
    target_link_libraries(DiscordCPPBot PRIVATE
            "${CMAKE_SOURCE_DIR}/dependencies/Windows/lib/dpp-10.1/dpp.lib")
elseif (APPLE)
    #   Please be sure that you have installed dpp with brew
    #   https://dpp.dev/install-brew.html
    target_include_directories(DiscordCPPBot PRIVATE
            "/opt/homebrew/include")
    target_link_libraries(DiscordCPPBot PRIVATE
            "/opt/homebrew/lib/libdpp.dylib")
endif()