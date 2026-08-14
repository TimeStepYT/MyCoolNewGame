cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)

project(Balls)

add_executable(Balls
    src/main.cpp
    src/Game.cpp
    src/Renderer.cpp
    src/Circle.cpp
    src/Mouse.cpp
)

set_target_properties(Balls PROPERTIES 
    WIN32_EXECUTABLE TRUE
)

find_package(SDL3 QUIET)

if (NOT SDL3_FOUND)
    include(cmake/CPM.cmake)

    CPMAddPackage("gh:libsdl-org/SDL#release-3.4.14")
endif()

target_link_libraries(Balls PRIVATE SDL3::SDL3)