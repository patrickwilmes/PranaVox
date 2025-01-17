cmake_minimum_required(VERSION 3.28)
project(PranaVox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
add_subdirectory(libs/glfw-3.4)

include_directories(libs/glfw-3.3.8/include)
include_directories(libs/glad/include)

add_executable(PranaVox src/main.cpp)
target_link_libraries(PranaVox PRIVATE TriAxisLib AK glfw)
