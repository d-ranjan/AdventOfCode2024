cmake_minimum_required(VERSION 3.25)

project(AdventOfCode2024 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_GENERATOR "Ninja")
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wunreachable-code)

if(WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-mingw-dynamic")
elseif(LINUX)
    list(APPEND CMAKE_PREFIX_PATH "/opt/vcpkg/installed/x64-linux-dynamic")
endif()

# add_subdirectory(day00)
# add_subdirectory(day01)
# add_subdirectory(day02)
# add_subdirectory(day03)
# add_subdirectory(day04)
add_subdirectory(day05)
