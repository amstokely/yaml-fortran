cmake_minimum_required(VERSION 3.20)
project(yaml-fortran LANGUAGES CXX C Fortran)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

enable_testing()

include("cmake/YamlFortran_Functions.cmake")
include(FetchContent)

FetchContent_Declare(
        yaml-cpp
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG 0.8.0
)
FetchContent_MakeAvailable(yaml-cpp)

add_subdirectory(src)
add_subdirectory(test)

