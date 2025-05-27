cmake_minimum_required(VERSION 3.31)
project(DiscordCPPBot LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Project_DIR "${CMAKE_SOURCE_DIR}")

add_executable(DiscordCPPBot
        src/main.cpp
        src/bot.cpp
        src/bot.hpp)

if (WIN32)
    #   On Work
    #
elseif (APPLE)
    #   Please be sure that you have installed dpp with brew
    #   https://dpp.dev/install-brew.html
    target_include_directories(DiscordCPPBot PRIVATE "/opt/homebrew/include")
    target_link_libraries(DiscordCPPBot PRIVATE "/opt/homebrew/lib/libdpp.dylib")
endif()