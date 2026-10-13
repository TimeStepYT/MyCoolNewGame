cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

set(CMAKE_MSVC_RUNTIME_LIBRARY)

project(MyCoolNewGame)

add_executable(MyCoolNewGame
    src/main.cpp
    src/Game.cpp
    src/Renderer.cpp
    src/Circle.cpp
    src/Mouse.cpp
)

if (WIN32)
    set_target_properties(MyCoolNewGame PROPERTIES 
        WIN32_EXECUTABLE TRUE
    )
    set_property(TARGET MyCoolNewGame PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

find_package(SDL3 QUIET)

if (NOT SDL3_FOUND)
    include(cmake/CPM.cmake)

    CPMAddPackage("gh:libsdl-org/SDL#release-3.4.14")
endif()

target_link_libraries(MyCoolNewGame PRIVATE SDL3::SDL3)