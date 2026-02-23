cmake_minimum_required(VERSION 3.20)
project(eliott-renderer VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_TOOLCHAIN_FILE "C:/Dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/Dev/vcpkg/installed/x64-mingw-static")


set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)

set(ELIOTT_ECS_BUILD_TESTS OFF)
add_subdirectory(extern/eliott-ecs)


add_library(eliott-renderer STATIC
    src/Renderer.cpp
    src/Texture.cpp
    src/SpriteBatch.cpp
)

target_include_directories(eliott-renderer PUBLIC
    include/
)

target_link_libraries(eliott-renderer PRIVATE
    eliott-ecs
SDL3::SDL3
    SDL3_image::SDL3_image
)